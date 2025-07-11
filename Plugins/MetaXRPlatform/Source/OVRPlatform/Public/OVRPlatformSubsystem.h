// Copyright (c) Meta Platforms, Inc. and affiliates.

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
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOvrNotification_Cowatching_ApiNotReady, const FString&, ApiNotReady);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOvrNotification_Cowatching_ApiReady, const FString&, ApiReady);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOvrNotification_Cowatching_InSessionChanged, const FOvrCowatchingState&, InSessionChanged);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOvrNotification_Cowatching_Initialized, const FString&, Initialized);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOvrNotification_Cowatching_PresenterDataChanged, const FString&, PresenterDataChanged);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOvrNotification_Cowatching_SessionStarted, const FString&, SessionStarted);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOvrNotification_Cowatching_SessionStopped, const FString&, SessionStopped);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOvrNotification_Cowatching_ViewersDataChanged, const FOvrCowatchViewerUpdate&, ViewersDataChanged);
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
/// UOvrPlatformSubsystem is a class that provides functionality for interacting with the Oculus platform.
/// It includes several public member functions and attributes, and its attributes include delegates for various Oculus platform notifications.
/// See more info about Platform Solutions [here](https://developer.oculus.com/documentation/unreal/ps-platform-intro/).
class OVRPLATFORM_API UOvrPlatformSubsystem
    : public UGameInstanceSubsystem
    , public FTickableGameObject
{
    GENERATED_BODY()

public:
    /**
    * Determines whether the subsystem should be created.
    *
    * @param Outer The outer object that this subsystem is being created for.
    * @return True if the subsystem should be created, false otherwise.
    */
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
    /**
    * Initializes the subsystem.
    *
    * This function is called when the subsystem is first created. It is responsible for setting up any initial state or resources that the subsystem needs to operate.
    *
    * @param Collection The collection of subsystems that this subsystem is a part of.
    */
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    /**
    * Deinitializes the subsystem.
    *
    * This function is called when the subsystem is being shut down. It is responsible for releasing any resources or cleaning up any state that was created during initialization.
    */
    virtual void Deinitialize() override;

private:

    // Whether this instance of subsystem being initiated is the first one in multiplayer context
    static bool bFirstInstanceInit;
    bool bOculusInit = false;

#if PLATFORM_WINDOWS
    bool InitWithWindowsPlatform();
#elif PLATFORM_ANDROID
    bool InitWithAndroidPlatform();
#endif
    void StartAsyncInit();
    void GetAuthEmailAndPassword(FString& EmailOut, FString& PasswordOut);
    FString GetAppId();
    bool GetDoAsyncInit();
    bool IsEmailAndPasswordAuthRequested();
    bool IsEmailAndPasswordAuthRequested(const FString& Email, const FString& Password);

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

    /**
    * Adds a delegate to be called when an OVR request completes.
    *
    * This function allows you to register a callback function that will be executed when a specific OVR request completes.The delegate will be passed a single argument, which is the result of the request.
    *
    * @param RequestId The ID of the request that the delegate will be called for.
    * @param Delegate The delegate to be called when the request completes. The delegate should take a single argument of type FOvrPlatformMessageOnComplete.
    */
    void AddRequestDelegate(ovrRequest RequestId, FOvrPlatformMessageOnComplete&& Delegate);

    /**
    * Removes a delegate that was previously added with AddRequestDelegate.
    *
    * This function removes a delegate that was previously registered to be called when an OVR request completes.
    *
    * @param RequestId The ID of the request that the delegate was added for.
    */
    void RemoveRequestDelegate(ovrRequest RequestId);

    /**
    * Gets a multicast delegate that will be called for all messages of a specific type.
    *
    * This function returns a reference to a multicast delegate that will be called for all messages of a specific type. You can use this delegate to register a callback function that will be executed whenever a message of the specified type is received.
    *
    * @param MessageType The type of message that the delegate will be called for.
    * @return A reference to the multicast delegate. The delegate should take a single argument of type FOvrPlatformMulticastMessageOnComplete.
    */
    FOvrPlatformMulticastMessageOnComplete& GetNotifDelegate(ovrMessageType MessageType);
    /**
    * Removes a delegate that was previously registered with GetNotifDelegate.
    *
    * This function removes a delegate that was previously registered to be called for all messages of a specific type.
    *
    * @param MessageType The type of message that the delegate was registered for.
    * @param Delegate The delegate to remove.
    */
    void RemoveNotifDelegate(ovrMessageType MessageType, const FDelegateHandle& Delegate);

public: // Notifications

    /** The user has tapped the report button in the panel that appears after pressing the Oculus button. */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|AbuseReport")
    FOvrNotification_AbuseReport_ReportButtonPressed OnAbuseReportReportButtonPressed;

    /**
     * This event is triggered when a launch intent is received, whether it's a cold or warm start.
     * The payload contains the type of intent that was received. To obtain additional details,
     * you should call the UOvrFunctionsBlueprintLibrary::ApplicationLifecycle_GetLaunchDetails function.
     */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|ApplicationLifecycle")
    FOvrNotification_ApplicationLifecycle_LaunchIntentChanged OnApplicationLifecycleLaunchIntentChanged;

    /** Sent to indicate download progress for asset files. */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|AssetFile")
    FOvrNotification_AssetFile_DownloadUpdate OnAssetFileDownloadUpdate;

    /** Sets a callback function that will be triggered when the user is no longer in a copresent state and cowatching actions should not be performed. */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|Cowatching")
    FOvrNotification_Cowatching_ApiNotReady OnCowatchingApiNotReady;

    /** Sets a callback function that will be triggered when the user is in a copresent state and cowatching is ready to begin. */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|Cowatching")
    FOvrNotification_Cowatching_ApiReady OnCowatchingApiReady;

    /** Sets a callback function that will be triggered when the current user joins/leaves the cowatching session. */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|Cowatching")
    FOvrNotification_Cowatching_InSessionChanged OnCowatchingInSessionChanged;

    /** Sets a callback function that will be triggered when the cowatching API has been initialized. At this stage, the API is not yet ready for use. */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|Cowatching")
    FOvrNotification_Cowatching_Initialized OnCowatchingInitialized;

    /** Sets a callback function that will be triggered when the presenter updates the presenter data. */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|Cowatching")
    FOvrNotification_Cowatching_PresenterDataChanged OnCowatchingPresenterDataChanged;

    /** Sets a callback function that will be triggered when a user has started a cowatching session, and the ID of the session is reflected in the payload. */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|Cowatching")
    FOvrNotification_Cowatching_SessionStarted OnCowatchingSessionStarted;

    /** Sets a callback function that will be triggered when a cowatching session has ended. */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|Cowatching")
    FOvrNotification_Cowatching_SessionStopped OnCowatchingSessionStopped;

    /** Sets a callback function that will be triggered when a user joins or updates their viewer data. */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|Cowatching")
    FOvrNotification_Cowatching_ViewersDataChanged OnCowatchingViewersDataChanged;

    /**
     * Sent when the user is finished using the invite panel to send out invitations. Contains a list of invitees.
     * Parameter: Callback is a function that will be called when the invitation sent status changes.
     * FOvrLaunchInvitePanelFlowResult has 1 member:
     * UserList field FOvrLaunchInvitePanelFlowResult::InvitedUsers - A list of users that were sent an invitation to the session.
     */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|GroupPresence")
    FOvrNotification_GroupPresence_InvitationsSent OnGroupPresenceInvitationsSent;

    /**
     * Sent when a user has chosen to join the destination/lobby/match.
     * Read all the fields to figure out where the user wants to go and take
     * the appropriate actions to bring them there. If the user is unable to go there,
     * provide adequate messaging to the user on why they cannot go there.
     * These notifications should be responded to immediately.
     * Parameter: Callback is a function that will be called when a user has chosen to join the destination/lobby/match.
     * FOvrGroupPresenceJoinIntent has 4 members:
     * string field FOvrGroupPresenceJoinIntent::DeeplinkMessage - An opaque string provided by the developer to help them deeplink to content.
     * string field FOvrGroupPresenceJoinIntent::DestinationApiName - The destination the current user wants to go to.
     * string field FOvrGroupPresenceJoinIntent::LobbySessionId - The lobby session the current user wants to go to.
     * string field FOvrGroupPresenceJoinIntent::MatchSessionId - The match session the current user wants to go to.
     */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|GroupPresence")
    FOvrNotification_GroupPresence_JoinIntentReceived OnGroupPresenceJoinIntentReceived;

    /**
     * Sent when the user has chosen to leave the destination/lobby/match from the Oculus menu.
     * Read the specific fields to check the user is currently from the destination/lobby/match and take the appropriate actions to remove them.
     * Update the user's presence clearing the appropriate fields to indicate the user has left.
     * Parameter: Callback is a function that will be called when the user has chosen to leave the destination/lobby/match.
     * FOvrGroupPresenceLeaveIntent has 3 members:
     * string field FOvrGroupPresenceLeaveIntent::DestinationApiName - The destination the current user wants to leave.
     * string field FOvrGroupPresenceLeaveIntent::LobbySessionId - The lobby session the current user wants to leave.
     * string field FOvrGroupPresenceLeaveIntent::MatchSessionId - The match session the current user wants to leave.
     */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|GroupPresence")
    FOvrNotification_GroupPresence_LeaveIntentReceived OnGroupPresenceLeaveIntentReceived;

    /** Sent to indicate that more data has been read or an error occured. */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|HTTP")
    FOvrNotification_HTTP_Transfer OnHTTPTransfer;

    /**
     * Indicates that the livestreaming session has been updated. You can use this information to
     * throttle your game performance or increase CPU/GPU performance.  Use
     * FOvrLivestreamingStatus to extract the updated livestreaming status.
     */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|Livestreaming")
    FOvrNotification_Livestreaming_StatusChange OnLivestreamingStatusChange;

    /** Sent when the status of a connection has changed. The payload will be a type of FOvrNetSyncConnection. */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|NetSync")
    FOvrNotification_NetSync_ConnectionStatusChanged OnNetSyncConnectionStatusChanged;

    /**
     * Sent when the list of known connected sessions has changed. Contains
     * the new list of sessions. The payload will be a type of FOvrNetSyncSessionsChangedNotification.
     */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|NetSync")
    FOvrNotification_NetSync_SessionsChanged OnNetSyncSessionsChanged;

    /** Indicates that party has been updated. This will return a FOvrPartyUpdateNotification object. */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|Party")
    FOvrNotification_Party_PartyUpdate OnPartyPartyUpdate;

    /** Indicates that the current microphone availability state has been updated. Use UOvrRequestsBlueprintLibrary::Voip_GetMicrophoneAvailability() to extract the microphone availability state. */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|Voip")
    FOvrNotification_Voip_MicrophoneAvailabilityStateUpdate OnVoipMicrophoneAvailabilityStateUpdate;

    /**
     * Sent to indicate that some part of the overall state of SystemVoip
     * has changed. Use field FOvrSystemVoipState::Status and
     * the properties of FOvrSystemVoipState to extract the state that triggered the
     * notification.
     * Note that the state may have changed further since the notification was
     * generated, and that you may call the `GetSystemVoip...()` family of functions at any time
     * to get the current state directly.
     */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|Voip")
    FOvrNotification_Voip_SystemVoipState OnVoipSystemVoipState;

    /**
     * Gets VR camera related WebRTC data channel messages for update. This method is used to retrieve messages that are sent over the WebRTC
     * data channel, which can include information about the VR camera system, such as its current state or any errors that may have occurred. 
     */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|Vrcamera")
    FOvrNotification_Vrcamera_GetDataChannelMessageUpdate OnVrcameraGetDataChannelMessageUpdate;

    /**
     * Gets the surface and update action from the platform WebRTC for update. This method is used to retrieve information about
     * the current state of the VR camera system, including any updates that may be required.
     * See more info about Platform Solutions [here](https://developer.oculus.com/documentation/unreal/ps-platform-intro/).
     */
    UPROPERTY(BlueprintAssignable, Category = "OvrPlatform|Vrcamera")
    FOvrNotification_Vrcamera_GetSurfaceUpdate OnVrcameraGetSurfaceUpdate;

private: // Notification delegate handles and handlers

    FDelegateHandle OnAbuseReportReportButtonPressedHandle;
    void HandleOnAbuseReportReportButtonPressed(TOvrMessageHandlePtr Message, bool bIsError);

    FDelegateHandle OnApplicationLifecycleLaunchIntentChangedHandle;
    void HandleOnApplicationLifecycleLaunchIntentChanged(TOvrMessageHandlePtr Message, bool bIsError);

    FDelegateHandle OnAssetFileDownloadUpdateHandle;
    void HandleOnAssetFileDownloadUpdate(TOvrMessageHandlePtr Message, bool bIsError);

    FDelegateHandle OnCowatchingApiNotReadyHandle;
    void HandleOnCowatchingApiNotReady(TOvrMessageHandlePtr Message, bool bIsError);

    FDelegateHandle OnCowatchingApiReadyHandle;
    void HandleOnCowatchingApiReady(TOvrMessageHandlePtr Message, bool bIsError);

    FDelegateHandle OnCowatchingInSessionChangedHandle;
    void HandleOnCowatchingInSessionChanged(TOvrMessageHandlePtr Message, bool bIsError);

    FDelegateHandle OnCowatchingInitializedHandle;
    void HandleOnCowatchingInitialized(TOvrMessageHandlePtr Message, bool bIsError);

    FDelegateHandle OnCowatchingPresenterDataChangedHandle;
    void HandleOnCowatchingPresenterDataChanged(TOvrMessageHandlePtr Message, bool bIsError);

    FDelegateHandle OnCowatchingSessionStartedHandle;
    void HandleOnCowatchingSessionStarted(TOvrMessageHandlePtr Message, bool bIsError);

    FDelegateHandle OnCowatchingSessionStoppedHandle;
    void HandleOnCowatchingSessionStopped(TOvrMessageHandlePtr Message, bool bIsError);

    FDelegateHandle OnCowatchingViewersDataChangedHandle;
    void HandleOnCowatchingViewersDataChanged(TOvrMessageHandlePtr Message, bool bIsError);

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
    bool bMessagePumpActivated = false;

    virtual void Tick(float DeltaTime) override;
    virtual bool IsTickable() const override;
    virtual TStatId GetStatId() const override;

    void OnReceiveMessage(ovrMessageHandle Message);

    // Map of a specific request id to a specific delegate.
    TMap<uint64, FOvrPlatformMessageOnComplete> RequestDelegates;

    // Map of message type to multicast delegate.
    TMap<ovrMessageType, FOvrPlatformMulticastMessageOnComplete> NotifDelegates;
};
