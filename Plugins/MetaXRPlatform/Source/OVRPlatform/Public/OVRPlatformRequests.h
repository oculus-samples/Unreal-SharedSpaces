// Copyright (c) Meta Platforms, Inc. and affiliates.

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
/// The UOvrRequestsBlueprintLibrary class provides a collection of static public member functions that can be used to
/// interact with the Oculus platform. These functions include methods for handling abuse reports, achievements, asset files,
/// challenges, cowatching, device application integrity, entitlements, group presence, in-app purchases, language packs, leaderboards,
/// media sharing, notifications, parties, and user information. See more info about Platform Solutions [here](https://developer.oculus.com/documentation/unreal/ps-platform-intro/).
class OVRPLATFORM_API UOvrRequestsBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    // ----------------------------------------------------------------------
    // AbuseReport

    /** The currently running application has indicated they want to show their in-app reporting flow or that they choose to ignore the request. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|AbuseReport")
    static void AbuseReport_ReportRequestHandled(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// Possible states that an app can respond to the platform notification that the in-app reporting flow has been requested by the user.
        EOvrReportRequestResponse Response,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
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
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The api_name of the achievement that will be adding count, which can be retrieved by {{methods.achievement_definition.get_name}}.
        FString Name,
        /// The value of count that will be added to the achievement.
        int64 Count,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrAchievementUpdate& AchievementUpdate,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /** Unlock fields of a BITFIELD achievement. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Achievements")
    static void Achievements_AddFields(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The api_name of the Bitfield achievement whose field(s) will be unlocked, which can be retrieved by {{methods.achievement_definition.get_name}}.
        FString Name,
        /// A string containing either '0' or '1' characters. Every '1' will unlock the field in the corresponding position.
        FString Fields,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrAchievementUpdate& AchievementUpdate,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /** Retrieve all achievement definitions for the app, including their name, unlock requirements, and any additional details. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Achievements")
    static void Achievements_GetAllDefinitions(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrAchievementDefinitionPages& AchievementDefinitionPages,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /** Retrieve the progress for the user on all achievements in the app. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Achievements")
    static void Achievements_GetAllProgress(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrAchievementProgressPages& AchievementProgressPages,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /** Retrieve the achievement definitions that match the specified names, including their name, unlock requirements, and any additional details. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Achievements")
    static void Achievements_GetDefinitionsByName(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The api_names of the achievements used to retrieve the definition information, which can be retrieved by {{methods.achievement_definition.get_name}}.
        TArray<FString> Names,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrAchievementDefinitionPages& AchievementDefinitionPages,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /** Retrieve the user's progress on the achievements that match the specified names. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Achievements")
    static void Achievements_GetProgressByName(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The api_names of the achievements used to retrieve the progress information, which can be retrieved by {{methods.achievement_definition.get_name}}.
        TArray<FString> Names,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrAchievementProgressPages& AchievementProgressPages,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

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
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Achievements")
    static void Achievements_Unlock(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The api_name of the achievement that will be unlocked, which can be retrieved by {{methods.achievement_definition.get_name}}.
        FString Name,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrAchievementUpdate& AchievementUpdate,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    // ----------------------------------------------------------------------
    // Application

    /**
     * Cancel an app download that is in progress.
     * It will return a result when the download is cancelled.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Application")
    static void Application_CancelAppDownload(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrAppDownloadResult& AppDownloadResult,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /** Track download progress for an app. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Application")
    static void Application_CheckAppDownloadProgress(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrAppDownloadProgressResult& AppDownloadProgressResult,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Requests version information, including the field FOvrApplicationVersion::CurrentCode and
     * field FOvrApplicationVersion::CurrentName of the currently installed app
     * and field FOvrApplicationVersion::LatestCode, field FOvrApplicationVersion::LatestName,
     * field FOvrApplicationVersion::Size and field FOvrApplicationVersion::ReleaseDate of the latest app update.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Application")
    static void Application_GetVersion(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrApplicationVersion& ApplicationVersion,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Installs the app update that was previously downloaded.
     * Once the install begins the application will exit automatically.
     * After the installation process is complete, the app will be relaunched
     * based on the options passed in.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Application")
    static void Application_InstallAppUpdateAndRelaunch(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// Additional configuration for this relaunch, which is optional. It contains 5 fields {{options.application.deeplink_message}}, {{options.application.destination_api_name}}, {{options.application.lobby_session_id}}, {{options.application.match_session_id}} and {{options.application.room_id}}.
        FOvrApplicationOptions DeeplinkOptions,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrAppDownloadResult& AppDownloadResult,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Launches a different application in the user's library. If the user
     * does not have that application installed, they will be taken to that app's
     * page in the Oculus Store
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Application")
    static void Application_LaunchOtherApp(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The unique ID of the app to be launched.
        FOvrId AppID,
        /// Additional configuration for this request, which is optional. It contains 5 fields {{options.application.deeplink_message}}, {{options.application.destination_api_name}}, {{options.application.lobby_session_id}}, {{options.application.match_session_id}} and {{options.application.room_id}}.
        FOvrApplicationOptions DeeplinkOptions,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FString& StringPayload,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Starts an app download.
     * It will return a result when the download is finished.
     * Download progress can be monitored using the UOvrRequestsBlueprintLibrary::Application_CheckAppDownloadProgress().
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Application")
    static void Application_StartAppDownload(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrAppDownloadResult& AppDownloadResult,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    // ----------------------------------------------------------------------
    // ApplicationLifecycle

    // ----------------------------------------------------------------------
    // AssetFile

    /** \deprecated Use UOvrRequestsBlueprintLibrary::AssetFile_DeleteById() */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, DeprecationMessage="Use UOvrRequestsBlueprintLibrary::AssetFile_DeleteById()", Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|AssetFile")
    static void AssetFile_Delete(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The uuid of the asset file.
        FOvrId AssetFileID,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrAssetFileDeleteResult& AssetFileDeleteResult,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Removes a previously installed asset file from the device by its ID.
     * Returns an object containing the asset ID and file name, and a success flag.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|AssetFile")
    static void AssetFile_DeleteById(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The asset file ID
        FOvrId AssetFileID,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrAssetFileDeleteResult& AssetFileDeleteResult,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Removes a previously installed asset file from the device by its name.
     * Returns an object containing the asset ID and file name, and a success flag.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|AssetFile")
    static void AssetFile_DeleteByName(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The asset file name
        FString AssetFileName,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrAssetFileDeleteResult& AssetFileDeleteResult,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /** \deprecated Use UOvrRequestsBlueprintLibrary::AssetFile_DownloadById() */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, DeprecationMessage="Use UOvrRequestsBlueprintLibrary::AssetFile_DownloadById()", Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|AssetFile")
    static void AssetFile_Download(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The uuid of the file.
        FOvrId AssetFileID,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrAssetFileDownloadResult& AssetFileDownloadResult,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Downloads an asset file by its ID on demand. Returns an object containing
     * the asset ID and filepath. Sends periodic
     * UOvrPlatformSubsystem::OnAssetFileDownloadUpdate() to track the downloads.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|AssetFile")
    static void AssetFile_DownloadById(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The asset file ID
        FOvrId AssetFileID,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrAssetFileDownloadResult& AssetFileDownloadResult,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Downloads an asset file by its name on demand. Returns an object containing
     * the asset ID and filepath. Sends periodic
     * {notifications.asset_file.download_update}} to track the downloads.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|AssetFile")
    static void AssetFile_DownloadByName(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The asset file name
        FString AssetFileName,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrAssetFileDownloadResult& AssetFileDownloadResult,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /** \deprecated Use UOvrRequestsBlueprintLibrary::AssetFile_DownloadCancelById() */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, DeprecationMessage="Use UOvrRequestsBlueprintLibrary::AssetFile_DownloadCancelById()", Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|AssetFile")
    static void AssetFile_DownloadCancel(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The uuid of the asset file.
        FOvrId AssetFileID,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrAssetFileDownloadCancelResult& AssetFileDownloadCancelResult,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Cancels a previously spawned download request for an asset file by its ID.
     * Returns an object containing the asset ID and file path, and a success flag.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|AssetFile")
    static void AssetFile_DownloadCancelById(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The asset file ID
        FOvrId AssetFileID,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrAssetFileDownloadCancelResult& AssetFileDownloadCancelResult,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Cancels a previously spawned download request for an asset file by its name.
     * Returns an object containing the asset ID and file path, and a success flag.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|AssetFile")
    static void AssetFile_DownloadCancelByName(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The asset file name
        FString AssetFileName,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrAssetFileDownloadCancelResult& AssetFileDownloadCancelResult,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Returns an array of asset details with asset file names and their associated IDs field FOvrAssetDetails::AssetId,
     * and whether it's currently installed field FOvrAssetDetails::DownloadStatus.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|AssetFile")
    static void AssetFile_GetList(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        TArray<FOvrAssetDetails>& AssetDetailsArray,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /** \deprecated Use UOvrRequestsBlueprintLibrary::AssetFile_StatusById() */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, DeprecationMessage="Use UOvrRequestsBlueprintLibrary::AssetFile_StatusById()", Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|AssetFile")
    static void AssetFile_Status(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The uuid of the asset file.
        FOvrId AssetFileID,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrAssetDetails& AssetDetails,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /** Returns the details FOvrAssetDetails on a single asset: ID, file name, and whether it's currently installed */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|AssetFile")
    static void AssetFile_StatusById(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The asset file ID
        FOvrId AssetFileID,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrAssetDetails& AssetDetails,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /** Returns the details FOvrAssetDetails on a single asset: ID, file name, and whether it's currently installed */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|AssetFile")
    static void AssetFile_StatusByName(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The asset file name
        FString AssetFileName,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrAssetDetails& AssetDetails,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    // ----------------------------------------------------------------------
    // Avatar

    /**
     * Launches the Avatar Editor. Meta Avatars Editor is a feature that allows users to edit their Meta Avatars appearances within the VR application
     * that they are currently using. This experience is often used by users to switch their outfit and accessories to better suit the VR experience they are experiencing.
     * The result can be retrieved by field FOvrAvatarEditorResult::RequestSent.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Avatar")
    static void Avatar_LaunchAvatarEditor(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// A {{options.avatar_editor.create}} contains the options information, including an optional override for the source of the request, which is specified by {{options.avatar_editor.source_override}}.
        FOvrAvatarEditorOptions Options,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrAvatarEditorResult& AvatarEditorResult,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    // ----------------------------------------------------------------------
    // Challenges

    /** \deprecated Use server-to-server API call instead. */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, DeprecationMessage="Use server-to-server API call instead.", Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Challenges")
    static void Challenges_Create(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// A string represents the name of the leaderboard.
        FString LeaderboardName,
        /// This indicates the options of the challenge and it can be retrieved by {{options.challenge.create}}.
        FOvrChallengeOptions ChallengeOptions,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrChallenge& Challenge,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * If the current user has the necessary permissions, they can decline a challenge by providing the challenge ID,
     * which can be obtained using field FOvrChallenge::ID.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Challenges")
    static void Challenges_DeclineInvite(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The ID of challenge that the user is going to decline. It can be retrieved by {{methods.challenge.get_id}}.
        FOvrId ChallengeID,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrChallenge& Challenge,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /** \deprecated Use server-to-server API call instead. */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, DeprecationMessage="Use server-to-server API call instead.", Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Challenges")
    static void Challenges_Delete(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The uuid of the challenge.
        FOvrId ChallengeID,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /** Gets detailed information for a single challenge by providing the challenge ID, which can be retrieved by calling field FOvrChallenge::ID. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Challenges")
    static void Challenges_Get(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The id of the challenge whose entries to return, which can be retrieved by calling {{methods.challenge.get_id}}.
        FOvrId ChallengeID,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrChallenge& Challenge,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Retrieves a list of entries for a specific challenge, with options to filter and limit the results. By providing the challengeID,
     * you can specify which challenge's entries you want to retrieve. The limit parameter allows you to control the number of entries returned.
     * The filter parameter enables you to refine the results to only include entries from users who are bidirectional followers.
     * The startAt parameter allows you to define whether to center the query on the user or start at the top of the challenge.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Challenges")
    static void Challenges_GetEntries(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The id of the challenge whose entries to return, which can be retrieved by calling {{methods.challenge.get_id}}.
        FOvrId ChallengeID,
        /// Sets a limit on the maximum number of challenges to be fetched, which can be useful for pagination or performance reasons.
        int32 Limit,
        /// By using the {{enums.leaderboard_filter_type}}, you can refine the results to only include entries from users who are bidirectional followers.
        EOvrLeaderboardFilterType Filter,
        /// Defines whether to center the query on the user or start at the top of the challenge. If this is {{enum_members.leaderboard_start_at.centered_on_viewer}} or {{enum_members.leaderboard_start_at.centered_on_viewer_or_top}}, then the current user's ID will be automatically added to the query.
        EOvrLeaderboardStartAt StartAt,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrChallengeEntryPages& ChallengeEntryPages,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Returns a list of entries for a specific challenge, starting from a specified rank.
     * By providing the challengeID and rank, you can specify which challenge's entries you want to retrieve and where to start the query.
     * The limit parameter allows you to control the number of entries returned.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Challenges")
    static void Challenges_GetEntriesAfterRank(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The id of the challenge whose entries to return, which can be retrieved by calling {{methods.challenge.get_id}}.
        FOvrId ChallengeID,
        /// Sets a limit on the maximum number of challenges to be fetched, which can be useful for pagination or performance reasons.
        int32 Limit,
        /// The position after which to start. For example, 10 returns challenge results starting with the 11th user.
        int64 AfterRank,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrChallengeEntryPages& ChallengeEntryPages,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Retrieves a list of challenge entries for a specific set of user IDs, with options to filter and limit the results.
     * This method is useful for retrieving a list of challenge entries for a specific set of users, allowing you to display their progress and rankings within the challenge.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Challenges")
    static void Challenges_GetEntriesByIds(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The id of the challenge whose entries to return, which can be retrieved by calling {{methods.challenge.get_id}}.
        FOvrId ChallengeID,
        /// Sets a limit on the maximum number of challenges to be fetched, which can be useful for pagination or performance reasons.
        int32 Limit,
        /// Defines whether to center the query on the user or start at the top of the challenge. If this is {{enum_members.leaderboard_start_at.centered_on_viewer}} or {{enum_members.leaderboard_start_at.centered_on_viewer_or_top}}, then the current user's ID will be automatically added to the query.
        EOvrLeaderboardStartAt StartAt,
        /// Defines a list of user ids to get entries for.
        TArray<FOvrId> UserIDs,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrChallengeEntryPages& ChallengeEntryPages,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Returns a list of challenges that match the specified options. The FOvrChallengeOptions parameter allows you to specify
     * the criteria for the challenges you want to retrieve. The limit parameter allows you to control the number of challenges returned.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Challenges")
    static void Challenges_GetList(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// This indicates the options of the challenge and it can be retrieved by {{options.challenge.create}}.
        FOvrChallengeOptions ChallengeOptions,
        /// Sets a limit on the maximum number of challenges to be fetched, which can be useful for pagination or performance reasons.
        int32 Limit,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrChallengePages& ChallengePages,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * If the current user has the necessary permissions to join, participate in a challenge by providing the challenge ID,
     * which can be retrieved using field FOvrChallenge::ID.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Challenges")
    static void Challenges_Join(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The ID of challenge that the user is going to join. It can be retrieved by {{methods.challenge.get_id}}.
        FOvrId ChallengeID,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrChallenge& Challenge,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * If the current user has the necessary permissions, they can leave a challenge by providing the challenge ID,
     * which can be obtained using field FOvrChallenge::ID.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Challenges")
    static void Challenges_Leave(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The ID of challenge that the user is going to leave. It can be retrieved by {{methods.challenge.get_id}}.
        FOvrId ChallengeID,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrChallenge& Challenge,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /** \deprecated Use server-to-server API call instead. */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, DeprecationMessage="Use server-to-server API call instead.", Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Challenges")
    static void Challenges_UpdateInfo(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The uuid of the challenge.
        FOvrId ChallengeID,
        /// This indicates the options of the challenge and it can be retrieved by {{options.challenge.create}}.
        FOvrChallengeOptions ChallengeOptions,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrChallenge& Challenge,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    // ----------------------------------------------------------------------
    // Cowatching

    /**
     * Retrieve the presenter data that drives an active cowatching session.
     * This method can be called when there is an ongoing cowatching session,
     * allowing developers to access and utilize the presenter data to enhance the user experience.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Cowatching")
    static void Cowatching_GetPresenterData(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FString& StringPayload,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Retrieve the viewer data of everyone who is in a cowatching session whose data was set by UOvrRequestsBlueprintLibrary::Cowatching_SetViewerData() ViewerData.
     * This can be called when there is an active cowatching session.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Cowatching")
    static void Cowatching_GetViewersData(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrCowatchViewerPages& CowatchViewerPages,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Check whether the current user is participating in the ongoing cowatching session.
     * It returns a boolean value field FOvrCowatchingState::InSession indicating the user's presence in the session.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Cowatching")
    static void Cowatching_IsInSession(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrCowatchingState& CowatchingState,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /** Join the ongoing cowatching session as a viewer, updating data only possible for users already in the session. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Cowatching")
    static void Cowatching_JoinSession(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /** Launch a dialog for inviting users to cowatch in Copresent Home. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Cowatching")
    static void Cowatching_LaunchInviteDialog(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /** Leave the current cowatching session, rendering viewer data obsolete and no longer relevant to the ongoing experience. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Cowatching")
    static void Cowatching_LeaveSession(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /** Request to initiate a cowatching session as the presenter while being copresent in a shared virtual home environment. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Cowatching")
    static void Cowatching_RequestToPresent(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /** Stop being the presenter and terminate the ongoing cowatching session. This action will effectively end the shared media experience. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Cowatching")
    static void Cowatching_ResignFromPresenting(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Set the data that drives a cowatching session. This method is only callable by the presenter.
     * The video title cannot exceed 100 characters, and the data size is limited to 500 characters.
     * The data will be eventually consistent across all users.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Cowatching")
    static void Cowatching_SetPresenterData(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// A string representing the title of the video being played in the cowatching session. This parameter must not exceed 100 characters in length.
        FString VideoTitle,
        /// A string containing data that drives the cowatching session, such as video metadata or playback information. This parameter is limited to 500 characters in length and will be eventually consistent across all users participating in the session.
        FString PresenterData,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Set the current user's viewer data to be shared with copresent users. This can be called when there is an active cowatching session.
     * The data size is limited to 500 characters, and it will eventually become consistent across all users.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Cowatching")
    static void Cowatching_SetViewerData(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// A string containing data about the current user's viewer state, such as their preferences or settings. This data is shared with copresent users during an active cowatching session and is limited to 500 characters in size. The data will eventually become consistent across all users participating in the session.
        FString ViewerData,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    // ----------------------------------------------------------------------
    // DeviceApplicationIntegrity

    /**
     * Returns Device and Application Integrity Attestation JSON Web Token.
     * The token has format of header.claims.signature encoded in base64.
     * Header contains algorithm type (PS256) and token type (JWT).
     * See more details [here](https://developer.oculus.com/documentation/unreal/ps-attestation-api/#how-does-this-work).
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|DeviceApplicationIntegrity")
    static void DeviceApplicationIntegrity_GetIntegrityToken(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// A string that represents a nonce value used to generate the attestation token, ensuring uniqueness and security.
        FString ChallengeNonce,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FString& StringPayload,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    // ----------------------------------------------------------------------
    // Entitlement

    /**
     * Returns whether the current user is entitled to the current app. The primary purpose of this function is to verify
     * user access rights to the application, ensuring that the user is authorized to use it.
     * See example usage [here](https://developer.oculus.com/documentation/unreal/ps-entitlement-check/#entitlement).
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Entitlement")
    static void Entitlement_GetIsViewerEntitled(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    // ----------------------------------------------------------------------
    // GroupPresence

    /**
     * Clears the current group presence settings for your app. Use this when a user’s group presence setting in your app
     * needs to be changed when moving to new destinations in your app.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|GroupPresence")
    static void GroupPresence_Clear(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /** Returns a list of users that can be invited to your current lobby. These are pulled from your bidirectional followers and recently met lists. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|GroupPresence")
    static void GroupPresence_GetInvitableUsers(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// It contains two methods. 1. {{options.invite.suggested_users}} - Takes the userID as a parameter and adds it to the inevitable users list. 2. {{options_clear.invite.suggested_users}} - Clears the inevitable users list.
        FOvrInviteOptions Options,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrUserPages& UserPages,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /** Get the application invites which have been sent by the user. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|GroupPresence")
    static void GroupPresence_GetSentInvites(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrApplicationInvitePages& ApplicationInvitePages,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Launches the system invite dialog with a roster of eligible users for the current user to invite to the app.
     * It is recommended that you surface a button in your UI that triggers this dialog when a user is joinable.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|GroupPresence")
    static void GroupPresence_LaunchInvitePanel(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// It contains two methods. 1. {{options.invite.suggested_users}} - Takes the userID as a parameter and adds it to the inevitable users list. 2. {{options_clear.invite.suggested_users}} - Clears the inevitable users list.
        FOvrInviteOptions Options,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrInvitePanelResultInfo& InvitePanelResultInfo,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Launch an error dialog window with predefined messages for commonly occurring multiplayer errors.
     * Check the Invokable Error Dialogs documentation for more information about these error messages and their values.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|GroupPresence")
    static void GroupPresence_LaunchMultiplayerErrorDialog(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// It contains a {{options.multiplayer_error.error_key}} associated with the predefined error message to be shown to users.
        FOvrMultiplayerErrorOptions Options,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Launch the dialog allowing users to rejoin a previous lobby or match.
     * Either the user’s FOvrGroupPresenceOptions::LobbySessionId, their FOvrGroupPresenceOptions::MatchSessionId,
     * or both must be populated as valid rejoinable destinations.
     * Check the Rejoin documentation for use cases and information on this feature.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|GroupPresence")
    static void GroupPresence_LaunchRejoinDialog(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The unique identifier of the lobby session to rejoin.
        FString LobbySessionId,
        /// The unique identifier of the match session to rejoin.
        FString MatchSessionId,
        /// The unique name of the in-app destination to rejoin.
        FString DestinationApiName,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrRejoinDialogResult& RejoinDialogResult,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Launch the panel displaying the current users in the roster. We do not recommend using this API
     * because the list current users is surfaced in the Destination UI when the Meta Quest button is pressed.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|GroupPresence")
    static void GroupPresence_LaunchRosterPanel(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// It contains 2 methods. 1. {{options.roster.suggested_users}} - it takes userID as a parameter and adds it to the inevitable users list. 2. {{options_clear.roster.suggested_users}} - it clears the inevitable users list.
        FOvrRosterOptions Options,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Sends invites to the current application to the list of userIDs passed in.
     * You can fetch a list of users to pass in via the UOvrRequestsBlueprintLibrary::GroupPresence_GetInvitableUsers().
     * This API works as an alternative to UOvrRequestsBlueprintLibrary::GroupPresence_LaunchInvitePanel()
     * which delegates the invite flow to the system invite module.
     * UOvrRequestsBlueprintLibrary::GroupPresence_LaunchInvitePanel() is the recommended approach.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|GroupPresence")
    static void GroupPresence_SendInvites(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// userIDs is a list of users’ ids to send invites to.
        TArray<FOvrId> UserIDs,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrSendInvitesResult& SendInvitesResult,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Sets group presence information for your current app. It is recommended that you use this parameter and
     * its methods to set group presence information for your app. An example of using this parameter can be found
     * on the Group Presence overview page where the methods to set FOvrGroupPresenceOptions::DestinationApiName, FOvrGroupPresenceOptions::MatchSessionId,
     * and FOvrGroupPresenceOptions::LobbySessionId are used.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|GroupPresence")
    static void GroupPresence_Set(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The groupPresenceOptions parameter contains five methods. 1. {{options.group_presence.deeplink_message_override}} - Use {{options.group_presence.lobby_session_id}} or {{options.group_presence.match_session_id}} to specify the session. Use the {{options.group_presence.deeplink_message_override}} for any additional data in whatever format you wish to aid in bringing users together. If not specified, the deeplink_message for the user will default to the one on the destination. 2.{{options.group_presence.destination_api_name}} - This the unique API Name that refers to an in-app destination. 3.{{options.group_presence.is_joinable}} - Set whether or not the person is shown as joinable or not to others. A user that is joinable can invite others to join them. Set this to false if other users would not be able to join this user. For example, the current session is full, or only the host can invite others and the current user is not the host. 4.{{options.group_presence.lobby_session_id}} - This is a session that represents a closer group/squad/party of users. It is expected that all users with the same lobby session id can see or hear each other. Users with the same lobby session id in their group presence will show up in the roster and will show up as "Recently Played With" for future invites if they aren't already Oculus friends. This must be set in addition to {{options.group_presence.is_joinable}} being true for a user to use invites. 5.{{options.group_presence.match_session_id}} - This is a session that represents all the users that are playing a specific instance of a map, game mode, round, etc. This can include users from multiple different lobbies that joined together and the users may or may not remain together after the match is over. Users with the same match session id in their group presence will not show up in the Roster, but will show up as "Recently Played with" for future invites.
        FOvrGroupPresenceOptions GroupPresenceOptions,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Sets the user's FOvrGroupPresenceOptions::DeeplinkMessageOverride while keeping the other group presence parameters the same.
     * If the destination of the user is not set, the deeplink message cannot be set as there's no deeplink message to override.
     * This method does not power travel from the Meta Quest platform to your app.
     * You must set a user’s FOvrGroupPresenceOptions::DestinationApiName, FOvrGroupPresenceOptions::IsJoinable status,
     * and FOvrGroupPresenceOptions::LobbySessionId to enable travel to your app. Check Group Presence overview for more information about these values.
     * Note: Instead of using this standalone API, we recommend setting all GroupPresence parameters in one call to UOvrRequestsBlueprintLibrary::GroupPresence_Set().
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|GroupPresence")
    static void GroupPresence_SetDeeplinkMessageOverride(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// deeplink_message is the new {{options.group_presence.deeplink_message_override}} to set for the user, overriding the current deeplink message.
        FString DeeplinkMessage,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Replaces the user's current FOvrGroupPresenceOptions::DestinationApiName with the provided one. Use this to set a user's current destination
     * while keeping all the other Group Presence parameters the same. Setting a user's destination is required to enable travel from the Meta Quest Platform
     * to your app. NOTE instead of using the standalone API, we recommend setting all GroupPresence parameters in one call to UOvrRequestsBlueprintLibrary::GroupPresence_Set().
     * This helps ensure that all relevant presence information is singularly updated and helps reduce presence errors.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|GroupPresence")
    static void GroupPresence_SetDestination(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// api_name is the unique name of the in-app desination to set, replacing the user's current {{options.group_presence.destination_api_name}}.
        FString ApiName,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Sets a user’s current presence as joinable. Use this method to update a user’s joinability as it changes.
     * For example, when the game starts, the lobby becomes full, the user moves to a private,
     * non joinable instance while keeping all other GroupPresence parameters
     * (i.e  FOvrGroupPresenceOptions::DestinationApiName, FOvrGroupPresenceOptions::LobbySessionId,
     * FOvrGroupPresenceOptions::MatchSessionId) the same.
     * Setting a user’s destination is required to enable travel from the Meta Quest Platform to your app.
     * Note: Instead of using this individual API, we recommend setting all GroupPresence information with the UOvrRequestsBlueprintLibrary::GroupPresence_Set()
     * method and its associated parameters to simply managing all presence information.
     * This helps ensure that all relevant presence information is singularly updated and helps reduce presence errors.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|GroupPresence")
    static void GroupPresence_SetIsJoinable(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// If {{options.group_presence.is_joinable}} is true, the user can invite others to join them. If false, other users cannot join this user, for example, if the current session is full or only the host can invite others and the current user is not the host.
        bool IsJoinable,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Replaces the user's current FOvrGroupPresenceOptions::LobbySessionId for the provided string. Use this to set a user's current
     * lobby session id while keeping all other GroupPresence parameters the same. Setting a user's lobby session id is required to enable travel
     * from the Meta Quest Platform to your app. Check Group presence overview for more information. NOTE instead of using the standalone API,
     * we recommend setting all GroupPresence parameters in one call to UOvrRequestsBlueprintLibrary::GroupPresence_Set(). This helps ensure that all relevant presence
     * information is singularly updated and helps reduce presence errors.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|GroupPresence")
    static void GroupPresence_SetLobbySession(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// id is the unique identifier of the lobby session to set, replacing the user's current {{options.group_presence.lobby_session_id}}.
        FString Id,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Replaces the user's current FOvrGroupPresenceOptions::MatchSessionId for the provided one. Use this to update the user's current match session
     * id while keeping all other GroupPresence parameters the same. FOvrGroupPresenceOptions::MatchSessionId works in conjuction with
     * FOvrGroupPresenceOptions::LobbySessionId to determine if users are playing together. If a user's match and lobby session ids are the same,
     * they should be in the same multiplayer instance together. Users with the same lobby session id but different match session ids may be
     * in the same lobby for things like voice chat while in different instances in your app. WARNING match session id is often treated the same as
     * lobby session id, but this is in fact a distinct parameter and is not used for travel from the Meta Quest Platform. NOTE instead of using the standalone API,
     * we recommend setting all GroupPresence parameters in one call to UOvrRequestsBlueprintLibrary::GroupPresence_Set().
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|GroupPresence")
    static void GroupPresence_SetMatchSession(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// id is the unique identifier of the match session to set, replacing the user's current {{options.group_presence.match_session_id}}.
        FString Id,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    // ----------------------------------------------------------------------
    // IAP

    /**
     * Allow the consumable IAP product to be purchased again. Conceptually, this
     * indicates that the item was used or consumed. Important: Make sure to pass the
     * correct SKU of the purchase that will be consumed. This value is case-sensitive
     * and should match exactly with the product SKU set in the Developer Dashboard.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|IAP")
    static void IAP_ConsumePurchase(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The SKU of the product of the purchase that will be consumed. This value is case-sensitive and should match exactly with the product SKU set in the Developer Dashboard.
        FString Sku,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Retrieve a list of IAP products that can be purchased. Note: You must provide a list of SKUs (Stock Keeping Units)
     * to retrieve the corresponding product information. The SKUs are used to identify the products in the Oculus store,
     * which can be retrieved by accessing the Developer Dashboard or by field FOvrPurchase::SKU.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|IAP")
    static void IAP_GetProductsBySKU(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// An array of SKUs of the products to retrieve. Each SKU should be a string value that matches exactly with the product SKU set in the Oculus Developer Dashboard.
        TArray<FString> Skus,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrProductPages& ProductPages,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Retrieve a list of Purchase that the Logged-In-User has made. This list will
     * also contain consumable purchases that have not been consumed. Note: This method returns all purchases,
     * including consumable and non-consumable ones. If you only want to retrieve durable purchases,
     * use get_viewer_purchases_durable_cache instead.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|IAP")
    static void IAP_GetViewerPurchases(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrPurchasePages& PurchasePages,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Retrieve a list of Purchase that the Logged-In-User has made. This list will only contain
     * durable purchase (non-consumable) and is populated from a device cache. Important: It is recommended
     * to use UOvrRequestsBlueprintLibrary::IAP_GetViewerPurchases() first and only check the cache if that fails. This method is intended
     * as a fallback mechanism and may not always return up-to-date results.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|IAP")
    static void IAP_GetViewerPurchasesDurableCache(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrPurchasePages& PurchasePages,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Launch the checkout flow to purchase the existing product. Oculus Home tries
     * handle and fix as many errors as possible. Home returns the appropriate error
     * message and how to resolve it, if possible. Returns a purchase on success, and
     * an error on user cancellation or other errors.
     * 
     * In the case of a user cancelation, the field FOvrError::Message value will contain
     * a JSON object with a `"category"` property containing a value of `"user_canceled"`.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|IAP")
    static void IAP_LaunchCheckoutFlow(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// IAP sku for the item the user wishes to purchase.
        FString Sku,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrPurchase& Purchase,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    // ----------------------------------------------------------------------
    // LanguagePack

    /**
     * Returns currently installed and selected language pack for an app in the
     * view of the FOvrAssetDetails. Use field FOvrAssetDetails::Language field to extract needed
     * language info.
     * A particular language can be download and installed by a user from
     * the Oculus app on the application page.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|LanguagePack")
    static void LanguagePack_GetCurrent(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrAssetDetails& AssetDetails,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Sets the current language to specified. The parameter is the BCP47 language tag.
     * If a language pack is not downloaded yet, spawns automatically the
     * UOvrRequestsBlueprintLibrary::AssetFile_DownloadByName() request, and sends periodic
     * UOvrPlatformSubsystem::OnAssetFileDownloadUpdate() to track the downloads.
     * Once the language asset file is downloaded, call UOvrRequestsBlueprintLibrary::LanguagePack_GetCurrent()
     * to retrieve the data, and use the language at runtime.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|LanguagePack")
    static void LanguagePack_SetCurrent(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The BCP47 language tag that identifies the language to be set as the current language.
        FString Tag,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrAssetFileDownloadResult& AssetFileDownloadResult,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    // ----------------------------------------------------------------------
    // Leaderboard

    /** Retrieves detailed information for a single leaderboard with a specified name, returning an array of FOvrLeaderboard. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Leaderboard")
    static void Leaderboard_Get(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The name of the leaderboard to retrieve.
        FString LeaderboardName,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrLeaderboardPages& LeaderboardPages,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /** Retrieves a list of leaderboard entries for a specified LeaderboardName, with options to filter and limit the number of results returned. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Leaderboard")
    static void Leaderboard_GetEntries(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The name of the leaderboard from which to retrieve entries.
        FString LeaderboardName,
        /// Specifies the maximum number of entries to be returned.
        int32 Limit,
        /// By using ovrLeaderboard_FilterFriends, this allows you to filter the returned values to bidirectional followers.
        EOvrLeaderboardFilterType Filter,
        /// Defines whether to center the query on the user or start at the top of the leaderboard.
        EOvrLeaderboardStartAt StartAt,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrLeaderboardEntryPages& LeaderboardEntryPages,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /** Retrieves a block of leaderboard entries starting from a specific rank. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Leaderboard")
    static void Leaderboard_GetEntriesAfterRank(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The name of the leaderboard from which to retrieve entries.
        FString LeaderboardName,
        /// The maximum number of entries to return.
        int32 Limit,
        /// The position after which to start.  For example, 10 returns leaderboard results starting with the 11th user.
        int64 AfterRank,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrLeaderboardEntryPages& LeaderboardEntryPages,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /** Retrieves a block of leaderboard entries that match the specified user IDs. Only entries corresponding to the provided user IDs will be returned. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Leaderboard")
    static void Leaderboard_GetEntriesByIds(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The name of the leaderboard from which to retrieve entries.
        FString LeaderboardName,
        /// The maximum number of entries to return.
        int32 Limit,
        /// Defines whether to center the query on the user or start at the top of the leaderboard. If this is {{enum_members.leaderboard_start_at.centered_on_viewer}} or {{enum_members.leaderboard_start_at.centered_on_viewer_or_top}}, then the current user's ID will be automatically added to the query.
        EOvrLeaderboardStartAt StartAt,
        /// Defines a list of user ids to get entries for.
        TArray<FOvrId> UserIDs,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrLeaderboardEntryPages& LeaderboardEntryPages,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /** Writes a single entry to the leaderboard, returning FOvrLeaderboardUpdateStatus indicating whether the update was successful and providing the updated challenge IDs. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Leaderboard")
    static void Leaderboard_WriteEntry(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The name of the leaderboard to which the entry should be written.
        FString LeaderboardName,
        /// The score to be written in the leaderboard.
        int64 Score,
        /// A 2KB custom data field that is associated with the leaderboard entry. This can be a game replay or any additional information that provides more context about the entry for the viewer.
        TArray<uint8> ExtraData,
        /// If true, the score always updates.  This happens even if it is not the user's best score.
        bool ForceUpdate,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrLeaderboardUpdateStatus& LeaderboardUpdateStatus,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /** Writes a single entry to a leaderboard which can include supplementary metrics, returning FOvrLeaderboardUpdateStatus indicating whether the update was successful and providing the updated challenge IDs. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Leaderboard")
    static void Leaderboard_WriteEntryWithSupplementaryMetric(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The name of the leaderboard to which the entry should be written.
        FString LeaderboardName,
        /// The score to be written in the leaderboard.
        int64 Score,
        /// Supplemental piece of data that can be used for tiebreakers.
        int64 SupplementaryMetric,
        /// A 2KB custom data field that is associated with the leaderboard entry. This can be a game replay or any additional information that provides more context about the entry for the viewer.
        TArray<uint8> ExtraData,
        /// If true, the score always updates. This happens even if it is not the user's best score.
        bool ForceUpdate,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrLeaderboardUpdateStatus& LeaderboardUpdateStatus,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

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
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Media")
    static void Media_ShareToFacebook(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// this text will prepopulate the facebook status text-input box within the share modal
        FString PostTextSuggestion,
        /// path to the file to be shared to facebook
        FString FilePath,
        /// content type of the media to be shared
        EOvrMediaContentType ContentType,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrShareMediaResult& ShareMediaResult,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    // ----------------------------------------------------------------------
    // Notification

    /**
     * Marks a notification as read, causing it to disappear from various surfaces such as the Universal Menu and in-app retrieval.
     * This action is useful for indicating that the user has acknowledged or acted upon the notification.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Notification")
    static void Notification_MarkAsRead(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The unique identifier (UUID) of the notification to be marked as read.
        FOvrId NotificationID,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    // ----------------------------------------------------------------------
    // Party

    /** Load the current party the current FOvrUser is in. The returned FOvrParty will then contain information about other users in the party and invited users. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Party")
    static void Party_GetCurrent(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrParty& Party,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    // ----------------------------------------------------------------------
    // RichPresence

    /** \deprecated Use UOvrRequestsBlueprintLibrary::GroupPresence_Clear() */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, DeprecationMessage="Use UOvrRequestsBlueprintLibrary::GroupPresence_Clear()", Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|RichPresence")
    static void RichPresence_Clear(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /** Gets all the FOvrDestination that the presence can be set to */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|RichPresence")
    static void RichPresence_GetDestinations(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrDestinationPages& DestinationPages,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /** \deprecated Use UOvrRequestsBlueprintLibrary::GroupPresence_Set(). */
    UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, DeprecationMessage="Use UOvrRequestsBlueprintLibrary::GroupPresence_Set().", Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|RichPresence")
    static void RichPresence_Set(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The options of the rich presence.
        FOvrRichPresenceOptions RichPresenceOptions,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    // ----------------------------------------------------------------------
    // User

    /**
     * Retrieve the user with the given ID. This might fail if the ID is invalid
     * or the user is blocked.
     * 
     * NOTE: Users will have a unique ID per application.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|User")
    static void User_Get(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// User ID retrieved with this application.
        FOvrId UserID,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrUser& User,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /** Return an access token string for this user, suitable for making REST calls against graph.oculus.com. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|User")
    static void User_GetAccessToken(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FString& StringPayload,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /** Return the IDs of users entitled to use the current app that are blocked by the specified user */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|User")
    static void User_GetBlockedUsers(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrBlockedUserPages& BlockedUserPages,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
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
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrUser& User,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /** Retrieve a list of the logged in user's bidirectional followers. The payload type will be an array of FOvrUser  */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|User")
    static void User_GetLoggedInUserFriends(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrUserPages& UserPages,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Retrieve the currently signed in user's managed info.  This call is not available offline.
     * 
     * NOTE: This will return data only if the logged in user is a managed Meta account (MMA).
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|User")
    static void User_GetLoggedInUserManagedInfo(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrUser& User,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * returns an ovrID which is unique per org. allows different apps within the same
     * org to identify the user. 
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|User")
    static void User_GetOrgScopedID(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The id of the user that we are going to get its org scoped ID {{models.org_scoped_id}}.
        FOvrId UserID,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrOrgScopedID& OrgScopedID,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Returns all accounts belonging to this user.
     * Accounts are the Oculus user and x-users that are linked to this user.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|User")
    static void User_GetSdkAccounts(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        TArray<FOvrSdkAccount>& SdkAccountArray,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Part of the scheme to confirm the identity of a particular user in your backend.
     * You can pass the result of UOvrRequestsBlueprintLibrary::User_GetUserProof() and a user ID from
     * field FOvrUser::ID to your backend. Your server can then use our api
     * to verify identity.
     * 'https://graph.oculus.com/user_nonce_validate?nonce=USER_PROOF&amp;user_id=USER_ID&amp;access_token=ACCESS_TOKEN'
     * 
     * 
     * NOTE: The nonce is only good for one check and then it is invalidated.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|User")
    static void User_GetUserProof(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrUserProof& UserProof,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Launch the flow for blocking the given user. You can't follow, be followed, invited,
     *  or searched by a blocked user, for example. You can remove the block via
     *  ovr_User_LaunchUnblockFlow.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|User")
    static void User_LaunchBlockFlow(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The ID of the user that the viewer is going to launch the block flow request.
        FOvrId UserID,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrLaunchBlockFlowResult& LaunchBlockFlowResult,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /** Launch the flow for sending a follow request to a user. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|User")
    static void User_LaunchFriendRequestFlow(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The ID of the target user that is going to send the friend follow request to.
        FOvrId UserID,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrLaunchFriendRequestFlowResult& LaunchFriendRequestFlowResult,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /** Launch the flow for unblocking a user that the viewer has blocked. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|User")
    static void User_LaunchUnblockFlow(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// The ID of the user that the viewer is going to launch the unblock flow request.
        FOvrId UserID,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrLaunchUnblockFlowResult& LaunchUnblockFlowResult,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    // ----------------------------------------------------------------------
    // UserAgeCategory

    /** Retrieve the user age category for the current user. It can be used in field FOvrUserAccountAgeCategory::AgeCategory */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|UserAgeCategory")
    static void UserAgeCategory_Get(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrUserAccountAgeCategory& UserAccountAgeCategory,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /** Report the current user's age category to Meta. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|UserAgeCategory")
    static void UserAgeCategory_Report(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// Age category for developers to send to Meta. There are two members, children age group ({{enum_members.app_age_category.ch}}) and non-children age group ({{enum_members.app_age_category.nch}}).
        EOvrAppAgeCategory AgeCategory,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    // ----------------------------------------------------------------------
    // Voip

    /** Gets whether the microphone is currently available to the app. This can be used to show if the user's voice is able to be heard by other users. Returns a microphone availability state flag which determines whether it is available or not - FOvrMicrophoneAvailabilityState. */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Voip")
    static void Voip_GetMicrophoneAvailability(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrMicrophoneAvailabilityState& MicrophoneAvailabilityState,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

    /**
     * Sets whether SystemVoip should be suppressed so that this app's Voip can use the microphone and play incoming Voip audio. Once microphone switching functionality for the user is released, this function will no longer work. You can use UOvrRequestsBlueprintLibrary::Voip_GetMicrophoneAvailability() to see if the user has allowed the app access to the microphone.
     * This returns a FOvrSystemVoipState object which contains statuses about whether the microphone is muted or whether passthrough is enabled.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "OutExecs"), Category = "OvrPlatform|Voip")
    static void Voip_SetSystemVoipSuppressed(
        /// Word context
        UObject* WorldContextObject,
        /// Reference to an array of output pins that will be executed as a result of this request.
        EOvrRequestOutputPins& OutExecs,
        /// Information about the latent action that will be performed as a result of this request.
        FLatentActionInfo LatentInfo,
        /// A boolean indicates if the voip is supressed or not.
        bool Suppressed,
        /// Represents the payload of the request, if the request succeeded. These results can be used to provide more context and information about the outcome of the request.
        FOvrSystemVoipState& SystemVoipState,
        /// Error message if the request failed, which contains failure reason, it is empty if the request succeeded.
        FString& ErrorMsg);

};
