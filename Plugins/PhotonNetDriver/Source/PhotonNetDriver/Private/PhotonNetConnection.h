// Copyright (c) Meta Platforms, Inc. and affiliates.
// Use of the material below is subject to the terms of the MIT License
// https://github.com/oculus-samples/Unreal-SharedSpaces/blob/main/Plugins/PhotonNetDriver/LICENSE

#pragma once

#include "IpConnection.h"
#include "PhotonLBClient.h"
#include "PhotonNetConnection.generated.h"

/**
 *
 */
UCLASS(transient, config = Engine)
class UPhotonNetConnection : public UIpConnection
{
	GENERATED_BODY()
	
private:
	uint64_t PeerID;
	/** Should this net connection behave as a pass-through to normal IP */
	bool bIsPassThrough;
	UPhotonLBClient* mpLBClient;

public:

	// Begin NetConnection Interface
	virtual void InitBase(UNetDriver* InDriver, class FSocket* InSocket, const FURL& InURL, EConnectionState InState, int32 InMaxPacket = 0, int32 InPacketOverhead = 0) override;
	virtual void InitRemoteConnection(UNetDriver* InDriver, class FSocket* InSocket, const FURL& InURL, const class FInternetAddr& InRemoteAddr, EConnectionState InState, int32 InMaxPacket = 0, int32 InPacketOverhead = 0) override;
	virtual void InitLocalConnection(UNetDriver* InDriver, class FSocket* InSocket, const FURL& InURL, EConnectionState InState, int32 InMaxPacket = 0, int32 InPacketOverhead = 0) override;
	virtual void LowLevelSend(void* Data, int32 CountBits, FOutPacketTraits& Traits) override;
	FString LowLevelGetRemoteAddress(bool bAppendPort = false) override;
	FString LowLevelDescribe() override;
	virtual void FinishDestroy() override;

	virtual FString RemoteAddressToString() override;
	// End NetConnection Interface
	
};
