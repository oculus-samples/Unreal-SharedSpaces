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

#include "OVRPlatformTypes.h"
#include "OVRPlatformModels.generated.h"


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|AbuseReportRecording")
struct OVRPLATFORM_API FOvrAbuseReportRecording
{
    GENERATED_USTRUCT_BODY()

    /** A UUID associated with the Abuse Report recording. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AbuseReportRecording|Field")
    FString RecordingUuid;

    // Default ctor.
    FOvrAbuseReportRecording();

    // Copying values from an OVR handle.
    FOvrAbuseReportRecording(ovrAbuseReportRecordingHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrAbuseReportRecordingHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * An AchievementDefinition defines an achievement; this includes its name and how it is unlocked.
 * For an individual user's progress in unlocking an achievement, see AchievementProgress.
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|AchievementDefinition")
struct OVRPLATFORM_API FOvrAchievementDefinition
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AchievementDefinition|Field")
    EOvrAchievementType AchievementType;

    /** The name of the achievement. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AchievementDefinition|Field")
    FString ApiName;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AchievementDefinition|Field")
    int32 BitfieldLength;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AchievementDefinition|Field")
    int64 Target;

    // Default ctor.
    FOvrAchievementDefinition();

    // Copying values from an OVR handle.
    FOvrAchievementDefinition(ovrAchievementDefinitionHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrAchievementDefinitionHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};

USTRUCT(BlueprintType, Category = "OvrPlatform|Models|AchievementDefinitionArray")
struct OVRPLATFORM_API FOvrAchievementDefinitionPages
{
    GENERATED_USTRUCT_BODY()

    // Default ctor.
    FOvrAchievementDefinitionPages();

    // Copying values from an OVR handle to the array, and the originating message
    // to prevent the handle from being freed.
    FOvrAchievementDefinitionPages(ovrAchievementDefinitionArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating values from an OVR handle to the array, and the originating message
    // to prevent the handle from being freed.
    void Update(ovrAchievementDefinitionArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // OVR array handle for methods
    mutable ovrAchievementDefinitionArrayHandle PagedArrayHandle;

    // Original ref-counted message to hold onto array handle
    mutable TOvrMessageHandlePtr PagedArrayMessageHandlePtr;
};

UCLASS()
class OVRPLATFORM_API UOvrAchievementDefinitionPagesMethods : public UObject
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|AchievementDefinitionPages")
    static FOvrAchievementDefinition AchievementDefinitionPages_GetElement(const FOvrAchievementDefinitionPages& Model, int64 Index);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|AchievementDefinitionPages")
    static FString AchievementDefinitionPages_GetNextUrl(const FOvrAchievementDefinitionPages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|AchievementDefinitionPages")
    static int64 AchievementDefinitionPages_GetSize(const FOvrAchievementDefinitionPages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|AchievementDefinitionPages")
    static bool AchievementDefinitionPages_HasNextPage(const FOvrAchievementDefinitionPages& Model);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|AchievementProgress")
struct OVRPLATFORM_API FOvrAchievementProgress
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AchievementProgress|Field")
    FString Bitfield;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AchievementProgress|Field")
    int64 Count;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AchievementProgress|Field")
    bool IsUnlocked;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AchievementProgress|Field")
    FString Name;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AchievementProgress|Field")
    FDateTime UnlockTime;

    // Default ctor.
    FOvrAchievementProgress();

    // Copying values from an OVR handle.
    FOvrAchievementProgress(ovrAchievementProgressHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrAchievementProgressHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};

USTRUCT(BlueprintType, Category = "OvrPlatform|Models|AchievementProgressArray")
struct OVRPLATFORM_API FOvrAchievementProgressPages
{
    GENERATED_USTRUCT_BODY()

    // Default ctor.
    FOvrAchievementProgressPages();

    // Copying values from an OVR handle to the array, and the originating message
    // to prevent the handle from being freed.
    FOvrAchievementProgressPages(ovrAchievementProgressArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating values from an OVR handle to the array, and the originating message
    // to prevent the handle from being freed.
    void Update(ovrAchievementProgressArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // OVR array handle for methods
    mutable ovrAchievementProgressArrayHandle PagedArrayHandle;

    // Original ref-counted message to hold onto array handle
    mutable TOvrMessageHandlePtr PagedArrayMessageHandlePtr;
};

UCLASS()
class OVRPLATFORM_API UOvrAchievementProgressPagesMethods : public UObject
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|AchievementProgressPages")
    static FOvrAchievementProgress AchievementProgressPages_GetElement(const FOvrAchievementProgressPages& Model, int64 Index);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|AchievementProgressPages")
    static FString AchievementProgressPages_GetNextUrl(const FOvrAchievementProgressPages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|AchievementProgressPages")
    static int64 AchievementProgressPages_GetSize(const FOvrAchievementProgressPages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|AchievementProgressPages")
    static bool AchievementProgressPages_HasNextPage(const FOvrAchievementProgressPages& Model);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|AchievementUpdate")
struct OVRPLATFORM_API FOvrAchievementUpdate
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AchievementUpdate|Field")
    bool JustUnlocked;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AchievementUpdate|Field")
    FString Name;

    // Default ctor.
    FOvrAchievementUpdate();

    // Copying values from an OVR handle.
    FOvrAchievementUpdate(ovrAchievementUpdateHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrAchievementUpdateHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|ApplicationVersion")
struct OVRPLATFORM_API FOvrApplicationVersion
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ApplicationVersion|Field")
    int32 CurrentCode;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ApplicationVersion|Field")
    FString CurrentName;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ApplicationVersion|Field")
    int32 LatestCode;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ApplicationVersion|Field")
    FString LatestName;

    // Default ctor.
    FOvrApplicationVersion();

    // Copying values from an OVR handle.
    FOvrApplicationVersion(ovrApplicationVersionHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrApplicationVersionHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|AssetFileDeleteResult")
struct OVRPLATFORM_API FOvrAssetFileDeleteResult
{
    GENERATED_USTRUCT_BODY()

    /** DEPRECATED. Use field FOvrAssetFileDeleteResult::AssetId. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty, DeprecationMessage="Use field FOvrAssetFileDeleteResult::AssetId."), Category = "OvrPlatform|Models|AssetFileDeleteResult|Field")
    FOvrId AssetFileId;

    /** ID of the asset file */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AssetFileDeleteResult|Field")
    FOvrId AssetId;

    /** File path of the asset file. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AssetFileDeleteResult|Field")
    FString Filepath;

    /** Whether the asset delete was successful. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AssetFileDeleteResult|Field")
    bool Success;

    // Default ctor.
    FOvrAssetFileDeleteResult();

    // Copying values from an OVR handle.
    FOvrAssetFileDeleteResult(ovrAssetFileDeleteResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrAssetFileDeleteResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|AssetFileDownloadCancelResult")
struct OVRPLATFORM_API FOvrAssetFileDownloadCancelResult
{
    GENERATED_USTRUCT_BODY()

    /** DEPRECATED. Use field FOvrAssetFileDownloadCancelResult::AssetId. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty, DeprecationMessage="Use field FOvrAssetFileDownloadCancelResult::AssetId."), Category = "OvrPlatform|Models|AssetFileDownloadCancelResult|Field")
    FOvrId AssetFileId;

    /** ID of the asset file */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AssetFileDownloadCancelResult|Field")
    FOvrId AssetId;

    /** File path of the asset file. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AssetFileDownloadCancelResult|Field")
    FString Filepath;

    /** Whether the cancel request is succeeded. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AssetFileDownloadCancelResult|Field")
    bool Success;

    // Default ctor.
    FOvrAssetFileDownloadCancelResult();

    // Copying values from an OVR handle.
    FOvrAssetFileDownloadCancelResult(ovrAssetFileDownloadCancelResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrAssetFileDownloadCancelResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|AssetFileDownloadResult")
struct OVRPLATFORM_API FOvrAssetFileDownloadResult
{
    GENERATED_USTRUCT_BODY()

    /** ID of the asset file */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AssetFileDownloadResult|Field")
    FOvrId AssetId;

    /** File path of the asset file. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AssetFileDownloadResult|Field")
    FString Filepath;

    // Default ctor.
    FOvrAssetFileDownloadResult();

    // Copying values from an OVR handle.
    FOvrAssetFileDownloadResult(ovrAssetFileDownloadResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrAssetFileDownloadResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|AssetFileDownloadUpdate")
struct OVRPLATFORM_API FOvrAssetFileDownloadUpdate
{
    GENERATED_USTRUCT_BODY()

    /** DEPRECATED. Use field FOvrAssetFileDownloadUpdate::AssetId. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty, DeprecationMessage="Use field FOvrAssetFileDownloadUpdate::AssetId."), Category = "OvrPlatform|Models|AssetFileDownloadUpdate|Field")
    FOvrId AssetFileId;

    /** ID of the asset file */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AssetFileDownloadUpdate|Field")
    FOvrId AssetId;

    /** Total number of bytes. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AssetFileDownloadUpdate|Field")
    int64 BytesTotal;

    /** Number of bytes have been downloaded. -1 If the download hasn't started yet. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AssetFileDownloadUpdate|Field")
    int64 BytesTransferred;

    /** Flag indicating a download is completed. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AssetFileDownloadUpdate|Field")
    bool Completed;

    // Default ctor.
    FOvrAssetFileDownloadUpdate();

    // Copying values from an OVR handle.
    FOvrAssetFileDownloadUpdate(ovrAssetFileDownloadUpdateHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrAssetFileDownloadUpdateHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|BlockedUser")
struct OVRPLATFORM_API FOvrBlockedUser
{
    GENERATED_USTRUCT_BODY()

    /** user ID that has been blocked by the logged in user */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|BlockedUser|Field")
    FOvrId Id;

    // Default ctor.
    FOvrBlockedUser();

    // Copying values from an OVR handle.
    FOvrBlockedUser(ovrBlockedUserHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrBlockedUserHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};

USTRUCT(BlueprintType, Category = "OvrPlatform|Models|BlockedUserArray")
struct OVRPLATFORM_API FOvrBlockedUserPages
{
    GENERATED_USTRUCT_BODY()

    // Default ctor.
    FOvrBlockedUserPages();

    // Copying values from an OVR handle to the array, and the originating message
    // to prevent the handle from being freed.
    FOvrBlockedUserPages(ovrBlockedUserArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating values from an OVR handle to the array, and the originating message
    // to prevent the handle from being freed.
    void Update(ovrBlockedUserArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // OVR array handle for methods
    mutable ovrBlockedUserArrayHandle PagedArrayHandle;

    // Original ref-counted message to hold onto array handle
    mutable TOvrMessageHandlePtr PagedArrayMessageHandlePtr;
};

UCLASS()
class OVRPLATFORM_API UOvrBlockedUserPagesMethods : public UObject
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|BlockedUserPages")
    static FOvrBlockedUser BlockedUserPages_GetElement(const FOvrBlockedUserPages& Model, int64 Index);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|BlockedUserPages")
    static FString BlockedUserPages_GetNextUrl(const FOvrBlockedUserPages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|BlockedUserPages")
    static int64 BlockedUserPages_GetSize(const FOvrBlockedUserPages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|BlockedUserPages")
    static bool BlockedUserPages_HasNextPage(const FOvrBlockedUserPages& Model);
};


/** DEPRECATED. Will be removed from headers at version v49. */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|CalApplicationFinalized")
struct OVRPLATFORM_API FOvrCalApplicationFinalized
{
    GENERATED_USTRUCT_BODY()

    /**
     * Number of milliseconds to wait before launching the app.
     * Launcher should display a countdown to the user while waiting.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|CalApplicationFinalized|Field")
    int32 CountdownMS;

    /** ID of the application we should launch into. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|CalApplicationFinalized|Field")
    FOvrId ID;

    /**
     * Launch argument generated by the CAL system.  This must be passed unmodified
     * to the application as an intent extra or command line argument
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|CalApplicationFinalized|Field")
    FString LaunchDetails;

    // Default ctor.
    FOvrCalApplicationFinalized();

    // Copying values from an OVR handle.
    FOvrCalApplicationFinalized(ovrCalApplicationFinalizedHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrCalApplicationFinalizedHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/** DEPRECATED. Will be removed from headers at version v49. */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|CalApplicationProposed")
struct OVRPLATFORM_API FOvrCalApplicationProposed
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|CalApplicationProposed|Field")
    FOvrId ID;

    // Default ctor.
    FOvrCalApplicationProposed();

    // Copying values from an OVR handle.
    FOvrCalApplicationProposed(ovrCalApplicationProposedHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrCalApplicationProposedHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/** DEPRECATED. Will be removed from headers at version v49. */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|CalApplicationSuggestion")
struct OVRPLATFORM_API FOvrCalApplicationSuggestion
{
    GENERATED_USTRUCT_BODY()

    /** Application ID of the suggested app. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|CalApplicationSuggestion|Field")
    FOvrId ID;

    /**
     * Localized, privacy aware social context string to go with the app suggestion.
     * Intended to be directly displayed in UI.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|CalApplicationSuggestion|Field")
    FString SocialContext;

    // Default ctor.
    FOvrCalApplicationSuggestion();

    // Copying values from an OVR handle.
    FOvrCalApplicationSuggestion(ovrCalApplicationSuggestionHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrCalApplicationSuggestionHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/** DEPRECATED. Will be removed from headers at version v49. */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|CloudStorageData")
struct OVRPLATFORM_API FOvrCloudStorageData
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|CloudStorageData|Field")
    FString Bucket;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|CloudStorageData|Field")
    TArray<uint8> Data;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|CloudStorageData|Field")
    int32 DataSize;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|CloudStorageData|Field")
    FString Key;

    // Default ctor.
    FOvrCloudStorageData();

    // Copying values from an OVR handle.
    FOvrCloudStorageData(ovrCloudStorageDataHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrCloudStorageDataHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/** DEPRECATED. Will be removed from headers at version v49. */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|CloudStorageMetadata")
struct OVRPLATFORM_API FOvrCloudStorageMetadata
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|CloudStorageMetadata|Field")
    FString Bucket;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|CloudStorageMetadata|Field")
    int64 Counter;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|CloudStorageMetadata|Field")
    int32 DataSize;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|CloudStorageMetadata|Field")
    FString ExtraData;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|CloudStorageMetadata|Field")
    FString Key;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|CloudStorageMetadata|Field")
    int64 SaveTime;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|CloudStorageMetadata|Field")
    EOvrCloudStorageDataStatus Status;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|CloudStorageMetadata|Field")
    FString VersionHandle;

    // Default ctor.
    FOvrCloudStorageMetadata();

    // Copying values from an OVR handle.
    FOvrCloudStorageMetadata(ovrCloudStorageMetadataHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrCloudStorageMetadataHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/** DEPRECATED. Will be removed from headers at version v49. */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|CloudStorageConflictMetadata")
struct OVRPLATFORM_API FOvrCloudStorageConflictMetadata
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|CloudStorageConflictMetadata|Field")
    FOvrCloudStorageMetadata Local;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|CloudStorageConflictMetadata|Field")
    FOvrCloudStorageMetadata Remote;

    // Default ctor.
    FOvrCloudStorageConflictMetadata();

    // Copying values from an OVR handle.
    FOvrCloudStorageConflictMetadata(ovrCloudStorageConflictMetadataHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrCloudStorageConflictMetadataHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};

USTRUCT(BlueprintType, Category = "OvrPlatform|Models|CloudStorageMetadataArray")
struct OVRPLATFORM_API FOvrCloudStorageMetadataPages
{
    GENERATED_USTRUCT_BODY()

    // Default ctor.
    FOvrCloudStorageMetadataPages();

    // Copying values from an OVR handle to the array, and the originating message
    // to prevent the handle from being freed.
    FOvrCloudStorageMetadataPages(ovrCloudStorageMetadataArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating values from an OVR handle to the array, and the originating message
    // to prevent the handle from being freed.
    void Update(ovrCloudStorageMetadataArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // OVR array handle for methods
    mutable ovrCloudStorageMetadataArrayHandle PagedArrayHandle;

    // Original ref-counted message to hold onto array handle
    mutable TOvrMessageHandlePtr PagedArrayMessageHandlePtr;
};

UCLASS()
class OVRPLATFORM_API UOvrCloudStorageMetadataPagesMethods : public UObject
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|CloudStorageMetadataPages")
    static FOvrCloudStorageMetadata CloudStorageMetadataPages_GetElement(const FOvrCloudStorageMetadataPages& Model, int64 Index);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|CloudStorageMetadataPages")
    static FString CloudStorageMetadataPages_GetNextUrl(const FOvrCloudStorageMetadataPages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|CloudStorageMetadataPages")
    static int64 CloudStorageMetadataPages_GetSize(const FOvrCloudStorageMetadataPages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|CloudStorageMetadataPages")
    static bool CloudStorageMetadataPages_HasNextPage(const FOvrCloudStorageMetadataPages& Model);
};


/** DEPRECATED. Will be removed from headers at version v49. */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|CloudStorageUpdateResponse")
struct OVRPLATFORM_API FOvrCloudStorageUpdateResponse
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|CloudStorageUpdateResponse|Field")
    FString Bucket;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|CloudStorageUpdateResponse|Field")
    FString Key;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|CloudStorageUpdateResponse|Field")
    EOvrCloudStorageUpdateStatus Status;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|CloudStorageUpdateResponse|Field")
    FString VersionHandle;

    // Default ctor.
    FOvrCloudStorageUpdateResponse();

    // Copying values from an OVR handle.
    FOvrCloudStorageUpdateResponse(ovrCloudStorageUpdateResponseHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrCloudStorageUpdateResponseHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|Destination")
struct OVRPLATFORM_API FOvrDestination
{
    GENERATED_USTRUCT_BODY()

    /**
     * Pass it into FOvrRichPresenceOptions::ApiName() when calling
     * RichPresence_Set() to set this user's rich presence
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Destination|Field")
    FString ApiName;

    /**
     * The information that will be in field FOvrLaunchDetails::DeeplinkMessage
     * when a user enters via a deeplink. Alternatively will be in field FOvrUser::PresenceDeeplinkMessage
     * if the rich presence is set for the user.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Destination|Field")
    FString DeeplinkMessage;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Destination|Field")
    FString DisplayName;

    // Default ctor.
    FOvrDestination();

    // Copying values from an OVR handle.
    FOvrDestination(ovrDestinationHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrDestinationHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};

USTRUCT(BlueprintType, Category = "OvrPlatform|Models|DestinationArray")
struct OVRPLATFORM_API FOvrDestinationPages
{
    GENERATED_USTRUCT_BODY()

    // Default ctor.
    FOvrDestinationPages();

    // Copying values from an OVR handle to the array, and the originating message
    // to prevent the handle from being freed.
    FOvrDestinationPages(ovrDestinationArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating values from an OVR handle to the array, and the originating message
    // to prevent the handle from being freed.
    void Update(ovrDestinationArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // OVR array handle for methods
    mutable ovrDestinationArrayHandle PagedArrayHandle;

    // Original ref-counted message to hold onto array handle
    mutable TOvrMessageHandlePtr PagedArrayMessageHandlePtr;
};

UCLASS()
class OVRPLATFORM_API UOvrDestinationPagesMethods : public UObject
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|DestinationPages")
    static FOvrDestination DestinationPages_GetElement(const FOvrDestinationPages& Model, int64 Index);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|DestinationPages")
    static FString DestinationPages_GetNextUrl(const FOvrDestinationPages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|DestinationPages")
    static int64 DestinationPages_GetSize(const FOvrDestinationPages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|DestinationPages")
    static bool DestinationPages_HasNextPage(const FOvrDestinationPages& Model);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|Error")
struct OVRPLATFORM_API FOvrError
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Error|Field")
    int32 Code;

    /**
     * Human readable description of the error that can be displayed to the user.
     * Might be the empty string if there is no user-appropriate description available.
     * Not intended to be parsed as it might change at any time or be translated.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Error|Field")
    FString DisplayableMessage;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Error|Field")
    int32 HttpCode;

    /**
     * Technical description of what went wrong intended for developers. For use in
     * logs or developer consoles.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Error|Field")
    FString Message;

    // Default ctor.
    FOvrError();

    // Copying values from an OVR handle.
    FOvrError(ovrErrorHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrErrorHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|GroupPresenceJoinIntent")
struct OVRPLATFORM_API FOvrGroupPresenceJoinIntent
{
    GENERATED_USTRUCT_BODY()

    /**
     * An opaque string provided by the developer to help them deeplink
     * to content.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|GroupPresenceJoinIntent|Field")
    FString DeeplinkMessage;

    /** If populated, the destination the current user wants to go to */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|GroupPresenceJoinIntent|Field")
    FString DestinationApiName;

    /** If populated, the lobby session the current user wants to go to */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|GroupPresenceJoinIntent|Field")
    FString LobbySessionId;

    /** If populated, the match session the current user wants to go to */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|GroupPresenceJoinIntent|Field")
    FString MatchSessionId;

    // Default ctor.
    FOvrGroupPresenceJoinIntent();

    // Copying values from an OVR handle.
    FOvrGroupPresenceJoinIntent(ovrGroupPresenceJoinIntentHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrGroupPresenceJoinIntentHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|GroupPresenceLeaveIntent")
struct OVRPLATFORM_API FOvrGroupPresenceLeaveIntent
{
    GENERATED_USTRUCT_BODY()

    /** If populated, the destination the current user wants to leave */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|GroupPresenceLeaveIntent|Field")
    FString DestinationApiName;

    /** If populated, the lobby session the current user wants to leave */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|GroupPresenceLeaveIntent|Field")
    FString LobbySessionId;

    /** If populated, the match session the current user wants to leave */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|GroupPresenceLeaveIntent|Field")
    FString MatchSessionId;

    // Default ctor.
    FOvrGroupPresenceLeaveIntent();

    // Copying values from an OVR handle.
    FOvrGroupPresenceLeaveIntent(ovrGroupPresenceLeaveIntentHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrGroupPresenceLeaveIntentHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|HttpTransferUpdate")
struct OVRPLATFORM_API FOvrHttpTransferUpdate
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|HttpTransferUpdate|Field")
    TArray<uint8> Bytes;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|HttpTransferUpdate|Field")
    FOvrId ID;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|HttpTransferUpdate|Field")
    bool IsCompleted;

    // Default ctor.
    FOvrHttpTransferUpdate();

    // Copying values from an OVR handle.
    FOvrHttpTransferUpdate(ovrHttpTransferUpdateHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrHttpTransferUpdateHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|InstalledApplication")
struct OVRPLATFORM_API FOvrInstalledApplication
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|InstalledApplication|Field")
    FString ApplicationId;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|InstalledApplication|Field")
    FString PackageName;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|InstalledApplication|Field")
    FString Status;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|InstalledApplication|Field")
    int32 VersionCode;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|InstalledApplication|Field")
    FString VersionName;

    // Default ctor.
    FOvrInstalledApplication();

    // Copying values from an OVR handle.
    FOvrInstalledApplication(ovrInstalledApplicationHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrInstalledApplicationHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|InvitePanelResultInfo")
struct OVRPLATFORM_API FOvrInvitePanelResultInfo
{
    GENERATED_USTRUCT_BODY()

    /** A boolean for whether or not any invites has been sent. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|InvitePanelResultInfo|Field")
    bool InvitesSent;

    // Default ctor.
    FOvrInvitePanelResultInfo();

    // Copying values from an OVR handle.
    FOvrInvitePanelResultInfo(ovrInvitePanelResultInfoHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrInvitePanelResultInfoHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|LanguagePackInfo")
struct OVRPLATFORM_API FOvrLanguagePackInfo
{
    GENERATED_USTRUCT_BODY()

    /** Language name in English language. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LanguagePackInfo|Field")
    FString EnglishName;

    /** Language name in the native language. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LanguagePackInfo|Field")
    FString NativeName;

    /** Language tag in BCP47 format. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LanguagePackInfo|Field")
    FString Tag;

    // Default ctor.
    FOvrLanguagePackInfo();

    // Copying values from an OVR handle.
    FOvrLanguagePackInfo(ovrLanguagePackInfoHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrLanguagePackInfoHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|AssetDetails")
struct OVRPLATFORM_API FOvrAssetDetails
{
    GENERATED_USTRUCT_BODY()

    /**  ID of the asset file */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AssetDetails|Field")
    FOvrId AssetId;

    /**
     * One of 'default', 'store', or 'language_pack'.
     * 
     * The 'default' type denotes this Asset File is used purely as an
     * implementation detail (to download extra content post-installation).
     * 
     * The 'store' type shows, that the Asset File should be shown in Store.
     * 
     * The 'language_pack' is a special type used to manage different languages and
     * translation data, which can be downloaded post-installation.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AssetDetails|Field")
    FString AssetType;

    /** One of 'installed', 'available', or 'in-progress' */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AssetDetails|Field")
    FString DownloadStatus;

    /** File path of the asset file */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AssetDetails|Field")
    FString Filepath;

    /** One of 'free', 'entitled', or 'not-entitled' */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AssetDetails|Field")
    FString IapStatus;

    /** For 'language_pack' assets type, contains language info. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AssetDetails|Field")
    FOvrLanguagePackInfo Language;

    /** Extra metadata associated with this asset file */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AssetDetails|Field")
    FString Metadata;

    // Default ctor.
    FOvrAssetDetails();

    // Copying values from an OVR handle.
    FOvrAssetDetails(ovrAssetDetailsHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrAssetDetailsHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|LaunchBlockFlowResult")
struct OVRPLATFORM_API FOvrLaunchBlockFlowResult
{
    GENERATED_USTRUCT_BODY()

    /** Whether the viewer successfully blocked the user. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LaunchBlockFlowResult|Field")
    bool DidBlock;

    /** Whether the viewer chose to cancel the block flow. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LaunchBlockFlowResult|Field")
    bool DidCancel;

    // Default ctor.
    FOvrLaunchBlockFlowResult();

    // Copying values from an OVR handle.
    FOvrLaunchBlockFlowResult(ovrLaunchBlockFlowResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrLaunchBlockFlowResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|LaunchFriendRequestFlowResult")
struct OVRPLATFORM_API FOvrLaunchFriendRequestFlowResult
{
    GENERATED_USTRUCT_BODY()

    /** Whether the viewer chose to cancel the friend request flow. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LaunchFriendRequestFlowResult|Field")
    bool DidCancel;

    /** Whether the viewer successfully sent the friend request. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LaunchFriendRequestFlowResult|Field")
    bool DidSendRequest;

    // Default ctor.
    FOvrLaunchFriendRequestFlowResult();

    // Copying values from an OVR handle.
    FOvrLaunchFriendRequestFlowResult(ovrLaunchFriendRequestFlowResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrLaunchFriendRequestFlowResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|LaunchReportFlowResult")
struct OVRPLATFORM_API FOvrLaunchReportFlowResult
{
    GENERATED_USTRUCT_BODY()

    /** Whether the viewer chose to cancel the report flow. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LaunchReportFlowResult|Field")
    bool DidCancel;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LaunchReportFlowResult|Field")
    FOvrId UserReportId;

    // Default ctor.
    FOvrLaunchReportFlowResult();

    // Copying values from an OVR handle.
    FOvrLaunchReportFlowResult(ovrLaunchReportFlowResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrLaunchReportFlowResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|LaunchUnblockFlowResult")
struct OVRPLATFORM_API FOvrLaunchUnblockFlowResult
{
    GENERATED_USTRUCT_BODY()

    /** Whether the viewer chose to cancel the unblock flow. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LaunchUnblockFlowResult|Field")
    bool DidCancel;

    /** Whether the viewer successfully unblocked the user. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LaunchUnblockFlowResult|Field")
    bool DidUnblock;

    // Default ctor.
    FOvrLaunchUnblockFlowResult();

    // Copying values from an OVR handle.
    FOvrLaunchUnblockFlowResult(ovrLaunchUnblockFlowResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrLaunchUnblockFlowResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|Leaderboard")
struct OVRPLATFORM_API FOvrLeaderboard
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Leaderboard|Field")
    FString ApiName;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Leaderboard|Field")
    FOvrDestination Destination;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Leaderboard|Field")
    FOvrId ID;

    // Default ctor.
    FOvrLeaderboard();

    // Copying values from an OVR handle.
    FOvrLeaderboard(ovrLeaderboardHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrLeaderboardHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};

USTRUCT(BlueprintType, Category = "OvrPlatform|Models|LeaderboardArray")
struct OVRPLATFORM_API FOvrLeaderboardPages
{
    GENERATED_USTRUCT_BODY()

    // Default ctor.
    FOvrLeaderboardPages();

    // Copying values from an OVR handle to the array, and the originating message
    // to prevent the handle from being freed.
    FOvrLeaderboardPages(ovrLeaderboardArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating values from an OVR handle to the array, and the originating message
    // to prevent the handle from being freed.
    void Update(ovrLeaderboardArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // OVR array handle for methods
    mutable ovrLeaderboardArrayHandle PagedArrayHandle;

    // Original ref-counted message to hold onto array handle
    mutable TOvrMessageHandlePtr PagedArrayMessageHandlePtr;
};

UCLASS()
class OVRPLATFORM_API UOvrLeaderboardPagesMethods : public UObject
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|LeaderboardPages")
    static FOvrLeaderboard LeaderboardPages_GetElement(const FOvrLeaderboardPages& Model, int64 Index);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|LeaderboardPages")
    static FString LeaderboardPages_GetNextUrl(const FOvrLeaderboardPages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|LeaderboardPages")
    static int64 LeaderboardPages_GetSize(const FOvrLeaderboardPages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|LeaderboardPages")
    static bool LeaderboardPages_HasNextPage(const FOvrLeaderboardPages& Model);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|LeaderboardUpdateStatus")
struct OVRPLATFORM_API FOvrLeaderboardUpdateStatus
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LeaderboardUpdateStatus|Field")
    bool DidUpdate;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LeaderboardUpdateStatus|Field")
    TArray<FOvrId> UpdatedChallengeIds;

    // Default ctor.
    FOvrLeaderboardUpdateStatus();

    // Copying values from an OVR handle.
    FOvrLeaderboardUpdateStatus(ovrLeaderboardUpdateStatusHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrLeaderboardUpdateStatusHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|LinkedAccount")
struct OVRPLATFORM_API FOvrLinkedAccount
{
    GENERATED_USTRUCT_BODY()

    /** Access token of the linked account. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LinkedAccount|Field")
    FString AccessToken;

    /** Service provider with which the linked account is associated. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LinkedAccount|Field")
    EOvrServiceProvider ServiceProvider;

    /** User ID of the linked account. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LinkedAccount|Field")
    FString UserId;

    // Default ctor.
    FOvrLinkedAccount();

    // Copying values from an OVR handle.
    FOvrLinkedAccount(ovrLinkedAccountHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrLinkedAccountHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|LivestreamingApplicationStatus")
struct OVRPLATFORM_API FOvrLivestreamingApplicationStatus
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LivestreamingApplicationStatus|Field")
    bool StreamingEnabled;

    // Default ctor.
    FOvrLivestreamingApplicationStatus();

    // Copying values from an OVR handle.
    FOvrLivestreamingApplicationStatus(ovrLivestreamingApplicationStatusHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrLivestreamingApplicationStatusHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|LivestreamingStartResult")
struct OVRPLATFORM_API FOvrLivestreamingStartResult
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LivestreamingStartResult|Field")
    EOvrLivestreamingStartStatus StreamingResult;

    // Default ctor.
    FOvrLivestreamingStartResult();

    // Copying values from an OVR handle.
    FOvrLivestreamingStartResult(ovrLivestreamingStartResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrLivestreamingStartResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|LivestreamingStatus")
struct OVRPLATFORM_API FOvrLivestreamingStatus
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LivestreamingStatus|Field")
    bool CommentsVisible;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LivestreamingStatus|Field")
    bool IsPaused;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LivestreamingStatus|Field")
    bool LivestreamingEnabled;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LivestreamingStatus|Field")
    int32 LivestreamingType;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LivestreamingStatus|Field")
    bool MicEnabled;

    // Default ctor.
    FOvrLivestreamingStatus();

    // Copying values from an OVR handle.
    FOvrLivestreamingStatus(ovrLivestreamingStatusHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrLivestreamingStatusHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|LivestreamingVideoStats")
struct OVRPLATFORM_API FOvrLivestreamingVideoStats
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LivestreamingVideoStats|Field")
    int32 CommentCount;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LivestreamingVideoStats|Field")
    int32 ReactionCount;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LivestreamingVideoStats|Field")
    FString TotalViews;

    // Default ctor.
    FOvrLivestreamingVideoStats();

    // Copying values from an OVR handle.
    FOvrLivestreamingVideoStats(ovrLivestreamingVideoStatsHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrLivestreamingVideoStatsHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/** DEPRECATED. Will be removed from headers at version v49. */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|MatchmakingAdminSnapshotCandidate")
struct OVRPLATFORM_API FOvrMatchmakingAdminSnapshotCandidate
{
    GENERATED_USTRUCT_BODY()

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|MatchmakingAdminSnapshotCandidate|Field")
    bool CanMatch;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|MatchmakingAdminSnapshotCandidate|Field")
    float MyTotalScore;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|MatchmakingAdminSnapshotCandidate|Field")
    float TheirCurrentThreshold;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|MatchmakingAdminSnapshotCandidate|Field")
    float TheirTotalScore;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|MatchmakingAdminSnapshotCandidate|Field")
    FString TraceId;

    // Default ctor.
    FOvrMatchmakingAdminSnapshotCandidate();

    // Copying values from an OVR handle.
    FOvrMatchmakingAdminSnapshotCandidate(ovrMatchmakingAdminSnapshotCandidateHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrMatchmakingAdminSnapshotCandidateHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/** DEPRECATED. Will be removed from headers at version v49. */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|MatchmakingAdminSnapshot")
struct OVRPLATFORM_API FOvrMatchmakingAdminSnapshot
{
    GENERATED_USTRUCT_BODY()

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|MatchmakingAdminSnapshot|Field")
    TArray<FOvrMatchmakingAdminSnapshotCandidate> Candidates;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|MatchmakingAdminSnapshot|Field")
    float MyCurrentThreshold;

    // Default ctor.
    FOvrMatchmakingAdminSnapshot();

    // Copying values from an OVR handle.
    FOvrMatchmakingAdminSnapshot(ovrMatchmakingAdminSnapshotHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrMatchmakingAdminSnapshotHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/** DEPRECATED. Will be removed from headers at version v49. */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|MatchmakingEnqueueResult")
struct OVRPLATFORM_API FOvrMatchmakingEnqueueResult
{
    GENERATED_USTRUCT_BODY()

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * If 'IsDebug' is set in ovrMatchmakingOptionsHandle, this will return with the
     * enqueue results.
     */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|MatchmakingEnqueueResult|Field")
    FOvrMatchmakingAdminSnapshot AdminSnapshot;

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * The average amount of time (mean average) that users in this queue have waited
     * during the last hour or more. The wait times, whether the users canceled or found a
     * match, are used to generate this value. Use this to give users an indication
     * of how long they can expect to wait.
     */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|MatchmakingEnqueueResult|Field")
    int32 AverageWait;

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * The number of matches made from the pool the user is participating in.
     * You can use this to give users an indication of whether they should
     * bother to wait.
     */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|MatchmakingEnqueueResult|Field")
    int32 MatchesInLastHourCount;

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * The amount of time the 95th percentile waited during the last hour or more.
     * The wait times, whether the users canceled or found a match, are used to generate
     * this value. Use this to give users an indication of the maximum amount of time they
     * can expect to wait.
     */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|MatchmakingEnqueueResult|Field")
    int32 MaxExpectedWait;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|MatchmakingEnqueueResult|Field")
    FString Pool;

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * Percentage of people in the same queue as the user who
     * got matched, from 0 to 100 percent.  Stats are taken from the last hour or more.  You
     * can use this to give users an indication of whether they should wait.
     */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|MatchmakingEnqueueResult|Field")
    int32 RecentMatchPercentage;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|MatchmakingEnqueueResult|Field")
    FString RequestHash;

    // Default ctor.
    FOvrMatchmakingEnqueueResult();

    // Copying values from an OVR handle.
    FOvrMatchmakingEnqueueResult(ovrMatchmakingEnqueueResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrMatchmakingEnqueueResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/** DEPRECATED. Will be removed from headers at version v49. */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|MatchmakingStats")
struct OVRPLATFORM_API FOvrMatchmakingStats
{
    GENERATED_USTRUCT_BODY()

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|MatchmakingStats|Field")
    int32 DrawCount;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|MatchmakingStats|Field")
    int32 LossCount;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|MatchmakingStats|Field")
    int32 SkillLevel;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|MatchmakingStats|Field")
    float SkillMean;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|MatchmakingStats|Field")
    float SkillStandardDeviation;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|MatchmakingStats|Field")
    int32 WinCount;

    // Default ctor.
    FOvrMatchmakingStats();

    // Copying values from an OVR handle.
    FOvrMatchmakingStats(ovrMatchmakingStatsHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrMatchmakingStatsHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|Microphone")
struct OVRPLATFORM_API FOvrMicrophone
{
    GENERATED_USTRUCT_BODY()

    // Default ctor.
    FOvrMicrophone();

    // Copying values from an OVR handle.
    FOvrMicrophone(ovrMicrophoneHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrMicrophoneHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // OVR Handle for methods
    ovrMicrophoneHandle Handle;
};

UCLASS()
class OVRPLATFORM_API UOvrMicrophoneMethods : public UObject
{
    GENERATED_BODY()

public:

    /**
     *  Returns the minimum number of samples available to be read.
     * This function is inherently racy, it is possible that more samples
     * may be returned by the next call to getPCM.  This function is only implemented on Android.
     * Windows will always return 0.
     */
    /*
     * Not exposed to blueprints, call C API directly: size_t ovr_Microphone_GetNumSamplesAvailable(const ovrMicrophoneHandle obj);
     */

    /**
     * Returns the size of the internal ringbuffer used by the microhone in elements.  This size is the maximum
     * number of elements that can ever be returned by field FOvrMicrophone::GetPCM*.
     * 
     * 
     * This function can be safely called from any thread.
     */
    /*
     * Not exposed to blueprints, call C API directly: size_t ovr_Microphone_GetOutputBufferMaxSize(const ovrMicrophoneHandle obj);
     */

    /**
     * Gets all available samples of microphone data and
     * copies it into outputBuffer. The microphone will generate data at roughly
     * the rate of 480 samples per 10ms. The data format is 16 bit fixed point 48khz mono.
     * 
     * 
     * This function can be safely called from any thread.
     */
    /*
     * Not exposed to blueprints, call C API directly: size_t ovr_Microphone_GetPCM(const ovrMicrophoneHandle obj, int16_t *outputBuffer, size_t outputBufferNumElements);
     */

    /**
     * Gets all available samples of microphone data and
     * copies it into outputBuffer. The microphone will generate data at roughly
     * the rate of 480 samples per 10ms. The data format is 32 bit floating point 48khz mono.
     * 
     * 
     * This function can be safely called from any thread.
     */
    /*
     * Not exposed to blueprints, call C API directly: size_t ovr_Microphone_GetPCMFloat(const ovrMicrophoneHandle obj, float *outputBuffer, size_t outputBufferNumElements);
     */

    /**
     * DEPRECATED. Use field FOvrMicrophone::GetPCMFloat instead.
     * Gets all available samples of microphone data and
     * copies it into outputBuffer. The microphone will generate data at roughly
     * the rate of 480 samples per 10ms. The data format is 32 bit floating point 48khz mono.
     * 
     * 
     * This function can be safely called from any thread.
     */
    /*
     * Not exposed to blueprints, call C API directly: size_t ovr_Microphone_ReadData(const ovrMicrophoneHandle obj, float *outputBuffer, size_t outputBufferSize);
     */

    /**
     * Indicates that the caller is fine with a certain delay in the
     * delivery of recorded audio frames.  Setting this to a low value will
     * reduce the latency at the cost of efficiency.  Note that this is only
     * a hint; the actual implementation may ignore it.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|Microphone")
    static void Microphone_SetAcceptableRecordingDelayHint(FOvrMicrophone& Model, int64 DelayMs);

    /** Register a callback that will be called whenever audio data is available for the microphone. */
    /*
     * Not exposed to blueprints, call C API directly: void ovr_Microphone_SetAudioDataAvailableCallback(const ovrMicrophoneHandle obj, MicrophoneDataAvailableCallback cb, void *userData);
     */

    /**
     * Starts microphone recording.  After this is called pcm data can be extracted using
     * field FOvrMicrophone::GetPCM.
     * 
     * 
     * This function can be safely called from any thread.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|Microphone")
    static void Microphone_Start(FOvrMicrophone& Model);

    /**
     * Stops microphone recording.
     * 
     * 
     * This function can be safely called from any thread.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|Microphone")
    static void Microphone_Stop(FOvrMicrophone& Model);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|MicrophoneAvailabilityState")
struct OVRPLATFORM_API FOvrMicrophoneAvailabilityState
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|MicrophoneAvailabilityState|Field")
    bool MicrophoneAvailable;

    // Default ctor.
    FOvrMicrophoneAvailabilityState();

    // Copying values from an OVR handle.
    FOvrMicrophoneAvailabilityState(ovrMicrophoneAvailabilityStateHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrMicrophoneAvailabilityStateHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|NetSyncConnection")
struct OVRPLATFORM_API FOvrNetSyncConnection
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|NetSyncConnection|Field")
    int64 ConnectionId;

    /** If status is Disconnected, specifies the reason. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|NetSyncConnection|Field")
    EOvrNetSyncDisconnectReason DisconnectReason;

    /**
     * The ID of the local session. Will be null if the connection is not
     * active
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|NetSyncConnection|Field")
    FOvrId SessionId;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|NetSyncConnection|Field")
    EOvrNetSyncConnectionStatus Status;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|NetSyncConnection|Field")
    FString ZoneId;

    // Default ctor.
    FOvrNetSyncConnection();

    // Copying values from an OVR handle.
    FOvrNetSyncConnection(ovrNetSyncConnectionHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrNetSyncConnectionHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|NetSyncSession")
struct OVRPLATFORM_API FOvrNetSyncSession
{
    GENERATED_USTRUCT_BODY()

    /** Which connection this session exists within */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|NetSyncSession|Field")
    int64 ConnectionId;

    /** True if the local session has muted this session. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|NetSyncSession|Field")
    bool Muted;

    /** The cloud networking internal session ID that represents this connection. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|NetSyncSession|Field")
    FOvrId SessionId;

    /** The ovrID of the user behind this session */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|NetSyncSession|Field")
    FOvrId UserId;

    /** The name of the voip group that this session is subscribed to */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|NetSyncSession|Field")
    FString VoipGroup;

    // Default ctor.
    FOvrNetSyncSession();

    // Copying values from an OVR handle.
    FOvrNetSyncSession(ovrNetSyncSessionHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrNetSyncSessionHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|NetSyncSessionsChangedNotification")
struct OVRPLATFORM_API FOvrNetSyncSessionsChangedNotification
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|NetSyncSessionsChangedNotification|Field")
    int64 ConnectionId;

    /** The new list of sessions */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|NetSyncSessionsChangedNotification|Field")
    TArray<FOvrNetSyncSession> Sessions;

    // Default ctor.
    FOvrNetSyncSessionsChangedNotification();

    // Copying values from an OVR handle.
    FOvrNetSyncSessionsChangedNotification(ovrNetSyncSessionsChangedNotificationHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrNetSyncSessionsChangedNotificationHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|NetSyncSetSessionPropertyResult")
struct OVRPLATFORM_API FOvrNetSyncSetSessionPropertyResult
{
    GENERATED_USTRUCT_BODY()

    /** Which session the operation was modifying */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|NetSyncSetSessionPropertyResult|Field")
    FOvrNetSyncSession Session;

    // Default ctor.
    FOvrNetSyncSetSessionPropertyResult();

    // Copying values from an OVR handle.
    FOvrNetSyncSetSessionPropertyResult(ovrNetSyncSetSessionPropertyResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrNetSyncSetSessionPropertyResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|NetSyncVoipAttenuationValue")
struct OVRPLATFORM_API FOvrNetSyncVoipAttenuationValue
{
    GENERATED_USTRUCT_BODY()

    /** decibel fall-off value */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|NetSyncVoipAttenuationValue|Field")
    float Decibels;

    /** The starting distance of this attenuation value */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|NetSyncVoipAttenuationValue|Field")
    float Distance;

    // Default ctor.
    FOvrNetSyncVoipAttenuationValue();

    // Copying values from an OVR handle.
    FOvrNetSyncVoipAttenuationValue(ovrNetSyncVoipAttenuationValueHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrNetSyncVoipAttenuationValueHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|NetworkingPeer")
struct OVRPLATFORM_API FOvrNetworkingPeer
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|NetworkingPeer|Field")
    FOvrId ID;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|NetworkingPeer|Field")
    EOvrPeerConnectionState State;

    // Default ctor.
    FOvrNetworkingPeer();

    // Copying values from an OVR handle.
    FOvrNetworkingPeer(ovrNetworkingPeerHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrNetworkingPeerHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|OrgScopedID")
struct OVRPLATFORM_API FOvrOrgScopedID
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|OrgScopedID|Field")
    FOvrId ID;

    // Default ctor.
    FOvrOrgScopedID();

    // Copying values from an OVR handle.
    FOvrOrgScopedID(ovrOrgScopedIDHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrOrgScopedIDHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|Packet")
struct OVRPLATFORM_API FOvrPacket
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Packet|Field")
    TArray<uint8> Bytes;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Packet|Field")
    EOvrSendPolicy SendPolicy;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Packet|Field")
    FOvrId SenderID;

    // Default ctor.
    FOvrPacket();

    // Copying values from an OVR handle.
    FOvrPacket(ovrPacketHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrPacketHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // OVR Handle for methods
    ovrPacketHandle Handle;
};

UCLASS()
class OVRPLATFORM_API UOvrPacketMethods : public UObject
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|Packet")
    static void Packet_Free(FOvrPacket& Model);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|PartyID")
struct OVRPLATFORM_API FOvrPartyID
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|PartyID|Field")
    FOvrId ID;

    // Default ctor.
    FOvrPartyID();

    // Copying values from an OVR handle.
    FOvrPartyID(ovrPartyIDHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrPartyIDHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|PartyUpdateNotification")
struct OVRPLATFORM_API FOvrPartyUpdateNotification
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|PartyUpdateNotification|Field")
    EOvrPartyUpdateAction Action;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|PartyUpdateNotification|Field")
    FOvrId PartyId;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|PartyUpdateNotification|Field")
    FOvrId SenderId;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|PartyUpdateNotification|Field")
    FString UpdateTimestamp;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|PartyUpdateNotification|Field")
    FString UserAlias;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|PartyUpdateNotification|Field")
    FOvrId UserId;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|PartyUpdateNotification|Field")
    FString UserName;

    // Default ctor.
    FOvrPartyUpdateNotification();

    // Copying values from an OVR handle.
    FOvrPartyUpdateNotification(ovrPartyUpdateNotificationHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrPartyUpdateNotificationHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|Pid")
struct OVRPLATFORM_API FOvrPid
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Pid|Field")
    FString Id;

    // Default ctor.
    FOvrPid();

    // Copying values from an OVR handle.
    FOvrPid(ovrPidHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrPidHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|PingResult")
struct OVRPLATFORM_API FOvrPingResult
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|PingResult|Field")
    FOvrId ID;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|PingResult|Field")
    bool IsTimeout;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|PingResult|Field")
    int64 PingTimeUsec;

    // Default ctor.
    FOvrPingResult();

    // Copying values from an OVR handle.
    FOvrPingResult(ovrPingResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrPingResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|PlatformInitialize")
struct OVRPLATFORM_API FOvrPlatformInitialize
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|PlatformInitialize|Field")
    EOvrPlatformInitializeResult Result;

    // Default ctor.
    FOvrPlatformInitialize();

    // Copying values from an OVR handle.
    FOvrPlatformInitialize(ovrPlatformInitializeHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrPlatformInitializeHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|Product")
struct OVRPLATFORM_API FOvrProduct
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Product|Field")
    FString Description;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Product|Field")
    FString FormattedPrice;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Product|Field")
    FString Name;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Product|Field")
    FString SKU;

    // Default ctor.
    FOvrProduct();

    // Copying values from an OVR handle.
    FOvrProduct(ovrProductHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrProductHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};

USTRUCT(BlueprintType, Category = "OvrPlatform|Models|ProductArray")
struct OVRPLATFORM_API FOvrProductPages
{
    GENERATED_USTRUCT_BODY()

    // Default ctor.
    FOvrProductPages();

    // Copying values from an OVR handle to the array, and the originating message
    // to prevent the handle from being freed.
    FOvrProductPages(ovrProductArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating values from an OVR handle to the array, and the originating message
    // to prevent the handle from being freed.
    void Update(ovrProductArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // OVR array handle for methods
    mutable ovrProductArrayHandle PagedArrayHandle;

    // Original ref-counted message to hold onto array handle
    mutable TOvrMessageHandlePtr PagedArrayMessageHandlePtr;
};

UCLASS()
class OVRPLATFORM_API UOvrProductPagesMethods : public UObject
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ProductPages")
    static FOvrProduct ProductPages_GetElement(const FOvrProductPages& Model, int64 Index);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ProductPages")
    static FString ProductPages_GetNextUrl(const FOvrProductPages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ProductPages")
    static int64 ProductPages_GetSize(const FOvrProductPages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ProductPages")
    static bool ProductPages_HasNextPage(const FOvrProductPages& Model);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|Purchase")
struct OVRPLATFORM_API FOvrPurchase
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Purchase|Field")
    FDateTime ExpirationTime;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Purchase|Field")
    FDateTime GrantTime;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Purchase|Field")
    FString PurchaseID;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Purchase|Field")
    FString SKU;

    // Default ctor.
    FOvrPurchase();

    // Copying values from an OVR handle.
    FOvrPurchase(ovrPurchaseHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrPurchaseHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};

USTRUCT(BlueprintType, Category = "OvrPlatform|Models|PurchaseArray")
struct OVRPLATFORM_API FOvrPurchasePages
{
    GENERATED_USTRUCT_BODY()

    // Default ctor.
    FOvrPurchasePages();

    // Copying values from an OVR handle to the array, and the originating message
    // to prevent the handle from being freed.
    FOvrPurchasePages(ovrPurchaseArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating values from an OVR handle to the array, and the originating message
    // to prevent the handle from being freed.
    void Update(ovrPurchaseArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // OVR array handle for methods
    mutable ovrPurchaseArrayHandle PagedArrayHandle;

    // Original ref-counted message to hold onto array handle
    mutable TOvrMessageHandlePtr PagedArrayMessageHandlePtr;
};

UCLASS()
class OVRPLATFORM_API UOvrPurchasePagesMethods : public UObject
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|PurchasePages")
    static FOvrPurchase PurchasePages_GetElement(const FOvrPurchasePages& Model, int64 Index);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|PurchasePages")
    static FString PurchasePages_GetNextUrl(const FOvrPurchasePages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|PurchasePages")
    static int64 PurchasePages_GetSize(const FOvrPurchasePages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|PurchasePages")
    static bool PurchasePages_HasNextPage(const FOvrPurchasePages& Model);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|RejoinDialogResult")
struct OVRPLATFORM_API FOvrRejoinDialogResult
{
    GENERATED_USTRUCT_BODY()

    /** A boolean for if the user decided to rejoin. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|RejoinDialogResult|Field")
    bool RejoinSelected;

    // Default ctor.
    FOvrRejoinDialogResult();

    // Copying values from an OVR handle.
    FOvrRejoinDialogResult(ovrRejoinDialogResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrRejoinDialogResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/** DEPRECATED. Will be removed from headers at version v49. */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|RoomInviteNotification")
struct OVRPLATFORM_API FOvrRoomInviteNotification
{
    GENERATED_USTRUCT_BODY()

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|RoomInviteNotification|Field")
    FOvrId ID;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|RoomInviteNotification|Field")
    FOvrId RoomID;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|RoomInviteNotification|Field")
    FOvrId SenderID;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|RoomInviteNotification|Field")
    FDateTime SentTime;

    // Default ctor.
    FOvrRoomInviteNotification();

    // Copying values from an OVR handle.
    FOvrRoomInviteNotification(ovrRoomInviteNotificationHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrRoomInviteNotificationHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};

USTRUCT(BlueprintType, Category = "OvrPlatform|Models|RoomInviteNotificationArray")
struct OVRPLATFORM_API FOvrRoomInviteNotificationPages
{
    GENERATED_USTRUCT_BODY()

    // Default ctor.
    FOvrRoomInviteNotificationPages();

    // Copying values from an OVR handle to the array, and the originating message
    // to prevent the handle from being freed.
    FOvrRoomInviteNotificationPages(ovrRoomInviteNotificationArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating values from an OVR handle to the array, and the originating message
    // to prevent the handle from being freed.
    void Update(ovrRoomInviteNotificationArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // OVR array handle for methods
    mutable ovrRoomInviteNotificationArrayHandle PagedArrayHandle;

    // Original ref-counted message to hold onto array handle
    mutable TOvrMessageHandlePtr PagedArrayMessageHandlePtr;
};

UCLASS()
class OVRPLATFORM_API UOvrRoomInviteNotificationPagesMethods : public UObject
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|RoomInviteNotificationPages")
    static FOvrRoomInviteNotification RoomInviteNotificationPages_GetElement(const FOvrRoomInviteNotificationPages& Model, int64 Index);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|RoomInviteNotificationPages")
    static FString RoomInviteNotificationPages_GetNextUrl(const FOvrRoomInviteNotificationPages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|RoomInviteNotificationPages")
    static int64 RoomInviteNotificationPages_GetSize(const FOvrRoomInviteNotificationPages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|RoomInviteNotificationPages")
    static bool RoomInviteNotificationPages_HasNextPage(const FOvrRoomInviteNotificationPages& Model);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|SdkAccount")
struct OVRPLATFORM_API FOvrSdkAccount
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|SdkAccount|Field")
    EOvrSdkAccountType AccountType;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|SdkAccount|Field")
    FOvrId UserId;

    // Default ctor.
    FOvrSdkAccount();

    // Copying values from an OVR handle.
    FOvrSdkAccount(ovrSdkAccountHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrSdkAccountHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|ShareMediaResult")
struct OVRPLATFORM_API FOvrShareMediaResult
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ShareMediaResult|Field")
    EOvrShareMediaStatus Status;

    // Default ctor.
    FOvrShareMediaResult();

    // Copying values from an OVR handle.
    FOvrShareMediaResult(ovrShareMediaResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrShareMediaResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|SupplementaryMetric")
struct OVRPLATFORM_API FOvrSupplementaryMetric
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|SupplementaryMetric|Field")
    FOvrId ID;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|SupplementaryMetric|Field")
    int64 Metric;

    // Default ctor.
    FOvrSupplementaryMetric();

    // Copying values from an OVR handle.
    FOvrSupplementaryMetric(ovrSupplementaryMetricHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrSupplementaryMetricHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|SystemVoipState")
struct OVRPLATFORM_API FOvrSystemVoipState
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|SystemVoipState|Field")
    EOvrVoipMuteState MicrophoneMuted;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|SystemVoipState|Field")
    EOvrSystemVoipStatus Status;

    // Default ctor.
    FOvrSystemVoipState();

    // Copying values from an OVR handle.
    FOvrSystemVoipState(ovrSystemVoipStateHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrSystemVoipStateHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|User")
struct OVRPLATFORM_API FOvrUser
{
    GENERATED_USTRUCT_BODY()

    /**
     * A potentially non unique displayable name chosen by the user.
     * Could also be the same as the oculus_ID
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|User|Field")
    FString DisplayName;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|User|Field")
    FOvrId ID;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|User|Field")
    FString ImageUrl;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|User|Field")
    FString InviteToken;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|User|Field")
    FString OculusID;

    /**
     * Human readable string of what the user is currently doing.
     * Not intended to be parsed as it might change at anytime or be translated
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|User|Field")
    FString Presence;

    /** Intended to be parsed and used to deeplink to parts of the app */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|User|Field")
    FString PresenceDeeplinkMessage;

    /** If provided, the destination this user is currently at in the app */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|User|Field")
    FString PresenceDestinationApiName;

    /** If provided, the lobby session this user is currently at in the app */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|User|Field")
    FString PresenceLobbySessionId;

    /** If provided, the match session this user is currently at in the app */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|User|Field")
    FString PresenceMatchSessionId;

    /** Enum value of what the user is currently doing. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|User|Field")
    EOvrUserPresenceStatus PresenceStatus;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|User|Field")
    FString SmallImageUrl;

    // Default ctor.
    FOvrUser();

    // Copying values from an OVR handle.
    FOvrUser(ovrUserHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrUserHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|ApplicationInvite")
struct OVRPLATFORM_API FOvrApplicationInvite
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ApplicationInvite|Field")
    FOvrDestination Destination;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ApplicationInvite|Field")
    FOvrId ID;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ApplicationInvite|Field")
    bool IsActive;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ApplicationInvite|Field")
    FString LobbySessionId;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ApplicationInvite|Field")
    FString MatchSessionId;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ApplicationInvite|Field")
    FOvrUser Recipient;

    // Default ctor.
    FOvrApplicationInvite();

    // Copying values from an OVR handle.
    FOvrApplicationInvite(ovrApplicationInviteHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrApplicationInviteHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};

USTRUCT(BlueprintType, Category = "OvrPlatform|Models|ApplicationInviteArray")
struct OVRPLATFORM_API FOvrApplicationInvitePages
{
    GENERATED_USTRUCT_BODY()

    // Default ctor.
    FOvrApplicationInvitePages();

    // Copying values from an OVR handle to the array, and the originating message
    // to prevent the handle from being freed.
    FOvrApplicationInvitePages(ovrApplicationInviteArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating values from an OVR handle to the array, and the originating message
    // to prevent the handle from being freed.
    void Update(ovrApplicationInviteArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // OVR array handle for methods
    mutable ovrApplicationInviteArrayHandle PagedArrayHandle;

    // Original ref-counted message to hold onto array handle
    mutable TOvrMessageHandlePtr PagedArrayMessageHandlePtr;
};

UCLASS()
class OVRPLATFORM_API UOvrApplicationInvitePagesMethods : public UObject
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ApplicationInvitePages")
    static FOvrApplicationInvite ApplicationInvitePages_GetElement(const FOvrApplicationInvitePages& Model, int64 Index);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ApplicationInvitePages")
    static FString ApplicationInvitePages_GetNextUrl(const FOvrApplicationInvitePages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ApplicationInvitePages")
    static int64 ApplicationInvitePages_GetSize(const FOvrApplicationInvitePages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ApplicationInvitePages")
    static bool ApplicationInvitePages_HasNextPage(const FOvrApplicationInvitePages& Model);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|ChallengeEntry")
struct OVRPLATFORM_API FOvrChallengeEntry
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ChallengeEntry|Field")
    FString DisplayScore;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ChallengeEntry|Field")
    TArray<uint8> ExtraData;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ChallengeEntry|Field")
    FOvrId ID;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ChallengeEntry|Field")
    int32 Rank;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ChallengeEntry|Field")
    int64 Score;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ChallengeEntry|Field")
    FDateTime Timestamp;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ChallengeEntry|Field")
    FOvrUser User;

    // Default ctor.
    FOvrChallengeEntry();

    // Copying values from an OVR handle.
    FOvrChallengeEntry(ovrChallengeEntryHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrChallengeEntryHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};

USTRUCT(BlueprintType, Category = "OvrPlatform|Models|ChallengeEntryArray")
struct OVRPLATFORM_API FOvrChallengeEntryPages
{
    GENERATED_USTRUCT_BODY()

    // Default ctor.
    FOvrChallengeEntryPages();

    // Copying values from an OVR handle to the array, and the originating message
    // to prevent the handle from being freed.
    FOvrChallengeEntryPages(ovrChallengeEntryArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating values from an OVR handle to the array, and the originating message
    // to prevent the handle from being freed.
    void Update(ovrChallengeEntryArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // OVR array handle for methods
    mutable ovrChallengeEntryArrayHandle PagedArrayHandle;

    // Original ref-counted message to hold onto array handle
    mutable TOvrMessageHandlePtr PagedArrayMessageHandlePtr;
};

UCLASS()
class OVRPLATFORM_API UOvrChallengeEntryPagesMethods : public UObject
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ChallengeEntryPages")
    static FOvrChallengeEntry ChallengeEntryPages_GetElement(const FOvrChallengeEntryPages& Model, int64 Index);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ChallengeEntryPages")
    static FString ChallengeEntryPages_GetNextUrl(const FOvrChallengeEntryPages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ChallengeEntryPages")
    static FString ChallengeEntryPages_GetPreviousUrl(const FOvrChallengeEntryPages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ChallengeEntryPages")
    static int64 ChallengeEntryPages_GetSize(const FOvrChallengeEntryPages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ChallengeEntryPages")
    static int64 ChallengeEntryPages_GetTotalCount(const FOvrChallengeEntryPages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ChallengeEntryPages")
    static bool ChallengeEntryPages_HasNextPage(const FOvrChallengeEntryPages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ChallengeEntryPages")
    static bool ChallengeEntryPages_HasPreviousPage(const FOvrChallengeEntryPages& Model);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|LeaderboardEntry")
struct OVRPLATFORM_API FOvrLeaderboardEntry
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LeaderboardEntry|Field")
    FString DisplayScore;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LeaderboardEntry|Field")
    TArray<uint8> ExtraData;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LeaderboardEntry|Field")
    FOvrId ID;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LeaderboardEntry|Field")
    int32 Rank;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LeaderboardEntry|Field")
    int64 Score;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LeaderboardEntry|Field")
    FOvrSupplementaryMetric SupplementaryMetric;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LeaderboardEntry|Field")
    FDateTime Timestamp;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LeaderboardEntry|Field")
    FOvrUser User;

    // Default ctor.
    FOvrLeaderboardEntry();

    // Copying values from an OVR handle.
    FOvrLeaderboardEntry(ovrLeaderboardEntryHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrLeaderboardEntryHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};

USTRUCT(BlueprintType, Category = "OvrPlatform|Models|LeaderboardEntryArray")
struct OVRPLATFORM_API FOvrLeaderboardEntryPages
{
    GENERATED_USTRUCT_BODY()

    // Default ctor.
    FOvrLeaderboardEntryPages();

    // Copying values from an OVR handle to the array, and the originating message
    // to prevent the handle from being freed.
    FOvrLeaderboardEntryPages(ovrLeaderboardEntryArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating values from an OVR handle to the array, and the originating message
    // to prevent the handle from being freed.
    void Update(ovrLeaderboardEntryArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // OVR array handle for methods
    mutable ovrLeaderboardEntryArrayHandle PagedArrayHandle;

    // Original ref-counted message to hold onto array handle
    mutable TOvrMessageHandlePtr PagedArrayMessageHandlePtr;
};

UCLASS()
class OVRPLATFORM_API UOvrLeaderboardEntryPagesMethods : public UObject
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|LeaderboardEntryPages")
    static FOvrLeaderboardEntry LeaderboardEntryPages_GetElement(const FOvrLeaderboardEntryPages& Model, int64 Index);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|LeaderboardEntryPages")
    static FString LeaderboardEntryPages_GetNextUrl(const FOvrLeaderboardEntryPages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|LeaderboardEntryPages")
    static FString LeaderboardEntryPages_GetPreviousUrl(const FOvrLeaderboardEntryPages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|LeaderboardEntryPages")
    static int64 LeaderboardEntryPages_GetSize(const FOvrLeaderboardEntryPages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|LeaderboardEntryPages")
    static int64 LeaderboardEntryPages_GetTotalCount(const FOvrLeaderboardEntryPages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|LeaderboardEntryPages")
    static bool LeaderboardEntryPages_HasNextPage(const FOvrLeaderboardEntryPages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|LeaderboardEntryPages")
    static bool LeaderboardEntryPages_HasPreviousPage(const FOvrLeaderboardEntryPages& Model);
};


/** DEPRECATED. Will be removed from headers at version v49. */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|MatchmakingEnqueuedUser")
struct OVRPLATFORM_API FOvrMatchmakingEnqueuedUser
{
    GENERATED_USTRUCT_BODY()

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|MatchmakingEnqueuedUser|Field")
    TArray<FOvrId> AdditionalUserIDs;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|MatchmakingEnqueuedUser|Field")
    TMap<FString, FString> CustomData;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|MatchmakingEnqueuedUser|Field")
    FOvrUser User;

    // Default ctor.
    FOvrMatchmakingEnqueuedUser();

    // Copying values from an OVR handle.
    FOvrMatchmakingEnqueuedUser(ovrMatchmakingEnqueuedUserHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrMatchmakingEnqueuedUserHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|SendInvitesResult")
struct OVRPLATFORM_API FOvrSendInvitesResult
{
    GENERATED_USTRUCT_BODY()

    /** The list of invites that was sent */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|SendInvitesResult|Field")
    FOvrApplicationInvitePages Invites;

    // Default ctor.
    FOvrSendInvitesResult();

    // Copying values from an OVR handle.
    FOvrSendInvitesResult(ovrSendInvitesResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrSendInvitesResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};

USTRUCT(BlueprintType, Category = "OvrPlatform|Models|UserArray")
struct OVRPLATFORM_API FOvrUserPages
{
    GENERATED_USTRUCT_BODY()

    // Default ctor.
    FOvrUserPages();

    // Copying values from an OVR handle to the array, and the originating message
    // to prevent the handle from being freed.
    FOvrUserPages(ovrUserArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating values from an OVR handle to the array, and the originating message
    // to prevent the handle from being freed.
    void Update(ovrUserArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // OVR array handle for methods
    mutable ovrUserArrayHandle PagedArrayHandle;

    // Original ref-counted message to hold onto array handle
    mutable TOvrMessageHandlePtr PagedArrayMessageHandlePtr;
};

UCLASS()
class OVRPLATFORM_API UOvrUserPagesMethods : public UObject
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|UserPages")
    static FOvrUser UserPages_GetElement(const FOvrUserPages& Model, int64 Index);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|UserPages")
    static FString UserPages_GetNextUrl(const FOvrUserPages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|UserPages")
    static int64 UserPages_GetSize(const FOvrUserPages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|UserPages")
    static bool UserPages_HasNextPage(const FOvrUserPages& Model);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|Challenge")
struct OVRPLATFORM_API FOvrChallenge
{
    GENERATED_USTRUCT_BODY()

    /**  Was this challenge created by a user or the app developer */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Challenge|Field")
    EOvrChallengeCreationType CreationType;

    /**  A displayable string of the challenge's description */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Challenge|Field")
    FString Description;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Challenge|Field")
    FDateTime EndDate;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Challenge|Field")
    FOvrId ID;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Challenge|Field")
    FOvrUserPages InvitedUsers;

    /**  The leaderboard associated with this challenge */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Challenge|Field")
    FOvrLeaderboard Leaderboard;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Challenge|Field")
    FOvrUserPages Participants;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Challenge|Field")
    FDateTime StartDate;

    /**  A displayable string of the challenge's title */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Challenge|Field")
    FString Title;

    /**  A enum that specify who can see this challenge */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Challenge|Field")
    EOvrChallengeVisibility Visibility;

    // Default ctor.
    FOvrChallenge();

    // Copying values from an OVR handle.
    FOvrChallenge(ovrChallengeHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrChallengeHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};

USTRUCT(BlueprintType, Category = "OvrPlatform|Models|ChallengeArray")
struct OVRPLATFORM_API FOvrChallengePages
{
    GENERATED_USTRUCT_BODY()

    // Default ctor.
    FOvrChallengePages();

    // Copying values from an OVR handle to the array, and the originating message
    // to prevent the handle from being freed.
    FOvrChallengePages(ovrChallengeArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating values from an OVR handle to the array, and the originating message
    // to prevent the handle from being freed.
    void Update(ovrChallengeArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // OVR array handle for methods
    mutable ovrChallengeArrayHandle PagedArrayHandle;

    // Original ref-counted message to hold onto array handle
    mutable TOvrMessageHandlePtr PagedArrayMessageHandlePtr;
};

UCLASS()
class OVRPLATFORM_API UOvrChallengePagesMethods : public UObject
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ChallengePages")
    static FOvrChallenge ChallengePages_GetElement(const FOvrChallengePages& Model, int64 Index);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ChallengePages")
    static FString ChallengePages_GetNextUrl(const FOvrChallengePages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ChallengePages")
    static FString ChallengePages_GetPreviousUrl(const FOvrChallengePages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ChallengePages")
    static int64 ChallengePages_GetSize(const FOvrChallengePages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ChallengePages")
    static int64 ChallengePages_GetTotalCount(const FOvrChallengePages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ChallengePages")
    static bool ChallengePages_HasNextPage(const FOvrChallengePages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ChallengePages")
    static bool ChallengePages_HasPreviousPage(const FOvrChallengePages& Model);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|LaunchDetails")
struct OVRPLATFORM_API FOvrLaunchDetails
{
    GENERATED_USTRUCT_BODY()

    /**
     * An opaque string provided by the developer to help them deeplink
     * to content on app startup.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LaunchDetails|Field")
    FString DeeplinkMessage;

    /** If provided, the intended destination the user would like to go to */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LaunchDetails|Field")
    FString DestinationApiName;

    /**
     * A string typically used to distinguish where the deeplink came from.
     * For instance, a DEEPLINK launch type could be coming from events or rich presence.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LaunchDetails|Field")
    FString LaunchSource;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LaunchDetails|Field")
    EOvrLaunchType LaunchType;

    /** If provided, the intended lobby the user would like to be in */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LaunchDetails|Field")
    FString LobbySessionID;

    /** If provided, the intended session the user would like to be in */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LaunchDetails|Field")
    FString MatchSessionID;

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * If provided, the intended room the user would like to be in
     */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|LaunchDetails|Field")
    FOvrId RoomID;

    /** A unique identifer to keep track of a user going through the deeplinking flow */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LaunchDetails|Field")
    FString TrackingID;

    /** If provided, the intended users the user would like to be with */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LaunchDetails|Field")
    FOvrUserPages Users;

    // Default ctor.
    FOvrLaunchDetails();

    // Copying values from an OVR handle.
    FOvrLaunchDetails(ovrLaunchDetailsHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrLaunchDetailsHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|LaunchInvitePanelFlowResult")
struct OVRPLATFORM_API FOvrLaunchInvitePanelFlowResult
{
    GENERATED_USTRUCT_BODY()

    /** A list of users that were sent an invitation to the session. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LaunchInvitePanelFlowResult|Field")
    FOvrUserPages InvitedUsers;

    // Default ctor.
    FOvrLaunchInvitePanelFlowResult();

    // Copying values from an OVR handle.
    FOvrLaunchInvitePanelFlowResult(ovrLaunchInvitePanelFlowResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrLaunchInvitePanelFlowResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/** DEPRECATED. Will be removed from headers at version v49. */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|Team")
struct OVRPLATFORM_API FOvrTeam
{
    GENERATED_USTRUCT_BODY()

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|Team|Field")
    FOvrUserPages AssignedUsers;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|Team|Field")
    int32 MaxUsers;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|Team|Field")
    int32 MinUsers;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|Team|Field")
    FString Name;

    // Default ctor.
    FOvrTeam();

    // Copying values from an OVR handle.
    FOvrTeam(ovrTeamHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrTeamHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/** DEPRECATED. Will be removed from headers at version v49. */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|Room")
struct OVRPLATFORM_API FOvrRoom
{
    GENERATED_USTRUCT_BODY()

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|Room|Field")
    FOvrId ApplicationID;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|Room|Field")
    TMap<FString, FString> DataStore;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|Room|Field")
    FString Description;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|Room|Field")
    FOvrId ID;

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * A list of users that have been invited to the room, but have not joined the room yet.
     */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|Room|Field")
    FOvrUserPages InvitedUsers;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|Room|Field")
    bool IsMembershipLocked;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|Room|Field")
    EOvrRoomJoinPolicy JoinPolicy;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|Room|Field")
    EOvrRoomJoinability Joinability;

    /**
     * DEPRECATED. Will be removed from headers at version v49.
     * If this is a matchmaking room, it contains all users matched into
     * the room, including the host as well as users enqueued by someone else.
     * Also includes additional per-user matchmaking metadata.
     */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|Room|Field")
    TArray<FOvrMatchmakingEnqueuedUser> MatchedUsers;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|Room|Field")
    int32 MaxUsers;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|Room|Field")
    FString Name;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|Room|Field")
    FOvrUser Owner;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|Room|Field")
    TArray<FOvrTeam> Teams;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|Room|Field")
    EOvrRoomType Type;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|Room|Field")
    FOvrUserPages Users;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|Room|Field")
    int32 Version;

    // Default ctor.
    FOvrRoom();

    // Copying values from an OVR handle.
    FOvrRoom(ovrRoomHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrRoomHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/** DEPRECATED. Will be removed from headers at version v49. */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|MatchmakingEnqueueResultAndRoom")
struct OVRPLATFORM_API FOvrMatchmakingEnqueueResultAndRoom
{
    GENERATED_USTRUCT_BODY()

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|MatchmakingEnqueueResultAndRoom|Field")
    FOvrMatchmakingEnqueueResult MatchmakingEnqueueResult;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|MatchmakingEnqueueResultAndRoom|Field")
    FOvrRoom Room;

    // Default ctor.
    FOvrMatchmakingEnqueueResultAndRoom();

    // Copying values from an OVR handle.
    FOvrMatchmakingEnqueueResultAndRoom(ovrMatchmakingEnqueueResultAndRoomHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrMatchmakingEnqueueResultAndRoomHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/** DEPRECATED. Will be removed from headers at version v49. */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|MatchmakingRoom")
struct OVRPLATFORM_API FOvrMatchmakingRoom
{
    GENERATED_USTRUCT_BODY()

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|MatchmakingRoom|Field")
    bool HasPingTime;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|MatchmakingRoom|Field")
    int32 PingTime;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|MatchmakingRoom|Field")
    FOvrRoom Room;

    // Default ctor.
    FOvrMatchmakingRoom();

    // Copying values from an OVR handle.
    FOvrMatchmakingRoom(ovrMatchmakingRoomHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrMatchmakingRoomHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/** DEPRECATED. Will be removed from headers at version v49. */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|MatchmakingBrowseResult")
struct OVRPLATFORM_API FOvrMatchmakingBrowseResult
{
    GENERATED_USTRUCT_BODY()

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|MatchmakingBrowseResult|Field")
    FOvrMatchmakingEnqueueResult EnqueueResult;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|MatchmakingBrowseResult|Field")
    TArray<FOvrMatchmakingRoom> Rooms;

    // Default ctor.
    FOvrMatchmakingBrowseResult();

    // Copying values from an OVR handle.
    FOvrMatchmakingBrowseResult(ovrMatchmakingBrowseResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrMatchmakingBrowseResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|Party")
struct OVRPLATFORM_API FOvrParty
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Party|Field")
    FOvrId ID;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Party|Field")
    FOvrUserPages InvitedUsers;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Party|Field")
    FOvrUser Leader;

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|Party|Field")
    FOvrRoom Room;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Party|Field")
    FOvrUserPages Users;

    // Default ctor.
    FOvrParty();

    // Copying values from an OVR handle.
    FOvrParty(ovrPartyHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrPartyHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};

USTRUCT(BlueprintType, Category = "OvrPlatform|Models|RoomArray")
struct OVRPLATFORM_API FOvrRoomPages
{
    GENERATED_USTRUCT_BODY()

    // Default ctor.
    FOvrRoomPages();

    // Copying values from an OVR handle to the array, and the originating message
    // to prevent the handle from being freed.
    FOvrRoomPages(ovrRoomArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating values from an OVR handle to the array, and the originating message
    // to prevent the handle from being freed.
    void Update(ovrRoomArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // OVR array handle for methods
    mutable ovrRoomArrayHandle PagedArrayHandle;

    // Original ref-counted message to hold onto array handle
    mutable TOvrMessageHandlePtr PagedArrayMessageHandlePtr;
};

UCLASS()
class OVRPLATFORM_API UOvrRoomPagesMethods : public UObject
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|RoomPages")
    static FOvrRoom RoomPages_GetElement(const FOvrRoomPages& Model, int64 Index);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|RoomPages")
    static FString RoomPages_GetNextUrl(const FOvrRoomPages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|RoomPages")
    static int64 RoomPages_GetSize(const FOvrRoomPages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|RoomPages")
    static bool RoomPages_HasNextPage(const FOvrRoomPages& Model);
};


/** DEPRECATED. Will be removed from headers at version v49. */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|UserAndRoom")
struct OVRPLATFORM_API FOvrUserAndRoom
{
    GENERATED_USTRUCT_BODY()

    /** DEPRECATED. Will be removed from headers at version v49. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty), Category = "OvrPlatform|Models|UserAndRoom|Field")
    FOvrRoom Room;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|UserAndRoom|Field")
    FOvrUser User;

    // Default ctor.
    FOvrUserAndRoom();

    // Copying values from an OVR handle.
    FOvrUserAndRoom(ovrUserAndRoomHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrUserAndRoomHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};

USTRUCT(BlueprintType, Category = "OvrPlatform|Models|UserAndRoomArray")
struct OVRPLATFORM_API FOvrUserAndRoomPages
{
    GENERATED_USTRUCT_BODY()

    // Default ctor.
    FOvrUserAndRoomPages();

    // Copying values from an OVR handle to the array, and the originating message
    // to prevent the handle from being freed.
    FOvrUserAndRoomPages(ovrUserAndRoomArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating values from an OVR handle to the array, and the originating message
    // to prevent the handle from being freed.
    void Update(ovrUserAndRoomArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // OVR array handle for methods
    mutable ovrUserAndRoomArrayHandle PagedArrayHandle;

    // Original ref-counted message to hold onto array handle
    mutable TOvrMessageHandlePtr PagedArrayMessageHandlePtr;
};

UCLASS()
class OVRPLATFORM_API UOvrUserAndRoomPagesMethods : public UObject
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|UserAndRoomPages")
    static FOvrUserAndRoom UserAndRoomPages_GetElement(const FOvrUserAndRoomPages& Model, int64 Index);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|UserAndRoomPages")
    static FString UserAndRoomPages_GetNextUrl(const FOvrUserAndRoomPages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|UserAndRoomPages")
    static int64 UserAndRoomPages_GetSize(const FOvrUserAndRoomPages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|UserAndRoomPages")
    static bool UserAndRoomPages_HasNextPage(const FOvrUserAndRoomPages& Model);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|UserCapability")
struct OVRPLATFORM_API FOvrUserCapability
{
    GENERATED_USTRUCT_BODY()

    /** Human readable description of the capability describing what possessing it entails for a given user */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|UserCapability|Field")
    FString Description;

    /** Whether the capability is currently enabled for the user */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|UserCapability|Field")
    bool IsEnabled;

    /** Unique identifer for the capability */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|UserCapability|Field")
    FString Name;

    /** If present, specifies the reason the capability was enabled or disabled */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|UserCapability|Field")
    FString ReasonCode;

    // Default ctor.
    FOvrUserCapability();

    // Copying values from an OVR handle.
    FOvrUserCapability(ovrUserCapabilityHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrUserCapabilityHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};

USTRUCT(BlueprintType, Category = "OvrPlatform|Models|UserCapabilityArray")
struct OVRPLATFORM_API FOvrUserCapabilityPages
{
    GENERATED_USTRUCT_BODY()

    // Default ctor.
    FOvrUserCapabilityPages();

    // Copying values from an OVR handle to the array, and the originating message
    // to prevent the handle from being freed.
    FOvrUserCapabilityPages(ovrUserCapabilityArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating values from an OVR handle to the array, and the originating message
    // to prevent the handle from being freed.
    void Update(ovrUserCapabilityArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // OVR array handle for methods
    mutable ovrUserCapabilityArrayHandle PagedArrayHandle;

    // Original ref-counted message to hold onto array handle
    mutable TOvrMessageHandlePtr PagedArrayMessageHandlePtr;
};

UCLASS()
class OVRPLATFORM_API UOvrUserCapabilityPagesMethods : public UObject
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|UserCapabilityPages")
    static FOvrUserCapability UserCapabilityPages_GetElement(const FOvrUserCapabilityPages& Model, int64 Index);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|UserCapabilityPages")
    static FString UserCapabilityPages_GetNextUrl(const FOvrUserCapabilityPages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|UserCapabilityPages")
    static int64 UserCapabilityPages_GetSize(const FOvrUserCapabilityPages& Model);

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|UserCapabilityPages")
    static bool UserCapabilityPages_HasNextPage(const FOvrUserCapabilityPages& Model);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|UserDataStoreUpdateResponse")
struct OVRPLATFORM_API FOvrUserDataStoreUpdateResponse
{
    GENERATED_USTRUCT_BODY()

    /** Whether the update request is succeeded. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|UserDataStoreUpdateResponse|Field")
    bool Success;

    // Default ctor.
    FOvrUserDataStoreUpdateResponse();

    // Copying values from an OVR handle.
    FOvrUserDataStoreUpdateResponse(ovrUserDataStoreUpdateResponseHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrUserDataStoreUpdateResponseHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|UserProof")
struct OVRPLATFORM_API FOvrUserProof
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|UserProof|Field")
    FString Nonce;

    // Default ctor.
    FOvrUserProof();

    // Copying values from an OVR handle.
    FOvrUserProof(ovrUserProofHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrUserProofHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * DEPRECATED. Do not add new requests using this.
 * Use launch_report_flow_result instead.
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|UserReportID")
struct OVRPLATFORM_API FOvrUserReportID
{
    GENERATED_USTRUCT_BODY()

    /** Whether the viewer chose to cancel the report flow. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|UserReportID|Field")
    bool DidCancel;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|UserReportID|Field")
    FOvrId ID;

    // Default ctor.
    FOvrUserReportID();

    // Copying values from an OVR handle.
    FOvrUserReportID(ovrUserReportIDHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrUserReportIDHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|VoipDecoder")
struct OVRPLATFORM_API FOvrVoipDecoder
{
    GENERATED_USTRUCT_BODY()

    // Default ctor.
    FOvrVoipDecoder();

    // Copying values from an OVR handle.
    FOvrVoipDecoder(ovrVoipDecoderHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrVoipDecoderHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // OVR Handle for methods
    ovrVoipDecoderHandle Handle;
};

UCLASS()
class OVRPLATFORM_API UOvrVoipDecoderMethods : public UObject
{
    GENERATED_BODY()

public:

    /*
     * Not exposed to blueprints, call C API directly: void ovr_VoipDecoder_Decode(const ovrVoipDecoderHandle obj, const unsigned char *compressedData, size_t compressedSize);
     */

    /*
     * Not exposed to blueprints, call C API directly: size_t ovr_VoipDecoder_GetDecodedPCM(const ovrVoipDecoderHandle obj, float *outputBuffer, size_t outputBufferSize);
     */
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|VoipEncoder")
struct OVRPLATFORM_API FOvrVoipEncoder
{
    GENERATED_USTRUCT_BODY()

    // Default ctor.
    FOvrVoipEncoder();

    // Copying values from an OVR handle.
    FOvrVoipEncoder(ovrVoipEncoderHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // Setting all values to their defaults.
    void Clear();

    // Updating with values from an OVR handle.
    void Update(ovrVoipEncoderHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    // OVR Handle for methods
    ovrVoipEncoderHandle Handle;
};

UCLASS()
class OVRPLATFORM_API UOvrVoipEncoderMethods : public UObject
{
    GENERATED_BODY()

public:

    /*
     * Not exposed to blueprints, call C API directly: void ovr_VoipEncoder_AddPCM(const ovrVoipEncoderHandle obj, const float *inputData, unsigned int inputSize);
     */

    /*
     * Not exposed to blueprints, call C API directly: size_t ovr_VoipEncoder_GetCompressedData(const ovrVoipEncoderHandle obj, unsigned char *outputBuffer, size_t intputSize);
     */

    /*
     * Not exposed to blueprints, call C API directly: size_t ovr_VoipEncoder_GetCompressedDataSize(const ovrVoipEncoderHandle obj);
     */
};

