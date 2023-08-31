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
    // AbuseReport

    /** The currently running application has indicated they want to show their in-app reporting flow or that they choose to ignore the request. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|AbuseReport")
    static void AbuseReport_ReportRequestHandled(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        EOvrReportRequestResponse Response,
        FString& ErrorMsg);

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

    /**
     * Cancel an app download that is in progress.
     * It will return a result when the download is cancelled.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Application")
    static void Application_CancelAppDownload(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrAppDownloadResult& AppDownloadResult,
        FString& ErrorMsg);

    /** Track download progress for an app */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Application")
    static void Application_CheckAppDownloadProgress(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrAppDownloadProgressResult& AppDownloadProgressResult,
        FString& ErrorMsg);

    /**
     * Requests version information, including the version code and version name of the currently installed app
     * and version code, version name, size and release date of the latest app update
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Application")
    static void Application_GetVersion(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrApplicationVersion& ApplicationVersion,
        FString& ErrorMsg);

    /**
     * Installs the app update that was previously downloaded.
     * Once the install begins the application will exit automatically.
     * After the installation process is complete, the app will be relaunched
     * based on the options passed.
     * @param DeeplinkOptions - Additional configuration for this relaunch. Optional.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Application")
    static void Application_InstallAppUpdateAndRelaunch(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrApplicationOptions DeeplinkOptions,
        FOvrAppDownloadResult& AppDownloadResult,
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

    /**
     * Starts an app download.
     * It will return a result when the download is finished.
     * Download progress can be monitored using the check_app_download_progress API.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Application")
    static void Application_StartAppDownload(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrAppDownloadResult& AppDownloadResult,
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
    // Avatar

    /** Launches the Avatar Editor */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Avatar")
    static void Avatar_LaunchAvatarEditor(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrAvatarEditorOptions Options,
        FOvrAvatarEditorResult& AvatarEditorResult,
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
     * @param Filter - By using ovrLeaderboard_FilterFriends, this allows you to filter the returned values to bidirectional followers.
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
    // DeviceApplicationIntegrity

    /**
     * Returns Device and Application Integrity Attestation JSON Web Token.
     * The token has format of header.claims.signature encoded in base64.
     * Header contains algorithm type (PS256) and token type (JWT).
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|DeviceApplicationIntegrity")
    static void DeviceApplicationIntegrity_GetIntegrityToken(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FString ChallengeNonce,
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

    /** Returns a list of users that can be invited to your current lobby. These are pulled from your bidirectional followers and recently met lists. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|GroupPresence")
    static void GroupPresence_GetInvitableUsers(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrInviteOptions Options,
        FOvrUserPages& UserPages,
        FString& ErrorMsg);

    /** Get the application invites which have been sent by the user. */
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

    /** Send application invites to the passed in userIDs. */
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
     * @param Filter - By using ovrLeaderboard_FilterFriends, this allows you to filter the returned values to bidirectional followers.
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

    /** Retrieve a list of the logged in user's bidirectional followers. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|User")
    static void User_GetLoggedInUserFriends(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrUserPages& UserPages,
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
     * Launch the flow for blocking the given user. You can't follow, be followed, invited,
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
     * Launch the flow for sending a follow request to a user.
     * @param UserID - User ID of user to send a follow request to
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
    // UserAgeCategory

    /** Retrieve the user age category for the current user. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|UserAgeCategory")
    static void UserAgeCategory_Get(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        FOvrUserAccountAgeCategory& UserAccountAgeCategory,
        FString& ErrorMsg);

    /** Report the current user's age category to Meta. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|UserAgeCategory")
    static void UserAgeCategory_Report(
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        EOvrAppAgeCategory AgeCategory,
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
