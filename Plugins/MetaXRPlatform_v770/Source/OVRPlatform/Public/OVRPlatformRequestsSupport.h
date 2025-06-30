// Copyright (c) Meta Platforms, Inc. and affiliates.

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

/// An Interface for our latent actions that can be interrupted. It provide a way to handle OVR Platform requests that are initiated by blueprint nodes. 
/// These requests often involve network communication and require a response handler to be registered with the UOvrPlatformSubsystem.
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
    /// This function can be called to ignore the response from the Oculus Platform SDK. When this function is called, the latent action will not wait for a response from the SDK and will instead continue execution immediately.
    void IgnoreResponse();

protected:
    /// This is the name of the function that will be executed when the latent action is triggered.
    FName ExecutionFunction;
    /// This variable is used to store the output link.
    int32 OutputLink;
    /// This is a weak pointer to an object that will be notified when the latent action is complete. 
    FWeakObjectPtr CallbackTarget;
    /// This is an instance of the OvrPlatformRequestGenerator class, which is used to generate requests to the Oculus Platform SDK.
    OvrPlatformRequestGenerator RequestGenerator;
    /// This is an instance of the OvrPlatformResponseProcessor class, which is used to process the response from the Oculus Platform SDK.
    OvrPlatformResponseProcessor ResponseProcessor;
    /// This is the ID of the request.
    ovrRequest RequestID;
    /// This variable indicates whether the response from the Oculus VR Platform (OVRP) Subsystem should be ignored.
    bool bIgnoreResponse;
    /// This function returns a pointer to the UOvrPlatformSubsystem object, which provides access to the Oculus Platform SDK. The subsystem is used to perform various operations with the Oculus Platform, such as making requests and processing responses.
    UOvrPlatformSubsystem* GetOvrPlatform();
    /// This function unlinks the request delegate from the Oculus Platform SDK. The request delegate is used to handle the response from the SDK, and unlinking it allows the latent action to ignore the response if desired.
    void UnlinkRequestDelegate();
    /// This function is a virtual function that is called when the object associated with the latent action is destroyed. 
    virtual void NotifyObjectDestroyed() override;
};

/// FOvrRequestLatentAction is a latent action class for blueprint nodes that wait for OVR Platform UOvrPlatformSubsystem responses. 
/// It handles most requests and has two function objects, RequestGenerator and ResponseProcessor, which are used to generate the request and process the response, respectively. 
/// The class also has several member variables to track the status of the request and response processing.
class FOvrRequestLatentAction
    : public FOvrPreemptableLatentAction
{
public:
    /// This variable is a `boolean` that indicates whether the "then" pin of the latent action has been executed.
    bool bThenPinExecuted;
    /// This variable is a `boolean` that indicates whether the response from the Oculus VR Platform (OVR) Subsystem has been processed.
    bool bResponseProcessed;
    /// This variable is a `boolean` that indicates whether the request to the OVR Subsystem was successful.
    bool bRequestSuccessful;
    ///  A reference to an ::EOvrRequestOutputPins enum, which represents the output pins for the request.
    EOvrRequestOutputPins& OutExecs;
    ///  A reference to a string, which represents the error message for the request.
    FString& ErrorMsg;

    FOvrRequestLatentAction(const FLatentActionInfo& LatentInfo, EOvrRequestOutputPins& OutExecs, FString& ErrorMsg, OvrPlatformRequestGenerator&& RG, OvrPlatformResponseProcessor&& RP)
        : FOvrPreemptableLatentAction(LatentInfo, std::move(RG), std::move(RP))
        , bThenPinExecuted(false)
        , bResponseProcessed(false)
        , bRequestSuccessful(false)
        , OutExecs(OutExecs)
        , ErrorMsg(ErrorMsg)
    {}

    /// It's responsible for updating the state of the latent 
    /// action while it is waiting for a response from the OVR Platform.
    virtual void UpdateOperation(FLatentResponse& Response) override;

#if WITH_EDITOR
    // Returns a human readable description of the latent operation's current state
    virtual FString GetDescription() const override;
#endif
};

/// It's a latent action for most blueprint nodes that wait for OVR Platform responses. 
/// It provides a way to handle requests for paged arrays in a latent manner, allowing for the processing of responses, such as UOvrPageRequestsBlueprintLibrary::FetchAchievementDefinitionPage.
class FOvrPageRequestLatentAction
    : public FOvrPreemptableLatentAction
{
public:
    /// \brief This variable indicates whether the "then" pin of the latent action has been executed.
    bool bThenPinExecuted;
    /// \brief This variable indicates whether the response from the Oculus VR Platform (OVRP) Subsystem has been processed.
    bool bResponseProcessed;
    /// \brief This variable indicates whether the request to the OVRP Subsystem was successful.
    bool bRequestSuccessful;
    /// \brief The current page number. This output pin is used to pass an array of execution pins back to the blueprint. Each execution pin represents a page of data that was retrieved from the OVRP Subsystem.
    EOvrPageRequestOutputPins& OutExecs;
    /// \brief This output pin is used to pass an error message back to the blueprint if the request to the OVRP Subsystem failed.
    FString& ErrorMsg;

    FOvrPageRequestLatentAction(const FLatentActionInfo& LatentInfo, EOvrPageRequestOutputPins& OutExecs, FString& ErrorMsg, OvrPlatformRequestGenerator&& RG, OvrPlatformResponseProcessor&& RP)
        : FOvrPreemptableLatentAction(LatentInfo, std::move(RG), std::move(RP))
        , bThenPinExecuted(false)
        , bResponseProcessed(false)
        , bRequestSuccessful(false)
        , OutExecs(OutExecs)
        , ErrorMsg(ErrorMsg)
    {}

    /// \brief It's responsible for updating the state of the latent action based on the current state of the request to the Oculus VR Platform (OVRP) Subsystem.
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
