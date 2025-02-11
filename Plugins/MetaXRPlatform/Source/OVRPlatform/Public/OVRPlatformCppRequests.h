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

/**
 * The currently running application has indicated they want to show their in-app reporting flow or that they choose to ignore the request.
 * @param Response - Possible states that an app can respond to the platform notification that the in-app reporting flow has been requested by the user.
 */
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
 * @param Name - The api_name of the achievement that will be adding count, which can be retrieved by field FOvrAchievementDefinition::ApiName.
 * @param Count - The value of count that will be added to the achievement.
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
 * @param Name - The api_name of the Bitfield achievement whose field(s) will be unlocked, which can be retrieved by field FOvrAchievementDefinition::ApiName.
 * @param Fields - A string containing either '0' or '1' characters. Every '1' will unlock the field in the corresponding position.
 */
typedef TSharedPtr<FOvrAchievementUpdate> FOvrAchievementUpdatePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Achievements_AddFields_Delegate, bool, FOvrAchievementUpdatePtr, FString);

void OvrPlatform_Achievements_AddFields(
    UGameInstance* GameInstance,
    FString Name,
    FString Fields,
    OvrPlatform_Achievements_AddFields_Delegate&& Delegate);

/** Retrieve all achievement definitions for the app, including their name, unlock requirements, and any additional details. */
typedef TSharedPtr<FOvrAchievementDefinitionPages> FOvrAchievementDefinitionArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Achievements_GetAllDefinitions_Delegate, bool, FOvrAchievementDefinitionArrayPtr, FString);

void OvrPlatform_Achievements_GetAllDefinitions(
    UGameInstance* GameInstance,
    OvrPlatform_Achievements_GetAllDefinitions_Delegate&& Delegate);

/** Retrieve the progress for the user on all achievements in the app. */
typedef TSharedPtr<FOvrAchievementProgressPages> FOvrAchievementProgressArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Achievements_GetAllProgress_Delegate, bool, FOvrAchievementProgressArrayPtr, FString);

void OvrPlatform_Achievements_GetAllProgress(
    UGameInstance* GameInstance,
    OvrPlatform_Achievements_GetAllProgress_Delegate&& Delegate);

/**
 * Retrieve the achievement definitions that match the specified names, including their name, unlock requirements, and any additional details.
 * @param Names - The api_names of the achievements used to retrieve the definition information, which can be retrieved by field FOvrAchievementDefinition::ApiName.
 * @param Count - The number of specified achievements names.
 */
typedef TSharedPtr<FOvrAchievementDefinitionPages> FOvrAchievementDefinitionArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Achievements_GetDefinitionsByName_Delegate, bool, FOvrAchievementDefinitionArrayPtr, FString);

void OvrPlatform_Achievements_GetDefinitionsByName(
    UGameInstance* GameInstance,
    TArray<FString> Names,
    OvrPlatform_Achievements_GetDefinitionsByName_Delegate&& Delegate);

/**
 * Retrieve the user's progress on the achievements that match the specified names.
 * @param Names - The api_names of the achievements used to retrieve the progress information, which can be retrieved by field FOvrAchievementDefinition::ApiName.
 * @param Count - The number of specified achievements names.
 */
typedef TSharedPtr<FOvrAchievementProgressPages> FOvrAchievementProgressArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Achievements_GetProgressByName_Delegate, bool, FOvrAchievementProgressArrayPtr, FString);

void OvrPlatform_Achievements_GetProgressByName(
    UGameInstance* GameInstance,
    TArray<FString> Names,
    OvrPlatform_Achievements_GetProgressByName_Delegate&& Delegate);

/**
 * Unlock the achievement with the given name. This can be of any achievement type: a simple unlock, count-based, or bitfield-based achievement.
 * The Meta Quest Platform supports three types of achievements: simple, count and bitfield. Each achievement type has a different unlock mechanism.
 * Simple achievements are all-or-nothing. They are unlocked by a single event or objective completion.
 * For example, a simple achievement is unlocked when Frodo reaches Mount Doom.
 * Count achievements are unlocked when a counter reaches a defined target. Define the field FOvrAchievementDefinition::Target
 * to reach that triggers the achievement. For example, a target achievement is unlocked when Darth Vader chokes 3 disappointing Imperial officers.
 * Bitfield achievements are unlocked when a target number of bits in a bitfield are set. Define the field FOvrAchievementDefinition::Target
 * and field FOvrAchievementDefinition::BitfieldLength that triggers the achievement.
 * For example, a bitfield achievement is unlocked when Harry destroys 5 of the 7 Horcruxes.
 * @param Name - The api_name of the achievement that will be unlocked, which can be retrieved by field FOvrAchievementDefinition::ApiName.
 */
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

/** Track download progress for an app. */
typedef TSharedPtr<FOvrAppDownloadProgressResult> FOvrAppDownloadProgressResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Application_CheckAppDownloadProgress_Delegate, bool, FOvrAppDownloadProgressResultPtr, FString);

void OvrPlatform_Application_CheckAppDownloadProgress(
    UGameInstance* GameInstance,
    OvrPlatform_Application_CheckAppDownloadProgress_Delegate&& Delegate);

/**
 * Requests version information, including the field FOvrApplicationVersion::CurrentCode and
 * field FOvrApplicationVersion::CurrentName of the currently installed app
 * and field FOvrApplicationVersion::LatestCode, field FOvrApplicationVersion::LatestName,
 * field FOvrApplicationVersion::Size and field FOvrApplicationVersion::ReleaseDate of the latest app update.
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
 * based on the options passed in.
 * @param DeeplinkOptions - Additional configuration for this relaunch, which is optional. It contains 5 fields FOvrApplicationOptions::DeeplinkMessage, FOvrApplicationOptions::DestinationApiName, FOvrApplicationOptions::LobbySessionId, FOvrApplicationOptions::MatchSessionId and FOvrApplicationOptions::RoomId.
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
 * @param AppID - The unique ID of the app to be launched.
 * @param DeeplinkOptions - Additional configuration for this request, which is optional. It contains 5 fields FOvrApplicationOptions::DeeplinkMessage, FOvrApplicationOptions::DestinationApiName, FOvrApplicationOptions::LobbySessionId, FOvrApplicationOptions::MatchSessionId and FOvrApplicationOptions::RoomId.
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
 * Download progress can be monitored using the Application_CheckAppDownloadProgress().
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

/** \deprecated Use AssetFile_DeleteById() */
typedef TSharedPtr<FOvrAssetFileDeleteResult> FOvrAssetFileDeleteResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_AssetFile_Delete_Delegate, bool, FOvrAssetFileDeleteResultPtr, FString);

[[deprecated("Use AssetFile_DeleteById()")]]
void OvrPlatform_AssetFile_Delete(
    UGameInstance* GameInstance,
    FOvrId AssetFileID,
    OvrPlatform_AssetFile_Delete_Delegate&& Delegate);

/**
 * Removes a previously installed asset file from the device by its ID.
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
 * Removes a previously installed asset file from the device by its name.
 * Returns an object containing the asset ID and file name, and a success flag.
 * @param AssetFileName - The asset file name
 */
typedef TSharedPtr<FOvrAssetFileDeleteResult> FOvrAssetFileDeleteResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_AssetFile_DeleteByName_Delegate, bool, FOvrAssetFileDeleteResultPtr, FString);

void OvrPlatform_AssetFile_DeleteByName(
    UGameInstance* GameInstance,
    FString AssetFileName,
    OvrPlatform_AssetFile_DeleteByName_Delegate&& Delegate);

/** \deprecated Use AssetFile_DownloadById() */
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

/** \deprecated Use AssetFile_DownloadCancelById() */
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
 * Returns an array of asset details with asset file names and their associated IDs field FOvrAssetDetails::AssetId,
 * and whether it's currently installed field FOvrAssetDetails::DownloadStatus.
 */
typedef TSharedPtr<TArray<FOvrAssetDetails>> FOvrAssetDetailsArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_AssetFile_GetList_Delegate, bool, FOvrAssetDetailsArrayPtr, FString);

void OvrPlatform_AssetFile_GetList(
    UGameInstance* GameInstance,
    OvrPlatform_AssetFile_GetList_Delegate&& Delegate);

/** \deprecated Use AssetFile_StatusById() */
typedef TSharedPtr<FOvrAssetDetails> FOvrAssetDetailsPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_AssetFile_Status_Delegate, bool, FOvrAssetDetailsPtr, FString);

[[deprecated("Use AssetFile_StatusById()")]]
void OvrPlatform_AssetFile_Status(
    UGameInstance* GameInstance,
    FOvrId AssetFileID,
    OvrPlatform_AssetFile_Status_Delegate&& Delegate);

/**
 * Returns the details FOvrAssetDetails on a single asset: ID, file name, and whether it's currently installed
 * @param AssetFileID - The asset file ID
 */
typedef TSharedPtr<FOvrAssetDetails> FOvrAssetDetailsPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_AssetFile_StatusById_Delegate, bool, FOvrAssetDetailsPtr, FString);

void OvrPlatform_AssetFile_StatusById(
    UGameInstance* GameInstance,
    FOvrId AssetFileID,
    OvrPlatform_AssetFile_StatusById_Delegate&& Delegate);

/**
 * Returns the details FOvrAssetDetails on a single asset: ID, file name, and whether it's currently installed
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

/**
 * Launches the Avatar Editor. Meta Avatars Editor is a feature that allows users to edit their Meta Avatars appearances within the VR application
 * that they are currently using. This experience is often used by users to switch their outfit and accessories to better suit the VR experience they are experiencing.
 * The result can be retrieved by field FOvrAvatarEditorResult::RequestSent.
 * @param Options - A FOvrAvatarEditorOptions contains the options information, including an optional override for the source of the request, which is specified by FOvrAvatarEditorOptions::SourceOverride.
 */
typedef TSharedPtr<FOvrAvatarEditorResult> FOvrAvatarEditorResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Avatar_LaunchAvatarEditor_Delegate, bool, FOvrAvatarEditorResultPtr, FString);

void OvrPlatform_Avatar_LaunchAvatarEditor(
    UGameInstance* GameInstance,
    FOvrAvatarEditorOptions Options,
    OvrPlatform_Avatar_LaunchAvatarEditor_Delegate&& Delegate);

// ----------------------------------------------------------------------
// Challenges

/** \deprecated Use server-to-server API call instead. */
typedef TSharedPtr<FOvrChallenge> FOvrChallengePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Challenges_Create_Delegate, bool, FOvrChallengePtr, FString);

[[deprecated("Use server-to-server API call instead.")]]
void OvrPlatform_Challenges_Create(
    UGameInstance* GameInstance,
    FString LeaderboardName,
    FOvrChallengeOptions ChallengeOptions,
    OvrPlatform_Challenges_Create_Delegate&& Delegate);

/**
 * If the current user has the necessary permissions, they can decline a challenge by providing the challenge ID,
 * which can be obtained using field FOvrChallenge::ID.
 * @param ChallengeID - The ID of challenge that the user is going to decline. It can be retrieved by field FOvrChallenge::ID.
 */
typedef TSharedPtr<FOvrChallenge> FOvrChallengePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Challenges_DeclineInvite_Delegate, bool, FOvrChallengePtr, FString);

void OvrPlatform_Challenges_DeclineInvite(
    UGameInstance* GameInstance,
    FOvrId ChallengeID,
    OvrPlatform_Challenges_DeclineInvite_Delegate&& Delegate);

/** \deprecated Use server-to-server API call instead. */
DECLARE_DELEGATE_TwoParams(OvrPlatform_Challenges_Delete_Delegate, bool, FString);

[[deprecated("Use server-to-server API call instead.")]]
void OvrPlatform_Challenges_Delete(
    UGameInstance* GameInstance,
    FOvrId ChallengeID,
    OvrPlatform_Challenges_Delete_Delegate&& Delegate);

/**
 * Gets detailed information for a single challenge by providing the challenge ID, which can be retrieved by calling field FOvrChallenge::ID.
 * @param ChallengeID - The id of the challenge whose entries to return, which can be retrieved by calling field FOvrChallenge::ID.
 */
typedef TSharedPtr<FOvrChallenge> FOvrChallengePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Challenges_Get_Delegate, bool, FOvrChallengePtr, FString);

void OvrPlatform_Challenges_Get(
    UGameInstance* GameInstance,
    FOvrId ChallengeID,
    OvrPlatform_Challenges_Get_Delegate&& Delegate);

/**
 * Retrieves a list of entries for a specific challenge, with options to filter and limit the results. By providing the challengeID,
 * you can specify which challenge's entries you want to retrieve. The limit parameter allows you to control the number of entries returned.
 * The filter parameter enables you to refine the results to only include entries from users who are bidirectional followers.
 * The startAt parameter allows you to define whether to center the query on the user or start at the top of the challenge.
 * @param ChallengeID - The id of the challenge whose entries to return, which can be retrieved by calling field FOvrChallenge::ID.
 * @param Limit - Sets a limit on the maximum number of challenges to be fetched, which can be useful for pagination or performance reasons.
 * @param Filter - By using the EOvrLeaderboardFilterType, you can refine the results to only include entries from users who are bidirectional followers.
 * @param StartAt - Defines whether to center the query on the user or start at the top of the challenge. If this is EOvrLeaderboardStartAt::CenteredOnViewer or EOvrLeaderboardStartAt::CenteredOnViewerOrTop, then the current user's ID will be automatically added to the query.
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
 * Returns a list of entries for a specific challenge, starting from a specified rank.
 * By providing the challengeID and rank, you can specify which challenge's entries you want to retrieve and where to start the query.
 * The limit parameter allows you to control the number of entries returned.
 * @param ChallengeID - The id of the challenge whose entries to return, which can be retrieved by calling field FOvrChallenge::ID.
 * @param Limit - Sets a limit on the maximum number of challenges to be fetched, which can be useful for pagination or performance reasons.
 * @param AfterRank - The position after which to start. For example, 10 returns challenge results starting with the 11th user.
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
 * Retrieves a list of challenge entries for a specific set of user IDs, with options to filter and limit the results.
 * This method is useful for retrieving a list of challenge entries for a specific set of users, allowing you to display their progress and rankings within the challenge.
 * @param ChallengeID - The id of the challenge whose entries to return, which can be retrieved by calling field FOvrChallenge::ID.
 * @param Limit - Sets a limit on the maximum number of challenges to be fetched, which can be useful for pagination or performance reasons.
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

/**
 * Returns a list of challenges that match the specified options. The FOvrChallengeOptions parameter allows you to specify
 * the criteria for the challenges you want to retrieve. The limit parameter allows you to control the number of challenges returned.
 * @param ChallengeOptions - This indicates the options of the challenge and it can be retrieved by FOvrChallengeOptions.
 * @param Limit - Sets a limit on the maximum number of challenges to be fetched, which can be useful for pagination or performance reasons.
 */
typedef TSharedPtr<FOvrChallengePages> FOvrChallengeArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Challenges_GetList_Delegate, bool, FOvrChallengeArrayPtr, FString);

void OvrPlatform_Challenges_GetList(
    UGameInstance* GameInstance,
    FOvrChallengeOptions ChallengeOptions,
    int32 Limit,
    OvrPlatform_Challenges_GetList_Delegate&& Delegate);

/**
 * If the current user has the necessary permissions to join, participate in a challenge by providing the challenge ID,
 * which can be retrieved using field FOvrChallenge::ID.
 * @param ChallengeID - The ID of challenge that the user is going to join. It can be retrieved by field FOvrChallenge::ID.
 */
typedef TSharedPtr<FOvrChallenge> FOvrChallengePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Challenges_Join_Delegate, bool, FOvrChallengePtr, FString);

void OvrPlatform_Challenges_Join(
    UGameInstance* GameInstance,
    FOvrId ChallengeID,
    OvrPlatform_Challenges_Join_Delegate&& Delegate);

/**
 * If the current user has the necessary permissions, they can leave a challenge by providing the challenge ID,
 * which can be obtained using field FOvrChallenge::ID.
 * @param ChallengeID - The ID of challenge that the user is going to leave. It can be retrieved by field FOvrChallenge::ID.
 */
typedef TSharedPtr<FOvrChallenge> FOvrChallengePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Challenges_Leave_Delegate, bool, FOvrChallengePtr, FString);

void OvrPlatform_Challenges_Leave(
    UGameInstance* GameInstance,
    FOvrId ChallengeID,
    OvrPlatform_Challenges_Leave_Delegate&& Delegate);

/** \deprecated Use server-to-server API call instead. */
typedef TSharedPtr<FOvrChallenge> FOvrChallengePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Challenges_UpdateInfo_Delegate, bool, FOvrChallengePtr, FString);

[[deprecated("Use server-to-server API call instead.")]]
void OvrPlatform_Challenges_UpdateInfo(
    UGameInstance* GameInstance,
    FOvrId ChallengeID,
    FOvrChallengeOptions ChallengeOptions,
    OvrPlatform_Challenges_UpdateInfo_Delegate&& Delegate);

// ----------------------------------------------------------------------
// Cowatching

/**
 * Retrieve the presenter data that drives an active cowatching session.
 * This method can be called when there is an ongoing cowatching session,
 * allowing developers to access and utilize the presenter data to enhance the user experience.
 */
typedef TSharedPtr<FString> FStringPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Cowatching_GetPresenterData_Delegate, bool, FStringPtr, FString);

void OvrPlatform_Cowatching_GetPresenterData(
    UGameInstance* GameInstance,
    OvrPlatform_Cowatching_GetPresenterData_Delegate&& Delegate);

/**
 * Retrieve the viewer data of everyone who is in a cowatching session whose data was set by Cowatching_SetViewerData() ViewerData.
 * This can be called when there is an active cowatching session.
 */
typedef TSharedPtr<FOvrCowatchViewerPages> FOvrCowatchViewerArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Cowatching_GetViewersData_Delegate, bool, FOvrCowatchViewerArrayPtr, FString);

void OvrPlatform_Cowatching_GetViewersData(
    UGameInstance* GameInstance,
    OvrPlatform_Cowatching_GetViewersData_Delegate&& Delegate);

/**
 * Check whether the current user is participating in the ongoing cowatching session.
 * It returns a boolean value field FOvrCowatchingState::InSession indicating the user's presence in the session.
 */
typedef TSharedPtr<FOvrCowatchingState> FOvrCowatchingStatePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Cowatching_IsInSession_Delegate, bool, FOvrCowatchingStatePtr, FString);

void OvrPlatform_Cowatching_IsInSession(
    UGameInstance* GameInstance,
    OvrPlatform_Cowatching_IsInSession_Delegate&& Delegate);

/** Join the ongoing cowatching session as a viewer, updating data only possible for users already in the session. */
DECLARE_DELEGATE_TwoParams(OvrPlatform_Cowatching_JoinSession_Delegate, bool, FString);

void OvrPlatform_Cowatching_JoinSession(
    UGameInstance* GameInstance,
    OvrPlatform_Cowatching_JoinSession_Delegate&& Delegate);

/** Launch a dialog for inviting users to cowatch in Copresent Home. */
DECLARE_DELEGATE_TwoParams(OvrPlatform_Cowatching_LaunchInviteDialog_Delegate, bool, FString);

void OvrPlatform_Cowatching_LaunchInviteDialog(
    UGameInstance* GameInstance,
    OvrPlatform_Cowatching_LaunchInviteDialog_Delegate&& Delegate);

/** Leave the current cowatching session, rendering viewer data obsolete and no longer relevant to the ongoing experience. */
DECLARE_DELEGATE_TwoParams(OvrPlatform_Cowatching_LeaveSession_Delegate, bool, FString);

void OvrPlatform_Cowatching_LeaveSession(
    UGameInstance* GameInstance,
    OvrPlatform_Cowatching_LeaveSession_Delegate&& Delegate);

/** Request to initiate a cowatching session as the presenter while being copresent in a shared virtual home environment. */
DECLARE_DELEGATE_TwoParams(OvrPlatform_Cowatching_RequestToPresent_Delegate, bool, FString);

void OvrPlatform_Cowatching_RequestToPresent(
    UGameInstance* GameInstance,
    OvrPlatform_Cowatching_RequestToPresent_Delegate&& Delegate);

/** Stop being the presenter and terminate the ongoing cowatching session. This action will effectively end the shared media experience. */
DECLARE_DELEGATE_TwoParams(OvrPlatform_Cowatching_ResignFromPresenting_Delegate, bool, FString);

void OvrPlatform_Cowatching_ResignFromPresenting(
    UGameInstance* GameInstance,
    OvrPlatform_Cowatching_ResignFromPresenting_Delegate&& Delegate);

/**
 * Set the data that drives a cowatching session. This method is only callable by the presenter.
 * The video title cannot exceed 100 characters, and the data size is limited to 500 characters.
 * The data will be eventually consistent across all users.
 * @param VideoTitle - A string representing the title of the video being played in the cowatching session. This parameter must not exceed 100 characters in length.
 * @param PresenterData - A string containing data that drives the cowatching session, such as video metadata or playback information. This parameter is limited to 500 characters in length and will be eventually consistent across all users participating in the session.
 */
DECLARE_DELEGATE_TwoParams(OvrPlatform_Cowatching_SetPresenterData_Delegate, bool, FString);

void OvrPlatform_Cowatching_SetPresenterData(
    UGameInstance* GameInstance,
    FString VideoTitle,
    FString PresenterData,
    OvrPlatform_Cowatching_SetPresenterData_Delegate&& Delegate);

/**
 * Set the current user's viewer data to be shared with copresent users. This can be called when there is an active cowatching session.
 * The data size is limited to 500 characters, and it will eventually become consistent across all users.
 * @param ViewerData - A string containing data about the current user's viewer state, such as their preferences or settings. This data is shared with copresent users during an active cowatching session and is limited to 500 characters in size. The data will eventually become consistent across all users participating in the session.
 */
DECLARE_DELEGATE_TwoParams(OvrPlatform_Cowatching_SetViewerData_Delegate, bool, FString);

void OvrPlatform_Cowatching_SetViewerData(
    UGameInstance* GameInstance,
    FString ViewerData,
    OvrPlatform_Cowatching_SetViewerData_Delegate&& Delegate);

// ----------------------------------------------------------------------
// DeviceApplicationIntegrity

/**
 * Returns Device and Application Integrity Attestation JSON Web Token.
 * The token has format of header.claims.signature encoded in base64.
 * Header contains algorithm type (PS256) and token type (JWT).
 * See more details [here](https://developer.oculus.com/documentation/unreal/ps-attestation-api/#how-does-this-work).
 * @param ChallengeNonce - A string that represents a nonce value used to generate the attestation token, ensuring uniqueness and security.
 */
typedef TSharedPtr<FString> FStringPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_DeviceApplicationIntegrity_GetIntegrityToken_Delegate, bool, FStringPtr, FString);

void OvrPlatform_DeviceApplicationIntegrity_GetIntegrityToken(
    UGameInstance* GameInstance,
    FString ChallengeNonce,
    OvrPlatform_DeviceApplicationIntegrity_GetIntegrityToken_Delegate&& Delegate);

// ----------------------------------------------------------------------
// Entitlement

/**
 * Returns whether the current user is entitled to the current app. The primary purpose of this function is to verify
 * user access rights to the application, ensuring that the user is authorized to use it.
 * See example usage [here](https://developer.oculus.com/documentation/unreal/ps-entitlement-check/#entitlement).
 */
DECLARE_DELEGATE_TwoParams(OvrPlatform_Entitlement_GetIsViewerEntitled_Delegate, bool, FString);

void OvrPlatform_Entitlement_GetIsViewerEntitled(
    UGameInstance* GameInstance,
    OvrPlatform_Entitlement_GetIsViewerEntitled_Delegate&& Delegate);

// ----------------------------------------------------------------------
// GroupPresence

/**
 * Clears the current group presence settings for your app. Use this when a user’s group presence setting in your app
 * needs to be changed when moving to new destinations in your app.
 */
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
 * Launches the system invite dialog with a roster of eligible users for the current user to invite to the app.
 * It is recommended that you surface a button in your UI that triggers this dialog when a user is joinable.
 * @param Options - It contains two methods. 1. Add FOvrInviteOptions::SuggestedUsers - Takes the userID as a parameter and adds it to the inevitable users list. 2. Clear FOvrInviteOptions::SuggestedUsers - Clears the inevitable users list.
 */
typedef TSharedPtr<FOvrInvitePanelResultInfo> FOvrInvitePanelResultInfoPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_GroupPresence_LaunchInvitePanel_Delegate, bool, FOvrInvitePanelResultInfoPtr, FString);

void OvrPlatform_GroupPresence_LaunchInvitePanel(
    UGameInstance* GameInstance,
    FOvrInviteOptions Options,
    OvrPlatform_GroupPresence_LaunchInvitePanel_Delegate&& Delegate);

/**
 * Launch an error dialog window with predefined messages for commonly occurring multiplayer errors.
 * Check the Invokable Error Dialogs documentation for more information about these error messages and their values.
 * @param Options - It contains a FOvrMultiplayerErrorOptions::ErrorKey associated with the predefined error message to be shown to users.
 */
DECLARE_DELEGATE_TwoParams(OvrPlatform_GroupPresence_LaunchMultiplayerErrorDialog_Delegate, bool, FString);

void OvrPlatform_GroupPresence_LaunchMultiplayerErrorDialog(
    UGameInstance* GameInstance,
    FOvrMultiplayerErrorOptions Options,
    OvrPlatform_GroupPresence_LaunchMultiplayerErrorDialog_Delegate&& Delegate);

/**
 * Launch the dialog allowing users to rejoin a previous lobby or match.
 * Either the user’s FOvrGroupPresenceOptions::LobbySessionId, their FOvrGroupPresenceOptions::MatchSessionId,
 * or both must be populated as valid rejoinable destinations.
 * Check the Rejoin documentation for use cases and information on this feature.
 * @param LobbySessionId - The unique identifier of the lobby session to rejoin.
 * @param MatchSessionId - The unique identifier of the match session to rejoin.
 * @param DestinationApiName - The unique name of the in-app destination to rejoin.
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
 * Launch the panel displaying the current users in the roster. We do not recommend using this API
 * because the list current users is surfaced in the Destination UI when the Meta Quest button is pressed.
 * @param Options - It contains 2 methods. 1. Add FOvrRosterOptions::SuggestedUsers - it takes userID as a parameter and adds it to the inevitable users list. 2.Clear FOvrRosterOptions::SuggestedUsers - it clears the inevitable users list.
 */
DECLARE_DELEGATE_TwoParams(OvrPlatform_GroupPresence_LaunchRosterPanel_Delegate, bool, FString);

void OvrPlatform_GroupPresence_LaunchRosterPanel(
    UGameInstance* GameInstance,
    FOvrRosterOptions Options,
    OvrPlatform_GroupPresence_LaunchRosterPanel_Delegate&& Delegate);

/**
 * Sends invites to the current application to the list of userIDs passed in.
 * You can fetch a list of users to pass in via the GroupPresence_GetInvitableUsers().
 * This API works as an alternative to GroupPresence_LaunchInvitePanel()
 * which delegates the invite flow to the system invite module.
 * GroupPresence_LaunchInvitePanel() is the recommended approach.
 * @param UserIDs - userIDs is a list of users’ ids to send invites to.
 * @param UserIDLength - The number of user IDs provided.
 */
typedef TSharedPtr<FOvrSendInvitesResult> FOvrSendInvitesResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_GroupPresence_SendInvites_Delegate, bool, FOvrSendInvitesResultPtr, FString);

void OvrPlatform_GroupPresence_SendInvites(
    UGameInstance* GameInstance,
    TArray<FOvrId> UserIDs,
    OvrPlatform_GroupPresence_SendInvites_Delegate&& Delegate);

/**
 * Sets group presence information for your current app. It is recommended that you use this parameter and
 * its methods to set group presence information for your app. An example of using this parameter can be found
 * on the Group Presence overview page where the methods to set FOvrGroupPresenceOptions::DestinationApiName, FOvrGroupPresenceOptions::MatchSessionId,
 * and FOvrGroupPresenceOptions::LobbySessionId are used.
 * @param GroupPresenceOptions - The groupPresenceOptions parameter contains five methods. 1. FOvrGroupPresenceOptions::DeeplinkMessageOverride - Use FOvrGroupPresenceOptions::LobbySessionId or FOvrGroupPresenceOptions::MatchSessionId to specify the session. Use the FOvrGroupPresenceOptions::DeeplinkMessageOverride for any additional data in whatever format you wish to aid in bringing users together. If not specified, the deeplink_message for the user will default to the one on the destination. 2.FOvrGroupPresenceOptions::DestinationApiName - This the unique API Name that refers to an in-app destination. 3.FOvrGroupPresenceOptions::IsJoinable - Set whether or not the person is shown as joinable or not to others. A user that is joinable can invite others to join them. Set this to false if other users would not be able to join this user. For example, the current session is full, or only the host can invite others and the current user is not the host. 4.FOvrGroupPresenceOptions::LobbySessionId - This is a session that represents a closer group/squad/party of users. It is expected that all users with the same lobby session id can see or hear each other. Users with the same lobby session id in their group presence will show up in the roster and will show up as "Recently Played With" for future invites if they aren't already Oculus friends. This must be set in addition to FOvrGroupPresenceOptions::IsJoinable being true for a user to use invites. 5.FOvrGroupPresenceOptions::MatchSessionId - This is a session that represents all the users that are playing a specific instance of a map, game mode, round, etc. This can include users from multiple different lobbies that joined together and the users may or may not remain together after the match is over. Users with the same match session id in their group presence will not show up in the Roster, but will show up as "Recently Played with" for future invites.
 */
DECLARE_DELEGATE_TwoParams(OvrPlatform_GroupPresence_Set_Delegate, bool, FString);

void OvrPlatform_GroupPresence_Set(
    UGameInstance* GameInstance,
    FOvrGroupPresenceOptions GroupPresenceOptions,
    OvrPlatform_GroupPresence_Set_Delegate&& Delegate);

/**
 * Sets the user's FOvrGroupPresenceOptions::DeeplinkMessageOverride while keeping the other group presence parameters the same.
 * If the destination of the user is not set, the deeplink message cannot be set as there's no deeplink message to override.
 * This method does not power travel from the Meta Quest platform to your app.
 * You must set a user’s FOvrGroupPresenceOptions::DestinationApiName, FOvrGroupPresenceOptions::IsJoinable status,
 * and FOvrGroupPresenceOptions::LobbySessionId to enable travel to your app. Check Group Presence overview for more information about these values.
 * Note: Instead of using this standalone API, we recommend setting all GroupPresence parameters in one call to GroupPresence_Set().
 * @param DeeplinkMessage - deeplink_message is the new FOvrGroupPresenceOptions::DeeplinkMessageOverride to set for the user, overriding the current deeplink message.
 */
DECLARE_DELEGATE_TwoParams(OvrPlatform_GroupPresence_SetDeeplinkMessageOverride_Delegate, bool, FString);

void OvrPlatform_GroupPresence_SetDeeplinkMessageOverride(
    UGameInstance* GameInstance,
    FString DeeplinkMessage,
    OvrPlatform_GroupPresence_SetDeeplinkMessageOverride_Delegate&& Delegate);

/**
 * Replaces the user's current FOvrGroupPresenceOptions::DestinationApiName with the provided one. Use this to set a user's current destination
 * while keeping all the other Group Presence parameters the same. Setting a user's destination is required to enable travel from the Meta Quest Platform
 * to your app. NOTE instead of using the standalone API, we recommend setting all GroupPresence parameters in one call to GroupPresence_Set().
 * This helps ensure that all relevant presence information is singularly updated and helps reduce presence errors.
 * @param ApiName - api_name is the unique name of the in-app desination to set, replacing the user's current FOvrGroupPresenceOptions::DestinationApiName.
 */
DECLARE_DELEGATE_TwoParams(OvrPlatform_GroupPresence_SetDestination_Delegate, bool, FString);

void OvrPlatform_GroupPresence_SetDestination(
    UGameInstance* GameInstance,
    FString ApiName,
    OvrPlatform_GroupPresence_SetDestination_Delegate&& Delegate);

/**
 * Sets a user’s current presence as joinable. Use this method to update a user’s joinability as it changes.
 * For example, when the game starts, the lobby becomes full, the user moves to a private,
 * non joinable instance while keeping all other GroupPresence parameters
 * (i.e  FOvrGroupPresenceOptions::DestinationApiName, FOvrGroupPresenceOptions::LobbySessionId,
 * FOvrGroupPresenceOptions::MatchSessionId) the same.
 * Setting a user’s destination is required to enable travel from the Meta Quest Platform to your app.
 * Note: Instead of using this individual API, we recommend setting all GroupPresence information with the GroupPresence_Set()
 * method and its associated parameters to simply managing all presence information.
 * This helps ensure that all relevant presence information is singularly updated and helps reduce presence errors.
 * @param IsJoinable - If FOvrGroupPresenceOptions::IsJoinable is true, the user can invite others to join them. If false, other users cannot join this user, for example, if the current session is full or only the host can invite others and the current user is not the host.
 */
DECLARE_DELEGATE_TwoParams(OvrPlatform_GroupPresence_SetIsJoinable_Delegate, bool, FString);

void OvrPlatform_GroupPresence_SetIsJoinable(
    UGameInstance* GameInstance,
    bool IsJoinable,
    OvrPlatform_GroupPresence_SetIsJoinable_Delegate&& Delegate);

/**
 * Replaces the user's current FOvrGroupPresenceOptions::LobbySessionId for the provided string. Use this to set a user's current
 * lobby session id while keeping all other GroupPresence parameters the same. Setting a user's lobby session id is required to enable travel
 * from the Meta Quest Platform to your app. Check Group presence overview for more information. NOTE instead of using the standalone API,
 * we recommend setting all GroupPresence parameters in one call to GroupPresence_Set(). This helps ensure that all relevant presence
 * information is singularly updated and helps reduce presence errors.
 * @param Id - id is the unique identifier of the lobby session to set, replacing the user's current FOvrGroupPresenceOptions::LobbySessionId.
 */
DECLARE_DELEGATE_TwoParams(OvrPlatform_GroupPresence_SetLobbySession_Delegate, bool, FString);

void OvrPlatform_GroupPresence_SetLobbySession(
    UGameInstance* GameInstance,
    FString Id,
    OvrPlatform_GroupPresence_SetLobbySession_Delegate&& Delegate);

/**
 * Replaces the user's current FOvrGroupPresenceOptions::MatchSessionId for the provided one. Use this to update the user's current match session
 * id while keeping all other GroupPresence parameters the same. FOvrGroupPresenceOptions::MatchSessionId works in conjuction with
 * FOvrGroupPresenceOptions::LobbySessionId to determine if users are playing together. If a user's match and lobby session ids are the same,
 * they should be in the same multiplayer instance together. Users with the same lobby session id but different match session ids may be
 * in the same lobby for things like voice chat while in different instances in your app. WARNING match session id is often treated the same as
 * lobby session id, but this is in fact a distinct parameter and is not used for travel from the Meta Quest Platform. NOTE instead of using the standalone API,
 * we recommend setting all GroupPresence parameters in one call to GroupPresence_Set().
 * @param Id - id is the unique identifier of the match session to set, replacing the user's current FOvrGroupPresenceOptions::MatchSessionId.
 */
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
 * @param Sku - The SKU of the product of the purchase that will be consumed. This value is case-sensitive and should match exactly with the product SKU set in the Developer Dashboard.
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
 * message and how to resolve it, if possible. Returns a purchase on success, empty
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
 * view of the FOvrAssetDetails. Use field FOvrAssetDetails::Language field to extract needed
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
 * to retrieve the data, and use the language at runtime.
 * @param Tag - The BCP47 language tag that identifies the language to be set as the current language.
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
 * @param ForceUpdate - If true, the score always updates. This happens even if it is not the user's best score.
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
 *  Launch the Share to Facebook modal, allowing users to share local media files to Facebook.
 * Accepts a PostTextSuggestion string for the default text of the Facebook post.
 * Requires a FilePath string as the path to the image to be shared to Facebook.
 * This image should be located in your app's internal storage directory.
 * Requires a ContentType indicating the type of media to be shared
 * (only 'photo' is currently supported).
 * The payload for the result is defined as FOvrShareMediaResult.
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

/** \deprecated Use the clear method in group presence */
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

/** \deprecated Use GroupPresence_Set(). */
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

/** Return an access token string for this user, suitable for making REST calls against graph.oculus.com. */
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

/** Retrieve a list of the logged in user's bidirectional followers. The payload type will be an array of FOvrUser  */
typedef TSharedPtr<FOvrUserPages> FOvrUserArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_User_GetLoggedInUserFriends_Delegate, bool, FOvrUserArrayPtr, FString);

void OvrPlatform_User_GetLoggedInUserFriends(
    UGameInstance* GameInstance,
    OvrPlatform_User_GetLoggedInUserFriends_Delegate&& Delegate);

/**
 * Retrieve the currently signed in user's managed info.  This call is not available offline.
 * 
 * NOTE: This will return data only if the logged in user is a managed Meta account (MMA).
 */
typedef TSharedPtr<FOvrUser> FOvrUserPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_User_GetLoggedInUserManagedInfo_Delegate, bool, FOvrUserPtr, FString);

void OvrPlatform_User_GetLoggedInUserManagedInfo(
    UGameInstance* GameInstance,
    OvrPlatform_User_GetLoggedInUserManagedInfo_Delegate&& Delegate);

/**
 * returns an ovrID which is unique per org. allows different apps within the same
 * org to identify the user. 
 * @param UserID - The id of the user that we are going to get its org scoped ID FOvrOrgScopedID.
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
 * User_Get() to your backend. Your server can then use our api
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
 * @param UserID - The ID of the user that the viewer is going to laucnh the block flow request.
 */
typedef TSharedPtr<FOvrLaunchBlockFlowResult> FOvrLaunchBlockFlowResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_User_LaunchBlockFlow_Delegate, bool, FOvrLaunchBlockFlowResultPtr, FString);

void OvrPlatform_User_LaunchBlockFlow(
    UGameInstance* GameInstance,
    FOvrId UserID,
    OvrPlatform_User_LaunchBlockFlow_Delegate&& Delegate);

/**
 * Launch the flow for sending a follow request to a user.
 * @param UserID - The ID of the target user that is going to send the friend follow request to.
 */
typedef TSharedPtr<FOvrLaunchFriendRequestFlowResult> FOvrLaunchFriendRequestFlowResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_User_LaunchFriendRequestFlow_Delegate, bool, FOvrLaunchFriendRequestFlowResultPtr, FString);

void OvrPlatform_User_LaunchFriendRequestFlow(
    UGameInstance* GameInstance,
    FOvrId UserID,
    OvrPlatform_User_LaunchFriendRequestFlow_Delegate&& Delegate);

/**
 * Launch the flow for unblocking a user that the viewer has blocked.
 * @param UserID - The ID of the user that the viewer is going to launch the unblock flow request.
 */
typedef TSharedPtr<FOvrLaunchUnblockFlowResult> FOvrLaunchUnblockFlowResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_User_LaunchUnblockFlow_Delegate, bool, FOvrLaunchUnblockFlowResultPtr, FString);

void OvrPlatform_User_LaunchUnblockFlow(
    UGameInstance* GameInstance,
    FOvrId UserID,
    OvrPlatform_User_LaunchUnblockFlow_Delegate&& Delegate);

// ----------------------------------------------------------------------
// UserAgeCategory

/** Retrieve the user age category for the current user. It can be used in field FOvrUserAccountAgeCategory::AgeCategory */
typedef TSharedPtr<FOvrUserAccountAgeCategory> FOvrUserAccountAgeCategoryPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_UserAgeCategory_Get_Delegate, bool, FOvrUserAccountAgeCategoryPtr, FString);

void OvrPlatform_UserAgeCategory_Get(
    UGameInstance* GameInstance,
    OvrPlatform_UserAgeCategory_Get_Delegate&& Delegate);

/**
 * Report the current user's age category to Meta.
 * @param AgeCategory - Age category for developers to send to Meta. There are two members, children age group (EOvrAppAgeCategory::Ch) and non-children age group (EOvrAppAgeCategory::Nch).
 */
DECLARE_DELEGATE_TwoParams(OvrPlatform_UserAgeCategory_Report_Delegate, bool, FString);

void OvrPlatform_UserAgeCategory_Report(
    UGameInstance* GameInstance,
    EOvrAppAgeCategory AgeCategory,
    OvrPlatform_UserAgeCategory_Report_Delegate&& Delegate);

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

