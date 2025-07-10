// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OVRPlatformRequestsSupport.h"
#include "Engine/GameInstance.h"

// ----------------------------------------------------------------------
// FOvrPreemptableLatentAction

FOvrPreemptableLatentAction::~FOvrPreemptableLatentAction()
{
    UnlinkRequestDelegate();
}

UOvrPlatformSubsystem* FOvrPreemptableLatentAction::GetOvrPlatform()
{
    // Caching OVRP with static will crash when running in most editor modes the second time you run the game.
    UOvrPlatformSubsystem* OvrPlatform = nullptr;

    if (CallbackTarget.IsValid() && CallbackTarget.Get()->GetWorld())
    {
        OvrPlatform = CallbackTarget.Get()->GetWorld()->GetGameInstance()->GetSubsystem<UOvrPlatformSubsystem>();
    }

    return OvrPlatform;
}

void FOvrPreemptableLatentAction::UnlinkRequestDelegate()
{
    // Remove response handler from Oculus Platform Subsystem.
    if (RequestID)
    {
        auto OvrPlatform = GetOvrPlatform();
        if (OvrPlatform)
        {
            OvrPlatform->RemoveRequestDelegate(RequestID);
        }
        RequestID = 0;
    }
}

void FOvrPreemptableLatentAction::IgnoreResponse()
{
    if (!bIgnoreResponse)
    {
        bIgnoreResponse = true;
        UnlinkRequestDelegate();
    }
}

void FOvrPreemptableLatentAction::NotifyObjectDestroyed()
{
    UnlinkRequestDelegate();
}

// ----------------------------------------------------------------------
// FOvrRequestLatentAction

void FOvrRequestLatentAction::UpdateOperation(FLatentResponse& Response)
{
    // First update, we allow the flow to continue.
    if (!bThenPinExecuted)
    {
        // We have timed out while waiting.
        OutExecs = EOvrRequestOutputPins::Then;
        Response.TriggerLink(ExecutionFunction, OutputLink, CallbackTarget);
        bThenPinExecuted = true;
        return;
    }

    // Sending the request is next, even if we are asked to ignore the response.
    if (!RequestID)
    {
        // There are a few scenarios, such as the game instance construction, where
        // we can think that there will be a delay for the OVR Platform Subsystem
        // to be ready.
        UOvrPlatformSubsystem* OvrPlatform = GetOvrPlatform();
        if (!OvrPlatform)
        {
            return;
        }

        RequestID = RequestGenerator();

        if (!RequestID)
        {
            ErrorMsg = TEXT("Request generator failure.");
            OutExecs = EOvrRequestOutputPins::Failure;
            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
            return;
        }

        if (!bIgnoreResponse)
        {
            OvrPlatform->AddRequestDelegate(
                RequestID,
                FOvrPlatformMessageOnComplete::CreateLambda(
                    [this](TOvrMessageHandlePtr MessagePtr, bool bIsError)
                    {
                        // ResponseProcessors always clear outputs to defaults, even in case of error.
                        ResponseProcessor(MessagePtr, bIsError);

                        if (bIsError)
                        {
                            ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                            ErrorMsg = FString(ovr_Error_GetMessage(Error));
                        }
                        else
                        {
                            bRequestSuccessful = true;
                            ErrorMsg.Reset(0);
                        }

                        bResponseProcessed = true;
                    }
                ));
        }

        return;
    }

    // If asked to ignore the response, we are done without triggering an exit pin.
    if (bIgnoreResponse)
    {
        Response.DoneIf(true);
        return;
    }

    // Exit if response processed.
    if (bResponseProcessed)
    {
        OutExecs = bRequestSuccessful ? EOvrRequestOutputPins::Success : EOvrRequestOutputPins::Failure;
        Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        return;
    }
}

#if WITH_EDITOR
// Returns a human readable description of the latent operation's current state
FString FOvrRequestLatentAction::GetDescription() const
{
    FString Msg = TEXT("proper description should go here");
    return Msg;
}
#endif

// ----------------------------------------------------------------------
// FOvrPageRequestLatentAction

void FOvrPageRequestLatentAction::UpdateOperation(FLatentResponse& Response)
{
    // First update, we allow the flow to continue.
    if (!bThenPinExecuted)
    {
        // We have timed out while waiting.
        OutExecs = EOvrPageRequestOutputPins::Then;
        Response.TriggerLink(ExecutionFunction, OutputLink, CallbackTarget);
        bThenPinExecuted = true;
        return;
    }

    // Sending the request is next, even if we are asked to ignore the response.
    if (!RequestID)
    {
        // There are a few scenarios, such as the game instance construction, where
        // we can think that there will be a delay for the OVR Platform Subsystem
        // to be ready.
        UOvrPlatformSubsystem* OvrPlatform = GetOvrPlatform();
        if (!OvrPlatform)
        {
            return;
        }

        RequestID = RequestGenerator();

        if (!RequestID)
        {
            ErrorMsg = TEXT("Request generator failure.");
            OutExecs = EOvrPageRequestOutputPins::Failure;
            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
            return;
        }
        else if (RequestID == OVR_REQUEST_IMMEDIATE)
        {
            ErrorMsg.Reset(0);
            OutExecs = EOvrPageRequestOutputPins::PageReady;
            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
            return;
        }
        else if (RequestID == OVR_REQUEST_NO_MORE_PAGES)
        {
            ErrorMsg.Reset(0);
            OutExecs = EOvrPageRequestOutputPins::NoMorePages;
            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
            return;
        }

        if (!bIgnoreResponse)
        {
            OvrPlatform->AddRequestDelegate(
                RequestID,
                FOvrPlatformMessageOnComplete::CreateLambda(
                    [this](TOvrMessageHandlePtr MessagePtr, bool bIsError)
                    {
                        // ResponseProcessors always clear outputs to defaults, even in case of error.
                        ResponseProcessor(MessagePtr, bIsError);

                        if (bIsError)
                        {
                            ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                            ErrorMsg = FString(ovr_Error_GetMessage(Error));
                        }
                        else
                        {
                            bRequestSuccessful = true;
                            ErrorMsg.Reset(0);
                        }

                        bResponseProcessed = true;
                    }
                ));
        }

        return;
    }

    // If asked to ignore the response, we are done without triggering an exit pin.
    if (bIgnoreResponse)
    {
        Response.DoneIf(true);
        return;
    }

    // Exit if response processed.
    if (bResponseProcessed)
    {
        OutExecs = bRequestSuccessful ? EOvrPageRequestOutputPins::PageReady : EOvrPageRequestOutputPins::Failure;
        Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        return;
    }
}

#if WITH_EDITOR
// Returns a human readable description of the latent operation's current state
FString FOvrPageRequestLatentAction::GetDescription() const
{
    FString Msg = TEXT("proper description should go here");
    return Msg;
}
#endif
