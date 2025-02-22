// Copyright (c) Meta Platforms, Inc. and affiliates.

// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#pragma once

#include "CoreMinimal.h"
#include "OVRPlatformTypes.h"
#include "OVRPlatformOptions.generated.h"


/**
 * The Abuse Report Options provide a way for developers to customize the reporting flow and specify the type of content being reported,
 * which can be either a EOvrAbuseReportType::User or an EOvrAbuseReportType::Object,
 * helping to maintain a safe and respectful community within their application.
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Options|AbuseReport")
struct OVRPLATFORM_API FOvrAbuseReportOptions
{
    GENERATED_USTRUCT_BODY()

    /**
     * Set whether or not to show the user selection step.
     * If the reported object is a user, they can choose to block the reported user from further interactions within the platform.
     */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|AbuseReport|Option")
    bool PreventPeopleChooser;

    /**
     * The intended entity type #EOvrAbuseReportType being reported, it can be either a user EOvrAbuseReportType::User
     * or an object/content EOvrAbuseReportType::Object.
     */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|AbuseReport|Option")
    EOvrAbuseReportType ReportType;

    FOvrAbuseReportOptions()
    {
        PreventPeopleChooser = false;
        ReportType = EOvrAbuseReportType::Unknown;
    }
};

/**
 * The Advanced Abuse Report Options provides a way for developers to customize the reporting flow and specify the type of content being reported,
 * which can be either a EOvrAbuseReportType::User or an EOvrAbuseReportType::Object,
 * helping to maintain a safe and respectful community within their application.
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Options|AdvancedAbuseReport")
struct OVRPLATFORM_API FOvrAdvancedAbuseReportOptions
{
    GENERATED_USTRUCT_BODY()

    /**
     * This field is intended to allow developers to pass custom metadata through the report flow.
     * The metadata passed through is included with the report received by the developer.
     */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|AdvancedAbuseReport|Option")
    TMap<FString, FString> DeveloperDefinedContext;

    /**
     * If #EOvrAbuseReportType is EOvrAbuseReportType::Object, a string representing the type of content being reported.
     * This should correspond to the object_type string used in the UI.
     */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|AdvancedAbuseReport|Option")
    FString ObjectType;

    /**
     * The intended entity type #EOvrAbuseReportType being reported, it can be either a user EOvrAbuseReportType::User
     * or an object/content EOvrAbuseReportType::Object.
     */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|AdvancedAbuseReport|Option")
    EOvrAbuseReportType ReportType;

    /**
     * Provide a list of users to suggest for reporting. This list should include users that the reporter has recently interacted with
     * to aid them in selecting the right user to report.
     */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|AdvancedAbuseReport|Option")
    TArray<FOvrId> SuggestedUsers;

    FOvrAdvancedAbuseReportOptions()
    {
        ObjectType = TEXT("");
        ReportType = EOvrAbuseReportType::Unknown;
    }
};

/**
 * The Application option contains additional configuration to be passed in to UOvrRequestsBlueprintLibrary::Application_LaunchOtherApp() and
 * UOvrRequestsBlueprintLibrary::Application_InstallAppUpdateAndRelaunch(). It contains 5 fields FOvrApplicationOptions::DeeplinkMessage,
 * FOvrApplicationOptions::DestinationApiName, FOvrApplicationOptions::LobbySessionId, FOvrApplicationOptions::MatchSessionId
 * and FOvrApplicationOptions::RoomId.
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Options|Application")
struct OVRPLATFORM_API FOvrApplicationOptions
{
    GENERATED_USTRUCT_BODY()

    /**
     * A message to be passed to a launched app, which can be retrieved
     * with field FOvrLaunchDetails::DeeplinkMessage.
     */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|Application|Option")
    FString DeeplinkMessage;

    /**
     * If provided, the intended destination to be passed to the launched
     * app, which can be retrieved with field FOvrLaunchDetails::DestinationApiName.
     */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|Application|Option")
    FString DestinationApiName;

    /**
     * If provided, the intended lobby where the launched app should take
     * the user. All users with the same lobby_session_id should end up grouped
     * together in the launched app, which can be retrieved with field FOvrLaunchDetails::LobbySessionID.
     */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|Application|Option")
    FString LobbySessionId;

    /**
     * If provided, the intended instance of the destination that a user
     * should be launched into, which can be retrieved with field FOvrLaunchDetails::MatchSessionID.
     */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|Application|Option")
    FString MatchSessionId;

    /**
     * [Deprecated]If provided, the intended room where the launched app
     * should take the user (all users heading to the same place should have the
     * same value). A room_id of 0 is INVALID.
     */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|Application|Option")
    FOvrId RoomId;

    FOvrApplicationOptions()
    {
        DeeplinkMessage = TEXT("");
        DestinationApiName = TEXT("");
        LobbySessionId = TEXT("");
        MatchSessionId = TEXT("");
        RoomId = 0;
    }
};

/**
 *  The Avatar Editor Option is a feature that allows users to create and customize their avatars.
 * It is launched by the UOvrRequestsBlueprintLibrary::Avatar_LaunchAvatarEditor() request and provides a way for users
 * to specify the source of the request, allowing for more flexibility and customization in the avatar creation process.
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Options|AvatarEditor")
struct OVRPLATFORM_API FOvrAvatarEditorOptions
{
    GENERATED_USTRUCT_BODY()

    /**
     * Optional override for where the request is coming from. This field allows you to specify the source of the request
     * in the launched editor by calling UOvrRequestsBlueprintLibrary::Avatar_LaunchAvatarEditor(), which can be useful in cases where you want to track
     * or identify the origin of the request.
     */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|AvatarEditor|Option")
    FString SourceOverride;

    FOvrAvatarEditorOptions()
    {
        SourceOverride = TEXT("");
    }
};

/**
 * The Challenge Option is a parameter that can be passed in the UOvrRequestsBlueprintLibrary::Challenges_GetList() method to retrieve
 * a list of challenges that match the specified options. The FOvrChallengeOptions parameter allows you to
 * specify the criteria for the challenges you want to retrieve, such as the viewer filter, the visibility, or the date range.
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Options|Challenge")
struct OVRPLATFORM_API FOvrChallengeOptions
{
    GENERATED_USTRUCT_BODY()

    /**
     * The description of the challenge is a detailed and informative text that provides a comprehensive overview of the challenge's
     * objectives, rules, and requirements, which can be retrieved with field FOvrChallenge::Description.
     */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|Challenge|Option")
    FString Description;

    /** The challenge end date is the timestamp when this challenge ends, which can be retrieved using field FOvrChallenge::EndDate. */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|Challenge|Option")
    FDateTime EndDate;

    /**
     * This option indicates whether to include challenges that are currently active in the search results. By default, this is set to true,
     * meaning that only active challenges will be returned.
     */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|Challenge|Option")
    bool IncludeActiveChallenges;

    /**
     * This option indicates whether to include challenges that have not yet started in the search results. By default, this is set to false,
     * meaning that only active will be returned.
     */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|Challenge|Option")
    bool IncludeFutureChallenges;

    /**
     * This option indicates whether to include challenges that have already ended in the search results. By default, this is set to false,
     * meaning that only active will be returned.
     */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|Challenge|Option")
    bool IncludePastChallenges;

    /**
     * Optional: Only find challenges belonging to this leaderboard. This filter allows you to narrow down the search results to only include challenges
     * that are associated with a specific leaderboard.
     */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|Challenge|Option")
    FString LeaderboardName;

    /** The challenge start date is the timestamp when this challenge begins, which can be retrieved using field FOvrChallenge::StartDate. */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|Challenge|Option")
    FDateTime StartDate;

    /**
     * The title of the challenge is a descriptive label that provides a concise summary of the challenge's purpose and objectives,
     * which can be retrieved with field FOvrChallenge::Title.
     */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|Challenge|Option")
    FString Title;

    /**
     * An enum that specifies what filter to apply to the list of returned challenges.
     * 
     * Returns all public (EOvrChallengeVisibility::Public) and invite-only (EOvrChallengeVisibility::InviteOnly) FOvrChallenge in which the user is a participant or invitee. Excludes private (EOvrChallengeVisibility::Private) challenges.
     * 
     * EOvrChallengeViewerFilter::Participating - Returns challenges the user is participating in.
     * 
     * EOvrChallengeViewerFilter::Invited - Returns challenges the user is invited to.
     * 
     * EOvrChallengeViewerFilter::ParticipatingOrInvited - Returns challenges the user is either participating in or invited to.
     */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|Challenge|Option")
    EOvrChallengeViewerFilter ViewerFilter;

    /**
     * The challenge visibility setting specifies who can see and participate in this challenge, which be retrieved with field FOvrChallenge::Visibility.
     * There are three visibility levels: EOvrChallengeVisibility::Public, EOvrChallengeVisibility::InviteOnly and
     * EOvrChallengeVisibility::Private.
     */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|Challenge|Option")
    EOvrChallengeVisibility Visibility;

    FOvrChallengeOptions()
    {
        Description = TEXT("");
        EndDate = FDateTime(0);
        IncludeActiveChallenges = false;
        IncludeFutureChallenges = false;
        IncludePastChallenges = false;
        LeaderboardName = TEXT("");
        StartDate = FDateTime(0);
        Title = TEXT("");
        ViewerFilter = EOvrChallengeViewerFilter::Unknown;
        Visibility = EOvrChallengeVisibility::Unknown;
    }
};

/**
 * The Group Presence Option, to be passed in to UOvrRequestsBlueprintLibrary::GroupPresence_Set(), is a set of fields that allows developers to specify the presence of a user in a group/squad/party.
 * It provides a way for developers to create a more immersive and social experience for their users by allowing them to join and interact with other users.
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Options|GroupPresence")
struct OVRPLATFORM_API FOvrGroupPresenceOptions
{
    GENERATED_USTRUCT_BODY()

    /**
     * Use FOvrGroupPresenceOptions::LobbySessionId or FOvrGroupPresenceOptions::MatchSessionId to specify the session. Use the deeplink message override for
     * any additional data in whatever format you wish to aid in bringing users together. If not specified, the deeplink_message for the user will default to the one on the
     * destination.
     */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|GroupPresence|Option")
    FString DeeplinkMessageOverride;

    /** This the unique API Name that refers to an in-app destination */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|GroupPresence|Option")
    FString DestinationApiName;

    /**
     * Set whether or not the person is shown as joinable or not to others.  A user that is joinable can invite others to join them. Set this to false if other
     * users would not be able to join this user. For example: the current session is full, or only the host can invite others and the current user is not the host.
     */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|GroupPresence|Option")
    bool IsJoinable;

    /**
     * This is a session that represents a closer group/squad/party of users. It is expected that all users with the same lobby session id can see or
     * hear each other. Users with the same lobby session id in their group presence will show up in the roster and will show up as "Recently Played With"
     * for future invites if they aren't already Oculus friends. This must be set in addition to is_joinable being true for a user to use invites.
     */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|GroupPresence|Option")
    FString LobbySessionId;

    /**
     * This is a session that represents all the users that are playing a specific instance of a map, game mode, round, etc. This
     * can include users from multiple different lobbies that joined together and the users may or may not remain together after the match is over.
     * Users with the same match session id in their group presence will not show up in the Roster, but will show up as "Recently Played with" for future invites.
     */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|GroupPresence|Option")
    FString MatchSessionId;

    FOvrGroupPresenceOptions()
    {
        DeeplinkMessageOverride = TEXT("");
        DestinationApiName = TEXT("");
        IsJoinable = false;
        LobbySessionId = TEXT("");
        MatchSessionId = TEXT("");
    }
};

/**
 * The Invite Option, to be passed in to UOvrRequestsBlueprintLibrary::GroupPresence_GetInvitableUsers() and UOvrRequestsBlueprintLibrary::GroupPresence_LaunchInvitePanel(),
 * is a field that allows developers to specify a list of suggested users to be added to the invitable users list, making it easier for users to
 * connect with others and create a more social experience.
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Options|Invite")
struct OVRPLATFORM_API FOvrInviteOptions
{
    GENERATED_USTRUCT_BODY()

    /**
     * Passing in these users will add them to the invitable users list. From the UOvrRequestsBlueprintLibrary::GroupPresence_LaunchInvitePanel(), the user can open the invite list,
     * where the suggested users will be added.
     */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|Invite|Option")
    TArray<FOvrId> SuggestedUsers;
};

/**
 * The multiplayer error option is a feature that allows developers to display general error messages to FOvrUser in invokable error dialogs.
 * This option is particularly useful in multiplayer games or applications where errors can occur due to various reasons such as network connectivity
 * issues, server downtime, or other technical problems.
 * Read more about error dialogues in our [docs](https://developer.oculus.com/documentation/unreal/ps-error-dialogs/).
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Options|MultiplayerError")
struct OVRPLATFORM_API FOvrMultiplayerErrorOptions
{
    GENERATED_USTRUCT_BODY()

    /**
     * Key associated with the predefined error message to be shown to users.
     * 
     * Key List:
     * 
     * - EOvrMultiplayerErrorErrorKey::DestinationUnavailable
     * 
     * - EOvrMultiplayerErrorErrorKey::DlcRequired
     * 
     * - EOvrMultiplayerErrorErrorKey::General
     * 
     * - EOvrMultiplayerErrorErrorKey::GroupFull
     * 
     * - EOvrMultiplayerErrorErrorKey::InviterNotJoinable
     * 
     * - EOvrMultiplayerErrorErrorKey::LevelNotHighEnough
     * 
     * - EOvrMultiplayerErrorErrorKey::LevelNotUnlocked
     * 
     * - EOvrMultiplayerErrorErrorKey::NetworkTimeout
     * 
     * - EOvrMultiplayerErrorErrorKey::NoLongerAvailable
     * 
     * - EOvrMultiplayerErrorErrorKey::UpdateRequired
     * 
     * - EOvrMultiplayerErrorErrorKey::TutorialRequired
     */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|MultiplayerError|Option")
    EOvrMultiplayerErrorErrorKey ErrorKey;

    FOvrMultiplayerErrorOptions()
    {
        ErrorKey = EOvrMultiplayerErrorErrorKey::Unknown;
    }
};

/**
 * The NetSyncOption configures network connections, focusing on VoIP data streams.
 * It includes 'zone_id' for unique identifiers within the application, 'voip_stream_default' to set default VoIP stream modes , and 'voip_group' to assign a VoIP group upon connection.
 * It can be set when create a new connection and retrieved using FOvrNetSyncConnection.
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Options|NetSync")
struct OVRPLATFORM_API FOvrNetSyncOptions
{
    GENERATED_USTRUCT_BODY()

    /**
     * If provided, immediately set the voip_group to this value upon
     * connection and can be retrieved using field FOvrNetSyncSession::VoipGroup
     */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|NetSync|Option")
    FString VoipGroup;

    /**
     * When a new remote voip user connects, default that connection to this
     * stream type by default. There are three modes:
     * EOvrNetSyncVoipStreamMode::Unknown, EOvrNetSyncVoipStreamMode::Ambisonic, EOvrNetSyncVoipStreamMode::Mono.
     */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|NetSync|Option")
    EOvrNetSyncVoipStreamMode VoipStreamDefault;

    /** A `string` represents the unique identifier within the current application grouping.  */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|NetSync|Option")
    FString ZoneId;

    FOvrNetSyncOptions()
    {
        VoipGroup = TEXT("");
        VoipStreamDefault = EOvrNetSyncVoipStreamMode::Unknown;
        ZoneId = TEXT("");
    }
};

USTRUCT(BlueprintType, Category = "OvrPlatform|Options|RichPresence")
struct OVRPLATFORM_API FOvrRichPresenceOptions
{
    GENERATED_USTRUCT_BODY()

    /** \deprecated Use FOvrGroupPresenceOptions::DestinationApiName */
    UPROPERTY(BlueprintReadWrite, meta = (DeprecatedProperty, DeprecationMessage="Use FOvrGroupPresenceOptions::DestinationApiName"), Category = "OvrPlatform|Options|RichPresence|Option")
    FString ApiName;

    /** \deprecated Use FOvrGroupPresenceOptions::DeeplinkMessageOverride  */
    UPROPERTY(BlueprintReadWrite, meta = (DeprecatedProperty, DeprecationMessage="Use FOvrGroupPresenceOptions::DeeplinkMessageOverride"), Category = "OvrPlatform|Options|RichPresence|Option")
    FString DeeplinkMessageOverride;

    /** \deprecated Use FOvrGroupPresenceOptions::IsJoinable */
    UPROPERTY(BlueprintReadWrite, meta = (DeprecatedProperty, DeprecationMessage="Use FOvrGroupPresenceOptions::IsJoinable"), Category = "OvrPlatform|Options|RichPresence|Option")
    bool IsJoinable;

    FOvrRichPresenceOptions()
    {
        ApiName = TEXT("");
        DeeplinkMessageOverride = TEXT("");
        IsJoinable = false;
    }
};

/** The roster option, to be passed into UOvrRequestsBlueprintLibrary::GroupPresence_LaunchRosterPanel() which is used to launch the panel displaying the current users in the roster/party. You can read more about rosters in our [docs](https://developer.oculus.com/documentation/unreal/ps-roster/). */
USTRUCT(BlueprintType, Category = "OvrPlatform|Options|Roster")
struct OVRPLATFORM_API FOvrRosterOptions
{
    GENERATED_USTRUCT_BODY()

    /**
     * Passing in these users will add them to the invitable users list. From the UOvrRequestsBlueprintLibrary::GroupPresence_LaunchRosterPanel(), the FOvrUser can open the invite list,
     * where the suggested users will be added.
     */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|Roster|Option")
    TArray<FOvrId> SuggestedUsers;
};

/**
 * The user_options configuration is used to specify additional settings for the FOvrUser.
 * It allows you to customize the response by specifying the time window,
 * maximum number of users, and service providers for which linked accounts should be retrieved.
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Options|User")
struct OVRPLATFORM_API FOvrUserOptions
{
    GENERATED_USTRUCT_BODY()

    /** This field specifies the maximum number of FOvrUser that should be returned in the response.  */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|User|Option")
    int32 MaxUsers;

    /** It's an array of #EOvrServiceProvider objects that specifies the service providers for which linked accounts should be retrieved. */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|User|Option")
    TArray<EOvrServiceProvider> ServiceProviders;

    /** This field specifies the time window in seconds for which the linked accounts should be retrieved. */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|User|Option")
    EOvrTimeWindow TimeWindow;

    FOvrUserOptions()
    {
        MaxUsers = 0;
        TimeWindow = EOvrTimeWindow::Unknown;
    }
};

/**
 * The voip_options configuration is used to specify additional settings for the VoIP transmission for a FOvrUser.
 * It consists of two primary options which include using DTX for transmission and setting a maxmimum bitrate for the network connection.
 * You can read more about VoIP [here](https://developer.oculus.com/documentation/unity/ps-parties/#voip-options).
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Options|Voip")
struct OVRPLATFORM_API FOvrVoipOptions
{
    GENERATED_USTRUCT_BODY()

    /**
     * Sets the maximum average bitrate the audio codec should use. Higher bitrates
     * will increase audio quality at the expense of increased network usage. Use a lower
     * bitrate if you think the quality is good but the network usage is too much. Use a
     * higher bitrate if you think the quality is bad and you can afford to have a large
     * streaming bitrate.
     */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|Voip|Option")
    EOvrVoipBitrate BitrateForNewConnections;

    /**
     * Set the opus codec to use discontinous transmission (DTX). DTX only transmits
     * data when a person is speaking. Setting this to EOvrVoipDtxState::Enabled takes advantage of the fact
     * that in a two-way converstation each individual speaks for less than half the time.
     * Enabling DTX will conserve battery power and reduce transmission rate when a pause
     * in the voice chat is detected.
     */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|Voip|Option")
    EOvrVoipDtxState CreateNewConnectionUseDtx;

    FOvrVoipOptions()
    {
        BitrateForNewConnections = EOvrVoipBitrate::Unknown;
        CreateNewConnectionUseDtx = EOvrVoipDtxState::Unknown;
    }
};
