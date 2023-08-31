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

#include "OVRPlatformModels.h"
#include "OVRPlatformOptions.h"
#include "OVRPlatformRequestsSupport.h"

// ----------------------------------------------------------------------
// AbuseReport

/** The currently running application has indicated they want to show their in-app reporting flow or that they choose to ignore the request. */
DECLARE_DELEGATE_TwoParams(OvrPlatform_AbuseReport_ReportRequestHandled_Delegate, bool, FString);

void OvrPlatform_AbuseReport_ReportRequestHandled(
    UGameInstance* GameInstance,
    EOvrReportRequestResponse Response,
    OvrPlatform_AbuseReport_ReportRequestHandled_Delegate&& Delegate);

// ----------------------------------------------------------------------
// Achievements

/**
 * Add 'count' to the achievement with the given name. This must be a COUNT achievement.
 * The largest number that is supported by this method is the max value of a signed 64-bit integer.
 * If the number is larger than that, it is clamped to that max value before being passed to
 * the servers.
 */
typedef TSharedPtr<FOvrAchievementUpdate> FOvrAchievementUpdatePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Achievements_AddCount_Delegate, bool, FOvrAchievementUpdatePtr, FString);

void OvrPlatform_Achievements_AddCount(
    UGameInstance* GameInstance,
    FString Name,
    int64 Count,
    OvrPlatform_Achievements_AddCount_Delegate&& Delegate);

/**
 * Unlock fields of a BITFIELD achievement.
 * @param Name - The name of the achievement to unlock
 * @param Fields - A string containing either '0' or '1' characters. Every '1' will unlock the field in the corresponding position.
 */
typedef TSharedPtr<FOvrAchievementUpdate> FOvrAchievementUpdatePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Achievements_AddFields_Delegate, bool, FOvrAchievementUpdatePtr, FString);

void OvrPlatform_Achievements_AddFields(
    UGameInstance* GameInstance,
    FString Name,
    FString Fields,
    OvrPlatform_Achievements_AddFields_Delegate&& Delegate);

/** Request all achievement definitions for the app. */
typedef TSharedPtr<FOvrAchievementDefinitionPages> FOvrAchievementDefinitionArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Achievements_GetAllDefinitions_Delegate, bool, FOvrAchievementDefinitionArrayPtr, FString);

void OvrPlatform_Achievements_GetAllDefinitions(
    UGameInstance* GameInstance,
    OvrPlatform_Achievements_GetAllDefinitions_Delegate&& Delegate);

/** Request the progress for the user on all achievements in the app. */
typedef TSharedPtr<FOvrAchievementProgressPages> FOvrAchievementProgressArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Achievements_GetAllProgress_Delegate, bool, FOvrAchievementProgressArrayPtr, FString);

void OvrPlatform_Achievements_GetAllProgress(
    UGameInstance* GameInstance,
    OvrPlatform_Achievements_GetAllProgress_Delegate&& Delegate);

/** Request the achievement definitions that match the specified names. */
typedef TSharedPtr<FOvrAchievementDefinitionPages> FOvrAchievementDefinitionArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Achievements_GetDefinitionsByName_Delegate, bool, FOvrAchievementDefinitionArrayPtr, FString);

void OvrPlatform_Achievements_GetDefinitionsByName(
    UGameInstance* GameInstance,
    TArray<FString> Names,
    OvrPlatform_Achievements_GetDefinitionsByName_Delegate&& Delegate);

/** Request the user's progress on the specified achievements. */
typedef TSharedPtr<FOvrAchievementProgressPages> FOvrAchievementProgressArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Achievements_GetProgressByName_Delegate, bool, FOvrAchievementProgressArrayPtr, FString);

void OvrPlatform_Achievements_GetProgressByName(
    UGameInstance* GameInstance,
    TArray<FString> Names,
    OvrPlatform_Achievements_GetProgressByName_Delegate&& Delegate);

/** Unlock the achievement with the given name. This can be of any achievement type. */
typedef TSharedPtr<FOvrAchievementUpdate> FOvrAchievementUpdatePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Achievements_Unlock_Delegate, bool, FOvrAchievementUpdatePtr, FString);

void OvrPlatform_Achievements_Unlock(
    UGameInstance* GameInstance,
    FString Name,
    OvrPlatform_Achievements_Unlock_Delegate&& Delegate);

// ----------------------------------------------------------------------
// Application

/**
 * Cancel an app download that is in progress.
 * It will return a result when the download is cancelled.
 */
typedef TSharedPtr<FOvrAppDownloadResult> FOvrAppDownloadResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Application_CancelAppDownload_Delegate, bool, FOvrAppDownloadResultPtr, FString);

void OvrPlatform_Application_CancelAppDownload(
    UGameInstance* GameInstance,
    OvrPlatform_Application_CancelAppDownload_Delegate&& Delegate);

/** Track download progress for an app */
typedef TSharedPtr<FOvrAppDownloadProgressResult> FOvrAppDownloadProgressResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Application_CheckAppDownloadProgress_Delegate, bool, FOvrAppDownloadProgressResultPtr, FString);

void OvrPlatform_Application_CheckAppDownloadProgress(
    UGameInstance* GameInstance,
    OvrPlatform_Application_CheckAppDownloadProgress_Delegate&& Delegate);

/**
 * Requests version information, including the version code and version name of the currently installed app
 * and version code, version name, size and release date of the latest app update
 */
typedef TSharedPtr<FOvrApplicationVersion> FOvrApplicationVersionPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Application_GetVersion_Delegate, bool, FOvrApplicationVersionPtr, FString);

void OvrPlatform_Application_GetVersion(
    UGameInstance* GameInstance,
    OvrPlatform_Application_GetVersion_Delegate&& Delegate);

/**
 * Installs the app update that was previously downloaded.
 * Once the install begins the application will exit automatically.
 * After the installation process is complete, the app will be relaunched
 * based on the options passed.
 * @param DeeplinkOptions - Additional configuration for this relaunch. Optional.
 */
typedef TSharedPtr<FOvrAppDownloadResult> FOvrAppDownloadResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Application_InstallAppUpdateAndRelaunch_Delegate, bool, FOvrAppDownloadResultPtr, FString);

void OvrPlatform_Application_InstallAppUpdateAndRelaunch(
    UGameInstance* GameInstance,
    FOvrApplicationOptions DeeplinkOptions,
    OvrPlatform_Application_InstallAppUpdateAndRelaunch_Delegate&& Delegate);

/**
 * Launches a different application in the user's library. If the user
 * does not have that application installed, they will be taken to that app's
 * page in the Oculus Store
 * @param AppID - The ID of the app to launch
 * @param DeeplinkOptions - Additional configuration for this requests. Optional.
 */
typedef TSharedPtr<FString> FStringPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Application_LaunchOtherApp_Delegate, bool, FStringPtr, FString);

void OvrPlatform_Application_LaunchOtherApp(
    UGameInstance* GameInstance,
    FOvrId AppID,
    FOvrApplicationOptions DeeplinkOptions,
    OvrPlatform_Application_LaunchOtherApp_Delegate&& Delegate);

/**
 * Starts an app download.
 * It will return a result when the download is finished.
 * Download progress can be monitored using the check_app_download_progress API.
 */
typedef TSharedPtr<FOvrAppDownloadResult> FOvrAppDownloadResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Application_StartAppDownload_Delegate, bool, FOvrAppDownloadResultPtr, FString);

void OvrPlatform_Application_StartAppDownload(
    UGameInstance* GameInstance,
    OvrPlatform_Application_StartAppDownload_Delegate&& Delegate);

// ----------------------------------------------------------------------
// ApplicationLifecycle

// ----------------------------------------------------------------------
// AssetFile

/** DEPRECATED. Use AssetFile_DeleteById() */
typedef TSharedPtr<FOvrAssetFileDeleteResult> FOvrAssetFileDeleteResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_AssetFile_Delete_Delegate, bool, FOvrAssetFileDeleteResultPtr, FString);

[[deprecated("Use AssetFile_DeleteById()")]]
void OvrPlatform_AssetFile_Delete(
    UGameInstance* GameInstance,
    FOvrId AssetFileID,
    OvrPlatform_AssetFile_Delete_Delegate&& Delegate);

/**
 * Removes an previously installed asset file from the device by its ID.
 * Returns an object containing the asset ID and file name, and a success flag.
 * @param AssetFileID - The asset file ID
 */
typedef TSharedPtr<FOvrAssetFileDeleteResult> FOvrAssetFileDeleteResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_AssetFile_DeleteById_Delegate, bool, FOvrAssetFileDeleteResultPtr, FString);

void OvrPlatform_AssetFile_DeleteById(
    UGameInstance* GameInstance,
    FOvrId AssetFileID,
    OvrPlatform_AssetFile_DeleteById_Delegate&& Delegate);

/**
 * Removes an previously installed asset file from the device by its name.
 * Returns an object containing the asset ID and file name, and a success flag.
 * @param AssetFileName - The asset file name
 */
typedef TSharedPtr<FOvrAssetFileDeleteResult> FOvrAssetFileDeleteResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_AssetFile_DeleteByName_Delegate, bool, FOvrAssetFileDeleteResultPtr, FString);

void OvrPlatform_AssetFile_DeleteByName(
    UGameInstance* GameInstance,
    FString AssetFileName,
    OvrPlatform_AssetFile_DeleteByName_Delegate&& Delegate);

/** DEPRECATED. Use AssetFile_DownloadById() */
typedef TSharedPtr<FOvrAssetFileDownloadResult> FOvrAssetFileDownloadResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_AssetFile_Download_Delegate, bool, FOvrAssetFileDownloadResultPtr, FString);

[[deprecated("Use AssetFile_DownloadById()")]]
void OvrPlatform_AssetFile_Download(
    UGameInstance* GameInstance,
    FOvrId AssetFileID,
    OvrPlatform_AssetFile_Download_Delegate&& Delegate);

/**
 * Downloads an asset file by its ID on demand. Returns an object containing
 * the asset ID and filepath. Sends periodic
 * FOvrNotification_AssetFile_DownloadUpdate to track the downloads.
 * @param AssetFileID - The asset file ID
 */
typedef TSharedPtr<FOvrAssetFileDownloadResult> FOvrAssetFileDownloadResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_AssetFile_DownloadById_Delegate, bool, FOvrAssetFileDownloadResultPtr, FString);

void OvrPlatform_AssetFile_DownloadById(
    UGameInstance* GameInstance,
    FOvrId AssetFileID,
    OvrPlatform_AssetFile_DownloadById_Delegate&& Delegate);

/**
 * Downloads an asset file by its name on demand. Returns an object containing
 * the asset ID and filepath. Sends periodic
 * {notifications.asset_file.download_update}} to track the downloads.
 * @param AssetFileName - The asset file name
 */
typedef TSharedPtr<FOvrAssetFileDownloadResult> FOvrAssetFileDownloadResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_AssetFile_DownloadByName_Delegate, bool, FOvrAssetFileDownloadResultPtr, FString);

void OvrPlatform_AssetFile_DownloadByName(
    UGameInstance* GameInstance,
    FString AssetFileName,
    OvrPlatform_AssetFile_DownloadByName_Delegate&& Delegate);

/** DEPRECATED. Use AssetFile_DownloadCancelById() */
typedef TSharedPtr<FOvrAssetFileDownloadCancelResult> FOvrAssetFileDownloadCancelResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_AssetFile_DownloadCancel_Delegate, bool, FOvrAssetFileDownloadCancelResultPtr, FString);

[[deprecated("Use AssetFile_DownloadCancelById()")]]
void OvrPlatform_AssetFile_DownloadCancel(
    UGameInstance* GameInstance,
    FOvrId AssetFileID,
    OvrPlatform_AssetFile_DownloadCancel_Delegate&& Delegate);

/**
 * Cancels a previously spawned download request for an asset file by its ID.
 * Returns an object containing the asset ID and file path, and a success flag.
 * @param AssetFileID - The asset file ID
 */
typedef TSharedPtr<FOvrAssetFileDownloadCancelResult> FOvrAssetFileDownloadCancelResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_AssetFile_DownloadCancelById_Delegate, bool, FOvrAssetFileDownloadCancelResultPtr, FString);

void OvrPlatform_AssetFile_DownloadCancelById(
    UGameInstance* GameInstance,
    FOvrId AssetFileID,
    OvrPlatform_AssetFile_DownloadCancelById_Delegate&& Delegate);

/**
 * Cancels a previously spawned download request for an asset file by its name.
 * Returns an object containing the asset ID and file path, and a success flag.
 * @param AssetFileName - The asset file name
 */
typedef TSharedPtr<FOvrAssetFileDownloadCancelResult> FOvrAssetFileDownloadCancelResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_AssetFile_DownloadCancelByName_Delegate, bool, FOvrAssetFileDownloadCancelResultPtr, FString);

void OvrPlatform_AssetFile_DownloadCancelByName(
    UGameInstance* GameInstance,
    FString AssetFileName,
    OvrPlatform_AssetFile_DownloadCancelByName_Delegate&& Delegate);

/**
 * Returns an array of objects with asset file names and their associated IDs,
 * and and whether it's currently installed.
 */
typedef TSharedPtr<TArray<FOvrAssetDetails>> FOvrAssetDetailsArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_AssetFile_GetList_Delegate, bool, FOvrAssetDetailsArrayPtr, FString);

void OvrPlatform_AssetFile_GetList(
    UGameInstance* GameInstance,
    OvrPlatform_AssetFile_GetList_Delegate&& Delegate);

/** DEPRECATED. Use AssetFile_StatusById() */
typedef TSharedPtr<FOvrAssetDetails> FOvrAssetDetailsPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_AssetFile_Status_Delegate, bool, FOvrAssetDetailsPtr, FString);

[[deprecated("Use AssetFile_StatusById()")]]
void OvrPlatform_AssetFile_Status(
    UGameInstance* GameInstance,
    FOvrId AssetFileID,
    OvrPlatform_AssetFile_Status_Delegate&& Delegate);

/**
 * Returns the details on a single asset: ID, file name, and whether it's currently installed
 * @param AssetFileID - The asset file ID
 */
typedef TSharedPtr<FOvrAssetDetails> FOvrAssetDetailsPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_AssetFile_StatusById_Delegate, bool, FOvrAssetDetailsPtr, FString);

void OvrPlatform_AssetFile_StatusById(
    UGameInstance* GameInstance,
    FOvrId AssetFileID,
    OvrPlatform_AssetFile_StatusById_Delegate&& Delegate);

/**
 * Returns the details on a single asset: ID, file name, and whether it's currently installed
 * @param AssetFileName - The asset file name
 */
typedef TSharedPtr<FOvrAssetDetails> FOvrAssetDetailsPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_AssetFile_StatusByName_Delegate, bool, FOvrAssetDetailsPtr, FString);

void OvrPlatform_AssetFile_StatusByName(
    UGameInstance* GameInstance,
    FString AssetFileName,
    OvrPlatform_AssetFile_StatusByName_Delegate&& Delegate);

// ----------------------------------------------------------------------
// Avatar

/** Launches the Avatar Editor */
typedef TSharedPtr<FOvrAvatarEditorResult> FOvrAvatarEditorResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Avatar_LaunchAvatarEditor_Delegate, bool, FOvrAvatarEditorResultPtr, FString);

void OvrPlatform_Avatar_LaunchAvatarEditor(
    UGameInstance* GameInstance,
    FOvrAvatarEditorOptions Options,
    OvrPlatform_Avatar_LaunchAvatarEditor_Delegate&& Delegate);

// ----------------------------------------------------------------------
// Challenges

/** DEPRECATED. Use server-to-server API call instead. */
typedef TSharedPtr<FOvrChallenge> FOvrChallengePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Challenges_Create_Delegate, bool, FOvrChallengePtr, FString);

[[deprecated("Use server-to-server API call instead.")]]
void OvrPlatform_Challenges_Create(
    UGameInstance* GameInstance,
    FString LeaderboardName,
    FOvrChallengeOptions ChallengeOptions,
    OvrPlatform_Challenges_Create_Delegate&& Delegate);

/** If the current user has an invite to the challenge, decline the invite */
typedef TSharedPtr<FOvrChallenge> FOvrChallengePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Challenges_DeclineInvite_Delegate, bool, FOvrChallengePtr, FString);

void OvrPlatform_Challenges_DeclineInvite(
    UGameInstance* GameInstance,
    FOvrId ChallengeID,
    OvrPlatform_Challenges_DeclineInvite_Delegate&& Delegate);

/** DEPRECATED. Use server-to-server API call instead. */
DECLARE_DELEGATE_TwoParams(OvrPlatform_Challenges_Delete_Delegate, bool, FString);

[[deprecated("Use server-to-server API call instead.")]]
void OvrPlatform_Challenges_Delete(
    UGameInstance* GameInstance,
    FOvrId ChallengeID,
    OvrPlatform_Challenges_Delete_Delegate&& Delegate);

/**
 * Gets the information for a single challenge
 * @param ChallengeID - The id of the challenge whose entries to return.
 */
typedef TSharedPtr<FOvrChallenge> FOvrChallengePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Challenges_Get_Delegate, bool, FOvrChallengePtr, FString);

void OvrPlatform_Challenges_Get(
    UGameInstance* GameInstance,
    FOvrId ChallengeID,
    OvrPlatform_Challenges_Get_Delegate&& Delegate);

/**
 * Requests a block of challenge entries.
 * @param ChallengeID - The id of the challenge whose entries to return.
 * @param Limit - Defines the maximum number of entries to return.
 * @param Filter - By using ovrLeaderboard_FilterFriends, this allows you to filter the returned values to bidirectional followers.
 * @param StartAt - Defines whether to center the query on the user or start at the top of the challenge.
 */
typedef TSharedPtr<FOvrChallengeEntryPages> FOvrChallengeEntryArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Challenges_GetEntries_Delegate, bool, FOvrChallengeEntryArrayPtr, FString);

void OvrPlatform_Challenges_GetEntries(
    UGameInstance* GameInstance,
    FOvrId ChallengeID,
    int32 Limit,
    EOvrLeaderboardFilterType Filter,
    EOvrLeaderboardStartAt StartAt,
    OvrPlatform_Challenges_GetEntries_Delegate&& Delegate);

/**
 * Requests a block of challenge entries.
 * @param ChallengeID - The id of the challenge whose entries to return.
 * @param Limit - The maximum number of entries to return.
 * @param AfterRank - The position after which to start.  For example, 10 returns challenge results starting with the 11th user.
 */
typedef TSharedPtr<FOvrChallengeEntryPages> FOvrChallengeEntryArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Challenges_GetEntriesAfterRank_Delegate, bool, FOvrChallengeEntryArrayPtr, FString);

void OvrPlatform_Challenges_GetEntriesAfterRank(
    UGameInstance* GameInstance,
    FOvrId ChallengeID,
    int32 Limit,
    int64 AfterRank,
    OvrPlatform_Challenges_GetEntriesAfterRank_Delegate&& Delegate);

/**
 * Requests a block of challenge entries. Will return only entries matching the user IDs passed in.
 * @param ChallengeID - The id of the challenge whose entries to return.
 * @param Limit - Defines the maximum number of entries to return.
 * @param StartAt - Defines whether to center the query on the user or start at the top of the challenge. If this is EOvrLeaderboardStartAt::CenteredOnViewer or EOvrLeaderboardStartAt::CenteredOnViewerOrTop, then the current user's ID will be automatically added to the query.
 * @param UserIDs - Defines a list of user ids to get entries for.
 * @param UserIDLength - The number of user IDs provided.
 */
typedef TSharedPtr<FOvrChallengeEntryPages> FOvrChallengeEntryArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Challenges_GetEntriesByIds_Delegate, bool, FOvrChallengeEntryArrayPtr, FString);

void OvrPlatform_Challenges_GetEntriesByIds(
    UGameInstance* GameInstance,
    FOvrId ChallengeID,
    int32 Limit,
    EOvrLeaderboardStartAt StartAt,
    TArray<FOvrId> UserIDs,
    OvrPlatform_Challenges_GetEntriesByIds_Delegate&& Delegate);

/** Requests for a list of challenge */
typedef TSharedPtr<FOvrChallengePages> FOvrChallengeArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Challenges_GetList_Delegate, bool, FOvrChallengeArrayPtr, FString);

void OvrPlatform_Challenges_GetList(
    UGameInstance* GameInstance,
    FOvrChallengeOptions ChallengeOptions,
    int32 Limit,
    OvrPlatform_Challenges_GetList_Delegate&& Delegate);

/** If the current user has permission, join the challenge */
typedef TSharedPtr<FOvrChallenge> FOvrChallengePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Challenges_Join_Delegate, bool, FOvrChallengePtr, FString);

void OvrPlatform_Challenges_Join(
    UGameInstance* GameInstance,
    FOvrId ChallengeID,
    OvrPlatform_Challenges_Join_Delegate&& Delegate);

/** If the current user has permission, leave the challenge */
typedef TSharedPtr<FOvrChallenge> FOvrChallengePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Challenges_Leave_Delegate, bool, FOvrChallengePtr, FString);

void OvrPlatform_Challenges_Leave(
    UGameInstance* GameInstance,
    FOvrId ChallengeID,
    OvrPlatform_Challenges_Leave_Delegate&& Delegate);

/** DEPRECATED. Use server-to-server API call instead. */
typedef TSharedPtr<FOvrChallenge> FOvrChallengePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Challenges_UpdateInfo_Delegate, bool, FOvrChallengePtr, FString);

[[deprecated("Use server-to-server API call instead.")]]
void OvrPlatform_Challenges_UpdateInfo(
    UGameInstance* GameInstance,
    FOvrId ChallengeID,
    FOvrChallengeOptions ChallengeOptions,
    OvrPlatform_Challenges_UpdateInfo_Delegate&& Delegate);

// ----------------------------------------------------------------------
// DeviceApplicationIntegrity

/**
 * Returns Device and Application Integrity Attestation JSON Web Token.
 * The token has format of header.claims.signature encoded in base64.
 * Header contains algorithm type (PS256) and token type (JWT).
 */
typedef TSharedPtr<FString> FStringPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_DeviceApplicationIntegrity_GetIntegrityToken_Delegate, bool, FStringPtr, FString);

void OvrPlatform_DeviceApplicationIntegrity_GetIntegrityToken(
    UGameInstance* GameInstance,
    FString ChallengeNonce,
    OvrPlatform_DeviceApplicationIntegrity_GetIntegrityToken_Delegate&& Delegate);

// ----------------------------------------------------------------------
// Entitlement

/** Returns whether the current user is entitled to the current app. */
DECLARE_DELEGATE_TwoParams(OvrPlatform_Entitlement_GetIsViewerEntitled_Delegate, bool, FString);

void OvrPlatform_Entitlement_GetIsViewerEntitled(
    UGameInstance* GameInstance,
    OvrPlatform_Entitlement_GetIsViewerEntitled_Delegate&& Delegate);

// ----------------------------------------------------------------------
// GroupPresence

/** Clear group presence for running app */
DECLARE_DELEGATE_TwoParams(OvrPlatform_GroupPresence_Clear_Delegate, bool, FString);

void OvrPlatform_GroupPresence_Clear(
    UGameInstance* GameInstance,
    OvrPlatform_GroupPresence_Clear_Delegate&& Delegate);

/** Returns a list of users that can be invited to your current lobby. These are pulled from your bidirectional followers and recently met lists. */
typedef TSharedPtr<FOvrUserPages> FOvrUserArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_GroupPresence_GetInvitableUsers_Delegate, bool, FOvrUserArrayPtr, FString);

void OvrPlatform_GroupPresence_GetInvitableUsers(
    UGameInstance* GameInstance,
    FOvrInviteOptions Options,
    OvrPlatform_GroupPresence_GetInvitableUsers_Delegate&& Delegate);

/** Get the application invites which have been sent by the user. */
typedef TSharedPtr<FOvrApplicationInvitePages> FOvrApplicationInviteArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_GroupPresence_GetSentInvites_Delegate, bool, FOvrApplicationInviteArrayPtr, FString);

void OvrPlatform_GroupPresence_GetSentInvites(
    UGameInstance* GameInstance,
    OvrPlatform_GroupPresence_GetSentInvites_Delegate&& Delegate);

/**
 * Launch the flow to allow the user to invite others to their current session.
 * This can only be used if the user is in a joinable session.
 */
typedef TSharedPtr<FOvrInvitePanelResultInfo> FOvrInvitePanelResultInfoPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_GroupPresence_LaunchInvitePanel_Delegate, bool, FOvrInvitePanelResultInfoPtr, FString);

void OvrPlatform_GroupPresence_LaunchInvitePanel(
    UGameInstance* GameInstance,
    FOvrInviteOptions Options,
    OvrPlatform_GroupPresence_LaunchInvitePanel_Delegate&& Delegate);

/** Launch an error dialog with predefined messages for common multiplayer errors. */
DECLARE_DELEGATE_TwoParams(OvrPlatform_GroupPresence_LaunchMultiplayerErrorDialog_Delegate, bool, FString);

void OvrPlatform_GroupPresence_LaunchMultiplayerErrorDialog(
    UGameInstance* GameInstance,
    FOvrMultiplayerErrorOptions Options,
    OvrPlatform_GroupPresence_LaunchMultiplayerErrorDialog_Delegate&& Delegate);

/**
 * Launch the dialog which will allow the user to rejoin a previous lobby/match. Either the lobby_session_id
 * or the match_session_id, or both, must be populated.
 */
typedef TSharedPtr<FOvrRejoinDialogResult> FOvrRejoinDialogResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_GroupPresence_LaunchRejoinDialog_Delegate, bool, FOvrRejoinDialogResultPtr, FString);

void OvrPlatform_GroupPresence_LaunchRejoinDialog(
    UGameInstance* GameInstance,
    FString LobbySessionId,
    FString MatchSessionId,
    FString DestinationApiName,
    OvrPlatform_GroupPresence_LaunchRejoinDialog_Delegate&& Delegate);

/**
 * Launch the panel which displays the current users in the roster. Users with the same lobby and match session
 * id as part of their presence will show up here.
 */
DECLARE_DELEGATE_TwoParams(OvrPlatform_GroupPresence_LaunchRosterPanel_Delegate, bool, FString);

void OvrPlatform_GroupPresence_LaunchRosterPanel(
    UGameInstance* GameInstance,
    FOvrRosterOptions Options,
    OvrPlatform_GroupPresence_LaunchRosterPanel_Delegate&& Delegate);

/** Send application invites to the passed in userIDs. */
typedef TSharedPtr<FOvrSendInvitesResult> FOvrSendInvitesResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_GroupPresence_SendInvites_Delegate, bool, FOvrSendInvitesResultPtr, FString);

void OvrPlatform_GroupPresence_SendInvites(
    UGameInstance* GameInstance,
    TArray<FOvrId> UserIDs,
    OvrPlatform_GroupPresence_SendInvites_Delegate&& Delegate);

/** Set group presence for running app */
DECLARE_DELEGATE_TwoParams(OvrPlatform_GroupPresence_Set_Delegate, bool, FString);

void OvrPlatform_GroupPresence_Set(
    UGameInstance* GameInstance,
    FOvrGroupPresenceOptions GroupPresenceOptions,
    OvrPlatform_GroupPresence_Set_Delegate&& Delegate);

/**
 * Set the user's deeplink message while keeping the other group presence parameters the same. If the destination of the user is not set,
 * the deeplink message cannot be set as there's no deeplink message to override.
 */
DECLARE_DELEGATE_TwoParams(OvrPlatform_GroupPresence_SetDeeplinkMessageOverride_Delegate, bool, FString);

void OvrPlatform_GroupPresence_SetDeeplinkMessageOverride(
    UGameInstance* GameInstance,
    FString DeeplinkMessage,
    OvrPlatform_GroupPresence_SetDeeplinkMessageOverride_Delegate&& Delegate);

/** Replaces the user's current destination for the provided one. All other existing group presence parameters will remain the same. */
DECLARE_DELEGATE_TwoParams(OvrPlatform_GroupPresence_SetDestination_Delegate, bool, FString);

void OvrPlatform_GroupPresence_SetDestination(
    UGameInstance* GameInstance,
    FString ApiName,
    OvrPlatform_GroupPresence_SetDestination_Delegate&& Delegate);

/**
 * Set if the current user's destination and session is joinable while keeping the other group presence
 * parameters the same. If the destination or session ids of the user is not set, they cannot be set to joinable.
 */
DECLARE_DELEGATE_TwoParams(OvrPlatform_GroupPresence_SetIsJoinable_Delegate, bool, FString);

void OvrPlatform_GroupPresence_SetIsJoinable(
    UGameInstance* GameInstance,
    bool IsJoinable,
    OvrPlatform_GroupPresence_SetIsJoinable_Delegate&& Delegate);

/** Replaces the user's current lobby session id for the provided one. All other existing group presence parameters will remain the same. */
DECLARE_DELEGATE_TwoParams(OvrPlatform_GroupPresence_SetLobbySession_Delegate, bool, FString);

void OvrPlatform_GroupPresence_SetLobbySession(
    UGameInstance* GameInstance,
    FString Id,
    OvrPlatform_GroupPresence_SetLobbySession_Delegate&& Delegate);

/** Replaces the user's current match session id for the provided one. All other existing group presence parameters will remain the same. */
DECLARE_DELEGATE_TwoParams(OvrPlatform_GroupPresence_SetMatchSession_Delegate, bool, FString);

void OvrPlatform_GroupPresence_SetMatchSession(
    UGameInstance* GameInstance,
    FString Id,
    OvrPlatform_GroupPresence_SetMatchSession_Delegate&& Delegate);

// ----------------------------------------------------------------------
// IAP

/**
 * Allow the consumable IAP product to be purchased again. Conceptually, this
 * indicates that the item was used or consumed.
 */
DECLARE_DELEGATE_TwoParams(OvrPlatform_IAP_ConsumePurchase_Delegate, bool, FString);

void OvrPlatform_IAP_ConsumePurchase(
    UGameInstance* GameInstance,
    FString Sku,
    OvrPlatform_IAP_ConsumePurchase_Delegate&& Delegate);

/**
 * Retrieve a list of IAP products that can be purchased.
 * @param Skus - The SKUs of the products to retrieve.
 * @param Count - Number of items you provided in the SKUs.
 */
typedef TSharedPtr<FOvrProductPages> FOvrProductArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_IAP_GetProductsBySKU_Delegate, bool, FOvrProductArrayPtr, FString);

void OvrPlatform_IAP_GetProductsBySKU(
    UGameInstance* GameInstance,
    TArray<FString> Skus,
    OvrPlatform_IAP_GetProductsBySKU_Delegate&& Delegate);

/**
 * Retrieve a list of Purchase that the Logged-In-User has made. This list will
 * also contain consumable purchases that have not been consumed.
 */
typedef TSharedPtr<FOvrPurchasePages> FOvrPurchaseArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_IAP_GetViewerPurchases_Delegate, bool, FOvrPurchaseArrayPtr, FString);

void OvrPlatform_IAP_GetViewerPurchases(
    UGameInstance* GameInstance,
    OvrPlatform_IAP_GetViewerPurchases_Delegate&& Delegate);

/**
 * Retrieve a list of Purchase that the Logged-In-User has made. This list will only contain
 * durable purchase (non-consumable) and is populated from a device cache. It is recommended in
 * all cases to use ovr_User_GetViewerPurchases first and only check the cache if that fails.
 */
typedef TSharedPtr<FOvrPurchasePages> FOvrPurchaseArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_IAP_GetViewerPurchasesDurableCache_Delegate, bool, FOvrPurchaseArrayPtr, FString);

void OvrPlatform_IAP_GetViewerPurchasesDurableCache(
    UGameInstance* GameInstance,
    OvrPlatform_IAP_GetViewerPurchasesDurableCache_Delegate&& Delegate);

/**
 * Launch the checkout flow to purchase the existing product. Oculus Home tries
 * handle and fix as many errors as possible. Home returns the appropriate error
 * message and how to resolveit, if possible. Returns a purchase on success, empty
 * purchase on cancel, and an error on error.
 * @param Sku - IAP sku for the item the user wishes to purchase.
 */
typedef TSharedPtr<FOvrPurchase> FOvrPurchasePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_IAP_LaunchCheckoutFlow_Delegate, bool, FOvrPurchasePtr, FString);

void OvrPlatform_IAP_LaunchCheckoutFlow(
    UGameInstance* GameInstance,
    FString Sku,
    OvrPlatform_IAP_LaunchCheckoutFlow_Delegate&& Delegate);

// ----------------------------------------------------------------------
// LanguagePack

/**
 * Returns currently installed and selected language pack for an app in the
 * view of the `asset_details`. Use `language` field to extract neeeded
 * language info.
 * A particular language can be download and installed by a user from
 * the Oculus app on the application page.
 */
typedef TSharedPtr<FOvrAssetDetails> FOvrAssetDetailsPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_LanguagePack_GetCurrent_Delegate, bool, FOvrAssetDetailsPtr, FString);

void OvrPlatform_LanguagePack_GetCurrent(
    UGameInstance* GameInstance,
    OvrPlatform_LanguagePack_GetCurrent_Delegate&& Delegate);

/**
 * Sets the current language to specified. The parameter is the BCP47 language tag.
 * If a language pack is not downloaded yet, spawns automatically the
 * AssetFile_DownloadByName() request, and sends periodic
 * FOvrNotification_AssetFile_DownloadUpdate to track the downloads.
 * Once the language asset file is downloaded, call LanguagePack_GetCurrent()
 * to retrive the data, and use the language at runtime.
 * @param Tag - BCP47 language tag
 */
typedef TSharedPtr<FOvrAssetFileDownloadResult> FOvrAssetFileDownloadResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_LanguagePack_SetCurrent_Delegate, bool, FOvrAssetFileDownloadResultPtr, FString);

void OvrPlatform_LanguagePack_SetCurrent(
    UGameInstance* GameInstance,
    FString Tag,
    OvrPlatform_LanguagePack_SetCurrent_Delegate&& Delegate);

// ----------------------------------------------------------------------
// Leaderboard

/**
 * Gets the information for a single leaderboard
 * @param LeaderboardName - The name of the leaderboard to return.
 */
typedef TSharedPtr<FOvrLeaderboardPages> FOvrLeaderboardArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Leaderboard_Get_Delegate, bool, FOvrLeaderboardArrayPtr, FString);

void OvrPlatform_Leaderboard_Get(
    UGameInstance* GameInstance,
    FString LeaderboardName,
    OvrPlatform_Leaderboard_Get_Delegate&& Delegate);

/**
 * Requests a block of leaderboard entries.
 * @param LeaderboardName - The name of the leaderboard whose entries to return.
 * @param Limit - Defines the maximum number of entries to return.
 * @param Filter - By using ovrLeaderboard_FilterFriends, this allows you to filter the returned values to bidirectional followers.
 * @param StartAt - Defines whether to center the query on the user or start at the top of the leaderboard.
 */
typedef TSharedPtr<FOvrLeaderboardEntryPages> FOvrLeaderboardEntryArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Leaderboard_GetEntries_Delegate, bool, FOvrLeaderboardEntryArrayPtr, FString);

void OvrPlatform_Leaderboard_GetEntries(
    UGameInstance* GameInstance,
    FString LeaderboardName,
    int32 Limit,
    EOvrLeaderboardFilterType Filter,
    EOvrLeaderboardStartAt StartAt,
    OvrPlatform_Leaderboard_GetEntries_Delegate&& Delegate);

/**
 * Requests a block of leaderboard entries.
 * @param LeaderboardName - The name of the leaderboard.
 * @param Limit - The maximum number of entries to return.
 * @param AfterRank - The position after which to start.  For example, 10 returns leaderboard results starting with the 11th user.
 */
typedef TSharedPtr<FOvrLeaderboardEntryPages> FOvrLeaderboardEntryArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Leaderboard_GetEntriesAfterRank_Delegate, bool, FOvrLeaderboardEntryArrayPtr, FString);

void OvrPlatform_Leaderboard_GetEntriesAfterRank(
    UGameInstance* GameInstance,
    FString LeaderboardName,
    int32 Limit,
    int64 AfterRank,
    OvrPlatform_Leaderboard_GetEntriesAfterRank_Delegate&& Delegate);

/**
 * Requests a block of leaderboard entries. Will return only entries matching the user IDs passed in.
 * @param LeaderboardName - The name of the leaderboard whose entries to return.
 * @param Limit - Defines the maximum number of entries to return.
 * @param StartAt - Defines whether to center the query on the user or start at the top of the leaderboard. If this is EOvrLeaderboardStartAt::CenteredOnViewer or EOvrLeaderboardStartAt::CenteredOnViewerOrTop, then the current user's ID will be automatically added to the query.
 * @param UserIDs - Defines a list of user ids to get entries for.
 * @param UserIDLength - The number of user IDs provided.
 */
typedef TSharedPtr<FOvrLeaderboardEntryPages> FOvrLeaderboardEntryArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Leaderboard_GetEntriesByIds_Delegate, bool, FOvrLeaderboardEntryArrayPtr, FString);

void OvrPlatform_Leaderboard_GetEntriesByIds(
    UGameInstance* GameInstance,
    FString LeaderboardName,
    int32 Limit,
    EOvrLeaderboardStartAt StartAt,
    TArray<FOvrId> UserIDs,
    OvrPlatform_Leaderboard_GetEntriesByIds_Delegate&& Delegate);

/**
 * Writes a single entry to a leaderboard.
 * @param LeaderboardName - The leaderboard for which to write the entry.
 * @param Score - The score to write.
 * @param ExtraData - A 2KB custom data field that is associated with the leaderboard entry. This can be a game replay or anything that provides more detail about the entry to the viewer.
 * @param ExtraDataLength - The length of the extra data.
 * @param ForceUpdate - If true, the score always updates.  This happens even if it is not the user's best score.
 */
typedef TSharedPtr<FOvrLeaderboardUpdateStatus> FOvrLeaderboardUpdateStatusPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Leaderboard_WriteEntry_Delegate, bool, FOvrLeaderboardUpdateStatusPtr, FString);

void OvrPlatform_Leaderboard_WriteEntry(
    UGameInstance* GameInstance,
    FString LeaderboardName,
    int64 Score,
    TArray<uint8> ExtraData,
    bool ForceUpdate,
    OvrPlatform_Leaderboard_WriteEntry_Delegate&& Delegate);

/**
 * Writes a single entry to a leaderboard, can include supplementary metrics
 * @param LeaderboardName - The leaderboard for which to write the entry.
 * @param Score - The score to write.
 * @param SupplementaryMetric - A metric that can be used for tiebreakers.
 * @param ExtraData - A 2KB custom data field that is associated with the leaderboard entry. This can be a game replay or anything that provides more detail about the entry to the viewer.
 * @param ExtraDataLength - The length of the extra data.
 * @param ForceUpdate - If true, the score always updates. This happens ecen if it is not the user's best score.
 */
typedef TSharedPtr<FOvrLeaderboardUpdateStatus> FOvrLeaderboardUpdateStatusPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Leaderboard_WriteEntryWithSupplementaryMetric_Delegate, bool, FOvrLeaderboardUpdateStatusPtr, FString);

void OvrPlatform_Leaderboard_WriteEntryWithSupplementaryMetric(
    UGameInstance* GameInstance,
    FString LeaderboardName,
    int64 Score,
    int64 SupplementaryMetric,
    TArray<uint8> ExtraData,
    bool ForceUpdate,
    OvrPlatform_Leaderboard_WriteEntryWithSupplementaryMetric_Delegate&& Delegate);

// ----------------------------------------------------------------------
// Media

/**
 *  Launch the Share to Facebook modal via a deeplink to Home on Gear VR, allowing users to share local media files to Facebook.
 * Accepts a postTextSuggestion string for the default text of the Facebook post.
 * Requires a filePath string as the path to the image to be shared to Facebook. This image should be located in your app's internal storage directory.
 * Requires a contentType indicating the type of media to be shared (only 'photo' is currently supported.) 
 * @param PostTextSuggestion - this text will prepopulate the facebook status text-input box within the share modal
 * @param FilePath - path to the file to be shared to facebook
 * @param ContentType - content type of the media to be shared
 */
typedef TSharedPtr<FOvrShareMediaResult> FOvrShareMediaResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Media_ShareToFacebook_Delegate, bool, FOvrShareMediaResultPtr, FString);

void OvrPlatform_Media_ShareToFacebook(
    UGameInstance* GameInstance,
    FString PostTextSuggestion,
    FString FilePath,
    EOvrMediaContentType ContentType,
    OvrPlatform_Media_ShareToFacebook_Delegate&& Delegate);

// ----------------------------------------------------------------------
// Notification

/**
 * Mark a notification as read. This causes it to disappear from the
 * Universal Menu, the Oculus App, Oculus Home, and in-app retrieval.
 */
DECLARE_DELEGATE_TwoParams(OvrPlatform_Notification_MarkAsRead_Delegate, bool, FString);

void OvrPlatform_Notification_MarkAsRead(
    UGameInstance* GameInstance,
    FOvrId NotificationID,
    OvrPlatform_Notification_MarkAsRead_Delegate&& Delegate);

// ----------------------------------------------------------------------
// Party

/** Load the party the current user is in. */
typedef TSharedPtr<FOvrParty> FOvrPartyPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Party_GetCurrent_Delegate, bool, FOvrPartyPtr, FString);

void OvrPlatform_Party_GetCurrent(
    UGameInstance* GameInstance,
    OvrPlatform_Party_GetCurrent_Delegate&& Delegate);

// ----------------------------------------------------------------------
// RichPresence

/** DEPRECATED. Use the clear method in group presence */
DECLARE_DELEGATE_TwoParams(OvrPlatform_RichPresence_Clear_Delegate, bool, FString);

[[deprecated("Use the clear method in group presence")]]
void OvrPlatform_RichPresence_Clear(
    UGameInstance* GameInstance,
    OvrPlatform_RichPresence_Clear_Delegate&& Delegate);

/** Gets all the destinations that the presence can be set to */
typedef TSharedPtr<FOvrDestinationPages> FOvrDestinationArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_RichPresence_GetDestinations_Delegate, bool, FOvrDestinationArrayPtr, FString);

void OvrPlatform_RichPresence_GetDestinations(
    UGameInstance* GameInstance,
    OvrPlatform_RichPresence_GetDestinations_Delegate&& Delegate);

/** DEPRECATED. Use GroupPresence_Set(). */
DECLARE_DELEGATE_TwoParams(OvrPlatform_RichPresence_Set_Delegate, bool, FString);

[[deprecated("Use GroupPresence_Set().")]]
void OvrPlatform_RichPresence_Set(
    UGameInstance* GameInstance,
    FOvrRichPresenceOptions RichPresenceOptions,
    OvrPlatform_RichPresence_Set_Delegate&& Delegate);

// ----------------------------------------------------------------------
// User

/**
 * Retrieve the user with the given ID. This might fail if the ID is invalid
 * or the user is blocked.
 * 
 * NOTE: Users will have a unique ID per application.
 * @param UserID - User ID retrieved with this application.
 */
typedef TSharedPtr<FOvrUser> FOvrUserPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_User_Get_Delegate, bool, FOvrUserPtr, FString);

void OvrPlatform_User_Get(
    UGameInstance* GameInstance,
    FOvrId UserID,
    OvrPlatform_User_Get_Delegate&& Delegate);

/** Return an access token for this user, suitable for making REST calls against graph.oculus.com. */
typedef TSharedPtr<FString> FStringPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_User_GetAccessToken_Delegate, bool, FStringPtr, FString);

void OvrPlatform_User_GetAccessToken(
    UGameInstance* GameInstance,
    OvrPlatform_User_GetAccessToken_Delegate&& Delegate);

/** Return the IDs of users entitled to use the current app that are blocked by the specified user */
typedef TSharedPtr<FOvrBlockedUserPages> FOvrBlockedUserArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_User_GetBlockedUsers_Delegate, bool, FOvrBlockedUserArrayPtr, FString);

void OvrPlatform_User_GetBlockedUsers(
    UGameInstance* GameInstance,
    OvrPlatform_User_GetBlockedUsers_Delegate&& Delegate);

/**
 * Retrieve the currently signed in user.  This call is available offline.
 * 
 * 
 * NOTE: This will not return the user's presence as it should always be 'online'
 * in your application.
 * 
 * 
 * NOTE: Users will have a unique ID per application.
 */
typedef TSharedPtr<FOvrUser> FOvrUserPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_User_GetLoggedInUser_Delegate, bool, FOvrUserPtr, FString);

void OvrPlatform_User_GetLoggedInUser(
    UGameInstance* GameInstance,
    OvrPlatform_User_GetLoggedInUser_Delegate&& Delegate);

/** Retrieve a list of the logged in user's bidirectional followers. */
typedef TSharedPtr<FOvrUserPages> FOvrUserArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_User_GetLoggedInUserFriends_Delegate, bool, FOvrUserArrayPtr, FString);

void OvrPlatform_User_GetLoggedInUserFriends(
    UGameInstance* GameInstance,
    OvrPlatform_User_GetLoggedInUserFriends_Delegate&& Delegate);

/**
 * returns an ovrID which is unique per org. allows different apps within the same
 * org to identify the user. 
 * @param UserID - to load the org scoped id of
 */
typedef TSharedPtr<FOvrOrgScopedID> FOvrOrgScopedIDPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_User_GetOrgScopedID_Delegate, bool, FOvrOrgScopedIDPtr, FString);

void OvrPlatform_User_GetOrgScopedID(
    UGameInstance* GameInstance,
    FOvrId UserID,
    OvrPlatform_User_GetOrgScopedID_Delegate&& Delegate);

/**
 * Returns all accounts belonging to this user.
 * Accounts are the Oculus user and x-users that are linked to this user.
 */
typedef TSharedPtr<TArray<FOvrSdkAccount>> FOvrSdkAccountArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_User_GetSdkAccounts_Delegate, bool, FOvrSdkAccountArrayPtr, FString);

void OvrPlatform_User_GetSdkAccounts(
    UGameInstance* GameInstance,
    OvrPlatform_User_GetSdkAccounts_Delegate&& Delegate);

/**
 * Part of the scheme to confirm the identity of a particular user in your backend.
 * You can pass the result of User_GetUserProof() and a user ID from
 * User_Get() to your your backend. Your server can then use our api
 * to verify identity.
 * 'https://graph.oculus.com/user_nonce_validate?nonce=USER_PROOF&amp;user_id=USER_ID&amp;access_token=ACCESS_TOKEN'
 * 
 * 
 * NOTE: The nonce is only good for one check and then it is invalidated.
 */
typedef TSharedPtr<FOvrUserProof> FOvrUserProofPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_User_GetUserProof_Delegate, bool, FOvrUserProofPtr, FString);

void OvrPlatform_User_GetUserProof(
    UGameInstance* GameInstance,
    OvrPlatform_User_GetUserProof_Delegate&& Delegate);

/**
 * Launch the flow for blocking the given user. You can't follow, be followed, invited,
 *  or searched by a blocked user, for example. You can remove the block via
 *  ovr_User_LaunchUnblockFlow.
 * @param UserID - User ID of user being blocked
 */
typedef TSharedPtr<FOvrLaunchBlockFlowResult> FOvrLaunchBlockFlowResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_User_LaunchBlockFlow_Delegate, bool, FOvrLaunchBlockFlowResultPtr, FString);

void OvrPlatform_User_LaunchBlockFlow(
    UGameInstance* GameInstance,
    FOvrId UserID,
    OvrPlatform_User_LaunchBlockFlow_Delegate&& Delegate);

/**
 * Launch the flow for sending a follow request to a user.
 * @param UserID - User ID of user to send a follow request to
 */
typedef TSharedPtr<FOvrLaunchFriendRequestFlowResult> FOvrLaunchFriendRequestFlowResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_User_LaunchFriendRequestFlow_Delegate, bool, FOvrLaunchFriendRequestFlowResultPtr, FString);

void OvrPlatform_User_LaunchFriendRequestFlow(
    UGameInstance* GameInstance,
    FOvrId UserID,
    OvrPlatform_User_LaunchFriendRequestFlow_Delegate&& Delegate);

/**
 * Launch the flow for unblocking a user that the viewer has blocked.
 * @param UserID - User ID of user to unblock
 */
typedef TSharedPtr<FOvrLaunchUnblockFlowResult> FOvrLaunchUnblockFlowResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_User_LaunchUnblockFlow_Delegate, bool, FOvrLaunchUnblockFlowResultPtr, FString);

void OvrPlatform_User_LaunchUnblockFlow(
    UGameInstance* GameInstance,
    FOvrId UserID,
    OvrPlatform_User_LaunchUnblockFlow_Delegate&& Delegate);

// ----------------------------------------------------------------------
// UserAgeCategory

/** Retrieve the user age category for the current user. */
typedef TSharedPtr<FOvrUserAccountAgeCategory> FOvrUserAccountAgeCategoryPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_UserAgeCategory_Get_Delegate, bool, FOvrUserAccountAgeCategoryPtr, FString);

void OvrPlatform_UserAgeCategory_Get(
    UGameInstance* GameInstance,
    OvrPlatform_UserAgeCategory_Get_Delegate&& Delegate);

/** Report the current user's age category to Meta. */
DECLARE_DELEGATE_TwoParams(OvrPlatform_UserAgeCategory_Report_Delegate, bool, FString);

void OvrPlatform_UserAgeCategory_Report(
    UGameInstance* GameInstance,
    EOvrAppAgeCategory AgeCategory,
    OvrPlatform_UserAgeCategory_Report_Delegate&& Delegate);

// ----------------------------------------------------------------------
// UserDataStore

/**
 * Delete an entry by a key from a private user data store.
 * @param UserID - The ID of the user who owns this private user data store.
 * @param Key - The key of entry.
 */
typedef TSharedPtr<FOvrUserDataStoreUpdateResponse> FOvrUserDataStoreUpdateResponsePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_UserDataStore_PrivateDeleteEntryByKey_Delegate, bool, FOvrUserDataStoreUpdateResponsePtr, FString);

void OvrPlatform_UserDataStore_PrivateDeleteEntryByKey(
    UGameInstance* GameInstance,
    FOvrId UserID,
    FString Key,
    OvrPlatform_UserDataStore_PrivateDeleteEntryByKey_Delegate&& Delegate);

/**
 * Get entries from a private user data store.
 * @param UserID - The ID of the user who owns this private user data store.
 */
typedef TSharedPtr<TMap<FString, FString>> FOvrDataStorePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_UserDataStore_PrivateGetEntries_Delegate, bool, FOvrDataStorePtr, FString);

void OvrPlatform_UserDataStore_PrivateGetEntries(
    UGameInstance* GameInstance,
    FOvrId UserID,
    OvrPlatform_UserDataStore_PrivateGetEntries_Delegate&& Delegate);

/**
 * Get an entry by a key from a private user data store.
 * @param UserID - The ID of the user who owns this private user data store.
 * @param Key - The key of entry.
 */
typedef TSharedPtr<TMap<FString, FString>> FOvrDataStorePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_UserDataStore_PrivateGetEntryByKey_Delegate, bool, FOvrDataStorePtr, FString);

void OvrPlatform_UserDataStore_PrivateGetEntryByKey(
    UGameInstance* GameInstance,
    FOvrId UserID,
    FString Key,
    OvrPlatform_UserDataStore_PrivateGetEntryByKey_Delegate&& Delegate);

/**
 * Write a single entry to a private user data store.
 * @param UserID - The ID of the user who owns this private user data store.
 * @param Key - The key of entry.
 * @param Value - The value of entry.
 */
typedef TSharedPtr<FOvrUserDataStoreUpdateResponse> FOvrUserDataStoreUpdateResponsePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_UserDataStore_PrivateWriteEntry_Delegate, bool, FOvrUserDataStoreUpdateResponsePtr, FString);

void OvrPlatform_UserDataStore_PrivateWriteEntry(
    UGameInstance* GameInstance,
    FOvrId UserID,
    FString Key,
    FString Value,
    OvrPlatform_UserDataStore_PrivateWriteEntry_Delegate&& Delegate);

/**
 * Delete an entry by a key from a public user data store.
 * @param UserID - The ID of the user who owns this public user data store.
 * @param Key - The key of entry.
 */
typedef TSharedPtr<FOvrUserDataStoreUpdateResponse> FOvrUserDataStoreUpdateResponsePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_UserDataStore_PublicDeleteEntryByKey_Delegate, bool, FOvrUserDataStoreUpdateResponsePtr, FString);

void OvrPlatform_UserDataStore_PublicDeleteEntryByKey(
    UGameInstance* GameInstance,
    FOvrId UserID,
    FString Key,
    OvrPlatform_UserDataStore_PublicDeleteEntryByKey_Delegate&& Delegate);

/**
 * Get entries from a public user data store.
 * @param UserID - The ID of the user who owns this public user data store.
 */
typedef TSharedPtr<TMap<FString, FString>> FOvrDataStorePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_UserDataStore_PublicGetEntries_Delegate, bool, FOvrDataStorePtr, FString);

void OvrPlatform_UserDataStore_PublicGetEntries(
    UGameInstance* GameInstance,
    FOvrId UserID,
    OvrPlatform_UserDataStore_PublicGetEntries_Delegate&& Delegate);

/**
 * Get an entry by a key from a public user data store.
 * @param UserID - The ID of the user who owns this public user data store.
 * @param Key - The key of entry.
 */
typedef TSharedPtr<TMap<FString, FString>> FOvrDataStorePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_UserDataStore_PublicGetEntryByKey_Delegate, bool, FOvrDataStorePtr, FString);

void OvrPlatform_UserDataStore_PublicGetEntryByKey(
    UGameInstance* GameInstance,
    FOvrId UserID,
    FString Key,
    OvrPlatform_UserDataStore_PublicGetEntryByKey_Delegate&& Delegate);

/**
 * Write a single entry to a public user data store.
 * @param UserID - The ID of the user who owns this public user data store.
 * @param Key - The key of entry.
 * @param Value - The value of entry.
 */
typedef TSharedPtr<FOvrUserDataStoreUpdateResponse> FOvrUserDataStoreUpdateResponsePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_UserDataStore_PublicWriteEntry_Delegate, bool, FOvrUserDataStoreUpdateResponsePtr, FString);

void OvrPlatform_UserDataStore_PublicWriteEntry(
    UGameInstance* GameInstance,
    FOvrId UserID,
    FString Key,
    FString Value,
    OvrPlatform_UserDataStore_PublicWriteEntry_Delegate&& Delegate);

// ----------------------------------------------------------------------
// Voip

/** Gets whether the microphone is currently available to the app. This can be used to show if the user's voice is able to be heard by other users. */
typedef TSharedPtr<FOvrMicrophoneAvailabilityState> FOvrMicrophoneAvailabilityStatePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Voip_GetMicrophoneAvailability_Delegate, bool, FOvrMicrophoneAvailabilityStatePtr, FString);

void OvrPlatform_Voip_GetMicrophoneAvailability(
    UGameInstance* GameInstance,
    OvrPlatform_Voip_GetMicrophoneAvailability_Delegate&& Delegate);

/** Sets whether SystemVoip should be suppressed so that this app's Voip can use the mic and play incoming Voip audio. Once microphone switching functionality for the user is released, this function will no longer work. You can use get_microphone_availability to see if the user has allowed the app access to the microphone. */
typedef TSharedPtr<FOvrSystemVoipState> FOvrSystemVoipStatePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Voip_SetSystemVoipSuppressed_Delegate, bool, FOvrSystemVoipStatePtr, FString);

void OvrPlatform_Voip_SetSystemVoipSuppressed(
    UGameInstance* GameInstance,
    bool Suppressed,
    OvrPlatform_Voip_SetSystemVoipSuppressed_Delegate&& Delegate);

