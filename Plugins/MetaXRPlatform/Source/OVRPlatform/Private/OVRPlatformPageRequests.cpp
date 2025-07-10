// Copyright (c) Meta Platforms, Inc. and affiliates.

// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#include "OVRPlatformPageRequests.h"
#include "Engine/Engine.h"

// ----------------------------------------------------------------------
// AchievementDefinitionPages

void UOvrPageRequestsBlueprintLibrary::FetchAchievementDefinitionPage(
    UObject* WorldContextObject,
    const EOvrForwardArrayIteratorInputPins& InExecs,
    EOvrPageRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    const FOvrAchievementDefinitionPages& AchievementDefinitionPages,
    // Output
    TArray<FOvrAchievementDefinition>& AchievementDefinitionArray,
    bool& bHasNextPage,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformRequestGenerator RequestGenerator;

        if (InExecs == EOvrForwardArrayIteratorInputPins::Execute)
        {
            RequestGenerator = [&AchievementDefinitionPages, &AchievementDefinitionArray, &bHasNextPage]()->ovrRequest
            {
                size_t Size = ovr_AchievementDefinitionArray_GetSize(AchievementDefinitionPages.PagedArrayHandle);
                AchievementDefinitionArray.Empty(Size);
                for (size_t Index = 0; Index < Size; ++Index)
                {
                    AchievementDefinitionArray.Add(FOvrAchievementDefinition(ovr_AchievementDefinitionArray_GetElement(AchievementDefinitionPages.PagedArrayHandle, Index), AchievementDefinitionPages.PagedArrayMessageHandlePtr));
                }
                bHasNextPage = ovr_AchievementDefinitionArray_HasNextPage(AchievementDefinitionPages.PagedArrayHandle);

                // Reading the current page, so no real request is needed.
                return OVR_REQUEST_IMMEDIATE;
            };
        }
        else // InExecs == EOvrForwardArrayIteratorInputPins::NextPage
        {
            if (!bHasNextPage)
            {
                RequestGenerator = []()->ovrRequest
                {
                    return OVR_REQUEST_NO_MORE_PAGES;
                };
            }
            else
            {
                RequestGenerator = [&AchievementDefinitionPages]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Achievements_GetNextAchievementDefinitionArrayPage(AchievementDefinitionPages.PagedArrayHandle);
                    return RequestID;
                };
            }

        }

        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrPageRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                std::move(RequestGenerator),
                // Response Processor
                [&AchievementDefinitionPages, &AchievementDefinitionArray, &bHasNextPage](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // Defaults on outputs.
                    AchievementDefinitionArray.Empty();

                    // Message extraction if no error.
                    if (!bIsError)
                    {
                        AchievementDefinitionPages.PagedArrayHandle = ovr_Message_GetAchievementDefinitionArray(*MessagePtr);
                        AchievementDefinitionPages.PagedArrayMessageHandlePtr = MessagePtr;

                        size_t Size = ovr_AchievementDefinitionArray_GetSize(AchievementDefinitionPages.PagedArrayHandle);
                        AchievementDefinitionArray.Empty(Size);
                        for (size_t Index = 0; Index < Size; ++Index)
                        {
                            AchievementDefinitionArray.Add(FOvrAchievementDefinition(ovr_AchievementDefinitionArray_GetElement(AchievementDefinitionPages.PagedArrayHandle, Index), AchievementDefinitionPages.PagedArrayMessageHandlePtr));
                        }
                        bHasNextPage = ovr_AchievementDefinitionArray_HasNextPage(AchievementDefinitionPages.PagedArrayHandle);
                    }
                }));
    }
}

// ----------------------------------------------------------------------
// AchievementProgressPages

void UOvrPageRequestsBlueprintLibrary::FetchAchievementProgressPage(
    UObject* WorldContextObject,
    const EOvrForwardArrayIteratorInputPins& InExecs,
    EOvrPageRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    const FOvrAchievementProgressPages& AchievementProgressPages,
    // Output
    TArray<FOvrAchievementProgress>& AchievementProgressArray,
    bool& bHasNextPage,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformRequestGenerator RequestGenerator;

        if (InExecs == EOvrForwardArrayIteratorInputPins::Execute)
        {
            RequestGenerator = [&AchievementProgressPages, &AchievementProgressArray, &bHasNextPage]()->ovrRequest
            {
                size_t Size = ovr_AchievementProgressArray_GetSize(AchievementProgressPages.PagedArrayHandle);
                AchievementProgressArray.Empty(Size);
                for (size_t Index = 0; Index < Size; ++Index)
                {
                    AchievementProgressArray.Add(FOvrAchievementProgress(ovr_AchievementProgressArray_GetElement(AchievementProgressPages.PagedArrayHandle, Index), AchievementProgressPages.PagedArrayMessageHandlePtr));
                }
                bHasNextPage = ovr_AchievementProgressArray_HasNextPage(AchievementProgressPages.PagedArrayHandle);

                // Reading the current page, so no real request is needed.
                return OVR_REQUEST_IMMEDIATE;
            };
        }
        else // InExecs == EOvrForwardArrayIteratorInputPins::NextPage
        {
            if (!bHasNextPage)
            {
                RequestGenerator = []()->ovrRequest
                {
                    return OVR_REQUEST_NO_MORE_PAGES;
                };
            }
            else
            {
                RequestGenerator = [&AchievementProgressPages]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Achievements_GetNextAchievementProgressArrayPage(AchievementProgressPages.PagedArrayHandle);
                    return RequestID;
                };
            }

        }

        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrPageRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                std::move(RequestGenerator),
                // Response Processor
                [&AchievementProgressPages, &AchievementProgressArray, &bHasNextPage](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // Defaults on outputs.
                    AchievementProgressArray.Empty();

                    // Message extraction if no error.
                    if (!bIsError)
                    {
                        AchievementProgressPages.PagedArrayHandle = ovr_Message_GetAchievementProgressArray(*MessagePtr);
                        AchievementProgressPages.PagedArrayMessageHandlePtr = MessagePtr;

                        size_t Size = ovr_AchievementProgressArray_GetSize(AchievementProgressPages.PagedArrayHandle);
                        AchievementProgressArray.Empty(Size);
                        for (size_t Index = 0; Index < Size; ++Index)
                        {
                            AchievementProgressArray.Add(FOvrAchievementProgress(ovr_AchievementProgressArray_GetElement(AchievementProgressPages.PagedArrayHandle, Index), AchievementProgressPages.PagedArrayMessageHandlePtr));
                        }
                        bHasNextPage = ovr_AchievementProgressArray_HasNextPage(AchievementProgressPages.PagedArrayHandle);
                    }
                }));
    }
}

// ----------------------------------------------------------------------
// ApplicationInvitePages

void UOvrPageRequestsBlueprintLibrary::FetchApplicationInvitePage(
    UObject* WorldContextObject,
    const EOvrForwardArrayIteratorInputPins& InExecs,
    EOvrPageRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    const FOvrApplicationInvitePages& ApplicationInvitePages,
    // Output
    TArray<FOvrApplicationInvite>& ApplicationInviteArray,
    bool& bHasNextPage,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformRequestGenerator RequestGenerator;

        if (InExecs == EOvrForwardArrayIteratorInputPins::Execute)
        {
            RequestGenerator = [&ApplicationInvitePages, &ApplicationInviteArray, &bHasNextPage]()->ovrRequest
            {
                size_t Size = ovr_ApplicationInviteArray_GetSize(ApplicationInvitePages.PagedArrayHandle);
                ApplicationInviteArray.Empty(Size);
                for (size_t Index = 0; Index < Size; ++Index)
                {
                    ApplicationInviteArray.Add(FOvrApplicationInvite(ovr_ApplicationInviteArray_GetElement(ApplicationInvitePages.PagedArrayHandle, Index), ApplicationInvitePages.PagedArrayMessageHandlePtr));
                }
                bHasNextPage = ovr_ApplicationInviteArray_HasNextPage(ApplicationInvitePages.PagedArrayHandle);

                // Reading the current page, so no real request is needed.
                return OVR_REQUEST_IMMEDIATE;
            };
        }
        else // InExecs == EOvrForwardArrayIteratorInputPins::NextPage
        {
            if (!bHasNextPage)
            {
                RequestGenerator = []()->ovrRequest
                {
                    return OVR_REQUEST_NO_MORE_PAGES;
                };
            }
            else
            {
                RequestGenerator = [&ApplicationInvitePages]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_GroupPresence_GetNextApplicationInviteArrayPage(ApplicationInvitePages.PagedArrayHandle);
                    return RequestID;
                };
            }

        }

        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrPageRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                std::move(RequestGenerator),
                // Response Processor
                [&ApplicationInvitePages, &ApplicationInviteArray, &bHasNextPage](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // Defaults on outputs.
                    ApplicationInviteArray.Empty();

                    // Message extraction if no error.
                    if (!bIsError)
                    {
                        ApplicationInvitePages.PagedArrayHandle = ovr_Message_GetApplicationInviteArray(*MessagePtr);
                        ApplicationInvitePages.PagedArrayMessageHandlePtr = MessagePtr;

                        size_t Size = ovr_ApplicationInviteArray_GetSize(ApplicationInvitePages.PagedArrayHandle);
                        ApplicationInviteArray.Empty(Size);
                        for (size_t Index = 0; Index < Size; ++Index)
                        {
                            ApplicationInviteArray.Add(FOvrApplicationInvite(ovr_ApplicationInviteArray_GetElement(ApplicationInvitePages.PagedArrayHandle, Index), ApplicationInvitePages.PagedArrayMessageHandlePtr));
                        }
                        bHasNextPage = ovr_ApplicationInviteArray_HasNextPage(ApplicationInvitePages.PagedArrayHandle);
                    }
                }));
    }
}

// ----------------------------------------------------------------------
// BlockedUserPages

void UOvrPageRequestsBlueprintLibrary::FetchBlockedUserPage(
    UObject* WorldContextObject,
    const EOvrForwardArrayIteratorInputPins& InExecs,
    EOvrPageRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    const FOvrBlockedUserPages& BlockedUserPages,
    // Output
    TArray<FOvrBlockedUser>& BlockedUserArray,
    bool& bHasNextPage,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformRequestGenerator RequestGenerator;

        if (InExecs == EOvrForwardArrayIteratorInputPins::Execute)
        {
            RequestGenerator = [&BlockedUserPages, &BlockedUserArray, &bHasNextPage]()->ovrRequest
            {
                size_t Size = ovr_BlockedUserArray_GetSize(BlockedUserPages.PagedArrayHandle);
                BlockedUserArray.Empty(Size);
                for (size_t Index = 0; Index < Size; ++Index)
                {
                    BlockedUserArray.Add(FOvrBlockedUser(ovr_BlockedUserArray_GetElement(BlockedUserPages.PagedArrayHandle, Index), BlockedUserPages.PagedArrayMessageHandlePtr));
                }
                bHasNextPage = ovr_BlockedUserArray_HasNextPage(BlockedUserPages.PagedArrayHandle);

                // Reading the current page, so no real request is needed.
                return OVR_REQUEST_IMMEDIATE;
            };
        }
        else // InExecs == EOvrForwardArrayIteratorInputPins::NextPage
        {
            if (!bHasNextPage)
            {
                RequestGenerator = []()->ovrRequest
                {
                    return OVR_REQUEST_NO_MORE_PAGES;
                };
            }
            else
            {
                RequestGenerator = [&BlockedUserPages]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_User_GetNextBlockedUserArrayPage(BlockedUserPages.PagedArrayHandle);
                    return RequestID;
                };
            }

        }

        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrPageRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                std::move(RequestGenerator),
                // Response Processor
                [&BlockedUserPages, &BlockedUserArray, &bHasNextPage](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // Defaults on outputs.
                    BlockedUserArray.Empty();

                    // Message extraction if no error.
                    if (!bIsError)
                    {
                        BlockedUserPages.PagedArrayHandle = ovr_Message_GetBlockedUserArray(*MessagePtr);
                        BlockedUserPages.PagedArrayMessageHandlePtr = MessagePtr;

                        size_t Size = ovr_BlockedUserArray_GetSize(BlockedUserPages.PagedArrayHandle);
                        BlockedUserArray.Empty(Size);
                        for (size_t Index = 0; Index < Size; ++Index)
                        {
                            BlockedUserArray.Add(FOvrBlockedUser(ovr_BlockedUserArray_GetElement(BlockedUserPages.PagedArrayHandle, Index), BlockedUserPages.PagedArrayMessageHandlePtr));
                        }
                        bHasNextPage = ovr_BlockedUserArray_HasNextPage(BlockedUserPages.PagedArrayHandle);
                    }
                }));
    }
}

// ----------------------------------------------------------------------
// ChallengePages

void UOvrPageRequestsBlueprintLibrary::FetchChallengePage(
    UObject* WorldContextObject,
    const EOvrBidirectionalArrayIteratorInputPins& InExecs,
    EOvrPageRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    const FOvrChallengePages& ChallengePages,
    // Output
    TArray<FOvrChallenge>& ChallengeArray,
    bool& bHasNextPage,
    bool& bHasPreviousPage,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformRequestGenerator RequestGenerator;

        if (InExecs == EOvrBidirectionalArrayIteratorInputPins::Execute)
        {
            RequestGenerator = [&ChallengePages, &ChallengeArray, &bHasNextPage, &bHasPreviousPage]()->ovrRequest
            {
                size_t Size = ovr_ChallengeArray_GetSize(ChallengePages.PagedArrayHandle);
                ChallengeArray.Empty(Size);
                for (size_t Index = 0; Index < Size; ++Index)
                {
                    ChallengeArray.Add(FOvrChallenge(ovr_ChallengeArray_GetElement(ChallengePages.PagedArrayHandle, Index), ChallengePages.PagedArrayMessageHandlePtr));
                }
                bHasNextPage = ovr_ChallengeArray_HasNextPage(ChallengePages.PagedArrayHandle);
                bHasPreviousPage = ovr_ChallengeArray_HasPreviousPage(ChallengePages.PagedArrayHandle);

                // Reading the current page, so no real request is needed.
                return OVR_REQUEST_IMMEDIATE;
            };
        }
        else if (InExecs == EOvrBidirectionalArrayIteratorInputPins::NextPage)
        {
            if (!bHasNextPage)
            {
                RequestGenerator = []()->ovrRequest
                {
                    return OVR_REQUEST_NO_MORE_PAGES;
                };
            }
            else
            {
                RequestGenerator = [&ChallengePages]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Challenges_GetNextChallenges(ChallengePages.PagedArrayHandle);
                    return RequestID;
                };
            }
        }
        else // InExecs == EOvrBidirectionalArrayIteratorInputPins::PreviousPage
        {
            if (!bHasPreviousPage)
            {
                RequestGenerator = []()->ovrRequest
                {
                    return OVR_REQUEST_NO_MORE_PAGES;
                };
            }
            else
            {
                RequestGenerator = [&ChallengePages]()->ovrRequest
                {
                    ovrRequest RequestID =ovr_Challenges_GetPreviousChallenges(ChallengePages.PagedArrayHandle);
                    return RequestID;
                };
            }
        }

        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrPageRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                std::move(RequestGenerator),
                // Response Processor
                [&ChallengePages, &ChallengeArray, &bHasNextPage, &bHasPreviousPage](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // Defaults on outputs.
                    ChallengeArray.Empty();

                    // Message extraction if no error.
                    if (!bIsError)
                    {
                        ChallengePages.PagedArrayHandle = ovr_Message_GetChallengeArray(*MessagePtr);
                        ChallengePages.PagedArrayMessageHandlePtr = MessagePtr;

                        size_t Size = ovr_ChallengeArray_GetSize(ChallengePages.PagedArrayHandle);
                        ChallengeArray.Empty(Size);
                        for (size_t Index = 0; Index < Size; ++Index)
                        {
                            ChallengeArray.Add(FOvrChallenge(ovr_ChallengeArray_GetElement(ChallengePages.PagedArrayHandle, Index), ChallengePages.PagedArrayMessageHandlePtr));
                        }
                        bHasNextPage = ovr_ChallengeArray_HasNextPage(ChallengePages.PagedArrayHandle);
                        bHasPreviousPage = ovr_ChallengeArray_HasPreviousPage(ChallengePages.PagedArrayHandle);
                    }
                }));
    }
}

// ----------------------------------------------------------------------
// ChallengeEntryPages

void UOvrPageRequestsBlueprintLibrary::FetchChallengeEntryPage(
    UObject* WorldContextObject,
    const EOvrBidirectionalArrayIteratorInputPins& InExecs,
    EOvrPageRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    const FOvrChallengeEntryPages& ChallengeEntryPages,
    // Output
    TArray<FOvrChallengeEntry>& ChallengeEntryArray,
    bool& bHasNextPage,
    bool& bHasPreviousPage,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformRequestGenerator RequestGenerator;

        if (InExecs == EOvrBidirectionalArrayIteratorInputPins::Execute)
        {
            RequestGenerator = [&ChallengeEntryPages, &ChallengeEntryArray, &bHasNextPage, &bHasPreviousPage]()->ovrRequest
            {
                size_t Size = ovr_ChallengeEntryArray_GetSize(ChallengeEntryPages.PagedArrayHandle);
                ChallengeEntryArray.Empty(Size);
                for (size_t Index = 0; Index < Size; ++Index)
                {
                    ChallengeEntryArray.Add(FOvrChallengeEntry(ovr_ChallengeEntryArray_GetElement(ChallengeEntryPages.PagedArrayHandle, Index), ChallengeEntryPages.PagedArrayMessageHandlePtr));
                }
                bHasNextPage = ovr_ChallengeEntryArray_HasNextPage(ChallengeEntryPages.PagedArrayHandle);
                bHasPreviousPage = ovr_ChallengeEntryArray_HasPreviousPage(ChallengeEntryPages.PagedArrayHandle);

                // Reading the current page, so no real request is needed.
                return OVR_REQUEST_IMMEDIATE;
            };
        }
        else if (InExecs == EOvrBidirectionalArrayIteratorInputPins::NextPage)
        {
            if (!bHasNextPage)
            {
                RequestGenerator = []()->ovrRequest
                {
                    return OVR_REQUEST_NO_MORE_PAGES;
                };
            }
            else
            {
                RequestGenerator = [&ChallengeEntryPages]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Challenges_GetNextEntries(ChallengeEntryPages.PagedArrayHandle);
                    return RequestID;
                };
            }
        }
        else // InExecs == EOvrBidirectionalArrayIteratorInputPins::PreviousPage
        {
            if (!bHasPreviousPage)
            {
                RequestGenerator = []()->ovrRequest
                {
                    return OVR_REQUEST_NO_MORE_PAGES;
                };
            }
            else
            {
                RequestGenerator = [&ChallengeEntryPages]()->ovrRequest
                {
                    ovrRequest RequestID =ovr_Challenges_GetPreviousEntries(ChallengeEntryPages.PagedArrayHandle);
                    return RequestID;
                };
            }
        }

        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrPageRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                std::move(RequestGenerator),
                // Response Processor
                [&ChallengeEntryPages, &ChallengeEntryArray, &bHasNextPage, &bHasPreviousPage](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // Defaults on outputs.
                    ChallengeEntryArray.Empty();

                    // Message extraction if no error.
                    if (!bIsError)
                    {
                        ChallengeEntryPages.PagedArrayHandle = ovr_Message_GetChallengeEntryArray(*MessagePtr);
                        ChallengeEntryPages.PagedArrayMessageHandlePtr = MessagePtr;

                        size_t Size = ovr_ChallengeEntryArray_GetSize(ChallengeEntryPages.PagedArrayHandle);
                        ChallengeEntryArray.Empty(Size);
                        for (size_t Index = 0; Index < Size; ++Index)
                        {
                            ChallengeEntryArray.Add(FOvrChallengeEntry(ovr_ChallengeEntryArray_GetElement(ChallengeEntryPages.PagedArrayHandle, Index), ChallengeEntryPages.PagedArrayMessageHandlePtr));
                        }
                        bHasNextPage = ovr_ChallengeEntryArray_HasNextPage(ChallengeEntryPages.PagedArrayHandle);
                        bHasPreviousPage = ovr_ChallengeEntryArray_HasPreviousPage(ChallengeEntryPages.PagedArrayHandle);
                    }
                }));
    }
}

// ----------------------------------------------------------------------
// CowatchViewerPages

void UOvrPageRequestsBlueprintLibrary::FetchCowatchViewerPage(
    UObject* WorldContextObject,
    const EOvrForwardArrayIteratorInputPins& InExecs,
    EOvrPageRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    const FOvrCowatchViewerPages& CowatchViewerPages,
    // Output
    TArray<FOvrCowatchViewer>& CowatchViewerArray,
    bool& bHasNextPage,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformRequestGenerator RequestGenerator;

        if (InExecs == EOvrForwardArrayIteratorInputPins::Execute)
        {
            RequestGenerator = [&CowatchViewerPages, &CowatchViewerArray, &bHasNextPage]()->ovrRequest
            {
                size_t Size = ovr_CowatchViewerArray_GetSize(CowatchViewerPages.PagedArrayHandle);
                CowatchViewerArray.Empty(Size);
                for (size_t Index = 0; Index < Size; ++Index)
                {
                    CowatchViewerArray.Add(FOvrCowatchViewer(ovr_CowatchViewerArray_GetElement(CowatchViewerPages.PagedArrayHandle, Index), CowatchViewerPages.PagedArrayMessageHandlePtr));
                }
                bHasNextPage = ovr_CowatchViewerArray_HasNextPage(CowatchViewerPages.PagedArrayHandle);

                // Reading the current page, so no real request is needed.
                return OVR_REQUEST_IMMEDIATE;
            };
        }
        else // InExecs == EOvrForwardArrayIteratorInputPins::NextPage
        {
            if (!bHasNextPage)
            {
                RequestGenerator = []()->ovrRequest
                {
                    return OVR_REQUEST_NO_MORE_PAGES;
                };
            }
            else
            {
                RequestGenerator = [&CowatchViewerPages]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Cowatching_GetNextCowatchViewerArrayPage(CowatchViewerPages.PagedArrayHandle);
                    return RequestID;
                };
            }

        }

        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrPageRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                std::move(RequestGenerator),
                // Response Processor
                [&CowatchViewerPages, &CowatchViewerArray, &bHasNextPage](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // Defaults on outputs.
                    CowatchViewerArray.Empty();

                    // Message extraction if no error.
                    if (!bIsError)
                    {
                        CowatchViewerPages.PagedArrayHandle = ovr_Message_GetCowatchViewerArray(*MessagePtr);
                        CowatchViewerPages.PagedArrayMessageHandlePtr = MessagePtr;

                        size_t Size = ovr_CowatchViewerArray_GetSize(CowatchViewerPages.PagedArrayHandle);
                        CowatchViewerArray.Empty(Size);
                        for (size_t Index = 0; Index < Size; ++Index)
                        {
                            CowatchViewerArray.Add(FOvrCowatchViewer(ovr_CowatchViewerArray_GetElement(CowatchViewerPages.PagedArrayHandle, Index), CowatchViewerPages.PagedArrayMessageHandlePtr));
                        }
                        bHasNextPage = ovr_CowatchViewerArray_HasNextPage(CowatchViewerPages.PagedArrayHandle);
                    }
                }));
    }
}

// ----------------------------------------------------------------------
// DestinationPages

void UOvrPageRequestsBlueprintLibrary::FetchDestinationPage(
    UObject* WorldContextObject,
    const EOvrForwardArrayIteratorInputPins& InExecs,
    EOvrPageRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    const FOvrDestinationPages& DestinationPages,
    // Output
    TArray<FOvrDestination>& DestinationArray,
    bool& bHasNextPage,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformRequestGenerator RequestGenerator;

        if (InExecs == EOvrForwardArrayIteratorInputPins::Execute)
        {
            RequestGenerator = [&DestinationPages, &DestinationArray, &bHasNextPage]()->ovrRequest
            {
                size_t Size = ovr_DestinationArray_GetSize(DestinationPages.PagedArrayHandle);
                DestinationArray.Empty(Size);
                for (size_t Index = 0; Index < Size; ++Index)
                {
                    DestinationArray.Add(FOvrDestination(ovr_DestinationArray_GetElement(DestinationPages.PagedArrayHandle, Index), DestinationPages.PagedArrayMessageHandlePtr));
                }
                bHasNextPage = ovr_DestinationArray_HasNextPage(DestinationPages.PagedArrayHandle);

                // Reading the current page, so no real request is needed.
                return OVR_REQUEST_IMMEDIATE;
            };
        }
        else // InExecs == EOvrForwardArrayIteratorInputPins::NextPage
        {
            if (!bHasNextPage)
            {
                RequestGenerator = []()->ovrRequest
                {
                    return OVR_REQUEST_NO_MORE_PAGES;
                };
            }
            else
            {
                RequestGenerator = [&DestinationPages]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_RichPresence_GetNextDestinationArrayPage(DestinationPages.PagedArrayHandle);
                    return RequestID;
                };
            }

        }

        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrPageRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                std::move(RequestGenerator),
                // Response Processor
                [&DestinationPages, &DestinationArray, &bHasNextPage](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // Defaults on outputs.
                    DestinationArray.Empty();

                    // Message extraction if no error.
                    if (!bIsError)
                    {
                        DestinationPages.PagedArrayHandle = ovr_Message_GetDestinationArray(*MessagePtr);
                        DestinationPages.PagedArrayMessageHandlePtr = MessagePtr;

                        size_t Size = ovr_DestinationArray_GetSize(DestinationPages.PagedArrayHandle);
                        DestinationArray.Empty(Size);
                        for (size_t Index = 0; Index < Size; ++Index)
                        {
                            DestinationArray.Add(FOvrDestination(ovr_DestinationArray_GetElement(DestinationPages.PagedArrayHandle, Index), DestinationPages.PagedArrayMessageHandlePtr));
                        }
                        bHasNextPage = ovr_DestinationArray_HasNextPage(DestinationPages.PagedArrayHandle);
                    }
                }));
    }
}

// ----------------------------------------------------------------------
// LeaderboardPages

void UOvrPageRequestsBlueprintLibrary::FetchLeaderboardPage(
    UObject* WorldContextObject,
    const EOvrForwardArrayIteratorInputPins& InExecs,
    EOvrPageRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    const FOvrLeaderboardPages& LeaderboardPages,
    // Output
    TArray<FOvrLeaderboard>& LeaderboardArray,
    bool& bHasNextPage,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformRequestGenerator RequestGenerator;

        if (InExecs == EOvrForwardArrayIteratorInputPins::Execute)
        {
            RequestGenerator = [&LeaderboardPages, &LeaderboardArray, &bHasNextPage]()->ovrRequest
            {
                size_t Size = ovr_LeaderboardArray_GetSize(LeaderboardPages.PagedArrayHandle);
                LeaderboardArray.Empty(Size);
                for (size_t Index = 0; Index < Size; ++Index)
                {
                    LeaderboardArray.Add(FOvrLeaderboard(ovr_LeaderboardArray_GetElement(LeaderboardPages.PagedArrayHandle, Index), LeaderboardPages.PagedArrayMessageHandlePtr));
                }
                bHasNextPage = ovr_LeaderboardArray_HasNextPage(LeaderboardPages.PagedArrayHandle);

                // Reading the current page, so no real request is needed.
                return OVR_REQUEST_IMMEDIATE;
            };
        }
        else // InExecs == EOvrForwardArrayIteratorInputPins::NextPage
        {
            if (!bHasNextPage)
            {
                RequestGenerator = []()->ovrRequest
                {
                    return OVR_REQUEST_NO_MORE_PAGES;
                };
            }
            else
            {
                RequestGenerator = [&LeaderboardPages]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Leaderboard_GetNextLeaderboardArrayPage(LeaderboardPages.PagedArrayHandle);
                    return RequestID;
                };
            }

        }

        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrPageRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                std::move(RequestGenerator),
                // Response Processor
                [&LeaderboardPages, &LeaderboardArray, &bHasNextPage](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // Defaults on outputs.
                    LeaderboardArray.Empty();

                    // Message extraction if no error.
                    if (!bIsError)
                    {
                        LeaderboardPages.PagedArrayHandle = ovr_Message_GetLeaderboardArray(*MessagePtr);
                        LeaderboardPages.PagedArrayMessageHandlePtr = MessagePtr;

                        size_t Size = ovr_LeaderboardArray_GetSize(LeaderboardPages.PagedArrayHandle);
                        LeaderboardArray.Empty(Size);
                        for (size_t Index = 0; Index < Size; ++Index)
                        {
                            LeaderboardArray.Add(FOvrLeaderboard(ovr_LeaderboardArray_GetElement(LeaderboardPages.PagedArrayHandle, Index), LeaderboardPages.PagedArrayMessageHandlePtr));
                        }
                        bHasNextPage = ovr_LeaderboardArray_HasNextPage(LeaderboardPages.PagedArrayHandle);
                    }
                }));
    }
}

// ----------------------------------------------------------------------
// LeaderboardEntryPages

void UOvrPageRequestsBlueprintLibrary::FetchLeaderboardEntryPage(
    UObject* WorldContextObject,
    const EOvrBidirectionalArrayIteratorInputPins& InExecs,
    EOvrPageRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    const FOvrLeaderboardEntryPages& LeaderboardEntryPages,
    // Output
    TArray<FOvrLeaderboardEntry>& LeaderboardEntryArray,
    bool& bHasNextPage,
    bool& bHasPreviousPage,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformRequestGenerator RequestGenerator;

        if (InExecs == EOvrBidirectionalArrayIteratorInputPins::Execute)
        {
            RequestGenerator = [&LeaderboardEntryPages, &LeaderboardEntryArray, &bHasNextPage, &bHasPreviousPage]()->ovrRequest
            {
                size_t Size = ovr_LeaderboardEntryArray_GetSize(LeaderboardEntryPages.PagedArrayHandle);
                LeaderboardEntryArray.Empty(Size);
                for (size_t Index = 0; Index < Size; ++Index)
                {
                    LeaderboardEntryArray.Add(FOvrLeaderboardEntry(ovr_LeaderboardEntryArray_GetElement(LeaderboardEntryPages.PagedArrayHandle, Index), LeaderboardEntryPages.PagedArrayMessageHandlePtr));
                }
                bHasNextPage = ovr_LeaderboardEntryArray_HasNextPage(LeaderboardEntryPages.PagedArrayHandle);
                bHasPreviousPage = ovr_LeaderboardEntryArray_HasPreviousPage(LeaderboardEntryPages.PagedArrayHandle);

                // Reading the current page, so no real request is needed.
                return OVR_REQUEST_IMMEDIATE;
            };
        }
        else if (InExecs == EOvrBidirectionalArrayIteratorInputPins::NextPage)
        {
            if (!bHasNextPage)
            {
                RequestGenerator = []()->ovrRequest
                {
                    return OVR_REQUEST_NO_MORE_PAGES;
                };
            }
            else
            {
                RequestGenerator = [&LeaderboardEntryPages]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Leaderboard_GetNextEntries(LeaderboardEntryPages.PagedArrayHandle);
                    return RequestID;
                };
            }
        }
        else // InExecs == EOvrBidirectionalArrayIteratorInputPins::PreviousPage
        {
            if (!bHasPreviousPage)
            {
                RequestGenerator = []()->ovrRequest
                {
                    return OVR_REQUEST_NO_MORE_PAGES;
                };
            }
            else
            {
                RequestGenerator = [&LeaderboardEntryPages]()->ovrRequest
                {
                    ovrRequest RequestID =ovr_Leaderboard_GetPreviousEntries(LeaderboardEntryPages.PagedArrayHandle);
                    return RequestID;
                };
            }
        }

        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrPageRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                std::move(RequestGenerator),
                // Response Processor
                [&LeaderboardEntryPages, &LeaderboardEntryArray, &bHasNextPage, &bHasPreviousPage](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // Defaults on outputs.
                    LeaderboardEntryArray.Empty();

                    // Message extraction if no error.
                    if (!bIsError)
                    {
                        LeaderboardEntryPages.PagedArrayHandle = ovr_Message_GetLeaderboardEntryArray(*MessagePtr);
                        LeaderboardEntryPages.PagedArrayMessageHandlePtr = MessagePtr;

                        size_t Size = ovr_LeaderboardEntryArray_GetSize(LeaderboardEntryPages.PagedArrayHandle);
                        LeaderboardEntryArray.Empty(Size);
                        for (size_t Index = 0; Index < Size; ++Index)
                        {
                            LeaderboardEntryArray.Add(FOvrLeaderboardEntry(ovr_LeaderboardEntryArray_GetElement(LeaderboardEntryPages.PagedArrayHandle, Index), LeaderboardEntryPages.PagedArrayMessageHandlePtr));
                        }
                        bHasNextPage = ovr_LeaderboardEntryArray_HasNextPage(LeaderboardEntryPages.PagedArrayHandle);
                        bHasPreviousPage = ovr_LeaderboardEntryArray_HasPreviousPage(LeaderboardEntryPages.PagedArrayHandle);
                    }
                }));
    }
}

// ----------------------------------------------------------------------
// ProductPages

void UOvrPageRequestsBlueprintLibrary::FetchProductPage(
    UObject* WorldContextObject,
    const EOvrForwardArrayIteratorInputPins& InExecs,
    EOvrPageRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    const FOvrProductPages& ProductPages,
    // Output
    TArray<FOvrProduct>& ProductArray,
    bool& bHasNextPage,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformRequestGenerator RequestGenerator;

        if (InExecs == EOvrForwardArrayIteratorInputPins::Execute)
        {
            RequestGenerator = [&ProductPages, &ProductArray, &bHasNextPage]()->ovrRequest
            {
                size_t Size = ovr_ProductArray_GetSize(ProductPages.PagedArrayHandle);
                ProductArray.Empty(Size);
                for (size_t Index = 0; Index < Size; ++Index)
                {
                    ProductArray.Add(FOvrProduct(ovr_ProductArray_GetElement(ProductPages.PagedArrayHandle, Index), ProductPages.PagedArrayMessageHandlePtr));
                }
                bHasNextPage = ovr_ProductArray_HasNextPage(ProductPages.PagedArrayHandle);

                // Reading the current page, so no real request is needed.
                return OVR_REQUEST_IMMEDIATE;
            };
        }
        else // InExecs == EOvrForwardArrayIteratorInputPins::NextPage
        {
            if (!bHasNextPage)
            {
                RequestGenerator = []()->ovrRequest
                {
                    return OVR_REQUEST_NO_MORE_PAGES;
                };
            }
            else
            {
                RequestGenerator = [&ProductPages]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_IAP_GetNextProductArrayPage(ProductPages.PagedArrayHandle);
                    return RequestID;
                };
            }

        }

        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrPageRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                std::move(RequestGenerator),
                // Response Processor
                [&ProductPages, &ProductArray, &bHasNextPage](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // Defaults on outputs.
                    ProductArray.Empty();

                    // Message extraction if no error.
                    if (!bIsError)
                    {
                        ProductPages.PagedArrayHandle = ovr_Message_GetProductArray(*MessagePtr);
                        ProductPages.PagedArrayMessageHandlePtr = MessagePtr;

                        size_t Size = ovr_ProductArray_GetSize(ProductPages.PagedArrayHandle);
                        ProductArray.Empty(Size);
                        for (size_t Index = 0; Index < Size; ++Index)
                        {
                            ProductArray.Add(FOvrProduct(ovr_ProductArray_GetElement(ProductPages.PagedArrayHandle, Index), ProductPages.PagedArrayMessageHandlePtr));
                        }
                        bHasNextPage = ovr_ProductArray_HasNextPage(ProductPages.PagedArrayHandle);
                    }
                }));
    }
}

// ----------------------------------------------------------------------
// PurchasePages

void UOvrPageRequestsBlueprintLibrary::FetchPurchasePage(
    UObject* WorldContextObject,
    const EOvrForwardArrayIteratorInputPins& InExecs,
    EOvrPageRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    const FOvrPurchasePages& PurchasePages,
    // Output
    TArray<FOvrPurchase>& PurchaseArray,
    bool& bHasNextPage,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformRequestGenerator RequestGenerator;

        if (InExecs == EOvrForwardArrayIteratorInputPins::Execute)
        {
            RequestGenerator = [&PurchasePages, &PurchaseArray, &bHasNextPage]()->ovrRequest
            {
                size_t Size = ovr_PurchaseArray_GetSize(PurchasePages.PagedArrayHandle);
                PurchaseArray.Empty(Size);
                for (size_t Index = 0; Index < Size; ++Index)
                {
                    PurchaseArray.Add(FOvrPurchase(ovr_PurchaseArray_GetElement(PurchasePages.PagedArrayHandle, Index), PurchasePages.PagedArrayMessageHandlePtr));
                }
                bHasNextPage = ovr_PurchaseArray_HasNextPage(PurchasePages.PagedArrayHandle);

                // Reading the current page, so no real request is needed.
                return OVR_REQUEST_IMMEDIATE;
            };
        }
        else // InExecs == EOvrForwardArrayIteratorInputPins::NextPage
        {
            if (!bHasNextPage)
            {
                RequestGenerator = []()->ovrRequest
                {
                    return OVR_REQUEST_NO_MORE_PAGES;
                };
            }
            else
            {
                RequestGenerator = [&PurchasePages]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_IAP_GetNextPurchaseArrayPage(PurchasePages.PagedArrayHandle);
                    return RequestID;
                };
            }

        }

        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrPageRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                std::move(RequestGenerator),
                // Response Processor
                [&PurchasePages, &PurchaseArray, &bHasNextPage](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // Defaults on outputs.
                    PurchaseArray.Empty();

                    // Message extraction if no error.
                    if (!bIsError)
                    {
                        PurchasePages.PagedArrayHandle = ovr_Message_GetPurchaseArray(*MessagePtr);
                        PurchasePages.PagedArrayMessageHandlePtr = MessagePtr;

                        size_t Size = ovr_PurchaseArray_GetSize(PurchasePages.PagedArrayHandle);
                        PurchaseArray.Empty(Size);
                        for (size_t Index = 0; Index < Size; ++Index)
                        {
                            PurchaseArray.Add(FOvrPurchase(ovr_PurchaseArray_GetElement(PurchasePages.PagedArrayHandle, Index), PurchasePages.PagedArrayMessageHandlePtr));
                        }
                        bHasNextPage = ovr_PurchaseArray_HasNextPage(PurchasePages.PagedArrayHandle);
                    }
                }));
    }
}

// ----------------------------------------------------------------------
// UserPages

void UOvrPageRequestsBlueprintLibrary::FetchUserPage(
    UObject* WorldContextObject,
    const EOvrForwardArrayIteratorInputPins& InExecs,
    EOvrPageRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    const FOvrUserPages& UserPages,
    // Output
    TArray<FOvrUser>& UserArray,
    bool& bHasNextPage,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformRequestGenerator RequestGenerator;

        if (InExecs == EOvrForwardArrayIteratorInputPins::Execute)
        {
            RequestGenerator = [&UserPages, &UserArray, &bHasNextPage]()->ovrRequest
            {
                size_t Size = ovr_UserArray_GetSize(UserPages.PagedArrayHandle);
                UserArray.Empty(Size);
                for (size_t Index = 0; Index < Size; ++Index)
                {
                    UserArray.Add(FOvrUser(ovr_UserArray_GetElement(UserPages.PagedArrayHandle, Index), UserPages.PagedArrayMessageHandlePtr));
                }
                bHasNextPage = ovr_UserArray_HasNextPage(UserPages.PagedArrayHandle);

                // Reading the current page, so no real request is needed.
                return OVR_REQUEST_IMMEDIATE;
            };
        }
        else // InExecs == EOvrForwardArrayIteratorInputPins::NextPage
        {
            if (!bHasNextPage)
            {
                RequestGenerator = []()->ovrRequest
                {
                    return OVR_REQUEST_NO_MORE_PAGES;
                };
            }
            else
            {
                RequestGenerator = [&UserPages]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_User_GetNextUserArrayPage(UserPages.PagedArrayHandle);
                    return RequestID;
                };
            }

        }

        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrPageRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                std::move(RequestGenerator),
                // Response Processor
                [&UserPages, &UserArray, &bHasNextPage](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // Defaults on outputs.
                    UserArray.Empty();

                    // Message extraction if no error.
                    if (!bIsError)
                    {
                        UserPages.PagedArrayHandle = ovr_Message_GetUserArray(*MessagePtr);
                        UserPages.PagedArrayMessageHandlePtr = MessagePtr;

                        size_t Size = ovr_UserArray_GetSize(UserPages.PagedArrayHandle);
                        UserArray.Empty(Size);
                        for (size_t Index = 0; Index < Size; ++Index)
                        {
                            UserArray.Add(FOvrUser(ovr_UserArray_GetElement(UserPages.PagedArrayHandle, Index), UserPages.PagedArrayMessageHandlePtr));
                        }
                        bHasNextPage = ovr_UserArray_HasNextPage(UserPages.PagedArrayHandle);
                    }
                }));
    }
}

// ----------------------------------------------------------------------
// UserCapabilityPages

void UOvrPageRequestsBlueprintLibrary::FetchUserCapabilityPage(
    UObject* WorldContextObject,
    const EOvrForwardArrayIteratorInputPins& InExecs,
    EOvrPageRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    const FOvrUserCapabilityPages& UserCapabilityPages,
    // Output
    TArray<FOvrUserCapability>& UserCapabilityArray,
    bool& bHasNextPage,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformRequestGenerator RequestGenerator;

        if (InExecs == EOvrForwardArrayIteratorInputPins::Execute)
        {
            RequestGenerator = [&UserCapabilityPages, &UserCapabilityArray, &bHasNextPage]()->ovrRequest
            {
                size_t Size = ovr_UserCapabilityArray_GetSize(UserCapabilityPages.PagedArrayHandle);
                UserCapabilityArray.Empty(Size);
                for (size_t Index = 0; Index < Size; ++Index)
                {
                    UserCapabilityArray.Add(FOvrUserCapability(ovr_UserCapabilityArray_GetElement(UserCapabilityPages.PagedArrayHandle, Index), UserCapabilityPages.PagedArrayMessageHandlePtr));
                }
                bHasNextPage = ovr_UserCapabilityArray_HasNextPage(UserCapabilityPages.PagedArrayHandle);

                // Reading the current page, so no real request is needed.
                return OVR_REQUEST_IMMEDIATE;
            };
        }
        else // InExecs == EOvrForwardArrayIteratorInputPins::NextPage
        {
            if (!bHasNextPage)
            {
                RequestGenerator = []()->ovrRequest
                {
                    return OVR_REQUEST_NO_MORE_PAGES;
                };
            }
            else
            {
                RequestGenerator = [&UserCapabilityPages]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_User_GetNextUserCapabilityArrayPage(UserCapabilityPages.PagedArrayHandle);
                    return RequestID;
                };
            }

        }

        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrPageRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                std::move(RequestGenerator),
                // Response Processor
                [&UserCapabilityPages, &UserCapabilityArray, &bHasNextPage](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // Defaults on outputs.
                    UserCapabilityArray.Empty();

                    // Message extraction if no error.
                    if (!bIsError)
                    {
                        UserCapabilityPages.PagedArrayHandle = ovr_Message_GetUserCapabilityArray(*MessagePtr);
                        UserCapabilityPages.PagedArrayMessageHandlePtr = MessagePtr;

                        size_t Size = ovr_UserCapabilityArray_GetSize(UserCapabilityPages.PagedArrayHandle);
                        UserCapabilityArray.Empty(Size);
                        for (size_t Index = 0; Index < Size; ++Index)
                        {
                            UserCapabilityArray.Add(FOvrUserCapability(ovr_UserCapabilityArray_GetElement(UserCapabilityPages.PagedArrayHandle, Index), UserCapabilityPages.PagedArrayMessageHandlePtr));
                        }
                        bHasNextPage = ovr_UserCapabilityArray_HasNextPage(UserCapabilityPages.PagedArrayHandle);
                    }
                }));
    }
}

