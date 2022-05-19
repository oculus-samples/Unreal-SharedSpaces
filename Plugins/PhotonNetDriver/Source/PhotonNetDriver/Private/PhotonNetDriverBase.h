// Copyright (c) Facebook Technologies, LLC and its affiliates.  All rights reserved.

#pragma once

#include "OvrPlatform/Private/OvrNetIPAddress.h"
#include "Containers/UnrealString.h"

class PhotonNetDriverBase
{
public:
	virtual ~PhotonNetDriverBase(void) {}
	virtual void OnNewNetworkingPeerRequest(int playerNr) = 0;
	virtual void OnNetworkingConnectionStateChange(ovrID peerID, FString state) = 0;
	virtual TMap<int, ovrID>* GetPeerIds() = 0;
};

