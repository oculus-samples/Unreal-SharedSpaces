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

// These converters are used to translate options from UE to C during calls to the OVR Platform.

#include "OVRPlatformOptions.h"

struct OVRPLATFORM_API FOvrAbuseReportOptionsConverter
{
    FOvrAbuseReportOptionsConverter(const FOvrAbuseReportOptions& Options):
        Handle(ovr_AbuseReportOptions_Create())
    {
        if (Handle)
        {
            ovr_AbuseReportOptions_SetPreventPeopleChooser(Handle, Options.PreventPeopleChooser);
            ovr_AbuseReportOptions_SetReportType(Handle, ConvertAbuseReportType(Options.ReportType));
        }
    }

    ~FOvrAbuseReportOptionsConverter()
    {
        ovr_AbuseReportOptions_Destroy(Handle);
    }

    operator ovrAbuseReportOptionsHandle() const
    {
        return Handle;
    }

    ovrAbuseReportOptionsHandle Handle;
};

struct OVRPLATFORM_API FOvrAdvancedAbuseReportOptionsConverter
{
    FOvrAdvancedAbuseReportOptionsConverter(const FOvrAdvancedAbuseReportOptions& Options):
        Handle(ovr_AdvancedAbuseReportOptions_Create())
    {
        if (Handle)
        {
            for (auto& Pair : Options.DeveloperDefinedContext)
            {
                ovr_AdvancedAbuseReportOptions_SetDeveloperDefinedContextString(Handle, TCHAR_TO_UTF8(*Pair.Key), TCHAR_TO_UTF8(*Pair.Value));
            }
            ovr_AdvancedAbuseReportOptions_SetObjectType(Handle, TCHAR_TO_UTF8(*Options.ObjectType));
            ovr_AdvancedAbuseReportOptions_SetReportType(Handle, ConvertAbuseReportType(Options.ReportType));
            for (size_t Index = 0, TotalIndices = Options.SuggestedUsers.Num(); Index < TotalIndices; ++Index)
            {
                ovr_AdvancedAbuseReportOptions_AddSuggestedUser(Handle, static_cast<ovrID>(Options.SuggestedUsers[Index]));
            }
        }
    }

    ~FOvrAdvancedAbuseReportOptionsConverter()
    {
        ovr_AdvancedAbuseReportOptions_Destroy(Handle);
    }

    operator ovrAdvancedAbuseReportOptionsHandle() const
    {
        return Handle;
    }

    ovrAdvancedAbuseReportOptionsHandle Handle;
};

struct OVRPLATFORM_API FOvrApplicationOptionsConverter
{
    FOvrApplicationOptionsConverter(const FOvrApplicationOptions& Options):
        Handle(ovr_ApplicationOptions_Create())
    {
        if (Handle)
        {
            ovr_ApplicationOptions_SetDeeplinkMessage(Handle, TCHAR_TO_UTF8(*Options.DeeplinkMessage));
        }
    }

    ~FOvrApplicationOptionsConverter()
    {
        ovr_ApplicationOptions_Destroy(Handle);
    }

    operator ovrApplicationOptionsHandle() const
    {
        return Handle;
    }

    ovrApplicationOptionsHandle Handle;
};

struct OVRPLATFORM_API FOvrChallengeOptionsConverter
{
    FOvrChallengeOptionsConverter(const FOvrChallengeOptions& Options):
        Handle(ovr_ChallengeOptions_Create())
    {
        if (Handle)
        {
            ovr_ChallengeOptions_SetDescription(Handle, TCHAR_TO_UTF8(*Options.Description));
            ovr_ChallengeOptions_SetEndDate(Handle, (unsigned long long) Options.EndDate.ToUnixTimestamp());
            ovr_ChallengeOptions_SetIncludeActiveChallenges(Handle, Options.IncludeActiveChallenges);
            ovr_ChallengeOptions_SetIncludeFutureChallenges(Handle, Options.IncludeFutureChallenges);
            ovr_ChallengeOptions_SetIncludePastChallenges(Handle, Options.IncludePastChallenges);
            ovr_ChallengeOptions_SetLeaderboardName(Handle, TCHAR_TO_UTF8(*Options.LeaderboardName));
            ovr_ChallengeOptions_SetStartDate(Handle, (unsigned long long) Options.StartDate.ToUnixTimestamp());
            ovr_ChallengeOptions_SetTitle(Handle, TCHAR_TO_UTF8(*Options.Title));
            ovr_ChallengeOptions_SetViewerFilter(Handle, ConvertChallengeViewerFilter(Options.ViewerFilter));
            ovr_ChallengeOptions_SetVisibility(Handle, ConvertChallengeVisibility(Options.Visibility));
        }
    }

    ~FOvrChallengeOptionsConverter()
    {
        ovr_ChallengeOptions_Destroy(Handle);
    }

    operator ovrChallengeOptionsHandle() const
    {
        return Handle;
    }

    ovrChallengeOptionsHandle Handle;
};

struct OVRPLATFORM_API FOvrGroupPresenceOptionsConverter
{
    FOvrGroupPresenceOptionsConverter(const FOvrGroupPresenceOptions& Options):
        Handle(ovr_GroupPresenceOptions_Create())
    {
        if (Handle)
        {
            ovr_GroupPresenceOptions_SetDeeplinkMessageOverride(Handle, TCHAR_TO_UTF8(*Options.DeeplinkMessageOverride));
            ovr_GroupPresenceOptions_SetDestinationApiName(Handle, TCHAR_TO_UTF8(*Options.DestinationApiName));
            ovr_GroupPresenceOptions_SetIsJoinable(Handle, Options.IsJoinable);
            ovr_GroupPresenceOptions_SetLobbySessionId(Handle, TCHAR_TO_UTF8(*Options.LobbySessionId));
            ovr_GroupPresenceOptions_SetMatchSessionId(Handle, TCHAR_TO_UTF8(*Options.MatchSessionId));
        }
    }

    ~FOvrGroupPresenceOptionsConverter()
    {
        ovr_GroupPresenceOptions_Destroy(Handle);
    }

    operator ovrGroupPresenceOptionsHandle() const
    {
        return Handle;
    }

    ovrGroupPresenceOptionsHandle Handle;
};

struct OVRPLATFORM_API FOvrInviteOptionsConverter
{
    FOvrInviteOptionsConverter(const FOvrInviteOptions& Options):
        Handle(ovr_InviteOptions_Create())
    {
        if (Handle)
        {
            for (size_t Index = 0, TotalIndices = Options.SuggestedUsers.Num(); Index < TotalIndices; ++Index)
            {
                ovr_InviteOptions_AddSuggestedUser(Handle, static_cast<ovrID>(Options.SuggestedUsers[Index]));
            }
        }
    }

    ~FOvrInviteOptionsConverter()
    {
        ovr_InviteOptions_Destroy(Handle);
    }

    operator ovrInviteOptionsHandle() const
    {
        return Handle;
    }

    ovrInviteOptionsHandle Handle;
};

struct OVRPLATFORM_API FOvrMatchmakingOptionsConverter
{
    FOvrMatchmakingOptionsConverter(const FOvrMatchmakingOptions& Options):
        Handle(ovr_MatchmakingOptions_Create())
    {
        if (Handle)
        {
            for (auto& Pair : Options.CreateRoomDataStore)
            {
                ovr_MatchmakingOptions_SetCreateRoomDataStoreString(Handle, TCHAR_TO_UTF8(*Pair.Key), TCHAR_TO_UTF8(*Pair.Value));
            }
            ovr_MatchmakingOptions_SetCreateRoomJoinPolicy(Handle, ConvertRoomJoinPolicy(Options.CreateRoomJoinPolicy));
            ovr_MatchmakingOptions_SetCreateRoomMaxUsers(Handle, static_cast<unsigned int>(Options.CreateRoomMaxUsers));
            for (size_t Index = 0, TotalIndices = Options.EnqueueAdditionalUsers.Num(); Index < TotalIndices; ++Index)
            {
                ovr_MatchmakingOptions_AddEnqueueAdditionalUser(Handle, static_cast<ovrID>(Options.EnqueueAdditionalUsers[Index]));
            }
            for (auto& Pair : Options.EnqueueDataSettings)
            {
                switch (Pair.Value.Type)
                {
                case EOvrKeyValuePairType::Int:
                    ovr_MatchmakingOptions_SetEnqueueDataSettingsInt(Handle, TCHAR_TO_UTF8(*Pair.Key), Pair.Value.IntValue);
                    break;
                case EOvrKeyValuePairType::Double:
                    ovr_MatchmakingOptions_SetEnqueueDataSettingsDouble(Handle, TCHAR_TO_UTF8(*Pair.Key), double(Pair.Value.FloatValue));
                    break;
                case EOvrKeyValuePairType::String:
                    ovr_MatchmakingOptions_SetEnqueueDataSettingsString(Handle, TCHAR_TO_UTF8(*Pair.Key), TCHAR_TO_UTF8(*Pair.Value.StringValue));
                    break;
                default:
                    break;
                }
            }
            ovr_MatchmakingOptions_SetEnqueueIsDebug(Handle, Options.EnqueueIsDebug);
            ovr_MatchmakingOptions_SetEnqueueQueryKey(Handle, TCHAR_TO_UTF8(*Options.EnqueueQueryKey));
        }
    }

    ~FOvrMatchmakingOptionsConverter()
    {
        ovr_MatchmakingOptions_Destroy(Handle);
    }

    operator ovrMatchmakingOptionsHandle() const
    {
        return Handle;
    }

    ovrMatchmakingOptionsHandle Handle;
};

struct OVRPLATFORM_API FOvrMultiplayerErrorOptionsConverter
{
    FOvrMultiplayerErrorOptionsConverter(const FOvrMultiplayerErrorOptions& Options):
        Handle(ovr_MultiplayerErrorOptions_Create())
    {
        if (Handle)
        {
            ovr_MultiplayerErrorOptions_SetErrorKey(Handle, ConvertMultiplayerErrorErrorKey(Options.ErrorKey));
        }
    }

    ~FOvrMultiplayerErrorOptionsConverter()
    {
        ovr_MultiplayerErrorOptions_Destroy(Handle);
    }

    operator ovrMultiplayerErrorOptionsHandle() const
    {
        return Handle;
    }

    ovrMultiplayerErrorOptionsHandle Handle;
};

struct OVRPLATFORM_API FOvrNetSyncOptionsConverter
{
    FOvrNetSyncOptionsConverter(const FOvrNetSyncOptions& Options):
        Handle(ovr_NetSyncOptions_Create())
    {
        if (Handle)
        {
            ovr_NetSyncOptions_SetVoipGroup(Handle, TCHAR_TO_UTF8(*Options.VoipGroup));
            ovr_NetSyncOptions_SetVoipStreamDefault(Handle, ConvertNetSyncVoipStreamMode(Options.VoipStreamDefault));
            ovr_NetSyncOptions_SetZoneId(Handle, TCHAR_TO_UTF8(*Options.ZoneId));
        }
    }

    ~FOvrNetSyncOptionsConverter()
    {
        ovr_NetSyncOptions_Destroy(Handle);
    }

    operator ovrNetSyncOptionsHandle() const
    {
        return Handle;
    }

    ovrNetSyncOptionsHandle Handle;
};

struct OVRPLATFORM_API FOvrRichPresenceOptionsConverter
{
    FOvrRichPresenceOptionsConverter(const FOvrRichPresenceOptions& Options):
        Handle(ovr_RichPresenceOptions_Create())
    {
        if (Handle)
        {
            ovr_RichPresenceOptions_SetApiName(Handle, TCHAR_TO_UTF8(*Options.ApiName));
            for (auto& Pair : Options.Args)
            {
                ovr_RichPresenceOptions_SetArgsString(Handle, TCHAR_TO_UTF8(*Pair.Key), TCHAR_TO_UTF8(*Pair.Value));
            }
            ovr_RichPresenceOptions_SetCurrentCapacity(Handle, static_cast<unsigned int>(Options.CurrentCapacity));
            ovr_RichPresenceOptions_SetDeeplinkMessageOverride(Handle, TCHAR_TO_UTF8(*Options.DeeplinkMessageOverride));
            ovr_RichPresenceOptions_SetEndTime(Handle, (unsigned long long) Options.EndTime.ToUnixTimestamp());
            ovr_RichPresenceOptions_SetExtraContext(Handle, ConvertRichPresenceExtraContext(Options.ExtraContext));
            ovr_RichPresenceOptions_SetInstanceId(Handle, TCHAR_TO_UTF8(*Options.InstanceId));
            ovr_RichPresenceOptions_SetIsIdle(Handle, Options.IsIdle);
            ovr_RichPresenceOptions_SetIsJoinable(Handle, Options.IsJoinable);
            ovr_RichPresenceOptions_SetJoinableId(Handle, TCHAR_TO_UTF8(*Options.JoinableId));
            ovr_RichPresenceOptions_SetLobbySessionId(Handle, TCHAR_TO_UTF8(*Options.LobbySessionId));
            ovr_RichPresenceOptions_SetMatchSessionId(Handle, TCHAR_TO_UTF8(*Options.MatchSessionId));
            ovr_RichPresenceOptions_SetMaxCapacity(Handle, static_cast<unsigned int>(Options.MaxCapacity));
            ovr_RichPresenceOptions_SetStartTime(Handle, (unsigned long long) Options.StartTime.ToUnixTimestamp());
        }
    }

    ~FOvrRichPresenceOptionsConverter()
    {
        ovr_RichPresenceOptions_Destroy(Handle);
    }

    operator ovrRichPresenceOptionsHandle() const
    {
        return Handle;
    }

    ovrRichPresenceOptionsHandle Handle;
};

struct OVRPLATFORM_API FOvrRoomOptionsConverter
{
    FOvrRoomOptionsConverter(const FOvrRoomOptions& Options):
        Handle(ovr_RoomOptions_Create())
    {
        if (Handle)
        {
            for (auto& Pair : Options.DataStore)
            {
                ovr_RoomOptions_SetDataStoreString(Handle, TCHAR_TO_UTF8(*Pair.Key), TCHAR_TO_UTF8(*Pair.Value));
            }
            ovr_RoomOptions_SetExcludeRecentlyMet(Handle, Options.ExcludeRecentlyMet);
            ovr_RoomOptions_SetMaxUserResults(Handle, static_cast<unsigned int>(Options.MaxUserResults));
            ovr_RoomOptions_SetOrdering(Handle, ConvertUserOrdering(Options.Ordering));
            ovr_RoomOptions_SetRecentlyMetTimeWindow(Handle, ConvertTimeWindow(Options.RecentlyMetTimeWindow));
            ovr_RoomOptions_SetRoomId(Handle, static_cast<ovrID>(Options.RoomId));
            ovr_RoomOptions_SetTurnOffUpdates(Handle, Options.TurnOffUpdates);
        }
    }

    ~FOvrRoomOptionsConverter()
    {
        ovr_RoomOptions_Destroy(Handle);
    }

    operator ovrRoomOptionsHandle() const
    {
        return Handle;
    }

    ovrRoomOptionsHandle Handle;
};

struct OVRPLATFORM_API FOvrRosterOptionsConverter
{
    FOvrRosterOptionsConverter(const FOvrRosterOptions& Options):
        Handle(ovr_RosterOptions_Create())
    {
        if (Handle)
        {
            for (size_t Index = 0, TotalIndices = Options.SuggestedUsers.Num(); Index < TotalIndices; ++Index)
            {
                ovr_RosterOptions_AddSuggestedUser(Handle, static_cast<ovrID>(Options.SuggestedUsers[Index]));
            }
        }
    }

    ~FOvrRosterOptionsConverter()
    {
        ovr_RosterOptions_Destroy(Handle);
    }

    operator ovrRosterOptionsHandle() const
    {
        return Handle;
    }

    ovrRosterOptionsHandle Handle;
};

struct OVRPLATFORM_API FOvrUserOptionsConverter
{
    FOvrUserOptionsConverter(const FOvrUserOptions& Options):
        Handle(ovr_UserOptions_Create())
    {
        if (Handle)
        {
            ovr_UserOptions_SetMaxUsers(Handle, static_cast<unsigned int>(Options.MaxUsers));
            for (size_t Index = 0, TotalIndices = Options.ServiceProviders.Num(); Index < TotalIndices; ++Index)
            {
                ovr_UserOptions_AddServiceProvider(Handle, ConvertServiceProvider(Options.ServiceProviders[Index]));
            }
            ovr_UserOptions_SetTimeWindow(Handle, ConvertTimeWindow(Options.TimeWindow));
        }
    }

    ~FOvrUserOptionsConverter()
    {
        ovr_UserOptions_Destroy(Handle);
    }

    operator ovrUserOptionsHandle() const
    {
        return Handle;
    }

    ovrUserOptionsHandle Handle;
};

struct OVRPLATFORM_API FOvrVoipOptionsConverter
{
    FOvrVoipOptionsConverter(const FOvrVoipOptions& Options):
        Handle(ovr_VoipOptions_Create())
    {
        if (Handle)
        {
            ovr_VoipOptions_SetBitrateForNewConnections(Handle, ConvertVoipBitrate(Options.BitrateForNewConnections));
            ovr_VoipOptions_SetCreateNewConnectionUseDtx(Handle, ConvertVoipDtxState(Options.CreateNewConnectionUseDtx));
        }
    }

    ~FOvrVoipOptionsConverter()
    {
        ovr_VoipOptions_Destroy(Handle);
    }

    operator ovrVoipOptionsHandle() const
    {
        return Handle;
    }

    ovrVoipOptionsHandle Handle;
};
