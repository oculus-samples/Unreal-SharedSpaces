// Copyright (c) Meta Platforms, Inc. and affiliates.

// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#pragma once

#include "CoreMinimal.h"

#include "OVRPlatformModels.h"
#include "OVRPlatformOptions.h"
#include "OVRPlatformRequestsSupport.h"

// ----------------------------------------------------------------------
// FOvrAchievementDefinitionPages paged array.

bool OVRPLATFORM_API OvrPlatform_AchievementDefinitionPages_GetPageEntries(
    const FOvrAchievementDefinitionPages& AchievementDefinitionPages,
    TArray<FOvrAchievementDefinition>& Current);

bool OVRPLATFORM_API OvrPlatform_AchievementDefinitionPages_HasNextPage(
    const FOvrAchievementDefinitionPages& AchievementDefinitionPages);

DECLARE_DELEGATE_ThreeParams(OvrPlatform_AchievementDefinitionPage_Delegate, bool, FOvrAchievementDefinitionPages, FString);

bool OVRPLATFORM_API OvrPlatform_AchievementDefinitionPages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrAchievementDefinitionPages& AchievementDefinitionPages,
    OvrPlatform_AchievementDefinitionPage_Delegate&& Delegate);

// ----------------------------------------------------------------------
// FOvrAchievementProgressPages paged array.

bool OVRPLATFORM_API OvrPlatform_AchievementProgressPages_GetPageEntries(
    const FOvrAchievementProgressPages& AchievementProgressPages,
    TArray<FOvrAchievementProgress>& Current);

bool OVRPLATFORM_API OvrPlatform_AchievementProgressPages_HasNextPage(
    const FOvrAchievementProgressPages& AchievementProgressPages);

DECLARE_DELEGATE_ThreeParams(OvrPlatform_AchievementProgressPage_Delegate, bool, FOvrAchievementProgressPages, FString);

bool OVRPLATFORM_API OvrPlatform_AchievementProgressPages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrAchievementProgressPages& AchievementProgressPages,
    OvrPlatform_AchievementProgressPage_Delegate&& Delegate);

// ----------------------------------------------------------------------
// FOvrApplicationInvitePages paged array.

bool OVRPLATFORM_API OvrPlatform_ApplicationInvitePages_GetPageEntries(
    const FOvrApplicationInvitePages& ApplicationInvitePages,
    TArray<FOvrApplicationInvite>& Current);

bool OVRPLATFORM_API OvrPlatform_ApplicationInvitePages_HasNextPage(
    const FOvrApplicationInvitePages& ApplicationInvitePages);

DECLARE_DELEGATE_ThreeParams(OvrPlatform_ApplicationInvitePage_Delegate, bool, FOvrApplicationInvitePages, FString);

bool OVRPLATFORM_API OvrPlatform_ApplicationInvitePages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrApplicationInvitePages& ApplicationInvitePages,
    OvrPlatform_ApplicationInvitePage_Delegate&& Delegate);

// ----------------------------------------------------------------------
// FOvrBlockedUserPages paged array.

bool OVRPLATFORM_API OvrPlatform_BlockedUserPages_GetPageEntries(
    const FOvrBlockedUserPages& BlockedUserPages,
    TArray<FOvrBlockedUser>& Current);

bool OVRPLATFORM_API OvrPlatform_BlockedUserPages_HasNextPage(
    const FOvrBlockedUserPages& BlockedUserPages);

DECLARE_DELEGATE_ThreeParams(OvrPlatform_BlockedUserPage_Delegate, bool, FOvrBlockedUserPages, FString);

bool OVRPLATFORM_API OvrPlatform_BlockedUserPages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrBlockedUserPages& BlockedUserPages,
    OvrPlatform_BlockedUserPage_Delegate&& Delegate);

// ----------------------------------------------------------------------
// FOvrChallengePages paged array.

bool OVRPLATFORM_API OvrPlatform_ChallengePages_GetPageEntries(
    const FOvrChallengePages& ChallengePages,
    TArray<FOvrChallenge>& Current);

bool OVRPLATFORM_API OvrPlatform_ChallengePages_HasNextPage(
    const FOvrChallengePages& ChallengePages);

bool OVRPLATFORM_API OvrPlatform_ChallengePages_HasPreviousPage(
    const FOvrChallengePages& ChallengePages);

DECLARE_DELEGATE_ThreeParams(OvrPlatform_ChallengePage_Delegate, bool, FOvrChallengePages, FString);

bool OVRPLATFORM_API OvrPlatform_ChallengePages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrChallengePages& ChallengePages,
    OvrPlatform_ChallengePage_Delegate&& Delegate);

bool OVRPLATFORM_API OvrPlatform_ChallengePages_FetchPreviousPage(
    UGameInstance* GameInstance,
    const FOvrChallengePages& ChallengePages,
    OvrPlatform_ChallengePage_Delegate&& Delegate);

// ----------------------------------------------------------------------
// FOvrChallengeEntryPages paged array.

bool OVRPLATFORM_API OvrPlatform_ChallengeEntryPages_GetPageEntries(
    const FOvrChallengeEntryPages& ChallengeEntryPages,
    TArray<FOvrChallengeEntry>& Current);

bool OVRPLATFORM_API OvrPlatform_ChallengeEntryPages_HasNextPage(
    const FOvrChallengeEntryPages& ChallengeEntryPages);

bool OVRPLATFORM_API OvrPlatform_ChallengeEntryPages_HasPreviousPage(
    const FOvrChallengeEntryPages& ChallengeEntryPages);

DECLARE_DELEGATE_ThreeParams(OvrPlatform_ChallengeEntryPage_Delegate, bool, FOvrChallengeEntryPages, FString);

bool OVRPLATFORM_API OvrPlatform_ChallengeEntryPages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrChallengeEntryPages& ChallengeEntryPages,
    OvrPlatform_ChallengeEntryPage_Delegate&& Delegate);

bool OVRPLATFORM_API OvrPlatform_ChallengeEntryPages_FetchPreviousPage(
    UGameInstance* GameInstance,
    const FOvrChallengeEntryPages& ChallengeEntryPages,
    OvrPlatform_ChallengeEntryPage_Delegate&& Delegate);

// ----------------------------------------------------------------------
// FOvrCowatchViewerPages paged array.

bool OVRPLATFORM_API OvrPlatform_CowatchViewerPages_GetPageEntries(
    const FOvrCowatchViewerPages& CowatchViewerPages,
    TArray<FOvrCowatchViewer>& Current);

bool OVRPLATFORM_API OvrPlatform_CowatchViewerPages_HasNextPage(
    const FOvrCowatchViewerPages& CowatchViewerPages);

DECLARE_DELEGATE_ThreeParams(OvrPlatform_CowatchViewerPage_Delegate, bool, FOvrCowatchViewerPages, FString);

bool OVRPLATFORM_API OvrPlatform_CowatchViewerPages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrCowatchViewerPages& CowatchViewerPages,
    OvrPlatform_CowatchViewerPage_Delegate&& Delegate);

// ----------------------------------------------------------------------
// FOvrDestinationPages paged array.

bool OVRPLATFORM_API OvrPlatform_DestinationPages_GetPageEntries(
    const FOvrDestinationPages& DestinationPages,
    TArray<FOvrDestination>& Current);

bool OVRPLATFORM_API OvrPlatform_DestinationPages_HasNextPage(
    const FOvrDestinationPages& DestinationPages);

DECLARE_DELEGATE_ThreeParams(OvrPlatform_DestinationPage_Delegate, bool, FOvrDestinationPages, FString);

bool OVRPLATFORM_API OvrPlatform_DestinationPages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrDestinationPages& DestinationPages,
    OvrPlatform_DestinationPage_Delegate&& Delegate);

// ----------------------------------------------------------------------
// FOvrLeaderboardPages paged array.

bool OVRPLATFORM_API OvrPlatform_LeaderboardPages_GetPageEntries(
    const FOvrLeaderboardPages& LeaderboardPages,
    TArray<FOvrLeaderboard>& Current);

bool OVRPLATFORM_API OvrPlatform_LeaderboardPages_HasNextPage(
    const FOvrLeaderboardPages& LeaderboardPages);

DECLARE_DELEGATE_ThreeParams(OvrPlatform_LeaderboardPage_Delegate, bool, FOvrLeaderboardPages, FString);

bool OVRPLATFORM_API OvrPlatform_LeaderboardPages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrLeaderboardPages& LeaderboardPages,
    OvrPlatform_LeaderboardPage_Delegate&& Delegate);

// ----------------------------------------------------------------------
// FOvrLeaderboardEntryPages paged array.

bool OVRPLATFORM_API OvrPlatform_LeaderboardEntryPages_GetPageEntries(
    const FOvrLeaderboardEntryPages& LeaderboardEntryPages,
    TArray<FOvrLeaderboardEntry>& Current);

bool OVRPLATFORM_API OvrPlatform_LeaderboardEntryPages_HasNextPage(
    const FOvrLeaderboardEntryPages& LeaderboardEntryPages);

bool OVRPLATFORM_API OvrPlatform_LeaderboardEntryPages_HasPreviousPage(
    const FOvrLeaderboardEntryPages& LeaderboardEntryPages);

DECLARE_DELEGATE_ThreeParams(OvrPlatform_LeaderboardEntryPage_Delegate, bool, FOvrLeaderboardEntryPages, FString);

bool OVRPLATFORM_API OvrPlatform_LeaderboardEntryPages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrLeaderboardEntryPages& LeaderboardEntryPages,
    OvrPlatform_LeaderboardEntryPage_Delegate&& Delegate);

bool OVRPLATFORM_API OvrPlatform_LeaderboardEntryPages_FetchPreviousPage(
    UGameInstance* GameInstance,
    const FOvrLeaderboardEntryPages& LeaderboardEntryPages,
    OvrPlatform_LeaderboardEntryPage_Delegate&& Delegate);

// ----------------------------------------------------------------------
// FOvrProductPages paged array.

bool OVRPLATFORM_API OvrPlatform_ProductPages_GetPageEntries(
    const FOvrProductPages& ProductPages,
    TArray<FOvrProduct>& Current);

bool OVRPLATFORM_API OvrPlatform_ProductPages_HasNextPage(
    const FOvrProductPages& ProductPages);

DECLARE_DELEGATE_ThreeParams(OvrPlatform_ProductPage_Delegate, bool, FOvrProductPages, FString);

bool OVRPLATFORM_API OvrPlatform_ProductPages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrProductPages& ProductPages,
    OvrPlatform_ProductPage_Delegate&& Delegate);

// ----------------------------------------------------------------------
// FOvrPurchasePages paged array.

bool OVRPLATFORM_API OvrPlatform_PurchasePages_GetPageEntries(
    const FOvrPurchasePages& PurchasePages,
    TArray<FOvrPurchase>& Current);

bool OVRPLATFORM_API OvrPlatform_PurchasePages_HasNextPage(
    const FOvrPurchasePages& PurchasePages);

DECLARE_DELEGATE_ThreeParams(OvrPlatform_PurchasePage_Delegate, bool, FOvrPurchasePages, FString);

bool OVRPLATFORM_API OvrPlatform_PurchasePages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrPurchasePages& PurchasePages,
    OvrPlatform_PurchasePage_Delegate&& Delegate);

// ----------------------------------------------------------------------
// FOvrUserPages paged array.

bool OVRPLATFORM_API OvrPlatform_UserPages_GetPageEntries(
    const FOvrUserPages& UserPages,
    TArray<FOvrUser>& Current);

bool OVRPLATFORM_API OvrPlatform_UserPages_HasNextPage(
    const FOvrUserPages& UserPages);

DECLARE_DELEGATE_ThreeParams(OvrPlatform_UserPage_Delegate, bool, FOvrUserPages, FString);

bool OVRPLATFORM_API OvrPlatform_UserPages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrUserPages& UserPages,
    OvrPlatform_UserPage_Delegate&& Delegate);

// ----------------------------------------------------------------------
// FOvrUserCapabilityPages paged array.

bool OVRPLATFORM_API OvrPlatform_UserCapabilityPages_GetPageEntries(
    const FOvrUserCapabilityPages& UserCapabilityPages,
    TArray<FOvrUserCapability>& Current);

bool OVRPLATFORM_API OvrPlatform_UserCapabilityPages_HasNextPage(
    const FOvrUserCapabilityPages& UserCapabilityPages);

DECLARE_DELEGATE_ThreeParams(OvrPlatform_UserCapabilityPage_Delegate, bool, FOvrUserCapabilityPages, FString);

bool OVRPLATFORM_API OvrPlatform_UserCapabilityPages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrUserCapabilityPages& UserCapabilityPages,
    OvrPlatform_UserCapabilityPage_Delegate&& Delegate);

