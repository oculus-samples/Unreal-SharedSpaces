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
// FOvrAchievementDefinitionPages paged array.

bool OvrPlatform_AchievementDefinitionPages_GetPageEntries(
    const FOvrAchievementDefinitionPages& AchievementDefinitionPages,
    TArray<FOvrAchievementDefinition>& Current);

bool OvrPlatform_AchievementDefinitionPages_HasNextPage(
    const FOvrAchievementDefinitionPages& AchievementDefinitionPages);

DECLARE_DELEGATE_ThreeParams(OvrPlatform_AchievementDefinitionPage_Delegate, bool, FOvrAchievementDefinitionPages, FString);

bool OvrPlatform_AchievementDefinitionPages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrAchievementDefinitionPages& AchievementDefinitionPages,
    OvrPlatform_AchievementDefinitionPage_Delegate&& Delegate);

// ----------------------------------------------------------------------
// FOvrAchievementProgressPages paged array.

bool OvrPlatform_AchievementProgressPages_GetPageEntries(
    const FOvrAchievementProgressPages& AchievementProgressPages,
    TArray<FOvrAchievementProgress>& Current);

bool OvrPlatform_AchievementProgressPages_HasNextPage(
    const FOvrAchievementProgressPages& AchievementProgressPages);

DECLARE_DELEGATE_ThreeParams(OvrPlatform_AchievementProgressPage_Delegate, bool, FOvrAchievementProgressPages, FString);

bool OvrPlatform_AchievementProgressPages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrAchievementProgressPages& AchievementProgressPages,
    OvrPlatform_AchievementProgressPage_Delegate&& Delegate);

// ----------------------------------------------------------------------
// FOvrChallengePages paged array.

bool OvrPlatform_ChallengePages_GetPageEntries(
    const FOvrChallengePages& ChallengePages,
    TArray<FOvrChallenge>& Current);

bool OvrPlatform_ChallengePages_HasNextPage(
    const FOvrChallengePages& ChallengePages);

bool OvrPlatform_ChallengePages_HasPreviousPage(
    const FOvrChallengePages& ChallengePages);

DECLARE_DELEGATE_ThreeParams(OvrPlatform_ChallengePage_Delegate, bool, FOvrChallengePages, FString);

bool OvrPlatform_ChallengePages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrChallengePages& ChallengePages,
    OvrPlatform_ChallengePage_Delegate&& Delegate);

bool OvrPlatform_ChallengePages_FetchPreviousPage(
    UGameInstance* GameInstance,
    const FOvrChallengePages& ChallengePages,
    OvrPlatform_ChallengePage_Delegate&& Delegate);

// ----------------------------------------------------------------------
// FOvrChallengeEntryPages paged array.

bool OvrPlatform_ChallengeEntryPages_GetPageEntries(
    const FOvrChallengeEntryPages& ChallengeEntryPages,
    TArray<FOvrChallengeEntry>& Current);

bool OvrPlatform_ChallengeEntryPages_HasNextPage(
    const FOvrChallengeEntryPages& ChallengeEntryPages);

bool OvrPlatform_ChallengeEntryPages_HasPreviousPage(
    const FOvrChallengeEntryPages& ChallengeEntryPages);

DECLARE_DELEGATE_ThreeParams(OvrPlatform_ChallengeEntryPage_Delegate, bool, FOvrChallengeEntryPages, FString);

bool OvrPlatform_ChallengeEntryPages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrChallengeEntryPages& ChallengeEntryPages,
    OvrPlatform_ChallengeEntryPage_Delegate&& Delegate);

bool OvrPlatform_ChallengeEntryPages_FetchPreviousPage(
    UGameInstance* GameInstance,
    const FOvrChallengeEntryPages& ChallengeEntryPages,
    OvrPlatform_ChallengeEntryPage_Delegate&& Delegate);

// ----------------------------------------------------------------------
// FOvrCloudStorageMetadataPages paged array.

bool OvrPlatform_CloudStorageMetadataPages_GetPageEntries(
    const FOvrCloudStorageMetadataPages& CloudStorageMetadataPages,
    TArray<FOvrCloudStorageMetadata>& Current);

bool OvrPlatform_CloudStorageMetadataPages_HasNextPage(
    const FOvrCloudStorageMetadataPages& CloudStorageMetadataPages);

DECLARE_DELEGATE_ThreeParams(OvrPlatform_CloudStorageMetadataPage_Delegate, bool, FOvrCloudStorageMetadataPages, FString);

bool OvrPlatform_CloudStorageMetadataPages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrCloudStorageMetadataPages& CloudStorageMetadataPages,
    OvrPlatform_CloudStorageMetadataPage_Delegate&& Delegate);

// ----------------------------------------------------------------------
// FOvrDestinationPages paged array.

bool OvrPlatform_DestinationPages_GetPageEntries(
    const FOvrDestinationPages& DestinationPages,
    TArray<FOvrDestination>& Current);

bool OvrPlatform_DestinationPages_HasNextPage(
    const FOvrDestinationPages& DestinationPages);

DECLARE_DELEGATE_ThreeParams(OvrPlatform_DestinationPage_Delegate, bool, FOvrDestinationPages, FString);

bool OvrPlatform_DestinationPages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrDestinationPages& DestinationPages,
    OvrPlatform_DestinationPage_Delegate&& Delegate);

// ----------------------------------------------------------------------
// FOvrLeaderboardPages paged array.

bool OvrPlatform_LeaderboardPages_GetPageEntries(
    const FOvrLeaderboardPages& LeaderboardPages,
    TArray<FOvrLeaderboard>& Current);

bool OvrPlatform_LeaderboardPages_HasNextPage(
    const FOvrLeaderboardPages& LeaderboardPages);

DECLARE_DELEGATE_ThreeParams(OvrPlatform_LeaderboardPage_Delegate, bool, FOvrLeaderboardPages, FString);

bool OvrPlatform_LeaderboardPages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrLeaderboardPages& LeaderboardPages,
    OvrPlatform_LeaderboardPage_Delegate&& Delegate);

// ----------------------------------------------------------------------
// FOvrLeaderboardEntryPages paged array.

bool OvrPlatform_LeaderboardEntryPages_GetPageEntries(
    const FOvrLeaderboardEntryPages& LeaderboardEntryPages,
    TArray<FOvrLeaderboardEntry>& Current);

bool OvrPlatform_LeaderboardEntryPages_HasNextPage(
    const FOvrLeaderboardEntryPages& LeaderboardEntryPages);

bool OvrPlatform_LeaderboardEntryPages_HasPreviousPage(
    const FOvrLeaderboardEntryPages& LeaderboardEntryPages);

DECLARE_DELEGATE_ThreeParams(OvrPlatform_LeaderboardEntryPage_Delegate, bool, FOvrLeaderboardEntryPages, FString);

bool OvrPlatform_LeaderboardEntryPages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrLeaderboardEntryPages& LeaderboardEntryPages,
    OvrPlatform_LeaderboardEntryPage_Delegate&& Delegate);

bool OvrPlatform_LeaderboardEntryPages_FetchPreviousPage(
    UGameInstance* GameInstance,
    const FOvrLeaderboardEntryPages& LeaderboardEntryPages,
    OvrPlatform_LeaderboardEntryPage_Delegate&& Delegate);

// ----------------------------------------------------------------------
// FOvrProductPages paged array.

bool OvrPlatform_ProductPages_GetPageEntries(
    const FOvrProductPages& ProductPages,
    TArray<FOvrProduct>& Current);

bool OvrPlatform_ProductPages_HasNextPage(
    const FOvrProductPages& ProductPages);

DECLARE_DELEGATE_ThreeParams(OvrPlatform_ProductPage_Delegate, bool, FOvrProductPages, FString);

bool OvrPlatform_ProductPages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrProductPages& ProductPages,
    OvrPlatform_ProductPage_Delegate&& Delegate);

// ----------------------------------------------------------------------
// FOvrPurchasePages paged array.

bool OvrPlatform_PurchasePages_GetPageEntries(
    const FOvrPurchasePages& PurchasePages,
    TArray<FOvrPurchase>& Current);

bool OvrPlatform_PurchasePages_HasNextPage(
    const FOvrPurchasePages& PurchasePages);

DECLARE_DELEGATE_ThreeParams(OvrPlatform_PurchasePage_Delegate, bool, FOvrPurchasePages, FString);

bool OvrPlatform_PurchasePages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrPurchasePages& PurchasePages,
    OvrPlatform_PurchasePage_Delegate&& Delegate);

// ----------------------------------------------------------------------
// FOvrRoomPages paged array.

bool OvrPlatform_RoomPages_GetPageEntries(
    const FOvrRoomPages& RoomPages,
    TArray<FOvrRoom>& Current);

bool OvrPlatform_RoomPages_HasNextPage(
    const FOvrRoomPages& RoomPages);

DECLARE_DELEGATE_ThreeParams(OvrPlatform_RoomPage_Delegate, bool, FOvrRoomPages, FString);

bool OvrPlatform_RoomPages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrRoomPages& RoomPages,
    OvrPlatform_RoomPage_Delegate&& Delegate);

// ----------------------------------------------------------------------
// FOvrRoomInviteNotificationPages paged array.

bool OvrPlatform_RoomInviteNotificationPages_GetPageEntries(
    const FOvrRoomInviteNotificationPages& RoomInviteNotificationPages,
    TArray<FOvrRoomInviteNotification>& Current);

bool OvrPlatform_RoomInviteNotificationPages_HasNextPage(
    const FOvrRoomInviteNotificationPages& RoomInviteNotificationPages);

DECLARE_DELEGATE_ThreeParams(OvrPlatform_RoomInviteNotificationPage_Delegate, bool, FOvrRoomInviteNotificationPages, FString);

bool OvrPlatform_RoomInviteNotificationPages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrRoomInviteNotificationPages& RoomInviteNotificationPages,
    OvrPlatform_RoomInviteNotificationPage_Delegate&& Delegate);

// ----------------------------------------------------------------------
// FOvrUserAndRoomPages paged array.

bool OvrPlatform_UserAndRoomPages_GetPageEntries(
    const FOvrUserAndRoomPages& UserAndRoomPages,
    TArray<FOvrUserAndRoom>& Current);

bool OvrPlatform_UserAndRoomPages_HasNextPage(
    const FOvrUserAndRoomPages& UserAndRoomPages);

DECLARE_DELEGATE_ThreeParams(OvrPlatform_UserAndRoomPage_Delegate, bool, FOvrUserAndRoomPages, FString);

bool OvrPlatform_UserAndRoomPages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrUserAndRoomPages& UserAndRoomPages,
    OvrPlatform_UserAndRoomPage_Delegate&& Delegate);

// ----------------------------------------------------------------------
// FOvrUserPages paged array.

bool OvrPlatform_UserPages_GetPageEntries(
    const FOvrUserPages& UserPages,
    TArray<FOvrUser>& Current);

bool OvrPlatform_UserPages_HasNextPage(
    const FOvrUserPages& UserPages);

DECLARE_DELEGATE_ThreeParams(OvrPlatform_UserPage_Delegate, bool, FOvrUserPages, FString);

bool OvrPlatform_UserPages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrUserPages& UserPages,
    OvrPlatform_UserPage_Delegate&& Delegate);

