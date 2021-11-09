// Copyright (c) Facebook, Inc. and its affiliates.

#pragma once

#include "OculusPlatform/Private/IPAddressOculus.h"
#include "Containers/UnrealString.h"

class PhotonNetDriverBase
{
public:
	virtual ~PhotonNetDriverBase(void) {}
	virtual void OnNewNetworkingPeerRequest(int playerNr) = 0;
	virtual void OnNetworkingConnectionStateChange(ovrID peerID, FString state) = 0;
	virtual TMap<int, ovrID>* GetPeerIds() = 0;
};

