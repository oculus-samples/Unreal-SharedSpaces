// Copyright (c) Facebook, Inc. and its affiliates.

#pragma once

#include "CoreMinimal.h"
#include "NetConnectionForOculus.h"
#include "IpNetDriver.h"
#include "IPAddress.h"
#include "OculusPlatformSubsystem.h"
#include "NetDriverForOculus.generated.h"


UCLASS(Transient, Config = Engine)
class OCULUSPLATFORM_API UNetDriverForOculus : public UIpNetDriver
{
	GENERATED_BODY()

private:

	FDelegateHandle PeerConnectRequestDelegateHandle;
	FDelegateHandle NetworkingConnectionStateChangeDelegateHandle;

	bool AddNewClientConnection(ovrID PeerID);
	/** Should this net driver behave as a passthrough to normal IP */
	bool bIsPassthrough;

	TMap<uint64, EConnectionState> PendingClientConnections;

public:
	TMap<uint64, UNetConnectionForOculus*> Connections;

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

	void OnNewNetworkingPeerRequest(ovrMessageHandle Message, bool bIsError);

	void OnNetworkingConnectionStateChange(ovrMessageHandle Message, bool bIsError);
};
