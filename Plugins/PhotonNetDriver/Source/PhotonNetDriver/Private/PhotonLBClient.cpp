// Copyright (c) Facebook Technologies, LLC and its affiliates.  All rights reserved.

#include "PhotonLBClient.h"
#include "Engine/GameEngine.h"
#include "FWaitForConnectionToMasterServerAction.h"


void UPhotonLBClient::Initialize(FSubsystemCollectionBase& Collection)
{
	mpClient = nullptr;
	mpListener = nullptr;
	mpNetDriver = nullptr;

	FCoreDelegates::ApplicationWillEnterBackgroundDelegate.AddUObject(this, &UPhotonLBClient::HandleApplicationEnterBackground);
	FCoreDelegates::ApplicationHasEnteredForegroundDelegate.AddUObject(this,&UPhotonLBClient::HandleApplicationEnterForeground);

	BeginPlay();
}

void UPhotonLBClient::Deinitialize()
{
}

void UPhotonLBClient::BeginPlay(void)
{
	srand(GETTIMEMS());
	mpListener = new LoadBalancingListener(this);
	if (mpListener)
	{
		mpClient = new ExitGames::LoadBalancing::Client(*mpListener, ExitGames::Common::JString(TCHAR_TO_UTF8(*AppID)), ExitGames::Common::JString(TCHAR_TO_UTF8(*appVersion)));
		mpListener->setLBC(mpClient);
	}
}

void UPhotonLBClient::HandleApplicationEnterBackground()
{
	LogEntry(TEXT("Photon Client - Detected Application Quit"));

	Leave();
}

void UPhotonLBClient::HandleApplicationEnterForeground()
{
	LogEntry(TEXT("Photon Client - Detected Application Return"));
	if (mConnectionState == CONNECTED)
	{
		bool Result = mpClient->reconnectAndRejoin();
		LogEntry(FString::Printf(TEXT("Photon Client - reconnect and rejoin => %s"), Result ? TEXT("successful") : TEXT("failed")));
	}

	OnApplicationEnterForeground.Broadcast();
}

bool UPhotonLBClient::ConnectToMasterServer(FString id)
{
	if (mConnectionState == NOT_CONNECTED)
	{
		LogEntry(FString::Printf(TEXT("Connecting...")));
		LogEntry(FString::Printf(TEXT("appID is set to %s"), *AppID));
		
		if (mpClient)
		{
			ExitGames::Common::JString userId = ExitGames::Common::JString(TCHAR_TO_UTF8(*id));
			mLocalID = strtoull(TCHAR_TO_ANSI(*id), nullptr, 10);
			UE_LOG(LogNet, Verbose, TEXT("mLocalID FString %s"), *id);

			mpClient->connect(ExitGames::LoadBalancing::ConnectOptions(ExitGames::LoadBalancing::AuthenticationValues().setUserID(userId), userId, ExitGames::Common::JString(TCHAR_TO_UTF8(*serverAddress))));
			mConnectionState = PENDING;
		}
	}

	return (mConnectionState == NOT_CONNECTED);
}

void UPhotonLBClient::WaitForConnectionToMasterServer(
	UObject* WorldContextObject,
	float TimeToWait,
	EWaitForConnectionToMasterServerType& OutExecs,
	FLatentActionInfo LatentInfo)
{
	if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
	{
		auto& LatentActionManager = World->GetLatentActionManager();
		if (LatentActionManager.FindExistingAction<FWaitForConnectionToMasterServerAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == nullptr)
		{
			LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
				new FWaitForConnectionToMasterServerAction(LatentInfo, this, TimeToWait, &OutExecs));
		}
	}
}

void UPhotonLBClient::ConnectReturn(bool bSuccessful)
{
	LogEntry(FString::Printf(TEXT("Master Server Connect Return => %s"), bSuccessful ? TEXT("successful") : TEXT("failed")));

	if (bSuccessful)
	{
		mConnectionState = CONNECTED;
	}
	else
	{
		mConnectionState = NOT_CONNECTED;
	}

	OnMasterServerConnected.Broadcast(bSuccessful);
}

bool UPhotonLBClient::IsConnectedToMasterServer()
{
	return (mConnectionState == CONNECTED);
}

void UPhotonLBClient::Disconnected()
{
	LogEntry(FString::Printf(TEXT("Disconnected from Master Server (state %d)"), mpClient->getState()));
	mConnectionState = NOT_CONNECTED;

	//ConnectToMasterServer(FString::Printf(TEXT("%llu"),mLocalID));
	OnMasterServerDisconnected.Broadcast();
}

void UPhotonLBClient::Tick(float DeltaSeconds)
{
	if(mpClient && mpListener)
	{
		mpClient->service();
		mpListener->service();
	}
}

void UPhotonLBClient::Leave(void)
{
	if(mpClient->getIsInGameRoom())
	{
		LogEntry(FString::Printf(TEXT("Leave Room")));
		mpClient->opLeaveRoom();
	}
}

bool UPhotonLBClient::IsInRoom(FString& RoomName)
{
	if (mpClient->getIsInGameRoom())
	{
		LogEntry(FString::Printf(TEXT("IsInRoom? Yes -> room %s"), *toFString(mpClient->getCurrentlyJoinedRoom().getName())));

		RoomName = toFString(mpClient->getCurrentlyJoinedRoom().getName());
		return true;
	}
	else
	{
		LogEntry(FString::Printf(TEXT("IsInRoom? No")));
	}

	return false;
}

bool UPhotonLBClient::SendPacket(ovrID id, short length, const nByte* data, bool reliable)
{
	int targetPlayer = GetPlayerNum(id);
	short numTargetPlayers = 1;

	if (targetPlayer == 0)
	{
		UE_LOG(LogNet, Verbose, TEXT("Send Packet - target id %llu not found"), id);
		return false;
	}

	ExitGames::Common::Hashtable DataToSend;

	// add sender id
	DataToSend.put((nByte)1, static_cast<int64>(mLocalID));
	// add packet size
	DataToSend.put((nByte)2, length);
	// add data
	DataToSend.put((nByte)3, data, length);

	UE_LOG(LogNet, VeryVerbose, TEXT("Send Packet - sender %llu size %d player %d"), mLocalID, length, targetPlayer);

	return mpClient->opRaiseEvent(reliable, DataToSend, EVENTCODE_PACKET, ExitGames::LoadBalancing::RaiseEventOptions().setTargetPlayers(&targetPlayer, numTargetPlayers));
}

IncomingPacket* UPhotonLBClient::ReadPacket()
{
	return mpListener->ReadPacket();
}

void UPhotonLBClient::RemovePacket()
{
	mpListener->RemovePacket();
}

FSingleIntDelegate* UPhotonLBClient::GetAddPlayerDelegate()
{
	return mpListener->GetAddPlayerDelegate();
}

void UPhotonLBClient::playerJoined(int playerNr)
{
	if (mpNetDriver != nullptr)
	{
		mpNetDriver->OnNewNetworkingPeerRequest(playerNr);
	}
	else
	{
		LogError(FString::Printf(TEXT("playerJoined mpNetDriver is null. playerNr %d"), playerNr));
	}
}

void UPhotonLBClient::removePlayer(int playerNr)
{
	if (mpNetDriver != nullptr)
	{
		ovrID peerID = GetPeerID(playerNr);
		if (peerID != 0)
		{
			mpNetDriver->OnNetworkingConnectionStateChange(peerID, FString(TEXT("Closed")));
		}
		else
		{
			UE_LOG(LogNet, Verbose, TEXT("removePlayer - player %d not found"), playerNr);
		}
	}
}

void UPhotonLBClient::Accept(ovrID peerID)
{
	
}

void UPhotonLBClient::Close(ovrID peerID)
{
	
}

void UPhotonLBClient::Connect(ovrID peerID)
{	
	int targetPlayer = GetPlayerNum(peerID);
	short numTargetPlayers = 1;

	ExitGames::Common::Hashtable DataToSend;

	UE_LOG(LogNet, Verbose, TEXT("Connect to peerID %llu playerNr %d"), peerID, targetPlayer);

	mpClient->opRaiseEvent(true, DataToSend, EVENTCODE_CONNECT, ExitGames::LoadBalancing::RaiseEventOptions().setTargetPlayers(&targetPlayer, numTargetPlayers));
}

bool UPhotonLBClient::IsConnected(ovrID peerID)
{
	if (mpClient->getIsInGameRoom())
	{
		FString id = FString::Printf(TEXT("%llu"), peerID);
		ExitGames::Common::JString peer = ExitGames::Common::JString(TCHAR_TO_UTF8(*id));

		const ExitGames::Common::JVector<ExitGames::LoadBalancing::Player*>& players = mpClient->getCurrentlyJoinedRoom().getPlayers();

		for(unsigned int i=0; i<players.getSize(); ++i)
		{
			const ExitGames::LoadBalancing::Player* p = players[i];
			if (p->getName() == peer)
			{
				return true;
			}
		}
	}
	return false;
}

bool UPhotonLBClient::IsTickable() const
{
	// Since we are a UCLASS this will prevent us from ticking the CDO.
	return !IsTemplate();
}

TStatId UPhotonLBClient::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(FPhotonNetDriver, STATGROUP_Tickables);
}

bool UPhotonLBClient::GetHostAddress(FString& hostAddress)
{
	int masterPlayerNr = mpClient->getCurrentlyJoinedRoom().getMasterClientID();
	const ExitGames::LoadBalancing::Player* masterPlayer = mpClient->getCurrentlyJoinedRoom().getPlayerForNumber(masterPlayerNr);

	if (masterPlayer == nullptr)
	{
		LogError(FString::Printf(TEXT("GetHostAddress - masterPlayer is null")));
		return false;
	}

	ExitGames::Common::JString masterId = masterPlayer->getUserID();
	hostAddress = FOvrInternetAddr(toFString(masterId)).ToString(false);

	return true;
}

bool UPhotonLBClient::JoinOrCreateRoom(FString RoomName, int32 MaxPlayers)
{
	LogEntry(FString::Printf(TEXT("JoinOrCreateRoom %s with max %d players"), *RoomName, MaxPlayers));

	if (mConnectionState != CONNECTED)
	{
		if (mConnectionState != PENDING)
		{
			LogError(FString::Printf(TEXT("JoinOrCreateRoom %s failed. Connection to master server is pending."), *RoomName));
		}
		else
		{
			LogError(FString::Printf(TEXT("JoinOrCreateRoom %s failed. Not connected to master server."), *RoomName));
		}
		return false;
	}

	ExitGames::Common::JString roomName = ExitGames::Common::JString(TCHAR_TO_UTF8(*RoomName));
	ExitGames::Common::Hashtable roomProps;

	bool result = mpClient->opJoinOrCreateRoom(roomName, ExitGames::LoadBalancing::RoomOptions().setMaxPlayers(MaxPlayers).setCustomRoomProperties(roomProps).setPublishUserID(true));
	
	if (!result)
	{
		LogError(FString::Printf(TEXT("JoinOrCreateRoom %s failed"), *RoomName));
	}

	return result;
}

void UPhotonLBClient::JoinOrCreateRoomReturn(bool bSuccessful, int errorCode, const ExitGames::Common::JString& errorString)
{
	LogEntry(FString::Printf(TEXT("JoinOrCreateRoomReturn %s"), bSuccessful ? TEXT("successful") : TEXT("failed")));

	bool bMasterClient = false;
	
	FString hostAddress;
	FString RoomName;

	if (bSuccessful)
	{
		RoomName = toFString(mpClient->getCurrentlyJoinedRoom().getName());

		if (!GetHostAddress(hostAddress))
		{
			bSuccessful = false;
			LogError(FString::Printf(TEXT("GetHostAddress Failed for Room %s"), *RoomName));
		}

		bMasterClient = mpClient->getLocalPlayer().getIsMasterClient();
	}

	LogEntry(FString::Printf(TEXT("Broadcast OnRoomJoinedOrCreated successful [%s] room [%s] master [%s] host [%s]"),
		bSuccessful ? TEXT("yes") : TEXT("no"),
		*RoomName,
		bMasterClient ? TEXT("yes") : TEXT("no"),
		*hostAddress));

	OnRoomJoinedOrCreated.Broadcast(bSuccessful, RoomName, bMasterClient, hostAddress, errorCode, toFString(errorString));
}

void UPhotonLBClient::LeaveRoomReturn(bool bSuccessful)
{
	LogEntry(FString::Printf(TEXT("LeaveRoomReturn %s"), bSuccessful ? TEXT("successful") : TEXT("failed")));

	OnLeaveRoom.Broadcast(bSuccessful);
}

void UPhotonLBClient::OnMasterClientChanged(int id, int oldId)
{
	if (oldId == 0)
	{
		LogWarning(TEXT("OnMasterClientChanged: old id is 0"));
		return; // Room just created, or was empty
	}

	FString hostAddress;

	if (!GetHostAddress(hostAddress))
	{
		LogError(TEXT("GetHostAddress Failed in OnMasterClientChanged"));
	}

	bool bMasterClient = mpClient->getLocalPlayer().getIsMasterClient();

	LogEntry(FString::Printf(TEXT("Broadcast OnMasterClientChanged master [%s] host [%s]"),
		bMasterClient ? TEXT("yes") : TEXT("no"),
		*hostAddress));

	MasterClientChanged.Broadcast(bMasterClient, hostAddress);
}

// The PeerId hashtable is stored in the PhotonIPNetDriver
// This means it gets destroyed when the room changes hosts or the player changes rooms
ovrID UPhotonLBClient::GetPeerID(int playerNr)
{
	ovrID peerId = 0;

	if (mpNetDriver->GetPeerIds()->Contains(playerNr))
	{
		peerId = *(mpNetDriver->GetPeerIds()->Find(playerNr));
	}
	else if (mpClient->getLocalPlayer().getNumber() == playerNr)
	{
		FString userID = FString(mpClient->getLocalPlayer().getUserID().UTF8Representation().cstr());
		peerId = strtoull(TCHAR_TO_ANSI(*userID), nullptr, 10);
	}
	else if (mpClient->getIsInGameRoom())
	{
		const ExitGames::Common::JVector<ExitGames::LoadBalancing::Player*>& players = mpClient->getCurrentlyJoinedRoom().getPlayers();
		for(unsigned int i=0; i<players.getSize(); ++i)
		{
			const ExitGames::LoadBalancing::Player* p = players[i];
			if (p->getNumber() == playerNr)
			{
				FString userID = FString(p->getUserID().UTF8Representation().cstr());
				peerId = strtoull(TCHAR_TO_ANSI(*userID), nullptr, 10);
			}
		}
	}
	else
	{
		UE_LOG(LogNet, Verbose, TEXT("Player %d not found"), playerNr);
	}
	return peerId;
}

int UPhotonLBClient::GetPlayerNum(ovrID id)
{
	if (mLocalID == id)
	{
		return mpClient->getLocalPlayer().getNumber();
	}
	else if (mpClient->getIsInGameRoom())
	{
		const ExitGames::Common::JVector<ExitGames::LoadBalancing::Player*>& players = mpClient->getCurrentlyJoinedRoom().getPlayers();
		for(unsigned int i=0; i<players.getSize(); ++i)
		{
			const ExitGames::LoadBalancing::Player* p = players[i];

			FString userID = FString(p->getUserID().UTF8Representation().cstr());
			ovrID peerId = strtoull(TCHAR_TO_ANSI(*userID), nullptr, 10);

			if (peerId == id)
			{
				return p->getNumber();
			}
		}
	}
	
	UE_LOG(LogNet, Verbose, TEXT("PeerID %llu not found"), id);
	return 0;
}

void UPhotonLBClient::SetPlayerNum(int playerNr, const ExitGames::Common::JString& playerId)
{
	FString userID = FString(playerId.UTF8Representation().cstr());
	ovrID peerId = strtoull(TCHAR_TO_ANSI(*userID), nullptr, 10);

	UE_LOG(LogNet, Verbose, TEXT("SetPlayerNum %d %llu"), playerNr, peerId);
	if (mpNetDriver != nullptr)
	{
		mpNetDriver->GetPeerIds()->Add(playerNr, peerId);
	}
	else
	{
		UE_LOG(LogNet, Verbose, TEXT("SetPlayerNum failed! mpNetDriver is nullptr"));
	}
}

void UPhotonLBClient::LogEntry(const FString& LogEntry, bool bBroadcast /* = true */)
{
	if (bBroadcast)
	{
		OnLogEntry.Broadcast(LogEntry);
	}

	UE_LOG(LogNet, Log, TEXT("%s"), *LogEntry);
}

void UPhotonLBClient::LogWarning(const FString& LogEntry, bool bBroadcast /* = true */)
{
	if (bBroadcast)
	{
		OnLogEntry.Broadcast(LogEntry);
	}

	UE_LOG(LogNet, Warning, TEXT("%s"), *LogEntry);
}

void UPhotonLBClient::LogError(const FString& LogEntry, bool bBroadcast /* = true */)
{
	if (bBroadcast)
	{
		OnLogEntry.Broadcast(LogEntry);
	}

	UE_LOG(LogNet, Error, TEXT("%s"), *LogEntry);
}