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
#include "Kismet/BlueprintFunctionLibrary.h"

#include <functional>

#include "OVRPlatformModels.h"
#include "OVRPlatformOptions.h"
#include "OVRPlatformRequestsSupport.h"

#include "OVRPlatformRequests.generated.h"

UCLASS()
class OVRPLATFORM_API UOvrRequestsBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    // ----------------------------------------------------------------------
    // Achievements

    /**
     * Add 'count' to the achievement with the given name. This must be a COUNT achievement.
     * The largest number that is supported by this method is the max value of a signed 64-bit integer.
     * If the number is larger than that, it is clamped to that max value before being passed to
     * the servers.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Achievements")
    static void Achievements_AddCount(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString Name,
        int64 Count,
        FOvrAchievementUpdate& AchievementUpdate,
        FString& ErrorMsg);

    /**
     * Unlock fields of a BITFIELD achievement.
     * @param Name - The name of the achievement to unlock
     * @param Fields - A string containing either '0' or '1' characters. Every '1' will unlock the field in the corresponding position.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Achievements")
    static void Achievements_AddFields(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString Name,
        FString Fields,
        FOvrAchievementUpdate& AchievementUpdate,
        FString& ErrorMsg);

    /** Request all achievement definitions for the app. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Achievements")
    static void Achievements_GetAllDefinitions(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrAchievementDefinitionPages& AchievementDefinitionPages,
        FString& ErrorMsg);

    /** Request the progress for the user on all achievements in the app. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Achievements")
    static void Achievements_GetAllProgress(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrAchievementProgressPages& AchievementProgressPages,
        FString& ErrorMsg);

    /** Request the achievement definitions that match the specified names. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Achievements")
    static void Achievements_GetDefinitionsByName(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        TArray<FString> Names,
        FOvrAchievementDefinitionPages& AchievementDefinitionPages,
        FString& ErrorMsg);

    /** Request the user's progress on the specified achievements. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Achievements")
    static void Achievements_GetProgressByName(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        TArray<FString> Names,
        FOvrAchievementProgressPages& AchievementProgressPages,
        FString& ErrorMsg);

    /** Unlock the achievement with the given name. This can be of any achievement type. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Achievements")
    static void Achievements_Unlock(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString Name,
        FOvrAchievementUpdate& AchievementUpdate,
        FString& ErrorMsg);

    // ----------------------------------------------------------------------
    // Application

    /** Requests version information, including the currently installed and latest available version name and version code. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Application")
    static void Application_GetVersion(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrApplicationVersion& ApplicationVersion,
        FString& ErrorMsg);

    /**
     * Launches a different application in the user's library. If the user
     * does not have that application installed, they will be taken to that app's
     * page in the Oculus Store
     * @param AppID - The ID of the app to launch
     * @param DeeplinkOptions - Additional configuration for this requests. Optional.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Application")
    static void Application_LaunchOtherApp(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId AppID,
        FOvrApplicationOptions DeeplinkOptions,
        FString& StringPayload,
        FString& ErrorMsg);

    // ----------------------------------------------------------------------
    // ApplicationLifecycle

    // ----------------------------------------------------------------------
    // AssetFile

    /** DEPRECATED. Use AssetFile_DeleteById() */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, DeprecationMessage="Use AssetFile_DeleteById()", Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|AssetFile")
    static void AssetFile_Delete(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId AssetFileID,
        FOvrAssetFileDeleteResult& AssetFileDeleteResult,
        FString& ErrorMsg);

    /**
     * Removes an previously installed asset file from the device by its ID.
     * Returns an object containing the asset ID and file name, and a success flag.
     * @param AssetFileID - The asset file ID
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|AssetFile")
    static void AssetFile_DeleteById(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId AssetFileID,
        FOvrAssetFileDeleteResult& AssetFileDeleteResult,
        FString& ErrorMsg);

    /**
     * Removes an previously installed asset file from the device by its name.
     * Returns an object containing the asset ID and file name, and a success flag.
     * @param AssetFileName - The asset file name
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|AssetFile")
    static void AssetFile_DeleteByName(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString AssetFileName,
        FOvrAssetFileDeleteResult& AssetFileDeleteResult,
        FString& ErrorMsg);

    /** DEPRECATED. Use AssetFile_DownloadById() */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, DeprecationMessage="Use AssetFile_DownloadById()", Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|AssetFile")
    static void AssetFile_Download(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId AssetFileID,
        FOvrAssetFileDownloadResult& AssetFileDownloadResult,
        FString& ErrorMsg);

    /**
     * Downloads an asset file by its ID on demand. Returns an object containing
     * the asset ID and filepath. Sends periodic
     * FOvrNotification_AssetFile_DownloadUpdate to track the downloads.
     * @param AssetFileID - The asset file ID
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|AssetFile")
    static void AssetFile_DownloadById(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId AssetFileID,
        FOvrAssetFileDownloadResult& AssetFileDownloadResult,
        FString& ErrorMsg);

    /**
     * Downloads an asset file by its name on demand. Returns an object containing
     * the asset ID and filepath. Sends periodic
     * {notifications.asset_file.download_update}} to track the downloads.
     * @param AssetFileName - The asset file name
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|AssetFile")
    static void AssetFile_DownloadByName(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString AssetFileName,
        FOvrAssetFileDownloadResult& AssetFileDownloadResult,
        FString& ErrorMsg);

    /** DEPRECATED. Use AssetFile_DownloadCancelById() */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, DeprecationMessage="Use AssetFile_DownloadCancelById()", Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|AssetFile")
    static void AssetFile_DownloadCancel(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId AssetFileID,
        FOvrAssetFileDownloadCancelResult& AssetFileDownloadCancelResult,
        FString& ErrorMsg);

    /**
     * Cancels a previously spawned download request for an asset file by its ID.
     * Returns an object containing the asset ID and file path, and a success flag.
     * @param AssetFileID - The asset file ID
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|AssetFile")
    static void AssetFile_DownloadCancelById(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId AssetFileID,
        FOvrAssetFileDownloadCancelResult& AssetFileDownloadCancelResult,
        FString& ErrorMsg);

    /**
     * Cancels a previously spawned download request for an asset file by its name.
     * Returns an object containing the asset ID and file path, and a success flag.
     * @param AssetFileName - The asset file name
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|AssetFile")
    static void AssetFile_DownloadCancelByName(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString AssetFileName,
        FOvrAssetFileDownloadCancelResult& AssetFileDownloadCancelResult,
        FString& ErrorMsg);

    /**
     * Returns an array of objects with asset file names and their associated IDs,
     * and and whether it's currently installed.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|AssetFile")
    static void AssetFile_GetList(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        TArray<FOvrAssetDetails>& AssetDetailsArray,
        FString& ErrorMsg);

    /** DEPRECATED. Use AssetFile_StatusById() */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, DeprecationMessage="Use AssetFile_StatusById()", Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|AssetFile")
    static void AssetFile_Status(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId AssetFileID,
        FOvrAssetDetails& AssetDetails,
        FString& ErrorMsg);

    /**
     * Returns the details on a single asset: ID, file name, and whether it's currently installed
     * @param AssetFileID - The asset file ID
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|AssetFile")
    static void AssetFile_StatusById(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId AssetFileID,
        FOvrAssetDetails& AssetDetails,
        FString& ErrorMsg);

    /**
     * Returns the details on a single asset: ID, file name, and whether it's currently installed
     * @param AssetFileName - The asset file name
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|AssetFile")
    static void AssetFile_StatusByName(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString AssetFileName,
        FOvrAssetDetails& AssetDetails,
        FString& ErrorMsg);

    // ----------------------------------------------------------------------
    // Challenges

    /** DEPRECATED. Use server-to-server API call instead. */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, DeprecationMessage="Use server-to-server API call instead.", Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Challenges")
    static void Challenges_Create(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString LeaderboardName,
        FOvrChallengeOptions ChallengeOptions,
        FOvrChallenge& Challenge,
        FString& ErrorMsg);

    /** If the current user has an invite to the challenge, decline the invite */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Challenges")
    static void Challenges_DeclineInvite(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId ChallengeID,
        FOvrChallenge& Challenge,
        FString& ErrorMsg);

    /** DEPRECATED. Use server-to-server API call instead. */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, DeprecationMessage="Use server-to-server API call instead.", Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Challenges")
    static void Challenges_Delete(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId ChallengeID,
        FString& ErrorMsg);

    /**
     * Gets the information for a single challenge
     * @param ChallengeID - The id of the challenge whose entries to return.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Challenges")
    static void Challenges_Get(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId ChallengeID,
        FOvrChallenge& Challenge,
        FString& ErrorMsg);

    /**
     * Requests a block of challenge entries.
     * @param ChallengeID - The id of the challenge whose entries to return.
     * @param Limit - Defines the maximum number of entries to return.
     * @param Filter - Allows you to restrict the returned values by friends.
     * @param StartAt - Defines whether to center the query on the user or start at the top of the challenge.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Challenges")
    static void Challenges_GetEntries(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId ChallengeID,
        int32 Limit,
        EOvrLeaderboardFilterType Filter,
        EOvrLeaderboardStartAt StartAt,
        FOvrChallengeEntryPages& ChallengeEntryPages,
        FString& ErrorMsg);

    /**
     * Requests a block of challenge entries.
     * @param ChallengeID - The id of the challenge whose entries to return.
     * @param Limit - The maximum number of entries to return.
     * @param AfterRank - The position after which to start.  For example, 10 returns challenge results starting with the 11th user.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Challenges")
    static void Challenges_GetEntriesAfterRank(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId ChallengeID,
        int32 Limit,
        int64 AfterRank,
        FOvrChallengeEntryPages& ChallengeEntryPages,
        FString& ErrorMsg);

    /**
     * Requests a block of challenge entries. Will return only entries matching the user IDs passed in.
     * @param ChallengeID - The id of the challenge whose entries to return.
     * @param Limit - Defines the maximum number of entries to return.
     * @param StartAt - Defines whether to center the query on the user or start at the top of the challenge. If this is EOvrLeaderboardStartAt::CenteredOnViewer or EOvrLeaderboardStartAt::CenteredOnViewerOrTop, then the current user's ID will be automatically added to the query.
     * @param UserIDs - Defines a list of user ids to get entries for.
     * @param UserIDLength - The number of user IDs provided.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Challenges")
    static void Challenges_GetEntriesByIds(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId ChallengeID,
        int32 Limit,
        EOvrLeaderboardStartAt StartAt,
        TArray<FOvrId> UserIDs,
        FOvrChallengeEntryPages& ChallengeEntryPages,
        FString& ErrorMsg);

    /** Requests for a list of challenge */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Challenges")
    static void Challenges_GetList(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrChallengeOptions ChallengeOptions,
        int32 Limit,
        FOvrChallengePages& ChallengePages,
        FString& ErrorMsg);

    /** If the current user has permission, join the challenge */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Challenges")
    static void Challenges_Join(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId ChallengeID,
        FOvrChallenge& Challenge,
        FString& ErrorMsg);

    /** If the current user has permission, leave the challenge */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Challenges")
    static void Challenges_Leave(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId ChallengeID,
        FOvrChallenge& Challenge,
        FString& ErrorMsg);

    /** DEPRECATED. Use server-to-server API call instead. */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, DeprecationMessage="Use server-to-server API call instead.", Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Challenges")
    static void Challenges_UpdateInfo(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId ChallengeID,
        FOvrChallengeOptions ChallengeOptions,
        FOvrChallenge& Challenge,
        FString& ErrorMsg);

    // ----------------------------------------------------------------------
    // CloudStorage

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * Deletes the specified save data buffer.  Conflicts are handled just like Saves.
     * @param Bucket - The name of the storage bucket.
     * @param Key - The name for this saved data.
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|CloudStorage")
    static void CloudStorage_Delete(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString Bucket,
        FString Key,
        FOvrCloudStorageUpdateResponse& CloudStorageUpdateResponse,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * 
     * Loads the saved entry for the specified bucket and key.
     * If a conflict exists with the key then an error message is returned.
     * @param Bucket - The name of the storage bucket.
     * @param Key - The name for this saved data.
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|CloudStorage")
    static void CloudStorage_Load(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString Bucket,
        FString Key,
        FOvrCloudStorageData& CloudStorageData,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * Loads all the metadata for the saves in the specified bucket, including conflicts.
     * @param Bucket - The name of the storage bucket.
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|CloudStorage")
    static void CloudStorage_LoadBucketMetadata(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString Bucket,
        FOvrCloudStorageMetadataPages& CloudStorageMetadataPages,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * Loads the metadata for this bucket-key combination that need to be manually resolved.
     * @param Bucket - The name of the storage bucket
     * @param Key - The key for this saved data.
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|CloudStorage")
    static void CloudStorage_LoadConflictMetadata(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString Bucket,
        FString Key,
        FOvrCloudStorageConflictMetadata& CloudStorageConflictMetadata,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * Loads the data specified by the storage handle.
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|CloudStorage")
    static void CloudStorage_LoadHandle(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString Handle,
        FOvrCloudStorageData& CloudStorageData,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * load the metadata for the specified key
     * @param Bucket - The name of the storage bucket.
     * @param Key - The name for this saved data.
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|CloudStorage")
    static void CloudStorage_LoadMetadata(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString Bucket,
        FString Key,
        FOvrCloudStorageMetadata& CloudStorageMetadata,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * Selects the local save for manual conflict resolution.
     * @param Bucket - The name of the storage bucket.
     * @param Key - The name for this saved data.
     * @param RemoteHandle - The handle of the remote that the local file was resolved against.
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|CloudStorage")
    static void CloudStorage_ResolveKeepLocal(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString Bucket,
        FString Key,
        FString RemoteHandle,
        FOvrCloudStorageUpdateResponse& CloudStorageUpdateResponse,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * Selects the remote save for manual conflict resolution.
     * @param Bucket - The name of the storage bucket.
     * @param Key - The name for this saved data.
     * @param RemoteHandle - The handle of the remote.
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|CloudStorage")
    static void CloudStorage_ResolveKeepRemote(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString Bucket,
        FString Key,
        FString RemoteHandle,
        FOvrCloudStorageUpdateResponse& CloudStorageUpdateResponse,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
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
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|CloudStorage")
    static void CloudStorage_Save(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString Bucket,
        FString Key,
        TArray<uint8> Data,
        int64 Counter,
        FString ExtraData,
        FOvrCloudStorageUpdateResponse& CloudStorageUpdateResponse,
        FString& ErrorMsg);

    // ----------------------------------------------------------------------
    // CloudStorage2

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * Get the directory path for the current user/app pair that will be used during cloud storage synchronization
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|CloudStorage2")
    static void CloudStorage2_GetUserDirectoryPath(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString& StringPayload,
        FString& ErrorMsg);

    // ----------------------------------------------------------------------
    // Entitlement

    /** Returns whether the current user is entitled to the current app. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Entitlement")
    static void Entitlement_GetIsViewerEntitled(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString& ErrorMsg);

    // ----------------------------------------------------------------------
    // GroupPresence

    /** Clear group presence for running app */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|GroupPresence")
    static void GroupPresence_Clear(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString& ErrorMsg);

    /** Returns a list of users that can be invited to your current lobby. These are pulled from your friends and recently met lists. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|GroupPresence")
    static void GroupPresence_GetInvitableUsers(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrInviteOptions Options,
        FOvrUserPages& UserPages,
        FString& ErrorMsg);

    /** Returns a list of users that can be invited to your current lobby. These are pulled from your friends and recently met lists. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|GroupPresence")
    static void GroupPresence_GetSentInvites(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrApplicationInvitePages& ApplicationInvitePages,
        FString& ErrorMsg);

    /**
     * Launch the flow to allow the user to invite others to their current session.
     * This can only be used if the user is in a joinable session.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|GroupPresence")
    static void GroupPresence_LaunchInvitePanel(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrInviteOptions Options,
        FOvrInvitePanelResultInfo& InvitePanelResultInfo,
        FString& ErrorMsg);

    /** Launch an error dialog with predefined messages for common multiplayer errors. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|GroupPresence")
    static void GroupPresence_LaunchMultiplayerErrorDialog(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrMultiplayerErrorOptions Options,
        FString& ErrorMsg);

    /**
     * Launch the dialog which will allow the user to rejoin a previous lobby/match. Either the lobby_session_id
     * or the match_session_id, or both, must be populated.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|GroupPresence")
    static void GroupPresence_LaunchRejoinDialog(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString LobbySessionId,
        FString MatchSessionId,
        FString DestinationApiName,
        FOvrRejoinDialogResult& RejoinDialogResult,
        FString& ErrorMsg);

    /**
     * Launch the panel which displays the current users in the roster. Users with the same lobby and match session
     * id as part of their presence will show up here.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|GroupPresence")
    static void GroupPresence_LaunchRosterPanel(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrRosterOptions Options,
        FString& ErrorMsg);

    /** Returns a list of users that can be invited to your current lobby. These are pulled from your friends and recently met lists. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|GroupPresence")
    static void GroupPresence_SendInvites(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        TArray<FOvrId> UserIDs,
        FOvrSendInvitesResult& SendInvitesResult,
        FString& ErrorMsg);

    /** Set group presence for running app */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|GroupPresence")
    static void GroupPresence_Set(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrGroupPresenceOptions GroupPresenceOptions,
        FString& ErrorMsg);

    /**
     * Set the user's deeplink message while keeping the other group presence parameters the same. If the destination of the user is not set,
     * the deeplink message cannot be set as there's no deeplink message to override.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|GroupPresence")
    static void GroupPresence_SetDeeplinkMessageOverride(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString DeeplinkMessage,
        FString& ErrorMsg);

    /** Replaces the user's current destination for the provided one. All other existing group presence parameters will remain the same. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|GroupPresence")
    static void GroupPresence_SetDestination(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString ApiName,
        FString& ErrorMsg);

    /**
     * Set if the current user's destination and session is joinable while keeping the other group presence
     * parameters the same. If the destination or session ids of the user is not set, they cannot be set to joinable.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|GroupPresence")
    static void GroupPresence_SetIsJoinable(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        bool IsJoinable,
        FString& ErrorMsg);

    /** Replaces the user's current lobby session id for the provided one. All other existing group presence parameters will remain the same. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|GroupPresence")
    static void GroupPresence_SetLobbySession(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString Id,
        FString& ErrorMsg);

    /** Replaces the user's current match session id for the provided one. All other existing group presence parameters will remain the same. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|GroupPresence")
    static void GroupPresence_SetMatchSession(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString Id,
        FString& ErrorMsg);

    // ----------------------------------------------------------------------
    // IAP

    /**
     * Allow the consumable IAP product to be purchased again. Conceptually, this
     * indicates that the item was used or consumed.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|IAP")
    static void IAP_ConsumePurchase(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString Sku,
        FString& ErrorMsg);

    /**
     * Retrieve a list of IAP products that can be purchased.
     * @param Skus - The SKUs of the products to retrieve.
     * @param Count - Number of items you provided in the SKUs.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|IAP")
    static void IAP_GetProductsBySKU(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        TArray<FString> Skus,
        FOvrProductPages& ProductPages,
        FString& ErrorMsg);

    /**
     * Retrieve a list of Purchase that the Logged-In-User has made. This list will
     * also contain consumable purchases that have not been consumed.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|IAP")
    static void IAP_GetViewerPurchases(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrPurchasePages& PurchasePages,
        FString& ErrorMsg);

    /**
     * Retrieve a list of Purchase that the Logged-In-User has made. This list will only contain
     * durable purchase (non-consumable) and is populated from a device cache. It is recommended in
     * all cases to use ovr_User_GetViewerPurchases first and only check the cache if that fails.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|IAP")
    static void IAP_GetViewerPurchasesDurableCache(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrPurchasePages& PurchasePages,
        FString& ErrorMsg);

    /**
     * Launch the checkout flow to purchase the existing product. Oculus Home tries
     * handle and fix as many errors as possible. Home returns the appropriate error
     * message and how to resolveit, if possible. Returns a purchase on success, empty
     * purchase on cancel, and an error on error.
     * @param Sku - IAP sku for the item the user wishes to purchase.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|IAP")
    static void IAP_LaunchCheckoutFlow(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString Sku,
        FOvrPurchase& Purchase,
        FString& ErrorMsg);

    // ----------------------------------------------------------------------
    // LanguagePack

    /**
     * Returns currently installed and selected language pack for an app in the
     * view of the `asset_details`. Use `language` field to extract neeeded
     * language info.
     * A particular language can be download and installed by a user from
     * the Oculus app on the application page.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|LanguagePack")
    static void LanguagePack_GetCurrent(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrAssetDetails& AssetDetails,
        FString& ErrorMsg);

    /**
     * Sets the current language to specified. The parameter is the BCP47 language tag.
     * If a language pack is not downloaded yet, spawns automatically the
     * AssetFile_DownloadByName() request, and sends periodic
     * FOvrNotification_AssetFile_DownloadUpdate to track the downloads.
     * Once the language asset file is downloaded, call LanguagePack_GetCurrent()
     * to retrive the data, and use the language at runtime.
     * @param Tag - BCP47 language tag
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|LanguagePack")
    static void LanguagePack_SetCurrent(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString Tag,
        FOvrAssetFileDownloadResult& AssetFileDownloadResult,
        FString& ErrorMsg);

    // ----------------------------------------------------------------------
    // Leaderboard

    /**
     * Gets the information for a single leaderboard
     * @param LeaderboardName - The name of the leaderboard to return.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Leaderboard")
    static void Leaderboard_Get(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString LeaderboardName,
        FOvrLeaderboardPages& LeaderboardPages,
        FString& ErrorMsg);

    /**
     * Requests a block of leaderboard entries.
     * @param LeaderboardName - The name of the leaderboard whose entries to return.
     * @param Limit - Defines the maximum number of entries to return.
     * @param Filter - Allows you to restrict the returned values by friends.
     * @param StartAt - Defines whether to center the query on the user or start at the top of the leaderboard.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Leaderboard")
    static void Leaderboard_GetEntries(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString LeaderboardName,
        int32 Limit,
        EOvrLeaderboardFilterType Filter,
        EOvrLeaderboardStartAt StartAt,
        FOvrLeaderboardEntryPages& LeaderboardEntryPages,
        FString& ErrorMsg);

    /**
     * Requests a block of leaderboard entries.
     * @param LeaderboardName - The name of the leaderboard.
     * @param Limit - The maximum number of entries to return.
     * @param AfterRank - The position after which to start.  For example, 10 returns leaderboard results starting with the 11th user.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Leaderboard")
    static void Leaderboard_GetEntriesAfterRank(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString LeaderboardName,
        int32 Limit,
        int64 AfterRank,
        FOvrLeaderboardEntryPages& LeaderboardEntryPages,
        FString& ErrorMsg);

    /**
     * Requests a block of leaderboard entries. Will return only entries matching the user IDs passed in.
     * @param LeaderboardName - The name of the leaderboard whose entries to return.
     * @param Limit - Defines the maximum number of entries to return.
     * @param StartAt - Defines whether to center the query on the user or start at the top of the leaderboard. If this is EOvrLeaderboardStartAt::CenteredOnViewer or EOvrLeaderboardStartAt::CenteredOnViewerOrTop, then the current user's ID will be automatically added to the query.
     * @param UserIDs - Defines a list of user ids to get entries for.
     * @param UserIDLength - The number of user IDs provided.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Leaderboard")
    static void Leaderboard_GetEntriesByIds(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString LeaderboardName,
        int32 Limit,
        EOvrLeaderboardStartAt StartAt,
        TArray<FOvrId> UserIDs,
        FOvrLeaderboardEntryPages& LeaderboardEntryPages,
        FString& ErrorMsg);

    /**
     * Writes a single entry to a leaderboard.
     * @param LeaderboardName - The leaderboard for which to write the entry.
     * @param Score - The score to write.
     * @param ExtraData - A 2KB custom data field that is associated with the leaderboard entry. This can be a game replay or anything that provides more detail about the entry to the viewer.
     * @param ExtraDataLength - The length of the extra data.
     * @param ForceUpdate - If true, the score always updates.  This happens even if it is not the user's best score.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Leaderboard")
    static void Leaderboard_WriteEntry(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString LeaderboardName,
        int64 Score,
        TArray<uint8> ExtraData,
        bool ForceUpdate,
        FOvrLeaderboardUpdateStatus& LeaderboardUpdateStatus,
        FString& ErrorMsg);

    /**
     * Writes a single entry to a leaderboard, can include supplementary metrics
     * @param LeaderboardName - The leaderboard for which to write the entry.
     * @param Score - The score to write.
     * @param SupplementaryMetric - A metric that can be used for tiebreakers.
     * @param ExtraData - A 2KB custom data field that is associated with the leaderboard entry. This can be a game replay or anything that provides more detail about the entry to the viewer.
     * @param ExtraDataLength - The length of the extra data.
     * @param ForceUpdate - If true, the score always updates. This happens ecen if it is not the user's best score.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Leaderboard")
    static void Leaderboard_WriteEntryWithSupplementaryMetric(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString LeaderboardName,
        int64 Score,
        int64 SupplementaryMetric,
        TArray<uint8> ExtraData,
        bool ForceUpdate,
        FOvrLeaderboardUpdateStatus& LeaderboardUpdateStatus,
        FString& ErrorMsg);

    // ----------------------------------------------------------------------
    // Matchmaking

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * @param Pool - A BROWSE type matchmaking pool.
     * @param CustomQueryData - Optional. Custom query data.
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Matchmaking")
    static void Matchmaking_Browse(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString Pool,
        FOvrMatchmakingCustomQueryData CustomQueryData,
        FOvrMatchmakingBrowseResult& MatchmakingBrowseResult,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
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
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Matchmaking")
    static void Matchmaking_Browse2(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString Pool,
        FOvrMatchmakingOptions MatchmakingOptions,
        FOvrMatchmakingBrowseResult& MatchmakingBrowseResult,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * @param Pool - The pool in question.
     * @param RequestHash - Used to find your entry in a queue.
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Matchmaking")
    static void Matchmaking_Cancel(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString Pool,
        FString RequestHash,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * Modes: QUICKMATCH, BROWSE
     * 
     * 
     *   Makes a best effort to cancel a previous Enqueue request before a match occurs.  Typically triggered
     *   when a user gives up waiting.  For BROWSE mode, call this when a user gives up looking through the room list or when the
     *   host of a room wants to stop receiving new users.
     *   If you don't cancel but the user goes offline, the user/room will be timed out of the queue within 30 seconds.
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Matchmaking")
    static void Matchmaking_Cancel2(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * @param Pool - The matchmaking pool to use, which is defined for the app.
     * @param MaxUsers - Overrides the Max Users value, which is configured in pool settings of the Developer Dashboard.
     * @param SubscribeToUpdates - If true, sends a message with type FOvrNotification_Room_RoomUpdate when the room data changes, such as when users join or leave.
     * @param CustomQueryData - Optional.  See "Custom criteria" section above.
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Matchmaking")
    static void Matchmaking_CreateAndEnqueueRoom(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString Pool,
        int32 MaxUsers,
        bool SubscribeToUpdates,
        FOvrMatchmakingCustomQueryData CustomQueryData,
        FOvrMatchmakingEnqueueResultAndRoom& MatchmakingEnqueueResultAndRoom,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
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
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Matchmaking")
    static void Matchmaking_CreateAndEnqueueRoom2(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString Pool,
        FOvrMatchmakingOptions MatchmakingOptions,
        FOvrMatchmakingEnqueueResultAndRoom& MatchmakingEnqueueResultAndRoom,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * @param Pool - The matchmaking pool to use, which is defined for the app.
     * @param MaxUsers - Overrides the Max Users value, which is configured in pool settings of the Developer Dashboard.
     * @param SubscribeToUpdates - If true, sends a message with type FOvrNotification_Room_RoomUpdate when room data changes, such as when users join or leave.
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Matchmaking")
    static void Matchmaking_CreateRoom(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString Pool,
        int32 MaxUsers,
        bool SubscribeToUpdates,
        FOvrRoom& Room,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
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
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Matchmaking")
    static void Matchmaking_CreateRoom2(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString Pool,
        FOvrMatchmakingOptions MatchmakingOptions,
        FOvrRoom& Room,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * @param Pool - The pool to enqueue in.
     * @param CustomQueryData - Optional.  See "Custom criteria" section above.
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Matchmaking")
    static void Matchmaking_Enqueue(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString Pool,
        FOvrMatchmakingCustomQueryData CustomQueryData,
        FOvrMatchmakingEnqueueResult& MatchmakingEnqueueResult,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
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
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Matchmaking")
    static void Matchmaking_Enqueue2(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString Pool,
        FOvrMatchmakingOptions MatchmakingOptions,
        FOvrMatchmakingEnqueueResult& MatchmakingEnqueueResult,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * @param RoomID - Returned either from FOvrNotification_Matchmaking_MatchFound or from Matchmaking_CreateRoom().
     * @param CustomQueryData - Optional.  See the "Custom criteria" section above.
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Matchmaking")
    static void Matchmaking_EnqueueRoom(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId RoomID,
        FOvrMatchmakingCustomQueryData CustomQueryData,
        FOvrMatchmakingEnqueueResult& MatchmakingEnqueueResult,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
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
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Matchmaking")
    static void Matchmaking_EnqueueRoom2(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId RoomID,
        FOvrMatchmakingOptions MatchmakingOptions,
        FOvrMatchmakingEnqueueResult& MatchmakingEnqueueResult,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * Modes: QUICKMATCH, BROWSE
     * 
     * Used to debug the state of the current matchmaking pool queue.  This is not intended to be used in production.
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Matchmaking")
    static void Matchmaking_GetAdminSnapshot(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrMatchmakingAdminSnapshot& MatchmakingAdminSnapshot,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
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
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Matchmaking")
    static void Matchmaking_GetStats(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString Pool,
        int32 MaxLevel,
        EOvrMatchmakingStatApproach Approach,
        FOvrMatchmakingStats& MatchmakingStats,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * @param RoomID - ID of a room previously returned from FOvrNotification_Matchmaking_MatchFound or Matchmaking_Browse().
     * @param SubscribeToUpdates - If true, sends a message with type FOvrNotification_Room_RoomUpdate when room data changes, such as when users join or leave.
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Matchmaking")
    static void Matchmaking_JoinRoom(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId RoomID,
        bool SubscribeToUpdates,
        FOvrRoom& Room,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
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
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Matchmaking")
    static void Matchmaking_ReportResultInsecure(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId RoomID,
        TMap<FString, FOvrVariant> Data,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * Modes: QUICKMATCH, BROWSE (+ Skill Pool)
     * 
     * For pools with skill-based matching.  See overview documentation above.
     * 
     * Call after calling Room_Join2() when the players are present to begin a rated match for which you plan to report the results
     * (using Matchmaking_ReportResultInsecure()).
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Matchmaking")
    static void Matchmaking_StartMatch(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId RoomID,
        FString& ErrorMsg);

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
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Media")
    static void Media_ShareToFacebook(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString PostTextSuggestion,
        FString FilePath,
        EOvrMediaContentType ContentType,
        FOvrShareMediaResult& ShareMediaResult,
        FString& ErrorMsg);

    // ----------------------------------------------------------------------
    // Notification

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * 
     * Retrieve a list of all pending room invites for your application (for example, notifications
     * that may have been sent before the user launched your game).  You can also get push
     * notifications with FOvrNotification_Room_InviteReceived.
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Notification")
    static void Notification_GetRoomInvites(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrRoomInviteNotificationPages& RoomInviteNotificationPages,
        FString& ErrorMsg);

    /**
     * Mark a notification as read. This causes it to disappear from the
     * Universal Menu, the Oculus App, Oculus Home, and in-app retrieval.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Notification")
    static void Notification_MarkAsRead(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId NotificationID,
        FString& ErrorMsg);

    // ----------------------------------------------------------------------
    // Party

    /** Load the party the current user is in. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Party")
    static void Party_GetCurrent(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrParty& Party,
        FString& ErrorMsg);

    // ----------------------------------------------------------------------
    // RichPresence

    /** DEPRECATED. Use the clear method in group presence */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, DeprecationMessage="Use the clear method in group presence", Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|RichPresence")
    static void RichPresence_Clear(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString& ErrorMsg);

    /** Gets all the destinations that the presence can be set to */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|RichPresence")
    static void RichPresence_GetDestinations(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrDestinationPages& DestinationPages,
        FString& ErrorMsg);

    /** DEPRECATED. Use GroupPresence_Set(). */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, DeprecationMessage="Use GroupPresence_Set().", Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|RichPresence")
    static void RichPresence_Set(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrRichPresenceOptions RichPresenceOptions,
        FString& ErrorMsg);

    // ----------------------------------------------------------------------
    // Room

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * @param JoinPolicy - Specifies who can join the room without an invite.
     * @param MaxUsers - The maximum number of users allowed in the room, including the creator.
     * @param SubscribeToUpdates - If true, sends a message with type FOvrNotification_Room_RoomUpdate when room data changes, such as when users join or leave.
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Room")
    static void Room_CreateAndJoinPrivate(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        EOvrRoomJoinPolicy JoinPolicy,
        int32 MaxUsers,
        bool SubscribeToUpdates,
        FOvrRoom& Room,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * Creates a new private (client controlled) room and adds the caller to it. This type of room is good
     * for matches where the user wants to play with friends, as they're primarially discoverable by examining
     * which rooms your friends are in.
     * @param JoinPolicy - Specifies who can join the room without an invite.
     * @param MaxUsers - The maximum number of users allowed in the room, including the creator.
     * @param RoomOptions - Additional room configuration for this request. Optional.
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Room")
    static void Room_CreateAndJoinPrivate2(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        EOvrRoomJoinPolicy JoinPolicy,
        int32 MaxUsers,
        FOvrRoomOptions RoomOptions,
        FOvrRoom& Room,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * Allows arbitrary rooms for the application to be loaded.
     * @param RoomID - The room to load.
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Room")
    static void Room_Get(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId RoomID,
        FOvrRoom& Room,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * Easy loading of the room you're currently in. If you don't want live updates
     * on your current room (by using subscribeToUpdates), you can use this to refresh the data.
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Room")
    static void Room_GetCurrent(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrRoom& Room,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * Allows the current room for a given user to be loaded. Remember that the user's privacy settings
     * may not allow their room to be loaded. Because of this, it's often possible to load the users in
     * a room, but not to take those users and load their room.
     * @param UserID - ID of the user for which to load the room.
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Room")
    static void Room_GetCurrentForUser(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId UserID,
        FOvrRoom& Room,
        FString& ErrorMsg);

    /** DEPRECATED. Will be removed from headers at version v49. */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Room")
    static void Room_GetInvitableUsers(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrUserPages& UserPages,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
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
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Room")
    static void Room_GetInvitableUsers2(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrRoomOptions RoomOptions,
        FOvrUserPages& UserPages,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * Fetches the list of moderated rooms created for the application.
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Room")
    static void Room_GetModeratedRooms(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrRoomPages& RoomPages,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * Invites a user to the specified room.  They will receive a notification via
     * FOvrNotification_Room_InviteReceived if they are in your game, and/or they can poll for room invites
     * using Notification_GetRoomInvites().
     * @param RoomID - The ID of your current room.
     * @param InviteToken - A user's invite token, returned by Room_GetInvitableUsers().
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Room")
    static void Room_InviteUser(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId RoomID,
        FString InviteToken,
        FOvrRoom& Room,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * Joins the target room (leaving the one you're currently in).
     * @param RoomID - The room to join.
     * @param SubscribeToUpdates - If true, sends a message with type FOvrNotification_Room_RoomUpdate when room data changes, such as when users join or leave.
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Room")
    static void Room_Join(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId RoomID,
        bool SubscribeToUpdates,
        FOvrRoom& Room,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * Joins the target room (leaving the one you're currently in).
     * @param RoomID - The room to join.
     * @param RoomOptions - Additional room configuration for this request. Optional.
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Room")
    static void Room_Join2(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId RoomID,
        FOvrRoomOptions RoomOptions,
        FOvrRoom& Room,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * Allows the room owner to kick a user out of the current room.
     * @param RoomID - The room that you currently own (check field FOvrRoom::Owner).
     * @param UserID - The user to be kicked (cannot be yourself).
     * @param KickDurationSeconds - Length of the ban, in seconds.
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Room")
    static void Room_KickUser(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId RoomID,
        FOvrId UserID,
        int32 KickDurationSeconds,
        FOvrRoom& Room,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     *  Launch the invitable user flow to invite to the logged in user's current
     * room. This is intended to be a nice shortcut for developers not wanting
     * to build out their own Invite UI although it has the same rules as if
     * you build it yourself. 
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Room")
    static void Room_LaunchInvitableUserFlow(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId RoomID,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * 
     * Removes you from your current room.  Returns the solo room you are now in if it succeeds
     * @param RoomID - The room you're currently in.
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Room")
    static void Room_Leave(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId RoomID,
        FOvrRoom& Room,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * Allows the room owner to set the description of their room.
     * @param RoomID - The room that you currently own (check field FOvrRoom::Owner).
     * @param Description - The new name of the room.
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Room")
    static void Room_SetDescription(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId RoomID,
        FString Description,
        FOvrRoom& Room,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * Allows the room owner to update the data store (set of key value pairs) of their room.
     * 
     * NOTE: Room datastores only allow string values. If you provide int or double values, this returns an error.
     * @param RoomID - The room that you currently own (check field FOvrRoom::Owner).
     * @param Data - The key/value pairs to add or update; null values clear a given key.
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Room")
    static void Room_UpdateDataStore(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId RoomID,
        TMap<FString, FOvrVariant> Data,
        FOvrRoom& Room,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * Disallow new members from being able to join the room. This will prevent
     * joins from Room_Join(), invites, 'Join From Home', etc.
     * Users that are in the room at the time of lockdown WILL be able to rejoin.
     * @param RoomID - The room whose membership you want to lock or unlock.
     * @param MembershipLockStatus - The new LockStatus for the room
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Room")
    static void Room_UpdateMembershipLockStatus(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId RoomID,
        EOvrRoomMembershipLockStatus MembershipLockStatus,
        FOvrRoom& Room,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * Allows the room owner to transfer ownership to someone else.
     * @param RoomID - The room that the user owns (check field FOvrRoom::Owner).
     * @param UserID - The new user to make an owner; the user must be in the room.
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Room")
    static void Room_UpdateOwner(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId RoomID,
        FOvrId UserID,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * Sets the join policy of the user's private room.
     * @param RoomID - The room ID that the user owns (check field FOvrRoom::Owner).
     * @param NewJoinPolicy - The new join policy for the room.
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Room")
    static void Room_UpdatePrivateRoomJoinPolicy(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId RoomID,
        EOvrRoomJoinPolicy NewJoinPolicy,
        FOvrRoom& Room,
        FString& ErrorMsg);

    // ----------------------------------------------------------------------
    // User

    /**
     * Retrieve the user with the given ID. This might fail if the ID is invalid
     * or the user is blocked.
     * 
     * NOTE: Users will have a unique ID per application.
     * @param UserID - User ID retrieved with this application.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|User")
    static void User_Get(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId UserID,
        FOvrUser& User,
        FString& ErrorMsg);

    /** Return an access token for this user, suitable for making REST calls against graph.oculus.com. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|User")
    static void User_GetAccessToken(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString& StringPayload,
        FString& ErrorMsg);

    /** Return the IDs of users entitled to use the current app that are blocked by the specified user */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|User")
    static void User_GetBlockedUsers(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrBlockedUserPages& BlockedUserPages,
        FString& ErrorMsg);

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
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|User")
    static void User_GetLoggedInUser(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrUser& User,
        FString& ErrorMsg);

    /** Retrieve a list of the logged in user's friends. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|User")
    static void User_GetLoggedInUserFriends(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrUserPages& UserPages,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Use User_GetLoggedInUserFriends() instead Will be removed from headers at version v49.
     * Retrieve a list of the logged in user's friends and any rooms they
     * might be in.
     */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, DeprecationMessage="Use User_GetLoggedInUserFriends() instead", Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|User")
    static void User_GetLoggedInUserFriendsAndRooms(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrUserAndRoomPages& UserAndRoomPages,
        FString& ErrorMsg);

    /**
     * DEPRECATED. Will be removed from headers at version v49.
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
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|User")
    static void User_GetLoggedInUserRecentlyMetUsersAndRooms(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrUserOptions UserOptions,
        FOvrUserAndRoomPages& UserAndRoomPages,
        FString& ErrorMsg);

    /**
     * returns an ovrID which is unique per org. allows different apps within the same
     * org to identify the user. 
     * @param UserID - to load the org scoped id of
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|User")
    static void User_GetOrgScopedID(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId UserID,
        FOvrOrgScopedID& OrgScopedID,
        FString& ErrorMsg);

    /**
     * Returns all accounts belonging to this user.
     * Accounts are the Oculus user and x-users that are linked to this user.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|User")
    static void User_GetSdkAccounts(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        TArray<FOvrSdkAccount>& SdkAccountArray,
        FString& ErrorMsg);

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
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|User")
    static void User_GetUserProof(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrUserProof& UserProof,
        FString& ErrorMsg);

    /**
     * Launch the flow for blocking the given user. You can't be friended, invited,
     *  or searched by a blocked user, for example. You can remove the block via
     *  ovr_User_LaunchUnblockFlow.
     * @param UserID - User ID of user being blocked
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|User")
    static void User_LaunchBlockFlow(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId UserID,
        FOvrLaunchBlockFlowResult& LaunchBlockFlowResult,
        FString& ErrorMsg);

    /**
     * Launch the flow for sending a friend request to a user.
     * @param UserID - User ID of user to send a friend request to
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|User")
    static void User_LaunchFriendRequestFlow(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId UserID,
        FOvrLaunchFriendRequestFlowResult& LaunchFriendRequestFlowResult,
        FString& ErrorMsg);

    /**
     * Launch the flow for unblocking a user that the viewer has blocked.
     * @param UserID - User ID of user to unblock
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|User")
    static void User_LaunchUnblockFlow(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId UserID,
        FOvrLaunchUnblockFlowResult& LaunchUnblockFlowResult,
        FString& ErrorMsg);

    // ----------------------------------------------------------------------
    // UserDataStore

    /**
     * Delete an entry by a key from a private user data store.
     * @param UserID - The ID of the user who owns this private user data store.
     * @param Key - The key of entry.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|UserDataStore")
    static void UserDataStore_PrivateDeleteEntryByKey(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId UserID,
        FString Key,
        FOvrUserDataStoreUpdateResponse& UserDataStoreUpdateResponse,
        FString& ErrorMsg);

    /**
     * Get entries from a private user data store.
     * @param UserID - The ID of the user who owns this private user data store.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|UserDataStore")
    static void UserDataStore_PrivateGetEntries(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId UserID,
        TMap<FString, FString>& DataStore,
        FString& ErrorMsg);

    /**
     * Get an entry by a key from a private user data store.
     * @param UserID - The ID of the user who owns this private user data store.
     * @param Key - The key of entry.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|UserDataStore")
    static void UserDataStore_PrivateGetEntryByKey(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId UserID,
        FString Key,
        TMap<FString, FString>& DataStore,
        FString& ErrorMsg);

    /**
     * Write a single entry to a private user data store.
     * @param UserID - The ID of the user who owns this private user data store.
     * @param Key - The key of entry.
     * @param Value - The value of entry.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|UserDataStore")
    static void UserDataStore_PrivateWriteEntry(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId UserID,
        FString Key,
        FString Value,
        FOvrUserDataStoreUpdateResponse& UserDataStoreUpdateResponse,
        FString& ErrorMsg);

    /**
     * Delete an entry by a key from a public user data store.
     * @param UserID - The ID of the user who owns this public user data store.
     * @param Key - The key of entry.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|UserDataStore")
    static void UserDataStore_PublicDeleteEntryByKey(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId UserID,
        FString Key,
        FOvrUserDataStoreUpdateResponse& UserDataStoreUpdateResponse,
        FString& ErrorMsg);

    /**
     * Get entries from a public user data store.
     * @param UserID - The ID of the user who owns this public user data store.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|UserDataStore")
    static void UserDataStore_PublicGetEntries(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId UserID,
        TMap<FString, FString>& DataStore,
        FString& ErrorMsg);

    /**
     * Get an entry by a key from a public user data store.
     * @param UserID - The ID of the user who owns this public user data store.
     * @param Key - The key of entry.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|UserDataStore")
    static void UserDataStore_PublicGetEntryByKey(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId UserID,
        FString Key,
        TMap<FString, FString>& DataStore,
        FString& ErrorMsg);

    /**
     * Write a single entry to a public user data store.
     * @param UserID - The ID of the user who owns this public user data store.
     * @param Key - The key of entry.
     * @param Value - The value of entry.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|UserDataStore")
    static void UserDataStore_PublicWriteEntry(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrId UserID,
        FString Key,
        FString Value,
        FOvrUserDataStoreUpdateResponse& UserDataStoreUpdateResponse,
        FString& ErrorMsg);

    // ----------------------------------------------------------------------
    // Voip

    /** Gets whether the microphone is currently available to the app. This can be used to show if the user's voice is able to be heard by other users. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Voip")
    static void Voip_GetMicrophoneAvailability(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrMicrophoneAvailabilityState& MicrophoneAvailabilityState,
        FString& ErrorMsg);

    /** Sets whether SystemVoip should be suppressed so that this app's Voip can use the mic and play incoming Voip audio. Once microphone switching functionality for the user is released, this function will no longer work. You can use get_microphone_availability to see if the user has allowed the app access to the microphone. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Voip")
    static void Voip_SetSystemVoipSuppressed(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        bool Suppressed,
        FOvrSystemVoipState& SystemVoipState,
        FString& ErrorMsg);

};
