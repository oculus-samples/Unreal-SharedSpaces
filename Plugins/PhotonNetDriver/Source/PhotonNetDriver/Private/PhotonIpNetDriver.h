// Copyright (c) Meta Platforms, Inc. and affiliates.
// Use of the material below is subject to the terms of the MIT License
// https://github.com/oculus-samples/Unreal-SharedSpaces/blob/main/Plugins/PhotonNetDriver/LICENSE

#pragma once

#include "CoreMinimal.h"
#include "PhotonNetConnection.h"
#include "IpNetDriver.h"
#include "OvrPlatform/Private/OvrNetIPAddress.h"
#include "PhotonNetDriverBase.h"
#include "PhotonIpNetDriver.generated.h"

/**
 * 
 */
UCLASS(transient, config = Engine)
class UPhotonIpNetDriver : public UIpNetDriver, public PhotonNetDriverBase //PHOTONNETDRIVER_API
{
	GENERATED_BODY()

private:

	bool AddNewClientConnection(ovrID PeerID);
	/** Should this net driver behave as a passthrough to normal IP */
	bool bIsPassthrough;

	TMap<ovrID, EConnectionState> PendingClientConnections;
	TMap<int, ovrID> PeerIds;

public:
	TMap<ovrID, UPhotonNetConnection*> Connections;

	// Begin UNetDriver interface.
	virtual bool IsAvailable() const override;
	virtual bool InitBase(bool bInitAsClient, FNetworkNotify* InNotify, const FURL& URL, bool bReuseAddressAndPort, FString& Error) override;
	virtual bool InitConnect(FNetworkNotify* InNotify, const FURL& ConnectURL, FString& Error) override;
	virtual bool InitListen(FNetworkNotify* InNotify, FURL& LocalURL, bool bReuseAddressAndPort, FString& Error) override;
	virtual void TickDispatch(float DeltaTime) override;
	virtual void LowLevelSend(TSharedPtr<const FInternetAddr> Address, void* Data, int32 CountBits, FOutPacketTraits& Traits) override;
	virtual void Shutdown() override;
	virtual bool IsNetResourceValid() override;
	virtual class ISocketSubsystem* GetSocketSubsystem() override;
	// End UNetDriver interface

	void OnNewNetworkingPeerRequest(int playerNr);
	void OnNetworkingConnectionStateChange(ovrID peerID, FString InState);
	TMap<int, ovrID>* GetPeerIds();

private:
	UPhotonLBClient* mpLBClient;

	friend class UPhotonNetConnection;
};
