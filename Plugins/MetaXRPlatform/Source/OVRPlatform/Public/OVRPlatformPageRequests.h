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
#include "OVRPlatformRequestsSupport.h"

#include "OVRPlatformPageRequests.generated.h"

UENUM(BlueprintType)
enum class EOvrForwardArrayIteratorInputPins: uint8
{
    /** Returns the current page of the array. */
    Execute,
    /** Requests the next page of the array. */
    NextPage,
};

UENUM(BlueprintType)
enum class EOvrBidirectionalArrayIteratorInputPins: uint8
{
    /** Returns the current page of the array. */
    Execute,
    /** Requests the next page of the array. */
    NextPage,
    /** Requests the previous page of the array. */
    PreviousPage,
};

UCLASS()
class OVRPLATFORM_API UOvrPageRequestsBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    /**
     * Fetches a page from an FOvrAchievementDefinitionPages paged array.
     * @param AchievementDefinitionPages - a FOvrAchievementDefinitionPages
     * @param AchievementDefinitionArray - an array of FOvrAchievementDefinition
     * @param bHasNextPage - if more pages are available after this one.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "InExecs,OutExecs", AutoCreateRefTerm="AchievementDefinitionPages"), Category = "OvrPlatform|Models|AchievementDefinitionArray")
    static void FetchAchievementDefinitionPage(
        UObject* WorldContextObject,
        const EOvrForwardArrayIteratorInputPins& InExecs,
        EOvrPageRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        const FOvrAchievementDefinitionPages& AchievementDefinitionPages,
        TArray<FOvrAchievementDefinition>& AchievementDefinitionArray,
        bool& bHasNextPage,
        FString& ErrorMsg);

    /**
     * Fetches a page from an FOvrAchievementProgressPages paged array.
     * @param AchievementProgressPages - a FOvrAchievementProgressPages
     * @param AchievementProgressArray - an array of FOvrAchievementProgress
     * @param bHasNextPage - if more pages are available after this one.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "InExecs,OutExecs", AutoCreateRefTerm="AchievementProgressPages"), Category = "OvrPlatform|Models|AchievementProgressArray")
    static void FetchAchievementProgressPage(
        UObject* WorldContextObject,
        const EOvrForwardArrayIteratorInputPins& InExecs,
        EOvrPageRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        const FOvrAchievementProgressPages& AchievementProgressPages,
        TArray<FOvrAchievementProgress>& AchievementProgressArray,
        bool& bHasNextPage,
        FString& ErrorMsg);

    /**
     * Fetches a page from an FOvrApplicationInvitePages paged array.
     * @param ApplicationInvitePages - a FOvrApplicationInvitePages
     * @param ApplicationInviteArray - an array of FOvrApplicationInvite
     * @param bHasNextPage - if more pages are available after this one.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "InExecs,OutExecs", AutoCreateRefTerm="ApplicationInvitePages"), Category = "OvrPlatform|Models|ApplicationInviteArray")
    static void FetchApplicationInvitePage(
        UObject* WorldContextObject,
        const EOvrForwardArrayIteratorInputPins& InExecs,
        EOvrPageRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        const FOvrApplicationInvitePages& ApplicationInvitePages,
        TArray<FOvrApplicationInvite>& ApplicationInviteArray,
        bool& bHasNextPage,
        FString& ErrorMsg);

    /**
     * Fetches a page from an FOvrBlockedUserPages paged array.
     * @param BlockedUserPages - a FOvrBlockedUserPages
     * @param BlockedUserArray - an array of FOvrBlockedUser
     * @param bHasNextPage - if more pages are available after this one.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "InExecs,OutExecs", AutoCreateRefTerm="BlockedUserPages"), Category = "OvrPlatform|Models|BlockedUserArray")
    static void FetchBlockedUserPage(
        UObject* WorldContextObject,
        const EOvrForwardArrayIteratorInputPins& InExecs,
        EOvrPageRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        const FOvrBlockedUserPages& BlockedUserPages,
        TArray<FOvrBlockedUser>& BlockedUserArray,
        bool& bHasNextPage,
        FString& ErrorMsg);

    /**
     * Fetches a page from a bidirectional FOvrChallengePages paged array.
     * @param ChallengePages - a FOvrChallengePages
     * @param ChallengeArray - an array of FOvrChallenge
     * @param bHasNextPage - if more pages are available after this one.
     * @param bHasPreviousPage - if more pages are available before this one.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "InExecs,OutExecs", AutoCreateRefTerm="ChallengePages"), Category = "OvrPlatform|Models|ChallengeArray")
    static void FetchChallengePage(
        UObject* WorldContextObject,
        const EOvrBidirectionalArrayIteratorInputPins& InExecs,
        EOvrPageRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        const FOvrChallengePages& ChallengePages,
        TArray<FOvrChallenge>& ChallengeArray,
        bool& bHasNextPage,
        bool& bHasPreviousPage,
        FString& ErrorMsg);

    /**
     * Fetches a page from a bidirectional FOvrChallengeEntryPages paged array.
     * @param ChallengeEntryPages - a FOvrChallengeEntryPages
     * @param ChallengeEntryArray - an array of FOvrChallengeEntry
     * @param bHasNextPage - if more pages are available after this one.
     * @param bHasPreviousPage - if more pages are available before this one.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "InExecs,OutExecs", AutoCreateRefTerm="ChallengeEntryPages"), Category = "OvrPlatform|Models|ChallengeEntryArray")
    static void FetchChallengeEntryPage(
        UObject* WorldContextObject,
        const EOvrBidirectionalArrayIteratorInputPins& InExecs,
        EOvrPageRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        const FOvrChallengeEntryPages& ChallengeEntryPages,
        TArray<FOvrChallengeEntry>& ChallengeEntryArray,
        bool& bHasNextPage,
        bool& bHasPreviousPage,
        FString& ErrorMsg);

    /**
     * Fetches a page from an FOvrDestinationPages paged array.
     * @param DestinationPages - a FOvrDestinationPages
     * @param DestinationArray - an array of FOvrDestination
     * @param bHasNextPage - if more pages are available after this one.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "InExecs,OutExecs", AutoCreateRefTerm="DestinationPages"), Category = "OvrPlatform|Models|DestinationArray")
    static void FetchDestinationPage(
        UObject* WorldContextObject,
        const EOvrForwardArrayIteratorInputPins& InExecs,
        EOvrPageRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        const FOvrDestinationPages& DestinationPages,
        TArray<FOvrDestination>& DestinationArray,
        bool& bHasNextPage,
        FString& ErrorMsg);

    /**
     * Fetches a page from an FOvrLeaderboardPages paged array.
     * @param LeaderboardPages - a FOvrLeaderboardPages
     * @param LeaderboardArray - an array of FOvrLeaderboard
     * @param bHasNextPage - if more pages are available after this one.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "InExecs,OutExecs", AutoCreateRefTerm="LeaderboardPages"), Category = "OvrPlatform|Models|LeaderboardArray")
    static void FetchLeaderboardPage(
        UObject* WorldContextObject,
        const EOvrForwardArrayIteratorInputPins& InExecs,
        EOvrPageRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        const FOvrLeaderboardPages& LeaderboardPages,
        TArray<FOvrLeaderboard>& LeaderboardArray,
        bool& bHasNextPage,
        FString& ErrorMsg);

    /**
     * Fetches a page from a bidirectional FOvrLeaderboardEntryPages paged array.
     * @param LeaderboardEntryPages - a FOvrLeaderboardEntryPages
     * @param LeaderboardEntryArray - an array of FOvrLeaderboardEntry
     * @param bHasNextPage - if more pages are available after this one.
     * @param bHasPreviousPage - if more pages are available before this one.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "InExecs,OutExecs", AutoCreateRefTerm="LeaderboardEntryPages"), Category = "OvrPlatform|Models|LeaderboardEntryArray")
    static void FetchLeaderboardEntryPage(
        UObject* WorldContextObject,
        const EOvrBidirectionalArrayIteratorInputPins& InExecs,
        EOvrPageRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        const FOvrLeaderboardEntryPages& LeaderboardEntryPages,
        TArray<FOvrLeaderboardEntry>& LeaderboardEntryArray,
        bool& bHasNextPage,
        bool& bHasPreviousPage,
        FString& ErrorMsg);

    /**
     * Fetches a page from an FOvrProductPages paged array.
     * @param ProductPages - a FOvrProductPages
     * @param ProductArray - an array of FOvrProduct
     * @param bHasNextPage - if more pages are available after this one.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "InExecs,OutExecs", AutoCreateRefTerm="ProductPages"), Category = "OvrPlatform|Models|ProductArray")
    static void FetchProductPage(
        UObject* WorldContextObject,
        const EOvrForwardArrayIteratorInputPins& InExecs,
        EOvrPageRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        const FOvrProductPages& ProductPages,
        TArray<FOvrProduct>& ProductArray,
        bool& bHasNextPage,
        FString& ErrorMsg);

    /**
     * Fetches a page from an FOvrPurchasePages paged array.
     * @param PurchasePages - a FOvrPurchasePages
     * @param PurchaseArray - an array of FOvrPurchase
     * @param bHasNextPage - if more pages are available after this one.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "InExecs,OutExecs", AutoCreateRefTerm="PurchasePages"), Category = "OvrPlatform|Models|PurchaseArray")
    static void FetchPurchasePage(
        UObject* WorldContextObject,
        const EOvrForwardArrayIteratorInputPins& InExecs,
        EOvrPageRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        const FOvrPurchasePages& PurchasePages,
        TArray<FOvrPurchase>& PurchaseArray,
        bool& bHasNextPage,
        FString& ErrorMsg);

    /**
     * Fetches a page from an FOvrUserPages paged array.
     * @param UserPages - a FOvrUserPages
     * @param UserArray - an array of FOvrUser
     * @param bHasNextPage - if more pages are available after this one.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "InExecs,OutExecs", AutoCreateRefTerm="UserPages"), Category = "OvrPlatform|Models|UserArray")
    static void FetchUserPage(
        UObject* WorldContextObject,
        const EOvrForwardArrayIteratorInputPins& InExecs,
        EOvrPageRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        const FOvrUserPages& UserPages,
        TArray<FOvrUser>& UserArray,
        bool& bHasNextPage,
        FString& ErrorMsg);

    /**
     * Fetches a page from an FOvrUserCapabilityPages paged array.
     * @param UserCapabilityPages - a FOvrUserCapabilityPages
     * @param UserCapabilityArray - an array of FOvrUserCapability
     * @param bHasNextPage - if more pages are available after this one.
     */
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject", ExpandEnumAsExecs = "InExecs,OutExecs", AutoCreateRefTerm="UserCapabilityPages"), Category = "OvrPlatform|Models|UserCapabilityArray")
    static void FetchUserCapabilityPage(
        UObject* WorldContextObject,
        const EOvrForwardArrayIteratorInputPins& InExecs,
        EOvrPageRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        const FOvrUserCapabilityPages& UserCapabilityPages,
        TArray<FOvrUserCapability>& UserCapabilityArray,
        bool& bHasNextPage,
        FString& ErrorMsg);
};
