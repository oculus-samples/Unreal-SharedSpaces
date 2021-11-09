// Copyright (c) Facebook, Inc. and its affiliates.


#include "PhotonIpNetDriver.h"
#include "Kismet/GameplayStatics.h"
#include "PacketHandlers/StatelessConnectHandlerComponent.h"
#include "Engine/GameEngine.h"

// Returns true if this net driver is valid for the current configuration.
bool UPhotonIpNetDriver::IsAvailable() const
{
	return true;
}

// Get the socket subsystem appropriate for this net driver
ISocketSubsystem* UPhotonIpNetDriver::GetSocketSubsystem()
{
	if (bIsPassthrough)
	{
		return UIpNetDriver::GetSocketSubsystem();
	}

	/** Not used */
	return nullptr;
}

// Common initialization between server and client connection setup
bool UPhotonIpNetDriver::InitBase(bool bInitAsClient, FNetworkNotify* InNotify, const FURL& URL, bool bReuseAddressAndPort, FString& Error)
{
	if (bIsPassthrough)
	{
		return UIpNetDriver::InitBase(bInitAsClient, InNotify, URL, bReuseAddressAndPort, Error);
	}

	if (!UNetDriver::InitBase(bInitAsClient, InNotify, URL, bReuseAddressAndPort, Error))
	{
		return false;
	}

	if (mpLBClient == NULL)
	{
		UGameInstance* GameInstance = ((UGameEngine*)GEngine)->GameInstance;
		mpLBClient = GameInstance->GetSubsystem<UPhotonLBClient>();
	}
	
	mpLBClient->SetNetDriver(this);

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

	return true;
}

// Initialize the net driver in client mode
bool UPhotonIpNetDriver::InitConnect(FNetworkNotify* InNotify, const FURL& ConnectURL, FString& Error)
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
	UPhotonNetConnection* Connection = NewObject<UPhotonNetConnection>(NetConnectionClass);
	check(Connection);

	ovrID id = OculusAddr.GetID();

	// Set it as the server connection before anything else so everything knows this is a client
	ServerConnection = Connection;
	Connection->InitLocalConnection(this, nullptr, ConnectURL, mpLBClient->IsConnected(id) ? USOCK_Open : USOCK_Pending);

	Connections.Add(id, Connection);

	// Connect via Photon
	mpLBClient->Connect(id);

	// Create the control channel so we can send the Hello message
	CreateInitialClientChannels();
	
	return true;
}

// Initialize the network driver in server mode (listener)
bool UPhotonIpNetDriver::InitListen(FNetworkNotify* InNotify, FURL& LocalURL, bool bReuseAddressAndPort, FString& Error)
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

	InitConnectionlessHandler();

	UE_LOG(LogNet, Verbose, TEXT("Init as a listen server %s"), *LocalURL.ToString(true));

	return true;
}

// Handle time update: read and process packets
void UPhotonIpNetDriver::TickDispatch(float DeltaTime)
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
		auto Packet = mpLBClient->ReadPacket();
		if (!Packet) 
		{
			break;
		}
		
		bool bIgnorePacket = false;
		
		ovrID PeerID = Packet->senderID;
		auto PacketSize = Packet->length;
		auto Data = (uint8 *)Packet->data;

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

			const ProcessedPacket UnProcessedPacket = ConnectionlessHandler->IncomingConnectionless(OculusAddr, Data, PacketSize);

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
				UPhotonNetConnection* Connection = NewObject<UPhotonNetConnection>(NetConnectionClass);
				check(Connection);

				Connection->InitRemoteConnection(this, nullptr, FURL(), *OculusAddr, mpLBClient->IsConnected(PeerID) ? USOCK_Open : USOCK_Pending);
				
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
		mpLBClient->RemovePacket();
	}
}

// Sends a 'connectionless' (not associated with a UNetConection) packet, to the specified address.
void UPhotonIpNetDriver::LowLevelSend(TSharedPtr<const FInternetAddr> Address, void* Data, int32 CountBits, FOutPacketTraits& Traits)
{
	if (bIsPassthrough)
	{
		return UIpNetDriver::LowLevelSend(Address, Data, CountBits, Traits);
	}
	FInternetAddrOculus OculusAddr(FURL(nullptr, *Address->ToString(false), ETravelType::TRAVEL_Absolute));
	ovrID PeerID = OculusAddr.GetID();
	if (mpLBClient->IsConnected(PeerID))
	{
		const nByte* DataToSend = reinterpret_cast<nByte*>(Data);

		if (ConnectionlessHandler.IsValid())
		{
			const ProcessedPacket ProcessedData = ConnectionlessHandler->OutgoingConnectionless(Address, (uint8*)DataToSend, CountBits, Traits);

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
		
		short CountBytes = FMath::DivideAndRoundUp(CountBits, 8);

		if (CountBits > 0)
		{
			mpLBClient->SendPacket(PeerID, CountBytes, DataToSend, false);
		}
	}
	else
	{
		UE_LOG(LogNet, Warning, TEXT("There is no connection to: %llu"), PeerID);
	}
}

void UPhotonIpNetDriver::OnNewNetworkingPeerRequest(int playerNr)
{
	ovrID PeerID = mpLBClient->GetPeerID(playerNr);

	if (AddNewClientConnection(PeerID)) 
	{
		// Accept the connection
		UE_LOG(LogNet, Verbose, TEXT("Accepting peer request and waiting for challenge: %llu"), PeerID);
		mpLBClient->Accept(PeerID);
	}
}

bool UPhotonIpNetDriver::AddNewClientConnection(ovrID PeerID)
{
	// Ignore the peer if not accepting new connections
	if (Notify->NotifyAcceptingConnection() != EAcceptConnection::Accept)
	{
		UE_LOG(LogNet, Warning, TEXT("Not accepting more new connections"));
		return false;
	}

	UE_LOG(LogNet, Verbose, TEXT("New incoming peer request: %llu"), PeerID);

	// Add to the list of clients we are expecting a challenge from
	PendingClientConnections.Add(PeerID, mpLBClient->IsConnected(PeerID) ? USOCK_Open : USOCK_Pending);

	// Remove it from existing connections map if it exists.
	int playerNr = mpLBClient->GetPlayerNum(PeerID);
	Connections.Remove(PeerID);
	PeerIds.Remove(playerNr);

	return true;
}

void UPhotonIpNetDriver::OnNetworkingConnectionStateChange(ovrID PeerID, FString State)
{
	UE_LOG(LogNet, Verbose, TEXT("%llu changed network connection state"), PeerID);
	
	if (!Connections.Contains(PeerID))
	{
		if (!PendingClientConnections.Contains(PeerID))
		{
			UE_LOG(LogNet, Warning, TEXT("Peer ID not found in connections: %llu"), PeerID);
			return;
		}
		
		if (State == FString(TEXT("Connected")))
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
	if (State == FString(TEXT("Connected")))
	{
		// Use IsConnected as the source of truth of the actual connection
		if (mpLBClient->IsConnected(PeerID))
		{
			// Connections in a state of Closed will not have a NetDriver
			// They will hit a nullptr exception if processing packets
			if (Connection->State == EConnectionState::USOCK_Closed)
			{
				UE_LOG(LogNet, Warning, TEXT("Cannot reopen a closed connection to %llu"), PeerID);

				// Better to close the underlying connection if we hit this state
				mpLBClient->Close(PeerID);
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
	else if (State == FString(TEXT("Closed")))
	{
		// Use IsConnected as the source of truth of the actual connection
		if (!mpLBClient->IsConnected(PeerID))
		{
			if (Connection->State == EConnectionState::USOCK_Pending && !IsServer())
			{
				// Treat the pending case as if the connection timed out and try again
				UE_LOG(LogNet, Verbose, TEXT("Notification said %llu is closed, but connection is still pending.  Ignoring potentially old notification and retry the connection"), PeerID);
				mpLBClient->Connect(PeerID);
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
	else if (State == FString(TEXT("Timeout")))
	{
		if (Connection->State == EConnectionState::USOCK_Pending && !IsServer())
		{
			UE_LOG(LogNet, Verbose, TEXT("Retrying connection to %llu"), PeerID);
			mpLBClient->Connect(PeerID);
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

// Shutdown all connections managed by this net driver
void UPhotonIpNetDriver::Shutdown()
{
	if (bIsPassthrough)
	{
		UIpNetDriver::Shutdown();
		return;
	}
	mpLBClient->SetNetDriver(nullptr);
	UNetDriver::Shutdown();

	UE_LOG(LogNet, Verbose, TEXT("Photon Net Driver shutdown"));
	
	// Ensure all current connections are closed now
	for (auto& Connection : Connections)
	{
		ovrID PeerID = Connection.Key;
		if (mpLBClient->IsConnected(PeerID))
		{
			UE_LOG(LogNet, Verbose, TEXT("Closing open connection to: %llu"), PeerID);
			mpLBClient->Close(PeerID);
		}
	}

	PeerIds.Empty();
}

bool UPhotonIpNetDriver::IsNetResourceValid()
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

TMap<int, ovrID>* UPhotonIpNetDriver::GetPeerIds()
{
	return &PeerIds;
}