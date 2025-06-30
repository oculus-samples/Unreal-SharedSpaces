// Copyright (c) Meta Platforms, Inc. and affiliates.

// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#pragma once

#include "CoreMinimal.h"
#include "OVR_Platform.h"

#include "OVR_AbuseReportType.h"
#include "OVR_AccountAgeCategory.h"
#include "OVR_AchievementType.h"
#include "OVR_AppAgeCategory.h"
#include "OVR_AppInstallResult.h"
#include "OVR_AppStatus.h"
#include "OVR_ChallengeCreationType.h"
#include "OVR_ChallengeViewerFilter.h"
#include "OVR_ChallengeVisibility.h"
#include "OVR_KeyValuePairType.h"
#include "OVR_LaunchResult.h"
#include "OVR_LaunchType.h"
#include "OVR_LeaderboardFilterType.h"
#include "OVR_LeaderboardStartAt.h"
#include "OVR_LivestreamingStartStatus.h"
#include "OVR_LogEventName.h"
#include "OVR_LogEventParameter.h"
#include "OVR_MediaContentType.h"
#include "OVR_MultiplayerErrorErrorKey.h"
#include "OVR_NetSyncConnectionStatus.h"
#include "OVR_NetSyncDisconnectReason.h"
#include "OVR_NetSyncVoipMicSource.h"
#include "OVR_NetSyncVoipStreamMode.h"
#include "OVR_OfferTerm.h"
#include "OVR_OfferType.h"
#include "OVR_PartyUpdateAction.h"
#include "OVR_PermissionGrantStatus.h"
#include "OVR_PlatformInitializeResult.h"
#include "OVR_ProductType.h"
#include "OVR_ReportRequestResponse.h"
#include "OVR_RichPresenceExtraContext.h"
#include "OVR_SdkAccountType.h"
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


/**
 * Represents the type of abuse report, can be categorized as either concerning a user, an object, or being unknown.
 * It can be specified as a field in the FOvrAbuseReportOptions::ReportType option.
 */
UENUM(BlueprintType)
enum class EOvrAbuseReportType : uint8
{
    Unknown,
    /**
     * This refers to reports that are related to non-user entities, such as a virtual environment or an inanimate object within a platform.
     * An example provided is a report concerning a "world," which could be a virtual space or environment.
     */
    Object,
    /**
     * This category is used for reports that directly involve a user's actions or behavior.
     * This could include reports on harassment, inappropriate behavior, or other violations that
     * are directly linked to a user's conduct on a platform.
     */
    User,
};

ovrAbuseReportType OVRPLATFORM_API ConvertAbuseReportType(EOvrAbuseReportType Value);
EOvrAbuseReportType OVRPLATFORM_API ConvertAbuseReportType(ovrAbuseReportType Value);

/**
 * The age category in a Meta account is used to determine eligibility for certain features and services.
 * This information is important for ensuring that users are able to access the appropriate content and functionality based on their age.
 * The values are used in FOvrUserAccountAgeCategory API.
 * See more details [here](https://developer.oculus.com/documentation/unreal/ps-get-age-category-api).
 */
UENUM(BlueprintType)
enum class EOvrAccountAgeCategory : uint8
{
    Unknown,
    /** Child age group for users between the ages of 10-12 (or applicable age in user's region). */
    Ch,
    /** Teenage age group for users between the ages of 13-17 (or applicable age in user's region). */
    Tn,
    /** Adult age group for users ages 18 and up (or applicable age in user's region). */
    Ad,
};

ovrAccountAgeCategory OVRPLATFORM_API ConvertAccountAgeCategory(EOvrAccountAgeCategory Value);
EOvrAccountAgeCategory OVRPLATFORM_API ConvertAccountAgeCategory(ovrAccountAgeCategory Value);

/**
 * Determines the type of the achievement. This enum defines the different types of achievements that can be used in the game.
 * Each type has its own unique characteristics and requirements for unlocking.
 * See more details about achievement [here](https://developer.oculus.com/documentation/unreal/ps-achievements/).
 */
UENUM(BlueprintType)
enum class EOvrAchievementType : uint8
{
    Unknown,
    /**
     * Simple achievements are unlocked by a single event or objective completion. They are often used to reward players for
     * completing specific tasks or milestones within the game.
     */
    Simple,
    /** Bitfield achievements are unlocked when a target number of bits are set within a bitfield. */
    Bitfield,
    /**
     * Count achievements are unlocked when a counter reaches a defined target. The counter is incremented each time the player completes
     * the required action, and when it reaches the target value, the achievement is unlocked.
     */
    Count,
};

ovrAchievementType OVRPLATFORM_API ConvertAchievementType(EOvrAchievementType Value);
EOvrAchievementType OVRPLATFORM_API ConvertAchievementType(ovrAchievementType Value);

/**
 * The age category in a Meta account is used to determine eligibility for certain features and services.
 * This information is important for ensuring that users are able to access the appropriate content and functionality based on their age.
 * The values are used in FOvrUserAccountAgeCategory API.
 * See more details [here](https://developer.oculus.com/documentation/unreal/ps-get-age-category-api).
 */
UENUM(BlueprintType)
enum class EOvrAppAgeCategory : uint8
{
    Unknown,
    /** Child age group for users between the ages of 10-12 (or applicable age in user's region). */
    Ch,
    /** Non-child age group for users ages 13 and up (or applicable age in user's region). */
    Nch,
};

ovrAppAgeCategory OVRPLATFORM_API ConvertAppAgeCategory(EOvrAppAgeCategory Value);
EOvrAppAgeCategory OVRPLATFORM_API ConvertAppAgeCategory(ovrAppAgeCategory Value);

/**
 * Result of installing an app. In case of an error during install process,
 * the error message contains the string representation of this result. This is
 * returned from UOvrRequestsBlueprintLibrary::Application_StartAppDownload(), UOvrRequestsBlueprintLibrary::Application_CancelAppDownload() and UOvrRequestsBlueprintLibrary::Application_InstallAppUpdateAndRelaunch() APIs.
 */
UENUM(BlueprintType)
enum class EOvrAppInstallResult : uint8
{
    Unknown,
    /** Install of the app failed due to low storage on the device */
    LowStorage,
    /** Install of the app failed due to a network error */
    NetworkError,
    /**
     * Install of the app failed as another install request for this application
     * is already being processed by the installer
     */
    DuplicateRequest,
    /** Install of the app failed due to an internal installer error */
    InstallerError,
    /** Install of the app failed because the user canceled the install operation */
    UserCancelled,
    /** Install of the app failed due to a user authorization error */
    AuthorizationError,
    /** Install of the app succeeded */
    Success,
};

ovrAppInstallResult OVRPLATFORM_API ConvertAppInstallResult(EOvrAppInstallResult Value);
EOvrAppInstallResult OVRPLATFORM_API ConvertAppInstallResult(ovrAppInstallResult Value);

/**
 * This property indicates the current status of the app on the device. It is important to note that
 * an app can only query its own status, not the status of other apps installed on the device. It can be
 * retrieved by field FOvrAppDownloadProgressResult::StatusCode.
 */
UENUM(BlueprintType)
enum class EOvrAppStatus : uint8
{
    Unknown,
    /**
     * The user possesses a valid entitlement for the app, indicating they have the right to install it,
     * although it is not currently installed on the device.
     */
    Entitled,
    /** The app is scheduled for download. The download will start as soon as prior queued downloads are completed. */
    DownloadQueued,
    /** The app is currently being downloaded to the device. This status is active during the download process until it is complete. */
    Downloading,
    /** The app is currently being installed on the device. This status remains until the installation is fully completed. */
    Installing,
    /** The app is successfully installed on the device and is ready to be used. */
    Installed,
    /** The app is currently being uninstalled from the device. This status remains until the uninstallation process is complete. */
    Uninstalling,
    /** The installation of the app is scheduled and will commence once any prior installations are completed. */
    InstallQueued,
};

ovrAppStatus OVRPLATFORM_API ConvertAppStatus(EOvrAppStatus Value);
EOvrAppStatus OVRPLATFORM_API ConvertAppStatus(ovrAppStatus Value);

/**
 * Describes the creator of the associated challenge. This field indicates who created the challenge, whether
 * it was EOvrChallengeCreationType::UserCreated or EOvrChallengeCreationType::DeveloperCreated.
 * Understanding the creator of the associated challenge can provide valuable context and help participants better
 * understand the nature and purpose of the challenge.
 */
UENUM(BlueprintType)
enum class EOvrChallengeCreationType : uint8
{
    Unknown,
    /**
     * The challenge was created by a User. This means that a regular user of the app created the challenge, and it may be
     * a community-driven challenge or a personal challenge created by the user for themselves or others.
     */
    UserCreated,
    /**
     * The challenge was created by the app developer. This means that the challenge was created by the team behind the app,
     * and it may be an official challenge or a special event created by the developers to engage with the community or promote specific
     * features of the app.
     */
    DeveloperCreated,
};

ovrChallengeCreationType OVRPLATFORM_API ConvertChallengeCreationType(EOvrChallengeCreationType Value);
EOvrChallengeCreationType OVRPLATFORM_API ConvertChallengeCreationType(ovrChallengeCreationType Value);

/**
 * The available filtering options on the FOvrChallenge returned by UOvrRequestsBlueprintLibrary::Challenges_GetList().
 * These filters allow users to customize their search results and retrieve only the challenges that meet specific criteria.
 * See more details of Challenges in [here](https://developer.oculus.com/documentation/unreal/ps-challenges/).
 */
UENUM(BlueprintType)
enum class EOvrChallengeViewerFilter : uint8
{
    Unknown,
    /**
     * Returns all public ((EOvrChallengeVisibility::Public)) and invite-only (EOvrChallengeVisibility::InviteOnly)
     * FOvrChallenges in which the user is a participant or invitee. Excludes private (EOvrChallengeVisibility::Private)
     * challenges. This filter is useful for users who want to see all challenges they are involved in, regardless of their visibility settings.
     */
    AllVisible,
    /**
     * Returns challenges in which the user is a participant. This filter is useful for users who want to see only the challenges they are
     * actively participating in.
     */
    Participating,
    /**
     * Returns challenges that the user has been invited to. This filter is useful for users who want to see only the challenges
     * they have been explicitly invited to.
     */
    Invited,
    /**
     * Returns challenges the user is either participating in or invited to. This filter is useful for users who want to see all challenges
     * they are involved in, whether as a participant or an invitee.
     */
    ParticipatingOrInvited,
};

ovrChallengeViewerFilter OVRPLATFORM_API ConvertChallengeViewerFilter(EOvrChallengeViewerFilter Value);
EOvrChallengeViewerFilter OVRPLATFORM_API ConvertChallengeViewerFilter(ovrChallengeViewerFilter Value);

/**
 * The visibility of the challenge. A challenge may be invite-only, public, or private. The visibility setting determines who can
 * see and participate in the challenge.
 * See more details of Challenges in [here](https://developer.oculus.com/documentation/unreal/ps-challenges/).
 */
UENUM(BlueprintType)
enum class EOvrChallengeVisibility : uint8
{
    Unknown,
    /**
     * Only those invited can participate in it. Everyone can see it, but only those with an invitation can joinand participate in the challenge.
     * This setting is useful for challenges that are meant to be exclusive or for a specific group of people.
     */
    InviteOnly,
    /**
     * Everyone can participate and see this challenge. This setting makes the challenge open to anyone who wants to join,
     * and everyone can see the challenge details and progress. This setting is useful for challenges that are meant to be open and inclusive.
     */
    Public,
    /**
     * Only those invited can participate and see this challenge. This setting makes the challenge invisible to everyone except
     * those who have been explicitly invited. Only those with an invitation can see the challenge details and progress,
     * and only they can participate. This setting is useful for challenges that are meant to be highly exclusive or confidential.
     */
    Private,
};

ovrChallengeVisibility OVRPLATFORM_API ConvertChallengeVisibility(EOvrChallengeVisibility Value);
EOvrChallengeVisibility OVRPLATFORM_API ConvertChallengeVisibility(ovrChallengeVisibility Value);

/**
 * It's a data structure that represents a pair of values, where one value serves as the key and the other value serves as the corresponding value.
 * It can be used to store a different type of data, allowing for flexibility in how data is stored and retrieved.
 */
UENUM(BlueprintType)
enum class EOvrKeyValuePairType : uint8
{
    /** This member represents the key value as a string. It is used to store text-based data, such as names. */
    String,
    /** This member represents the key value as an integer. It is used to store numerical data, such as ages */
    Int,
    /**  This member represents the key value as a double-precision floating-point number. It is used to store numerical data with decimal points, such as prices. */
    Double,
    Unknown,
};

ovrKeyValuePairType OVRPLATFORM_API ConvertKeyValuePairType(EOvrKeyValuePairType Value);
EOvrKeyValuePairType OVRPLATFORM_API ConvertKeyValuePairType(ovrKeyValuePairType Value);

/**
 * An enum that specifies the whether the attempt to launch this application via a deeplink was successful.
 * The value is meant to be reported after a deeplink by calling UOvrFunctionsBlueprintLibrary::ApplicationLifecycle_LogDeeplinkResult
 */
UENUM(BlueprintType)
enum class EOvrLaunchResult : uint8
{
    Unknown,
    /** The application launched successfully. */
    Success,
    /** The application launch failed because the room was full. */
    FailedRoomFull,
    /** The application launch failed because the game has already started. */
    FailedGameAlreadyStarted,
    /** The appplicatin launch failed because the room couldn't be found. */
    FailedRoomNotFound,
    /** The application launch failed because the user declined the invitation. */
    FailedUserDeclined,
    /** The application launch failed due to some other reason. */
    FailedOtherReason,
};

ovrLaunchResult OVRPLATFORM_API ConvertLaunchResult(EOvrLaunchResult Value);
EOvrLaunchResult OVRPLATFORM_API ConvertLaunchResult(ovrLaunchResult Value);

/**
 * It's an enum that defines several different types of launches for an application.
 * It provides a way to differentiate between different types of launches and to access additional information about the launch details.
 * It can be retrieved using field FOvrLaunchDetails::LaunchType to get the launch type information of an application.
 */
UENUM(BlueprintType)
enum class EOvrLaunchType : uint8
{
    Unknown,
    /**  Normal launch from the user's library  */
    Normal,
    /**
     *  Launch from the user accepting an invite.  Check field FOvrLaunchDetails::LobbySessionID,
     *     field FOvrLaunchDetails::MatchSessionID, field FOvrLaunchDetails::DestinationApiName and
     *     field FOvrLaunchDetails::DeeplinkMessage. 
     */
    Invite,
    /**  DEPRECATED  */
    Coordinated,
    /**
     *  Launched from UOvrRequestsBlueprintLibrary::Application_LaunchOtherApp().
     *     Check field FOvrLaunchDetails::LaunchSource and field FOvrLaunchDetails::DeeplinkMessage. 
     */
    Deeplink,
};

ovrLaunchType OVRPLATFORM_API ConvertLaunchType(EOvrLaunchType Value);
EOvrLaunchType OVRPLATFORM_API ConvertLaunchType(ovrLaunchType Value);

/**
 * An enum that defines the different types of filters that can be applied to a leaderboard.
 * It can be used in UOvrRequestsBlueprintLibrary::Leaderboard_GetEntries() to filter the leaderboard entries, such as only friends or specific user IDs.
 */
UENUM(BlueprintType)
enum class EOvrLeaderboardFilterType : uint8
{
    /** No filter enabled on the leaderboard. */
    None,
    /** This value indicates that the leaderboard should be filtered to include only friends (bidirectional followers) of the current user. */
    Friends,
    Unknown,
    /**
     * Filter the leaderboard to include specific user IDs.
     * Use this filter to get rankings for users that are competing against each other.
     * You specify the leaderboard name and whether to start at the top, or for the results to center on the (client) user.
     * Note that if you specify the results to center on the client user, their leaderboard entry will be included in the returned array, regardless of whether their ID is explicitly specified in the list of IDs.
     */
    UserIds,
};

ovrLeaderboardFilterType OVRPLATFORM_API ConvertLeaderboardFilterType(EOvrLeaderboardFilterType Value);
EOvrLeaderboardFilterType OVRPLATFORM_API ConvertLeaderboardFilterType(ovrLeaderboardFilterType Value);

/**
 * An enum that allows you to specify the starting point for the leaderboard entries.
 * It can be used as a params in UOvrRequestsBlueprintLibrary::Leaderboard_GetEntries() to the starting point for the leaderboard entries that are returned in the response.
 */
UENUM(BlueprintType)
enum class EOvrLeaderboardStartAt : uint8
{
    /** This value indicates that the leaderboard entries should start at the top of the leaderboard. */
    Top,
    /** This value indicates that the leaderboard entries should start at the viewer's position on the leaderboard */
    CenteredOnViewer,
    /**  This value indicates that the leaderboard entries should start at the viewer's position on the leaderboard, or at the top of the leaderboard if the viewer is not present. */
    CenteredOnViewerOrTop,
    Unknown,
};

ovrLeaderboardStartAt OVRPLATFORM_API ConvertLeaderboardStartAt(EOvrLeaderboardStartAt Value);
EOvrLeaderboardStartAt OVRPLATFORM_API ConvertLeaderboardStartAt(ovrLeaderboardStartAt Value);

/**
 * It's an enum that represents the possible outcomes of starting a livestreaming session.
 * This allows the API to return a standardized and well-defined set of values to indicate the outcome of starting a livestreaming session.
 * It can be used in field FOvrLivestreamingStartResult::StreamingResult as type information.
 */
UENUM(BlueprintType)
enum class EOvrLivestreamingStartStatus : uint8
{
    /** This member represents a successful start of the livestreaming session. */
    Success = 1,
    Unknown = 0,
    /** This member represents an error where the package was not set during the livestreaming start process.  */
    NoPackageSet = uint8(-1),
    /** This member represents an error where Facebook Connect was not enabled during the livestreaming start process. */
    NoFbConnect = uint8(-2),
    /** This member represents an error where a session ID was not provided during the livestreaming start process. */
    NoSessionId = uint8(-3),
    /** This member represents an error where required parameters were missing during the livestreaming start process. */
    MissingParameters = uint8(-4),
};

ovrLivestreamingStartStatus OVRPLATFORM_API ConvertLivestreamingStartStatus(EOvrLivestreamingStartStatus Value);
EOvrLivestreamingStartStatus OVRPLATFORM_API ConvertLivestreamingStartStatus(ovrLivestreamingStartStatus Value);

/**
 * It's an enum that represents a list of possible event names that can be used to track user interactions and other important occurrences within an application.
 * These events can be used to track user engagement, conversion rates, and other important metrics within an app. By logging these events, developers can gain valuable insights into how users interact with their app and make data-driven decisions to improve the user experience.
 * The log event parameters can be found in #EOvrLogEventParameter.
 */
UENUM(BlueprintType)
enum class EOvrLogEventName : uint8
{
    Unknown,
    /** This event is triggered when a user clicks on an advertisement within the app. */
    AdClick,
    /** This event is triggered when an advertisement is displayed to the user within the app. */
    AdImpression,
    /**
     * This event is triggered when a user completes the registration process within the app.
     * This could include creating an account, verifying email address, or completing a profile.
     */
    VrCompleteRegistration,
    /** This event is triggered when a user completes a tutorial or guided experience within the app. */
    VrTutorialCompletion,
    /** This event is triggered when a user interacts with a contact form or other contact-related feature within the app. */
    Contact,
    /** This event is triggered when a user customizes a product or item within the app. This could include selecting options, choosing colors, or adding features. */
    CustomizeProduct,
    /** This event is triggered when a user makes a donation within the app. */
    Donate,
    /** This event is triggered when a user interacts with a feature that helps them find a physical location, such as a store or event. */
    FindLocation,
    /**
     * This event is triggered when a user rates an item or experience within the app.
     * This could include rating a product, service, or experience on a scale.
     */
    VrRate,
    /** This event is triggered when a user schedules an appointment or event within the app. */
    Schedule,
    /** This event is triggered when a user performs a search within the app. This could include searching for a product, service, or information. */
    VrSearch,
    /** This event is triggered when a user starts a free trial or demo of an app or game. */
    SmartTrial,
    /** This event is triggered when a user submits an application or form within the app. */
    SubmitApplication,
    /** This event is triggered when a user subscribes to a service or newsletter within the app. */
    Subscribe,
    /** This event is triggered when a user views content within the app, such as a video or article. */
    VrContentView,
    /** This event is triggered when the Oculus Platform SDK is initialized within the app. This could include setting up the SDK, loading assets, or initializing game engines. */
    VrSdkInitialize,
    /** This event is triggered when the app is granted background status by the Oculus Platform SDK. */
    VrSdkBackgroundStatusAvailable,
    /** This event is triggered when the app is denied background status by the Oculus Platform SDK. */
    VrSdkBackgroundStatusDenied,
    /** This event is triggered when the app is granted restricted background status by the Oculus Platform SDK. */
    VrSdkBackgroundStatusRestricted,
    /** This event is triggered when a user adds payment information within the app. This could include entering credit card details, linking a PayPal account, or setting up recurring payments. */
    VrAddPaymentInfo,
    /** This event is triggered when a user adds an item to their cart within the app. This could include selecting products and choosing quantities. */
    VrAddToCart,
    /** This event is triggered when a user adds an item to their wishlist within the app. */
    VrAddToWishlist,
    /** This event is triggered when a user begins the checkout process within the app. This could include reviewing orders, entering shipping information, or selecting payment methods. */
    VrInitiatedCheckout,
    /** This event is triggered when a user completes a purchase within the app. This could include finalizing an order, confirming payment, or receiving a confirmation message. */
    VrPurchase,
    /** This event is triggered when a user updates their catalog or inventory within the app. */
    VrCatalogUpdate,
    /** This event is triggered when a purchase fails within the app. This could include an error message, a failed payment, or a cancelled order. */
    VrPurchaseFailed,
    /** This event is triggered when a purchase is restored within the app. This could include reactivating a subscription, reinstating a service, or restoring access to a product. */
    VrPurchaseRestored,
    /** This event is triggered when a user begins the checkout process for a subscription within the app. */
    SubscriptionInitiatedCheckout,
    /** This event is triggered when a subscription fails within the app. This could include an error message, a failed payment, or a cancelled subscription. */
    SubscriptionFailed,
    /** This event is triggered when a subscription is restored within the app. This could include reactivating a subscription, reinstating a service, or restoring access to a product. */
    SubscriptionRestore,
    /** This event is triggered when a user achieves a level or milestone within the app. */
    VrLevelAchieved,
    /** This event is triggered when a user achieves a level or milestone within the app. */
    VrAchievementUnlocked,
    /** This event is triggered when a user spends credits or virtual currency within the app. */
    VrSpentCredits,
    /** This event is triggered when a user obtains a push token within the app. */
    VrObtainPushToken,
    /** This event is triggered when a user opens a push notification within the app. */
    VrPushOpened,
    /** This event is triggered when a user activates the app.  This could include launching the app, logging in, or starting a new session. */
    VrActivateApp,
    /** This event is triggered when a user deactivates the app. This could include closing the app, logging out, or ending a session. */
    VrDeactivateApp,
};

ovrLogEventName OVRPLATFORM_API ConvertLogEventName(EOvrLogEventName Value);
EOvrLogEventName OVRPLATFORM_API ConvertLogEventName(ovrLogEventName Value);

/**
 * It's an enum about a list of possible parameters that can be logged for an event. See more information about log event in #EOvrLogEventName.
 * Each member of the enum represents a specific parameter that can be logged. 
 */
UENUM(BlueprintType)
enum class EOvrLogEventParameter : uint8
{
    Unknown,
    /** This parameter represents the currency used in a virtual reality (VR) transaction and it's important for tracking and analyzing VR transactions across different regions and currencies. */
    VrCurrency,
    /** This parameter represents the method used to register for a VR service or application. It helps to understand how users are accessing VR services and applications. */
    VrRegistrationMethod,
    /** This parameter represents the type of content being accessed or interacted with in a VR environment. It helps to understand what types of content are most popular among VR users. */
    VrContentType,
    /** This parameter represents the specific content being accessed or interacted with in a VR environment. */
    VrContent,
    /** This parameter represents the unique identifier for the content being accessed or interacted with in a VR environment. */
    VrContentId,
    /** This parameter represents the search query entered by the user in a VR environment. It helps to understand what users are searching for and how they are interacting with VR search functionality. */
    VrSearchString,
    /** This parameter represents whether an action was successful or not in a VR environment. */
    VrSuccess,
    /** This parameter represents the maximum rating value allowed for a particular VR content or service. */
    VrMaxRatingValue,
    /** This parameter represents whether payment information is available for a VR transaction. It helps to understand whether users have the necessary payment information to complete a VR transaction. */
    VrPaymentInfoAvailable,
    /** This parameter represents the number of items involved. */
    VrNumItems,
    /** This parameter represents the level or stage reached by the user in a VR game or application. */
    VrLevel,
    /** This parameter represents a brief description of the VR content or service being accessed or interacted with. */
    VrDescription,
    /** This parameter represents the type of advertisement displayed to the user in a VR environment. */
    AdType,
    /** This parameter represents the unique identifier for a VR order or transaction. It helps to track and analyze individual VR transactions and orders. */
    VrOrderId,
    /** This parameter represents the name of the event being logged. */
    EventName,
    /** This parameter represents the timestamp when the event was logged. It helps to understand when specific events occurred and how they relate to other events in the VR environment. */
    LogTime,
    /** This parameter represents whether the event was implicitly logged or explicitly logged by the user. */
    ImplicitlyLogged,
    /** This parameter represents whether the event occurred while the application was running in the background or foreground. */
    InBackground,
    /** This parameter represents the campaign or promotion associated with a VR push notification. It helps to understand the context and purpose of VR push notifications. */
    VrPushCampaign,
    /** This parameter represents the action taken by the user on a VR push notification, such as clicking or dismissing. */
    VrPushAction,
    /** This parameter represents the type of in-app purchase (IAP) product being purchased or interacted with in a VR environment. */
    VrIapProductType,
    /**  This parameter represents the title of the VR content being accessed or interacted with. It helps to provide context and understanding of what the VR experience entails. */
    VrContentTitle,
    /** This parameter represents the unique identifier for a VR transaction. It helps to track and analyze individual VR transactions and orders. */
    VrTransactionId,
    /** This parameter represents the date and time of a VR transaction. It helps to understand when specific transactions occurred. */
    VrTransactionDate,
    /** This parameter represents the subscription period for an in-app purchase (IAP) product in a VR environment, such as monthly or annually. */
    VrIapSubsPeriod,
    /** This parameter represents whether the user is starting a free trial for an IAP product in a VR environment.  */
    VrIapIsStartTrial,
    /** This parameter represents whether an IAP product has a free trial available in a VR environment.  */
    VrIapHasFreeTrial,
    /** This parameter represents the length of the free trial period for an IAP product in a VR environment.  */
    VrIapTrialPeriod,
    /** This parameter represents the price of the IAP product during the free trial period in a VR environment.  */
    VrIapTrialPrice,
    /** This parameter represents the unique identifier for a user session in a VR environment. It helps to track and analyze individual user sessions and understand how users are interacting with VR applications and services over time. */
    SessionId,
};

ovrLogEventParameter OVRPLATFORM_API ConvertLogEventParameter(EOvrLogEventParameter Value);
EOvrLogEventParameter OVRPLATFORM_API ConvertLogEventParameter(ovrLogEventParameter Value);

/**
 * An enum that represents the type of media content being shared, which can be useful for various purposes such as displaying the media content in a specific way or applying certain filters or effects to it.
 * It can be used as a type of parameter in UOvrRequestsBlueprintLibrary::Media_ShareToFacebook().
 */
UENUM(BlueprintType)
enum class EOvrMediaContentType : uint8
{
    Unknown,
    /**
     * Indicates that the media content is a photo.
     * This value can be used to specify that the media content being shared is a photo.
     */
    Photo,
};

ovrMediaContentType OVRPLATFORM_API ConvertMediaContentType(EOvrMediaContentType Value);
EOvrMediaContentType OVRPLATFORM_API ConvertMediaContentType(ovrMediaContentType Value);

/**
 * Possible keys of the errors which could occurred when using the [multiplayer features](https://developer.oculus.com/documentation/unreal/ps-multiplayer-overview/).
 * e.g., you may need to use `destination_unavailable` for destinations feature and use `inviter_not_joinable` for invite feature and so on.
 */
UENUM(BlueprintType)
enum class EOvrMultiplayerErrorErrorKey : uint8
{
    Unknown,
    /** This error key will be used to tell the user that the travel destination is not available any more. */
    DestinationUnavailable,
    /** This error will tell the user that the downloadable content will be needed. */
    DlcRequired,
    /** This error key will be used in a broad range of general errors which are not be covered by the members of the enum. */
    General,
    /** This error key may be used to explain to the user the reason why she/he failed in joining a group. */
    GroupFull,
    /** This error key will be used in explaining why an inviter cannot invite a recepient successfully. The group presence can be set to joinable by using UOvrRequestsBlueprintLibrary::GroupPresence_SetIsJoinable(). */
    InviterNotJoinable,
    /** Certain features will not be available to the user in the app because the user's level does not reach to certain level. */
    LevelNotHighEnough,
    /** This error key may be used to explain to the user the failure was occurred becasue some level has not been reached. */
    LevelNotUnlocked,
    /** When the predefined network timeout has reached, the ongoing activity would be stopped. The dialog will use this error key to give the user the information. */
    NetworkTimeout,
    NoLongerAvailable,
    UpdateRequired,
    TutorialRequired,
};

ovrMultiplayerErrorErrorKey OVRPLATFORM_API ConvertMultiplayerErrorErrorKey(EOvrMultiplayerErrorErrorKey Value);
EOvrMultiplayerErrorErrorKey OVRPLATFORM_API ConvertMultiplayerErrorErrorKey(ovrMultiplayerErrorErrorKey Value);

/**
 * It represents the possible status of a FOvrNetSyncConnection which
 * allows multiple clients to connect and communicate with each other in real-time.
 * The connection provides a way to manage and facilitate real-time communication and
 * data synchronization between multiple clients in a networked environment.
 */
UENUM(BlueprintType)
enum class EOvrNetSyncConnectionStatus : uint8
{
    Unknown,
    /** This member indicates that the connection of the network sync has been started and the process is ongoing. */
    Connecting,
    /** This member indicates that the current status of the network sync connection is not connected. */
    Disconnected,
    /** This member indicates that the current status of the network sync connection is connected. */
    Connected,
};

ovrNetSyncConnectionStatus OVRPLATFORM_API ConvertNetSyncConnectionStatus(EOvrNetSyncConnectionStatus Value);
EOvrNetSyncConnectionStatus OVRPLATFORM_API ConvertNetSyncConnectionStatus(ovrNetSyncConnectionStatus Value);

/**
 * It represents the possible reasons why the status of a FOvrNetSyncConnection, which
 * allows multiple clients to connect and communicate with each other in real-time, is disconnected.
 * The connection provides a way to manage and facilitate real-time communication and
 * data synchronization between multiple clients in a networked environment.
 */
UENUM(BlueprintType)
enum class EOvrNetSyncDisconnectReason : uint8
{
    Unknown,
    /** This member indicates that the disconnect of the FOvrNetSyncConnection was initialized from the a user request. */
    LocalTerminated,
    /** This member indicates that the connection of the FOvrNetSyncConnection was shutdown by the server intentionally. */
    ServerTerminated,
    /** This member indicates that the initial connection request never succeeded. */
    Failed,
    /** This member indicates that the FOvrNetSyncConnection was shutdown because of the network timeout. */
    Lost,
};

ovrNetSyncDisconnectReason OVRPLATFORM_API ConvertNetSyncDisconnectReason(EOvrNetSyncDisconnectReason Value);
EOvrNetSyncDisconnectReason OVRPLATFORM_API ConvertNetSyncDisconnectReason(ovrNetSyncDisconnectReason Value);

/**
 * A network synchronization system allows multiple clients to connect and communicate with each other in real-time.
 * Once a FOvrNetSyncConnection is established, it uses Voice over Internet Protocol to allow users to make
 * voice calls using the internet. The mic source will represent the current source of the mic in the call.
 */
UENUM(BlueprintType)
enum class EOvrNetSyncVoipMicSource : uint8
{
    Unknown,
    /**
     * This `enum` member represents no net sync connection has been identified as the source from which the data was sent
     * to the server
     */
    None,
    /**
     * This `enum` member represents an internal net sync connection has been identified as the source from which the data was sent
     * to the server
     */
    Internal,
};

ovrNetSyncVoipMicSource OVRPLATFORM_API ConvertNetSyncVoipMicSource(EOvrNetSyncVoipMicSource Value);
EOvrNetSyncVoipMicSource OVRPLATFORM_API ConvertNetSyncVoipMicSource(ovrNetSyncVoipMicSource Value);

/**
 * A network synchronization system allows multiple clients to connect and communicate with each other in real-time.
 * Once a FOvrNetSyncConnection is established, user can choose the stream mode for the connection.
 * The FOvrNetSyncOptions::VoipStreamDefault will be used when a new VoIP(Voice over Internet Protocol) user connects.
 */
UENUM(BlueprintType)
enum class EOvrNetSyncVoipStreamMode : uint8
{
    Unknown,
    /**
     * This `enum` member represents the ambisonic steam mode the VoIP stream uses. It is the default value of FOvrNetSyncOptions::VoipStreamDefault.
     * Since it allows for the creation of immersive, surround sound experiences that simulate real-world audio environments, it typically used in virtual
     * reality (VR) and augmented reality (AR) applications.
     */
    Ambisonic,
    /**
     * This `enum` member represents the mono steam mode the VoIP stream uses. The advantages mono stream mode has over ambisonic steam mode is
     * the audio encoding and decoding require less computational resources and thus audio streams require less bandwidth. So it is typically used in
     * applications with limited network resources.
     */
    Mono,
};

ovrNetSyncVoipStreamMode OVRPLATFORM_API ConvertNetSyncVoipStreamMode(EOvrNetSyncVoipStreamMode Value);
EOvrNetSyncVoipStreamMode OVRPLATFORM_API ConvertNetSyncVoipStreamMode(ovrNetSyncVoipStreamMode Value);

/**
 * An enumeration that defines the type of the FOvrTrialOffer. This can be utilized to determine the length of time for which the offer is valid.
 *  By setting this field, you can easily manage the duration of your offers and provide a better user experience for your customers.
 */
UENUM(BlueprintType)
enum class EOvrOfferTerm : uint8
{
    Unknown,
    /** Represents that the offer term is weekly. This means that the offer will be valid for a period of one week from the date of purchase. */
    WEEKLY,
    /** Represents that the offer term is biweekly. This means that the offer will be valid for a period of two weeks from the date of purchase. */
    BIWEEKLY,
    /** Represents that the offer term is monthly. This means that the offer will be valid for a period of one month from the date of purchase. */
    MONTHLY,
    /** Represents that the offer term is quarterly. This means that the offer will be valid for a period of three months from the date of purchase. */
    QUARTERLY,
    /** Represents that the offer term is every 6 months. This means that the offer will be valid for a period of six months from the date of purchase. */
    SEMIANNUAL,
    /** Represents that the offer term is annual. This means that the offer will be valid for a period of one year from the date of purchase. */
    ANNUAL,
    /** Represents that the offer term is every 2 years. This means that the offer will be valid for a period of two years from the date of purchase. */
    BIANNUAL,
};

ovrOfferTerm OVRPLATFORM_API ConvertOfferTerm(EOvrOfferTerm Value);
EOvrOfferTerm OVRPLATFORM_API ConvertOfferTerm(ovrOfferTerm Value);

/**
 * An enumeration that defines the type of the FOvrTrialOffer. This can be utilized to identify the specific type of offer,
 * such as a free trial or an intro offer. By setting this field, you can easily differentiate between different types of offers
 * and provide a better user experience for your customers.
 */
UENUM(BlueprintType)
enum class EOvrOfferType : uint8
{
    Unknown,
    /** This value indicates that the offer is an intro offer, which is typically a special promotion or discount offered to new customers.  */
    INTROOFFER,
    /** This value indicates that the offer is a free trial, which allows customers to try out a product or service without paying for it. */
    FREETRIAL,
};

ovrOfferType OVRPLATFORM_API ConvertOfferType(EOvrOfferType Value);
EOvrOfferType OVRPLATFORM_API ConvertOfferType(ovrOfferType Value);

/**
 * An enum that specifies the type of action related to the party and the user. For example,
 * field FOvrPartyUpdateNotification::Action contains the information about the user joined or
 * left the party or the user was invited or uninvited to the party.
 */
UENUM(BlueprintType)
enum class EOvrPartyUpdateAction : uint8
{
    Unknown,
    /** This `enum` member indicates the user joined the party. */
    Join,
    /** This `enum` member indicates the user left the party. */
    Leave,
    /** This `enum` member indicates the user was invited to the party. */
    Invite,
    /** This `enum` member indicates the user was uninvited to the party. */
    Uninvite,
};

ovrPartyUpdateAction OVRPLATFORM_API ConvertPartyUpdateAction(EOvrPartyUpdateAction Value);
EOvrPartyUpdateAction OVRPLATFORM_API ConvertPartyUpdateAction(ovrPartyUpdateAction Value);

/**
 * This `enum` represents the all possible statuses of a premission request. For example,
 * if an user wants to participate in a challenge, the user may request the permission to join
 * the FOvrChallenge first. If the permission grant status is granted, the user can call
 * UOvrRequestsBlueprintLibrary::Challenges_Join() to join the challenge.
 */
UENUM(BlueprintType)
enum class EOvrPermissionGrantStatus : uint8
{
    Unknown,
    /** This `enum` member indicates the status of the permission grant was approved. */
    Granted,
    /** This `enum` member indicates the status of the permission grant was rejected. */
    Denied,
    /** This `enum` member indicates the status of the permission grant was blocked. */
    Blocked,
};

ovrPermissionGrantStatus OVRPLATFORM_API ConvertPermissionGrantStatus(EOvrPermissionGrantStatus Value);
EOvrPermissionGrantStatus OVRPLATFORM_API ConvertPermissionGrantStatus(ovrPermissionGrantStatus Value);

/**
 * Describes the various results possible when attempting to initialize the platform.
 * Anything other than ::ovrPlatformInitialize_Success should be considered a fatal error
 * with respect to using the platform, as the platform is not guaranteed to be legitimate
 * or work correctly.
 */
UENUM(BlueprintType)
enum class EOvrPlatformInitializeResult : uint8
{
    /** Oculus Platform SDK initialization succeeded. */
    Success = 0,
    /** Oculus Platform SDK was not initialized. */
    Uninitialized = uint8(-1),
    /** Oculus Platform SDK failed to initialize because the pre-loaded module was on a different path than the validated library. */
    PreLoaded = uint8(-2),
    /** Oculus Platform SDK files failed to load. */
    FileInvalid = uint8(-3),
    /** Oculus Platform SDK failed to initialize due to an invalid signature in the signed certificate. */
    SignatureInvalid = uint8(-4),
    /** Oculus Platform SDK failed to initialize due to unable to verify the application's signature during initialization. */
    UnableToVerify = uint8(-5),
    /** There was a mismatch between the version of Oculus Platform SDK used by the application and the version installed on the Oculus user's device. */
    VersionMismatch = uint8(-6),
    Unknown = uint8(-7),
    /** Oculus Platform SDK failed to initialize because the Oculus user had an invalid account access token. */
    InvalidCredentials = uint8(-8),
    /** Oculus Platform SDK failed to initialize because the Oculus user does not have the application entitlement. */
    NotEntitled = uint8(-9),
};

ovrPlatformInitializeResult OVRPLATFORM_API ConvertPlatformInitializeResult(EOvrPlatformInitializeResult Value);
EOvrPlatformInitializeResult OVRPLATFORM_API ConvertPlatformInitializeResult(ovrPlatformInitializeResult Value);

/**
 * This `enum` value represents the possible types of a FOvrProduct, which is an item purchased in the application.
 * An In-app purchase (IAP) add-on can be durable, consuable, or a subscription.
 */
UENUM(BlueprintType)
enum class EOvrProductType : uint8
{
    Unknown,
    /** This product is a durable IAP item that can be consumed multiple times. It can be purchased only once. */
    DURABLE,
    /** This product is an IAP item that can be consumed only once. It can only be purchased again after it is consumed. */
    CONSUMABLE,
    /** This product represents a subscription. Subscriptions provide a way for users to purchase your app or its premium content by way of a recurring payment model. */
    SUBSCRIPTION,
};

ovrProductType OVRPLATFORM_API ConvertProductType(EOvrProductType Value);
EOvrProductType OVRPLATFORM_API ConvertProductType(ovrProductType Value);

/**
 * An application user can report abusive behavior or content following the in-app reporting flow.
 * This report request response represents the possible states that the app can respond to the platform
 * notification, i.e., the running application indicates whether they want to show their in-app reporting flow
 * or that they choose to ignore the request via UOvrRequestsBlueprintLibrary::AbuseReport_ReportRequestHandled().
 */
UENUM(BlueprintType)
enum class EOvrReportRequestResponse : uint8
{
    Unknown,
    /** This 'enum' member represents the response to the platform notification that the in-app reporting flow request is handled. */
    Handled,
    /** This 'enum' member represents the response to the platform notification that the in-app reporting flow request is not handled. */
    Unhandled,
    /** This 'enum' member represents the response to the platform notification that the in-app reporting flow is unavailable or non-existent. */
    Unavailable,
};

ovrReportRequestResponse OVRPLATFORM_API ConvertReportRequestResponse(EOvrReportRequestResponse Value);
EOvrReportRequestResponse OVRPLATFORM_API ConvertReportRequestResponse(ovrReportRequestResponse Value);

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

ovrRichPresenceExtraContext OVRPLATFORM_API ConvertRichPresenceExtraContext(EOvrRichPresenceExtraContext Value);
EOvrRichPresenceExtraContext OVRPLATFORM_API ConvertRichPresenceExtraContext(ovrRichPresenceExtraContext Value);

/** A user can have multiple sdk accounts associated with it. An FOvrSdkAccount represents the oculus user and the particular x-account that is linked to the  user. SDK accounts can be retrived for a particular user by calling UOvrRequestsBlueprintLibrary::User_GetSdkAccounts(). This enumeration represents the specific type of SDK account that is associated. */
UENUM(BlueprintType)
enum class EOvrSdkAccountType : uint8
{
    Unknown,
    Oculus,
    FacebookGameroom,
};

ovrSdkAccountType OVRPLATFORM_API ConvertSdkAccountType(EOvrSdkAccountType Value);
EOvrSdkAccountType OVRPLATFORM_API ConvertSdkAccountType(ovrSdkAccountType Value);

/** The service provider enum describes the specific provider that is associated with the FOvrLinkedAccount of a FOvrUser. Linked accounts for users represent the third party identities that are used for services or apps in association with user. */
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

ovrServiceProvider OVRPLATFORM_API ConvertServiceProvider(EOvrServiceProvider Value);
EOvrServiceProvider OVRPLATFORM_API ConvertServiceProvider(ovrServiceProvider Value);

/** ShareMediaStatus enumeration. */
UENUM(BlueprintType)
enum class EOvrShareMediaStatus : uint8
{
    Unknown,
    Shared,
    Canceled,
};

ovrShareMediaStatus OVRPLATFORM_API ConvertShareMediaStatus(EOvrShareMediaStatus Value);
EOvrShareMediaStatus OVRPLATFORM_API ConvertShareMediaStatus(ovrShareMediaStatus Value);

/** The system voip status is the priamary status in every FOvrSystemVoipState. The system voip state is used in parties and horizon home to describe the current state of the input/output for voip in an application. You can read more about system voip [here](https://developer.oculus.com/documentation/unreal/ps-parties/#voip-options). */
UENUM(BlueprintType)
enum class EOvrSystemVoipStatus : uint8
{
    Unknown,
    Unavailable,
    Suppressed,
    Active,
};

ovrSystemVoipStatus OVRPLATFORM_API ConvertSystemVoipStatus(EOvrSystemVoipStatus Value);
EOvrSystemVoipStatus OVRPLATFORM_API ConvertSystemVoipStatus(ovrSystemVoipStatus Value);

/** How far should we go back in time looking at history. */
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

ovrTimeWindow OVRPLATFORM_API ConvertTimeWindow(EOvrTimeWindow Value);
EOvrTimeWindow OVRPLATFORM_API ConvertTimeWindow(ovrTimeWindow Value);

/** The ordering that is used when returning a list of users. */
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

ovrUserOrdering OVRPLATFORM_API ConvertUserOrdering(EOvrUserOrdering Value);
EOvrUserOrdering OVRPLATFORM_API ConvertUserOrdering(ovrUserOrdering Value);

/** Describe the current status of the user and it can be retrieved with field FOvrUser::PresenceStatus. */
UENUM(BlueprintType)
enum class EOvrUserPresenceStatus : uint8
{
    Unknown,
    /** The user status is currently online. */
    Online,
    /** The user status is currently offline. */
    Offline,
};

ovrUserPresenceStatus OVRPLATFORM_API ConvertUserPresenceStatus(EOvrUserPresenceStatus Value);
EOvrUserPresenceStatus OVRPLATFORM_API ConvertUserPresenceStatus(ovrUserPresenceStatus Value);

/**
 * It's a set of predefined values that represent different levels of audio quality for Voice over IP (VoIP) connections.
 * It can be used in FOvrVoipOptions::BitrateForNewConnections to set the maximum average bitrate the audio codec should use for new VoIP connections.
 */
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
     * At this point the audio quality should be perceptually indistinguishable from the uncompressed
     * input.
     */
    B128000,
};

ovrVoipBitrate OVRPLATFORM_API ConvertVoipBitrate(EOvrVoipBitrate Value);
EOvrVoipBitrate OVRPLATFORM_API ConvertVoipBitrate(ovrVoipBitrate Value);

/**
 * This is an enum that defines the possible states for the Opus codec's discontinuous transmission (DTX) feature.
 * It allows you to control whether the Opus codec uses DTX to conserve battery power and reduce transmission rate during pauses in the voice chat.
 * It can be used as the type for the FOvrVoipOptions::CreateNewConnectionUseDtx
 */
UENUM(BlueprintType)
enum class EOvrVoipDtxState : uint8
{
    Unknown,
    /** This state indicates that the DTX feature is enabled. When enabled, the Opus codec will only transmit data when a person is speaking, which can conserve battery power and reduce transmission rate during pauses in the voice chat. */
    Enabled,
    /** This state indicates that the DTX feature is disabled. When disabled, the Opus codec will continuously transmit data, even during pauses in the voice chat. */
    Disabled,
};

ovrVoipDtxState OVRPLATFORM_API ConvertVoipDtxState(EOvrVoipDtxState Value);
EOvrVoipDtxState OVRPLATFORM_API ConvertVoipDtxState(ovrVoipDtxState Value);

/** VoipMuteState enumeration. */
UENUM(BlueprintType)
enum class EOvrVoipMuteState : uint8
{
    Unknown,
    Muted,
    Unmuted,
};

ovrVoipMuteState OVRPLATFORM_API ConvertVoipMuteState(EOvrVoipMuteState Value);
EOvrVoipMuteState OVRPLATFORM_API ConvertVoipMuteState(ovrVoipMuteState Value);

/** VoipSampleRate enumeration. */
UENUM(BlueprintType)
enum class EOvrVoipSampleRate : uint8
{
    Unknown,
    HZ24000,
    HZ44100,
    HZ48000,
};

ovrVoipSampleRate OVRPLATFORM_API ConvertVoipSampleRate(EOvrVoipSampleRate Value);
EOvrVoipSampleRate OVRPLATFORM_API ConvertVoipSampleRate(ovrVoipSampleRate Value);
