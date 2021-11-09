// Copyright (c) Facebook, Inc. and its affiliates.

#include "NetDriverForOculus.h"

#include "IPAddressOculus.h"
#include "NetConnectionForOculus.h"
#include "PacketHandlers/StatelessConnectHandlerComponent.h"
#include "Engine/Engine.h"
#include "Engine/GameInstance.h"
#include "Engine/ChildConnection.h"

bool UNetDriverForOculus::IsAvailable() const
{
	return true;
}

ISocketSubsystem* UNetDriverForOculus::GetSocketSubsystem()
{
	if (bIsPassthrough)
	{
		return UIpNetDriver::GetSocketSubsystem();
	}

	/** Not used */
	return nullptr;
}

bool UNetDriverForOculus::InitBase(bool bInitAsClient, FNetworkNotify* InNotify, const FURL& URL, bool bReuseAddressAndPort, FString& Error)
{
	if (bIsPassthrough)
	{
		return UIpNetDriver::InitBase(bInitAsClient, InNotify, URL, bReuseAddressAndPort, Error);
	}

	if (!UNetDriver::InitBase(bInitAsClient, InNotify, URL, bReuseAddressAndPort, Error))
	{
		return false;
	}

	if (InitialConnectTimeout == 0.0)
	{
		UE_LOG(LogNet, Warning, TEXT("InitalConnectTimeout was set to %f"), InitialConnectTimeout);
		InitialConnectTimeout = 120.0;
	}

	if (ConnectionTimeout == 0.0)
	{
		UE_LOG(LogNet, Warning, TEXT("ConnectionTimeout was set to %f"), ConnectionTimeout);
		ConnectionTimeout = 120.0;
	}

	if (KeepAliveTime == 0.0)
	{
		UE_LOG(LogNet, Warning, TEXT("KeepAliveTime was set to %f"), KeepAliveTime);
		KeepAliveTime = 0.2;
	}

	if (SpawnPrioritySeconds == 0.0)
	{
		UE_LOG(LogNet, Warning, TEXT("SpawnPrioritySeconds was set to %f"), SpawnPrioritySeconds);
		SpawnPrioritySeconds = 1.0;
	}

	if (RelevantTimeout == 0.0)
	{
		UE_LOG(LogNet, Warning, TEXT("RelevantTimeout was set to %f"), RelevantTimeout);
		RelevantTimeout = 5.0;
	}

	if (ServerTravelPause == 0.0)
	{
		UE_LOG(LogNet, Warning, TEXT("ServerTravelPause was set to %f"), ServerTravelPause);
		ServerTravelPause = 4.0;
	}

	// Listen for network state
	if (!NetworkingConnectionStateChangeDelegateHandle.IsValid())
	{
		UOculusPlatformSubsystem* OculusPlatform = GWorld->GetGameInstance()->GetSubsystem<UOculusPlatformSubsystem>();
		NetworkingConnectionStateChangeDelegateHandle =
			OculusPlatform->GetNotifDelegate(ovrMessage_Notification_Networking_ConnectionStateChange)
			.AddUObject(this, &UNetDriverForOculus::OnNetworkingConnectionStateChange);
	}

	return true;
}

bool UNetDriverForOculus::InitConnect(FNetworkNotify* InNotify, const FURL& ConnectURL, FString& Error)
{
	UE_LOG(LogNet, Verbose, TEXT("Connecting to host: %s"), *ConnectURL.ToString(true));

	FInternetAddrOculus OculusAddr(ConnectURL);
	if (!OculusAddr.IsValid())
	{
		UE_LOG(LogNet, Verbose, TEXT("Init as IPNetDriver connect"));
		bIsPassthrough = true;
		return UIpNetDriver::InitConnect(InNotify, ConnectURL, Error);
	}

	if (!InitBase(true, InNotify, ConnectURL, false, Error))
	{
		return false;
	}

	// Create an unreal connection to the server
	UNetConnectionForOculus* Connection = NewObject<UNetConnectionForOculus>(NetConnectionClass);
	check(Connection);

	// Set it as the server connection before anything else so everything knows this is a client
	ServerConnection = Connection;
	Connection->InitLocalConnection(this, nullptr, ConnectURL, ovr_Net_IsConnected(OculusAddr.GetID()) ? USOCK_Open : USOCK_Pending);

	Connections.Add(OculusAddr.GetID(), Connection);

	// Connect via OVR_Networking
	ovr_Net_Connect(OculusAddr.GetID());

	// Create the control channel so we can send the Hello message
	CreateInitialClientChannels();

	return true;
}

bool UNetDriverForOculus::InitListen(FNetworkNotify* InNotify, FURL& LocalURL, bool bReuseAddressAndPort, FString& Error)
{
	if (LocalURL.HasOption(TEXT("bIsLanMatch")))
	{
		UE_LOG(LogNet, Verbose, TEXT("Init as IPNetDriver listen server"));
		bIsPassthrough = true;
		return Super::InitListen(InNotify, LocalURL, bReuseAddressAndPort, Error);
	}

	if (!InitBase(false, InNotify, LocalURL, bReuseAddressAndPort, Error))
	{
		return false;
	}

	// Listen for incoming peers
	if (!PeerConnectRequestDelegateHandle.IsValid())
	{
		UOculusPlatformSubsystem* OculusPlatform = GWorld->GetGameInstance()->GetSubsystem<UOculusPlatformSubsystem>();
		PeerConnectRequestDelegateHandle =
			OculusPlatform->GetNotifDelegate(ovrMessage_Notification_Networking_PeerConnectRequest)
			.AddUObject(this, &UNetDriverForOculus::OnNewNetworkingPeerRequest);
	}

	InitConnectionlessHandler();

	UE_LOG(LogNet, Verbose, TEXT("Init as a listen server"));

	return true;
}

void UNetDriverForOculus::TickDispatch(float DeltaTime)
{
	if (bIsPassthrough)
	{
		UIpNetDriver::TickDispatch(DeltaTime);
		return;
	}

	UNetDriver::TickDispatch(DeltaTime);

	// Process all incoming packets.
	for (;;) 
	{
		auto Packet = ovr_Net_ReadPacket();
		if (!Packet) 
		{
			break;
		}

		bool bIgnorePacket = false;

		auto PeerID = ovr_Packet_GetSenderID(Packet);
		auto PacketSize = static_cast<int32>(ovr_Packet_GetSize(Packet));
		auto Data = (uint8 *)ovr_Packet_GetBytes(Packet);

		// The server must check the pending client connections first to see if any clients are challenging the server
		// This logic is basically the same as the one in IpNetDriver
		if (IsServer() && PendingClientConnections.Contains(PeerID))
		{
			bool bPassedChallenge = false;
			TSharedPtr<StatelessConnectHandlerComponent> StatelessConnect;

			if (!ConnectionlessHandler.IsValid() || !StatelessConnectComponent.IsValid())
			{
				UE_LOG(LogNet, Log,
					TEXT("Invalid ConnectionlessHandler (%i) or StatelessConnectComponent (%i); can't accept connections."),
					(int32)(ConnectionlessHandler.IsValid()), (int32)(StatelessConnectComponent.IsValid()));
				continue;
			}

			UE_LOG(LogNet, Verbose, TEXT("Checking challenge from: %llu"), PeerID);
			TSharedPtr<FInternetAddr> OculusAddr = MakeShareable(new FInternetAddrOculus(PeerID));
			StatelessConnect = StatelessConnectComponent.Pin();

			const ProcessedPacket UnProcessedPacket =
				ConnectionlessHandler->IncomingConnectionless(OculusAddr, Data, PacketSize);

			bool bRestartedHandshake = false;
			bPassedChallenge = !UnProcessedPacket.bError && StatelessConnect->HasPassedChallenge(OculusAddr, bRestartedHandshake);

			if (bPassedChallenge)
			{
				PendingClientConnections.Remove(PeerID);
				PacketSize = FMath::DivideAndRoundUp(UnProcessedPacket.CountBits, 8);

				if (PacketSize > 0)
				{
					Data = UnProcessedPacket.Data;
				}

				UE_LOG(LogNet, Log, TEXT("Server accepting post-challenge connection from: %llu"), PeerID);

				// Create an unreal connection to the client
				UNetConnectionForOculus* Connection = NewObject<UNetConnectionForOculus>(NetConnectionClass);
				check(Connection);

				Connection->InitRemoteConnection(this, nullptr, FURL(), *OculusAddr, ovr_Net_IsConnected(PeerID) ? USOCK_Open : USOCK_Pending);

				AddClientConnection(Connection);

				Connections.Add(PeerID, Connection);

				// Set the initial packet sequence from the handshake data
				if (StatelessConnect.IsValid())
				{
					int32 ServerSequence = 0;
					int32 ClientSequence = 0;

					StatelessConnect->GetChallengeSequence(ServerSequence, ClientSequence);

					Connection->InitSequence(ClientSequence, ServerSequence);

					StatelessConnect->ResetChallengeData();
				}

				if (Connection->Handler.IsValid())
				{
					Connection->Handler->BeginHandshaking();
				}

				Notify->NotifyAcceptedConnection(Connection);

				// If there is nothing left to process for this packet, then skip it
				if (PacketSize == 0)
				{
					bIgnorePacket = true;
				}
			}
			else
			{
				UE_LOG(LogNet, Warning, TEXT("Server failed post-challenge connection from: %llu"), PeerID);
				bIgnorePacket = true;
			}
		}

		// Process the packet if we aren't suppose to ignore it
		if (!bIgnorePacket && Connections.Contains(PeerID))
		{
			auto Connection = Connections[PeerID];

			if (Connection->State == EConnectionState::USOCK_Open)
			{
				UE_LOG(LogNetTraffic, VeryVerbose, TEXT("Got a raw packet of size %d"), PacketSize);
				Connection->ReceivedRawPacket(Data, PacketSize);
			}
			else 
			{
				// This can happen on non-seamless map travels
				UE_LOG(LogNet, Verbose, TEXT("Got a packet but the connection is closed to: %llu"), PeerID);
			}
		}
		else
		{
			UE_LOG(LogNet, Warning, TEXT("There is no connection to: %llu"), PeerID);
		}
		ovr_Packet_Free(Packet);
	}
}

void UNetDriverForOculus::LowLevelSend(TSharedPtr<const FInternetAddr> Address, void* Data, int32 CountBits, FOutPacketTraits& Traits)
{
	if (bIsPassthrough)
	{
		return UIpNetDriver::LowLevelSend(Address, Data, CountBits, Traits);
	}
	FInternetAddrOculus OculusAddr(FURL(nullptr, *Address->ToString(false), ETravelType::TRAVEL_Absolute));
	ovrID PeerID = OculusAddr.GetID();
	if (ovr_Net_IsConnected(PeerID))
	{
		const uint8* DataToSend = reinterpret_cast<uint8*>(Data);

		if (ConnectionlessHandler.IsValid())
		{
			const ProcessedPacket ProcessedData =
				ConnectionlessHandler->OutgoingConnectionless(Address, (uint8*)DataToSend, CountBits, Traits);

			if (!ProcessedData.bError)
			{
				DataToSend = ProcessedData.Data;
				CountBits = ProcessedData.CountBits;
			}
			else
			{
				CountBits = 0;
			}
		}


		int32 BytesSent = 0;
		uint32 CountBytes = FMath::DivideAndRoundUp(CountBits, 8);

		if (CountBits > 0)
		{
			ovr_Net_SendPacket(PeerID, static_cast<size_t>(CountBytes), DataToSend, ovrSend_Unreliable);
		}
	}
	else
	{
		UE_LOG(LogNet, Warning, TEXT("There is no connection to: %llu"), PeerID);
	}
}

void UNetDriverForOculus::OnNewNetworkingPeerRequest(ovrMessageHandle Message, bool bIsError)
{
	auto NetworkingPeer = ovr_Message_GetNetworkingPeer(Message);
	auto PeerID = ovr_NetworkingPeer_GetID(NetworkingPeer);

	if (AddNewClientConnection(PeerID)) 
	{
		// Accept the connection
		UE_LOG(LogNet, Verbose, TEXT("Accepting peer request and waiting for challenge: %llu"), PeerID);
		ovr_Net_Accept(PeerID);
	}
}

bool UNetDriverForOculus::AddNewClientConnection(ovrID PeerID)
{
	// Ignore the peer if not accepting new connections
	if (Notify->NotifyAcceptingConnection() != EAcceptConnection::Accept)
	{
		UE_LOG(LogNet, Warning, TEXT("Not accepting more new connections"));
		return false;
	}

	UE_LOG(LogNet, Verbose, TEXT("New incoming peer request: %llu"), PeerID);

	// Add to the list of clients we are expecting a challenge from
	PendingClientConnections.Add(PeerID, ovr_Net_IsConnected(PeerID) ? USOCK_Open : USOCK_Pending);

	// Remove it from existing connections map if it exists.
	Connections.Remove(PeerID);

	return true;
}

void UNetDriverForOculus::OnNetworkingConnectionStateChange(ovrMessageHandle Message, bool bIsError)
{

	auto NetworkingPeer = ovr_Message_GetNetworkingPeer(Message);

	auto PeerID = ovr_NetworkingPeer_GetID(NetworkingPeer);

	auto State = ovr_NetworkingPeer_GetState(NetworkingPeer);

	UE_LOG(LogNet, Verbose, TEXT("%llu changed network connection state"), PeerID);

	if (!Connections.Contains(PeerID))
	{
		if (!PendingClientConnections.Contains(PeerID))
		{
			UE_LOG(LogNet, Warning, TEXT("Peer ID not found in connections: %llu"), PeerID);
			return;
		}

		if (State == ovrPeerState_Connected)
		{
			PendingClientConnections[PeerID] = EConnectionState::USOCK_Open;
		}
		else
		{
			PendingClientConnections[PeerID] = EConnectionState::USOCK_Closed;
		}
		return;
	}

	auto Connection = Connections[PeerID];
	if (State == ovrPeerState_Connected)
	{
		// Use ovr_Net_IsConnected as the source of truth of the actual connection
		if (ovr_Net_IsConnected(PeerID))
		{
			// Connections in a state of Closed will not have a NetDriver
			// They will hit a nullptr exception if processing packets
			if (Connection->State == EConnectionState::USOCK_Closed)
			{
				UE_LOG(LogNet, Warning, TEXT("Cannot reopen a closed connection to %llu"), PeerID);

				// Better to close the underlying connection if we hit this state
				ovr_Net_Close(PeerID);
			}
			else
			{
				UE_LOG(LogNet, Verbose, TEXT("%llu is connected"), PeerID);
				Connection->State = EConnectionState::USOCK_Open;
			}
		}
		else
		{
			UE_LOG(LogNet, Verbose, TEXT("Notification said %llu is open, but connection is closed.  Ignoring potentially old notification"), PeerID);
		}
	}
	else if (State == ovrPeerState_Closed)
	{
		// Use ovr_Net_IsConnected as the source of truth of the actual connection
		if (!ovr_Net_IsConnected(PeerID))
		{
			if (Connection->State == EConnectionState::USOCK_Pending && !IsServer())
			{
				// Treat the pending case as if the connection timed out and try again
				UE_LOG(LogNet, Verbose, TEXT("Notification said %llu is closed, but connection is still pending.  Ignoring potentially old notification and retry the connection"), PeerID);
				ovr_Net_Connect(PeerID);
			}
			else
			{
				UE_LOG(LogNet, Verbose, TEXT("%llu is closed"), PeerID);
				Connection->State = EConnectionState::USOCK_Closed;
			}
		}
		else
		{
			UE_LOG(LogNet, Verbose, TEXT("Notification said %llu is closed, but connection is still open.  Ignoring potentially old notification"), PeerID);
		}
	}
	else if (State == ovrPeerState_Timeout)
	{
		if (Connection->State == EConnectionState::USOCK_Pending && !IsServer())
		{
			UE_LOG(LogNet, Verbose, TEXT("Retrying connection to %llu"), PeerID);
			ovr_Net_Connect(PeerID);
		}
		else
		{
			UE_LOG(LogNet, Warning, TEXT("%llu timed out"), PeerID);
			Connection->State = EConnectionState::USOCK_Closed;
		}
	}
	else
	{
		UE_LOG(LogNet, Warning, TEXT("%llu is in an unknown state"), PeerID);
	}
}

void UNetDriverForOculus::Shutdown()
{
	if (bIsPassthrough)
	{
		UIpNetDriver::Shutdown();
		return;
	}
	UNetDriver::Shutdown();

	UE_LOG(LogNet, Verbose, TEXT("Oculus Net Driver shutdown"));
	UOculusPlatformSubsystem* OculusPlatform = GWorld->GetGameInstance()->GetSubsystem<UOculusPlatformSubsystem>();
	if (PeerConnectRequestDelegateHandle.IsValid())
	{
		OculusPlatform->RemoveNotifDelegate(ovrMessage_Notification_Networking_PeerConnectRequest, PeerConnectRequestDelegateHandle);
		PeerConnectRequestDelegateHandle.Reset();
	}
	if (NetworkingConnectionStateChangeDelegateHandle.IsValid())
	{
		OculusPlatform->RemoveNotifDelegate(ovrMessage_Notification_Networking_ConnectionStateChange, NetworkingConnectionStateChangeDelegateHandle);
		NetworkingConnectionStateChangeDelegateHandle.Reset();
	}

	// Ensure all current connections are closed now
	for (auto& Connection : Connections)
	{
		ovrID PeerID = Connection.Key;
		if (ovr_Net_IsConnected(PeerID))
		{
			UE_LOG(LogNet, Verbose, TEXT("Closing open connection to: %llu"), PeerID);
			ovr_Net_Close(PeerID);
		}
	}
}

bool UNetDriverForOculus::IsNetResourceValid()
{
	if (bIsPassthrough)
	{
		return UIpNetDriver::IsNetResourceValid();
	}

	if (!IsAvailable())
	{
		return false;
	}

	// The listen server is always available
	if (IsServer())
	{
		return true;
	}

	// The clients need to wait until the connection is established before sending packets
	return ServerConnection->State == EConnectionState::USOCK_Open;
}
