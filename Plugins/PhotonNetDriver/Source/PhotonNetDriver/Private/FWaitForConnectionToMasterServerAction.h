// Copyright (c) Meta Platforms, Inc. and affiliates.
// Use of the material below is subject to the terms of the MIT License
// https://github.com/oculus-samples/Unreal-SharedSpaces/blob/main/Plugins/PhotonNetDriver/LICENSE

#pragma once

#include "CoreMinimal.h"
#include "UObject/WeakObjectPtr.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"
#include "PhotonLBClient.h"

/** Latent action for blueprint node that waits for the connection to master server to be established. */
class FWaitForConnectionToMasterServerAction : public FPendingLatentAction
{
public:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;

	UPhotonLBClient* PhotonClient;
	float TimeToWait;

	EWaitForConnectionToMasterServerType* OutExecs;

	FWaitForConnectionToMasterServerAction(const FLatentActionInfo& LatentInfo, UPhotonLBClient* PhotonClient, float TimeToWait, EWaitForConnectionToMasterServerType* OutExecs)
		: ExecutionFunction(LatentInfo.ExecutionFunction)
		, OutputLink(LatentInfo.Linkage)
		, CallbackTarget(LatentInfo.CallbackTarget)
		, PhotonClient(PhotonClient)
		, TimeToWait(TimeToWait)
		, OutExecs(OutExecs)
	{
	}

	virtual void UpdateOperation(FLatentResponse& Response) override
	{
		// Time out?
		if (TimeToWait > 0.0f)
		{
			TimeToWait -= Response.ElapsedTime();
			if (TimeToWait <= 0.0f)
			{
				// We have timed out while waiting.
				*OutExecs = EWaitForConnectionToMasterServerType::TimeOut;
				Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
			}
		}

		if (PhotonClient->IsConnectedToMasterServer())
		{
			*OutExecs = EWaitForConnectionToMasterServerType::ConnectionEstablished;
			Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
		}
	}

#if WITH_EDITOR
	// Returns a human readable description of the latent operation's current state
	virtual FString GetDescription() const override
	{
		FString Msg = TEXT("Waiting for Connection to Master Server");
		return Msg;
	}
#endif
};



