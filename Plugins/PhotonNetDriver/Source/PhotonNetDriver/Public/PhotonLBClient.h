// Copyright (c) Facebook, Inc. and its affiliates.

#pragma once

#include "Tickable.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "../Private/LoadBalancingListener.h"
#include "../Private/BaseView.h"
#include "PhotonNetDriverBase.h"
#include "OculusPlatform/Private/IPAddressOculus.h"
#include "CoreMinimal.h"
#include "PhotonLBClient.generated.h"

// Delegates for blueprint events
DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FPhotonLBClientOnJoinOrCreateComplete, bool, bSuccessful, FString, RoomName, bool, bIsMasterClient, FString, HostAddress, int, errorCode, FString, errorString);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPhotonLBClientOnMasterClientChanged, bool, bIsMasterClient, FString, HostAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPhotonLBClientOnLogEntry, FString, Log);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPhotonLBClientConnectedToMasterServer, bool, bSuccessful);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPhotonLBClientDisconnectedFromMasterServer);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPhotonLBClientOnLeaveRoom, bool, bSuccessful);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPhotonLBClientApplicationEnterForeground);

/** Output exec pins for the WaitForConnectionToMasterServer blueprint node. */
UENUM(BlueprintType)
enum class EWaitForConnectionToMasterServerType: uint8
{
	ConnectionEstablished,
	TimeOut,
};


class UPhotonIpNetDriver;
/**
 * 
 */


UCLASS()
class UPhotonLBClient
	: public UGameInstanceSubsystem
	, public FTickableGameObject
	, public BaseView
{
	GENERATED_BODY()

public:

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

private:
	virtual void Tick(float DeltaTime) override;
	virtual bool IsTickable() const override;
	virtual TStatId GetStatId() const override;

	// System notifications
	void HandleApplicationEnterBackground();
	void HandleApplicationEnterForeground();

public:

	const FString serverAddress = TEXT("ns.exitgames.com");	// Connect to Photon cloud master server
	const FString AppID = TEXT("xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx");	// Set your Photon AppID here
	const FString appVersion = TEXT("1.0");

	void BeginPlay();

	// BaseView overrides
	void updateState(int state, const ExitGames::Common::JString& stateStr, const ExitGames::Common::JString& joinedRoomName){}

	void initPlayers(){}

	void addPlayer(int playerNr, const ExitGames::Common::JString& playerId, bool local)
	{ 
		SetPlayerNum(playerNr, playerId);
	}

	void removePlayer(int playerNr);

	void updateRoomList(const ExitGames::Common::JVector<ExitGames::Common::JString>& roomNames)
	{
		TArray<FString> a;
		for(unsigned int i=0; i<roomNames.getSize(); ++i)
		{
			a.Push(FString(roomNames[i].UTF8Representation().cstr()));
		}
	}

	void playerJoined(int playerNr);

	// Exposing methods to blueprint 
	UFUNCTION(BlueprintCallable, Category = "Photon|Room")
	void Leave();
	
	// Util
	UFUNCTION(BlueprintCallable, Category = "Photon|Room")
	bool IsInRoom(FString& RoomName);

	ovrID GetPeerID(int playerNr);
	int GetPlayerNum(ovrID id);
	void SetPlayerNum(int playerNr, const ExitGames::Common::JString& playerId);

	void Accept(ovrID peerID);
	void Close(ovrID peerId);
	void Connect(ovrID peerId);
	bool IsConnected(ovrID peerId);

	bool SendPacket(ovrID id, short length, const nByte* data, bool reliable);
	IncomingPacket* ReadPacket();
	void RemovePacket();

	FSingleIntDelegate* GetAddPlayerDelegate();

	void SetLocalID(ovrID id) { mLocalID = id; }
	int GetLocalID() { return mLocalID; }
	void SetNetDriver(PhotonNetDriverBase* pNetDriver) { mpNetDriver = pNetDriver; }

public:
	UPROPERTY(BlueprintAssignable, Category = "Photon|Room")
	FPhotonLBClientOnJoinOrCreateComplete OnRoomJoinedOrCreated;

	UPROPERTY(BlueprintAssignable, Category = "Photon|Room")
	FPhotonLBClientOnLeaveRoom OnLeaveRoom;

	UPROPERTY(BlueprintAssignable, Category = "Photon|Room")
	FPhotonLBClientOnMasterClientChanged MasterClientChanged;

	UPROPERTY(BlueprintAssignable, Category = "Photon|General")
	FPhotonLBClientConnectedToMasterServer OnMasterServerConnected;

	UPROPERTY(BlueprintAssignable, Category = "Photon|General")
	FPhotonLBClientDisconnectedFromMasterServer OnMasterServerDisconnected;

	UPROPERTY(BlueprintAssignable, Category = "Photon|General")
	FPhotonLBClientApplicationEnterForeground OnApplicationEnterForeground;
	
	void JoinOrCreateRoomReturn(bool bSuccessful, int errorCode, const ExitGames::Common::JString& errorString);
	void LeaveRoomReturn(bool bSuccessful);
	void OnMasterClientChanged(int id, int oldId);
	void ConnectReturn(bool bSuccessful);
	void Disconnected();

	UFUNCTION(BlueprintCallable, Category = "Photon|Room")
	bool JoinOrCreateRoom(FString RoomName, int32 MaxPlayers);

	bool GetHostAddress(FString& hostAddress);

	UFUNCTION(BlueprintCallable, Category = "Photon|General")
	bool ConnectToMasterServer(FString id);

	UFUNCTION(BlueprintCallable, Category = "Photon|General")
	bool IsConnectedToMasterServer();

	/**
	 * Waits for the connection to master server to be established.
	 * @param WorldContextObject - World context
	 * @param TimeToWait - The node will exit with TimeOut if the connection is not established within that time.  Use negative seconds to never time out.
	 * @param LatentInfo - For latent node
	 * @param OutExecs - Exit pins.
	 */
	UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs", TimeToWait = "-1"), Category = "Photon|General")
	void WaitForConnectionToMasterServer(
		UObject* WorldContextObject,
		float TimeToWait,
		EWaitForConnectionToMasterServerType& OutExecs,
		FLatentActionInfo LatentInfo);

public:

	UPROPERTY(BlueprintAssignable, Category = "Photon|Log")
	FPhotonLBClientOnLogEntry OnLogEntry;

private:

	void LogEntry(const FString& LogEntry, bool bBroadcast = true);
	void LogWarning(const FString& LogEntry, bool bBroadcast = true);
	void LogError(const FString& LogEntry, bool bBroadcast = true);

private:
	ExitGames::LoadBalancing::Client* mpClient;
	LoadBalancingListener* mpListener;
	PhotonNetDriverBase* mpNetDriver;

	ovrID mLocalID;

	enum EServerConnectionState {
		NOT_CONNECTED = 0,
		PENDING,
		CONNECTED
	};

	EServerConnectionState mConnectionState = NOT_CONNECTED;
};