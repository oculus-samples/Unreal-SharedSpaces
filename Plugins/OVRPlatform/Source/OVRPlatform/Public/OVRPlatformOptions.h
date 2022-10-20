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
#include "OVRPlatformTypes.h"
#include "OVRPlatformOptions.generated.h"


USTRUCT(BlueprintType, Category = "OvrPlatform|Options|AbuseReport")
struct OVRPLATFORM_API FOvrAbuseReportOptions
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|AbuseReport|Option")
    bool PreventPeopleChooser;

    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|AbuseReport|Option")
    EOvrAbuseReportType ReportType;

    FOvrAbuseReportOptions()
    {
        PreventPeopleChooser = false;
        ReportType = EOvrAbuseReportType::Unknown;
    }
};

USTRUCT(BlueprintType, Category = "OvrPlatform|Options|AdvancedAbuseReport")
struct OVRPLATFORM_API FOvrAdvancedAbuseReportOptions
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|AdvancedAbuseReport|Option")
    TMap<FString, FString> DeveloperDefinedContext;

    /** If report_type is content, a string representing the type of content being reported. This should correspond to the object_type string used in the UI */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|AdvancedAbuseReport|Option")
    FString ObjectType;

    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|AdvancedAbuseReport|Option")
    EOvrAbuseReportType ReportType;

    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|AdvancedAbuseReport|Option")
    TArray<FOvrId> SuggestedUsers;

    FOvrAdvancedAbuseReportOptions()
    {
        ObjectType = TEXT("");
        ReportType = EOvrAbuseReportType::Unknown;
    }
};

USTRUCT(BlueprintType, Category = "OvrPlatform|Options|Application")
struct OVRPLATFORM_API FOvrApplicationOptions
{
    GENERATED_USTRUCT_BODY()

    /**
     * A message to be passed to a launched app, which can be retrieved
     * with field FOvrLaunchDetails::DeeplinkMessage
     */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|Application|Option")
    FString DeeplinkMessage;

    FOvrApplicationOptions()
    {
        DeeplinkMessage = TEXT("");
    }
};

USTRUCT(BlueprintType, Category = "OvrPlatform|Options|Challenge")
struct OVRPLATFORM_API FOvrChallengeOptions
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|Challenge|Option")
    FString Description;

    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|Challenge|Option")
    FDateTime EndDate;

    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|Challenge|Option")
    bool IncludeActiveChallenges;

    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|Challenge|Option")
    bool IncludeFutureChallenges;

    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|Challenge|Option")
    bool IncludePastChallenges;

    /** Optional: Only find challenges belonging to this leaderboard. */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|Challenge|Option")
    FString LeaderboardName;

    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|Challenge|Option")
    FDateTime StartDate;

    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|Challenge|Option")
    FString Title;

    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|Challenge|Option")
    EOvrChallengeViewerFilter ViewerFilter;

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

USTRUCT(BlueprintType, Category = "OvrPlatform|Options|Invite")
struct OVRPLATFORM_API FOvrInviteOptions
{
    GENERATED_USTRUCT_BODY()

    /** Passing in these users will add them to the invitable users list */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|Invite|Option")
    TArray<FOvrId> SuggestedUsers;
};

USTRUCT(BlueprintType, Category = "OvrPlatform|Options|Matchmaking")
struct OVRPLATFORM_API FOvrMatchmakingOptions
{
    GENERATED_USTRUCT_BODY()

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadWrite, meta = (DeprecatedProperty), Category = "OvrPlatform|Options|Matchmaking|Option")
    TMap<FString, FString> CreateRoomDataStore;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadWrite, meta = (DeprecatedProperty), Category = "OvrPlatform|Options|Matchmaking|Option")
    EOvrRoomJoinPolicy CreateRoomJoinPolicy;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadWrite, meta = (DeprecatedProperty), Category = "OvrPlatform|Options|Matchmaking|Option")
    int32 CreateRoomMaxUsers;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadWrite, meta = (DeprecatedProperty), Category = "OvrPlatform|Options|Matchmaking|Option")
    TArray<FOvrId> EnqueueAdditionalUsers;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadWrite, meta = (DeprecatedProperty), Category = "OvrPlatform|Options|Matchmaking|Option")
    TMap<FString, FOvrVariant> EnqueueDataSettings;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadWrite, meta = (DeprecatedProperty), Category = "OvrPlatform|Options|Matchmaking|Option")
    bool EnqueueIsDebug;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadWrite, meta = (DeprecatedProperty), Category = "OvrPlatform|Options|Matchmaking|Option")
    FString EnqueueQueryKey;

    FOvrMatchmakingOptions()
    {
        CreateRoomJoinPolicy = EOvrRoomJoinPolicy::Unknown;
        CreateRoomMaxUsers = 0;
        EnqueueIsDebug = false;
        EnqueueQueryKey = TEXT("");
    }
};

USTRUCT(BlueprintType, Category = "OvrPlatform|Options|MultiplayerError")
struct OVRPLATFORM_API FOvrMultiplayerErrorOptions
{
    GENERATED_USTRUCT_BODY()

    /** Key associated with the predefined error message to be shown to users. */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|MultiplayerError|Option")
    EOvrMultiplayerErrorErrorKey ErrorKey;

    FOvrMultiplayerErrorOptions()
    {
        ErrorKey = EOvrMultiplayerErrorErrorKey::Unknown;
    }
};

USTRUCT(BlueprintType, Category = "OvrPlatform|Options|NetSync")
struct OVRPLATFORM_API FOvrNetSyncOptions
{
    GENERATED_USTRUCT_BODY()

    /**
     * If provided, immediately set the voip_group to this value upon
     * connection
     */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|NetSync|Option")
    FString VoipGroup;

    /**
     * When a new remote voip user connects, default that connection to this
     * stream type by default.
     */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|NetSync|Option")
    EOvrNetSyncVoipStreamMode VoipStreamDefault;

    /** Unique identifier within the current application grouping */
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

    /** DEPRECATED. Use FOvrGroupPresenceOptions::DestinationApiName */
    UPROPERTY(BlueprintReadWrite, meta = (DeprecatedProperty, DeprecationMessage="Use FOvrGroupPresenceOptions::DestinationApiName"), Category = "OvrPlatform|Options|RichPresence|Option")
    FString ApiName;

    /** DEPRECATED. Unused. */
    UPROPERTY(BlueprintReadWrite, meta = (DeprecatedProperty, DeprecationMessage="Unused."), Category = "OvrPlatform|Options|RichPresence|Option")
    TMap<FString, FString> Args;

    /** DEPRECATED. Unused. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadWrite, meta = (DeprecatedProperty, DeprecationMessage="Unused."), Category = "OvrPlatform|Options|RichPresence|Option")
    int32 CurrentCapacity;

    /** DEPRECATED. Use FOvrGroupPresenceOptions::DeeplinkMessageOverride */
    UPROPERTY(BlueprintReadWrite, meta = (DeprecatedProperty, DeprecationMessage="Use FOvrGroupPresenceOptions::DeeplinkMessageOverride"), Category = "OvrPlatform|Options|RichPresence|Option")
    FString DeeplinkMessageOverride;

    /** DEPRECATED. Unused. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadWrite, meta = (DeprecatedProperty, DeprecationMessage="Unused."), Category = "OvrPlatform|Options|RichPresence|Option")
    FDateTime EndTime;

    /** DEPRECATED. Unused. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadWrite, meta = (DeprecatedProperty, DeprecationMessage="Unused."), Category = "OvrPlatform|Options|RichPresence|Option")
    EOvrRichPresenceExtraContext ExtraContext;

    /** DEPRECATED. Use FOvrGroupPresenceOptions::MatchSessionId Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadWrite, meta = (DeprecatedProperty, DeprecationMessage="Use FOvrGroupPresenceOptions::MatchSessionId"), Category = "OvrPlatform|Options|RichPresence|Option")
    FString InstanceId;

    /** DEPRECATED. Unused. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadWrite, meta = (DeprecatedProperty, DeprecationMessage="Unused."), Category = "OvrPlatform|Options|RichPresence|Option")
    bool IsIdle;

    /** DEPRECATED. Use FOvrGroupPresenceOptions::IsJoinable */
    UPROPERTY(BlueprintReadWrite, meta = (DeprecatedProperty, DeprecationMessage="Use FOvrGroupPresenceOptions::IsJoinable"), Category = "OvrPlatform|Options|RichPresence|Option")
    bool IsJoinable;

    /** DEPRECATED. Unused. */
    UPROPERTY(BlueprintReadWrite, meta = (DeprecatedProperty, DeprecationMessage="Unused."), Category = "OvrPlatform|Options|RichPresence|Option")
    FString JoinableId;

    /** DEPRECATED. Use FOvrGroupPresenceOptions::LobbySessionId Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadWrite, meta = (DeprecatedProperty, DeprecationMessage="Use FOvrGroupPresenceOptions::LobbySessionId"), Category = "OvrPlatform|Options|RichPresence|Option")
    FString LobbySessionId;

    /** DEPRECATED. Use FOvrGroupPresenceOptions::MatchSessionId Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadWrite, meta = (DeprecatedProperty, DeprecationMessage="Use FOvrGroupPresenceOptions::MatchSessionId"), Category = "OvrPlatform|Options|RichPresence|Option")
    FString MatchSessionId;

    /** DEPRECATED. Unused. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadWrite, meta = (DeprecatedProperty, DeprecationMessage="Unused."), Category = "OvrPlatform|Options|RichPresence|Option")
    int32 MaxCapacity;

    /** DEPRECATED. Unused. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadWrite, meta = (DeprecatedProperty, DeprecationMessage="Unused."), Category = "OvrPlatform|Options|RichPresence|Option")
    FDateTime StartTime;

    FOvrRichPresenceOptions()
    {
        ApiName = TEXT("");
        CurrentCapacity = 0;
        DeeplinkMessageOverride = TEXT("");
        EndTime = FDateTime(0);
        ExtraContext = EOvrRichPresenceExtraContext::Unknown;
        InstanceId = TEXT("");
        IsIdle = false;
        IsJoinable = false;
        JoinableId = TEXT("");
        LobbySessionId = TEXT("");
        MatchSessionId = TEXT("");
        MaxCapacity = 0;
        StartTime = FDateTime(0);
    }
};

USTRUCT(BlueprintType, Category = "OvrPlatform|Options|Room")
struct OVRPLATFORM_API FOvrRoomOptions
{
    GENERATED_USTRUCT_BODY()

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadWrite, meta = (DeprecatedProperty), Category = "OvrPlatform|Options|Room|Option")
    TMap<FString, FString> DataStore;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadWrite, meta = (DeprecatedProperty), Category = "OvrPlatform|Options|Room|Option")
    bool ExcludeRecentlyMet;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadWrite, meta = (DeprecatedProperty), Category = "OvrPlatform|Options|Room|Option")
    int32 MaxUserResults;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadWrite, meta = (DeprecatedProperty), Category = "OvrPlatform|Options|Room|Option")
    EOvrUserOrdering Ordering;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadWrite, meta = (DeprecatedProperty), Category = "OvrPlatform|Options|Room|Option")
    EOvrTimeWindow RecentlyMetTimeWindow;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadWrite, meta = (DeprecatedProperty), Category = "OvrPlatform|Options|Room|Option")
    FOvrId RoomId;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadWrite, meta = (DeprecatedProperty), Category = "OvrPlatform|Options|Room|Option")
    bool TurnOffUpdates;

    FOvrRoomOptions()
    {
        ExcludeRecentlyMet = false;
        MaxUserResults = 0;
        Ordering = EOvrUserOrdering::Unknown;
        RecentlyMetTimeWindow = EOvrTimeWindow::Unknown;
        RoomId = 0;
        TurnOffUpdates = false;
    }
};

USTRUCT(BlueprintType, Category = "OvrPlatform|Options|Roster")
struct OVRPLATFORM_API FOvrRosterOptions
{
    GENERATED_USTRUCT_BODY()

    /**
     * Passing in these users will add them to the invitable users list. From the roster panel, the user can open the invite list,
     * where the suggested users will be added.
     */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|Roster|Option")
    TArray<FOvrId> SuggestedUsers;
};

USTRUCT(BlueprintType, Category = "OvrPlatform|Options|User")
struct OVRPLATFORM_API FOvrUserOptions
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|User|Option")
    int32 MaxUsers;

    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|User|Option")
    TArray<EOvrServiceProvider> ServiceProviders;

    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|User|Option")
    EOvrTimeWindow TimeWindow;

    FOvrUserOptions()
    {
        MaxUsers = 0;
        TimeWindow = EOvrTimeWindow::Unknown;
    }
};

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
     * data when a person is speaking. Setting this to true takes advantage of the fact
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
