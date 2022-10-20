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

#include "OVRPlatformCppPageRequests.h"
#include "OVRPlatformRequestsConverters.h"
#include "OVRPlatformOptionsConverters.h"

#include "OVRPlatformSubsystem.h"

// ----------------------------------------------------------------------
// FOvrAchievementDefinitionPages paged array.

bool OvrPlatform_AchievementDefinitionPages_GetPageEntries(
    const FOvrAchievementDefinitionPages& AchievementDefinitionPages,
    TArray<FOvrAchievementDefinition>& Current)
{
    size_t Size = ovr_AchievementDefinitionArray_GetSize(AchievementDefinitionPages.PagedArrayHandle);
    Current.Empty(Size);
    for (size_t Index = 0; Index < Size; ++Index)
    {
        Current.Add(FOvrAchievementDefinition(ovr_AchievementDefinitionArray_GetElement(AchievementDefinitionPages.PagedArrayHandle, Index), AchievementDefinitionPages.PagedArrayMessageHandlePtr));
    }

    return Size > 0;
}

bool OvrPlatform_AchievementDefinitionPages_HasNextPage(
    const FOvrAchievementDefinitionPages& AchievementDefinitionPages)
{
    return ovr_AchievementDefinitionArray_HasNextPage(AchievementDefinitionPages.PagedArrayHandle);
}

bool OvrPlatform_AchievementDefinitionPages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrAchievementDefinitionPages& AchievementDefinitionPages,
    OvrPlatform_AchievementDefinitionPage_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Achievements_GetNextAchievementDefinitionArrayPage(AchievementDefinitionPages.PagedArrayHandle),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrAchievementDefinitionPages AchievementDefinitionPages;
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        AchievementDefinitionPages.PagedArrayHandle = ovr_Message_GetAchievementDefinitionArray(*MessagePtr);
                        AchievementDefinitionPages.PagedArrayMessageHandlePtr = MessagePtr;
                    }

                    Delegate.ExecuteIfBound(!bIsError, AchievementDefinitionPages, ErrMsg);
                }));
        return true;
    }
    else
    {
        return false;
    }
}

// ----------------------------------------------------------------------
// FOvrAchievementProgressPages paged array.

bool OvrPlatform_AchievementProgressPages_GetPageEntries(
    const FOvrAchievementProgressPages& AchievementProgressPages,
    TArray<FOvrAchievementProgress>& Current)
{
    size_t Size = ovr_AchievementProgressArray_GetSize(AchievementProgressPages.PagedArrayHandle);
    Current.Empty(Size);
    for (size_t Index = 0; Index < Size; ++Index)
    {
        Current.Add(FOvrAchievementProgress(ovr_AchievementProgressArray_GetElement(AchievementProgressPages.PagedArrayHandle, Index), AchievementProgressPages.PagedArrayMessageHandlePtr));
    }

    return Size > 0;
}

bool OvrPlatform_AchievementProgressPages_HasNextPage(
    const FOvrAchievementProgressPages& AchievementProgressPages)
{
    return ovr_AchievementProgressArray_HasNextPage(AchievementProgressPages.PagedArrayHandle);
}

bool OvrPlatform_AchievementProgressPages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrAchievementProgressPages& AchievementProgressPages,
    OvrPlatform_AchievementProgressPage_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Achievements_GetNextAchievementProgressArrayPage(AchievementProgressPages.PagedArrayHandle),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrAchievementProgressPages AchievementProgressPages;
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        AchievementProgressPages.PagedArrayHandle = ovr_Message_GetAchievementProgressArray(*MessagePtr);
                        AchievementProgressPages.PagedArrayMessageHandlePtr = MessagePtr;
                    }

                    Delegate.ExecuteIfBound(!bIsError, AchievementProgressPages, ErrMsg);
                }));
        return true;
    }
    else
    {
        return false;
    }
}

// ----------------------------------------------------------------------
// FOvrApplicationInvitePages paged array.

bool OvrPlatform_ApplicationInvitePages_GetPageEntries(
    const FOvrApplicationInvitePages& ApplicationInvitePages,
    TArray<FOvrApplicationInvite>& Current)
{
    size_t Size = ovr_ApplicationInviteArray_GetSize(ApplicationInvitePages.PagedArrayHandle);
    Current.Empty(Size);
    for (size_t Index = 0; Index < Size; ++Index)
    {
        Current.Add(FOvrApplicationInvite(ovr_ApplicationInviteArray_GetElement(ApplicationInvitePages.PagedArrayHandle, Index), ApplicationInvitePages.PagedArrayMessageHandlePtr));
    }

    return Size > 0;
}

bool OvrPlatform_ApplicationInvitePages_HasNextPage(
    const FOvrApplicationInvitePages& ApplicationInvitePages)
{
    return ovr_ApplicationInviteArray_HasNextPage(ApplicationInvitePages.PagedArrayHandle);
}

bool OvrPlatform_ApplicationInvitePages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrApplicationInvitePages& ApplicationInvitePages,
    OvrPlatform_ApplicationInvitePage_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_GroupPresence_GetNextApplicationInviteArrayPage(ApplicationInvitePages.PagedArrayHandle),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrApplicationInvitePages ApplicationInvitePages;
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ApplicationInvitePages.PagedArrayHandle = ovr_Message_GetApplicationInviteArray(*MessagePtr);
                        ApplicationInvitePages.PagedArrayMessageHandlePtr = MessagePtr;
                    }

                    Delegate.ExecuteIfBound(!bIsError, ApplicationInvitePages, ErrMsg);
                }));
        return true;
    }
    else
    {
        return false;
    }
}

// ----------------------------------------------------------------------
// FOvrBlockedUserPages paged array.

bool OvrPlatform_BlockedUserPages_GetPageEntries(
    const FOvrBlockedUserPages& BlockedUserPages,
    TArray<FOvrBlockedUser>& Current)
{
    size_t Size = ovr_BlockedUserArray_GetSize(BlockedUserPages.PagedArrayHandle);
    Current.Empty(Size);
    for (size_t Index = 0; Index < Size; ++Index)
    {
        Current.Add(FOvrBlockedUser(ovr_BlockedUserArray_GetElement(BlockedUserPages.PagedArrayHandle, Index), BlockedUserPages.PagedArrayMessageHandlePtr));
    }

    return Size > 0;
}

bool OvrPlatform_BlockedUserPages_HasNextPage(
    const FOvrBlockedUserPages& BlockedUserPages)
{
    return ovr_BlockedUserArray_HasNextPage(BlockedUserPages.PagedArrayHandle);
}

bool OvrPlatform_BlockedUserPages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrBlockedUserPages& BlockedUserPages,
    OvrPlatform_BlockedUserPage_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_User_GetNextBlockedUserArrayPage(BlockedUserPages.PagedArrayHandle),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrBlockedUserPages BlockedUserPages;
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        BlockedUserPages.PagedArrayHandle = ovr_Message_GetBlockedUserArray(*MessagePtr);
                        BlockedUserPages.PagedArrayMessageHandlePtr = MessagePtr;
                    }

                    Delegate.ExecuteIfBound(!bIsError, BlockedUserPages, ErrMsg);
                }));
        return true;
    }
    else
    {
        return false;
    }
}

// ----------------------------------------------------------------------
// FOvrChallengePages paged array.

bool OvrPlatform_ChallengePages_GetPageEntries(
    const FOvrChallengePages& ChallengePages,
    TArray<FOvrChallenge>& Current)
{
    size_t Size = ovr_ChallengeArray_GetSize(ChallengePages.PagedArrayHandle);
    Current.Empty(Size);
    for (size_t Index = 0; Index < Size; ++Index)
    {
        Current.Add(FOvrChallenge(ovr_ChallengeArray_GetElement(ChallengePages.PagedArrayHandle, Index), ChallengePages.PagedArrayMessageHandlePtr));
    }

    return Size > 0;
}

bool OvrPlatform_ChallengePages_HasNextPage(
    const FOvrChallengePages& ChallengePages)
{
    return ovr_ChallengeArray_HasNextPage(ChallengePages.PagedArrayHandle);
}

bool OvrPlatform_ChallengePages_HasPreviousPage(
    const FOvrChallengePages& ChallengePages)
{
    return ovr_ChallengeArray_HasPreviousPage(ChallengePages.PagedArrayHandle);
}

bool OvrPlatform_ChallengePages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrChallengePages& ChallengePages,
    OvrPlatform_ChallengePage_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Challenges_GetNextChallenges(ChallengePages.PagedArrayHandle),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrChallengePages ChallengePages;
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ChallengePages.PagedArrayHandle = ovr_Message_GetChallengeArray(*MessagePtr);
                        ChallengePages.PagedArrayMessageHandlePtr = MessagePtr;
                    }

                    Delegate.ExecuteIfBound(!bIsError, ChallengePages, ErrMsg);
                }));
        return true;
    }
    else
    {
        return false;
    }
}

bool OvrPlatform_ChallengePages_FetchPreviousPage(
    UGameInstance* GameInstance,
    const FOvrChallengePages& ChallengePages,
    OvrPlatform_ChallengePage_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Challenges_GetPreviousChallenges(ChallengePages.PagedArrayHandle),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrChallengePages ChallengePages;
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ChallengePages.PagedArrayHandle = ovr_Message_GetChallengeArray(*MessagePtr);
                        ChallengePages.PagedArrayMessageHandlePtr = MessagePtr;
                    }

                    Delegate.ExecuteIfBound(!bIsError, ChallengePages, ErrMsg);
                }));
        return true;
    }
    else
    {
        return false;
    }
}

// ----------------------------------------------------------------------
// FOvrChallengeEntryPages paged array.

bool OvrPlatform_ChallengeEntryPages_GetPageEntries(
    const FOvrChallengeEntryPages& ChallengeEntryPages,
    TArray<FOvrChallengeEntry>& Current)
{
    size_t Size = ovr_ChallengeEntryArray_GetSize(ChallengeEntryPages.PagedArrayHandle);
    Current.Empty(Size);
    for (size_t Index = 0; Index < Size; ++Index)
    {
        Current.Add(FOvrChallengeEntry(ovr_ChallengeEntryArray_GetElement(ChallengeEntryPages.PagedArrayHandle, Index), ChallengeEntryPages.PagedArrayMessageHandlePtr));
    }

    return Size > 0;
}

bool OvrPlatform_ChallengeEntryPages_HasNextPage(
    const FOvrChallengeEntryPages& ChallengeEntryPages)
{
    return ovr_ChallengeEntryArray_HasNextPage(ChallengeEntryPages.PagedArrayHandle);
}

bool OvrPlatform_ChallengeEntryPages_HasPreviousPage(
    const FOvrChallengeEntryPages& ChallengeEntryPages)
{
    return ovr_ChallengeEntryArray_HasPreviousPage(ChallengeEntryPages.PagedArrayHandle);
}

bool OvrPlatform_ChallengeEntryPages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrChallengeEntryPages& ChallengeEntryPages,
    OvrPlatform_ChallengeEntryPage_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Challenges_GetNextEntries(ChallengeEntryPages.PagedArrayHandle),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrChallengeEntryPages ChallengeEntryPages;
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ChallengeEntryPages.PagedArrayHandle = ovr_Message_GetChallengeEntryArray(*MessagePtr);
                        ChallengeEntryPages.PagedArrayMessageHandlePtr = MessagePtr;
                    }

                    Delegate.ExecuteIfBound(!bIsError, ChallengeEntryPages, ErrMsg);
                }));
        return true;
    }
    else
    {
        return false;
    }
}

bool OvrPlatform_ChallengeEntryPages_FetchPreviousPage(
    UGameInstance* GameInstance,
    const FOvrChallengeEntryPages& ChallengeEntryPages,
    OvrPlatform_ChallengeEntryPage_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Challenges_GetPreviousEntries(ChallengeEntryPages.PagedArrayHandle),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrChallengeEntryPages ChallengeEntryPages;
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ChallengeEntryPages.PagedArrayHandle = ovr_Message_GetChallengeEntryArray(*MessagePtr);
                        ChallengeEntryPages.PagedArrayMessageHandlePtr = MessagePtr;
                    }

                    Delegate.ExecuteIfBound(!bIsError, ChallengeEntryPages, ErrMsg);
                }));
        return true;
    }
    else
    {
        return false;
    }
}

// ----------------------------------------------------------------------
// FOvrCloudStorageMetadataPages paged array.

bool OvrPlatform_CloudStorageMetadataPages_GetPageEntries(
    const FOvrCloudStorageMetadataPages& CloudStorageMetadataPages,
    TArray<FOvrCloudStorageMetadata>& Current)
{
    size_t Size = ovr_CloudStorageMetadataArray_GetSize(CloudStorageMetadataPages.PagedArrayHandle);
    Current.Empty(Size);
    for (size_t Index = 0; Index < Size; ++Index)
    {
        Current.Add(FOvrCloudStorageMetadata(ovr_CloudStorageMetadataArray_GetElement(CloudStorageMetadataPages.PagedArrayHandle, Index), CloudStorageMetadataPages.PagedArrayMessageHandlePtr));
    }

    return Size > 0;
}

bool OvrPlatform_CloudStorageMetadataPages_HasNextPage(
    const FOvrCloudStorageMetadataPages& CloudStorageMetadataPages)
{
    return ovr_CloudStorageMetadataArray_HasNextPage(CloudStorageMetadataPages.PagedArrayHandle);
}

bool OvrPlatform_CloudStorageMetadataPages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrCloudStorageMetadataPages& CloudStorageMetadataPages,
    OvrPlatform_CloudStorageMetadataPage_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_CloudStorage_GetNextCloudStorageMetadataArrayPage(CloudStorageMetadataPages.PagedArrayHandle),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrCloudStorageMetadataPages CloudStorageMetadataPages;
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        CloudStorageMetadataPages.PagedArrayHandle = ovr_Message_GetCloudStorageMetadataArray(*MessagePtr);
                        CloudStorageMetadataPages.PagedArrayMessageHandlePtr = MessagePtr;
                    }

                    Delegate.ExecuteIfBound(!bIsError, CloudStorageMetadataPages, ErrMsg);
                }));
        return true;
    }
    else
    {
        return false;
    }
}

// ----------------------------------------------------------------------
// FOvrDestinationPages paged array.

bool OvrPlatform_DestinationPages_GetPageEntries(
    const FOvrDestinationPages& DestinationPages,
    TArray<FOvrDestination>& Current)
{
    size_t Size = ovr_DestinationArray_GetSize(DestinationPages.PagedArrayHandle);
    Current.Empty(Size);
    for (size_t Index = 0; Index < Size; ++Index)
    {
        Current.Add(FOvrDestination(ovr_DestinationArray_GetElement(DestinationPages.PagedArrayHandle, Index), DestinationPages.PagedArrayMessageHandlePtr));
    }

    return Size > 0;
}

bool OvrPlatform_DestinationPages_HasNextPage(
    const FOvrDestinationPages& DestinationPages)
{
    return ovr_DestinationArray_HasNextPage(DestinationPages.PagedArrayHandle);
}

bool OvrPlatform_DestinationPages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrDestinationPages& DestinationPages,
    OvrPlatform_DestinationPage_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_RichPresence_GetNextDestinationArrayPage(DestinationPages.PagedArrayHandle),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrDestinationPages DestinationPages;
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        DestinationPages.PagedArrayHandle = ovr_Message_GetDestinationArray(*MessagePtr);
                        DestinationPages.PagedArrayMessageHandlePtr = MessagePtr;
                    }

                    Delegate.ExecuteIfBound(!bIsError, DestinationPages, ErrMsg);
                }));
        return true;
    }
    else
    {
        return false;
    }
}

// ----------------------------------------------------------------------
// FOvrLeaderboardPages paged array.

bool OvrPlatform_LeaderboardPages_GetPageEntries(
    const FOvrLeaderboardPages& LeaderboardPages,
    TArray<FOvrLeaderboard>& Current)
{
    size_t Size = ovr_LeaderboardArray_GetSize(LeaderboardPages.PagedArrayHandle);
    Current.Empty(Size);
    for (size_t Index = 0; Index < Size; ++Index)
    {
        Current.Add(FOvrLeaderboard(ovr_LeaderboardArray_GetElement(LeaderboardPages.PagedArrayHandle, Index), LeaderboardPages.PagedArrayMessageHandlePtr));
    }

    return Size > 0;
}

bool OvrPlatform_LeaderboardPages_HasNextPage(
    const FOvrLeaderboardPages& LeaderboardPages)
{
    return ovr_LeaderboardArray_HasNextPage(LeaderboardPages.PagedArrayHandle);
}

bool OvrPlatform_LeaderboardPages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrLeaderboardPages& LeaderboardPages,
    OvrPlatform_LeaderboardPage_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Leaderboard_GetNextLeaderboardArrayPage(LeaderboardPages.PagedArrayHandle),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrLeaderboardPages LeaderboardPages;
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        LeaderboardPages.PagedArrayHandle = ovr_Message_GetLeaderboardArray(*MessagePtr);
                        LeaderboardPages.PagedArrayMessageHandlePtr = MessagePtr;
                    }

                    Delegate.ExecuteIfBound(!bIsError, LeaderboardPages, ErrMsg);
                }));
        return true;
    }
    else
    {
        return false;
    }
}

// ----------------------------------------------------------------------
// FOvrLeaderboardEntryPages paged array.

bool OvrPlatform_LeaderboardEntryPages_GetPageEntries(
    const FOvrLeaderboardEntryPages& LeaderboardEntryPages,
    TArray<FOvrLeaderboardEntry>& Current)
{
    size_t Size = ovr_LeaderboardEntryArray_GetSize(LeaderboardEntryPages.PagedArrayHandle);
    Current.Empty(Size);
    for (size_t Index = 0; Index < Size; ++Index)
    {
        Current.Add(FOvrLeaderboardEntry(ovr_LeaderboardEntryArray_GetElement(LeaderboardEntryPages.PagedArrayHandle, Index), LeaderboardEntryPages.PagedArrayMessageHandlePtr));
    }

    return Size > 0;
}

bool OvrPlatform_LeaderboardEntryPages_HasNextPage(
    const FOvrLeaderboardEntryPages& LeaderboardEntryPages)
{
    return ovr_LeaderboardEntryArray_HasNextPage(LeaderboardEntryPages.PagedArrayHandle);
}

bool OvrPlatform_LeaderboardEntryPages_HasPreviousPage(
    const FOvrLeaderboardEntryPages& LeaderboardEntryPages)
{
    return ovr_LeaderboardEntryArray_HasPreviousPage(LeaderboardEntryPages.PagedArrayHandle);
}

bool OvrPlatform_LeaderboardEntryPages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrLeaderboardEntryPages& LeaderboardEntryPages,
    OvrPlatform_LeaderboardEntryPage_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Leaderboard_GetNextEntries(LeaderboardEntryPages.PagedArrayHandle),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrLeaderboardEntryPages LeaderboardEntryPages;
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        LeaderboardEntryPages.PagedArrayHandle = ovr_Message_GetLeaderboardEntryArray(*MessagePtr);
                        LeaderboardEntryPages.PagedArrayMessageHandlePtr = MessagePtr;
                    }

                    Delegate.ExecuteIfBound(!bIsError, LeaderboardEntryPages, ErrMsg);
                }));
        return true;
    }
    else
    {
        return false;
    }
}

bool OvrPlatform_LeaderboardEntryPages_FetchPreviousPage(
    UGameInstance* GameInstance,
    const FOvrLeaderboardEntryPages& LeaderboardEntryPages,
    OvrPlatform_LeaderboardEntryPage_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Leaderboard_GetPreviousEntries(LeaderboardEntryPages.PagedArrayHandle),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrLeaderboardEntryPages LeaderboardEntryPages;
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        LeaderboardEntryPages.PagedArrayHandle = ovr_Message_GetLeaderboardEntryArray(*MessagePtr);
                        LeaderboardEntryPages.PagedArrayMessageHandlePtr = MessagePtr;
                    }

                    Delegate.ExecuteIfBound(!bIsError, LeaderboardEntryPages, ErrMsg);
                }));
        return true;
    }
    else
    {
        return false;
    }
}

// ----------------------------------------------------------------------
// FOvrProductPages paged array.

bool OvrPlatform_ProductPages_GetPageEntries(
    const FOvrProductPages& ProductPages,
    TArray<FOvrProduct>& Current)
{
    size_t Size = ovr_ProductArray_GetSize(ProductPages.PagedArrayHandle);
    Current.Empty(Size);
    for (size_t Index = 0; Index < Size; ++Index)
    {
        Current.Add(FOvrProduct(ovr_ProductArray_GetElement(ProductPages.PagedArrayHandle, Index), ProductPages.PagedArrayMessageHandlePtr));
    }

    return Size > 0;
}

bool OvrPlatform_ProductPages_HasNextPage(
    const FOvrProductPages& ProductPages)
{
    return ovr_ProductArray_HasNextPage(ProductPages.PagedArrayHandle);
}

bool OvrPlatform_ProductPages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrProductPages& ProductPages,
    OvrPlatform_ProductPage_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_IAP_GetNextProductArrayPage(ProductPages.PagedArrayHandle),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrProductPages ProductPages;
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ProductPages.PagedArrayHandle = ovr_Message_GetProductArray(*MessagePtr);
                        ProductPages.PagedArrayMessageHandlePtr = MessagePtr;
                    }

                    Delegate.ExecuteIfBound(!bIsError, ProductPages, ErrMsg);
                }));
        return true;
    }
    else
    {
        return false;
    }
}

// ----------------------------------------------------------------------
// FOvrPurchasePages paged array.

bool OvrPlatform_PurchasePages_GetPageEntries(
    const FOvrPurchasePages& PurchasePages,
    TArray<FOvrPurchase>& Current)
{
    size_t Size = ovr_PurchaseArray_GetSize(PurchasePages.PagedArrayHandle);
    Current.Empty(Size);
    for (size_t Index = 0; Index < Size; ++Index)
    {
        Current.Add(FOvrPurchase(ovr_PurchaseArray_GetElement(PurchasePages.PagedArrayHandle, Index), PurchasePages.PagedArrayMessageHandlePtr));
    }

    return Size > 0;
}

bool OvrPlatform_PurchasePages_HasNextPage(
    const FOvrPurchasePages& PurchasePages)
{
    return ovr_PurchaseArray_HasNextPage(PurchasePages.PagedArrayHandle);
}

bool OvrPlatform_PurchasePages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrPurchasePages& PurchasePages,
    OvrPlatform_PurchasePage_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_IAP_GetNextPurchaseArrayPage(PurchasePages.PagedArrayHandle),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrPurchasePages PurchasePages;
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        PurchasePages.PagedArrayHandle = ovr_Message_GetPurchaseArray(*MessagePtr);
                        PurchasePages.PagedArrayMessageHandlePtr = MessagePtr;
                    }

                    Delegate.ExecuteIfBound(!bIsError, PurchasePages, ErrMsg);
                }));
        return true;
    }
    else
    {
        return false;
    }
}

// ----------------------------------------------------------------------
// FOvrRoomPages paged array.

bool OvrPlatform_RoomPages_GetPageEntries(
    const FOvrRoomPages& RoomPages,
    TArray<FOvrRoom>& Current)
{
    size_t Size = ovr_RoomArray_GetSize(RoomPages.PagedArrayHandle);
    Current.Empty(Size);
    for (size_t Index = 0; Index < Size; ++Index)
    {
        Current.Add(FOvrRoom(ovr_RoomArray_GetElement(RoomPages.PagedArrayHandle, Index), RoomPages.PagedArrayMessageHandlePtr));
    }

    return Size > 0;
}

bool OvrPlatform_RoomPages_HasNextPage(
    const FOvrRoomPages& RoomPages)
{
    return ovr_RoomArray_HasNextPage(RoomPages.PagedArrayHandle);
}

bool OvrPlatform_RoomPages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrRoomPages& RoomPages,
    OvrPlatform_RoomPage_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Room_GetNextRoomArrayPage(RoomPages.PagedArrayHandle),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrRoomPages RoomPages;
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        RoomPages.PagedArrayHandle = ovr_Message_GetRoomArray(*MessagePtr);
                        RoomPages.PagedArrayMessageHandlePtr = MessagePtr;
                    }

                    Delegate.ExecuteIfBound(!bIsError, RoomPages, ErrMsg);
                }));
        return true;
    }
    else
    {
        return false;
    }
}

// ----------------------------------------------------------------------
// FOvrRoomInviteNotificationPages paged array.

bool OvrPlatform_RoomInviteNotificationPages_GetPageEntries(
    const FOvrRoomInviteNotificationPages& RoomInviteNotificationPages,
    TArray<FOvrRoomInviteNotification>& Current)
{
    size_t Size = ovr_RoomInviteNotificationArray_GetSize(RoomInviteNotificationPages.PagedArrayHandle);
    Current.Empty(Size);
    for (size_t Index = 0; Index < Size; ++Index)
    {
        Current.Add(FOvrRoomInviteNotification(ovr_RoomInviteNotificationArray_GetElement(RoomInviteNotificationPages.PagedArrayHandle, Index), RoomInviteNotificationPages.PagedArrayMessageHandlePtr));
    }

    return Size > 0;
}

bool OvrPlatform_RoomInviteNotificationPages_HasNextPage(
    const FOvrRoomInviteNotificationPages& RoomInviteNotificationPages)
{
    return ovr_RoomInviteNotificationArray_HasNextPage(RoomInviteNotificationPages.PagedArrayHandle);
}

bool OvrPlatform_RoomInviteNotificationPages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrRoomInviteNotificationPages& RoomInviteNotificationPages,
    OvrPlatform_RoomInviteNotificationPage_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Notification_GetNextRoomInviteNotificationArrayPage(RoomInviteNotificationPages.PagedArrayHandle),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrRoomInviteNotificationPages RoomInviteNotificationPages;
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        RoomInviteNotificationPages.PagedArrayHandle = ovr_Message_GetRoomInviteNotificationArray(*MessagePtr);
                        RoomInviteNotificationPages.PagedArrayMessageHandlePtr = MessagePtr;
                    }

                    Delegate.ExecuteIfBound(!bIsError, RoomInviteNotificationPages, ErrMsg);
                }));
        return true;
    }
    else
    {
        return false;
    }
}

// ----------------------------------------------------------------------
// FOvrUserAndRoomPages paged array.

bool OvrPlatform_UserAndRoomPages_GetPageEntries(
    const FOvrUserAndRoomPages& UserAndRoomPages,
    TArray<FOvrUserAndRoom>& Current)
{
    size_t Size = ovr_UserAndRoomArray_GetSize(UserAndRoomPages.PagedArrayHandle);
    Current.Empty(Size);
    for (size_t Index = 0; Index < Size; ++Index)
    {
        Current.Add(FOvrUserAndRoom(ovr_UserAndRoomArray_GetElement(UserAndRoomPages.PagedArrayHandle, Index), UserAndRoomPages.PagedArrayMessageHandlePtr));
    }

    return Size > 0;
}

bool OvrPlatform_UserAndRoomPages_HasNextPage(
    const FOvrUserAndRoomPages& UserAndRoomPages)
{
    return ovr_UserAndRoomArray_HasNextPage(UserAndRoomPages.PagedArrayHandle);
}

bool OvrPlatform_UserAndRoomPages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrUserAndRoomPages& UserAndRoomPages,
    OvrPlatform_UserAndRoomPage_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_User_GetNextUserAndRoomArrayPage(UserAndRoomPages.PagedArrayHandle),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrUserAndRoomPages UserAndRoomPages;
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        UserAndRoomPages.PagedArrayHandle = ovr_Message_GetUserAndRoomArray(*MessagePtr);
                        UserAndRoomPages.PagedArrayMessageHandlePtr = MessagePtr;
                    }

                    Delegate.ExecuteIfBound(!bIsError, UserAndRoomPages, ErrMsg);
                }));
        return true;
    }
    else
    {
        return false;
    }
}

// ----------------------------------------------------------------------
// FOvrUserPages paged array.

bool OvrPlatform_UserPages_GetPageEntries(
    const FOvrUserPages& UserPages,
    TArray<FOvrUser>& Current)
{
    size_t Size = ovr_UserArray_GetSize(UserPages.PagedArrayHandle);
    Current.Empty(Size);
    for (size_t Index = 0; Index < Size; ++Index)
    {
        Current.Add(FOvrUser(ovr_UserArray_GetElement(UserPages.PagedArrayHandle, Index), UserPages.PagedArrayMessageHandlePtr));
    }

    return Size > 0;
}

bool OvrPlatform_UserPages_HasNextPage(
    const FOvrUserPages& UserPages)
{
    return ovr_UserArray_HasNextPage(UserPages.PagedArrayHandle);
}

bool OvrPlatform_UserPages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrUserPages& UserPages,
    OvrPlatform_UserPage_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_User_GetNextUserArrayPage(UserPages.PagedArrayHandle),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrUserPages UserPages;
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        UserPages.PagedArrayHandle = ovr_Message_GetUserArray(*MessagePtr);
                        UserPages.PagedArrayMessageHandlePtr = MessagePtr;
                    }

                    Delegate.ExecuteIfBound(!bIsError, UserPages, ErrMsg);
                }));
        return true;
    }
    else
    {
        return false;
    }
}

// ----------------------------------------------------------------------
// FOvrUserCapabilityPages paged array.

bool OvrPlatform_UserCapabilityPages_GetPageEntries(
    const FOvrUserCapabilityPages& UserCapabilityPages,
    TArray<FOvrUserCapability>& Current)
{
    size_t Size = ovr_UserCapabilityArray_GetSize(UserCapabilityPages.PagedArrayHandle);
    Current.Empty(Size);
    for (size_t Index = 0; Index < Size; ++Index)
    {
        Current.Add(FOvrUserCapability(ovr_UserCapabilityArray_GetElement(UserCapabilityPages.PagedArrayHandle, Index), UserCapabilityPages.PagedArrayMessageHandlePtr));
    }

    return Size > 0;
}

bool OvrPlatform_UserCapabilityPages_HasNextPage(
    const FOvrUserCapabilityPages& UserCapabilityPages)
{
    return ovr_UserCapabilityArray_HasNextPage(UserCapabilityPages.PagedArrayHandle);
}

bool OvrPlatform_UserCapabilityPages_FetchNextPage(
    UGameInstance* GameInstance,
    const FOvrUserCapabilityPages& UserCapabilityPages,
    OvrPlatform_UserCapabilityPage_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_User_GetNextUserCapabilityArrayPage(UserCapabilityPages.PagedArrayHandle),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrUserCapabilityPages UserCapabilityPages;
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        UserCapabilityPages.PagedArrayHandle = ovr_Message_GetUserCapabilityArray(*MessagePtr);
                        UserCapabilityPages.PagedArrayMessageHandlePtr = MessagePtr;
                    }

                    Delegate.ExecuteIfBound(!bIsError, UserCapabilityPages, ErrMsg);
                }));
        return true;
    }
    else
    {
        return false;
    }
}

