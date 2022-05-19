/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 * All rights reserved.
 *
 * Licensed under the Oculus SDK License Agreement (the "License");
 * you may not use the Oculus SDK except in compliance with the License,
 * which is provided at the time of installation or download, or which
 * otherwise accompanies this software in either electronic or hard copy form.
 *
 * You may obtain a copy of the License at
 *
 * https://developer.oculus.com/licenses/oculussdk/
 *
 * Unless required by applicable law or agreed to in writing, the Oculus SDK
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "CoreMinimal.h"
#include "OvrNetConnection.h"
#include "IpNetDriver.h"
#include "IPAddress.h"
#include "OvrPlatformSubsystem.h"
#include "OvrNetDriver.generated.h"


UCLASS(Transient, Config = Engine)
class OVRPLATFORM_API UOvrNetDriver : public UIpNetDriver
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
	TMap<uint64, UOvrNetConnection*> Connections;

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

	void OnNewNetworkingPeerRequest(TOvrMessageHandlePtr Message, bool bIsError);
	void OnNetworkingConnectionStateChange(TOvrMessageHandlePtr Message, bool bIsError);
};
