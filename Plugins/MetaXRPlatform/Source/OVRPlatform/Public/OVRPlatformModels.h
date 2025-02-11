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


/**
 * A video recording evidence that can be used to collect video evidence when reporting abusive behavior or content within a platform.
 * More details are available in our [User Reporting Service Virtual Reality Check guideline](https://developer.oculus.com/resources/reporting-service/)
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|AbuseReportRecording")
struct OVRPLATFORM_API FOvrAbuseReportRecording
{
    GENERATED_USTRUCT_BODY()

    /**
     * A unique UUID associated with the Abuse Report recording.
     * It can be retrieved using field FOvrLaunchReportFlowResult::UserReportId
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AbuseReportRecording|Field")
    FString RecordingUuid;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrAbuseReportRecordingHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrAbuseReportRecording();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrAbuseReportRecording(ovrAbuseReportRecordingHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrAbuseReportRecordingHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * An AchievementDefinition defines an achievement; this includes its name and how it is unlocked.
 * For an individual user's progress in unlocking an achievement, see AchievementProgress.
 * It can be retrieved using Achievements_GetAllDefinitions().
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|AchievementDefinition")
struct OVRPLATFORM_API FOvrAchievementDefinition
{
    GENERATED_USTRUCT_BODY()

    /**
     * This is the type of achievement. There are three types of
     * achievement: EOvrAchievementType::Simple - unlocked by completion of a single event or objective, EOvrAchievementType::Bitfield - unlocked when a number of bits in a bitfield are set, and EOvrAchievementType::Count - unlocked when a counter reaches a defined target.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AchievementDefinition|Field")
    EOvrAchievementType AchievementType;

    /** A string of the api name of the achievement. It can be used to get the achievement progress by name by the function Achievements_GetProgressByName(). */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AchievementDefinition|Field")
    FString ApiName;

    /** It is required for bitfield achievements(EOvrAchievementType::Bitfield). This represents the size of the bitfield for this achievement. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AchievementDefinition|Field")
    int32 BitfieldLength;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AchievementDefinition|Field")
    int64 Target;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrAchievementDefinitionHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrAchievementDefinition();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrAchievementDefinition(ovrAchievementDefinitionHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrAchievementDefinitionHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};

/** Represents a paginated list of FOvrAchievementDefinition elements */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|AchievementDefinitionArray")
struct OVRPLATFORM_API FOvrAchievementDefinitionPages
{
    GENERATED_USTRUCT_BODY()

    /// \brief This is the default constructor for the struct, which initializes the ::ovrAchievementDefinitionArrayHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrAchievementDefinitionPages();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrAchievementDefinitionPages(ovrAchievementDefinitionArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrAchievementDefinitionArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // OVR array handle for methods
    mutable ovrAchievementDefinitionArrayHandle PagedArrayHandle;

    // Original ref-counted message to hold onto array handle
    mutable TOvrMessageHandlePtr PagedArrayMessageHandlePtr;
};

UCLASS()
/// \brief This class provides methods for accessing and manipulating the elements in a FOvrAchievementDefinitionPages paginated list. It allows you to easily retrieve and modify the elements in the list, as well as check if there is a next page of elements available.
class OVRPLATFORM_API UOvrAchievementDefinitionPagesMethods : public UObject
{
    GENERATED_BODY()

public:

    /** Access the indexed element in this list. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|AchievementDefinitionPages")
    static FOvrAchievementDefinition AchievementDefinitionPages_GetElement(const FOvrAchievementDefinitionPages& Model, int64 Index);

    /** The URL to request the next paginated list of elements. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|AchievementDefinitionPages")
    static FString AchievementDefinitionPages_GetNextUrl(const FOvrAchievementDefinitionPages& Model);

    /** The number of elements contained within this list. This is not equal to the total number of elements across multiple pages. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|AchievementDefinitionPages")
    static int64 AchievementDefinitionPages_GetSize(const FOvrAchievementDefinitionPages& Model);

    /** Whether there is a next page of elements that can be retrieved. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|AchievementDefinitionPages")
    static bool AchievementDefinitionPages_HasNextPage(const FOvrAchievementDefinitionPages& Model);
};


/**
 * The unlock progress of a particular achievement can be retrieved using Achievements_GetAllProgress().
 * It can be used to display the progress of each achievement in your game.
 * See the following [link](https://developer.oculus.com/documentation/unreal/ps-achievements/) for more information.
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|AchievementProgress")
struct OVRPLATFORM_API FOvrAchievementProgress
{
    GENERATED_USTRUCT_BODY()

    /**
     * If the type of the achievement is EOvrAchievementType::Bitfield
     * it represents the current bitfield state that the achievement has reached.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AchievementProgress|Field")
    FString Bitfield;

    /**
     * If the type of the achievement is EOvrAchievementType::Count,
     * it represents the current counter state that the achievement has reached.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AchievementProgress|Field")
    int64 Count;

    /** If the user has already unlocked this achievement. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AchievementProgress|Field")
    bool IsUnlocked;

    /**
     * The unique string that you use to reference the achievement
     * in your app, as specified in the developer dashboard.
     * It can be retrieved using field FOvrAchievementDefinition::ApiName.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AchievementProgress|Field")
    FString Name;

    /** If the achievement is unlocked, the time when it was unlocked. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AchievementProgress|Field")
    FDateTime UnlockTime;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrAchievementProgressHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrAchievementProgress();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrAchievementProgress(ovrAchievementProgressHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrAchievementProgressHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};

/** Represents a paginated list of FOvrAchievementProgress elements */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|AchievementProgressArray")
struct OVRPLATFORM_API FOvrAchievementProgressPages
{
    GENERATED_USTRUCT_BODY()

    /// \brief This is the default constructor for the struct, which initializes the ::ovrAchievementProgressArrayHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrAchievementProgressPages();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrAchievementProgressPages(ovrAchievementProgressArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrAchievementProgressArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // OVR array handle for methods
    mutable ovrAchievementProgressArrayHandle PagedArrayHandle;

    // Original ref-counted message to hold onto array handle
    mutable TOvrMessageHandlePtr PagedArrayMessageHandlePtr;
};

UCLASS()
/// \brief This class provides methods for accessing and manipulating the elements in a FOvrAchievementProgressPages paginated list. It allows you to easily retrieve and modify the elements in the list, as well as check if there is a next page of elements available.
class OVRPLATFORM_API UOvrAchievementProgressPagesMethods : public UObject
{
    GENERATED_BODY()

public:

    /** Access the indexed element in this list. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|AchievementProgressPages")
    static FOvrAchievementProgress AchievementProgressPages_GetElement(const FOvrAchievementProgressPages& Model, int64 Index);

    /** The URL to request the next paginated list of elements. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|AchievementProgressPages")
    static FString AchievementProgressPages_GetNextUrl(const FOvrAchievementProgressPages& Model);

    /** The number of elements contained within this list. This is not equal to the total number of elements across multiple pages. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|AchievementProgressPages")
    static int64 AchievementProgressPages_GetSize(const FOvrAchievementProgressPages& Model);

    /** Whether there is a next page of elements that can be retrieved. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|AchievementProgressPages")
    static bool AchievementProgressPages_HasNextPage(const FOvrAchievementProgressPages& Model);
};


/**
 * Represents an update to an existing achievement. It will be the payload if there is any updates on achievements,
 * as unlocking an achievement by Achievements_Unlock(), adding 'count' to the achievement by Achievements_AddCount(),
 * and unlocking fields of a BITFIELD achievement by Achievements_AddFields().
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|AchievementUpdate")
struct OVRPLATFORM_API FOvrAchievementUpdate
{
    GENERATED_USTRUCT_BODY()

    /** This indicates if this update caused the achievement to unlock. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AchievementUpdate|Field")
    bool JustUnlocked;

    /** The unique field FOvrAchievementDefinition::ApiName used to reference the updated achievement, as specified in the developer dashboard. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AchievementUpdate|Field")
    FString Name;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrAchievementUpdateHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrAchievementUpdate();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrAchievementUpdate(ovrAchievementUpdateHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrAchievementUpdateHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * Represents the result of the download of an application. You can retrieve it using
 * CheckAppDownloadProgress API (Application_CheckAppDownloadProgress()).
 * You can use this to check the progress and the status of an ongoing app download operation.
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|AppDownloadProgressResult")
struct OVRPLATFORM_API FOvrAppDownloadProgressResult
{
    GENERATED_USTRUCT_BODY()

    /** Total number of bytes that need to be downloaded */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AppDownloadProgressResult|Field")
    int64 DownloadBytes;

    /** Number of bytes that have already been downloaded. You can use this and field FOvrAppDownloadProgressResult::DownloadBytes to implement the progress bar. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AppDownloadProgressResult|Field")
    int64 DownloadedBytes;

    /** Status code of the current app status. You can use it to find out whether the app is being downloaded or queued for downloading */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AppDownloadProgressResult|Field")
    EOvrAppStatus StatusCode;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrAppDownloadProgressResultHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrAppDownloadProgressResult();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrAppDownloadProgressResult(ovrAppDownloadProgressResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrAppDownloadProgressResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * Represents the result of an app download. You will use it when you start an app download,
 * cancel an app download or install an app update which was previous downloaded.
 * In those scenarios, the app download result will be the payload of
 * Application_StartAppDownload(), Application_CancelAppDownload()
 * or Application_InstallAppUpdateAndRelaunch() API calls.
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|AppDownloadResult")
struct OVRPLATFORM_API FOvrAppDownloadResult
{
    GENERATED_USTRUCT_BODY()

    /**
     * Result of the install operation returned by the installer. You can find more information
     *  about possible members from EOvrAppInstallResult. In case of an error during
     *  install process, the error message contains the string representation of this result.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AppDownloadResult|Field")
    EOvrAppInstallResult AppInstallResult;

    /** Timestamp in milliseconds when the operation finished. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AppDownloadResult|Field")
    int64 Timestamp;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrAppDownloadResultHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrAppDownloadResult();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrAppDownloadResult(ovrAppDownloadResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrAppDownloadResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * Represents the version information for an application. The information includes the date of
 * latest release, the size of the latest release and the application name
 * and version code of currently installed version and the latest release. You can retrieve it
 * with Application_GetVersion().
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|ApplicationVersion")
struct OVRPLATFORM_API FOvrApplicationVersion
{
    GENERATED_USTRUCT_BODY()

    /** The version code number for the version of the application that is currently installed on the device. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ApplicationVersion|Field")
    int32 CurrentCode;

    /** The version name string for the version of the application that is currently installed on the device. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ApplicationVersion|Field")
    FString CurrentName;

    /**
     * Version code number of the latest update of the application. This may
     * or may not be currently installed on the device.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ApplicationVersion|Field")
    int32 LatestCode;

    /**
     * Version name string of the latest update of the application. This may
     * or may not be currently installed on the device.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ApplicationVersion|Field")
    FString LatestName;

    /** Seconds since epoch when the latest application update was released. You need to convert this date to a human readable format before displaying it to the application users. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ApplicationVersion|Field")
    int64 ReleaseDate;

    /** Size of the latest application update in bytes. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ApplicationVersion|Field")
    FString Size;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrApplicationVersionHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrApplicationVersion();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrApplicationVersion(ovrApplicationVersionHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrApplicationVersionHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * An AssetFileDeleteResult contains the result of a deleted asset file. You can delete an asset file by
 * using AssetFile_DeleteById() or AssetFile_DeleteByName().
 * The delete result contains the field FOvrAssetFileDeleteResult::AssetId, the file path,
 * and the success status of the deleted asset. 
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|AssetFileDeleteResult")
struct OVRPLATFORM_API FOvrAssetFileDeleteResult
{
    GENERATED_USTRUCT_BODY()

    /** \deprecated You can use field FOvrAssetFileDeleteResult::AssetId to retrieve the ID of the asset file. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty, DeprecationMessage="You can use field FOvrAssetFileDeleteResult::AssetId to retrieve the ID of the asset file."), Category = "OvrPlatform|Models|AssetFileDeleteResult|Field")
    FOvrId AssetFileId;

    /**
     * This represents the ID of the asset file. When you want to
     * use field FOvrAssetFileDeleteResult::AssetFileId, you need to use
     * field FOvrAssetFileDeleteResult::AssetId instead.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AssetFileDeleteResult|Field")
    FOvrId AssetId;

    /** File path of the asset file. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AssetFileDeleteResult|Field")
    FString Filepath;

    /** You can use this to determine whether deleting an asset file was successful or not. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AssetFileDeleteResult|Field")
    bool Success;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrAssetFileDeleteResultHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrAssetFileDeleteResult();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrAssetFileDeleteResult(ovrAssetFileDeleteResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrAssetFileDeleteResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/** An AssetFileDownloadCancelResult represents the result of a canceled download action of an asset file. You can cancel a download of an asset file by using AssetFile_DownloadCancelById() or AssetFile_DownloadCancelById(). The result contains three fields which are the asset file ID(use field FOvrAssetFileDownloadCancelResult::AssetId to access), the file path, and success status of the canceled download. */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|AssetFileDownloadCancelResult")
struct OVRPLATFORM_API FOvrAssetFileDownloadCancelResult
{
    GENERATED_USTRUCT_BODY()

    /** \deprecated You can use field FOvrAssetFileDownloadCancelResult::AssetId to retrieve the ID of the asset file instead. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty, DeprecationMessage="You can use field FOvrAssetFileDownloadCancelResult::AssetId to retrieve the ID of the asset file instead."), Category = "OvrPlatform|Models|AssetFileDownloadCancelResult|Field")
    FOvrId AssetFileId;

    /** ID of the asset file. NOTE: this does not represent the ID of the asset. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AssetFileDownloadCancelResult|Field")
    FOvrId AssetId;

    /** File path of the asset file. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AssetFileDownloadCancelResult|Field")
    FString Filepath;

    /** You can use this to determine whether the cancel request of downloading an asset file has succeeded. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AssetFileDownloadCancelResult|Field")
    bool Success;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrAssetFileDownloadCancelResultHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrAssetFileDownloadCancelResult();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrAssetFileDownloadCancelResult(ovrAssetFileDownloadCancelResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrAssetFileDownloadCancelResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * An AssetFileDownloadResult represents an asset that has been successfully downloaded.
 * It's used to store information about an asset that has been downloaded, such as its location on the local file system and its unique identifier asset file ID.
 * It can be retrieved using AssetFile_DownloadByName().
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|AssetFileDownloadResult")
struct OVRPLATFORM_API FOvrAssetFileDownloadResult
{
    GENERATED_USTRUCT_BODY()

    /**
     * ID of the asset file. It can be retrieved using field FOvrAssetDetails::AssetId.
     *  It can be used to retrieve the AssetFileDownloadResult by AssetFile_DownloadById().
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AssetFileDownloadResult|Field")
    FOvrId AssetId;

    /** File path of the asset file. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AssetFileDownloadResult|Field")
    FString Filepath;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrAssetFileDownloadResultHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrAssetFileDownloadResult();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrAssetFileDownloadResult(ovrAssetFileDownloadResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrAssetFileDownloadResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * An AssetFileDownloadUpdate represents the download status of an update for an asset file.
 * It contains the asset file ID, the download progress of the update, and its completion status.
 * It can be retrieved using FOvrNotification_AssetFile_DownloadUpdate. 
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|AssetFileDownloadUpdate")
struct OVRPLATFORM_API FOvrAssetFileDownloadUpdate
{
    GENERATED_USTRUCT_BODY()

    /** \deprecated Use field FOvrAssetFileDownloadUpdate::AssetId. */
    UPROPERTY(BlueprintReadOnly, meta = (DeprecatedProperty, DeprecationMessage="Use field FOvrAssetFileDownloadUpdate::AssetId."), Category = "OvrPlatform|Models|AssetFileDownloadUpdate|Field")
    FOvrId AssetFileId;

    /** ID of the asset file. It can be retrieved using field FOvrAssetDetails::AssetId. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AssetFileDownloadUpdate|Field")
    FOvrId AssetId;

    /** This field is of type uint and represents the total number of bytes in the asset file. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AssetFileDownloadUpdate|Field")
    int64 BytesTotal;

    /** An integer represents the number of bytes that have been downloaded. -1 If the download hasn't started yet. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AssetFileDownloadUpdate|Field")
    int64 BytesTransferred;

    /** This field is of type boolean and indicates whether the download has been completed or not. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AssetFileDownloadUpdate|Field")
    bool Completed;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrAssetFileDownloadUpdateHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrAssetFileDownloadUpdate();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrAssetFileDownloadUpdate(ovrAssetFileDownloadUpdateHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrAssetFileDownloadUpdateHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * This is the result that can be extracted from message payload when the avatar editor is launched.
 * It can be retrieved using Avatar_LaunchAvatarEditor().
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|AvatarEditorResult")
struct OVRPLATFORM_API FOvrAvatarEditorResult
{
    GENERATED_USTRUCT_BODY()

    /** Whether the request has sent. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AvatarEditorResult|Field")
    bool RequestSent;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrAvatarEditorResultHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrAvatarEditorResult();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrAvatarEditorResult(ovrAvatarEditorResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrAvatarEditorResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * It contains an array of users who have been blocked by the logged in user.
 * You can't follow, be followed, invited, or searched by a blocked user. It can be retrieved using User_GetBlockedUsers().
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|BlockedUser")
struct OVRPLATFORM_API FOvrBlockedUser
{
    GENERATED_USTRUCT_BODY()

    /**
     * It represents the user ID that has been blocked by the logged in user.
     * It is a type of ID and can be retrieved using field FOvrUser::ID.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|BlockedUser|Field")
    FOvrId Id;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrBlockedUserHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrBlockedUser();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrBlockedUser(ovrBlockedUserHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrBlockedUserHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};

/** Represents a paginated list of FOvrBlockedUser elements */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|BlockedUserArray")
struct OVRPLATFORM_API FOvrBlockedUserPages
{
    GENERATED_USTRUCT_BODY()

    /// \brief This is the default constructor for the struct, which initializes the ::ovrBlockedUserArrayHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrBlockedUserPages();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrBlockedUserPages(ovrBlockedUserArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrBlockedUserArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // OVR array handle for methods
    mutable ovrBlockedUserArrayHandle PagedArrayHandle;

    // Original ref-counted message to hold onto array handle
    mutable TOvrMessageHandlePtr PagedArrayMessageHandlePtr;
};

UCLASS()
/// \brief This class provides methods for accessing and manipulating the elements in a FOvrBlockedUserPages paginated list. It allows you to easily retrieve and modify the elements in the list, as well as check if there is a next page of elements available.
class OVRPLATFORM_API UOvrBlockedUserPagesMethods : public UObject
{
    GENERATED_BODY()

public:

    /** Access the indexed element in this list. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|BlockedUserPages")
    static FOvrBlockedUser BlockedUserPages_GetElement(const FOvrBlockedUserPages& Model, int64 Index);

    /** The URL to request the next paginated list of elements. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|BlockedUserPages")
    static FString BlockedUserPages_GetNextUrl(const FOvrBlockedUserPages& Model);

    /** The number of elements contained within this list. This is not equal to the total number of elements across multiple pages. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|BlockedUserPages")
    static int64 BlockedUserPages_GetSize(const FOvrBlockedUserPages& Model);

    /** Whether there is a next page of elements that can be retrieved. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|BlockedUserPages")
    static bool BlockedUserPages_HasNextPage(const FOvrBlockedUserPages& Model);
};


/**
 * Cowatch viewer represents a viewer in a cowatching session, including their user ID and any data that they have set.
 * The cowatch viewer data can be retrieved using Cowatching_GetViewersData().
 * It can be useful for tracking the participants in a cowatching session and managing their data.
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|CowatchViewer")
struct OVRPLATFORM_API FOvrCowatchViewer
{
    GENERATED_USTRUCT_BODY()

    /** Represents the viewer data set by this cowatching viewer. It's an optional `string` and can be set by Cowatching_SetViewerData(). */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|CowatchViewer|Field")
    FString Data;

    /** A unique user ID of the viewer. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|CowatchViewer|Field")
    FOvrId Id;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrCowatchViewerHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrCowatchViewer();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrCowatchViewer(ovrCowatchViewerHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrCowatchViewerHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};

/** Represents a paginated list of FOvrCowatchViewer elements */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|CowatchViewerArray")
struct OVRPLATFORM_API FOvrCowatchViewerPages
{
    GENERATED_USTRUCT_BODY()

    /// \brief This is the default constructor for the struct, which initializes the ::ovrCowatchViewerArrayHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrCowatchViewerPages();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrCowatchViewerPages(ovrCowatchViewerArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrCowatchViewerArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // OVR array handle for methods
    mutable ovrCowatchViewerArrayHandle PagedArrayHandle;

    // Original ref-counted message to hold onto array handle
    mutable TOvrMessageHandlePtr PagedArrayMessageHandlePtr;
};

UCLASS()
/// \brief This class provides methods for accessing and manipulating the elements in a FOvrCowatchViewerPages paginated list. It allows you to easily retrieve and modify the elements in the list, as well as check if there is a next page of elements available.
class OVRPLATFORM_API UOvrCowatchViewerPagesMethods : public UObject
{
    GENERATED_BODY()

public:

    /** Access the indexed element in this list. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|CowatchViewerPages")
    static FOvrCowatchViewer CowatchViewerPages_GetElement(const FOvrCowatchViewerPages& Model, int64 Index);

    /** The URL to request the next paginated list of elements. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|CowatchViewerPages")
    static FString CowatchViewerPages_GetNextUrl(const FOvrCowatchViewerPages& Model);

    /** The number of elements contained within this list. This is not equal to the total number of elements across multiple pages. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|CowatchViewerPages")
    static int64 CowatchViewerPages_GetSize(const FOvrCowatchViewerPages& Model);

    /** Whether there is a next page of elements that can be retrieved. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|CowatchViewerPages")
    static bool CowatchViewerPages_HasNextPage(const FOvrCowatchViewerPages& Model);
};


/**
 * CowatchWiewerUpdate is used to represent updates to viewer data within a cowatching session. It's essential for managing and synchronizing viewer data in real-time during cowatching sessions.
 * It can be retrieved using FOvrNotification_Cowatching_ViewersDataChanged when a user joins or updates their viewer data.
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|CowatchViewerUpdate")
struct OVRPLATFORM_API FOvrCowatchViewerUpdate
{
    GENERATED_USTRUCT_BODY()

    /** List of viewer data of all cowatch participants who is in a cowatching session. It can be retrieved using Cowatching_GetViewersData(). */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|CowatchViewerUpdate|Field")
    FOvrCowatchViewerPages DataList;

    /** A unique user ID of the user whose viewer data has been updated. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|CowatchViewerUpdate|Field")
    FOvrId Id;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrCowatchViewerUpdateHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrCowatchViewerUpdate();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrCowatchViewerUpdate(ovrCowatchViewerUpdateHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrCowatchViewerUpdateHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * It's designed to manage cowatching sessions within a shared virtual home environment. This state primarily focuses on tracking whether a user is currently participating in a cowatching session.
 * If there is any change in the cowatching state, it can be retrieved using FOvrNotification_Cowatching_InSessionChanged.
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|CowatchingState")
struct OVRPLATFORM_API FOvrCowatchingState
{
    GENERATED_USTRUCT_BODY()

    /** A `boolean` indicates if the current user is in a cowatching session. It can be retrieved using Cowatching_IsInSession(). */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|CowatchingState|Field")
    bool InSession;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrCowatchingStateHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrCowatchingState();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrCowatchingState(ovrCowatchingStateHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrCowatchingStateHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * The destination represents where the user would like to go to in the app.
 * It's usually associated with a travel or an invitation. Each destination has
 * field FOvrDestination::ApiName, field FOvrDestination::DisplayName,
 * field FOvrDestination::DeeplinkMessage and field FOvrDestination::ShareableUri link.
 * Please refer to member data documentation for details.
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|Destination")
struct OVRPLATFORM_API FOvrDestination
{
    GENERATED_USTRUCT_BODY()

    /**
     * You can pass it into FOvrGroupPresenceOptions::DestinationApiName when calling
     * GroupPresence_Set() to set this user's group presence.
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

    /** A displayable string of the destination name and it can be retrieved with field FOvrDestination::DisplayName. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Destination|Field")
    FString DisplayName;

    /** A URI that allows the user to deeplink directly to this destination */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Destination|Field")
    FString ShareableUri;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrDestinationHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrDestination();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrDestination(ovrDestinationHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrDestinationHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};

/** Represents a paginated list of FOvrDestination elements */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|DestinationArray")
struct OVRPLATFORM_API FOvrDestinationPages
{
    GENERATED_USTRUCT_BODY()

    /// \brief This is the default constructor for the struct, which initializes the ::ovrDestinationArrayHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrDestinationPages();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrDestinationPages(ovrDestinationArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrDestinationArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // OVR array handle for methods
    mutable ovrDestinationArrayHandle PagedArrayHandle;

    // Original ref-counted message to hold onto array handle
    mutable TOvrMessageHandlePtr PagedArrayMessageHandlePtr;
};

UCLASS()
/// \brief This class provides methods for accessing and manipulating the elements in a FOvrDestinationPages paginated list. It allows you to easily retrieve and modify the elements in the list, as well as check if there is a next page of elements available.
class OVRPLATFORM_API UOvrDestinationPagesMethods : public UObject
{
    GENERATED_BODY()

public:

    /** Access the indexed element in this list. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|DestinationPages")
    static FOvrDestination DestinationPages_GetElement(const FOvrDestinationPages& Model, int64 Index);

    /** The URL to request the next paginated list of elements. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|DestinationPages")
    static FString DestinationPages_GetNextUrl(const FOvrDestinationPages& Model);

    /** The number of elements contained within this list. This is not equal to the total number of elements across multiple pages. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|DestinationPages")
    static int64 DestinationPages_GetSize(const FOvrDestinationPages& Model);

    /** Whether there is a next page of elements that can be retrieved. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|DestinationPages")
    static bool DestinationPages_HasNextPage(const FOvrDestinationPages& Model);
};


/**
 * It represents an error response from the server.
 * It contains error information such as the error code, http status code, technical message, and displayable message.
 * It's used whenever the server needs to communicate an error or failure to the client.
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|Error")
struct OVRPLATFORM_API FOvrError
{
    GENERATED_USTRUCT_BODY()

    /**
     * It's a type of `integer` that represents the error code:
     * 
     * UNKNOWN_ERROR:1
     * 
     * AUTHENTICATION_ERROR:2
     * 
     * NETWORK_ERROR:3
     * 
     * STORE_INSTALLATION_ERROR:4
     * 
     * CALLER_NOT_SIGNED:5
     * 
     * UNKNOWN_SERVER_ERROR:6
     * 
     * PERMISSIONS_FAILURE:7
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Error|Field")
    int32 Code;

    /**
     * Human readable description of the error that can be displayed to the user.
     * Might be the empty string if there is no user-appropriate description available.
     * Not intended to be parsed as it might change at any time or be translated.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Error|Field")
    FString DisplayableMessage;

    /** It contains the HTTP status code for the error. More information about the http code can be found [here](https://en.wikipedia.org/wiki/List_of_HTTP_status_codes). */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Error|Field")
    int32 HttpCode;

    /**
     * Technical description of what went wrong intended for developers. For use in
     * logs or developer consoles.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Error|Field")
    FString Message;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrErrorHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrError();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrError(ovrErrorHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrErrorHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * An GroupPresenceJoinIntent represents a user's intent to join a group presence which
 * is user's presence to be at a FOvrDestination and session. People with same session id are
 * considered to be co-present together. Every combination of destination api name, lobby
 *  session id and match session id can uniquely identify a destination.
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|GroupPresenceJoinIntent")
struct OVRPLATFORM_API FOvrGroupPresenceJoinIntent
{
    GENERATED_USTRUCT_BODY()

    /** An opaque string provided by the developer to help bringing users together. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|GroupPresenceJoinIntent|Field")
    FString DeeplinkMessage;

    /** field FOvrDestination::ApiName is the unique API Name that refers to an in-app destination. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|GroupPresenceJoinIntent|Field")
    FString DestinationApiName;

    /**
     * This is a session ID that represents a closer group/squad/party of users. It is expected that all users with the same lobby session id can see or
     * hear each other. Users with the same lobby session id in their group presence will show up in the roster and will show up as "Recently Played With"
     * for future invites if they aren't already Oculus friends.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|GroupPresenceJoinIntent|Field")
    FString LobbySessionId;

    /**
     * This is a session that represents all the users that are playing a specific instance of a map, game mode, round, etc. This
     * can include users from multiple different lobbies that joined together and the users may or may not remain together after the match is over.
     * Users with the same match session id in their group presence will not show up in the Roster, but will show up as "Recently Played with" for future invites.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|GroupPresenceJoinIntent|Field")
    FString MatchSessionId;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrGroupPresenceJoinIntentHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrGroupPresenceJoinIntent();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrGroupPresenceJoinIntent(ovrGroupPresenceJoinIntentHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrGroupPresenceJoinIntentHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * An GroupPresenceLeaveIntent represents a user's intent to leave a group presence which
 * is user's presence to be at a FOvrDestination and session. People with same session id are
 * considered to be co-present together. Every combination of destination api name, lobby
 *  session id and match session id can uniquely identify a destination.
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|GroupPresenceLeaveIntent")
struct OVRPLATFORM_API FOvrGroupPresenceLeaveIntent
{
    GENERATED_USTRUCT_BODY()

    /** field FOvrDestination::ApiName is the unique API Name that refers to an in-app destination. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|GroupPresenceLeaveIntent|Field")
    FString DestinationApiName;

    /**
     * This is the match session that the current user wants to leave. A lobby session is a session ID
     * that represents a closer group/squad/party of users. It is expected that all users with the same
     * lobby session id can see or hear each other. Users with the same lobby session id in their group
     * presence will show up in the roster and will show up as "Recently Played With"
     * for future invites if they aren't already Oculus friends.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|GroupPresenceLeaveIntent|Field")
    FString LobbySessionId;

    /**
     * This is the match session that the current user wants to leave. A match session represents all
     * the users that are playing a specific instance of a map, game mode, round, etc. This can include users
     * from multiple different lobbies that joined together and the users may or may not remain together after
     * the match is over.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|GroupPresenceLeaveIntent|Field")
    FString MatchSessionId;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrGroupPresenceLeaveIntentHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrGroupPresenceLeaveIntent();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrGroupPresenceLeaveIntent(ovrGroupPresenceLeaveIntentHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrGroupPresenceLeaveIntentHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * Represents an update to an HTTP transfer, which is a process of transferring data over the internet using the HTTP protocol.
 * It provides a way for developers to monitor the progress of an HTTP transfer and can be retrieved using FOvrNotification_HTTP_Transfer.
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|HttpTransferUpdate")
struct OVRPLATFORM_API FOvrHttpTransferUpdate
{
    GENERATED_USTRUCT_BODY()

    /** An array of bytes that represents the data being transferred. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|HttpTransferUpdate|Field")
    TArray<uint8> Bytes;

    /**
     * It's a unique identifier for the HTTP transfer.
     * It is used to track the progress of the transfer and can be retrieved using field FOvrMessage::RequestID.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|HttpTransferUpdate|Field")
    FOvrId ID;

    /** This field is a `boolean` value that indicates whether the HTTP transfer has been completed or not. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|HttpTransferUpdate|Field")
    bool IsCompleted;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrHttpTransferUpdateHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrHttpTransferUpdate();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrHttpTransferUpdate(ovrHttpTransferUpdateHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrHttpTransferUpdateHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * InstalledApplication provides a way to retrieve information about installed application on a device,
 * including their package name, application ID, version name, version code, and status.
 * This information can be useful for tracking the status of applications on a device and identifying any issues that may need to be addressed.
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|InstalledApplication")
struct OVRPLATFORM_API FOvrInstalledApplication
{
    GENERATED_USTRUCT_BODY()

    /** It's a type of `string` represents the ID of the application, which is a unique identifier for the app. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|InstalledApplication|Field")
    FString ApplicationId;

    /** The package name of the installed application. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|InstalledApplication|Field")
    FString PackageName;

    /** A `string` represents the status of the installed application. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|InstalledApplication|Field")
    FString Status;

    /**
     * It's a type of `int` represents the current version code of the installed application.
     * It can be retreiving using field FOvrApplicationVersion::CurrentCode
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|InstalledApplication|Field")
    int32 VersionCode;

    /**
     * It's a type of `string` represents the current version name of the installed application.
     * It can be retreiving using field FOvrApplicationVersion::CurrentName
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|InstalledApplication|Field")
    FString VersionName;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrInstalledApplicationHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrInstalledApplication();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrInstalledApplication(ovrInstalledApplicationHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrInstalledApplicationHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * The information about the user's invitation to others to join their current session.
 * It can be retrieved using GroupPresence_LaunchInvitePanel()}.
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|InvitePanelResultInfo")
struct OVRPLATFORM_API FOvrInvitePanelResultInfo
{
    GENERATED_USTRUCT_BODY()

    /** A boolean for whether or not any invites have been sent. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|InvitePanelResultInfo|Field")
    bool InvitesSent;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrInvitePanelResultInfoHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrInvitePanelResultInfo();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrInvitePanelResultInfo(ovrInvitePanelResultInfoHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrInvitePanelResultInfoHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * It contains information about a specific language, including its identification tag, and names in both English and the native language.
 * It is useful for applications supporting multiple languages. It can be retrieved using field FOvrAssetDetails::Language.
 * Learn more about language pack in our [website](https://developer.oculus.com/documentation/unreal/ps-language-packs/)
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|LanguagePackInfo")
struct OVRPLATFORM_API FOvrLanguagePackInfo
{
    GENERATED_USTRUCT_BODY()

    /** Language name in English language. For example, the English name for "de.lang" will be "German". */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LanguagePackInfo|Field")
    FString EnglishName;

    /** Language name in its native language. For example, the native name for "de.lang" will be "Deutsch". */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LanguagePackInfo|Field")
    FString NativeName;

    /** Language tag in [BCP47](https://www.rfc-editor.org/info/bcp47) format with a suffix of "lang". For example, "de.lang" is a valid language pack name and its `tag` will be "de". */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LanguagePackInfo|Field")
    FString Tag;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrLanguagePackInfoHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrLanguagePackInfo();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrLanguagePackInfo(ovrLanguagePackInfoHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrLanguagePackInfoHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * An AssetDetails object contains detailed metadata for an asset file, including the asset file ID,
 * file path, asset type, and additional metadata that characterizes the asset. You can retrieve the
 * asset details using AssetFile_GetList()
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|AssetDetails")
struct OVRPLATFORM_API FOvrAssetDetails
{
    GENERATED_USTRUCT_BODY()

    /**  ID of the asset file. You can use this ID to uniquely identify a single asset. You can find more details from AssetFile_StatusById() */
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

    /** The status of in app purchases which are some extra content that users can buy right from apps. The value could be one of 'free', 'entitled', or 'not-entitled'. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AssetDetails|Field")
    FString IapStatus;

    /** This field gives information about currently selected and installed language for the asset. The language info contains language name and tag in BCP47 format. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AssetDetails|Field")
    FOvrLanguagePackInfo Language;

    /** Extra metadata associated with this asset file */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|AssetDetails|Field")
    FString Metadata;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrAssetDetailsHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrAssetDetails();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrAssetDetails(ovrAssetDetailsHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrAssetDetailsHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * It's used to block a user. Results of the launched block dialog including  whether the user was successfully blocked and whether the viewer canceled the block flow.
 * It can be retrieved using User_LaunchBlockFlow()
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|LaunchBlockFlowResult")
struct OVRPLATFORM_API FOvrLaunchBlockFlowResult
{
    GENERATED_USTRUCT_BODY()

    /**
     * A `boolean` indicates whether the viewer successfully blocked the user.
     * Learn more about [blocking users](https://developer.oculus.com/documentation/unreal/ps-blockingsdk/) from our website.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LaunchBlockFlowResult|Field")
    bool DidBlock;

    /** A `boolean` indicates whether the viewer chose to cancel the block flow. It will be 'true' if the viewer canceled 'Block' from the modal. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LaunchBlockFlowResult|Field")
    bool DidCancel;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrLaunchBlockFlowResultHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrLaunchBlockFlowResult();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrLaunchBlockFlowResult(ovrLaunchBlockFlowResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrLaunchBlockFlowResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * Users can initiate follow requests to other users encountered in the app
 * by launching the process from within the app. After the follow request has
 * been sent via a deeplinked modal, the viewer is returned to the app.
 * Users may find this process more convenient than using the Meta Quest mobile
 * app or returning to Meta Horizon Home to send follow requests since it is
 * less disruptive to the app experience they are currently focused on.
 * You can retrieve it using User_LaunchFriendRequestFlow().
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|LaunchFriendRequestFlowResult")
struct OVRPLATFORM_API FOvrLaunchFriendRequestFlowResult
{
    GENERATED_USTRUCT_BODY()

    /**
     * User can choose to cancel the friend request flow after sending it.
     * You can use this to check whether the viewer chose to cancel the friend request flow.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LaunchFriendRequestFlowResult|Field")
    bool DidCancel;

    /** Whether the viewer successfully sent the friend request. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LaunchFriendRequestFlowResult|Field")
    bool DidSendRequest;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrLaunchFriendRequestFlowResultHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrLaunchFriendRequestFlowResult();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrLaunchFriendRequestFlowResult(ovrLaunchFriendRequestFlowResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrLaunchFriendRequestFlowResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * Results of the launched report dialog including resulting report ID and user action. It can be retrieved using AbuseReport_ReportRequestHandled() to handle the result of a report request.
 * Learn more about our [User Reporting Service](https://developer.oculus.com/resources/reporting-service#faq_856753478660534).
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|LaunchReportFlowResult")
struct OVRPLATFORM_API FOvrLaunchReportFlowResult
{
    GENERATED_USTRUCT_BODY()

    /** A `boolean` which indicates whether the viewer chose to cancel the report flow before completing it. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LaunchReportFlowResult|Field")
    bool DidCancel;

    /**
     * ID of the report created by the user. It's optional and may not be present if the user cancelled the report flow.
     * Learn more about the [user reporting plugin](https://developer.oculus.com/resources/reporting-plugin) in our website.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LaunchReportFlowResult|Field")
    FOvrId UserReportId;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrLaunchReportFlowResultHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrLaunchReportFlowResult();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrLaunchReportFlowResult(ovrLaunchReportFlowResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrLaunchReportFlowResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * It's used to unblock a user. Results of the launched unblock dialog including whether the user was successfully unblocked and whether the viewer canceled the unblock flow.
 * It can be retrieved using User_LaunchUnblockFlow().
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|LaunchUnblockFlowResult")
struct OVRPLATFORM_API FOvrLaunchUnblockFlowResult
{
    GENERATED_USTRUCT_BODY()

    /** A `boolean` indicates whether the viewer chose to cancel the unblock flow. It will be 'true' if the viewer canceled 'Unblock' from the modal. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LaunchUnblockFlowResult|Field")
    bool DidCancel;

    /**
     * A `boolean` indicates whether the viewer successfully unblocked the user.
     * Learn more about [unblocking users](https://developer.oculus.com/documentation/unreal/ps-blockingsdk/) from our website.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LaunchUnblockFlowResult|Field")
    bool DidUnblock;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrLaunchUnblockFlowResultHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrLaunchUnblockFlowResult();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrLaunchUnblockFlowResult(ovrLaunchUnblockFlowResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrLaunchUnblockFlowResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * Leaderboards provide a way for a game to keep track of players and their scores in relation to other.
 * The leaderboard object contains information about this leaderboard ID, API name and destination.
 * Lean more about [leaderboard](https://developer.oculus.com/documentation/unreal/ps-leaderboards/) on our website.
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|Leaderboard")
struct OVRPLATFORM_API FOvrLeaderboard
{
    GENERATED_USTRUCT_BODY()

    /** The API name of this leaderboard. This is a unique string that your application will refer to this leaderboard in your app code. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Leaderboard|Field")
    FString ApiName;

    /** An optional deep link FOvrDestination, which means when a user clicks on the leaderboard, they will be taken to this in-app destination. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Leaderboard|Field")
    FOvrDestination Destination;

    /** The generated GUID of this leaderboard. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Leaderboard|Field")
    FOvrId ID;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrLeaderboardHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrLeaderboard();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrLeaderboard(ovrLeaderboardHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrLeaderboardHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};

/** Represents a paginated list of FOvrLeaderboard elements */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|LeaderboardArray")
struct OVRPLATFORM_API FOvrLeaderboardPages
{
    GENERATED_USTRUCT_BODY()

    /// \brief This is the default constructor for the struct, which initializes the ::ovrLeaderboardArrayHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrLeaderboardPages();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrLeaderboardPages(ovrLeaderboardArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrLeaderboardArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // OVR array handle for methods
    mutable ovrLeaderboardArrayHandle PagedArrayHandle;

    // Original ref-counted message to hold onto array handle
    mutable TOvrMessageHandlePtr PagedArrayMessageHandlePtr;
};

UCLASS()
/// \brief This class provides methods for accessing and manipulating the elements in a FOvrLeaderboardPages paginated list. It allows you to easily retrieve and modify the elements in the list, as well as check if there is a next page of elements available.
class OVRPLATFORM_API UOvrLeaderboardPagesMethods : public UObject
{
    GENERATED_BODY()

public:

    /** Access the indexed element in this list. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|LeaderboardPages")
    static FOvrLeaderboard LeaderboardPages_GetElement(const FOvrLeaderboardPages& Model, int64 Index);

    /** The URL to request the next paginated list of elements. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|LeaderboardPages")
    static FString LeaderboardPages_GetNextUrl(const FOvrLeaderboardPages& Model);

    /** The number of elements contained within this list. This is not equal to the total number of elements across multiple pages. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|LeaderboardPages")
    static int64 LeaderboardPages_GetSize(const FOvrLeaderboardPages& Model);

    /** Whether there is a next page of elements that can be retrieved. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|LeaderboardPages")
    static bool LeaderboardPages_HasNextPage(const FOvrLeaderboardPages& Model);
};


/** This object contains information about the status of the request to update the leaderboard.  */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|LeaderboardUpdateStatus")
struct OVRPLATFORM_API FOvrLeaderboardUpdateStatus
{
    GENERATED_USTRUCT_BODY()

    /** Whether the leaderboard was updated. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LeaderboardUpdateStatus|Field")
    bool DidUpdate;

    /**
     * If the leaderboard is updated, this represents the updated challenge IDs.
     * The updated challenge IDs can be used by Challenges_GetEntries(), Challenges_GetEntriesAfterRank(), or Challenges_GetEntriesByIds() APIs.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LeaderboardUpdateStatus|Field")
    TArray<FOvrId> UpdatedChallengeIds;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrLeaderboardUpdateStatusHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrLeaderboardUpdateStatus();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrLeaderboardUpdateStatus(ovrLeaderboardUpdateStatusHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrLeaderboardUpdateStatusHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * Represents a linked account that is associated with the FOvrUser's account in the system.
 *  It provides a way to store and manage information about linked accounts in the system,
 *  allowing users to easily access and manage their data or services from multiple platforms in one place
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|LinkedAccount")
struct OVRPLATFORM_API FOvrLinkedAccount
{
    GENERATED_USTRUCT_BODY()

    /**
     * Access token of the linked account.
     * This token is used to authenticate the user on the service provider's platform and grant access to their data or services.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LinkedAccount|Field")
    FString AccessToken;

    /**
     * Service provider with which the linked account is associated.
     * There are several possible service providers that can be found in EOvrServiceProvider.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LinkedAccount|Field")
    EOvrServiceProvider ServiceProvider;

    /**
     * A unique identifier represents the user ID of the linked account.
     * It can be retrieved using field FOvrUser::ID
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LinkedAccount|Field")
    FString UserId;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrLinkedAccountHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrLinkedAccount();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrLinkedAccount(ovrLinkedAccountHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrLinkedAccountHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * The livestreaming application status represents the status result of whether
 * the livestreaming is enabled for an app. If your app is enabled, you will receive
 * FOvrNotification_Livestreaming_StatusChange when the livestreaming session gets updated.
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|LivestreamingApplicationStatus")
struct OVRPLATFORM_API FOvrLivestreamingApplicationStatus
{
    GENERATED_USTRUCT_BODY()

    /** This is a boolean field and represents whether the app is allowed to do the livestreaming or not. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LivestreamingApplicationStatus|Field")
    bool StreamingEnabled;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrLivestreamingApplicationStatusHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrLivestreamingApplicationStatus();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrLivestreamingApplicationStatus(ovrLivestreamingApplicationStatusHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrLivestreamingApplicationStatusHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * You will receive this livestreaming start result once you start a livestream to Facebook or to a party in your app.
 * This result will show if the start status is a success or unknown or a failure because of various reasons including no
 * Facebook connection or missing parameters.
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|LivestreamingStartResult")
struct OVRPLATFORM_API FOvrLivestreamingStartResult
{
    GENERATED_USTRUCT_BODY()

    /**
     * This livestreaming result represents the start status of your livestream.
     * You can refer to EOvrLivestreamingStartStatus for possible status info.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LivestreamingStartResult|Field")
    EOvrLivestreamingStartStatus StreamingResult;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrLivestreamingStartResultHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrLivestreamingStartResult();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrLivestreamingStartResult(ovrLivestreamingStartResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrLivestreamingStartResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * The livestreaming status represents the status of a livestreaming event in your app.
 * You will receive FOvrNotification_Livestreaming_StatusChange whenever your livestreaming
 * session gets updated. The status contains info about your livestream type, whether your mic
 * is enabled, whether the comments are visible and etc.
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|LivestreamingStatus")
struct OVRPLATFORM_API FOvrLivestreamingStatus
{
    GENERATED_USTRUCT_BODY()

    /** This boolean field indicates if the comments from the audience in your livestreaming are visible. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LivestreamingStatus|Field")
    bool CommentsVisible;

    /** This boolean field indicates if your livestreaming in the app is paused or not. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LivestreamingStatus|Field")
    bool IsPaused;

    /**
     * This boolean field indicates if your app is livestreaming enabled. If your app is enabled,
     * you will receive FOvrNotification_Livestreaming_StatusChange when the livestreaming
     * session gets updated.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LivestreamingStatus|Field")
    bool LivestreamingEnabled;

    /** This field indicates the type of your livestreaming. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LivestreamingStatus|Field")
    int32 LivestreamingType;

    /** This boolean field indicates if your connected mic is enabled. The speaker will be muted if the field is false. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LivestreamingStatus|Field")
    bool MicEnabled;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrLivestreamingStatusHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrLivestreamingStatus();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrLivestreamingStatus(ovrLivestreamingStatusHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrLivestreamingStatusHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * The livestreaming video statistics represents the statistics info about a livestreaming video in your app.
 * The statistics include the total number of views, the number of reactions and the number of comments. You can
 * retrieve the information about whether your comments are visible from field FOvrLivestreamingStatus::CommentsVisible.
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|LivestreamingVideoStats")
struct OVRPLATFORM_API FOvrLivestreamingVideoStats
{
    GENERATED_USTRUCT_BODY()

    /** An 'integer' represents the information about the total number of comments left for your livestream video. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LivestreamingVideoStats|Field")
    int32 CommentCount;

    /** An 'integer' represents the information about the total number of reactions your livestream video received. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LivestreamingVideoStats|Field")
    int32 ReactionCount;

    /** This field gives the information about the total number of views of your livestream video. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LivestreamingVideoStats|Field")
    FString TotalViews;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrLivestreamingVideoStatsHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrLivestreamingVideoStats();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrLivestreamingVideoStats(ovrLivestreamingVideoStatsHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrLivestreamingVideoStatsHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|ManagedInfo")
struct OVRPLATFORM_API FOvrManagedInfo
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ManagedInfo|Field")
    FString Department;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ManagedInfo|Field")
    FString Email;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ManagedInfo|Field")
    FString EmployeeNumber;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ManagedInfo|Field")
    FString ExternalId;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ManagedInfo|Field")
    FString Location;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ManagedInfo|Field")
    FString Manager;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ManagedInfo|Field")
    FString Name;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ManagedInfo|Field")
    FString OrganizationId;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ManagedInfo|Field")
    FString OrganizationName;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ManagedInfo|Field")
    FString Position;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrManagedInfoHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrManagedInfo();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrManagedInfo(ovrManagedInfoHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrManagedInfoHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|Microphone")
struct OVRPLATFORM_API FOvrMicrophone
{
    GENERATED_USTRUCT_BODY()

    /// \brief This is the default constructor for the struct, which initializes the ::ovrMicrophoneHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrMicrophone();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrMicrophone(ovrMicrophoneHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
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
     * Gets all available samples of microphone data and
     * copies it into outputBuffer. The microphone will generate data at roughly
     * the rate of 480 samples per 10ms. The data format is 32 bit floating point 48khz mono.
     * 
     * 
     * This function can be safely called from any thread.
     * \deprecated Use field FOvrMicrophone::GetPCMFloat instead.
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

    /// \brief This is the default constructor for the struct, which initializes the ::ovrMicrophoneAvailabilityStateHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrMicrophoneAvailabilityState();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrMicrophoneAvailabilityState(ovrMicrophoneAvailabilityStateHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
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

    /// \brief This is the default constructor for the struct, which initializes the ::ovrNetSyncConnectionHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrNetSyncConnection();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrNetSyncConnection(ovrNetSyncConnectionHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
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

    /// \brief This is the default constructor for the struct, which initializes the ::ovrNetSyncSessionHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrNetSyncSession();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrNetSyncSession(ovrNetSyncSessionHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
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

    /// \brief This is the default constructor for the struct, which initializes the ::ovrNetSyncSessionsChangedNotificationHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrNetSyncSessionsChangedNotification();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrNetSyncSessionsChangedNotification(ovrNetSyncSessionsChangedNotificationHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrNetSyncSessionsChangedNotificationHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|NetSyncSetSessionPropertyResult")
struct OVRPLATFORM_API FOvrNetSyncSetSessionPropertyResult
{
    GENERATED_USTRUCT_BODY()

    /** Which session the operation was modifying */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|NetSyncSetSessionPropertyResult|Field")
    FOvrNetSyncSession Session;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrNetSyncSetSessionPropertyResultHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrNetSyncSetSessionPropertyResult();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrNetSyncSetSessionPropertyResult(ovrNetSyncSetSessionPropertyResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
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

    /// \brief This is the default constructor for the struct, which initializes the ::ovrNetSyncVoipAttenuationValueHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrNetSyncVoipAttenuationValue();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrNetSyncVoipAttenuationValue(ovrNetSyncVoipAttenuationValueHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrNetSyncVoipAttenuationValueHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * An ID for a FOvrUser which is unique per Developer Center organization.
 * It can be retrieved using User_GetOrgScopedID().
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|OrgScopedID")
struct OVRPLATFORM_API FOvrOrgScopedID
{
    GENERATED_USTRUCT_BODY()

    /** The unique id of the user, allowing different apps within the same Developer Center organization to have a consistent id for the same user. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|OrgScopedID|Field")
    FOvrId ID;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrOrgScopedIDHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrOrgScopedID();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrOrgScopedID(ovrOrgScopedIDHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrOrgScopedIDHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|Packet")
struct OVRPLATFORM_API FOvrPacket
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Packet|Field")
    TArray<uint8> Bytes;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Packet|Field")
    FOvrId SenderID;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrPacketHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrPacket();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrPacket(ovrPacketHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
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


/**
 * The party ID is a unique identifier of the party that will be generated for every distinct party. This ID can be used to make requests such as Party_Join(), Party_Leave(), Party_Create(), etc.
 * Read more about [parties](https://developer.oculus.com/documentation/unreal/ps-parties/).
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|PartyID")
struct OVRPLATFORM_API FOvrPartyID
{
    GENERATED_USTRUCT_BODY()

    /** The party ID can be used to retrieve FOvrParty. Every party will have a unique ID that is associated with it. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|PartyID|Field")
    FOvrId ID;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrPartyIDHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrPartyID();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrPartyID(ovrPartyIDHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrPartyIDHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/** The notification about updating a party status information to a participating user. Party Notifications are intended to update the user on various actions that are occurring in the user's party. This is primarily used in {'party_update': 'FOvrNotification_Party_PartyUpdate'}. */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|PartyUpdateNotification")
struct OVRPLATFORM_API FOvrPartyUpdateNotification
{
    GENERATED_USTRUCT_BODY()

    /**
     * An enum that specifies the type of action related to the party and user that this notification holds. It can be retrieved by using field FOvrPartyUpdateNotification::Action.
     * 
     * EOvrPartyUpdateAction::Join: The user is going to join the party.
     * 
     * EOvrPartyUpdateAction::Leave: The user is going to leave the party.
     * 
     * EOvrPartyUpdateAction::Invite: The user is invited to the party. 
     * 
     * EOvrPartyUpdateAction::Uninvite: The user is uninvited from the party. 
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|PartyUpdateNotification|Field")
    EOvrPartyUpdateAction Action;

    /** The ID of the party that will be updated. This can be retrieved with FOvrPartyID. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|PartyUpdateNotification|Field")
    FOvrId PartyId;

    /** The id of the FOvrUser who initiated the action that this party update status notification is in reference to. This is equivalent to field FOvrUser::ID for this user. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|PartyUpdateNotification|Field")
    FOvrId SenderId;

    /** A timestamp denoting when the party action occurred that this status update notification refers to. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|PartyUpdateNotification|Field")
    FString UpdateTimestamp;

    /** The alias of the FOvrUser whose party status has changed. This is an alias that is set by the user. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|PartyUpdateNotification|Field")
    FString UserAlias;

    /** The ID of the user, field FOvrUser::ID, whose party status has changed. This is a unique value for every FOvrUser. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|PartyUpdateNotification|Field")
    FOvrId UserId;

    /** The displayable name of the FOvrUser whose party status has changed. This is equivalent to field FOvrUser::DisplayName for this user. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|PartyUpdateNotification|Field")
    FString UserName;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrPartyUpdateNotificationHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrPartyUpdateNotification();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrPartyUpdateNotification(ovrPartyUpdateNotificationHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrPartyUpdateNotificationHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|Pid")
struct OVRPLATFORM_API FOvrPid
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Pid|Field")
    FString Id;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrPidHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrPid();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrPid(ovrPidHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrPidHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**  A PlatformInitialize object defines an attempt at initializing the Platform SDK. It contains the result of attempting to initialize the platform. The different types of initialization results are EOvrPlatformInitializeResult. */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|PlatformInitialize")
struct OVRPLATFORM_API FOvrPlatformInitialize
{
    GENERATED_USTRUCT_BODY()

    /**
     * The result of attempting to initialize the platform:
     * 
     * EOvrPlatformInitializeResult::Success - Platform SDK initialization succeeded.
     * 
     * EOvrPlatformInitializeResult::Uninitialized - Platform SDK was not initialized.
     * 
     * EOvrPlatformInitializeResult::PreLoaded - Platform SDK failed to initialize because the pre-loaded module was on a different path than the validated library.
     * 
     * EOvrPlatformInitializeResult::FileInvalid - Platform SDK files failed to load.
     * 
     * EOvrPlatformInitializeResult::SignatureInvalid - Platform SDK failed to initialize due to an invalid signature in the signed certificate.
     * 
     * EOvrPlatformInitializeResult::UnableToVerify - Platform SDK failed to verify the application's signature during initialization.
     * 
     * EOvrPlatformInitializeResult::VersionMismatch - There was a mismatch between the version of Platform SDK used by the application and the version installed on the user's device.
     * 
     * EOvrPlatformInitializeResult::InvalidCredentials - Platform SDK failed to initialize because the user had an invalid account access token.
     * 
     * EOvrPlatformInitializeResult::NotEntitled - Platform SDK failed to initialize because the user does not have the application entitlement.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|PlatformInitialize|Field")
    EOvrPlatformInitializeResult Result;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrPlatformInitializeHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrPlatformInitialize();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrPlatformInitialize(ovrPlatformInitializeHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrPlatformInitializeHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/** The price of a FOvrProduct. A price with a currency of "USD" and an amount in hundredths of 99 has a formatted string of "$0.99". */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|Price")
struct OVRPLATFORM_API FOvrPrice
{
    GENERATED_USTRUCT_BODY()

    /** The price of the product in hundredths of currency units. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Price|Field")
    int32 AmountInHundredths;

    /** The ISO 4217 currency code for the price of the product. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Price|Field")
    FString Currency;

    /** The formatted string representation of the price. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Price|Field")
    FString Formatted;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrPriceHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrPrice();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrPrice(ovrPriceHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrPriceHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * The class that represents the product information for a specific IAP which is available for purchase in your app.
 *   You can retrieve more information about the product(s) by using their SKU with IAP_GetProductsBySKU()
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|Product")
struct OVRPLATFORM_API FOvrProduct
{
    GENERATED_USTRUCT_BODY()

    /** The description for the product. The description should be meaningful and explanatory to help outline the product and its features. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Product|Field")
    FString Description;

    /** The formatted string for the FOvrPrice. This is the same value stored in FOvrPrice. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Product|Field")
    FString FormattedPrice;

    /** The name of the product. This will be used as a the display name and should be aligned with the user facing title. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Product|Field")
    FString Name;

    /** The FOvrPrice of the product contains the currency code, the amount in hundredths, and the formatted string representation. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Product|Field")
    FOvrPrice Price;

    /** The unique string that you use to reference the product in your app. The SKU is case-sensitive and should match the SKU reference in your code. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Product|Field")
    FString SKU;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrProductHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrProduct();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrProduct(ovrProductHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrProductHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};

/** Represents a paginated list of FOvrProduct elements */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|ProductArray")
struct OVRPLATFORM_API FOvrProductPages
{
    GENERATED_USTRUCT_BODY()

    /// \brief This is the default constructor for the struct, which initializes the ::ovrProductArrayHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrProductPages();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrProductPages(ovrProductArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrProductArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // OVR array handle for methods
    mutable ovrProductArrayHandle PagedArrayHandle;

    // Original ref-counted message to hold onto array handle
    mutable TOvrMessageHandlePtr PagedArrayMessageHandlePtr;
};

UCLASS()
/// \brief This class provides methods for accessing and manipulating the elements in a FOvrProductPages paginated list. It allows you to easily retrieve and modify the elements in the list, as well as check if there is a next page of elements available.
class OVRPLATFORM_API UOvrProductPagesMethods : public UObject
{
    GENERATED_BODY()

public:

    /** Access the indexed element in this list. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ProductPages")
    static FOvrProduct ProductPages_GetElement(const FOvrProductPages& Model, int64 Index);

    /** The URL to request the next paginated list of elements. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ProductPages")
    static FString ProductPages_GetNextUrl(const FOvrProductPages& Model);

    /** The number of elements contained within this list. This is not equal to the total number of elements across multiple pages. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ProductPages")
    static int64 ProductPages_GetSize(const FOvrProductPages& Model);

    /** Whether there is a next page of elements that can be retrieved. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ProductPages")
    static bool ProductPages_HasNextPage(const FOvrProductPages& Model);
};


/** A purchase is made when a user buys a FOvrProduct. The IAP product, which can represent a consumable item, a durable item, or a subscription, must be defined for purchase through the developer dashboard. */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|Purchase")
struct OVRPLATFORM_API FOvrPurchase
{
    GENERATED_USTRUCT_BODY()

    /** The developer payload feature is unimplemented. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Purchase|Field")
    FString DeveloperPayload;

    /** The time when the purchased FOvrProduct expires. This value only applies to subscriptions, and will be null for durable and consumable IAP items. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Purchase|Field")
    FDateTime ExpirationTime;

    /** The timestamp that represents when the user was granted entitlement to the FOvrProduct that was purchased. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Purchase|Field")
    FDateTime GrantTime;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Purchase|Field")
    FString PurchaseID;

    /** The Reporting ID feature is not implemented. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Purchase|Field")
    FString ReportingId;

    /** The SKU of the IAP FOvrProduct that was purchased. This value is case-sensitive. To retrieve the product information, you can use this value when calling IAP_GetProductsBySKU(). */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Purchase|Field")
    FString SKU;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrPurchaseHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrPurchase();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrPurchase(ovrPurchaseHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrPurchaseHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};

/** Represents a paginated list of FOvrPurchase elements */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|PurchaseArray")
struct OVRPLATFORM_API FOvrPurchasePages
{
    GENERATED_USTRUCT_BODY()

    /// \brief This is the default constructor for the struct, which initializes the ::ovrPurchaseArrayHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrPurchasePages();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrPurchasePages(ovrPurchaseArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrPurchaseArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // OVR array handle for methods
    mutable ovrPurchaseArrayHandle PagedArrayHandle;

    // Original ref-counted message to hold onto array handle
    mutable TOvrMessageHandlePtr PagedArrayMessageHandlePtr;
};

UCLASS()
/// \brief This class provides methods for accessing and manipulating the elements in a FOvrPurchasePages paginated list. It allows you to easily retrieve and modify the elements in the list, as well as check if there is a next page of elements available.
class OVRPLATFORM_API UOvrPurchasePagesMethods : public UObject
{
    GENERATED_BODY()

public:

    /** Access the indexed element in this list. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|PurchasePages")
    static FOvrPurchase PurchasePages_GetElement(const FOvrPurchasePages& Model, int64 Index);

    /** The URL to request the next paginated list of elements. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|PurchasePages")
    static FString PurchasePages_GetNextUrl(const FOvrPurchasePages& Model);

    /** The number of elements contained within this list. This is not equal to the total number of elements across multiple pages. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|PurchasePages")
    static int64 PurchasePages_GetSize(const FOvrPurchasePages& Model);

    /** Whether there is a next page of elements that can be retrieved. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|PurchasePages")
    static bool PurchasePages_HasNextPage(const FOvrPurchasePages& Model);
};


/**
 * A boolean that indicates the result of GroupPresence_LaunchRejoinDialog().
 * 'True' indicates that the application will rejoin the dialog, otherwise the application will not rejoin the dialog.
 * Read more about the [rejoin dialog](https://developer.oculus.com/documentation/unreal/ps-rejoin/#rejoin-apis).
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|RejoinDialogResult")
struct OVRPLATFORM_API FOvrRejoinDialogResult
{
    GENERATED_USTRUCT_BODY()

    /** A boolean for if the user has decided to rejoin. This is used in GroupPresence_LaunchRejoinDialog(). */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|RejoinDialogResult|Field")
    bool RejoinSelected;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrRejoinDialogResultHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrRejoinDialogResult();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrRejoinDialogResult(ovrRejoinDialogResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrRejoinDialogResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/** A single user can have multiple sdk accounts associated with it. SDK accounts represent the oculus user and x-accounts that are linked to the particular user. Retrieve the SDK accounts by using, User_GetSdkAccounts(). */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|SdkAccount")
struct OVRPLATFORM_API FOvrSdkAccount
{
    GENERATED_USTRUCT_BODY()

    /**
     * The specific type of account that this sdk account represents. The type can be one of the following: 
     * 
     * EOvrSdkAccountType::Unknown
     * 
     * EOvrSdkAccountType::Oculus
     * 
     * EOvrSdkAccountType::FacebookGameroom
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|SdkAccount|Field")
    EOvrSdkAccountType AccountType;

    /** The ID of the user, field FOvrUser::ID, of the sdk account. This is a unique value for every FOvrUser. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|SdkAccount|Field")
    FOvrId UserId;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrSdkAccountHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrSdkAccount();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrSdkAccount(ovrSdkAccountHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrSdkAccountHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/** The result from users launching the Share to Facebook modal which enables them to share local media files through Media_ShareToFacebook(). The result will contain a status field, EOvrShareMediaStatus. */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|ShareMediaResult")
struct OVRPLATFORM_API FOvrShareMediaResult
{
    GENERATED_USTRUCT_BODY()

    /**
     * The status of the share media result. The status can be of the following types:
     * 
     * EOvrShareMediaStatus::Unknown
     * 
     * EOvrShareMediaStatus::Shared
     * 
     * EOvrShareMediaStatus::Canceled
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ShareMediaResult|Field")
    EOvrShareMediaStatus Status;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrShareMediaResultHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrShareMediaResult();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrShareMediaResult(ovrShareMediaResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrShareMediaResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * This is a supplemental piece of data that is used for a single write to leaderboard entries. This metric is used for tiebreaker scenarios.
 *  You can make such an entry by using Leaderboard_WriteEntryWithSupplementaryMetric()
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|SupplementaryMetric")
struct OVRPLATFORM_API FOvrSupplementaryMetric
{
    GENERATED_USTRUCT_BODY()

    /** The ID of the leaderboard that this supplementary metric belongs to. This is the unique value for every FOvrLeaderboard. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|SupplementaryMetric|Field")
    FOvrId ID;

    /** This is the metric that is used to determine tiebreaks. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|SupplementaryMetric|Field")
    int64 Metric;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrSupplementaryMetricHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrSupplementaryMetric();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrSupplementaryMetric(ovrSupplementaryMetricHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
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

    /// \brief This is the default constructor for the struct, which initializes the ::ovrSystemVoipStateHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrSystemVoipState();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrSystemVoipState(ovrSystemVoipStateHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrSystemVoipStateHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * This is the class that represents the individual users who use your application.
 * Use the User object to retrieve information about your users, help them interact with your application, and customize their experience.
 * You can query for information about a particular user using their user id, field FOvrUser::ID. To learn more, read our [docs](https://developer.oculus.com/documentation/unreal/ps-presence/#user-and-friends) about users.
 * Note: You must complete a Data Use Checkup(DUC) in order to gain access to user platform features. Read more about DUC [here](https://developer.oculus.com/resources/publish-data-use/).
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|User")
struct OVRPLATFORM_API FOvrUser
{
    GENERATED_USTRUCT_BODY()

    /** A potentially non unique displayable name chosen by the FOvrUser. Could also be the same as the oculus_ID. This is often the name shown to other users. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|User|Field")
    FString DisplayName;

    /** The ID of the user, field FOvrUser::ID. This is a unique value for every individual FOvrUser. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|User|Field")
    FOvrId ID;

    /** The url of the profile picture that is chosen by the user. Retrieve this url by using field FOvrUser::ImageUrl. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|User|Field")
    FString ImageUrl;

    /**
     * Managed account info, FOvrManagedInfo, for the user which contains further metadata that is only available if the user is a Meta Managed Account(MMA).
     * There must be user consent via dialog during installation, your app must have DUC enabled, and the app must be admin-approved.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|User|Field")
    FOvrManagedInfo ManagedInfo;

    /** The oculus ID of the FOvrUser. This is used across the developer dashboard and is unique to oculus. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|User|Field")
    FString OculusID;

    /** Human readable string of what the user is currently doing. Not intended to be parsed as it might change at anytime or be translated. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|User|Field")
    FString Presence;

    /** Intended to be parsed and used to deeplink to parts of the app. Read more about deeplinking [here](https://developer.oculus.com/documentation/unreal/ps-deep-linking/). */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|User|Field")
    FString PresenceDeeplinkMessage;

    /** If provided, this is the unique API Name that refers to the FOvrDestination this user is currently at in the app. Read more about destinations [here](https://developer.oculus.com/documentation/unreal/ps-destinations-overview/) */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|User|Field")
    FString PresenceDestinationApiName;

    /**
     * If provided, the lobby session this user is currently at in the application. If the ApplicationInvite is generated from rich presence,
     * the lobby session id will be auto populated by calling field FOvrUser::PresenceLobbySessionId from the inviters' viewer context.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|User|Field")
    FString PresenceLobbySessionId;

    /**
     * If provided, the match session this user is currently at in the application. If the ApplicationInvite is generated from rich presence,
     * the match session id will be auto populated by calling field FOvrUser::PresenceMatchSessionId from the inviters' viewer context.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|User|Field")
    FString PresenceMatchSessionId;

    /** An enum value for the different statuses representing what the user is currently doing. The different statuses can be EOvrUserPresenceStatus::Unknown, EOvrUserPresenceStatus::Offline, EOvrUserPresenceStatus::Online. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|User|Field")
    EOvrUserPresenceStatus PresenceStatus;

    /** The url of the smaller/secondary profile picture that is chosen by the user. Retrieve this url by using field FOvrUser::SmallImageUrl. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|User|Field")
    FString SmallImageUrl;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrUserHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrUser();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrUser(ovrUserHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrUserHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * An Application Invite contains information about the invite, including the application ID,
 * destination, activity status, the lobby session id, the match session id,
 * and recipient's user id or user alias. If the invite is generated from rich presence,
 * the lobby/match session id will be auto populated by calling field FOvrUser::PresenceLobbySessionId
 * and field FOvrUser::PresenceMatchSessionId from the inviter's viewer context.
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|ApplicationInvite")
struct OVRPLATFORM_API FOvrApplicationInvite
{
    GENERATED_USTRUCT_BODY()

    /** The destination to which the recipient is invited. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ApplicationInvite|Field")
    FOvrDestination Destination;

    /** The ID of the application invite. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ApplicationInvite|Field")
    FOvrId ID;

    /** A boolean value indicating whether the invite is still active or not. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ApplicationInvite|Field")
    bool IsActive;

    /**
     * The lobby session id to which the recipient is invited. You can retrieve this by
     * calling field FOvrUser::PresenceLobbySessionId from the inviter's viewer context.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ApplicationInvite|Field")
    FString LobbySessionId;

    /**
     * The match session id to which the recipient is invited. You can retrieve this by
     * calling field FOvrUser::PresenceMatchSessionId from the inviter's viewer context.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ApplicationInvite|Field")
    FString MatchSessionId;

    /**
     * The recipient's user information, such as their ID and alias. You can get the ID of an
     * user by calling field FOvrUser::ID.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ApplicationInvite|Field")
    FOvrUser Recipient;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrApplicationInviteHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrApplicationInvite();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrApplicationInvite(ovrApplicationInviteHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrApplicationInviteHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};

/** Represents a paginated list of FOvrApplicationInvite elements */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|ApplicationInviteArray")
struct OVRPLATFORM_API FOvrApplicationInvitePages
{
    GENERATED_USTRUCT_BODY()

    /// \brief This is the default constructor for the struct, which initializes the ::ovrApplicationInviteArrayHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrApplicationInvitePages();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrApplicationInvitePages(ovrApplicationInviteArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrApplicationInviteArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // OVR array handle for methods
    mutable ovrApplicationInviteArrayHandle PagedArrayHandle;

    // Original ref-counted message to hold onto array handle
    mutable TOvrMessageHandlePtr PagedArrayMessageHandlePtr;
};

UCLASS()
/// \brief This class provides methods for accessing and manipulating the elements in a FOvrApplicationInvitePages paginated list. It allows you to easily retrieve and modify the elements in the list, as well as check if there is a next page of elements available.
class OVRPLATFORM_API UOvrApplicationInvitePagesMethods : public UObject
{
    GENERATED_BODY()

public:

    /** Access the indexed element in this list. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ApplicationInvitePages")
    static FOvrApplicationInvite ApplicationInvitePages_GetElement(const FOvrApplicationInvitePages& Model, int64 Index);

    /** The URL to request the next paginated list of elements. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ApplicationInvitePages")
    static FString ApplicationInvitePages_GetNextUrl(const FOvrApplicationInvitePages& Model);

    /** The number of elements contained within this list. This is not equal to the total number of elements across multiple pages. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ApplicationInvitePages")
    static int64 ApplicationInvitePages_GetSize(const FOvrApplicationInvitePages& Model);

    /** Whether there is a next page of elements that can be retrieved. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ApplicationInvitePages")
    static bool ApplicationInvitePages_HasNextPage(const FOvrApplicationInvitePages& Model);
};


/**
 * A challenge entry object contains information about an individual entry within a challenge such as the user who made the entry, the score achieved, and other relevant details.
 * It's the array element type of FOvrChallengeEntryArray and can be retrieved using Challenges_GetEntries().
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|ChallengeEntry")
struct OVRPLATFORM_API FOvrChallengeEntry
{
    GENERATED_USTRUCT_BODY()

    /** A displayable score for this challenge entry. The score is formatted with thousands separators and the relevant units are appended based on the associated leaderboard's score type. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ChallengeEntry|Field")
    FString DisplayScore;

    /** A 2KB custom data field that is associated with the challenge entry. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ChallengeEntry|Field")
    TArray<uint8> ExtraData;

    /** The unique identifier of this challenge entry which can be used by Challenges_GetEntriesByIds() and Challenges_GetEntries(). */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ChallengeEntry|Field")
    FOvrId ID;

    /** Challenges can be ranked by highest or lowest scores within a time period. This indicates the position of this challenge entry. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ChallengeEntry|Field")
    int32 Rank;

    /** The raw underlying value of the challenge entry score. It is a type of string that is returned by a long integer. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ChallengeEntry|Field")
    int64 Score;

    /** The timestamp of the creation of this entry in the challenge. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ChallengeEntry|Field")
    FDateTime Timestamp;

    /** The user corresponding to this entry within the challenge. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|ChallengeEntry|Field")
    FOvrUser User;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrChallengeEntryHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrChallengeEntry();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrChallengeEntry(ovrChallengeEntryHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrChallengeEntryHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};

/** A paginated array of FOvrChallengeEntry which can be retrieved by Challenges_GetEntries(). */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|ChallengeEntryArray")
struct OVRPLATFORM_API FOvrChallengeEntryPages
{
    GENERATED_USTRUCT_BODY()

    /// \brief This is the default constructor for the struct, which initializes the ::ovrChallengeEntryArrayHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrChallengeEntryPages();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrChallengeEntryPages(ovrChallengeEntryArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrChallengeEntryArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // OVR array handle for methods
    mutable ovrChallengeEntryArrayHandle PagedArrayHandle;

    // Original ref-counted message to hold onto array handle
    mutable TOvrMessageHandlePtr PagedArrayMessageHandlePtr;
};

UCLASS()
/// \brief This class provides methods for accessing and manipulating the elements in a FOvrChallengeEntryPages paginated list. It allows you to easily retrieve and modify the elements in the list, as well as check if there is a next page of elements available.
class OVRPLATFORM_API UOvrChallengeEntryPagesMethods : public UObject
{
    GENERATED_BODY()

public:

    /** The element of this array and the element type is FOvrChallengeEntry. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ChallengeEntryPages")
    static FOvrChallengeEntry ChallengeEntryPages_GetElement(const FOvrChallengeEntryPages& Model, int64 Index);

    /** The url of the next page of challenge entries. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ChallengeEntryPages")
    static FString ChallengeEntryPages_GetNextUrl(const FOvrChallengeEntryPages& Model);

    /** The url of the previous page of challenge entries. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ChallengeEntryPages")
    static FString ChallengeEntryPages_GetPreviousUrl(const FOvrChallengeEntryPages& Model);

    /** The size of this challenge entry array in bytes. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ChallengeEntryPages")
    static int64 ChallengeEntryPages_GetSize(const FOvrChallengeEntryPages& Model);

    /** The total count of FOvrChallengeEntry in this array, across all pages. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ChallengeEntryPages")
    static int64 ChallengeEntryPages_GetTotalCount(const FOvrChallengeEntryPages& Model);

    /** Whether this challenge entry array has a next page. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ChallengeEntryPages")
    static bool ChallengeEntryPages_HasNextPage(const FOvrChallengeEntryPages& Model);

    /** Whether this challenge entry array has a previous page. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ChallengeEntryPages")
    static bool ChallengeEntryPages_HasPreviousPage(const FOvrChallengeEntryPages& Model);
};


/**
 * A leaderboard entry object contains information about the FOvrUser who made the entry, their score, and other relevant details in the leaderboard.
 *  It provides a way for a game to keep track of players and their scores in relation to other. A single leaderboard entry can be written by Leaderboard_WriteEntry().
 *  A block of leaderboard entries can be retrieved using Leaderboard_GetEntries().
 *  Visit our [website](https://developer.oculus.com/documentation/unreal/ps-leaderboards/) for more information about the leaderboard entry.
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|LeaderboardEntry")
struct OVRPLATFORM_API FOvrLeaderboardEntry
{
    GENERATED_USTRUCT_BODY()

    /**
     * The formatted score that will be displayed in the leaderboard of this entry.
     * You can select a score type to determine how scores are displayed on Leaderboard.
     * See [here](https://developer.oculus.com/documentation/unity/ps-leaderboards/#create) for examples of different score type.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LeaderboardEntry|Field")
    FString DisplayScore;

    /**
     * A 2KB custom data field that is associated with the leaderboard entry. This can be a game replay or anything that provides more detail about the entry to the viewer.
     * It will be used by two entry methods: Leaderboard_WriteEntry() and Leaderboard_WriteEntryWithSupplementaryMetric()
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LeaderboardEntry|Field")
    TArray<uint8> ExtraData;

    /** This is a unique identifier for the leaderboard entry. It is of type `id` and is optional. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LeaderboardEntry|Field")
    FOvrId ID;

    /**
     * The rank of this leaderboard entry in the leaderboard. It is of type `int`.
     * It can be used in Leaderboard_GetEntriesAfterRank() to retrieve leaderboard entries starting from a specified rank.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LeaderboardEntry|Field")
    int32 Rank;

    /**
     * The raw underlying value of the score achieved by the user in the leaderboard.
     * It's of type `long_as_string` and it's used to determine the user's rank in the leaderboard. 
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LeaderboardEntry|Field")
    int64 Score;

    /** FOvrSupplementaryMetric is a supplemental piece of data that can be used for tiebreakers by Leaderboard_WriteEntryWithSupplementaryMetric(). */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LeaderboardEntry|Field")
    FOvrSupplementaryMetric SupplementaryMetric;

    /** The timestamp of this entry being created in the leaderboard. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LeaderboardEntry|Field")
    FDateTime Timestamp;

    /**
     * User of this leaderboard entry. It is of type FOvrUser.
     * You can request a block of leaderboard entries for the specified user ID(s) by Leaderboard_GetEntriesByIds().
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LeaderboardEntry|Field")
    FOvrUser User;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrLeaderboardEntryHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrLeaderboardEntry();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrLeaderboardEntry(ovrLeaderboardEntryHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrLeaderboardEntryHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};

/** An array of paginated leaderboard entries.  */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|LeaderboardEntryArray")
struct OVRPLATFORM_API FOvrLeaderboardEntryPages
{
    GENERATED_USTRUCT_BODY()

    /// \brief This is the default constructor for the struct, which initializes the ::ovrLeaderboardEntryArrayHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrLeaderboardEntryPages();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrLeaderboardEntryPages(ovrLeaderboardEntryArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrLeaderboardEntryArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // OVR array handle for methods
    mutable ovrLeaderboardEntryArrayHandle PagedArrayHandle;

    // Original ref-counted message to hold onto array handle
    mutable TOvrMessageHandlePtr PagedArrayMessageHandlePtr;
};

UCLASS()
/// \brief This class provides methods for accessing and manipulating the elements in a FOvrLeaderboardEntryPages paginated list. It allows you to easily retrieve and modify the elements in the list, as well as check if there is a next page of elements available.
class OVRPLATFORM_API UOvrLeaderboardEntryPagesMethods : public UObject
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|LeaderboardEntryPages")
    static FOvrLeaderboardEntry LeaderboardEntryPages_GetElement(const FOvrLeaderboardEntryPages& Model, int64 Index);

    /** The url of the next page of leaderboard entries */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|LeaderboardEntryPages")
    static FString LeaderboardEntryPages_GetNextUrl(const FOvrLeaderboardEntryPages& Model);

    /** The url of the previous leaderboard entries */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|LeaderboardEntryPages")
    static FString LeaderboardEntryPages_GetPreviousUrl(const FOvrLeaderboardEntryPages& Model);

    /** The size of this leaderboard entry array in bytes */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|LeaderboardEntryPages")
    static int64 LeaderboardEntryPages_GetSize(const FOvrLeaderboardEntryPages& Model);

    /** The total count of this leaderboard entry array, ignoring the pagination. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|LeaderboardEntryPages")
    static int64 LeaderboardEntryPages_GetTotalCount(const FOvrLeaderboardEntryPages& Model);

    /** Whether this leaderboard entry array has next page */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|LeaderboardEntryPages")
    static bool LeaderboardEntryPages_HasNextPage(const FOvrLeaderboardEntryPages& Model);

    /** Whether this leaderboard entry array has previous page */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|LeaderboardEntryPages")
    static bool LeaderboardEntryPages_HasPreviousPage(const FOvrLeaderboardEntryPages& Model);
};


/**
 * The result of sending an invite to a user or list of users shows invites were sent successfully through the resulting array.
 * This is the model returned in a successful response to the GroupPresence_SendInvites() api.
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|SendInvitesResult")
struct OVRPLATFORM_API FOvrSendInvitesResult
{
    GENERATED_USTRUCT_BODY()

    /** The list of invites that was sent through GroupPresence_SendInvites(). This invite list can comprise of friends and recently met users. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|SendInvitesResult|Field")
    FOvrApplicationInvitePages Invites;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrSendInvitesResultHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrSendInvitesResult();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrSendInvitesResult(ovrSendInvitesResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrSendInvitesResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * A UserAccountAgeCategory represents the age category of a Meta user. This object contains information
 *  about the user's age group, which can be used for various purposes such as targeted advertising or content restriction.
 *  The possible values for the age category are defined in the EOvrAccountAgeCategory.
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|UserAccountAgeCategory")
struct OVRPLATFORM_API FOvrUserAccountAgeCategory
{
    GENERATED_USTRUCT_BODY()

    /** Age category of the user in Meta account. This field represents the age group that the user falls into, and the possible values for this field are defined in the EOvrAccountAgeCategory. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|UserAccountAgeCategory|Field")
    EOvrAccountAgeCategory AgeCategory;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrUserAccountAgeCategoryHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrUserAccountAgeCategory();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrUserAccountAgeCategory(ovrUserAccountAgeCategoryHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrUserAccountAgeCategoryHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};

/** Represents a paginated list of FOvrUser elements */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|UserArray")
struct OVRPLATFORM_API FOvrUserPages
{
    GENERATED_USTRUCT_BODY()

    /// \brief This is the default constructor for the struct, which initializes the ::ovrUserArrayHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrUserPages();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrUserPages(ovrUserArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrUserArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // OVR array handle for methods
    mutable ovrUserArrayHandle PagedArrayHandle;

    // Original ref-counted message to hold onto array handle
    mutable TOvrMessageHandlePtr PagedArrayMessageHandlePtr;
};

UCLASS()
/// \brief This class provides methods for accessing and manipulating the elements in a FOvrUserPages paginated list. It allows you to easily retrieve and modify the elements in the list, as well as check if there is a next page of elements available.
class OVRPLATFORM_API UOvrUserPagesMethods : public UObject
{
    GENERATED_BODY()

public:

    /** Access the indexed element in this list. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|UserPages")
    static FOvrUser UserPages_GetElement(const FOvrUserPages& Model, int64 Index);

    /** The URL to request the next paginated list of elements. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|UserPages")
    static FString UserPages_GetNextUrl(const FOvrUserPages& Model);

    /** The number of elements contained within this list. This is not equal to the total number of elements across multiple pages. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|UserPages")
    static int64 UserPages_GetSize(const FOvrUserPages& Model);

    /** Whether there is a next page of elements that can be retrieved. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|UserPages")
    static bool UserPages_HasNextPage(const FOvrUserPages& Model);
};


/**
 * Challenges leverage FOvrDestination and Group Presence to create shareable links that allow
 * players to compete directly based on score.
 * 
 * Challenges can be ranked by highest or lowest scores within a time period. Any application
 * that uses Leaderboards gets Challenges for free. It appears in the Scoreboards UI.
 * Players can create Challenges and send invites through the Challenges app.
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|Challenge")
struct OVRPLATFORM_API FOvrChallenge
{
    GENERATED_USTRUCT_BODY()

    /**
     * An enum that specifies if this challenge was created by a user (EOvrChallengeCreationType::UserCreated)
     * or the app developer (EOvrChallengeCreationType::DeveloperCreated).
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Challenge|Field")
    EOvrChallengeCreationType CreationType;

    /** A displayable string of the challenge's description. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Challenge|Field")
    FString Description;

    /** The timestamp when this challenge ends. You can retrieve this field from the response of the challenge creation request. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Challenge|Field")
    FDateTime EndDate;

    /** The ID of the challenge. This is an unique string that the application will refer to this challenge in your app. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Challenge|Field")
    FOvrId ID;

    /** Users that are invited to this challenge. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Challenge|Field")
    FOvrUserPages InvitedUsers;

    /** The FOvrLeaderboard associated with this challenge. You can retrieve the leaderboard ID from the response of the challenge creation request. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Challenge|Field")
    FOvrLeaderboard Leaderboard;

    /** Users that have participated in this challenge. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Challenge|Field")
    FOvrUserPages Participants;

    /** The timestamp when this challenge begins. You can retrieve this field from the response of the challenge creation request. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Challenge|Field")
    FDateTime StartDate;

    /** A displayable string of the challenge's title. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Challenge|Field")
    FString Title;

    /**
     * An enum that specifies who can see and participate in this challenge.
     * 
     * EOvrChallengeVisibility::InviteOnly - Only those invited can participate in it. Everyone can see it.
     * 
     * EOvrChallengeVisibility::Public - Everyone can participate and see this challenge.
     * 
     * EOvrChallengeVisibility::Private - Only those invited can participate and see this challenge.
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Challenge|Field")
    EOvrChallengeVisibility Visibility;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrChallengeHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrChallenge();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrChallenge(ovrChallengeHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrChallengeHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};

/** A paginated array of FOvrChallenges that can be retrieved by Challenges_GetList(). */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|ChallengeArray")
struct OVRPLATFORM_API FOvrChallengePages
{
    GENERATED_USTRUCT_BODY()

    /// \brief This is the default constructor for the struct, which initializes the ::ovrChallengeArrayHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrChallengePages();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrChallengePages(ovrChallengeArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrChallengeArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // OVR array handle for methods
    mutable ovrChallengeArrayHandle PagedArrayHandle;

    // Original ref-counted message to hold onto array handle
    mutable TOvrMessageHandlePtr PagedArrayMessageHandlePtr;
};

UCLASS()
/// \brief This class provides methods for accessing and manipulating the elements in a FOvrChallengePages paginated list. It allows you to easily retrieve and modify the elements in the list, as well as check if there is a next page of elements available.
class OVRPLATFORM_API UOvrChallengePagesMethods : public UObject
{
    GENERATED_BODY()

public:

    /** The element of this challenge array. The element type is FOvrChallenge. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ChallengePages")
    static FOvrChallenge ChallengePages_GetElement(const FOvrChallengePages& Model, int64 Index);

    /** The url of the next page of challenges. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ChallengePages")
    static FString ChallengePages_GetNextUrl(const FOvrChallengePages& Model);

    /** The url of the previous page of challenges. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ChallengePages")
    static FString ChallengePages_GetPreviousUrl(const FOvrChallengePages& Model);

    /** The size of this challenge array in bytes. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ChallengePages")
    static int64 ChallengePages_GetSize(const FOvrChallengePages& Model);

    /** The total count of challenges contained in array, across all pages. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ChallengePages")
    static int64 ChallengePages_GetTotalCount(const FOvrChallengePages& Model);

    /** Whether this challenge array has a next page. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ChallengePages")
    static bool ChallengePages_HasNextPage(const FOvrChallengePages& Model);

    /** Whether this challenge array has a previous page. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|ChallengePages")
    static bool ChallengePages_HasPreviousPage(const FOvrChallengePages& Model);
};


/**
 * Details about the launch of the appplication.
 *  It can be used to check if your app is being launched using App to App Travel.
 * It can be retrieved using ApplicationLifecycle_GetLaunchDetails().
 */
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

    /**
     * A EOvrLaunchType that defines the different ways in which an application can be launched.
     * EOvrLaunchType::Normal - Normal launch from the user's library.
     * EOvrLaunchType::Invite - Launch from the user accepting an invite.
     * EOvrLaunchType::Deeplink - Launched from a deeplink. This flow is typically kicked off from Application_LaunchOtherApp()
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LaunchDetails|Field")
    EOvrLaunchType LaunchType;

    /** If provided, the intended lobby the user would like to be in */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LaunchDetails|Field")
    FString LobbySessionID;

    /** If provided, the intended session the user would like to be in */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LaunchDetails|Field")
    FString MatchSessionID;

    /** A unique identifier to keep track of a user going through the deeplinking flow */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LaunchDetails|Field")
    FString TrackingID;

    /** If provided, the intended users the user would like to be with */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LaunchDetails|Field")
    FOvrUserPages Users;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrLaunchDetailsHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrLaunchDetails();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrLaunchDetails(ovrLaunchDetailsHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrLaunchDetailsHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * Sent when the user is finished using the invite panel to send out invitations.
 * Contains a list of invitees. It can be retrieved using FOvrNotification_GroupPresence_InvitationsSent.
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|LaunchInvitePanelFlowResult")
struct OVRPLATFORM_API FOvrLaunchInvitePanelFlowResult
{
    GENERATED_USTRUCT_BODY()

    /** A list of users that were sent an invitation to the session. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|LaunchInvitePanelFlowResult|Field")
    FOvrUserPages InvitedUsers;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrLaunchInvitePanelFlowResultHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrLaunchInvitePanelFlowResult();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrLaunchInvitePanelFlowResult(ovrLaunchInvitePanelFlowResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrLaunchInvitePanelFlowResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * Parties allow users to start a voice chat with other members of the party.
 *  Party voice chats persist across apps in VR and users can continue to interact while navigating between apps. You can load a user's party by using Party_GetCurrent().
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|Party")
struct OVRPLATFORM_API FOvrParty
{
    GENERATED_USTRUCT_BODY()

    /** A unique identifier of this party. It can be used by Party_Join(), Party_Leave(), and Party_Invite(). */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Party|Field")
    FOvrId ID;

    /** An array of users who are invited to this party. These users are not a part of the party yet but have been invited. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Party|Field")
    FOvrUserPages InvitedUsers;

    /** The user who initialized this party. It's also the first user who joined the party. The leader can invite and kick other users. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Party|Field")
    FOvrUser Leader;

    /** An array that contains the users who are currently in this party. These users will remain in the party while navigating between apps. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|Party|Field")
    FOvrUserPages Users;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrPartyHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrParty();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrParty(ovrPartyHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrPartyHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/** This object represents a permission or capability for a particular user. You can fetch all the user capabilities for a logged-in FOvrUser by using User_GetUserCapabilities(). There is a unique name for every user capability. */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|UserCapability")
struct OVRPLATFORM_API FOvrUserCapability
{
    GENERATED_USTRUCT_BODY()

    /** The human readable description of the capability describing what possessing it entails for a given FOvrUser. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|UserCapability|Field")
    FString Description;

    /** Whether the capability is currently enabled for the user. When false, this field will gate the FOvrUser from the specified services. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|UserCapability|Field")
    bool IsEnabled;

    /** The unique identifier for the capability. An example capability could be "earn_achievements". */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|UserCapability|Field")
    FString Name;

    /**
     * This field specifies the reason the capability was enabled or disabled for the given FOvrUser.
     *  List of Reason Codes:
     *  - REASON_UNKOWN
     *  - SOCIAL_DISTANCING
     *  - VERBAL_ABUSE
     *  - TEXT_ABUSE
     *  - PARENTAL_CONTROL
     *  - DEVELOPER_ACTION
     *  - SALSA_RESTRICTION
     *  - SOCIAL_SUSPENSION
     *  - PAYMENT_SUSPENSION
     *  - PAYMENT_GIFTING_SUSPENSION
     */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|UserCapability|Field")
    FString ReasonCode;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrUserCapabilityHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrUserCapability();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrUserCapability(ovrUserCapabilityHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrUserCapabilityHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};

/** Represents a paginated list of FOvrUserCapability elements */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|UserCapabilityArray")
struct OVRPLATFORM_API FOvrUserCapabilityPages
{
    GENERATED_USTRUCT_BODY()

    /// \brief This is the default constructor for the struct, which initializes the ::ovrUserCapabilityArrayHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrUserCapabilityPages();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrUserCapabilityPages(ovrUserCapabilityArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrUserCapabilityArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr);

    // OVR array handle for methods
    mutable ovrUserCapabilityArrayHandle PagedArrayHandle;

    // Original ref-counted message to hold onto array handle
    mutable TOvrMessageHandlePtr PagedArrayMessageHandlePtr;
};

UCLASS()
/// \brief This class provides methods for accessing and manipulating the elements in a FOvrUserCapabilityPages paginated list. It allows you to easily retrieve and modify the elements in the list, as well as check if there is a next page of elements available.
class OVRPLATFORM_API UOvrUserCapabilityPagesMethods : public UObject
{
    GENERATED_BODY()

public:

    /** Access the indexed element in this list. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|UserCapabilityPages")
    static FOvrUserCapability UserCapabilityPages_GetElement(const FOvrUserCapabilityPages& Model, int64 Index);

    /** The URL to request the next paginated list of elements. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|UserCapabilityPages")
    static FString UserCapabilityPages_GetNextUrl(const FOvrUserCapabilityPages& Model);

    /** The number of elements contained within this list. This is not equal to the total number of elements across multiple pages. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|UserCapabilityPages")
    static int64 UserCapabilityPages_GetSize(const FOvrUserCapabilityPages& Model);

    /** Whether there is a next page of elements that can be retrieved. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Models|UserCapabilityPages")
    static bool UserCapabilityPages_HasNextPage(const FOvrUserCapabilityPages& Model);
};


/**
 * This payload contains information about the result of an update request to the user data store.
 * It includes a success field field FOvrUserDataStoreUpdateResponse::Success that indicates whether the update was successful or not.
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|UserDataStoreUpdateResponse")
struct OVRPLATFORM_API FOvrUserDataStoreUpdateResponse
{
    GENERATED_USTRUCT_BODY()

    /** Indicates whether the update request was successful or not. A value of true indicates that the update was successful, while a value of false indicates that the update failed. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|UserDataStoreUpdateResponse|Field")
    bool Success;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrUserDataStoreUpdateResponseHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrUserDataStoreUpdateResponse();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrUserDataStoreUpdateResponse(ovrUserDataStoreUpdateResponseHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrUserDataStoreUpdateResponseHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/**
 * This object is retrieved from the User_GetUserProof() request and will contain a nonce that is used to verify the identity of the User.
 * Read more about user verification in our [User Verification guide](https://developer.oculus.com/documentation/unreal/ps-ownership/#integrate-user-verification)
 * 
 * NOTE: The nonce is only good for one check and then it is invalidated.
 */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|UserProof")
struct OVRPLATFORM_API FOvrUserProof
{
    GENERATED_USTRUCT_BODY()

    /** A string that is returned from the client that is used to verify the identity of the User. The nonce can be used with the meta account to the `https://graph.oculus.com/user_nonce_validate` endpoint to verify identity. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|UserProof|Field")
    FString Nonce;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrUserProofHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrUserProof();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrUserProof(ovrUserProofHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrUserProofHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


/** \deprecated Do not add new requests using this. Use launch_report_flow_result instead.  */
USTRUCT(BlueprintType, Category = "OvrPlatform|Models|UserReportID")
struct OVRPLATFORM_API FOvrUserReportID
{
    GENERATED_USTRUCT_BODY()

    /** Whether the viewer chose to cancel the report flow. */
    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|UserReportID|Field")
    bool DidCancel;

    UPROPERTY(BlueprintReadOnly, Category = "OvrPlatform|Models|UserReportID|Field")
    FOvrId ID;

    /// \brief This is the default constructor for the struct, which initializes the ::ovrUserReportIDHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrUserReportID();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrUserReportID(ovrUserReportIDHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    void Update(ovrUserReportIDHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
};


USTRUCT(BlueprintType, Category = "OvrPlatform|Models|VoipDecoder")
struct OVRPLATFORM_API FOvrVoipDecoder
{
    GENERATED_USTRUCT_BODY()

    /// \brief This is the default constructor for the struct, which initializes the ::ovrVoipDecoderHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrVoipDecoder();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrVoipDecoder(ovrVoipDecoderHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
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

    /// \brief This is the default constructor for the struct, which initializes the ::ovrVoipEncoderHandle and ::TOvrMessageHandlePtr to their default values.
    FOvrVoipEncoder();

    /// \brief Copying values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
    FOvrVoipEncoder(ovrVoipEncoderHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

    /// \brief  Setting all values to their defaults, effectively clearing the struct.
    void Clear();

    /// \brief Updating values from an OVR handle to the array, and the originating message to prevent the handle from being freed.
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

