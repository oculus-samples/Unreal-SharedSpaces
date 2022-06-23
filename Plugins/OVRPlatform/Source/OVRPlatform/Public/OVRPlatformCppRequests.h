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

/** Requests version information, including the currently installed and latest available version name and version code. */
typedef TSharedPtr<FOvrApplicationVersion> FOvrApplicationVersionPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Application_GetVersion_Delegate, bool, FOvrApplicationVersionPtr, FString);

void OvrPlatform_Application_GetVersion(
    UGameInstance* GameInstance,
    OvrPlatform_Application_GetVersion_Delegate&& Delegate);

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
 * @param Filter - Allows you to restrict the returned values by friends.
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
// CloudStorage

/**
 * Deletes the specified save data buffer.  Conflicts are handled just like Saves.
 * @param Bucket - The name of the storage bucket.
 * @param Key - The name for this saved data.
 */
typedef TSharedPtr<FOvrCloudStorageUpdateResponse> FOvrCloudStorageUpdateResponsePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_CloudStorage_Delete_Delegate, bool, FOvrCloudStorageUpdateResponsePtr, FString);

void OvrPlatform_CloudStorage_Delete(
    UGameInstance* GameInstance,
    FString Bucket,
    FString Key,
    OvrPlatform_CloudStorage_Delete_Delegate&& Delegate);

/**
 * Loads the saved entry for the specified bucket and key.
 * If a conflict exists with the key then an error message is returned.
 * @param Bucket - The name of the storage bucket.
 * @param Key - The name for this saved data.
 */
typedef TSharedPtr<FOvrCloudStorageData> FOvrCloudStorageDataPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_CloudStorage_Load_Delegate, bool, FOvrCloudStorageDataPtr, FString);

void OvrPlatform_CloudStorage_Load(
    UGameInstance* GameInstance,
    FString Bucket,
    FString Key,
    OvrPlatform_CloudStorage_Load_Delegate&& Delegate);

/**
 * Loads all the metadata for the saves in the specified bucket, including conflicts.
 * @param Bucket - The name of the storage bucket.
 */
typedef TSharedPtr<FOvrCloudStorageMetadataPages> FOvrCloudStorageMetadataArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_CloudStorage_LoadBucketMetadata_Delegate, bool, FOvrCloudStorageMetadataArrayPtr, FString);

void OvrPlatform_CloudStorage_LoadBucketMetadata(
    UGameInstance* GameInstance,
    FString Bucket,
    OvrPlatform_CloudStorage_LoadBucketMetadata_Delegate&& Delegate);

/**
 * Loads the metadata for this bucket-key combination that need to be manually resolved.
 * @param Bucket - The name of the storage bucket
 * @param Key - The key for this saved data.
 */
typedef TSharedPtr<FOvrCloudStorageConflictMetadata> FOvrCloudStorageConflictMetadataPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_CloudStorage_LoadConflictMetadata_Delegate, bool, FOvrCloudStorageConflictMetadataPtr, FString);

void OvrPlatform_CloudStorage_LoadConflictMetadata(
    UGameInstance* GameInstance,
    FString Bucket,
    FString Key,
    OvrPlatform_CloudStorage_LoadConflictMetadata_Delegate&& Delegate);

/** Loads the data specified by the storage handle. */
typedef TSharedPtr<FOvrCloudStorageData> FOvrCloudStorageDataPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_CloudStorage_LoadHandle_Delegate, bool, FOvrCloudStorageDataPtr, FString);

void OvrPlatform_CloudStorage_LoadHandle(
    UGameInstance* GameInstance,
    FString Handle,
    OvrPlatform_CloudStorage_LoadHandle_Delegate&& Delegate);

/**
 * load the metadata for the specified key
 * @param Bucket - The name of the storage bucket.
 * @param Key - The name for this saved data.
 */
typedef TSharedPtr<FOvrCloudStorageMetadata> FOvrCloudStorageMetadataPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_CloudStorage_LoadMetadata_Delegate, bool, FOvrCloudStorageMetadataPtr, FString);

void OvrPlatform_CloudStorage_LoadMetadata(
    UGameInstance* GameInstance,
    FString Bucket,
    FString Key,
    OvrPlatform_CloudStorage_LoadMetadata_Delegate&& Delegate);

/**
 * Selects the local save for manual conflict resolution.
 * @param Bucket - The name of the storage bucket.
 * @param Key - The name for this saved data.
 * @param RemoteHandle - The handle of the remote that the local file was resolved against.
 */
typedef TSharedPtr<FOvrCloudStorageUpdateResponse> FOvrCloudStorageUpdateResponsePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_CloudStorage_ResolveKeepLocal_Delegate, bool, FOvrCloudStorageUpdateResponsePtr, FString);

void OvrPlatform_CloudStorage_ResolveKeepLocal(
    UGameInstance* GameInstance,
    FString Bucket,
    FString Key,
    FString RemoteHandle,
    OvrPlatform_CloudStorage_ResolveKeepLocal_Delegate&& Delegate);

/**
 * Selects the remote save for manual conflict resolution.
 * @param Bucket - The name of the storage bucket.
 * @param Key - The name for this saved data.
 * @param RemoteHandle - The handle of the remote.
 */
typedef TSharedPtr<FOvrCloudStorageUpdateResponse> FOvrCloudStorageUpdateResponsePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_CloudStorage_ResolveKeepRemote_Delegate, bool, FOvrCloudStorageUpdateResponsePtr, FString);

void OvrPlatform_CloudStorage_ResolveKeepRemote(
    UGameInstance* GameInstance,
    FString Bucket,
    FString Key,
    FString RemoteHandle,
    OvrPlatform_CloudStorage_ResolveKeepRemote_Delegate&& Delegate);

/**
 * Note: Cloud Storage is only available for Rift apps.
 * 
 * 
 * Send a save data buffer to the platform. CloudStorage_Save() passes a pointer
 * to your data in an async call. You need to maintain the save data until you receive the
 * message indicating that the save was successful.
 * 
 * 
 * 
 * If the data is destroyed or modified prior to receiving that message the data will not be saved.
 * @param Bucket - The name of the storage bucket.
 * @param Key - The name for this saved data.
 * @param Data - Start of the data block.
 * @param DataSize - Size of the data block.
 * @param Counter - Optional. Counter used for user data or auto-deconfliction.
 * @param ExtraData - Optional. String data that isn't used by the platform.
 */
typedef TSharedPtr<FOvrCloudStorageUpdateResponse> FOvrCloudStorageUpdateResponsePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_CloudStorage_Save_Delegate, bool, FOvrCloudStorageUpdateResponsePtr, FString);

void OvrPlatform_CloudStorage_Save(
    UGameInstance* GameInstance,
    FString Bucket,
    FString Key,
    TArray<uint8> Data,
    int64 Counter,
    FString ExtraData,
    OvrPlatform_CloudStorage_Save_Delegate&& Delegate);

// ----------------------------------------------------------------------
// CloudStorage2

/** Get the directory path for the current user/app pair that will be used during cloud storage synchronization */
typedef TSharedPtr<FString> FStringPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_CloudStorage2_GetUserDirectoryPath_Delegate, bool, FStringPtr, FString);

void OvrPlatform_CloudStorage2_GetUserDirectoryPath(
    UGameInstance* GameInstance,
    OvrPlatform_CloudStorage2_GetUserDirectoryPath_Delegate&& Delegate);

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

/** Set group presence for running app */
DECLARE_DELEGATE_TwoParams(OvrPlatform_GroupPresence_Set_Delegate, bool, FString);

void OvrPlatform_GroupPresence_Set(
    UGameInstance* GameInstance,
    FOvrGroupPresenceOptions GroupPresenceOptions,
    OvrPlatform_GroupPresence_Set_Delegate&& Delegate);

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
 * @param Filter - Allows you to restrict the returned values by friends.
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
// Matchmaking

/**
 * DEPRECATED. Use Matchmaking_Browse2().
 * @param Pool - A BROWSE type matchmaking pool.
 * @param CustomQueryData - Optional. Custom query data.
 */
typedef TSharedPtr<FOvrMatchmakingBrowseResult> FOvrMatchmakingBrowseResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Matchmaking_Browse_Delegate, bool, FOvrMatchmakingBrowseResultPtr, FString);

[[deprecated("Use Matchmaking_Browse2().")]]
void OvrPlatform_Matchmaking_Browse(
    UGameInstance* GameInstance,
    FString Pool,
    FOvrMatchmakingCustomQueryData CustomQueryData,
    OvrPlatform_Matchmaking_Browse_Delegate&& Delegate);

/**
 * Modes: BROWSE
 * 
 * See overview documentation above.
 * 
 * 
 * Return a list of matchmaking rooms in the current pool filtered by skill and
 * ping (if enabled). This also enqueues the user in the matchmaking queue.
 * When the user has made a selection, call Room_Join2() on one of
 * the rooms that was returned. If the user stops browsing, call Matchmaking_Cancel2().
 * 
 * 
 * 
 * 
 * In addition to the list of rooms, enqueue results are also returned.  Call
 * field FOvrMatchmakingBrowseResult::EnqueueResult to obtain them.  See
 * OVR_MatchmakingEnqueueResult.h for details.
 * @param Pool - A BROWSE type matchmaking pool.
 * @param MatchmakingOptions - Additional matchmaking configuration for this request. Optional.
 */
typedef TSharedPtr<FOvrMatchmakingBrowseResult> FOvrMatchmakingBrowseResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Matchmaking_Browse2_Delegate, bool, FOvrMatchmakingBrowseResultPtr, FString);

void OvrPlatform_Matchmaking_Browse2(
    UGameInstance* GameInstance,
    FString Pool,
    FOvrMatchmakingOptions MatchmakingOptions,
    OvrPlatform_Matchmaking_Browse2_Delegate&& Delegate);

/**
 * DEPRECATED. Use Matchmaking_Cancel2().
 * @param Pool - The pool in question.
 * @param RequestHash - Used to find your entry in a queue.
 */
DECLARE_DELEGATE_TwoParams(OvrPlatform_Matchmaking_Cancel_Delegate, bool, FString);

[[deprecated("Use Matchmaking_Cancel2().")]]
void OvrPlatform_Matchmaking_Cancel(
    UGameInstance* GameInstance,
    FString Pool,
    FString RequestHash,
    OvrPlatform_Matchmaking_Cancel_Delegate&& Delegate);

/**
 * Modes: QUICKMATCH, BROWSE
 * 
 * 
 *   Makes a best effort to cancel a previous Enqueue request before a match occurs.  Typically triggered
 *   when a user gives up waiting.  For BROWSE mode, call this when a user gives up looking through the room list or when the
 *   host of a room wants to stop receiving new users.
 *   If you don't cancel but the user goes offline, the user/room will be timed out of the queue within 30 seconds.
 */
DECLARE_DELEGATE_TwoParams(OvrPlatform_Matchmaking_Cancel2_Delegate, bool, FString);

void OvrPlatform_Matchmaking_Cancel2(
    UGameInstance* GameInstance,
    OvrPlatform_Matchmaking_Cancel2_Delegate&& Delegate);

/**
 * DEPRECATED. Use Matchmaking_CreateAndEnqueueRoom2().
 * @param Pool - The matchmaking pool to use, which is defined for the app.
 * @param MaxUsers - Overrides the Max Users value, which is configured in pool settings of the Developer Dashboard.
 * @param SubscribeToUpdates - If true, sends a message with type FOvrNotification_Room_RoomUpdate when the room data changes, such as when users join or leave.
 * @param CustomQueryData - Optional.  See "Custom criteria" section above.
 */
typedef TSharedPtr<FOvrMatchmakingEnqueueResultAndRoom> FOvrMatchmakingEnqueueResultAndRoomPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Matchmaking_CreateAndEnqueueRoom_Delegate, bool, FOvrMatchmakingEnqueueResultAndRoomPtr, FString);

[[deprecated("Use Matchmaking_CreateAndEnqueueRoom2().")]]
void OvrPlatform_Matchmaking_CreateAndEnqueueRoom(
    UGameInstance* GameInstance,
    FString Pool,
    int32 MaxUsers,
    bool SubscribeToUpdates,
    FOvrMatchmakingCustomQueryData CustomQueryData,
    OvrPlatform_Matchmaking_CreateAndEnqueueRoom_Delegate&& Delegate);

/**
 * Modes: BROWSE, QUICKMATCH (Advanced; Can Users Create Rooms = true)
 * 
 * See overview documentation above.
 * 
 * Create a matchmaking room, join it, and enqueue
 * it. This is the preferred method. But, if you do not wish to automatically
 * enqueue the room, you can call CreateRoom2 instead.
 * 
 * 
 * Visit https://dashboard.oculus.com/application/[YOUR_APP_ID]/matchmaking
 * to set up pools and queries
 * @param Pool - The matchmaking pool to use, which is defined for the app.
 * @param MatchmakingOptions - Additional matchmaking configuration for this request. Optional.
 */
typedef TSharedPtr<FOvrMatchmakingEnqueueResultAndRoom> FOvrMatchmakingEnqueueResultAndRoomPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Matchmaking_CreateAndEnqueueRoom2_Delegate, bool, FOvrMatchmakingEnqueueResultAndRoomPtr, FString);

void OvrPlatform_Matchmaking_CreateAndEnqueueRoom2(
    UGameInstance* GameInstance,
    FString Pool,
    FOvrMatchmakingOptions MatchmakingOptions,
    OvrPlatform_Matchmaking_CreateAndEnqueueRoom2_Delegate&& Delegate);

/**
 * DEPRECATED. Use Matchmaking_CreateRoom2().
 * @param Pool - The matchmaking pool to use, which is defined for the app.
 * @param MaxUsers - Overrides the Max Users value, which is configured in pool settings of the Developer Dashboard.
 * @param SubscribeToUpdates - If true, sends a message with type FOvrNotification_Room_RoomUpdate when room data changes, such as when users join or leave.
 */
typedef TSharedPtr<FOvrRoom> FOvrRoomPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Matchmaking_CreateRoom_Delegate, bool, FOvrRoomPtr, FString);

[[deprecated("Use Matchmaking_CreateRoom2().")]]
void OvrPlatform_Matchmaking_CreateRoom(
    UGameInstance* GameInstance,
    FString Pool,
    int32 MaxUsers,
    bool SubscribeToUpdates,
    OvrPlatform_Matchmaking_CreateRoom_Delegate&& Delegate);

/**
 * Create a matchmaking room and join it, but do
 * not enqueue the room. After creation, you can call EnqueueRoom2. However,
 * Oculus recommends using CreateAndEnqueueRoom2 instead.
 * 
 * Modes: BROWSE, QUICKMATCH (Advanced; Can Users Create Rooms = true)
 * 
 * Create a matchmaking room and join it, but do
 * not enqueue the room. After creation, you can call EnqueueRoom. Consider
 * using CreateAndEnqueueRoom instead.
 * 
 * 
 * Visit https://dashboard.oculus.com/application/[YOUR_APP_ID]/matchmaking
 * to set up pools and queries
 * @param Pool - The matchmaking pool to use, which is defined for the app.
 * @param MatchmakingOptions - Additional matchmaking configuration for this request. Optional.
 */
typedef TSharedPtr<FOvrRoom> FOvrRoomPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Matchmaking_CreateRoom2_Delegate, bool, FOvrRoomPtr, FString);

void OvrPlatform_Matchmaking_CreateRoom2(
    UGameInstance* GameInstance,
    FString Pool,
    FOvrMatchmakingOptions MatchmakingOptions,
    OvrPlatform_Matchmaking_CreateRoom2_Delegate&& Delegate);

/**
 * DEPRECATED. Use Matchmaking_Enqueue2().
 * @param Pool - The pool to enqueue in.
 * @param CustomQueryData - Optional.  See "Custom criteria" section above.
 */
typedef TSharedPtr<FOvrMatchmakingEnqueueResult> FOvrMatchmakingEnqueueResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Matchmaking_Enqueue_Delegate, bool, FOvrMatchmakingEnqueueResultPtr, FString);

[[deprecated("Use Matchmaking_Enqueue2().")]]
void OvrPlatform_Matchmaking_Enqueue(
    UGameInstance* GameInstance,
    FString Pool,
    FOvrMatchmakingCustomQueryData CustomQueryData,
    OvrPlatform_Matchmaking_Enqueue_Delegate&& Delegate);

/**
 * Modes: QUICKMATCH
 * 
 * See overview documentation above.
 * 
 * 
 * Enqueue yourself to await an available matchmaking room.  The platform returns a FOvrNotification_Matchmaking_MatchFound
 * message when a match is found.  Call Room_Join2() on the returned room.
 * The response contains useful information to display to the user to set expectations for
 * how long it will take to get a match.
 * 
 * 
 * If the user stops waiting, call Matchmaking_Cancel2().
 * @param Pool - The pool to enqueue in.
 * @param MatchmakingOptions - Additional matchmaking configuration for this request. Optional.
 */
typedef TSharedPtr<FOvrMatchmakingEnqueueResult> FOvrMatchmakingEnqueueResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Matchmaking_Enqueue2_Delegate, bool, FOvrMatchmakingEnqueueResultPtr, FString);

void OvrPlatform_Matchmaking_Enqueue2(
    UGameInstance* GameInstance,
    FString Pool,
    FOvrMatchmakingOptions MatchmakingOptions,
    OvrPlatform_Matchmaking_Enqueue2_Delegate&& Delegate);

/**
 * DEPRECATED. Please use Matchmaking_EnqueueRoom2() instead.
 * @param RoomID - Returned either from FOvrNotification_Matchmaking_MatchFound or from Matchmaking_CreateRoom().
 * @param CustomQueryData - Optional.  See the "Custom criteria" section above.
 */
typedef TSharedPtr<FOvrMatchmakingEnqueueResult> FOvrMatchmakingEnqueueResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Matchmaking_EnqueueRoom_Delegate, bool, FOvrMatchmakingEnqueueResultPtr, FString);

[[deprecated("Please use Matchmaking_EnqueueRoom2() instead.")]]
void OvrPlatform_Matchmaking_EnqueueRoom(
    UGameInstance* GameInstance,
    FOvrId RoomID,
    FOvrMatchmakingCustomQueryData CustomQueryData,
    OvrPlatform_Matchmaking_EnqueueRoom_Delegate&& Delegate);

/**
 * Modes: BROWSE (for Rooms only), ROOM
 * 
 * 
 * See the overview documentation above.
 * Enqueue yourself to await an available matchmaking room.  FOvrNotification_Matchmaking_MatchFound
 * gets enqueued when a match is found.
 * 
 * 
 * 
 * 
 * The response contains useful information to display to the user to set expectations for
 * how long it will take to get a match.
 * 
 * 
 * If the user stops waiting, call Matchmaking_Cancel2().
 * @param RoomID - Returned either from FOvrNotification_Matchmaking_MatchFound or from Matchmaking_CreateRoom().
 * @param MatchmakingOptions - Additional matchmaking configuration for this request. Optional.
 */
typedef TSharedPtr<FOvrMatchmakingEnqueueResult> FOvrMatchmakingEnqueueResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Matchmaking_EnqueueRoom2_Delegate, bool, FOvrMatchmakingEnqueueResultPtr, FString);

void OvrPlatform_Matchmaking_EnqueueRoom2(
    UGameInstance* GameInstance,
    FOvrId RoomID,
    FOvrMatchmakingOptions MatchmakingOptions,
    OvrPlatform_Matchmaking_EnqueueRoom2_Delegate&& Delegate);

/**
 * Modes: QUICKMATCH, BROWSE
 * 
 * Used to debug the state of the current matchmaking pool queue.  This is not intended to be used in production.
 */
typedef TSharedPtr<FOvrMatchmakingAdminSnapshot> FOvrMatchmakingAdminSnapshotPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Matchmaking_GetAdminSnapshot_Delegate, bool, FOvrMatchmakingAdminSnapshotPtr, FString);

void OvrPlatform_Matchmaking_GetAdminSnapshot(
    UGameInstance* GameInstance,
    OvrPlatform_Matchmaking_GetAdminSnapshot_Delegate&& Delegate);

/**
 * Modes: QUICKMATCH, BROWSE
 * 
 * Gets the matchmaking stats for the current user
 * 
 * 
 *   Given a pool it will look up the current user's wins, loss, draws and skill level.  The skill level return will be between
 *   1 and maxLevel.  The approach will dictate how should the skill level rise toward the max level.
 * @param Pool - The pool to look in
 * @param MaxLevel - The maximum skill level achievable
 * @param Approach - The growth function of how the skill levels should approach to the max level.  TRAILING is recommended for displaying to users
 */
typedef TSharedPtr<FOvrMatchmakingStats> FOvrMatchmakingStatsPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Matchmaking_GetStats_Delegate, bool, FOvrMatchmakingStatsPtr, FString);

void OvrPlatform_Matchmaking_GetStats(
    UGameInstance* GameInstance,
    FString Pool,
    int32 MaxLevel,
    EOvrMatchmakingStatApproach Approach,
    OvrPlatform_Matchmaking_GetStats_Delegate&& Delegate);

/**
 * DEPRECATED. Use Room_Join2().
 * @param RoomID - ID of a room previously returned from FOvrNotification_Matchmaking_MatchFound or Matchmaking_Browse().
 * @param SubscribeToUpdates - If true, sends a message with type FOvrNotification_Room_RoomUpdate when room data changes, such as when users join or leave.
 */
typedef TSharedPtr<FOvrRoom> FOvrRoomPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Matchmaking_JoinRoom_Delegate, bool, FOvrRoomPtr, FString);

[[deprecated("Use Room_Join2().")]]
void OvrPlatform_Matchmaking_JoinRoom(
    UGameInstance* GameInstance,
    FOvrId RoomID,
    bool SubscribeToUpdates,
    OvrPlatform_Matchmaking_JoinRoom_Delegate&& Delegate);

/**
 * Modes: QUICKMATCH, BROWSE (+ Skill Pool)
 * 
 * See the overview documentation above.
 * 
 * 
 * Call this after calling Matchmaking_StartMatch() to begin a rated skill match and after the match finishes.
 * The service will record the result and update the skills of all players involved, based on the results.
 * This method is insecure because, as a client API, it is susceptible to tampering and therefore cheating
 * to manipulate skill ratings.
 * @param RoomID - The room ID
 * @param Data - key value pairs
 */
DECLARE_DELEGATE_TwoParams(OvrPlatform_Matchmaking_ReportResultInsecure_Delegate, bool, FString);

void OvrPlatform_Matchmaking_ReportResultInsecure(
    UGameInstance* GameInstance,
    FOvrId RoomID,
    TMap<FString, FOvrVariant> Data,
    OvrPlatform_Matchmaking_ReportResultInsecure_Delegate&& Delegate);

/**
 * Modes: QUICKMATCH, BROWSE (+ Skill Pool)
 * 
 * For pools with skill-based matching.  See overview documentation above.
 * 
 * Call after calling Room_Join2() when the players are present to begin a rated match for which you plan to report the results
 * (using Matchmaking_ReportResultInsecure()).
 */
DECLARE_DELEGATE_TwoParams(OvrPlatform_Matchmaking_StartMatch_Delegate, bool, FString);

void OvrPlatform_Matchmaking_StartMatch(
    UGameInstance* GameInstance,
    FOvrId RoomID,
    OvrPlatform_Matchmaking_StartMatch_Delegate&& Delegate);

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
 * Retrieve a list of all pending room invites for your application (for example, notifications
 * that may have been sent before the user launched your game).  You can also get push
 * notifications with FOvrNotification_Room_InviteReceived.
 */
typedef TSharedPtr<FOvrRoomInviteNotificationPages> FOvrRoomInviteNotificationArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Notification_GetRoomInvites_Delegate, bool, FOvrRoomInviteNotificationArrayPtr, FString);

void OvrPlatform_Notification_GetRoomInvites(
    UGameInstance* GameInstance,
    OvrPlatform_Notification_GetRoomInvites_Delegate&& Delegate);

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
// Room

/**
 * DEPRECATED. Use Room_CreateAndJoinPrivate2().
 * @param JoinPolicy - Specifies who can join the room without an invite.
 * @param MaxUsers - The maximum number of users allowed in the room, including the creator.
 * @param SubscribeToUpdates - If true, sends a message with type FOvrNotification_Room_RoomUpdate when room data changes, such as when users join or leave.
 */
typedef TSharedPtr<FOvrRoom> FOvrRoomPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Room_CreateAndJoinPrivate_Delegate, bool, FOvrRoomPtr, FString);

[[deprecated("Use Room_CreateAndJoinPrivate2().")]]
void OvrPlatform_Room_CreateAndJoinPrivate(
    UGameInstance* GameInstance,
    EOvrRoomJoinPolicy JoinPolicy,
    int32 MaxUsers,
    bool SubscribeToUpdates,
    OvrPlatform_Room_CreateAndJoinPrivate_Delegate&& Delegate);

/**
 * Creates a new private (client controlled) room and adds the caller to it. This type of room is good
 * for matches where the user wants to play with friends, as they're primarially discoverable by examining
 * which rooms your friends are in.
 * @param JoinPolicy - Specifies who can join the room without an invite.
 * @param MaxUsers - The maximum number of users allowed in the room, including the creator.
 * @param RoomOptions - Additional room configuration for this request. Optional.
 */
typedef TSharedPtr<FOvrRoom> FOvrRoomPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Room_CreateAndJoinPrivate2_Delegate, bool, FOvrRoomPtr, FString);

void OvrPlatform_Room_CreateAndJoinPrivate2(
    UGameInstance* GameInstance,
    EOvrRoomJoinPolicy JoinPolicy,
    int32 MaxUsers,
    FOvrRoomOptions RoomOptions,
    OvrPlatform_Room_CreateAndJoinPrivate2_Delegate&& Delegate);

/**
 * Allows arbitrary rooms for the application to be loaded.
 * @param RoomID - The room to load.
 */
typedef TSharedPtr<FOvrRoom> FOvrRoomPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Room_Get_Delegate, bool, FOvrRoomPtr, FString);

void OvrPlatform_Room_Get(
    UGameInstance* GameInstance,
    FOvrId RoomID,
    OvrPlatform_Room_Get_Delegate&& Delegate);

/**
 * Easy loading of the room you're currently in. If you don't want live updates
 * on your current room (by using subscribeToUpdates), you can use this to refresh the data.
 */
typedef TSharedPtr<FOvrRoom> FOvrRoomPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Room_GetCurrent_Delegate, bool, FOvrRoomPtr, FString);

void OvrPlatform_Room_GetCurrent(
    UGameInstance* GameInstance,
    OvrPlatform_Room_GetCurrent_Delegate&& Delegate);

/**
 * Allows the current room for a given user to be loaded. Remember that the user's privacy settings
 * may not allow their room to be loaded. Because of this, it's often possible to load the users in
 * a room, but not to take those users and load their room.
 * @param UserID - ID of the user for which to load the room.
 */
typedef TSharedPtr<FOvrRoom> FOvrRoomPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Room_GetCurrentForUser_Delegate, bool, FOvrRoomPtr, FString);

void OvrPlatform_Room_GetCurrentForUser(
    UGameInstance* GameInstance,
    FOvrId UserID,
    OvrPlatform_Room_GetCurrentForUser_Delegate&& Delegate);

/** DEPRECATED. Use Room_GetInvitableUsers2(). */
typedef TSharedPtr<FOvrUserPages> FOvrUserArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Room_GetInvitableUsers_Delegate, bool, FOvrUserArrayPtr, FString);

[[deprecated("Use Room_GetInvitableUsers2().")]]
void OvrPlatform_Room_GetInvitableUsers(
    UGameInstance* GameInstance,
    OvrPlatform_Room_GetInvitableUsers_Delegate&& Delegate);

/**
 * Loads a list of users you can invite to a room. These are pulled from your
 * friends list and recently met lists and filtered for relevance and interest. If the room cannot be
 * joined, this list will be empty. By default, the invitable users returned
 * will be for the user's current room.
 * 
 * If your application grouping was created after September 9 2017, recently met users will be included by default.
 * If your application grouping was created before then, you can go to edit the setting in the "Rooms and Matchmaking"
 * section of Platform Services at dashboard.oculus.com
 * 
 * Customization can be done via RoomOptions. Create this object with FOvrRoomOptions.
 * The params that could be used are:
 * 
 * 1. FOvrRoomOptions::RoomId- will return the invitable users for this room (instead of the current room).
 * 
 * 2. FOvrRoomOptions::Ordering - returns the list of users in the provided ordering (see UserOrdering enum).
 * 
 * 3. FOvrRoomOptions::RecentlyMetTimeWindow - how long long ago should we include users you've recently met in
 * the results?
 * 
 * 4. FOvrRoomOptions::MaxUserResults - we will limit the number of results returned.
 * By default, the number is unlimited, but the server may choose to limit results for performance reasons.
 * 
 * 5. FOvrRoomOptions::ExcludeRecentlyMet - Don't include users recently in rooms with this user in the result.
 * Also, see the above comment.
 * 
 * Example custom C++ usage:
 * 
 * <codeblock>
 * auto roomOptions = ovr_RoomOptions_Create();
 * ovr_RoomOptions_SetOrdering(roomOptions, ovrUserOrdering_PresenceAlphabetical);
 * ovr_RoomOptions_SetRoomId(roomOptions, roomID);
 * ovr_Room_GetInvitableUsers2(roomOptions);
 * ovr_RoomOptions_Destroy(roomOptions);
 * </codeblock>
 * @param RoomOptions - Additional configuration for this request. Optional.
 */
typedef TSharedPtr<FOvrUserPages> FOvrUserArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Room_GetInvitableUsers2_Delegate, bool, FOvrUserArrayPtr, FString);

void OvrPlatform_Room_GetInvitableUsers2(
    UGameInstance* GameInstance,
    FOvrRoomOptions RoomOptions,
    OvrPlatform_Room_GetInvitableUsers2_Delegate&& Delegate);

/** Fetches the list of moderated rooms created for the application. */
typedef TSharedPtr<FOvrRoomPages> FOvrRoomArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Room_GetModeratedRooms_Delegate, bool, FOvrRoomArrayPtr, FString);

void OvrPlatform_Room_GetModeratedRooms(
    UGameInstance* GameInstance,
    OvrPlatform_Room_GetModeratedRooms_Delegate&& Delegate);

/**
 * Invites a user to the specified room.  They will receive a notification via
 * FOvrNotification_Room_InviteReceived if they are in your game, and/or they can poll for room invites
 * using Notification_GetRoomInvites().
 * @param RoomID - The ID of your current room.
 * @param InviteToken - A user's invite token, returned by Room_GetInvitableUsers().
 */
typedef TSharedPtr<FOvrRoom> FOvrRoomPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Room_InviteUser_Delegate, bool, FOvrRoomPtr, FString);

void OvrPlatform_Room_InviteUser(
    UGameInstance* GameInstance,
    FOvrId RoomID,
    FString InviteToken,
    OvrPlatform_Room_InviteUser_Delegate&& Delegate);

/**
 * Joins the target room (leaving the one you're currently in).
 * @param RoomID - The room to join.
 * @param SubscribeToUpdates - If true, sends a message with type FOvrNotification_Room_RoomUpdate when room data changes, such as when users join or leave.
 */
typedef TSharedPtr<FOvrRoom> FOvrRoomPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Room_Join_Delegate, bool, FOvrRoomPtr, FString);

void OvrPlatform_Room_Join(
    UGameInstance* GameInstance,
    FOvrId RoomID,
    bool SubscribeToUpdates,
    OvrPlatform_Room_Join_Delegate&& Delegate);

/**
 * Joins the target room (leaving the one you're currently in).
 * @param RoomID - The room to join.
 * @param RoomOptions - Additional room configuration for this request. Optional.
 */
typedef TSharedPtr<FOvrRoom> FOvrRoomPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Room_Join2_Delegate, bool, FOvrRoomPtr, FString);

void OvrPlatform_Room_Join2(
    UGameInstance* GameInstance,
    FOvrId RoomID,
    FOvrRoomOptions RoomOptions,
    OvrPlatform_Room_Join2_Delegate&& Delegate);

/**
 * Allows the room owner to kick a user out of the current room.
 * @param RoomID - The room that you currently own (check field FOvrRoom::Owner).
 * @param UserID - The user to be kicked (cannot be yourself).
 * @param KickDurationSeconds - Length of the ban, in seconds.
 */
typedef TSharedPtr<FOvrRoom> FOvrRoomPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Room_KickUser_Delegate, bool, FOvrRoomPtr, FString);

void OvrPlatform_Room_KickUser(
    UGameInstance* GameInstance,
    FOvrId RoomID,
    FOvrId UserID,
    int32 KickDurationSeconds,
    OvrPlatform_Room_KickUser_Delegate&& Delegate);

/**
 *  Launch the invitable user flow to invite to the logged in user's current
 * room. This is intended to be a nice shortcut for developers not wanting
 * to build out their own Invite UI although it has the same rules as if
 * you build it yourself. 
 */
DECLARE_DELEGATE_TwoParams(OvrPlatform_Room_LaunchInvitableUserFlow_Delegate, bool, FString);

void OvrPlatform_Room_LaunchInvitableUserFlow(
    UGameInstance* GameInstance,
    FOvrId RoomID,
    OvrPlatform_Room_LaunchInvitableUserFlow_Delegate&& Delegate);

/**
 * Removes you from your current room.  Returns the solo room you are now in if it succeeds
 * @param RoomID - The room you're currently in.
 */
typedef TSharedPtr<FOvrRoom> FOvrRoomPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Room_Leave_Delegate, bool, FOvrRoomPtr, FString);

void OvrPlatform_Room_Leave(
    UGameInstance* GameInstance,
    FOvrId RoomID,
    OvrPlatform_Room_Leave_Delegate&& Delegate);

/**
 * Allows the room owner to set the description of their room.
 * @param RoomID - The room that you currently own (check field FOvrRoom::Owner).
 * @param Description - The new name of the room.
 */
typedef TSharedPtr<FOvrRoom> FOvrRoomPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Room_SetDescription_Delegate, bool, FOvrRoomPtr, FString);

void OvrPlatform_Room_SetDescription(
    UGameInstance* GameInstance,
    FOvrId RoomID,
    FString Description,
    OvrPlatform_Room_SetDescription_Delegate&& Delegate);

/**
 * Allows the room owner to update the data store (set of key value pairs) of their room.
 * 
 * NOTE: Room datastores only allow string values. If you provide int or double values, this returns an error.
 * @param RoomID - The room that you currently own (check field FOvrRoom::Owner).
 * @param Data - The key/value pairs to add or update; null values clear a given key.
 */
typedef TSharedPtr<FOvrRoom> FOvrRoomPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Room_UpdateDataStore_Delegate, bool, FOvrRoomPtr, FString);

void OvrPlatform_Room_UpdateDataStore(
    UGameInstance* GameInstance,
    FOvrId RoomID,
    TMap<FString, FOvrVariant> Data,
    OvrPlatform_Room_UpdateDataStore_Delegate&& Delegate);

/**
 * Disallow new members from being able to join the room. This will prevent
 * joins from Room_Join(), invites, 'Join From Home', etc.
 * Users that are in the room at the time of lockdown WILL be able to rejoin.
 * @param RoomID - The room whose membership you want to lock or unlock.
 * @param MembershipLockStatus - The new LockStatus for the room
 */
typedef TSharedPtr<FOvrRoom> FOvrRoomPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Room_UpdateMembershipLockStatus_Delegate, bool, FOvrRoomPtr, FString);

void OvrPlatform_Room_UpdateMembershipLockStatus(
    UGameInstance* GameInstance,
    FOvrId RoomID,
    EOvrRoomMembershipLockStatus MembershipLockStatus,
    OvrPlatform_Room_UpdateMembershipLockStatus_Delegate&& Delegate);

/**
 * Allows the room owner to transfer ownership to someone else.
 * @param RoomID - The room that the user owns (check field FOvrRoom::Owner).
 * @param UserID - The new user to make an owner; the user must be in the room.
 */
DECLARE_DELEGATE_TwoParams(OvrPlatform_Room_UpdateOwner_Delegate, bool, FString);

void OvrPlatform_Room_UpdateOwner(
    UGameInstance* GameInstance,
    FOvrId RoomID,
    FOvrId UserID,
    OvrPlatform_Room_UpdateOwner_Delegate&& Delegate);

/**
 * Sets the join policy of the user's private room.
 * @param RoomID - The room ID that the user owns (check field FOvrRoom::Owner).
 * @param NewJoinPolicy - The new join policy for the room.
 */
typedef TSharedPtr<FOvrRoom> FOvrRoomPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Room_UpdatePrivateRoomJoinPolicy_Delegate, bool, FOvrRoomPtr, FString);

void OvrPlatform_Room_UpdatePrivateRoomJoinPolicy(
    UGameInstance* GameInstance,
    FOvrId RoomID,
    EOvrRoomJoinPolicy NewJoinPolicy,
    OvrPlatform_Room_UpdatePrivateRoomJoinPolicy_Delegate&& Delegate);

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

/** Retrieve a list of the logged in user's friends. */
typedef TSharedPtr<FOvrUserPages> FOvrUserArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_User_GetLoggedInUserFriends_Delegate, bool, FOvrUserArrayPtr, FString);

void OvrPlatform_User_GetLoggedInUserFriends(
    UGameInstance* GameInstance,
    OvrPlatform_User_GetLoggedInUserFriends_Delegate&& Delegate);

/**
 * Retrieve a list of the logged in user's friends and any rooms they
 * might be in.
 */
typedef TSharedPtr<FOvrUserAndRoomPages> FOvrUserAndRoomArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_User_GetLoggedInUserFriendsAndRooms_Delegate, bool, FOvrUserAndRoomArrayPtr, FString);

void OvrPlatform_User_GetLoggedInUserFriendsAndRooms(
    UGameInstance* GameInstance,
    OvrPlatform_User_GetLoggedInUserFriendsAndRooms_Delegate&& Delegate);

/**
 * Returns a list of users that the logged in user was in a room with recently, sorted by
 * relevance, along with any rooms they might be in.  All you need to do to use this method is to
 * use our Rooms API, and we will track the number of times users are together, their most recent
 * encounter, and the amount of time they spend together.
 * 
 * Customization can be done via UserOptions. Create this object with FOvrUserOptions.
 * The params that could be used are:
 * 
 * 1. FOvrUserOptions::TimeWindow - how recently should the users have played?  The default is
 * EOvrTimeWindow::ThirtyDays.
 * 
 * 2. FOvrUserOptions::MaxUsers - we will limit the number of results returned.
 * By default, the number is unlimited,
 * but the server may choose to limit results for performance reasons.
 * @param UserOptions - Additional configuration for this request. Optional.
 */
typedef TSharedPtr<FOvrUserAndRoomPages> FOvrUserAndRoomArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_User_GetLoggedInUserRecentlyMetUsersAndRooms_Delegate, bool, FOvrUserAndRoomArrayPtr, FString);

void OvrPlatform_User_GetLoggedInUserRecentlyMetUsersAndRooms(
    UGameInstance* GameInstance,
    FOvrUserOptions UserOptions,
    OvrPlatform_User_GetLoggedInUserRecentlyMetUsersAndRooms_Delegate&& Delegate);

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
 * Launch the flow for sending a friend request to a user.
 * @param UserID - User ID of user to send a friend request to
 */
typedef TSharedPtr<FOvrLaunchFriendRequestFlowResult> FOvrLaunchFriendRequestFlowResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_User_LaunchFriendRequestFlow_Delegate, bool, FOvrLaunchFriendRequestFlowResultPtr, FString);

void OvrPlatform_User_LaunchFriendRequestFlow(
    UGameInstance* GameInstance,
    FOvrId UserID,
    OvrPlatform_User_LaunchFriendRequestFlow_Delegate&& Delegate);

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

