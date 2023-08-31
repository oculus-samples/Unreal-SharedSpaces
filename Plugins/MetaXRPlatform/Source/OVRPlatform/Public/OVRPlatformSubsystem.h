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

// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#pragma once

#include "CoreMinimal.h"
#include "Tickable.h"
#include "Subsystems/GameInstanceSubsystem.h"

#include "OVRPlatformSDK.h"
#include "OVRPlatformTypes.h"
#include "OVRPlatformModels.h"
#include "OVRPlatformSubsystem.generated.h"

#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#endif

// Message Pump Delegates
DECLARE_DELEGATE_TwoParams(FOvrPlatformMessageOnComplete, TOvrMessageHandlePtr, bool);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOvrPlatformMulticastMessageOnComplete, TOvrMessageHandlePtr, bool);

// OVR Platform Notifications
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOvrNotification_AbuseReport_ReportButtonPressed, const FString&, ReportButtonPressed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOvrNotification_ApplicationLifecycle_LaunchIntentChanged, const FString&, LaunchIntentChanged);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOvrNotification_AssetFile_DownloadUpdate, const FOvrAssetFileDownloadUpdate&, DownloadUpdate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOvrNotification_GroupPresence_InvitationsSent, const FOvrLaunchInvitePanelFlowResult&, InvitationsSent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOvrNotification_GroupPresence_JoinIntentReceived, const FOvrGroupPresenceJoinIntent&, JoinIntentReceived);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOvrNotification_GroupPresence_LeaveIntentReceived, const FOvrGroupPresenceLeaveIntent&, LeaveIntentReceived);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOvrNotification_HTTP_Transfer, const FOvrHttpTransferUpdate&, Transfer);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOvrNotification_Livestreaming_StatusChange, const FOvrLivestreamingStatus&, StatusChange);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOvrNotification_NetSync_ConnectionStatusChanged, const FOvrNetSyncConnection&, ConnectionStatusChanged);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOvrNotification_NetSync_SessionsChanged, const FOvrNetSyncSessionsChangedNotification&, SessionsChanged);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOvrNotification_Party_PartyUpdate, const FOvrPartyUpdateNotification&, PartyUpdate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOvrNotification_Voip_MicrophoneAvailabilityStateUpdate, const FString&, MicrophoneAvailabilityStateUpdate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOvrNotification_Voip_SystemVoipState, const FOvrSystemVoipState&, SystemVoipState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOvrNotification_Vrcamera_GetDataChannelMessageUpdate, const FString&, GetDataChannelMessageUpdate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOvrNotification_Vrcamera_GetSurfaceUpdate, const FString&, GetSurfaceUpdate);

// OVR Platform Subsystem
UCLASS(Blueprintable)
class OVRPLATFORM_API UOvrPlatformSubsystem
    : public UGameInstanceSubsystem
    , public FTickableGameObject
{
    GENERATED_BODY()

public:

    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;

private:

    bool bOculusInit;

#if PLATFORM_WINDOWS
    bool InitWithWindowsPlatform();
#elif PLATFORM_ANDROID
    bool InitWithAndroidPlatform();
#endif
    FString GetAppId();

    // OVR Notifications (handle and handler)
    FDelegateHandle OnPlatformInitializedStandaloneHandle;
    void HandleOnPlatformInitialized(TOvrMessageHandlePtr Message, bool bIsError);

    // Notification to the game instance that we are ready.
    void NotifyGameInstanceThatSubsystemStarted(bool bOculusPlatformIsInitialized) const;

public:

    /**
     * The subsystem waits for your authorization to start processing messages, allowing
     * you to register your callbacks first.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Subsystem")
    void StartMessagePump();

public:

    // You can make direct OVR requests and register for responses.
    void AddRequestDelegate(ovrRequest RequestId, FOvrPlatformMessageOnComplete&& Delegate);
    void RemoveRequestDelegate(ovrRequest RequestId);

    // You can also register to be notified of any message type.
    FOvrPlatformMulticastMessageOnComplete& GetNotifDelegate(ovrMessageType MessageType);
    void RemoveNotifDelegate(ovrMessageType MessageType, const FDelegateHandle& Delegate);

public: // Notifications

    /** The user has tapped the report button in the panel that appears after pressing the Oculus button. */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|AbuseReport")
    FOvrNotification_AbuseReport_ReportButtonPressed OnAbuseReportReportButtonPressed;

    /**
     * Sent when a launch intent is received (for both cold and warm starts).
     * The payload is the type of the intent.
     * ApplicationLifecycle_GetLaunchDetails() should be called to
     * get the other details.
     */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|ApplicationLifecycle")
    FOvrNotification_ApplicationLifecycle_LaunchIntentChanged OnApplicationLifecycleLaunchIntentChanged;

    /** Sent to indicate download progress for asset files. */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|AssetFile")
    FOvrNotification_AssetFile_DownloadUpdate OnAssetFileDownloadUpdate;

    /**
     * Sent when the user is finished using the invite panel to send out invitations.
     * Contains a list of invitees.
     */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|GroupPresence")
    FOvrNotification_GroupPresence_InvitationsSent OnGroupPresenceInvitationsSent;

    /**
     * Sent when a user has chosen to join the destination/lobby/match. Read all
     * the fields to figure out where the user wants to go and take the appropriate
     * actions to bring them there. If the user is unable to go there, provide adequate
     * messaging to the user on why they cannot go there. These notifications should
     * be responded to immediately.
     */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|GroupPresence")
    FOvrNotification_GroupPresence_JoinIntentReceived OnGroupPresenceJoinIntentReceived;

    /**
     * Sent when the user has chosen to leave the destination/lobby/match from
     * the Oculus menu. Read the specific fields to check the user is currently from
     * the destination/lobby/match and take the appropriate actions to remove them.
     * Update the user's presence clearing the appropriate fields to indicate the user
     * has left. 
     */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|GroupPresence")
    FOvrNotification_GroupPresence_LeaveIntentReceived OnGroupPresenceLeaveIntentReceived;

    /** Sent to indicate that more data has been read or an error occured. */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|HTTP")
    FOvrNotification_HTTP_Transfer OnHTTPTransfer;

    /**
     * Indicates that the livestreaming session has been updated. You can use this information to
     * throttle your game performance or increase CPU/GPU performance.  Use
     * field FOvrMessage::LivestreamingStatus to extract the updated livestreaming status.
     */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|Livestreaming")
    FOvrNotification_Livestreaming_StatusChange OnLivestreamingStatusChange;

    /** Sent when the status of a connection has changed. */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|NetSync")
    FOvrNotification_NetSync_ConnectionStatusChanged OnNetSyncConnectionStatusChanged;

    /**
     * Sent when the list of known connected sessions has changed. Contains
     * the new list of sessions.
     */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|NetSync")
    FOvrNotification_NetSync_SessionsChanged OnNetSyncSessionsChanged;

    /** Indicates that party has been updated */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|Party")
    FOvrNotification_Party_PartyUpdate OnPartyPartyUpdate;

    /** Indicates that the current microphone availability state has been updated. Use Voip_GetMicrophoneAvailability() to extract the microphone availability state. */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|Voip")
    FOvrNotification_Voip_MicrophoneAvailabilityStateUpdate OnVoipMicrophoneAvailabilityStateUpdate;

    /**
     * Sent to indicate that some part of the overall state of SystemVoip
     * has changed. Use field FOvrMessage::SystemVoipState and
     * the properties of FOvrSystemVoipState to extract the state that triggered the
     * notification.
     * 
     * Note that the state may have changed further since the notification was
     * generated, and that you may call the `GetSystemVoip...()` family of functions at any time
     * to get the current state directly.
     */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|Voip")
    FOvrNotification_Voip_SystemVoipState OnVoipSystemVoipState;

    /** Get vr camera related webrtc data channel messages for update. */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|Vrcamera")
    FOvrNotification_Vrcamera_GetDataChannelMessageUpdate OnVrcameraGetDataChannelMessageUpdate;

    /** Get surface and update action from platform webrtc for update. */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|Vrcamera")
    FOvrNotification_Vrcamera_GetSurfaceUpdate OnVrcameraGetSurfaceUpdate;

private: // Notification delegate handles and handlers

    FDelegateHandle OnAbuseReportReportButtonPressedHandle;
    void HandleOnAbuseReportReportButtonPressed(TOvrMessageHandlePtr Message, bool bIsError);

    FDelegateHandle OnApplicationLifecycleLaunchIntentChangedHandle;
    void HandleOnApplicationLifecycleLaunchIntentChanged(TOvrMessageHandlePtr Message, bool bIsError);

    FDelegateHandle OnAssetFileDownloadUpdateHandle;
    void HandleOnAssetFileDownloadUpdate(TOvrMessageHandlePtr Message, bool bIsError);

    FDelegateHandle OnGroupPresenceInvitationsSentHandle;
    void HandleOnGroupPresenceInvitationsSent(TOvrMessageHandlePtr Message, bool bIsError);

    FDelegateHandle OnGroupPresenceJoinIntentReceivedHandle;
    void HandleOnGroupPresenceJoinIntentReceived(TOvrMessageHandlePtr Message, bool bIsError);

    FDelegateHandle OnGroupPresenceLeaveIntentReceivedHandle;
    void HandleOnGroupPresenceLeaveIntentReceived(TOvrMessageHandlePtr Message, bool bIsError);

    FDelegateHandle OnHTTPTransferHandle;
    void HandleOnHTTPTransfer(TOvrMessageHandlePtr Message, bool bIsError);

    FDelegateHandle OnLivestreamingStatusChangeHandle;
    void HandleOnLivestreamingStatusChange(TOvrMessageHandlePtr Message, bool bIsError);

    FDelegateHandle OnNetSyncConnectionStatusChangedHandle;
    void HandleOnNetSyncConnectionStatusChanged(TOvrMessageHandlePtr Message, bool bIsError);

    FDelegateHandle OnNetSyncSessionsChangedHandle;
    void HandleOnNetSyncSessionsChanged(TOvrMessageHandlePtr Message, bool bIsError);

    FDelegateHandle OnPartyPartyUpdateHandle;
    void HandleOnPartyPartyUpdate(TOvrMessageHandlePtr Message, bool bIsError);

    FDelegateHandle OnVoipMicrophoneAvailabilityStateUpdateHandle;
    void HandleOnVoipMicrophoneAvailabilityStateUpdate(TOvrMessageHandlePtr Message, bool bIsError);

    FDelegateHandle OnVoipSystemVoipStateHandle;
    void HandleOnVoipSystemVoipState(TOvrMessageHandlePtr Message, bool bIsError);

    FDelegateHandle OnVrcameraGetDataChannelMessageUpdateHandle;
    void HandleOnVrcameraGetDataChannelMessageUpdate(TOvrMessageHandlePtr Message, bool bIsError);

    FDelegateHandle OnVrcameraGetSurfaceUpdateHandle;
    void HandleOnVrcameraGetSurfaceUpdate(TOvrMessageHandlePtr Message, bool bIsError);

private: // Message pump.

    // The message pump need to be explicity started with StartMessagePump()
    bool bMessagePumpActivated;

    virtual void Tick(float DeltaTime) override;
    virtual bool IsTickable() const override;
    virtual TStatId GetStatId() const override;

    void OnReceiveMessage(ovrMessageHandle Message);

    // Map of a specific request id to a specific delegate.
    TMap<uint64, FOvrPlatformMessageOnComplete> RequestDelegates;

    // Map of message type to multicast delegate.
    TMap<ovrMessageType, FOvrPlatformMulticastMessageOnComplete> NotifDelegates;
};
