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

    /**
     * If provided, the intended destination to be passed to the launched
     * app
     */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|Application|Option")
    FString DestinationApiName;

    /**
     * If provided, the intended lobby where the launched app should take
     * the user. All users with the same lobby_session_id should end up grouped
     * together in the launched app.
     */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|Application|Option")
    FString LobbySessionId;

    /**
     * If provided, the intended instance of the destination that a user
     * should be launched into
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

USTRUCT(BlueprintType, Category = "OvrPlatform|Options|AvatarEditor")
struct OVRPLATFORM_API FOvrAvatarEditorOptions
{
    GENERATED_USTRUCT_BODY()

    /** Optional: Override for where the request is coming from. */
    UPROPERTY(BlueprintReadWrite, Category = "OvrPlatform|Options|AvatarEditor|Option")
    FString SourceOverride;

    FOvrAvatarEditorOptions()
    {
        SourceOverride = TEXT("");
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

    /** DEPRECATED. Use FOvrGroupPresenceOptions::DeeplinkMessageOverride */
    UPROPERTY(BlueprintReadWrite, meta = (DeprecatedProperty, DeprecationMessage="Use FOvrGroupPresenceOptions::DeeplinkMessageOverride"), Category = "OvrPlatform|Options|RichPresence|Option")
    FString DeeplinkMessageOverride;

    /** DEPRECATED. Use FOvrGroupPresenceOptions::IsJoinable */
    UPROPERTY(BlueprintReadWrite, meta = (DeprecatedProperty, DeprecationMessage="Use FOvrGroupPresenceOptions::IsJoinable"), Category = "OvrPlatform|Options|RichPresence|Option")
    bool IsJoinable;

    FOvrRichPresenceOptions()
    {
        ApiName = TEXT("");
        DeeplinkMessageOverride = TEXT("");
        IsJoinable = false;
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
