// Copyright (c) Meta Platforms, Inc. and affiliates.

// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#pragma once

#include "CoreMinimal.h"

#include "OVRPlatformModels.h"
#include "OVRPlatformOptions.h"
#include "OVRPlatformRequestsSupport.h"

// ----------------------------------------------------------------------
// AbuseReport

DECLARE_DELEGATE_TwoParams(OvrPlatform_AbuseReport_ReportRequestHandled_Delegate, bool, FString);

/** The currently running application has indicated they want to show their in-app reporting flow or that they choose to ignore the request. */
void OVRPLATFORM_API OvrPlatform_AbuseReport_ReportRequestHandled(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// Possible states that an app can respond to the platform notification that the in-app reporting flow has been requested by the user.
    EOvrReportRequestResponse Response,
    /// Delegate to be called when the request is complete
    OvrPlatform_AbuseReport_ReportRequestHandled_Delegate&& Delegate);

// ----------------------------------------------------------------------
// Achievements

typedef TSharedPtr<FOvrAchievementUpdate> FOvrAchievementUpdatePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Achievements_AddCount_Delegate, bool, FOvrAchievementUpdatePtr, FString);

/**
 * Add 'count' to the achievement with the given name. This must be a COUNT achievement.
 * The largest number that is supported by this method is the max value of a signed 64-bit integer.
 * If the number is larger than that, it is clamped to that max value before being passed to
 * the servers.
 */
void OVRPLATFORM_API OvrPlatform_Achievements_AddCount(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The api_name of the achievement that will be adding count, which can be retrieved by {{methods.achievement_definition.get_name}}.
    FString Name,
    /// The value of count that will be added to the achievement.
    int64 Count,
    /// Delegate to be called when the request is complete
    OvrPlatform_Achievements_AddCount_Delegate&& Delegate);

typedef TSharedPtr<FOvrAchievementUpdate> FOvrAchievementUpdatePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Achievements_AddFields_Delegate, bool, FOvrAchievementUpdatePtr, FString);

/** Unlock fields of a BITFIELD achievement. */
void OVRPLATFORM_API OvrPlatform_Achievements_AddFields(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The api_name of the Bitfield achievement whose field(s) will be unlocked, which can be retrieved by {{methods.achievement_definition.get_name}}.
    FString Name,
    /// A string containing either '0' or '1' characters. Every '1' will unlock the field in the corresponding position.
    FString Fields,
    /// Delegate to be called when the request is complete
    OvrPlatform_Achievements_AddFields_Delegate&& Delegate);

typedef TSharedPtr<FOvrAchievementDefinitionPages> FOvrAchievementDefinitionArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Achievements_GetAllDefinitions_Delegate, bool, FOvrAchievementDefinitionArrayPtr, FString);

/** Retrieve all achievement definitions for the app, including their name, unlock requirements, and any additional details. */
void OVRPLATFORM_API OvrPlatform_Achievements_GetAllDefinitions(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// Delegate to be called when the request is complete
    OvrPlatform_Achievements_GetAllDefinitions_Delegate&& Delegate);

typedef TSharedPtr<FOvrAchievementProgressPages> FOvrAchievementProgressArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Achievements_GetAllProgress_Delegate, bool, FOvrAchievementProgressArrayPtr, FString);

/** Retrieve the progress for the user on all achievements in the app. */
void OVRPLATFORM_API OvrPlatform_Achievements_GetAllProgress(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// Delegate to be called when the request is complete
    OvrPlatform_Achievements_GetAllProgress_Delegate&& Delegate);

typedef TSharedPtr<FOvrAchievementDefinitionPages> FOvrAchievementDefinitionArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Achievements_GetDefinitionsByName_Delegate, bool, FOvrAchievementDefinitionArrayPtr, FString);

/** Retrieve the achievement definitions that match the specified names, including their name, unlock requirements, and any additional details. */
void OVRPLATFORM_API OvrPlatform_Achievements_GetDefinitionsByName(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The api_names of the achievements used to retrieve the definition information, which can be retrieved by {{methods.achievement_definition.get_name}}.
    TArray<FString> Names,
    /// Delegate to be called when the request is complete
    OvrPlatform_Achievements_GetDefinitionsByName_Delegate&& Delegate);

typedef TSharedPtr<FOvrAchievementProgressPages> FOvrAchievementProgressArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Achievements_GetProgressByName_Delegate, bool, FOvrAchievementProgressArrayPtr, FString);

/** Retrieve the user's progress on the achievements that match the specified names. */
void OVRPLATFORM_API OvrPlatform_Achievements_GetProgressByName(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The api_names of the achievements used to retrieve the progress information, which can be retrieved by {{methods.achievement_definition.get_name}}.
    TArray<FString> Names,
    /// Delegate to be called when the request is complete
    OvrPlatform_Achievements_GetProgressByName_Delegate&& Delegate);

typedef TSharedPtr<FOvrAchievementUpdate> FOvrAchievementUpdatePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Achievements_Unlock_Delegate, bool, FOvrAchievementUpdatePtr, FString);

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
void OVRPLATFORM_API OvrPlatform_Achievements_Unlock(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The api_name of the achievement that will be unlocked, which can be retrieved by {{methods.achievement_definition.get_name}}.
    FString Name,
    /// Delegate to be called when the request is complete
    OvrPlatform_Achievements_Unlock_Delegate&& Delegate);

// ----------------------------------------------------------------------
// Application

typedef TSharedPtr<FOvrAppDownloadResult> FOvrAppDownloadResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Application_CancelAppDownload_Delegate, bool, FOvrAppDownloadResultPtr, FString);

/**
 * Cancel an app download that is in progress.
 * It will return a result when the download is cancelled.
 */
void OVRPLATFORM_API OvrPlatform_Application_CancelAppDownload(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// Delegate to be called when the request is complete
    OvrPlatform_Application_CancelAppDownload_Delegate&& Delegate);

typedef TSharedPtr<FOvrAppDownloadProgressResult> FOvrAppDownloadProgressResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Application_CheckAppDownloadProgress_Delegate, bool, FOvrAppDownloadProgressResultPtr, FString);

/** Track download progress for an app. */
void OVRPLATFORM_API OvrPlatform_Application_CheckAppDownloadProgress(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// Delegate to be called when the request is complete
    OvrPlatform_Application_CheckAppDownloadProgress_Delegate&& Delegate);

typedef TSharedPtr<FOvrApplicationVersion> FOvrApplicationVersionPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Application_GetVersion_Delegate, bool, FOvrApplicationVersionPtr, FString);

/**
 * Requests version information, including the field FOvrApplicationVersion::CurrentCode and
 * field FOvrApplicationVersion::CurrentName of the currently installed app
 * and field FOvrApplicationVersion::LatestCode, field FOvrApplicationVersion::LatestName,
 * field FOvrApplicationVersion::Size and field FOvrApplicationVersion::ReleaseDate of the latest app update.
 */
void OVRPLATFORM_API OvrPlatform_Application_GetVersion(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// Delegate to be called when the request is complete
    OvrPlatform_Application_GetVersion_Delegate&& Delegate);

typedef TSharedPtr<FOvrAppDownloadResult> FOvrAppDownloadResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Application_InstallAppUpdateAndRelaunch_Delegate, bool, FOvrAppDownloadResultPtr, FString);

/**
 * Installs the app update that was previously downloaded.
 * Once the install begins the application will exit automatically.
 * After the installation process is complete, the app will be relaunched
 * based on the options passed in.
 */
void OVRPLATFORM_API OvrPlatform_Application_InstallAppUpdateAndRelaunch(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// Additional configuration for this relaunch, which is optional. It contains 5 fields {{options.application.deeplink_message}}, {{options.application.destination_api_name}}, {{options.application.lobby_session_id}}, {{options.application.match_session_id}} and {{options.application.room_id}}.
    FOvrApplicationOptions DeeplinkOptions,
    /// Delegate to be called when the request is complete
    OvrPlatform_Application_InstallAppUpdateAndRelaunch_Delegate&& Delegate);

typedef TSharedPtr<FString> FStringPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Application_LaunchOtherApp_Delegate, bool, FStringPtr, FString);

/**
 * Launches a different application in the user's library. If the user
 * does not have that application installed, they will be taken to that app's
 * page in the Oculus Store
 */
void OVRPLATFORM_API OvrPlatform_Application_LaunchOtherApp(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The unique ID of the app to be launched.
    FOvrId AppID,
    /// Additional configuration for this request, which is optional. It contains 5 fields {{options.application.deeplink_message}}, {{options.application.destination_api_name}}, {{options.application.lobby_session_id}}, {{options.application.match_session_id}} and {{options.application.room_id}}.
    FOvrApplicationOptions DeeplinkOptions,
    /// Delegate to be called when the request is complete
    OvrPlatform_Application_LaunchOtherApp_Delegate&& Delegate);

typedef TSharedPtr<FOvrAppDownloadResult> FOvrAppDownloadResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Application_StartAppDownload_Delegate, bool, FOvrAppDownloadResultPtr, FString);

/**
 * Starts an app download.
 * It will return a result when the download is finished.
 * Download progress can be monitored using the UOvrRequestsBlueprintLibrary::Application_CheckAppDownloadProgress().
 */
void OVRPLATFORM_API OvrPlatform_Application_StartAppDownload(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// Delegate to be called when the request is complete
    OvrPlatform_Application_StartAppDownload_Delegate&& Delegate);

// ----------------------------------------------------------------------
// ApplicationLifecycle

// ----------------------------------------------------------------------
// AssetFile

typedef TSharedPtr<FOvrAssetFileDeleteResult> FOvrAssetFileDeleteResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_AssetFile_Delete_Delegate, bool, FOvrAssetFileDeleteResultPtr, FString);

[[deprecated("Use UOvrRequestsBlueprintLibrary::AssetFile_DeleteById()")]]
/** \deprecated Use UOvrRequestsBlueprintLibrary::AssetFile_DeleteById() */
void OVRPLATFORM_API OvrPlatform_AssetFile_Delete(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The uuid of the asset file.
    FOvrId AssetFileID,
    /// Delegate to be called when the request is complete
    OvrPlatform_AssetFile_Delete_Delegate&& Delegate);

typedef TSharedPtr<FOvrAssetFileDeleteResult> FOvrAssetFileDeleteResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_AssetFile_DeleteById_Delegate, bool, FOvrAssetFileDeleteResultPtr, FString);

/**
 * Removes a previously installed asset file from the device by its ID.
 * Returns an object containing the asset ID and file name, and a success flag.
 */
void OVRPLATFORM_API OvrPlatform_AssetFile_DeleteById(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The asset file ID
    FOvrId AssetFileID,
    /// Delegate to be called when the request is complete
    OvrPlatform_AssetFile_DeleteById_Delegate&& Delegate);

typedef TSharedPtr<FOvrAssetFileDeleteResult> FOvrAssetFileDeleteResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_AssetFile_DeleteByName_Delegate, bool, FOvrAssetFileDeleteResultPtr, FString);

/**
 * Removes a previously installed asset file from the device by its name.
 * Returns an object containing the asset ID and file name, and a success flag.
 */
void OVRPLATFORM_API OvrPlatform_AssetFile_DeleteByName(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The asset file name
    FString AssetFileName,
    /// Delegate to be called when the request is complete
    OvrPlatform_AssetFile_DeleteByName_Delegate&& Delegate);

typedef TSharedPtr<FOvrAssetFileDownloadResult> FOvrAssetFileDownloadResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_AssetFile_Download_Delegate, bool, FOvrAssetFileDownloadResultPtr, FString);

[[deprecated("Use UOvrRequestsBlueprintLibrary::AssetFile_DownloadById()")]]
/** \deprecated Use UOvrRequestsBlueprintLibrary::AssetFile_DownloadById() */
void OVRPLATFORM_API OvrPlatform_AssetFile_Download(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The uuid of the file.
    FOvrId AssetFileID,
    /// Delegate to be called when the request is complete
    OvrPlatform_AssetFile_Download_Delegate&& Delegate);

typedef TSharedPtr<FOvrAssetFileDownloadResult> FOvrAssetFileDownloadResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_AssetFile_DownloadById_Delegate, bool, FOvrAssetFileDownloadResultPtr, FString);

/**
 * Downloads an asset file by its ID on demand. Returns an object containing
 * the asset ID and filepath. Sends periodic
 * UOvrPlatformSubsystem::OnAssetFileDownloadUpdate() to track the downloads.
 */
void OVRPLATFORM_API OvrPlatform_AssetFile_DownloadById(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The asset file ID
    FOvrId AssetFileID,
    /// Delegate to be called when the request is complete
    OvrPlatform_AssetFile_DownloadById_Delegate&& Delegate);

typedef TSharedPtr<FOvrAssetFileDownloadResult> FOvrAssetFileDownloadResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_AssetFile_DownloadByName_Delegate, bool, FOvrAssetFileDownloadResultPtr, FString);

/**
 * Downloads an asset file by its name on demand. Returns an object containing
 * the asset ID and filepath. Sends periodic
 * {notifications.asset_file.download_update}} to track the downloads.
 */
void OVRPLATFORM_API OvrPlatform_AssetFile_DownloadByName(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The asset file name
    FString AssetFileName,
    /// Delegate to be called when the request is complete
    OvrPlatform_AssetFile_DownloadByName_Delegate&& Delegate);

typedef TSharedPtr<FOvrAssetFileDownloadCancelResult> FOvrAssetFileDownloadCancelResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_AssetFile_DownloadCancel_Delegate, bool, FOvrAssetFileDownloadCancelResultPtr, FString);

[[deprecated("Use UOvrRequestsBlueprintLibrary::AssetFile_DownloadCancelById()")]]
/** \deprecated Use UOvrRequestsBlueprintLibrary::AssetFile_DownloadCancelById() */
void OVRPLATFORM_API OvrPlatform_AssetFile_DownloadCancel(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The uuid of the asset file.
    FOvrId AssetFileID,
    /// Delegate to be called when the request is complete
    OvrPlatform_AssetFile_DownloadCancel_Delegate&& Delegate);

typedef TSharedPtr<FOvrAssetFileDownloadCancelResult> FOvrAssetFileDownloadCancelResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_AssetFile_DownloadCancelById_Delegate, bool, FOvrAssetFileDownloadCancelResultPtr, FString);

/**
 * Cancels a previously spawned download request for an asset file by its ID.
 * Returns an object containing the asset ID and file path, and a success flag.
 */
void OVRPLATFORM_API OvrPlatform_AssetFile_DownloadCancelById(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The asset file ID
    FOvrId AssetFileID,
    /// Delegate to be called when the request is complete
    OvrPlatform_AssetFile_DownloadCancelById_Delegate&& Delegate);

typedef TSharedPtr<FOvrAssetFileDownloadCancelResult> FOvrAssetFileDownloadCancelResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_AssetFile_DownloadCancelByName_Delegate, bool, FOvrAssetFileDownloadCancelResultPtr, FString);

/**
 * Cancels a previously spawned download request for an asset file by its name.
 * Returns an object containing the asset ID and file path, and a success flag.
 */
void OVRPLATFORM_API OvrPlatform_AssetFile_DownloadCancelByName(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The asset file name
    FString AssetFileName,
    /// Delegate to be called when the request is complete
    OvrPlatform_AssetFile_DownloadCancelByName_Delegate&& Delegate);

typedef TSharedPtr<TArray<FOvrAssetDetails>> FOvrAssetDetailsArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_AssetFile_GetList_Delegate, bool, FOvrAssetDetailsArrayPtr, FString);

/**
 * Returns an array of asset details with asset file names and their associated IDs field FOvrAssetDetails::AssetId,
 * and whether it's currently installed field FOvrAssetDetails::DownloadStatus.
 */
void OVRPLATFORM_API OvrPlatform_AssetFile_GetList(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// Delegate to be called when the request is complete
    OvrPlatform_AssetFile_GetList_Delegate&& Delegate);

typedef TSharedPtr<FOvrAssetDetails> FOvrAssetDetailsPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_AssetFile_Status_Delegate, bool, FOvrAssetDetailsPtr, FString);

[[deprecated("Use UOvrRequestsBlueprintLibrary::AssetFile_StatusById()")]]
/** \deprecated Use UOvrRequestsBlueprintLibrary::AssetFile_StatusById() */
void OVRPLATFORM_API OvrPlatform_AssetFile_Status(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The uuid of the asset file.
    FOvrId AssetFileID,
    /// Delegate to be called when the request is complete
    OvrPlatform_AssetFile_Status_Delegate&& Delegate);

typedef TSharedPtr<FOvrAssetDetails> FOvrAssetDetailsPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_AssetFile_StatusById_Delegate, bool, FOvrAssetDetailsPtr, FString);

/** Returns the details FOvrAssetDetails on a single asset: ID, file name, and whether it's currently installed */
void OVRPLATFORM_API OvrPlatform_AssetFile_StatusById(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The asset file ID
    FOvrId AssetFileID,
    /// Delegate to be called when the request is complete
    OvrPlatform_AssetFile_StatusById_Delegate&& Delegate);

typedef TSharedPtr<FOvrAssetDetails> FOvrAssetDetailsPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_AssetFile_StatusByName_Delegate, bool, FOvrAssetDetailsPtr, FString);

/** Returns the details FOvrAssetDetails on a single asset: ID, file name, and whether it's currently installed */
void OVRPLATFORM_API OvrPlatform_AssetFile_StatusByName(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The asset file name
    FString AssetFileName,
    /// Delegate to be called when the request is complete
    OvrPlatform_AssetFile_StatusByName_Delegate&& Delegate);

// ----------------------------------------------------------------------
// Avatar

typedef TSharedPtr<FOvrAvatarEditorResult> FOvrAvatarEditorResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Avatar_LaunchAvatarEditor_Delegate, bool, FOvrAvatarEditorResultPtr, FString);

/**
 * Launches the Avatar Editor. Meta Avatars Editor is a feature that allows users to edit their Meta Avatars appearances within the VR application
 * that they are currently using. This experience is often used by users to switch their outfit and accessories to better suit the VR experience they are experiencing.
 * The result can be retrieved by field FOvrAvatarEditorResult::RequestSent.
 */
void OVRPLATFORM_API OvrPlatform_Avatar_LaunchAvatarEditor(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// A {{options.avatar_editor.create}} contains the options information, including an optional override for the source of the request, which is specified by {{options.avatar_editor.source_override}}.
    FOvrAvatarEditorOptions Options,
    /// Delegate to be called when the request is complete
    OvrPlatform_Avatar_LaunchAvatarEditor_Delegate&& Delegate);

// ----------------------------------------------------------------------
// Challenges

typedef TSharedPtr<FOvrChallenge> FOvrChallengePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Challenges_Create_Delegate, bool, FOvrChallengePtr, FString);

[[deprecated("Use server-to-server API call instead.")]]
/** \deprecated Use server-to-server API call instead. */
void OVRPLATFORM_API OvrPlatform_Challenges_Create(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// A string represents the name of the leaderboard.
    FString LeaderboardName,
    /// This indicates the options of the challenge and it can be retrieved by {{options.challenge.create}}.
    FOvrChallengeOptions ChallengeOptions,
    /// Delegate to be called when the request is complete
    OvrPlatform_Challenges_Create_Delegate&& Delegate);

typedef TSharedPtr<FOvrChallenge> FOvrChallengePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Challenges_DeclineInvite_Delegate, bool, FOvrChallengePtr, FString);

/**
 * If the current user has the necessary permissions, they can decline a challenge by providing the challenge ID,
 * which can be obtained using field FOvrChallenge::ID.
 */
void OVRPLATFORM_API OvrPlatform_Challenges_DeclineInvite(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The ID of challenge that the user is going to decline. It can be retrieved by {{methods.challenge.get_id}}.
    FOvrId ChallengeID,
    /// Delegate to be called when the request is complete
    OvrPlatform_Challenges_DeclineInvite_Delegate&& Delegate);

DECLARE_DELEGATE_TwoParams(OvrPlatform_Challenges_Delete_Delegate, bool, FString);

[[deprecated("Use server-to-server API call instead.")]]
/** \deprecated Use server-to-server API call instead. */
void OVRPLATFORM_API OvrPlatform_Challenges_Delete(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The uuid of the challenge.
    FOvrId ChallengeID,
    /// Delegate to be called when the request is complete
    OvrPlatform_Challenges_Delete_Delegate&& Delegate);

typedef TSharedPtr<FOvrChallenge> FOvrChallengePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Challenges_Get_Delegate, bool, FOvrChallengePtr, FString);

/** Gets detailed information for a single challenge by providing the challenge ID, which can be retrieved by calling field FOvrChallenge::ID. */
void OVRPLATFORM_API OvrPlatform_Challenges_Get(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The id of the challenge whose entries to return, which can be retrieved by calling {{methods.challenge.get_id}}.
    FOvrId ChallengeID,
    /// Delegate to be called when the request is complete
    OvrPlatform_Challenges_Get_Delegate&& Delegate);

typedef TSharedPtr<FOvrChallengeEntryPages> FOvrChallengeEntryArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Challenges_GetEntries_Delegate, bool, FOvrChallengeEntryArrayPtr, FString);

/**
 * Retrieves a list of entries for a specific challenge, with options to filter and limit the results. By providing the challengeID,
 * you can specify which challenge's entries you want to retrieve. The limit parameter allows you to control the number of entries returned.
 * The filter parameter enables you to refine the results to only include entries from users who are bidirectional followers.
 * The startAt parameter allows you to define whether to center the query on the user or start at the top of the challenge.
 */
void OVRPLATFORM_API OvrPlatform_Challenges_GetEntries(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The id of the challenge whose entries to return, which can be retrieved by calling {{methods.challenge.get_id}}.
    FOvrId ChallengeID,
    /// Sets a limit on the maximum number of challenges to be fetched, which can be useful for pagination or performance reasons.
    int32 Limit,
    /// By using the {{enums.leaderboard_filter_type}}, you can refine the results to only include entries from users who are bidirectional followers.
    EOvrLeaderboardFilterType Filter,
    /// Defines whether to center the query on the user or start at the top of the challenge. If this is {{enum_members.leaderboard_start_at.centered_on_viewer}} or {{enum_members.leaderboard_start_at.centered_on_viewer_or_top}}, then the current user's ID will be automatically added to the query.
    EOvrLeaderboardStartAt StartAt,
    /// Delegate to be called when the request is complete
    OvrPlatform_Challenges_GetEntries_Delegate&& Delegate);

typedef TSharedPtr<FOvrChallengeEntryPages> FOvrChallengeEntryArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Challenges_GetEntriesAfterRank_Delegate, bool, FOvrChallengeEntryArrayPtr, FString);

/**
 * Returns a list of entries for a specific challenge, starting from a specified rank.
 * By providing the challengeID and rank, you can specify which challenge's entries you want to retrieve and where to start the query.
 * The limit parameter allows you to control the number of entries returned.
 */
void OVRPLATFORM_API OvrPlatform_Challenges_GetEntriesAfterRank(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The id of the challenge whose entries to return, which can be retrieved by calling {{methods.challenge.get_id}}.
    FOvrId ChallengeID,
    /// Sets a limit on the maximum number of challenges to be fetched, which can be useful for pagination or performance reasons.
    int32 Limit,
    /// The position after which to start. For example, 10 returns challenge results starting with the 11th user.
    int64 AfterRank,
    /// Delegate to be called when the request is complete
    OvrPlatform_Challenges_GetEntriesAfterRank_Delegate&& Delegate);

typedef TSharedPtr<FOvrChallengeEntryPages> FOvrChallengeEntryArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Challenges_GetEntriesByIds_Delegate, bool, FOvrChallengeEntryArrayPtr, FString);

/**
 * Retrieves a list of challenge entries for a specific set of user IDs, with options to filter and limit the results.
 * This method is useful for retrieving a list of challenge entries for a specific set of users, allowing you to display their progress and rankings within the challenge.
 */
void OVRPLATFORM_API OvrPlatform_Challenges_GetEntriesByIds(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The id of the challenge whose entries to return, which can be retrieved by calling {{methods.challenge.get_id}}.
    FOvrId ChallengeID,
    /// Sets a limit on the maximum number of challenges to be fetched, which can be useful for pagination or performance reasons.
    int32 Limit,
    /// Defines whether to center the query on the user or start at the top of the challenge. If this is {{enum_members.leaderboard_start_at.centered_on_viewer}} or {{enum_members.leaderboard_start_at.centered_on_viewer_or_top}}, then the current user's ID will be automatically added to the query.
    EOvrLeaderboardStartAt StartAt,
    /// Defines a list of user ids to get entries for.
    TArray<FOvrId> UserIDs,
    /// Delegate to be called when the request is complete
    OvrPlatform_Challenges_GetEntriesByIds_Delegate&& Delegate);

typedef TSharedPtr<FOvrChallengePages> FOvrChallengeArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Challenges_GetList_Delegate, bool, FOvrChallengeArrayPtr, FString);

/**
 * Returns a list of challenges that match the specified options. The FOvrChallengeOptions parameter allows you to specify
 * the criteria for the challenges you want to retrieve. The limit parameter allows you to control the number of challenges returned.
 */
void OVRPLATFORM_API OvrPlatform_Challenges_GetList(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// This indicates the options of the challenge and it can be retrieved by {{options.challenge.create}}.
    FOvrChallengeOptions ChallengeOptions,
    /// Sets a limit on the maximum number of challenges to be fetched, which can be useful for pagination or performance reasons.
    int32 Limit,
    /// Delegate to be called when the request is complete
    OvrPlatform_Challenges_GetList_Delegate&& Delegate);

typedef TSharedPtr<FOvrChallenge> FOvrChallengePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Challenges_Join_Delegate, bool, FOvrChallengePtr, FString);

/**
 * If the current user has the necessary permissions to join, participate in a challenge by providing the challenge ID,
 * which can be retrieved using field FOvrChallenge::ID.
 */
void OVRPLATFORM_API OvrPlatform_Challenges_Join(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The ID of challenge that the user is going to join. It can be retrieved by {{methods.challenge.get_id}}.
    FOvrId ChallengeID,
    /// Delegate to be called when the request is complete
    OvrPlatform_Challenges_Join_Delegate&& Delegate);

typedef TSharedPtr<FOvrChallenge> FOvrChallengePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Challenges_Leave_Delegate, bool, FOvrChallengePtr, FString);

/**
 * If the current user has the necessary permissions, they can leave a challenge by providing the challenge ID,
 * which can be obtained using field FOvrChallenge::ID.
 */
void OVRPLATFORM_API OvrPlatform_Challenges_Leave(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The ID of challenge that the user is going to leave. It can be retrieved by {{methods.challenge.get_id}}.
    FOvrId ChallengeID,
    /// Delegate to be called when the request is complete
    OvrPlatform_Challenges_Leave_Delegate&& Delegate);

typedef TSharedPtr<FOvrChallenge> FOvrChallengePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Challenges_UpdateInfo_Delegate, bool, FOvrChallengePtr, FString);

[[deprecated("Use server-to-server API call instead.")]]
/** \deprecated Use server-to-server API call instead. */
void OVRPLATFORM_API OvrPlatform_Challenges_UpdateInfo(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The uuid of the challenge.
    FOvrId ChallengeID,
    /// This indicates the options of the challenge and it can be retrieved by {{options.challenge.create}}.
    FOvrChallengeOptions ChallengeOptions,
    /// Delegate to be called when the request is complete
    OvrPlatform_Challenges_UpdateInfo_Delegate&& Delegate);

// ----------------------------------------------------------------------
// Cowatching

typedef TSharedPtr<FString> FStringPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Cowatching_GetPresenterData_Delegate, bool, FStringPtr, FString);

/**
 * Retrieve the presenter data that drives an active cowatching session.
 * This method can be called when there is an ongoing cowatching session,
 * allowing developers to access and utilize the presenter data to enhance the user experience.
 */
void OVRPLATFORM_API OvrPlatform_Cowatching_GetPresenterData(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// Delegate to be called when the request is complete
    OvrPlatform_Cowatching_GetPresenterData_Delegate&& Delegate);

typedef TSharedPtr<FOvrCowatchViewerPages> FOvrCowatchViewerArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Cowatching_GetViewersData_Delegate, bool, FOvrCowatchViewerArrayPtr, FString);

/**
 * Retrieve the viewer data of everyone who is in a cowatching session whose data was set by UOvrRequestsBlueprintLibrary::Cowatching_SetViewerData() ViewerData.
 * This can be called when there is an active cowatching session.
 */
void OVRPLATFORM_API OvrPlatform_Cowatching_GetViewersData(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// Delegate to be called when the request is complete
    OvrPlatform_Cowatching_GetViewersData_Delegate&& Delegate);

typedef TSharedPtr<FOvrCowatchingState> FOvrCowatchingStatePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Cowatching_IsInSession_Delegate, bool, FOvrCowatchingStatePtr, FString);

/**
 * Check whether the current user is participating in the ongoing cowatching session.
 * It returns a boolean value field FOvrCowatchingState::InSession indicating the user's presence in the session.
 */
void OVRPLATFORM_API OvrPlatform_Cowatching_IsInSession(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// Delegate to be called when the request is complete
    OvrPlatform_Cowatching_IsInSession_Delegate&& Delegate);

DECLARE_DELEGATE_TwoParams(OvrPlatform_Cowatching_JoinSession_Delegate, bool, FString);

/** Join the ongoing cowatching session as a viewer, updating data only possible for users already in the session. */
void OVRPLATFORM_API OvrPlatform_Cowatching_JoinSession(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// Delegate to be called when the request is complete
    OvrPlatform_Cowatching_JoinSession_Delegate&& Delegate);

DECLARE_DELEGATE_TwoParams(OvrPlatform_Cowatching_LaunchInviteDialog_Delegate, bool, FString);

/** Launch a dialog for inviting users to cowatch in Copresent Home. */
void OVRPLATFORM_API OvrPlatform_Cowatching_LaunchInviteDialog(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// Delegate to be called when the request is complete
    OvrPlatform_Cowatching_LaunchInviteDialog_Delegate&& Delegate);

DECLARE_DELEGATE_TwoParams(OvrPlatform_Cowatching_LeaveSession_Delegate, bool, FString);

/** Leave the current cowatching session, rendering viewer data obsolete and no longer relevant to the ongoing experience. */
void OVRPLATFORM_API OvrPlatform_Cowatching_LeaveSession(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// Delegate to be called when the request is complete
    OvrPlatform_Cowatching_LeaveSession_Delegate&& Delegate);

DECLARE_DELEGATE_TwoParams(OvrPlatform_Cowatching_RequestToPresent_Delegate, bool, FString);

/** Request to initiate a cowatching session as the presenter while being copresent in a shared virtual home environment. */
void OVRPLATFORM_API OvrPlatform_Cowatching_RequestToPresent(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// Delegate to be called when the request is complete
    OvrPlatform_Cowatching_RequestToPresent_Delegate&& Delegate);

DECLARE_DELEGATE_TwoParams(OvrPlatform_Cowatching_ResignFromPresenting_Delegate, bool, FString);

/** Stop being the presenter and terminate the ongoing cowatching session. This action will effectively end the shared media experience. */
void OVRPLATFORM_API OvrPlatform_Cowatching_ResignFromPresenting(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// Delegate to be called when the request is complete
    OvrPlatform_Cowatching_ResignFromPresenting_Delegate&& Delegate);

DECLARE_DELEGATE_TwoParams(OvrPlatform_Cowatching_SetPresenterData_Delegate, bool, FString);

/**
 * Set the data that drives a cowatching session. This method is only callable by the presenter.
 * The video title cannot exceed 100 characters, and the data size is limited to 500 characters.
 * The data will be eventually consistent across all users.
 */
void OVRPLATFORM_API OvrPlatform_Cowatching_SetPresenterData(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// A string representing the title of the video being played in the cowatching session. This parameter must not exceed 100 characters in length.
    FString VideoTitle,
    /// A string containing data that drives the cowatching session, such as video metadata or playback information. This parameter is limited to 500 characters in length and will be eventually consistent across all users participating in the session.
    FString PresenterData,
    /// Delegate to be called when the request is complete
    OvrPlatform_Cowatching_SetPresenterData_Delegate&& Delegate);

DECLARE_DELEGATE_TwoParams(OvrPlatform_Cowatching_SetViewerData_Delegate, bool, FString);

/**
 * Set the current user's viewer data to be shared with copresent users. This can be called when there is an active cowatching session.
 * The data size is limited to 500 characters, and it will eventually become consistent across all users.
 */
void OVRPLATFORM_API OvrPlatform_Cowatching_SetViewerData(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// A string containing data about the current user's viewer state, such as their preferences or settings. This data is shared with copresent users during an active cowatching session and is limited to 500 characters in size. The data will eventually become consistent across all users participating in the session.
    FString ViewerData,
    /// Delegate to be called when the request is complete
    OvrPlatform_Cowatching_SetViewerData_Delegate&& Delegate);

// ----------------------------------------------------------------------
// DeviceApplicationIntegrity

typedef TSharedPtr<FString> FStringPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_DeviceApplicationIntegrity_GetIntegrityToken_Delegate, bool, FStringPtr, FString);

/**
 * Returns Device and Application Integrity Attestation JSON Web Token.
 * The token has format of header.claims.signature encoded in base64.
 * Header contains algorithm type (PS256) and token type (JWT).
 * See more details [here](https://developer.oculus.com/documentation/unreal/ps-attestation-api/#how-does-this-work).
 */
void OVRPLATFORM_API OvrPlatform_DeviceApplicationIntegrity_GetIntegrityToken(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// A string that represents a nonce value used to generate the attestation token, ensuring uniqueness and security.
    FString ChallengeNonce,
    /// Delegate to be called when the request is complete
    OvrPlatform_DeviceApplicationIntegrity_GetIntegrityToken_Delegate&& Delegate);

// ----------------------------------------------------------------------
// Entitlement

DECLARE_DELEGATE_TwoParams(OvrPlatform_Entitlement_GetIsViewerEntitled_Delegate, bool, FString);

/**
 * Returns whether the current user is entitled to the current app. The primary purpose of this function is to verify
 * user access rights to the application, ensuring that the user is authorized to use it.
 * See example usage [here](https://developer.oculus.com/documentation/unreal/ps-entitlement-check/#entitlement).
 */
void OVRPLATFORM_API OvrPlatform_Entitlement_GetIsViewerEntitled(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// Delegate to be called when the request is complete
    OvrPlatform_Entitlement_GetIsViewerEntitled_Delegate&& Delegate);

// ----------------------------------------------------------------------
// GroupPresence

DECLARE_DELEGATE_TwoParams(OvrPlatform_GroupPresence_Clear_Delegate, bool, FString);

/**
 * Clears the current group presence settings for your app. Use this when a user’s group presence setting in your app
 * needs to be changed when moving to new destinations in your app.
 */
void OVRPLATFORM_API OvrPlatform_GroupPresence_Clear(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// Delegate to be called when the request is complete
    OvrPlatform_GroupPresence_Clear_Delegate&& Delegate);

typedef TSharedPtr<FOvrUserPages> FOvrUserArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_GroupPresence_GetInvitableUsers_Delegate, bool, FOvrUserArrayPtr, FString);

/** Returns a list of users that can be invited to your current lobby. These are pulled from your bidirectional followers and recently met lists. */
void OVRPLATFORM_API OvrPlatform_GroupPresence_GetInvitableUsers(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// It contains two methods. 1. {{options.invite.suggested_users}} - Takes the userID as a parameter and adds it to the inevitable users list. 2. {{options_clear.invite.suggested_users}} - Clears the inevitable users list.
    FOvrInviteOptions Options,
    /// Delegate to be called when the request is complete
    OvrPlatform_GroupPresence_GetInvitableUsers_Delegate&& Delegate);

typedef TSharedPtr<FOvrApplicationInvitePages> FOvrApplicationInviteArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_GroupPresence_GetSentInvites_Delegate, bool, FOvrApplicationInviteArrayPtr, FString);

/** Get the application invites which have been sent by the user. */
void OVRPLATFORM_API OvrPlatform_GroupPresence_GetSentInvites(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// Delegate to be called when the request is complete
    OvrPlatform_GroupPresence_GetSentInvites_Delegate&& Delegate);

typedef TSharedPtr<FOvrInvitePanelResultInfo> FOvrInvitePanelResultInfoPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_GroupPresence_LaunchInvitePanel_Delegate, bool, FOvrInvitePanelResultInfoPtr, FString);

/**
 * Launches the system invite dialog with a roster of eligible users for the current user to invite to the app.
 * It is recommended that you surface a button in your UI that triggers this dialog when a user is joinable.
 */
void OVRPLATFORM_API OvrPlatform_GroupPresence_LaunchInvitePanel(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// It contains two methods. 1. {{options.invite.suggested_users}} - Takes the userID as a parameter and adds it to the inevitable users list. 2. {{options_clear.invite.suggested_users}} - Clears the inevitable users list.
    FOvrInviteOptions Options,
    /// Delegate to be called when the request is complete
    OvrPlatform_GroupPresence_LaunchInvitePanel_Delegate&& Delegate);

DECLARE_DELEGATE_TwoParams(OvrPlatform_GroupPresence_LaunchMultiplayerErrorDialog_Delegate, bool, FString);

/**
 * Launch an error dialog window with predefined messages for commonly occurring multiplayer errors.
 * Check the Invokable Error Dialogs documentation for more information about these error messages and their values.
 */
void OVRPLATFORM_API OvrPlatform_GroupPresence_LaunchMultiplayerErrorDialog(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// It contains a {{options.multiplayer_error.error_key}} associated with the predefined error message to be shown to users.
    FOvrMultiplayerErrorOptions Options,
    /// Delegate to be called when the request is complete
    OvrPlatform_GroupPresence_LaunchMultiplayerErrorDialog_Delegate&& Delegate);

typedef TSharedPtr<FOvrRejoinDialogResult> FOvrRejoinDialogResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_GroupPresence_LaunchRejoinDialog_Delegate, bool, FOvrRejoinDialogResultPtr, FString);

/**
 * Launch the dialog allowing users to rejoin a previous lobby or match.
 * Either the user’s FOvrGroupPresenceOptions::LobbySessionId, their FOvrGroupPresenceOptions::MatchSessionId,
 * or both must be populated as valid rejoinable destinations.
 * Check the Rejoin documentation for use cases and information on this feature.
 */
void OVRPLATFORM_API OvrPlatform_GroupPresence_LaunchRejoinDialog(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The unique identifier of the lobby session to rejoin.
    FString LobbySessionId,
    /// The unique identifier of the match session to rejoin.
    FString MatchSessionId,
    /// The unique name of the in-app destination to rejoin.
    FString DestinationApiName,
    /// Delegate to be called when the request is complete
    OvrPlatform_GroupPresence_LaunchRejoinDialog_Delegate&& Delegate);

DECLARE_DELEGATE_TwoParams(OvrPlatform_GroupPresence_LaunchRosterPanel_Delegate, bool, FString);

/**
 * Launch the panel displaying the current users in the roster. We do not recommend using this API
 * because the list current users is surfaced in the Destination UI when the Meta Quest button is pressed.
 */
void OVRPLATFORM_API OvrPlatform_GroupPresence_LaunchRosterPanel(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// It contains 2 methods. 1. {{options.roster.suggested_users}} - it takes userID as a parameter and adds it to the inevitable users list. 2. {{options_clear.roster.suggested_users}} - it clears the inevitable users list.
    FOvrRosterOptions Options,
    /// Delegate to be called when the request is complete
    OvrPlatform_GroupPresence_LaunchRosterPanel_Delegate&& Delegate);

typedef TSharedPtr<FOvrSendInvitesResult> FOvrSendInvitesResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_GroupPresence_SendInvites_Delegate, bool, FOvrSendInvitesResultPtr, FString);

/**
 * Sends invites to the current application to the list of userIDs passed in.
 * You can fetch a list of users to pass in via the UOvrRequestsBlueprintLibrary::GroupPresence_GetInvitableUsers().
 * This API works as an alternative to UOvrRequestsBlueprintLibrary::GroupPresence_LaunchInvitePanel()
 * which delegates the invite flow to the system invite module.
 * UOvrRequestsBlueprintLibrary::GroupPresence_LaunchInvitePanel() is the recommended approach.
 */
void OVRPLATFORM_API OvrPlatform_GroupPresence_SendInvites(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// userIDs is a list of users’ ids to send invites to.
    TArray<FOvrId> UserIDs,
    /// Delegate to be called when the request is complete
    OvrPlatform_GroupPresence_SendInvites_Delegate&& Delegate);

DECLARE_DELEGATE_TwoParams(OvrPlatform_GroupPresence_Set_Delegate, bool, FString);

/**
 * Sets group presence information for your current app. It is recommended that you use this parameter and
 * its methods to set group presence information for your app. An example of using this parameter can be found
 * on the Group Presence overview page where the methods to set FOvrGroupPresenceOptions::DestinationApiName, FOvrGroupPresenceOptions::MatchSessionId,
 * and FOvrGroupPresenceOptions::LobbySessionId are used.
 */
void OVRPLATFORM_API OvrPlatform_GroupPresence_Set(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The groupPresenceOptions parameter contains five methods. 1. {{options.group_presence.deeplink_message_override}} - Use {{options.group_presence.lobby_session_id}} or {{options.group_presence.match_session_id}} to specify the session. Use the {{options.group_presence.deeplink_message_override}} for any additional data in whatever format you wish to aid in bringing users together. If not specified, the deeplink_message for the user will default to the one on the destination. 2.{{options.group_presence.destination_api_name}} - This the unique API Name that refers to an in-app destination. 3.{{options.group_presence.is_joinable}} - Set whether or not the person is shown as joinable or not to others. A user that is joinable can invite others to join them. Set this to false if other users would not be able to join this user. For example, the current session is full, or only the host can invite others and the current user is not the host. 4.{{options.group_presence.lobby_session_id}} - This is a session that represents a closer group/squad/party of users. It is expected that all users with the same lobby session id can see or hear each other. Users with the same lobby session id in their group presence will show up in the roster and will show up as "Recently Played With" for future invites if they aren't already Oculus friends. This must be set in addition to {{options.group_presence.is_joinable}} being true for a user to use invites. 5.{{options.group_presence.match_session_id}} - This is a session that represents all the users that are playing a specific instance of a map, game mode, round, etc. This can include users from multiple different lobbies that joined together and the users may or may not remain together after the match is over. Users with the same match session id in their group presence will not show up in the Roster, but will show up as "Recently Played with" for future invites.
    FOvrGroupPresenceOptions GroupPresenceOptions,
    /// Delegate to be called when the request is complete
    OvrPlatform_GroupPresence_Set_Delegate&& Delegate);

DECLARE_DELEGATE_TwoParams(OvrPlatform_GroupPresence_SetDeeplinkMessageOverride_Delegate, bool, FString);

/**
 * Sets the user's FOvrGroupPresenceOptions::DeeplinkMessageOverride while keeping the other group presence parameters the same.
 * If the destination of the user is not set, the deeplink message cannot be set as there's no deeplink message to override.
 * This method does not power travel from the Meta Quest platform to your app.
 * You must set a user’s FOvrGroupPresenceOptions::DestinationApiName, FOvrGroupPresenceOptions::IsJoinable status,
 * and FOvrGroupPresenceOptions::LobbySessionId to enable travel to your app. Check Group Presence overview for more information about these values.
 * Note: Instead of using this standalone API, we recommend setting all GroupPresence parameters in one call to UOvrRequestsBlueprintLibrary::GroupPresence_Set().
 */
void OVRPLATFORM_API OvrPlatform_GroupPresence_SetDeeplinkMessageOverride(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// deeplink_message is the new {{options.group_presence.deeplink_message_override}} to set for the user, overriding the current deeplink message.
    FString DeeplinkMessage,
    /// Delegate to be called when the request is complete
    OvrPlatform_GroupPresence_SetDeeplinkMessageOverride_Delegate&& Delegate);

DECLARE_DELEGATE_TwoParams(OvrPlatform_GroupPresence_SetDestination_Delegate, bool, FString);

/**
 * Replaces the user's current FOvrGroupPresenceOptions::DestinationApiName with the provided one. Use this to set a user's current destination
 * while keeping all the other Group Presence parameters the same. Setting a user's destination is required to enable travel from the Meta Quest Platform
 * to your app. NOTE instead of using the standalone API, we recommend setting all GroupPresence parameters in one call to UOvrRequestsBlueprintLibrary::GroupPresence_Set().
 * This helps ensure that all relevant presence information is singularly updated and helps reduce presence errors.
 */
void OVRPLATFORM_API OvrPlatform_GroupPresence_SetDestination(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// api_name is the unique name of the in-app desination to set, replacing the user's current {{options.group_presence.destination_api_name}}.
    FString ApiName,
    /// Delegate to be called when the request is complete
    OvrPlatform_GroupPresence_SetDestination_Delegate&& Delegate);

DECLARE_DELEGATE_TwoParams(OvrPlatform_GroupPresence_SetIsJoinable_Delegate, bool, FString);

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
void OVRPLATFORM_API OvrPlatform_GroupPresence_SetIsJoinable(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// If {{options.group_presence.is_joinable}} is true, the user can invite others to join them. If false, other users cannot join this user, for example, if the current session is full or only the host can invite others and the current user is not the host.
    bool IsJoinable,
    /// Delegate to be called when the request is complete
    OvrPlatform_GroupPresence_SetIsJoinable_Delegate&& Delegate);

DECLARE_DELEGATE_TwoParams(OvrPlatform_GroupPresence_SetLobbySession_Delegate, bool, FString);

/**
 * Replaces the user's current FOvrGroupPresenceOptions::LobbySessionId for the provided string. Use this to set a user's current
 * lobby session id while keeping all other GroupPresence parameters the same. Setting a user's lobby session id is required to enable travel
 * from the Meta Quest Platform to your app. Check Group presence overview for more information. NOTE instead of using the standalone API,
 * we recommend setting all GroupPresence parameters in one call to UOvrRequestsBlueprintLibrary::GroupPresence_Set(). This helps ensure that all relevant presence
 * information is singularly updated and helps reduce presence errors.
 */
void OVRPLATFORM_API OvrPlatform_GroupPresence_SetLobbySession(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// id is the unique identifier of the lobby session to set, replacing the user's current {{options.group_presence.lobby_session_id}}.
    FString Id,
    /// Delegate to be called when the request is complete
    OvrPlatform_GroupPresence_SetLobbySession_Delegate&& Delegate);

DECLARE_DELEGATE_TwoParams(OvrPlatform_GroupPresence_SetMatchSession_Delegate, bool, FString);

/**
 * Replaces the user's current FOvrGroupPresenceOptions::MatchSessionId for the provided one. Use this to update the user's current match session
 * id while keeping all other GroupPresence parameters the same. FOvrGroupPresenceOptions::MatchSessionId works in conjuction with
 * FOvrGroupPresenceOptions::LobbySessionId to determine if users are playing together. If a user's match and lobby session ids are the same,
 * they should be in the same multiplayer instance together. Users with the same lobby session id but different match session ids may be
 * in the same lobby for things like voice chat while in different instances in your app. WARNING match session id is often treated the same as
 * lobby session id, but this is in fact a distinct parameter and is not used for travel from the Meta Quest Platform. NOTE instead of using the standalone API,
 * we recommend setting all GroupPresence parameters in one call to UOvrRequestsBlueprintLibrary::GroupPresence_Set().
 */
void OVRPLATFORM_API OvrPlatform_GroupPresence_SetMatchSession(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// id is the unique identifier of the match session to set, replacing the user's current {{options.group_presence.match_session_id}}.
    FString Id,
    /// Delegate to be called when the request is complete
    OvrPlatform_GroupPresence_SetMatchSession_Delegate&& Delegate);

// ----------------------------------------------------------------------
// IAP

DECLARE_DELEGATE_TwoParams(OvrPlatform_IAP_ConsumePurchase_Delegate, bool, FString);

/**
 * Allow the consumable IAP product to be purchased again. Conceptually, this
 * indicates that the item was used or consumed. Important: Make sure to pass the
 * correct SKU of the purchase that will be consumed. This value is case-sensitive
 * and should match exactly with the product SKU set in the Developer Dashboard.
 */
void OVRPLATFORM_API OvrPlatform_IAP_ConsumePurchase(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The SKU of the product of the purchase that will be consumed. This value is case-sensitive and should match exactly with the product SKU set in the Developer Dashboard.
    FString Sku,
    /// Delegate to be called when the request is complete
    OvrPlatform_IAP_ConsumePurchase_Delegate&& Delegate);

typedef TSharedPtr<FOvrProductPages> FOvrProductArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_IAP_GetProductsBySKU_Delegate, bool, FOvrProductArrayPtr, FString);

/**
 * Retrieve a list of IAP products that can be purchased. Note: You must provide a list of SKUs (Stock Keeping Units)
 * to retrieve the corresponding product information. The SKUs are used to identify the products in the Oculus store,
 * which can be retrieved by accessing the Developer Dashboard or by field FOvrPurchase::SKU.
 */
void OVRPLATFORM_API OvrPlatform_IAP_GetProductsBySKU(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// An array of SKUs of the products to retrieve. Each SKU should be a string value that matches exactly with the product SKU set in the Oculus Developer Dashboard.
    TArray<FString> Skus,
    /// Delegate to be called when the request is complete
    OvrPlatform_IAP_GetProductsBySKU_Delegate&& Delegate);

typedef TSharedPtr<FOvrPurchasePages> FOvrPurchaseArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_IAP_GetViewerPurchases_Delegate, bool, FOvrPurchaseArrayPtr, FString);

/**
 * Retrieve a list of Purchase that the Logged-In-User has made. This list will
 * also contain consumable purchases that have not been consumed. Note: This method returns all purchases,
 * including consumable and non-consumable ones. If you only want to retrieve durable purchases,
 * use get_viewer_purchases_durable_cache instead.
 */
void OVRPLATFORM_API OvrPlatform_IAP_GetViewerPurchases(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// Delegate to be called when the request is complete
    OvrPlatform_IAP_GetViewerPurchases_Delegate&& Delegate);

typedef TSharedPtr<FOvrPurchasePages> FOvrPurchaseArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_IAP_GetViewerPurchasesDurableCache_Delegate, bool, FOvrPurchaseArrayPtr, FString);

/**
 * Retrieve a list of Purchase that the Logged-In-User has made. This list will only contain
 * durable purchase (non-consumable) and is populated from a device cache. Important: It is recommended
 * to use UOvrRequestsBlueprintLibrary::IAP_GetViewerPurchases() first and only check the cache if that fails. This method is intended
 * as a fallback mechanism and may not always return up-to-date results.
 */
void OVRPLATFORM_API OvrPlatform_IAP_GetViewerPurchasesDurableCache(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// Delegate to be called when the request is complete
    OvrPlatform_IAP_GetViewerPurchasesDurableCache_Delegate&& Delegate);

typedef TSharedPtr<FOvrPurchase> FOvrPurchasePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_IAP_LaunchCheckoutFlow_Delegate, bool, FOvrPurchasePtr, FString);

/**
 * Launch the checkout flow to purchase the existing product. Oculus Home tries
 * handle and fix as many errors as possible. Home returns the appropriate error
 * message and how to resolve it, if possible. Returns a purchase on success, and
 * an error on user cancellation or other errors.
 * 
 * In the case of a user cancelation, the field FOvrError::Message value will contain
 * a JSON object with a `"category"` property containing a value of `"user_canceled"`.
 */
void OVRPLATFORM_API OvrPlatform_IAP_LaunchCheckoutFlow(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// IAP sku for the item the user wishes to purchase.
    FString Sku,
    /// Delegate to be called when the request is complete
    OvrPlatform_IAP_LaunchCheckoutFlow_Delegate&& Delegate);

// ----------------------------------------------------------------------
// LanguagePack

typedef TSharedPtr<FOvrAssetDetails> FOvrAssetDetailsPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_LanguagePack_GetCurrent_Delegate, bool, FOvrAssetDetailsPtr, FString);

/**
 * Returns currently installed and selected language pack for an app in the
 * view of the FOvrAssetDetails. Use field FOvrAssetDetails::Language field to extract needed
 * language info.
 * A particular language can be download and installed by a user from
 * the Oculus app on the application page.
 */
void OVRPLATFORM_API OvrPlatform_LanguagePack_GetCurrent(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// Delegate to be called when the request is complete
    OvrPlatform_LanguagePack_GetCurrent_Delegate&& Delegate);

typedef TSharedPtr<FOvrAssetFileDownloadResult> FOvrAssetFileDownloadResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_LanguagePack_SetCurrent_Delegate, bool, FOvrAssetFileDownloadResultPtr, FString);

/**
 * Sets the current language to specified. The parameter is the BCP47 language tag.
 * If a language pack is not downloaded yet, spawns automatically the
 * UOvrRequestsBlueprintLibrary::AssetFile_DownloadByName() request, and sends periodic
 * UOvrPlatformSubsystem::OnAssetFileDownloadUpdate() to track the downloads.
 * Once the language asset file is downloaded, call UOvrRequestsBlueprintLibrary::LanguagePack_GetCurrent()
 * to retrieve the data, and use the language at runtime.
 */
void OVRPLATFORM_API OvrPlatform_LanguagePack_SetCurrent(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The BCP47 language tag that identifies the language to be set as the current language.
    FString Tag,
    /// Delegate to be called when the request is complete
    OvrPlatform_LanguagePack_SetCurrent_Delegate&& Delegate);

// ----------------------------------------------------------------------
// Leaderboard

typedef TSharedPtr<FOvrLeaderboardPages> FOvrLeaderboardArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Leaderboard_Get_Delegate, bool, FOvrLeaderboardArrayPtr, FString);

/** Retrieves detailed information for a single leaderboard with a specified name, returning an array of FOvrLeaderboard. */
void OVRPLATFORM_API OvrPlatform_Leaderboard_Get(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The name of the leaderboard to retrieve.
    FString LeaderboardName,
    /// Delegate to be called when the request is complete
    OvrPlatform_Leaderboard_Get_Delegate&& Delegate);

typedef TSharedPtr<FOvrLeaderboardEntryPages> FOvrLeaderboardEntryArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Leaderboard_GetEntries_Delegate, bool, FOvrLeaderboardEntryArrayPtr, FString);

/** Retrieves a list of leaderboard entries for a specified LeaderboardName, with options to filter and limit the number of results returned. */
void OVRPLATFORM_API OvrPlatform_Leaderboard_GetEntries(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The name of the leaderboard from which to retrieve entries.
    FString LeaderboardName,
    /// Specifies the maximum number of entries to be returned.
    int32 Limit,
    /// By using ovrLeaderboard_FilterFriends, this allows you to filter the returned values to bidirectional followers.
    EOvrLeaderboardFilterType Filter,
    /// Defines whether to center the query on the user or start at the top of the leaderboard.
    EOvrLeaderboardStartAt StartAt,
    /// Delegate to be called when the request is complete
    OvrPlatform_Leaderboard_GetEntries_Delegate&& Delegate);

typedef TSharedPtr<FOvrLeaderboardEntryPages> FOvrLeaderboardEntryArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Leaderboard_GetEntriesAfterRank_Delegate, bool, FOvrLeaderboardEntryArrayPtr, FString);

/** Retrieves a block of leaderboard entries starting from a specific rank. */
void OVRPLATFORM_API OvrPlatform_Leaderboard_GetEntriesAfterRank(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The name of the leaderboard from which to retrieve entries.
    FString LeaderboardName,
    /// The maximum number of entries to return.
    int32 Limit,
    /// The position after which to start.  For example, 10 returns leaderboard results starting with the 11th user.
    int64 AfterRank,
    /// Delegate to be called when the request is complete
    OvrPlatform_Leaderboard_GetEntriesAfterRank_Delegate&& Delegate);

typedef TSharedPtr<FOvrLeaderboardEntryPages> FOvrLeaderboardEntryArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Leaderboard_GetEntriesByIds_Delegate, bool, FOvrLeaderboardEntryArrayPtr, FString);

/** Retrieves a block of leaderboard entries that match the specified user IDs. Only entries corresponding to the provided user IDs will be returned. */
void OVRPLATFORM_API OvrPlatform_Leaderboard_GetEntriesByIds(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The name of the leaderboard from which to retrieve entries.
    FString LeaderboardName,
    /// The maximum number of entries to return.
    int32 Limit,
    /// Defines whether to center the query on the user or start at the top of the leaderboard. If this is {{enum_members.leaderboard_start_at.centered_on_viewer}} or {{enum_members.leaderboard_start_at.centered_on_viewer_or_top}}, then the current user's ID will be automatically added to the query.
    EOvrLeaderboardStartAt StartAt,
    /// Defines a list of user ids to get entries for.
    TArray<FOvrId> UserIDs,
    /// Delegate to be called when the request is complete
    OvrPlatform_Leaderboard_GetEntriesByIds_Delegate&& Delegate);

typedef TSharedPtr<FOvrLeaderboardUpdateStatus> FOvrLeaderboardUpdateStatusPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Leaderboard_WriteEntry_Delegate, bool, FOvrLeaderboardUpdateStatusPtr, FString);

/** Writes a single entry to the leaderboard, returning FOvrLeaderboardUpdateStatus indicating whether the update was successful and providing the updated challenge IDs. */
void OVRPLATFORM_API OvrPlatform_Leaderboard_WriteEntry(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The name of the leaderboard to which the entry should be written.
    FString LeaderboardName,
    /// The score to be written in the leaderboard.
    int64 Score,
    /// A 2KB custom data field that is associated with the leaderboard entry. This can be a game replay or any additional information that provides more context about the entry for the viewer.
    TArray<uint8> ExtraData,
    /// If true, the score always updates.  This happens even if it is not the user's best score.
    bool ForceUpdate,
    /// Delegate to be called when the request is complete
    OvrPlatform_Leaderboard_WriteEntry_Delegate&& Delegate);

typedef TSharedPtr<FOvrLeaderboardUpdateStatus> FOvrLeaderboardUpdateStatusPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Leaderboard_WriteEntryWithSupplementaryMetric_Delegate, bool, FOvrLeaderboardUpdateStatusPtr, FString);

/** Writes a single entry to a leaderboard which can include supplementary metrics, returning FOvrLeaderboardUpdateStatus indicating whether the update was successful and providing the updated challenge IDs. */
void OVRPLATFORM_API OvrPlatform_Leaderboard_WriteEntryWithSupplementaryMetric(
    /// Instance of the game
    UGameInstance* GameInstance,
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
    /// Delegate to be called when the request is complete
    OvrPlatform_Leaderboard_WriteEntryWithSupplementaryMetric_Delegate&& Delegate);

// ----------------------------------------------------------------------
// Media

typedef TSharedPtr<FOvrShareMediaResult> FOvrShareMediaResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Media_ShareToFacebook_Delegate, bool, FOvrShareMediaResultPtr, FString);

/**
 *  Launch the Share to Facebook modal, allowing users to share local media files to Facebook.
 * Accepts a PostTextSuggestion string for the default text of the Facebook post.
 * Requires a FilePath string as the path to the image to be shared to Facebook.
 * This image should be located in your app's internal storage directory.
 * Requires a ContentType indicating the type of media to be shared
 * (only 'photo' is currently supported).
 * The payload for the result is defined as FOvrShareMediaResult.
 */
void OVRPLATFORM_API OvrPlatform_Media_ShareToFacebook(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// this text will prepopulate the facebook status text-input box within the share modal
    FString PostTextSuggestion,
    /// path to the file to be shared to facebook
    FString FilePath,
    /// content type of the media to be shared
    EOvrMediaContentType ContentType,
    /// Delegate to be called when the request is complete
    OvrPlatform_Media_ShareToFacebook_Delegate&& Delegate);

// ----------------------------------------------------------------------
// Notification

DECLARE_DELEGATE_TwoParams(OvrPlatform_Notification_MarkAsRead_Delegate, bool, FString);

/**
 * Marks a notification as read, causing it to disappear from various surfaces such as the Universal Menu and in-app retrieval.
 * This action is useful for indicating that the user has acknowledged or acted upon the notification.
 */
void OVRPLATFORM_API OvrPlatform_Notification_MarkAsRead(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The unique identifier (UUID) of the notification to be marked as read.
    FOvrId NotificationID,
    /// Delegate to be called when the request is complete
    OvrPlatform_Notification_MarkAsRead_Delegate&& Delegate);

// ----------------------------------------------------------------------
// Party

typedef TSharedPtr<FOvrParty> FOvrPartyPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Party_GetCurrent_Delegate, bool, FOvrPartyPtr, FString);

/** Load the current party the current FOvrUser is in. The returned FOvrParty will then contain information about other users in the party and invited users. */
void OVRPLATFORM_API OvrPlatform_Party_GetCurrent(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// Delegate to be called when the request is complete
    OvrPlatform_Party_GetCurrent_Delegate&& Delegate);

// ----------------------------------------------------------------------
// RichPresence

DECLARE_DELEGATE_TwoParams(OvrPlatform_RichPresence_Clear_Delegate, bool, FString);

[[deprecated("Use UOvrRequestsBlueprintLibrary::GroupPresence_Clear()")]]
/** \deprecated Use UOvrRequestsBlueprintLibrary::GroupPresence_Clear() */
void OVRPLATFORM_API OvrPlatform_RichPresence_Clear(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// Delegate to be called when the request is complete
    OvrPlatform_RichPresence_Clear_Delegate&& Delegate);

typedef TSharedPtr<FOvrDestinationPages> FOvrDestinationArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_RichPresence_GetDestinations_Delegate, bool, FOvrDestinationArrayPtr, FString);

/** Gets all the FOvrDestination that the presence can be set to */
void OVRPLATFORM_API OvrPlatform_RichPresence_GetDestinations(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// Delegate to be called when the request is complete
    OvrPlatform_RichPresence_GetDestinations_Delegate&& Delegate);

DECLARE_DELEGATE_TwoParams(OvrPlatform_RichPresence_Set_Delegate, bool, FString);

[[deprecated("Use UOvrRequestsBlueprintLibrary::GroupPresence_Set().")]]
/** \deprecated Use UOvrRequestsBlueprintLibrary::GroupPresence_Set(). */
void OVRPLATFORM_API OvrPlatform_RichPresence_Set(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The options of the rich presence.
    FOvrRichPresenceOptions RichPresenceOptions,
    /// Delegate to be called when the request is complete
    OvrPlatform_RichPresence_Set_Delegate&& Delegate);

// ----------------------------------------------------------------------
// User

typedef TSharedPtr<FOvrUser> FOvrUserPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_User_Get_Delegate, bool, FOvrUserPtr, FString);

/**
 * Retrieve the user with the given ID. This might fail if the ID is invalid
 * or the user is blocked.
 * 
 * NOTE: Users will have a unique ID per application.
 */
void OVRPLATFORM_API OvrPlatform_User_Get(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// User ID retrieved with this application.
    FOvrId UserID,
    /// Delegate to be called when the request is complete
    OvrPlatform_User_Get_Delegate&& Delegate);

typedef TSharedPtr<FString> FStringPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_User_GetAccessToken_Delegate, bool, FStringPtr, FString);

/** Return an access token string for this user, suitable for making REST calls against graph.oculus.com. */
void OVRPLATFORM_API OvrPlatform_User_GetAccessToken(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// Delegate to be called when the request is complete
    OvrPlatform_User_GetAccessToken_Delegate&& Delegate);

typedef TSharedPtr<FOvrBlockedUserPages> FOvrBlockedUserArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_User_GetBlockedUsers_Delegate, bool, FOvrBlockedUserArrayPtr, FString);

/** Return the IDs of users entitled to use the current app that are blocked by the specified user */
void OVRPLATFORM_API OvrPlatform_User_GetBlockedUsers(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// Delegate to be called when the request is complete
    OvrPlatform_User_GetBlockedUsers_Delegate&& Delegate);

typedef TSharedPtr<FOvrUser> FOvrUserPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_User_GetLoggedInUser_Delegate, bool, FOvrUserPtr, FString);

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
void OVRPLATFORM_API OvrPlatform_User_GetLoggedInUser(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// Delegate to be called when the request is complete
    OvrPlatform_User_GetLoggedInUser_Delegate&& Delegate);

typedef TSharedPtr<FOvrUserPages> FOvrUserArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_User_GetLoggedInUserFriends_Delegate, bool, FOvrUserArrayPtr, FString);

/** Retrieve a list of the logged in user's bidirectional followers. The payload type will be an array of FOvrUser  */
void OVRPLATFORM_API OvrPlatform_User_GetLoggedInUserFriends(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// Delegate to be called when the request is complete
    OvrPlatform_User_GetLoggedInUserFriends_Delegate&& Delegate);

typedef TSharedPtr<FOvrUser> FOvrUserPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_User_GetLoggedInUserManagedInfo_Delegate, bool, FOvrUserPtr, FString);

/**
 * Retrieve the currently signed in user's managed info.  This call is not available offline.
 * 
 * NOTE: This will return data only if the logged in user is a managed Meta account (MMA).
 */
void OVRPLATFORM_API OvrPlatform_User_GetLoggedInUserManagedInfo(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// Delegate to be called when the request is complete
    OvrPlatform_User_GetLoggedInUserManagedInfo_Delegate&& Delegate);

typedef TSharedPtr<FOvrOrgScopedID> FOvrOrgScopedIDPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_User_GetOrgScopedID_Delegate, bool, FOvrOrgScopedIDPtr, FString);

/**
 * returns an ovrID which is unique per org. allows different apps within the same
 * org to identify the user. 
 */
void OVRPLATFORM_API OvrPlatform_User_GetOrgScopedID(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The id of the user that we are going to get its org scoped ID {{models.org_scoped_id}}.
    FOvrId UserID,
    /// Delegate to be called when the request is complete
    OvrPlatform_User_GetOrgScopedID_Delegate&& Delegate);

typedef TSharedPtr<TArray<FOvrSdkAccount>> FOvrSdkAccountArrayPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_User_GetSdkAccounts_Delegate, bool, FOvrSdkAccountArrayPtr, FString);

/**
 * Returns all accounts belonging to this user.
 * Accounts are the Oculus user and x-users that are linked to this user.
 */
void OVRPLATFORM_API OvrPlatform_User_GetSdkAccounts(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// Delegate to be called when the request is complete
    OvrPlatform_User_GetSdkAccounts_Delegate&& Delegate);

typedef TSharedPtr<FOvrUserProof> FOvrUserProofPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_User_GetUserProof_Delegate, bool, FOvrUserProofPtr, FString);

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
void OVRPLATFORM_API OvrPlatform_User_GetUserProof(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// Delegate to be called when the request is complete
    OvrPlatform_User_GetUserProof_Delegate&& Delegate);

typedef TSharedPtr<FOvrLaunchBlockFlowResult> FOvrLaunchBlockFlowResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_User_LaunchBlockFlow_Delegate, bool, FOvrLaunchBlockFlowResultPtr, FString);

/**
 * Launch the flow for blocking the given user. You can't follow, be followed, invited,
 *  or searched by a blocked user, for example. You can remove the block via
 *  ovr_User_LaunchUnblockFlow.
 */
void OVRPLATFORM_API OvrPlatform_User_LaunchBlockFlow(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The ID of the user that the viewer is going to launch the block flow request.
    FOvrId UserID,
    /// Delegate to be called when the request is complete
    OvrPlatform_User_LaunchBlockFlow_Delegate&& Delegate);

typedef TSharedPtr<FOvrLaunchFriendRequestFlowResult> FOvrLaunchFriendRequestFlowResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_User_LaunchFriendRequestFlow_Delegate, bool, FOvrLaunchFriendRequestFlowResultPtr, FString);

/** Launch the flow for sending a follow request to a user. */
void OVRPLATFORM_API OvrPlatform_User_LaunchFriendRequestFlow(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The ID of the target user that is going to send the friend follow request to.
    FOvrId UserID,
    /// Delegate to be called when the request is complete
    OvrPlatform_User_LaunchFriendRequestFlow_Delegate&& Delegate);

typedef TSharedPtr<FOvrLaunchUnblockFlowResult> FOvrLaunchUnblockFlowResultPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_User_LaunchUnblockFlow_Delegate, bool, FOvrLaunchUnblockFlowResultPtr, FString);

/** Launch the flow for unblocking a user that the viewer has blocked. */
void OVRPLATFORM_API OvrPlatform_User_LaunchUnblockFlow(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// The ID of the user that the viewer is going to launch the unblock flow request.
    FOvrId UserID,
    /// Delegate to be called when the request is complete
    OvrPlatform_User_LaunchUnblockFlow_Delegate&& Delegate);

// ----------------------------------------------------------------------
// UserAgeCategory

typedef TSharedPtr<FOvrUserAccountAgeCategory> FOvrUserAccountAgeCategoryPtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_UserAgeCategory_Get_Delegate, bool, FOvrUserAccountAgeCategoryPtr, FString);

/** Retrieve the user age category for the current user. It can be used in field FOvrUserAccountAgeCategory::AgeCategory */
void OVRPLATFORM_API OvrPlatform_UserAgeCategory_Get(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// Delegate to be called when the request is complete
    OvrPlatform_UserAgeCategory_Get_Delegate&& Delegate);

DECLARE_DELEGATE_TwoParams(OvrPlatform_UserAgeCategory_Report_Delegate, bool, FString);

/** Report the current user's age category to Meta. */
void OVRPLATFORM_API OvrPlatform_UserAgeCategory_Report(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// Age category for developers to send to Meta. There are two members, children age group ({{enum_members.app_age_category.ch}}) and non-children age group ({{enum_members.app_age_category.nch}}).
    EOvrAppAgeCategory AgeCategory,
    /// Delegate to be called when the request is complete
    OvrPlatform_UserAgeCategory_Report_Delegate&& Delegate);

// ----------------------------------------------------------------------
// Voip

typedef TSharedPtr<FOvrMicrophoneAvailabilityState> FOvrMicrophoneAvailabilityStatePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Voip_GetMicrophoneAvailability_Delegate, bool, FOvrMicrophoneAvailabilityStatePtr, FString);

/** Gets whether the microphone is currently available to the app. This can be used to show if the user's voice is able to be heard by other users. Returns a microphone availability state flag which determines whether it is available or not - FOvrMicrophoneAvailabilityState. */
void OVRPLATFORM_API OvrPlatform_Voip_GetMicrophoneAvailability(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// Delegate to be called when the request is complete
    OvrPlatform_Voip_GetMicrophoneAvailability_Delegate&& Delegate);

typedef TSharedPtr<FOvrSystemVoipState> FOvrSystemVoipStatePtr;
DECLARE_DELEGATE_ThreeParams(OvrPlatform_Voip_SetSystemVoipSuppressed_Delegate, bool, FOvrSystemVoipStatePtr, FString);

/**
 * Sets whether SystemVoip should be suppressed so that this app's Voip can use the microphone and play incoming Voip audio. Once microphone switching functionality for the user is released, this function will no longer work. You can use UOvrRequestsBlueprintLibrary::Voip_GetMicrophoneAvailability() to see if the user has allowed the app access to the microphone.
 * This returns a FOvrSystemVoipState object which contains statuses about whether the microphone is muted or whether passthrough is enabled.
 */
void OVRPLATFORM_API OvrPlatform_Voip_SetSystemVoipSuppressed(
    /// Instance of the game
    UGameInstance* GameInstance,
    /// A boolean indicates if the voip is supressed or not.
    bool Suppressed,
    /// Delegate to be called when the request is complete
    OvrPlatform_Voip_SetSystemVoipSuppressed_Delegate&& Delegate);

