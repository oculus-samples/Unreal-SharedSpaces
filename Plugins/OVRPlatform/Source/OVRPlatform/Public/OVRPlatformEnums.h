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
#include "OVR_Platform.h"

#include "OVR_AbuseReportType.h"
#include "OVR_AchievementType.h"
#include "OVR_ChallengeCreationType.h"
#include "OVR_ChallengeViewerFilter.h"
#include "OVR_ChallengeVisibility.h"
#include "OVR_CloudStorageDataStatus.h"
#include "OVR_CloudStorageUpdateStatus.h"
#include "OVR_KeyValuePairType.h"
#include "OVR_LaunchResult.h"
#include "OVR_LaunchType.h"
#include "OVR_LeaderboardFilterType.h"
#include "OVR_LeaderboardStartAt.h"
#include "OVR_LivestreamingStartStatus.h"
#include "OVR_LogEventName.h"
#include "OVR_LogEventParameter.h"
#include "OVR_MatchmakingCriterionImportance.h"
#include "OVR_MatchmakingStatApproach.h"
#include "OVR_MediaContentType.h"
#include "OVR_MultiplayerErrorErrorKey.h"
#include "OVR_NetSyncConnectionStatus.h"
#include "OVR_NetSyncDisconnectReason.h"
#include "OVR_NetSyncVoipMicSource.h"
#include "OVR_NetSyncVoipStreamMode.h"
#include "OVR_PartyUpdateAction.h"
#include "OVR_PeerConnectionState.h"
#include "OVR_PermissionGrantStatus.h"
#include "OVR_PlatformInitializeResult.h"
#include "OVR_ReportRequestResponse.h"
#include "OVR_RichPresenceExtraContext.h"
#include "OVR_RoomJoinPolicy.h"
#include "OVR_RoomJoinability.h"
#include "OVR_RoomMembershipLockStatus.h"
#include "OVR_RoomType.h"
#include "OVR_SdkAccountType.h"
#include "OVR_SendPolicy.h"
#include "OVR_ServiceProvider.h"
#include "OVR_ShareMediaStatus.h"
#include "OVR_SystemVoipStatus.h"
#include "OVR_TimeWindow.h"
#include "OVR_UserOrdering.h"
#include "OVR_UserPresenceStatus.h"
#include "OVR_VoipBitrate.h"
#include "OVR_VoipDtxState.h"
#include "OVR_VoipMuteState.h"
#include "OVR_VoipSampleRate.h"

#include "OVRPlatformEnums.generated.h"


/** AbuseReportType enumeration. */
UENUM(BlueprintType)
enum class EOvrAbuseReportType : uint8
{
    Unknown,
    /** A report for something besides a user, like a world. */
    Object,
    /** A report for a user's behavior or profile. */
    User,
};

ovrAbuseReportType ConvertAbuseReportType(EOvrAbuseReportType Value);
EOvrAbuseReportType ConvertAbuseReportType(ovrAbuseReportType Value);

/** AchievementType enumeration. */
UENUM(BlueprintType)
enum class EOvrAchievementType : uint8
{
    Unknown,
    Simple,
    Bitfield,
    Count,
};

ovrAchievementType ConvertAchievementType(EOvrAchievementType Value);
EOvrAchievementType ConvertAchievementType(ovrAchievementType Value);

/** ChallengeCreationType enumeration. */
UENUM(BlueprintType)
enum class EOvrChallengeCreationType : uint8
{
    Unknown,
    UserCreated,
    DeveloperCreated,
};

ovrChallengeCreationType ConvertChallengeCreationType(EOvrChallengeCreationType Value);
EOvrChallengeCreationType ConvertChallengeCreationType(ovrChallengeCreationType Value);

/** ChallengeViewerFilter enumeration. */
UENUM(BlueprintType)
enum class EOvrChallengeViewerFilter : uint8
{
    Unknown,
    AllVisible,
    Participating,
    Invited,
    ParticipatingOrInvited,
};

ovrChallengeViewerFilter ConvertChallengeViewerFilter(EOvrChallengeViewerFilter Value);
EOvrChallengeViewerFilter ConvertChallengeViewerFilter(ovrChallengeViewerFilter Value);

/** ChallengeVisibility enumeration. */
UENUM(BlueprintType)
enum class EOvrChallengeVisibility : uint8
{
    Unknown,
    /** Only those invited can participate in it. Everyone can see it */
    InviteOnly,
    /** Everyone can participate and see this challenge */
    Public,
    /** Only those invited can participate and see this challenge */
    Private,
};

ovrChallengeVisibility ConvertChallengeVisibility(EOvrChallengeVisibility Value);
EOvrChallengeVisibility ConvertChallengeVisibility(ovrChallengeVisibility Value);

/** CloudStorageDataStatus enumeration. */
UENUM(BlueprintType)
enum class EOvrCloudStorageDataStatus : uint8
{
    Unknown,
    InSync,
    NeedsDownload,
    RemoteDownloading,
    NeedsUpload,
    LocalUploading,
    InConflict,
};

ovrCloudStorageDataStatus ConvertCloudStorageDataStatus(EOvrCloudStorageDataStatus Value);
EOvrCloudStorageDataStatus ConvertCloudStorageDataStatus(ovrCloudStorageDataStatus Value);

/** CloudStorageUpdateStatus enumeration. */
UENUM(BlueprintType)
enum class EOvrCloudStorageUpdateStatus : uint8
{
    Unknown,
    Ok,
    BetterVersionStored,
    ManualMergeRequired,
};

ovrCloudStorageUpdateStatus ConvertCloudStorageUpdateStatus(EOvrCloudStorageUpdateStatus Value);
EOvrCloudStorageUpdateStatus ConvertCloudStorageUpdateStatus(ovrCloudStorageUpdateStatus Value);

/** KeyValuePairType enumeration. */
UENUM(BlueprintType)
enum class EOvrKeyValuePairType : uint8
{
    String,
    Int,
    Double,
    Unknown,
};

ovrKeyValuePairType ConvertKeyValuePairType(EOvrKeyValuePairType Value);
EOvrKeyValuePairType ConvertKeyValuePairType(ovrKeyValuePairType Value);

/** LaunchResult enumeration. */
UENUM(BlueprintType)
enum class EOvrLaunchResult : uint8
{
    Unknown,
    Success,
    FailedRoomFull,
    FailedGameAlreadyStarted,
    FailedRoomNotFound,
    FailedUserDeclined,
    FailedOtherReason,
};

ovrLaunchResult ConvertLaunchResult(EOvrLaunchResult Value);
EOvrLaunchResult ConvertLaunchResult(ovrLaunchResult Value);

/** LaunchType enumeration. */
UENUM(BlueprintType)
enum class EOvrLaunchType : uint8
{
    Unknown,
    Normal,
    Invite,
    Coordinated,
    Deeplink,
};

ovrLaunchType ConvertLaunchType(EOvrLaunchType Value);
EOvrLaunchType ConvertLaunchType(ovrLaunchType Value);

/** LeaderboardFilterType enumeration. */
UENUM(BlueprintType)
enum class EOvrLeaderboardFilterType : uint8
{
    None,
    Friends,
    Unknown,
    UserIds,
};

ovrLeaderboardFilterType ConvertLeaderboardFilterType(EOvrLeaderboardFilterType Value);
EOvrLeaderboardFilterType ConvertLeaderboardFilterType(ovrLeaderboardFilterType Value);

/** LeaderboardStartAt enumeration. */
UENUM(BlueprintType)
enum class EOvrLeaderboardStartAt : uint8
{
    Top,
    CenteredOnViewer,
    CenteredOnViewerOrTop,
    Unknown,
};

ovrLeaderboardStartAt ConvertLeaderboardStartAt(EOvrLeaderboardStartAt Value);
EOvrLeaderboardStartAt ConvertLeaderboardStartAt(ovrLeaderboardStartAt Value);

/** LivestreamingStartStatus enumeration. */
UENUM(BlueprintType)
enum class EOvrLivestreamingStartStatus : uint8
{
    Success = 1,
    Unknown = 0,
    NoPackageSet = uint8(-1),
    NoFbConnect = uint8(-2),
    NoSessionId = uint8(-3),
    MissingParameters = uint8(-4),
};

ovrLivestreamingStartStatus ConvertLivestreamingStartStatus(EOvrLivestreamingStartStatus Value);
EOvrLivestreamingStartStatus ConvertLivestreamingStartStatus(ovrLivestreamingStartStatus Value);

/** LogEventName enumeration. */
UENUM(BlueprintType)
enum class EOvrLogEventName : uint8
{
    Unknown,
    AdClick,
    AdImpression,
    VrCompleteRegistration,
    VrTutorialCompletion,
    Contact,
    CustomizeProduct,
    Donate,
    FindLocation,
    VrRate,
    Schedule,
    VrSearch,
    SmartTrial,
    SubmitApplication,
    Subscribe,
    VrContentView,
    VrSdkInitialize,
    VrSdkBackgroundStatusAvailable,
    VrSdkBackgroundStatusDenied,
    VrSdkBackgroundStatusRestricted,
    VrAddPaymentInfo,
    VrAddToCart,
    VrAddToWishlist,
    VrInitiatedCheckout,
    VrPurchase,
    VrCatalogUpdate,
    VrPurchaseFailed,
    VrPurchaseRestored,
    SubscriptionInitiatedCheckout,
    SubscriptionFailed,
    SubscriptionRestore,
    VrLevelAchieved,
    VrAchievementUnlocked,
    VrSpentCredits,
    VrObtainPushToken,
    VrPushOpened,
    VrActivateApp,
    VrDeactivateApp,
};

ovrLogEventName ConvertLogEventName(EOvrLogEventName Value);
EOvrLogEventName ConvertLogEventName(ovrLogEventName Value);

/** LogEventParameter enumeration. */
UENUM(BlueprintType)
enum class EOvrLogEventParameter : uint8
{
    Unknown,
    VrCurrency,
    VrRegistrationMethod,
    VrContentType,
    VrContent,
    VrContentId,
    VrSearchString,
    VrSuccess,
    VrMaxRatingValue,
    VrPaymentInfoAvailable,
    VrNumItems,
    VrLevel,
    VrDescription,
    AdType,
    VrOrderId,
    EventName,
    LogTime,
    ImplicitlyLogged,
    InBackground,
    VrPushCampaign,
    VrPushAction,
    VrIapProductType,
    VrContentTitle,
    VrTransactionId,
    VrTransactionDate,
    VrIapSubsPeriod,
    VrIapIsStartTrial,
    VrIapHasFreeTrial,
    VrIapTrialPeriod,
    VrIapTrialPrice,
    SessionId,
};

ovrLogEventParameter ConvertLogEventParameter(EOvrLogEventParameter Value);
EOvrLogEventParameter ConvertLogEventParameter(ovrLogEventParameter Value);

/** MatchmakingCriterionImportance enumeration. */
UENUM(BlueprintType)
enum class EOvrMatchmakingCriterionImportance : uint8
{
    Required,
    High,
    Medium,
    Low,
    Unknown,
};

ovrMatchmakingCriterionImportance ConvertMatchmakingCriterionImportance(EOvrMatchmakingCriterionImportance Value);
EOvrMatchmakingCriterionImportance ConvertMatchmakingCriterionImportance(ovrMatchmakingCriterionImportance Value);

/** MatchmakingStatApproach enumeration. */
UENUM(BlueprintType)
enum class EOvrMatchmakingStatApproach : uint8
{
    Unknown,
    Trailing,
    Swingy,
};

ovrMatchmakingStatApproach ConvertMatchmakingStatApproach(EOvrMatchmakingStatApproach Value);
EOvrMatchmakingStatApproach ConvertMatchmakingStatApproach(ovrMatchmakingStatApproach Value);

/** MediaContentType enumeration. */
UENUM(BlueprintType)
enum class EOvrMediaContentType : uint8
{
    Unknown,
    Photo,
};

ovrMediaContentType ConvertMediaContentType(EOvrMediaContentType Value);
EOvrMediaContentType ConvertMediaContentType(ovrMediaContentType Value);

/** MultiplayerErrorErrorKey enumeration. */
UENUM(BlueprintType)
enum class EOvrMultiplayerErrorErrorKey : uint8
{
    Unknown,
    DestinationUnavailable,
    DlcRequired,
    General,
    GroupFull,
    InviterNotJoinable,
    LevelNotHighEnough,
    LevelNotUnlocked,
    NetworkTimeout,
    NoLongerAvailable,
    UpdateRequired,
    TutorialRequired,
};

ovrMultiplayerErrorErrorKey ConvertMultiplayerErrorErrorKey(EOvrMultiplayerErrorErrorKey Value);
EOvrMultiplayerErrorErrorKey ConvertMultiplayerErrorErrorKey(ovrMultiplayerErrorErrorKey Value);

/** NetSyncConnectionStatus enumeration. */
UENUM(BlueprintType)
enum class EOvrNetSyncConnectionStatus : uint8
{
    Unknown,
    Connecting,
    Disconnected,
    Connected,
};

ovrNetSyncConnectionStatus ConvertNetSyncConnectionStatus(EOvrNetSyncConnectionStatus Value);
EOvrNetSyncConnectionStatus ConvertNetSyncConnectionStatus(ovrNetSyncConnectionStatus Value);

/** NetSyncDisconnectReason enumeration. */
UENUM(BlueprintType)
enum class EOvrNetSyncDisconnectReason : uint8
{
    Unknown,
    /** when disconnect was requested */
    LocalTerminated,
    /** server intentionally closed the connection */
    ServerTerminated,
    /** initial connection never succeeded */
    Failed,
    /** network timeout */
    Lost,
};

ovrNetSyncDisconnectReason ConvertNetSyncDisconnectReason(EOvrNetSyncDisconnectReason Value);
EOvrNetSyncDisconnectReason ConvertNetSyncDisconnectReason(ovrNetSyncDisconnectReason Value);

/** NetSyncVoipMicSource enumeration. */
UENUM(BlueprintType)
enum class EOvrNetSyncVoipMicSource : uint8
{
    Unknown,
    None,
    Internal,
};

ovrNetSyncVoipMicSource ConvertNetSyncVoipMicSource(EOvrNetSyncVoipMicSource Value);
EOvrNetSyncVoipMicSource ConvertNetSyncVoipMicSource(ovrNetSyncVoipMicSource Value);

/** NetSyncVoipStreamMode enumeration. */
UENUM(BlueprintType)
enum class EOvrNetSyncVoipStreamMode : uint8
{
    Unknown,
    Ambisonic,
    Mono,
};

ovrNetSyncVoipStreamMode ConvertNetSyncVoipStreamMode(EOvrNetSyncVoipStreamMode Value);
EOvrNetSyncVoipStreamMode ConvertNetSyncVoipStreamMode(ovrNetSyncVoipStreamMode Value);

/** PartyUpdateAction enumeration. */
UENUM(BlueprintType)
enum class EOvrPartyUpdateAction : uint8
{
    Unknown,
    Join,
    Leave,
    Invite,
    Uninvite,
};

ovrPartyUpdateAction ConvertPartyUpdateAction(EOvrPartyUpdateAction Value);
EOvrPartyUpdateAction ConvertPartyUpdateAction(ovrPartyUpdateAction Value);

/** PeerConnectionState enumeration. */
UENUM(BlueprintType)
enum class EOvrPeerConnectionState : uint8
{
    Unknown,
    /** Connection to the peer is established. */
    Connected,
    /**
     * A timeout expired while attempting to (re)establish a connection.  This
     * can happen if peer is unreachable or rejected the connection.
     */
    Timeout,
    /**
     * Connection to the peer is closed.  A connection transitions into
     * this state when it is explicitly closed by either the local or remote peer
     * calling Net_Close(). It also enters this state if the remote peer no longer responds to
     * our keep-alive probes.
     */
    Closed,
};

ovrPeerConnectionState ConvertPeerConnectionState(EOvrPeerConnectionState Value);
EOvrPeerConnectionState ConvertPeerConnectionState(ovrPeerConnectionState Value);

/** PermissionGrantStatus enumeration. */
UENUM(BlueprintType)
enum class EOvrPermissionGrantStatus : uint8
{
    Unknown,
    Granted,
    Denied,
    Blocked,
};

ovrPermissionGrantStatus ConvertPermissionGrantStatus(EOvrPermissionGrantStatus Value);
EOvrPermissionGrantStatus ConvertPermissionGrantStatus(ovrPermissionGrantStatus Value);

/**
 * Describes the various results possible when attempting to initialize the platform.
 * Anything other than ovrPlatformInitialize_Success should be considered a fatal error
 * with respect to using the platform, as the platform is not guaranteed to be legitimate
 * or work correctly.
 */
UENUM(BlueprintType)
enum class EOvrPlatformInitializeResult : uint8
{
    Success = 0,
    Uninitialized = uint8(-1),
    PreLoaded = uint8(-2),
    FileInvalid = uint8(-3),
    SignatureInvalid = uint8(-4),
    UnableToVerify = uint8(-5),
    VersionMismatch = uint8(-6),
    Unknown = uint8(-7),
    InvalidCredentials = uint8(-8),
    NotEntitled = uint8(-9),
};

ovrPlatformInitializeResult ConvertPlatformInitializeResult(EOvrPlatformInitializeResult Value);
EOvrPlatformInitializeResult ConvertPlatformInitializeResult(ovrPlatformInitializeResult Value);

/** ReportRequestResponse enumeration. */
UENUM(BlueprintType)
enum class EOvrReportRequestResponse : uint8
{
    Unknown,
    Handled,
    Unhandled,
    Unavailable,
};

ovrReportRequestResponse ConvertReportRequestResponse(EOvrReportRequestResponse Value);
EOvrReportRequestResponse ConvertReportRequestResponse(ovrReportRequestResponse Value);

/** Display extra information about the user's presence */
UENUM(BlueprintType)
enum class EOvrRichPresenceExtraContext : uint8
{
    Unknown,
    /** Display nothing */
    None,
    /** Display the current amount with the user over the max */
    CurrentCapacity,
    /** Display how long ago the match/game/race/etc started */
    StartedAgo,
    /** Display how soon the match/game/race/etc will end */
    EndingIn,
    /** Display that this user is looking for a match */
    LookingForAMatch,
};

ovrRichPresenceExtraContext ConvertRichPresenceExtraContext(EOvrRichPresenceExtraContext Value);
EOvrRichPresenceExtraContext ConvertRichPresenceExtraContext(ovrRichPresenceExtraContext Value);

/** RoomJoinPolicy enumeration. */
UENUM(BlueprintType)
enum class EOvrRoomJoinPolicy : uint8
{
    None,
    Everyone,
    FriendsOfMembers,
    FriendsOfOwner,
    InvitedUsers,
    Unknown,
};

ovrRoomJoinPolicy ConvertRoomJoinPolicy(EOvrRoomJoinPolicy Value);
EOvrRoomJoinPolicy ConvertRoomJoinPolicy(ovrRoomJoinPolicy Value);

/** RoomJoinability enumeration. */
UENUM(BlueprintType)
enum class EOvrRoomJoinability : uint8
{
    Unknown,
    AreIn,
    AreKicked,
    CanJoin,
    IsFull,
    NoViewer,
    PolicyPrevents,
};

ovrRoomJoinability ConvertRoomJoinability(EOvrRoomJoinability Value);
EOvrRoomJoinability ConvertRoomJoinability(ovrRoomJoinability Value);

/** RoomMembershipLockStatus enumeration. */
UENUM(BlueprintType)
enum class EOvrRoomMembershipLockStatus : uint8
{
    Unknown,
    Lock,
    Unlock,
};

ovrRoomMembershipLockStatus ConvertRoomMembershipLockStatus(EOvrRoomMembershipLockStatus Value);
EOvrRoomMembershipLockStatus ConvertRoomMembershipLockStatus(ovrRoomMembershipLockStatus Value);

/** RoomType enumeration. */
UENUM(BlueprintType)
enum class EOvrRoomType : uint8
{
    Unknown,
    Matchmaking,
    Moderated,
    Private,
    Solo,
};

ovrRoomType ConvertRoomType(EOvrRoomType Value);
EOvrRoomType ConvertRoomType(ovrRoomType Value);

/** SdkAccountType enumeration. */
UENUM(BlueprintType)
enum class EOvrSdkAccountType : uint8
{
    Unknown,
    Oculus,
    FacebookGameroom,
};

ovrSdkAccountType ConvertSdkAccountType(EOvrSdkAccountType Value);
EOvrSdkAccountType ConvertSdkAccountType(ovrSdkAccountType Value);

/** SendPolicy enumeration. */
UENUM(BlueprintType)
enum class EOvrSendPolicy : uint8
{
    /**
     * Sends a message using an unreliable data channel (UDP-based).  No delivery
     * or ordering guarantees are provided. Sending will fail unless a connection
     * to the peer is already established, either via a previous call to
     * Net_SendPacket() or an explicit Net_Connect().
     * 
     * 
     * Ideally, each message should fit into a single packet. Therefore, it is
     * recommended to keep them under 1200 bytes.
     */
    Unreliable,
    /**
     * Messages are delivered reliably and in order. The networking layer retries
     * until each message is acknowledged by the peer. Outgoing messages are
     * buffered until a working connection to the peer is established.
     */
    Reliable,
    Unknown,
};

ovrSendPolicy ConvertSendPolicy(EOvrSendPolicy Value);
EOvrSendPolicy ConvertSendPolicy(ovrSendPolicy Value);

/** ServiceProvider enumeration. */
UENUM(BlueprintType)
enum class EOvrServiceProvider : uint8
{
    Unknown,
    Dropbox,
    Facebook,
    Google,
    Instagram,
    RemoteMedia,
};

ovrServiceProvider ConvertServiceProvider(EOvrServiceProvider Value);
EOvrServiceProvider ConvertServiceProvider(ovrServiceProvider Value);

/** ShareMediaStatus enumeration. */
UENUM(BlueprintType)
enum class EOvrShareMediaStatus : uint8
{
    Unknown,
    Shared,
    Canceled,
};

ovrShareMediaStatus ConvertShareMediaStatus(EOvrShareMediaStatus Value);
EOvrShareMediaStatus ConvertShareMediaStatus(ovrShareMediaStatus Value);

/** SystemVoipStatus enumeration. */
UENUM(BlueprintType)
enum class EOvrSystemVoipStatus : uint8
{
    Unknown,
    Unavailable,
    Suppressed,
    Active,
};

ovrSystemVoipStatus ConvertSystemVoipStatus(EOvrSystemVoipStatus Value);
EOvrSystemVoipStatus ConvertSystemVoipStatus(ovrSystemVoipStatus Value);

/** How far should we go back in time looking at history?  This is used in some requests such as User_GetLoggedInUserRecentlyMetUsersAndRooms() */
UENUM(BlueprintType)
enum class EOvrTimeWindow : uint8
{
    Unknown,
    OneHour,
    OneDay,
    OneWeek,
    ThirtyDays,
    NinetyDays,
};

ovrTimeWindow ConvertTimeWindow(EOvrTimeWindow Value);
EOvrTimeWindow ConvertTimeWindow(ovrTimeWindow Value);

/**
 * The ordering that is used when returning a list of users. This is used in
 * some requests such as Room_GetInvitableUsers2()
 */
UENUM(BlueprintType)
enum class EOvrUserOrdering : uint8
{
    Unknown,
    /** No preference for ordering (could be in any or no order) */
    None,
    /**
     * Orders by online users first and then offline users. Within each group the
     * users are ordered alphabetically by display name
     */
    PresenceAlphabetical,
};

ovrUserOrdering ConvertUserOrdering(EOvrUserOrdering Value);
EOvrUserOrdering ConvertUserOrdering(ovrUserOrdering Value);

/** UserPresenceStatus enumeration. */
UENUM(BlueprintType)
enum class EOvrUserPresenceStatus : uint8
{
    Unknown,
    Online,
    Offline,
};

ovrUserPresenceStatus ConvertUserPresenceStatus(EOvrUserPresenceStatus Value);
EOvrUserPresenceStatus ConvertUserPresenceStatus(ovrUserPresenceStatus Value);

/** VoipBitrate enumeration. */
UENUM(BlueprintType)
enum class EOvrVoipBitrate : uint8
{
    Unknown,
    /**
     * Very low audio quality for minimal network usage. This may not give the full range of Hz for
     * audio, but it will save on network usage.
     */
    B16000,
    /** Lower audio quality but also less network usage. */
    B24000,
    /**
     * This is the default bitrate for voip connections. It should be the best tradeoff between
     * audio quality and network usage.
     */
    B32000,
    /**
     * Higher audio quality at the expense of network usage. Good if there's music being streamed
     * over the connections
     */
    B64000,
    /** Even higher audio quality for music streaming or radio-like quality. */
    B96000,
    /**
     * At this point the audio quality should be preceptually indistinguishable from the uncompressed
     * input.
     */
    B128000,
};

ovrVoipBitrate ConvertVoipBitrate(EOvrVoipBitrate Value);
EOvrVoipBitrate ConvertVoipBitrate(ovrVoipBitrate Value);

/** VoipDtxState enumeration. */
UENUM(BlueprintType)
enum class EOvrVoipDtxState : uint8
{
    Unknown,
    Enabled,
    Disabled,
};

ovrVoipDtxState ConvertVoipDtxState(EOvrVoipDtxState Value);
EOvrVoipDtxState ConvertVoipDtxState(ovrVoipDtxState Value);

/** VoipMuteState enumeration. */
UENUM(BlueprintType)
enum class EOvrVoipMuteState : uint8
{
    Unknown,
    Muted,
    Unmuted,
};

ovrVoipMuteState ConvertVoipMuteState(EOvrVoipMuteState Value);
EOvrVoipMuteState ConvertVoipMuteState(ovrVoipMuteState Value);

/** VoipSampleRate enumeration. */
UENUM(BlueprintType)
enum class EOvrVoipSampleRate : uint8
{
    Unknown,
    HZ24000,
    HZ44100,
    HZ48000,
};

ovrVoipSampleRate ConvertVoipSampleRate(EOvrVoipSampleRate Value);
EOvrVoipSampleRate ConvertVoipSampleRate(ovrVoipSampleRate Value);
