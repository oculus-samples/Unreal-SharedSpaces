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

#include <functional>

#include "Engine/LatentActionManager.h"
#include "LatentActions.h"
#include "OVRPlatformSubsystem.h"
#include "Engine/Engine.h"


/** Requests output pins. */
UENUM(BlueprintType)
enum class EOvrRequestOutputPins: uint8
{
    /** Always executes immediately, before the request is sent. */
    Then,

    /** Successful request. */
    Success,

    /** Failed request.  Check ErrorMsg. */
    Failure,
};

/** Paged array requests output pins. */
UENUM(BlueprintType)
enum class EOvrPageRequestOutputPins: uint8
{
    /** Always executes immediately when the node is entered, before any page request is sent. */
    Then,

    /** The page content is available in the output array. */
    PageReady,

    /** We attempted to fetch beyond the first or last pages. */
    NoMorePages,

    /** Failed request.  Check ErrorMsg. */
    Failure,
};

// ----------------------------------------------------------------------
// Generic blueprint latent action for handling requests and responses
// made to the Oculus VR Platform (OVRP) Subsystem.
//
// Blueprint nodes that make OVR Platform requests are all latent nodes:
// they often initiate a network request and register a response handler
// with UOvrPlatformSubsystem.  Each such node placed on a blueprint has
// a unique instance created for it.  We allow a single latent action at
// a time per latent node instance, which is why our latent actions
// derive from FOvrPreemptableLatentAction.   This is a base class that
// can be told to ignore the response it is waiting for.
//
// We have two subclasses:
// 1) FOvrRequestLatentAction handles most requests, while
// 2) FOvrPageRequestLatentAction handles requests for paged arrays.
//
// Their constructors take, among other parameters, two function objects,
// usually populated with lambdas.  The first one, RequestGenerator,
// has captured the input parameters in order to call the Oculus platform C
// call and it returns the generated request id.   The second one,
// ResponseProcessor, captures the output pins that it will set to defaults
// (i.e. clear) before populating them with the response payload data,
// when there is no errors.


// Signatures for the request generator and the response processor.
typedef std::function<ovrRequest()> OvrPlatformRequestGenerator;
typedef std::function<void(TOvrMessageHandlePtr Message, bool bIsError)> OvrPlatformResponseProcessor;

#define OVR_REQUEST_IMMEDIATE ovrRequest(-1)
#define OVR_REQUEST_NO_MORE_PAGES ovrRequest(-2)

// Interface for our latent actions that can be interrupted.
class FOvrPreemptableLatentAction
    : public FPendingLatentAction
{
public:

    FOvrPreemptableLatentAction(const FLatentActionInfo& LatentInfo, OvrPlatformRequestGenerator&& RG, OvrPlatformResponseProcessor&& RP)
        : ExecutionFunction(LatentInfo.ExecutionFunction)
        , OutputLink(LatentInfo.Linkage)
        , CallbackTarget(LatentInfo.CallbackTarget)
        , RequestGenerator(std::move(RG))
        , ResponseProcessor(std::move(RP))
        , RequestID(0)
        , bIgnoreResponse(false)
    {}

    virtual ~FOvrPreemptableLatentAction();

    void IgnoreResponse();

protected:

    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    OvrPlatformRequestGenerator RequestGenerator;
    OvrPlatformResponseProcessor ResponseProcessor;

    ovrRequest RequestID;

    bool bIgnoreResponse;

    UOvrPlatformSubsystem* GetOvrPlatform();
    void UnlinkRequestDelegate();

    // FPendingLatentAction implementation
    virtual void NotifyObjectDestroyed() override;
};

// Latent action for most blueprint nodes that wait for OVR Platform responses.
class FOvrRequestLatentAction
    : public FOvrPreemptableLatentAction
{
public:

    bool bThenPinExecuted;
    bool bResponseProcessed;
    bool bRequestSuccessful;

    EOvrRequestOutputPins& OutExecs;
    FString& ErrorMsg;

    FOvrRequestLatentAction(const FLatentActionInfo& LatentInfo, EOvrRequestOutputPins& OutExecs, FString& ErrorMsg, OvrPlatformRequestGenerator&& RG, OvrPlatformResponseProcessor&& RP)
        : FOvrPreemptableLatentAction(LatentInfo, std::move(RG), std::move(RP))
        , bThenPinExecuted(false)
        , bResponseProcessed(false)
        , bRequestSuccessful(false)
        , OutExecs(OutExecs)
        , ErrorMsg(ErrorMsg)
    {}

    // FPendingLatentAction implementation
    virtual void UpdateOperation(FLatentResponse& Response) override;

#if WITH_EDITOR
    // Returns a human readable description of the latent operation's current state
    virtual FString GetDescription() const override;
#endif
};

// Latent action for most blueprint nodes that wait for OVR Platform responses.
class FOvrPageRequestLatentAction
    : public FOvrPreemptableLatentAction
{
public:

    bool bThenPinExecuted;
    bool bResponseProcessed;
    bool bRequestSuccessful;

    EOvrPageRequestOutputPins& OutExecs;
    FString& ErrorMsg;

    FOvrPageRequestLatentAction(const FLatentActionInfo& LatentInfo, EOvrPageRequestOutputPins& OutExecs, FString& ErrorMsg, OvrPlatformRequestGenerator&& RG, OvrPlatformResponseProcessor&& RP)
        : FOvrPreemptableLatentAction(LatentInfo, std::move(RG), std::move(RP))
        , bThenPinExecuted(false)
        , bResponseProcessed(false)
        , bRequestSuccessful(false)
        , OutExecs(OutExecs)
        , ErrorMsg(ErrorMsg)
    {}

    // FPendingLatentAction implementation
    virtual void UpdateOperation(FLatentResponse& Response) override;

#if WITH_EDITOR
    // Returns a human readable description of the latent operation's current state
    virtual FString GetDescription() const override;
#endif
};

// Templatized function that ensures that we only have one latent action per blueprint node instance.
template <typename LatentActionType>
void OvrPlatformAddNewActionWithPreemption(UWorld* World, UObject* InActionObject, int32 UUID, LatentActionType* NewAction)
{
    auto& LatentActionManager = World->GetLatentActionManager();

    LatentActionType* OvrPlatformAction = LatentActionManager.FindExistingAction<LatentActionType>(InActionObject, UUID);
    if (OvrPlatformAction)
    {
        // Previous pending action is told to ignore whatever it is waiting for.
        OvrPlatformAction->IgnoreResponse();
    }

    LatentActionManager.AddNewAction(InActionObject, UUID, NewAction);
}
