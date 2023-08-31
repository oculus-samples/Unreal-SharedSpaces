// Copyright (c) Meta Platforms, Inc. and affiliates.
// Use of the material below is subject to the terms of the MIT License
// https://github.com/oculus-samples/Unreal-SharedSpaces/blob/main/Plugins/PhotonNetDriver/LICENSE

#pragma once

#include "PhotonOvrInternetAddr.h"
#include "Containers/UnrealString.h"

class PhotonNetDriverBase
{
public:
	virtual ~PhotonNetDriverBase(void) {}
	virtual void OnNewNetworkingPeerRequest(int playerNr) = 0;
	virtual void OnNetworkingConnectionStateChange(ovrID peerID, FString state) = 0;
	virtual TMap<int, ovrID>* GetPeerIds() = 0;
};

