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


USTRUCT(BlueprintType)
struct OVRPLATFORM_API FOvrAbuseReportOptions
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadWrite)
    bool PreventPeopleChooser;

    UPROPERTY(BlueprintReadWrite)
    EOvrAbuseReportType ReportType;

    FOvrAbuseReportOptions()
    {
        PreventPeopleChooser = false;
        ReportType = EOvrAbuseReportType::Unknown;
    }
};

USTRUCT(BlueprintType)
struct OVRPLATFORM_API FOvrAdvancedAbuseReportOptions
{
    GENERATED_USTRUCT_BODY()

    /** If report_type is content, a string representing the type of content being reported. This should correspond to the object_type string used in the UI */
    UPROPERTY(BlueprintReadWrite)
    FString ObjectType;

    UPROPERTY(BlueprintReadWrite)
    EOvrAbuseReportType ReportType;

    FOvrAdvancedAbuseReportOptions()
    {
        ObjectType = TEXT("");
        ReportType = EOvrAbuseReportType::Unknown;
    }
};

USTRUCT(BlueprintType)
struct OVRPLATFORM_API FOvrApplicationOptions
{
    GENERATED_USTRUCT_BODY()

    /**
     * A message to be passed to a launched app, which can be retrieved
     * with field FOvrLaunchDetails::DeeplinkMessage
     */
    UPROPERTY(BlueprintReadWrite)
    FString DeeplinkMessage;

    FOvrApplicationOptions()
    {
        DeeplinkMessage = TEXT("");
    }
};

USTRUCT(BlueprintType)
struct OVRPLATFORM_API FOvrChallengeOptions
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadWrite)
    FString Description;

    UPROPERTY(BlueprintReadWrite)
    FDateTime EndDate;

    UPROPERTY(BlueprintReadWrite)
    bool IncludeActiveChallenges;

    UPROPERTY(BlueprintReadWrite)
    bool IncludeFutureChallenges;

    UPROPERTY(BlueprintReadWrite)
    bool IncludePastChallenges;

    /** Optional: Only find challenges belonging to this leaderboard. */
    UPROPERTY(BlueprintReadWrite)
    FString LeaderboardName;

    UPROPERTY(BlueprintReadWrite)
    FDateTime StartDate;

    UPROPERTY(BlueprintReadWrite)
    FString Title;

    UPROPERTY(BlueprintReadWrite)
    EOvrChallengeViewerFilter ViewerFilter;

    UPROPERTY(BlueprintReadWrite)
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

USTRUCT(BlueprintType)
struct OVRPLATFORM_API FOvrGroupPresenceOptions
{
    GENERATED_USTRUCT_BODY()

    /** This the unique API Name that refers to an in-app destination */
    UPROPERTY(BlueprintReadWrite)
    FString DestinationApiName;

    /**
     * Set whether or not the person is shown as joinable or not to others.  A user that is joinable can invite others to join them. Set this to false if other
     * users would not be able to join this user. For example: the current session is full, or only the host can invite others and the current user is not the host.
     */
    UPROPERTY(BlueprintReadWrite)
    bool IsJoinable;

    /**
     * This is a session that represents a closer group/squad/party of users. It is expected that all users with the same lobby session id can see or
     * hear each other. Users with the same lobby session id in their group presence will show up in the roster and will show up as "Recently Played With"
     * for future invites if they aren't already Oculus friends. This must be set in addition to is_joinable being true for a user to use invites.
     */
    UPROPERTY(BlueprintReadWrite)
    FString LobbySessionId;

    /**
     * This is a session that represents all the users that are playing a specific instance of a map, game mode, round, etc. This
     * can include users from multiple different lobbies that joined together and the users may or may not remain together after the match is over.
     * Users with the same match session id in their group presence will not show up in the Roster, but will show up as "Recently Played with" for future invites.
     */
    UPROPERTY(BlueprintReadWrite)
    FString MatchSessionId;

    FOvrGroupPresenceOptions()
    {
        DestinationApiName = TEXT("");
        IsJoinable = false;
        LobbySessionId = TEXT("");
        MatchSessionId = TEXT("");
    }
};

USTRUCT(BlueprintType)
struct OVRPLATFORM_API FOvrInviteOptions
{
    GENERATED_USTRUCT_BODY()

    /** Passing in these users will add them to the invitable users list */
    UPROPERTY(BlueprintReadWrite)
    TArray<FOvrId> SuggestedUsers;
};

USTRUCT(BlueprintType)
struct OVRPLATFORM_API FOvrMatchmakingOptions
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadWrite)
    TMap<FString, FString> CreateRoomDataStore;

    UPROPERTY(BlueprintReadWrite)
    EOvrRoomJoinPolicy CreateRoomJoinPolicy;

    UPROPERTY(BlueprintReadWrite)
    int32 CreateRoomMaxUsers;

    UPROPERTY(BlueprintReadWrite)
    TArray<FOvrId> EnqueueAdditionalUsers;

    UPROPERTY(BlueprintReadWrite)
    TMap<FString, FOvrVariant> EnqueueDataSettings;

    UPROPERTY(BlueprintReadWrite)
    bool EnqueueIsDebug;

    UPROPERTY(BlueprintReadWrite)
    FString EnqueueQueryKey;

    FOvrMatchmakingOptions()
    {
        CreateRoomJoinPolicy = EOvrRoomJoinPolicy::Unknown;
        CreateRoomMaxUsers = 0;
        EnqueueIsDebug = false;
        EnqueueQueryKey = TEXT("");
    }
};

USTRUCT(BlueprintType)
struct OVRPLATFORM_API FOvrMultiplayerErrorOptions
{
    GENERATED_USTRUCT_BODY()

    /** Key associated with the predefined error message to be shown to users. */
    UPROPERTY(BlueprintReadWrite)
    EOvrMultiplayerErrorErrorKey ErrorKey;

    FOvrMultiplayerErrorOptions()
    {
        ErrorKey = EOvrMultiplayerErrorErrorKey::Unknown;
    }
};

USTRUCT(BlueprintType)
struct OVRPLATFORM_API FOvrNetSyncOptions
{
    GENERATED_USTRUCT_BODY()

    /**
     * If provided, immediately set the voip_group to this value upon
     * connection
     */
    UPROPERTY(BlueprintReadWrite)
    FString VoipGroup;

    /**
     * When a new remote voip user connects, default that connection to this
     * stream type by default.
     */
    UPROPERTY(BlueprintReadWrite)
    EOvrNetSyncVoipStreamMode VoipStreamDefault;

    /** Unique identifier within the current application grouping */
    UPROPERTY(BlueprintReadWrite)
    FString ZoneId;

    FOvrNetSyncOptions()
    {
        VoipGroup = TEXT("");
        VoipStreamDefault = EOvrNetSyncVoipStreamMode::Unknown;
        ZoneId = TEXT("");
    }
};

USTRUCT(BlueprintType)
struct OVRPLATFORM_API FOvrRichPresenceOptions
{
    GENERATED_USTRUCT_BODY()

    /** DEPRECATED: Use FOvrGroupPresenceOptions::DestinationApiName */
    UPROPERTY(BlueprintReadWrite)
    FString ApiName;

    /** DEPRECATED: Unused */
    UPROPERTY(BlueprintReadWrite)
    TMap<FString, FString> Args;

    /** DEPRECATED: Unused */
    UPROPERTY(BlueprintReadWrite)
    int32 CurrentCapacity;

    /** DEPRECATED: Use FOvrGroupPresenceOptions::LobbySessionId or FOvrGroupPresenceOptions::MatchSessionId to specify the session */
    UPROPERTY(BlueprintReadWrite)
    FString DeeplinkMessageOverride;

    /** DEPRECATED: Unused */
    UPROPERTY(BlueprintReadWrite)
    FDateTime EndTime;

    /** DEPRECATED: Unused */
    UPROPERTY(BlueprintReadWrite)
    EOvrRichPresenceExtraContext ExtraContext;

    /** DEPRECATED: Use FOvrGroupPresenceOptions::MatchSessionId */
    UPROPERTY(BlueprintReadWrite)
    FString InstanceId;

    /** DEPRECATED: Unused */
    UPROPERTY(BlueprintReadWrite)
    bool IsIdle;

    /** DEPRECATED: Use FOvrGroupPresenceOptions::IsJoinable */
    UPROPERTY(BlueprintReadWrite)
    bool IsJoinable;

    /** DEPRECATED: unused */
    UPROPERTY(BlueprintReadWrite)
    FString JoinableId;

    /** DEPRECATED: Use FOvrGroupPresenceOptions::LobbySessionId */
    UPROPERTY(BlueprintReadWrite)
    FString LobbySessionId;

    /** DEPRECATED: Use FOvrGroupPresenceOptions::MatchSessionId */
    UPROPERTY(BlueprintReadWrite)
    FString MatchSessionId;

    /** DEPRECATED: Unused */
    UPROPERTY(BlueprintReadWrite)
    int32 MaxCapacity;

    /** DEPRECATED: Unused */
    UPROPERTY(BlueprintReadWrite)
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

USTRUCT(BlueprintType)
struct OVRPLATFORM_API FOvrRoomOptions
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadWrite)
    TMap<FString, FString> DataStore;

    UPROPERTY(BlueprintReadWrite)
    bool ExcludeRecentlyMet;

    UPROPERTY(BlueprintReadWrite)
    int32 MaxUserResults;

    UPROPERTY(BlueprintReadWrite)
    EOvrUserOrdering Ordering;

    UPROPERTY(BlueprintReadWrite)
    EOvrTimeWindow RecentlyMetTimeWindow;

    UPROPERTY(BlueprintReadWrite)
    FOvrId RoomId;

    UPROPERTY(BlueprintReadWrite)
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

USTRUCT(BlueprintType)
struct OVRPLATFORM_API FOvrRosterOptions
{
    GENERATED_USTRUCT_BODY()

    /**
     * Passing in these users will add them to the invitable users list. From the roster panel, the user can open the invite list,
     * where the suggested users will be added.
     */
    UPROPERTY(BlueprintReadWrite)
    TArray<FOvrId> SuggestedUsers;
};

USTRUCT(BlueprintType)
struct OVRPLATFORM_API FOvrUserOptions
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadWrite)
    int32 MaxUsers;

    UPROPERTY(BlueprintReadWrite)
    TArray<EOvrServiceProvider> ServiceProviders;

    UPROPERTY(BlueprintReadWrite)
    EOvrTimeWindow TimeWindow;

    FOvrUserOptions()
    {
        MaxUsers = 0;
        TimeWindow = EOvrTimeWindow::Unknown;
    }
};

USTRUCT(BlueprintType)
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
    UPROPERTY(BlueprintReadWrite)
    EOvrVoipBitrate BitrateForNewConnections;

    /**
     * Set the opus codec to use discontinous transmission (DTX). DTX only transmits
     * data when a person is speaking. Setting this to true takes advantage of the fact
     * that in a two-way converstation each individual speaks for less than half the time.
     * Enabling DTX will conserve battery power and reduce transmission rate when a pause
     * in the voice chat is detected.
     */
    UPROPERTY(BlueprintReadWrite)
    EOvrVoipDtxState CreateNewConnectionUseDtx;

    FOvrVoipOptions()
    {
        BitrateForNewConnections = EOvrVoipBitrate::Unknown;
        CreateNewConnectionUseDtx = EOvrVoipDtxState::Unknown;
    }
};
