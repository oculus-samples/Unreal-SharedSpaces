// Copyright (c) Meta Platforms, Inc. and affiliates.

// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#include "OVRPlatformRequests.h"
#include "OVRPlatformRequestsConverters.h"
#include "OVRPlatformOptionsConverters.h"
#include "OVRPlatformCppRequests.h"
#include "OVRPlatformCppPageRequests.h"

// ----------------------------------------------------------------------
// AbuseReport

void UOvrRequestsBlueprintLibrary::AbuseReport_ReportRequestHandled(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    EOvrReportRequestResponse Response,
    // Output
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [Response]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_AbuseReport_ReportRequestHandled(ConvertReportRequestResponse(Response));

                    return RequestID;
                },
                // Response Processor
                [](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // No payload in response
                }));
    }
}

// ----------------------------------------------------------------------
// Achievements

void UOvrRequestsBlueprintLibrary::Achievements_AddCount(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FString Name,
    int64 Count,
    // Output
    FOvrAchievementUpdate& AchievementUpdate,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [Name, Count]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Achievements_AddCount(TCHAR_TO_UTF8(*Name), static_cast<unsigned long long>(Count));

                    return RequestID;
                },
                // Response Processor
                [&AchievementUpdate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        AchievementUpdate.Clear();
                    }
                    else
                    {
                        AchievementUpdate.Update(ovr_Message_GetAchievementUpdate(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::Achievements_AddFields(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FString Name,
    FString Fields,
    // Output
    FOvrAchievementUpdate& AchievementUpdate,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [Name, Fields]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Achievements_AddFields(TCHAR_TO_UTF8(*Name), TCHAR_TO_UTF8(*Fields));

                    return RequestID;
                },
                // Response Processor
                [&AchievementUpdate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        AchievementUpdate.Clear();
                    }
                    else
                    {
                        AchievementUpdate.Update(ovr_Message_GetAchievementUpdate(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::Achievements_GetAllDefinitions(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Output
    FOvrAchievementDefinitionPages& AchievementDefinitionPages,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                []()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Achievements_GetAllDefinitions();

                    return RequestID;
                },
                // Response Processor
                [&AchievementDefinitionPages](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        AchievementDefinitionPages.Clear();
                    }
                    else
                    {
                        AchievementDefinitionPages.Update(ovr_Message_GetAchievementDefinitionArray(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::Achievements_GetAllProgress(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Output
    FOvrAchievementProgressPages& AchievementProgressPages,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                []()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Achievements_GetAllProgress();

                    return RequestID;
                },
                // Response Processor
                [&AchievementProgressPages](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        AchievementProgressPages.Clear();
                    }
                    else
                    {
                        AchievementProgressPages.Update(ovr_Message_GetAchievementProgressArray(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::Achievements_GetDefinitionsByName(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    TArray<FString> Names,
    // Output
    FOvrAchievementDefinitionPages& AchievementDefinitionPages,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [Names]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Achievements_GetDefinitionsByName(OvrPlatformStringArray(Names), static_cast<int>(Names.Num()));

                    return RequestID;
                },
                // Response Processor
                [&AchievementDefinitionPages](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        AchievementDefinitionPages.Clear();
                    }
                    else
                    {
                        AchievementDefinitionPages.Update(ovr_Message_GetAchievementDefinitionArray(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::Achievements_GetProgressByName(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    TArray<FString> Names,
    // Output
    FOvrAchievementProgressPages& AchievementProgressPages,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [Names]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Achievements_GetProgressByName(OvrPlatformStringArray(Names), static_cast<int>(Names.Num()));

                    return RequestID;
                },
                // Response Processor
                [&AchievementProgressPages](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        AchievementProgressPages.Clear();
                    }
                    else
                    {
                        AchievementProgressPages.Update(ovr_Message_GetAchievementProgressArray(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::Achievements_Unlock(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FString Name,
    // Output
    FOvrAchievementUpdate& AchievementUpdate,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [Name]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Achievements_Unlock(TCHAR_TO_UTF8(*Name));

                    return RequestID;
                },
                // Response Processor
                [&AchievementUpdate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        AchievementUpdate.Clear();
                    }
                    else
                    {
                        AchievementUpdate.Update(ovr_Message_GetAchievementUpdate(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

// ----------------------------------------------------------------------
// Application

void UOvrRequestsBlueprintLibrary::Application_CancelAppDownload(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Output
    FOvrAppDownloadResult& AppDownloadResult,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                []()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Application_CancelAppDownload();

                    return RequestID;
                },
                // Response Processor
                [&AppDownloadResult](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        AppDownloadResult.Clear();
                    }
                    else
                    {
                        AppDownloadResult.Update(ovr_Message_GetAppDownloadResult(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::Application_CheckAppDownloadProgress(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Output
    FOvrAppDownloadProgressResult& AppDownloadProgressResult,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                []()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Application_CheckAppDownloadProgress();

                    return RequestID;
                },
                // Response Processor
                [&AppDownloadProgressResult](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        AppDownloadProgressResult.Clear();
                    }
                    else
                    {
                        AppDownloadProgressResult.Update(ovr_Message_GetAppDownloadProgressResult(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::Application_GetVersion(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Output
    FOvrApplicationVersion& ApplicationVersion,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                []()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Application_GetVersion();

                    return RequestID;
                },
                // Response Processor
                [&ApplicationVersion](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        ApplicationVersion.Clear();
                    }
                    else
                    {
                        ApplicationVersion.Update(ovr_Message_GetApplicationVersion(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::Application_InstallAppUpdateAndRelaunch(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FOvrApplicationOptions DeeplinkOptions,
    // Output
    FOvrAppDownloadResult& AppDownloadResult,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [DeeplinkOptions]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Application_InstallAppUpdateAndRelaunch(FOvrApplicationOptionsConverter(DeeplinkOptions));

                    return RequestID;
                },
                // Response Processor
                [&AppDownloadResult](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        AppDownloadResult.Clear();
                    }
                    else
                    {
                        AppDownloadResult.Update(ovr_Message_GetAppDownloadResult(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::Application_LaunchOtherApp(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FOvrId AppID,
    FOvrApplicationOptions DeeplinkOptions,
    // Output
    FString& StringPayload,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [AppID, DeeplinkOptions]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Application_LaunchOtherApp(static_cast<ovrID>(AppID), FOvrApplicationOptionsConverter(DeeplinkOptions));

                    return RequestID;
                },
                // Response Processor
                [&StringPayload](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        StringPayload = TEXT("");
                    }
                    else
                    {
                        StringPayload = UTF8_TO_TCHAR(ovr_Message_GetString(*MessagePtr));
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::Application_StartAppDownload(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Output
    FOvrAppDownloadResult& AppDownloadResult,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                []()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Application_StartAppDownload();

                    return RequestID;
                },
                // Response Processor
                [&AppDownloadResult](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        AppDownloadResult.Clear();
                    }
                    else
                    {
                        AppDownloadResult.Update(ovr_Message_GetAppDownloadResult(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

// ----------------------------------------------------------------------
// ApplicationLifecycle

// ----------------------------------------------------------------------
// AssetFile

void UOvrRequestsBlueprintLibrary::AssetFile_Delete(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FOvrId AssetFileID,
    // Output
    FOvrAssetFileDeleteResult& AssetFileDeleteResult,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [AssetFileID]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_AssetFile_Delete(static_cast<ovrID>(AssetFileID));

                    return RequestID;
                },
                // Response Processor
                [&AssetFileDeleteResult](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        AssetFileDeleteResult.Clear();
                    }
                    else
                    {
                        AssetFileDeleteResult.Update(ovr_Message_GetAssetFileDeleteResult(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::AssetFile_DeleteById(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FOvrId AssetFileID,
    // Output
    FOvrAssetFileDeleteResult& AssetFileDeleteResult,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [AssetFileID]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_AssetFile_DeleteById(static_cast<ovrID>(AssetFileID));

                    return RequestID;
                },
                // Response Processor
                [&AssetFileDeleteResult](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        AssetFileDeleteResult.Clear();
                    }
                    else
                    {
                        AssetFileDeleteResult.Update(ovr_Message_GetAssetFileDeleteResult(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::AssetFile_DeleteByName(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FString AssetFileName,
    // Output
    FOvrAssetFileDeleteResult& AssetFileDeleteResult,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [AssetFileName]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_AssetFile_DeleteByName(TCHAR_TO_UTF8(*AssetFileName));

                    return RequestID;
                },
                // Response Processor
                [&AssetFileDeleteResult](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        AssetFileDeleteResult.Clear();
                    }
                    else
                    {
                        AssetFileDeleteResult.Update(ovr_Message_GetAssetFileDeleteResult(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::AssetFile_Download(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FOvrId AssetFileID,
    // Output
    FOvrAssetFileDownloadResult& AssetFileDownloadResult,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [AssetFileID]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_AssetFile_Download(static_cast<ovrID>(AssetFileID));

                    return RequestID;
                },
                // Response Processor
                [&AssetFileDownloadResult](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        AssetFileDownloadResult.Clear();
                    }
                    else
                    {
                        AssetFileDownloadResult.Update(ovr_Message_GetAssetFileDownloadResult(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::AssetFile_DownloadById(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FOvrId AssetFileID,
    // Output
    FOvrAssetFileDownloadResult& AssetFileDownloadResult,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [AssetFileID]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_AssetFile_DownloadById(static_cast<ovrID>(AssetFileID));

                    return RequestID;
                },
                // Response Processor
                [&AssetFileDownloadResult](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        AssetFileDownloadResult.Clear();
                    }
                    else
                    {
                        AssetFileDownloadResult.Update(ovr_Message_GetAssetFileDownloadResult(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::AssetFile_DownloadByName(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FString AssetFileName,
    // Output
    FOvrAssetFileDownloadResult& AssetFileDownloadResult,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [AssetFileName]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_AssetFile_DownloadByName(TCHAR_TO_UTF8(*AssetFileName));

                    return RequestID;
                },
                // Response Processor
                [&AssetFileDownloadResult](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        AssetFileDownloadResult.Clear();
                    }
                    else
                    {
                        AssetFileDownloadResult.Update(ovr_Message_GetAssetFileDownloadResult(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::AssetFile_DownloadCancel(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FOvrId AssetFileID,
    // Output
    FOvrAssetFileDownloadCancelResult& AssetFileDownloadCancelResult,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [AssetFileID]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_AssetFile_DownloadCancel(static_cast<ovrID>(AssetFileID));

                    return RequestID;
                },
                // Response Processor
                [&AssetFileDownloadCancelResult](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        AssetFileDownloadCancelResult.Clear();
                    }
                    else
                    {
                        AssetFileDownloadCancelResult.Update(ovr_Message_GetAssetFileDownloadCancelResult(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::AssetFile_DownloadCancelById(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FOvrId AssetFileID,
    // Output
    FOvrAssetFileDownloadCancelResult& AssetFileDownloadCancelResult,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [AssetFileID]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_AssetFile_DownloadCancelById(static_cast<ovrID>(AssetFileID));

                    return RequestID;
                },
                // Response Processor
                [&AssetFileDownloadCancelResult](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        AssetFileDownloadCancelResult.Clear();
                    }
                    else
                    {
                        AssetFileDownloadCancelResult.Update(ovr_Message_GetAssetFileDownloadCancelResult(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::AssetFile_DownloadCancelByName(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FString AssetFileName,
    // Output
    FOvrAssetFileDownloadCancelResult& AssetFileDownloadCancelResult,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [AssetFileName]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_AssetFile_DownloadCancelByName(TCHAR_TO_UTF8(*AssetFileName));

                    return RequestID;
                },
                // Response Processor
                [&AssetFileDownloadCancelResult](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        AssetFileDownloadCancelResult.Clear();
                    }
                    else
                    {
                        AssetFileDownloadCancelResult.Update(ovr_Message_GetAssetFileDownloadCancelResult(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::AssetFile_GetList(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Output
    TArray<FOvrAssetDetails>& AssetDetailsArray,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                []()->ovrRequest
                {
                    ovrRequest RequestID = ovr_AssetFile_GetList();

                    return RequestID;
                },
                // Response Processor
                [&AssetDetailsArray](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        AssetDetailsArray.Empty();
                    }
                    else
                    {
                        ovrAssetDetailsArrayHandle AssetDetailsArrayHandle = ovr_Message_GetAssetDetailsArray(*MessagePtr);
                        size_t AssetDetailsArraySize = ovr_AssetDetailsArray_GetSize(AssetDetailsArrayHandle);
                        AssetDetailsArray.Empty(AssetDetailsArraySize);
                        for (size_t Index = 0; Index < AssetDetailsArraySize; ++Index)
                        {
                            AssetDetailsArray.Add(FOvrAssetDetails(ovr_AssetDetailsArray_GetElement(AssetDetailsArrayHandle, Index), MessagePtr));
                        }
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::AssetFile_Status(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FOvrId AssetFileID,
    // Output
    FOvrAssetDetails& AssetDetails,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [AssetFileID]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_AssetFile_Status(static_cast<ovrID>(AssetFileID));

                    return RequestID;
                },
                // Response Processor
                [&AssetDetails](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        AssetDetails.Clear();
                    }
                    else
                    {
                        AssetDetails.Update(ovr_Message_GetAssetDetails(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::AssetFile_StatusById(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FOvrId AssetFileID,
    // Output
    FOvrAssetDetails& AssetDetails,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [AssetFileID]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_AssetFile_StatusById(static_cast<ovrID>(AssetFileID));

                    return RequestID;
                },
                // Response Processor
                [&AssetDetails](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        AssetDetails.Clear();
                    }
                    else
                    {
                        AssetDetails.Update(ovr_Message_GetAssetDetails(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::AssetFile_StatusByName(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FString AssetFileName,
    // Output
    FOvrAssetDetails& AssetDetails,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [AssetFileName]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_AssetFile_StatusByName(TCHAR_TO_UTF8(*AssetFileName));

                    return RequestID;
                },
                // Response Processor
                [&AssetDetails](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        AssetDetails.Clear();
                    }
                    else
                    {
                        AssetDetails.Update(ovr_Message_GetAssetDetails(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

// ----------------------------------------------------------------------
// Avatar

void UOvrRequestsBlueprintLibrary::Avatar_LaunchAvatarEditor(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FOvrAvatarEditorOptions Options,
    // Output
    FOvrAvatarEditorResult& AvatarEditorResult,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [Options]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Avatar_LaunchAvatarEditor(FOvrAvatarEditorOptionsConverter(Options));

                    return RequestID;
                },
                // Response Processor
                [&AvatarEditorResult](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        AvatarEditorResult.Clear();
                    }
                    else
                    {
                        AvatarEditorResult.Update(ovr_Message_GetAvatarEditorResult(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

// ----------------------------------------------------------------------
// Challenges

void UOvrRequestsBlueprintLibrary::Challenges_Create(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FString LeaderboardName,
    FOvrChallengeOptions ChallengeOptions,
    // Output
    FOvrChallenge& Challenge,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [LeaderboardName, ChallengeOptions]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Challenges_Create(TCHAR_TO_UTF8(*LeaderboardName), FOvrChallengeOptionsConverter(ChallengeOptions));

                    return RequestID;
                },
                // Response Processor
                [&Challenge](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        Challenge.Clear();
                    }
                    else
                    {
                        Challenge.Update(ovr_Message_GetChallenge(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::Challenges_DeclineInvite(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FOvrId ChallengeID,
    // Output
    FOvrChallenge& Challenge,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [ChallengeID]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Challenges_DeclineInvite(static_cast<ovrID>(ChallengeID));

                    return RequestID;
                },
                // Response Processor
                [&Challenge](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        Challenge.Clear();
                    }
                    else
                    {
                        Challenge.Update(ovr_Message_GetChallenge(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::Challenges_Delete(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FOvrId ChallengeID,
    // Output
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [ChallengeID]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Challenges_Delete(static_cast<ovrID>(ChallengeID));

                    return RequestID;
                },
                // Response Processor
                [](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // No payload in response
                }));
    }
}

void UOvrRequestsBlueprintLibrary::Challenges_Get(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FOvrId ChallengeID,
    // Output
    FOvrChallenge& Challenge,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [ChallengeID]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Challenges_Get(static_cast<ovrID>(ChallengeID));

                    return RequestID;
                },
                // Response Processor
                [&Challenge](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        Challenge.Clear();
                    }
                    else
                    {
                        Challenge.Update(ovr_Message_GetChallenge(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::Challenges_GetEntries(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FOvrId ChallengeID,
    int32 Limit,
    EOvrLeaderboardFilterType Filter,
    EOvrLeaderboardStartAt StartAt,
    // Output
    FOvrChallengeEntryPages& ChallengeEntryPages,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [ChallengeID, Limit, Filter, StartAt]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Challenges_GetEntries(static_cast<ovrID>(ChallengeID), static_cast<int>(Limit), ConvertLeaderboardFilterType(Filter), ConvertLeaderboardStartAt(StartAt));

                    return RequestID;
                },
                // Response Processor
                [&ChallengeEntryPages](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        ChallengeEntryPages.Clear();
                    }
                    else
                    {
                        ChallengeEntryPages.Update(ovr_Message_GetChallengeEntryArray(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::Challenges_GetEntriesAfterRank(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FOvrId ChallengeID,
    int32 Limit,
    int64 AfterRank,
    // Output
    FOvrChallengeEntryPages& ChallengeEntryPages,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [ChallengeID, Limit, AfterRank]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Challenges_GetEntriesAfterRank(static_cast<ovrID>(ChallengeID), static_cast<int>(Limit), static_cast<unsigned long long>(AfterRank));

                    return RequestID;
                },
                // Response Processor
                [&ChallengeEntryPages](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        ChallengeEntryPages.Clear();
                    }
                    else
                    {
                        ChallengeEntryPages.Update(ovr_Message_GetChallengeEntryArray(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::Challenges_GetEntriesByIds(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FOvrId ChallengeID,
    int32 Limit,
    EOvrLeaderboardStartAt StartAt,
    TArray<FOvrId> UserIDs,
    // Output
    FOvrChallengeEntryPages& ChallengeEntryPages,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [ChallengeID, Limit, StartAt, UserIDs]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Challenges_GetEntriesByIds(static_cast<ovrID>(ChallengeID), static_cast<int>(Limit), ConvertLeaderboardStartAt(StartAt), OvrPlatformIdArray(UserIDs), static_cast<unsigned int>(UserIDs.Num()));

                    return RequestID;
                },
                // Response Processor
                [&ChallengeEntryPages](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        ChallengeEntryPages.Clear();
                    }
                    else
                    {
                        ChallengeEntryPages.Update(ovr_Message_GetChallengeEntryArray(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::Challenges_GetList(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FOvrChallengeOptions ChallengeOptions,
    int32 Limit,
    // Output
    FOvrChallengePages& ChallengePages,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [ChallengeOptions, Limit]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Challenges_GetList(FOvrChallengeOptionsConverter(ChallengeOptions), static_cast<int>(Limit));

                    return RequestID;
                },
                // Response Processor
                [&ChallengePages](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        ChallengePages.Clear();
                    }
                    else
                    {
                        ChallengePages.Update(ovr_Message_GetChallengeArray(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::Challenges_Join(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FOvrId ChallengeID,
    // Output
    FOvrChallenge& Challenge,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [ChallengeID]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Challenges_Join(static_cast<ovrID>(ChallengeID));

                    return RequestID;
                },
                // Response Processor
                [&Challenge](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        Challenge.Clear();
                    }
                    else
                    {
                        Challenge.Update(ovr_Message_GetChallenge(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::Challenges_Leave(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FOvrId ChallengeID,
    // Output
    FOvrChallenge& Challenge,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [ChallengeID]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Challenges_Leave(static_cast<ovrID>(ChallengeID));

                    return RequestID;
                },
                // Response Processor
                [&Challenge](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        Challenge.Clear();
                    }
                    else
                    {
                        Challenge.Update(ovr_Message_GetChallenge(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::Challenges_UpdateInfo(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FOvrId ChallengeID,
    FOvrChallengeOptions ChallengeOptions,
    // Output
    FOvrChallenge& Challenge,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [ChallengeID, ChallengeOptions]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Challenges_UpdateInfo(static_cast<ovrID>(ChallengeID), FOvrChallengeOptionsConverter(ChallengeOptions));

                    return RequestID;
                },
                // Response Processor
                [&Challenge](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        Challenge.Clear();
                    }
                    else
                    {
                        Challenge.Update(ovr_Message_GetChallenge(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

// ----------------------------------------------------------------------
// Cowatching

void UOvrRequestsBlueprintLibrary::Cowatching_GetPresenterData(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Output
    FString& StringPayload,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                []()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Cowatching_GetPresenterData();

                    return RequestID;
                },
                // Response Processor
                [&StringPayload](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        StringPayload = TEXT("");
                    }
                    else
                    {
                        StringPayload = UTF8_TO_TCHAR(ovr_Message_GetString(*MessagePtr));
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::Cowatching_GetViewersData(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Output
    FOvrCowatchViewerPages& CowatchViewerPages,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                []()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Cowatching_GetViewersData();

                    return RequestID;
                },
                // Response Processor
                [&CowatchViewerPages](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        CowatchViewerPages.Clear();
                    }
                    else
                    {
                        CowatchViewerPages.Update(ovr_Message_GetCowatchViewerArray(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::Cowatching_IsInSession(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Output
    FOvrCowatchingState& CowatchingState,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                []()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Cowatching_IsInSession();

                    return RequestID;
                },
                // Response Processor
                [&CowatchingState](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        CowatchingState.Clear();
                    }
                    else
                    {
                        CowatchingState.Update(ovr_Message_GetCowatchingState(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::Cowatching_JoinSession(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Output
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                []()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Cowatching_JoinSession();

                    return RequestID;
                },
                // Response Processor
                [](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // No payload in response
                }));
    }
}

void UOvrRequestsBlueprintLibrary::Cowatching_LaunchInviteDialog(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Output
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                []()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Cowatching_LaunchInviteDialog();

                    return RequestID;
                },
                // Response Processor
                [](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // No payload in response
                }));
    }
}

void UOvrRequestsBlueprintLibrary::Cowatching_LeaveSession(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Output
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                []()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Cowatching_LeaveSession();

                    return RequestID;
                },
                // Response Processor
                [](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // No payload in response
                }));
    }
}

void UOvrRequestsBlueprintLibrary::Cowatching_RequestToPresent(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Output
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                []()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Cowatching_RequestToPresent();

                    return RequestID;
                },
                // Response Processor
                [](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // No payload in response
                }));
    }
}

void UOvrRequestsBlueprintLibrary::Cowatching_ResignFromPresenting(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Output
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                []()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Cowatching_ResignFromPresenting();

                    return RequestID;
                },
                // Response Processor
                [](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // No payload in response
                }));
    }
}

void UOvrRequestsBlueprintLibrary::Cowatching_SetPresenterData(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FString VideoTitle,
    FString PresenterData,
    // Output
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [VideoTitle, PresenterData]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Cowatching_SetPresenterData(TCHAR_TO_UTF8(*VideoTitle), TCHAR_TO_UTF8(*PresenterData));

                    return RequestID;
                },
                // Response Processor
                [](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // No payload in response
                }));
    }
}

void UOvrRequestsBlueprintLibrary::Cowatching_SetViewerData(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FString ViewerData,
    // Output
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [ViewerData]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Cowatching_SetViewerData(TCHAR_TO_UTF8(*ViewerData));

                    return RequestID;
                },
                // Response Processor
                [](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // No payload in response
                }));
    }
}

// ----------------------------------------------------------------------
// DeviceApplicationIntegrity

void UOvrRequestsBlueprintLibrary::DeviceApplicationIntegrity_GetIntegrityToken(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FString ChallengeNonce,
    // Output
    FString& StringPayload,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [ChallengeNonce]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_DeviceApplicationIntegrity_GetIntegrityToken(TCHAR_TO_UTF8(*ChallengeNonce));

                    return RequestID;
                },
                // Response Processor
                [&StringPayload](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        StringPayload = TEXT("");
                    }
                    else
                    {
                        StringPayload = UTF8_TO_TCHAR(ovr_Message_GetString(*MessagePtr));
                    }
                }));
    }
}

// ----------------------------------------------------------------------
// Entitlement

void UOvrRequestsBlueprintLibrary::Entitlement_GetIsViewerEntitled(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Output
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                []()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Entitlement_GetIsViewerEntitled();

                    return RequestID;
                },
                // Response Processor
                [](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // No payload in response
                }));
    }
}

// ----------------------------------------------------------------------
// GroupPresence

void UOvrRequestsBlueprintLibrary::GroupPresence_Clear(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Output
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                []()->ovrRequest
                {
                    ovrRequest RequestID = ovr_GroupPresence_Clear();

                    return RequestID;
                },
                // Response Processor
                [](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // No payload in response
                }));
    }
}

void UOvrRequestsBlueprintLibrary::GroupPresence_GetInvitableUsers(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FOvrInviteOptions Options,
    // Output
    FOvrUserPages& UserPages,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [Options]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_GroupPresence_GetInvitableUsers(FOvrInviteOptionsConverter(Options));

                    return RequestID;
                },
                // Response Processor
                [&UserPages](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        UserPages.Clear();
                    }
                    else
                    {
                        UserPages.Update(ovr_Message_GetUserArray(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::GroupPresence_GetSentInvites(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Output
    FOvrApplicationInvitePages& ApplicationInvitePages,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                []()->ovrRequest
                {
                    ovrRequest RequestID = ovr_GroupPresence_GetSentInvites();

                    return RequestID;
                },
                // Response Processor
                [&ApplicationInvitePages](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        ApplicationInvitePages.Clear();
                    }
                    else
                    {
                        ApplicationInvitePages.Update(ovr_Message_GetApplicationInviteArray(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::GroupPresence_LaunchInvitePanel(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FOvrInviteOptions Options,
    // Output
    FOvrInvitePanelResultInfo& InvitePanelResultInfo,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [Options]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_GroupPresence_LaunchInvitePanel(FOvrInviteOptionsConverter(Options));

                    return RequestID;
                },
                // Response Processor
                [&InvitePanelResultInfo](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        InvitePanelResultInfo.Clear();
                    }
                    else
                    {
                        InvitePanelResultInfo.Update(ovr_Message_GetInvitePanelResultInfo(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::GroupPresence_LaunchMultiplayerErrorDialog(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FOvrMultiplayerErrorOptions Options,
    // Output
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [Options]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_GroupPresence_LaunchMultiplayerErrorDialog(FOvrMultiplayerErrorOptionsConverter(Options));

                    return RequestID;
                },
                // Response Processor
                [](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // No payload in response
                }));
    }
}

void UOvrRequestsBlueprintLibrary::GroupPresence_LaunchRejoinDialog(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FString LobbySessionId,
    FString MatchSessionId,
    FString DestinationApiName,
    // Output
    FOvrRejoinDialogResult& RejoinDialogResult,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [LobbySessionId, MatchSessionId, DestinationApiName]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_GroupPresence_LaunchRejoinDialog(TCHAR_TO_UTF8(*LobbySessionId), TCHAR_TO_UTF8(*MatchSessionId), TCHAR_TO_UTF8(*DestinationApiName));

                    return RequestID;
                },
                // Response Processor
                [&RejoinDialogResult](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        RejoinDialogResult.Clear();
                    }
                    else
                    {
                        RejoinDialogResult.Update(ovr_Message_GetRejoinDialogResult(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::GroupPresence_LaunchRosterPanel(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FOvrRosterOptions Options,
    // Output
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [Options]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_GroupPresence_LaunchRosterPanel(FOvrRosterOptionsConverter(Options));

                    return RequestID;
                },
                // Response Processor
                [](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // No payload in response
                }));
    }
}

void UOvrRequestsBlueprintLibrary::GroupPresence_SendInvites(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    TArray<FOvrId> UserIDs,
    // Output
    FOvrSendInvitesResult& SendInvitesResult,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [UserIDs]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_GroupPresence_SendInvites(OvrPlatformIdArray(UserIDs), static_cast<unsigned int>(UserIDs.Num()));

                    return RequestID;
                },
                // Response Processor
                [&SendInvitesResult](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        SendInvitesResult.Clear();
                    }
                    else
                    {
                        SendInvitesResult.Update(ovr_Message_GetSendInvitesResult(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::GroupPresence_Set(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FOvrGroupPresenceOptions GroupPresenceOptions,
    // Output
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [GroupPresenceOptions]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_GroupPresence_Set(FOvrGroupPresenceOptionsConverter(GroupPresenceOptions));

                    return RequestID;
                },
                // Response Processor
                [](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // No payload in response
                }));
    }
}

void UOvrRequestsBlueprintLibrary::GroupPresence_SetDeeplinkMessageOverride(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FString DeeplinkMessage,
    // Output
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [DeeplinkMessage]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_GroupPresence_SetDeeplinkMessageOverride(TCHAR_TO_UTF8(*DeeplinkMessage));

                    return RequestID;
                },
                // Response Processor
                [](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // No payload in response
                }));
    }
}

void UOvrRequestsBlueprintLibrary::GroupPresence_SetDestination(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FString ApiName,
    // Output
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [ApiName]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_GroupPresence_SetDestination(TCHAR_TO_UTF8(*ApiName));

                    return RequestID;
                },
                // Response Processor
                [](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // No payload in response
                }));
    }
}

void UOvrRequestsBlueprintLibrary::GroupPresence_SetIsJoinable(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    bool IsJoinable,
    // Output
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [IsJoinable]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_GroupPresence_SetIsJoinable(IsJoinable);

                    return RequestID;
                },
                // Response Processor
                [](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // No payload in response
                }));
    }
}

void UOvrRequestsBlueprintLibrary::GroupPresence_SetLobbySession(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FString Id,
    // Output
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [Id]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_GroupPresence_SetLobbySession(TCHAR_TO_UTF8(*Id));

                    return RequestID;
                },
                // Response Processor
                [](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // No payload in response
                }));
    }
}

void UOvrRequestsBlueprintLibrary::GroupPresence_SetMatchSession(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FString Id,
    // Output
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [Id]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_GroupPresence_SetMatchSession(TCHAR_TO_UTF8(*Id));

                    return RequestID;
                },
                // Response Processor
                [](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // No payload in response
                }));
    }
}

// ----------------------------------------------------------------------
// IAP

void UOvrRequestsBlueprintLibrary::IAP_ConsumePurchase(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FString Sku,
    // Output
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [Sku]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_IAP_ConsumePurchase(TCHAR_TO_UTF8(*Sku));

                    return RequestID;
                },
                // Response Processor
                [](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // No payload in response
                }));
    }
}

void UOvrRequestsBlueprintLibrary::IAP_GetProductsBySKU(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    TArray<FString> Skus,
    // Output
    FOvrProductPages& ProductPages,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [Skus]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_IAP_GetProductsBySKU(OvrPlatformStringArray(Skus), static_cast<int>(Skus.Num()));

                    return RequestID;
                },
                // Response Processor
                [&ProductPages](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        ProductPages.Clear();
                    }
                    else
                    {
                        ProductPages.Update(ovr_Message_GetProductArray(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::IAP_GetViewerPurchases(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Output
    FOvrPurchasePages& PurchasePages,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                []()->ovrRequest
                {
                    ovrRequest RequestID = ovr_IAP_GetViewerPurchases();

                    return RequestID;
                },
                // Response Processor
                [&PurchasePages](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        PurchasePages.Clear();
                    }
                    else
                    {
                        PurchasePages.Update(ovr_Message_GetPurchaseArray(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::IAP_GetViewerPurchasesDurableCache(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Output
    FOvrPurchasePages& PurchasePages,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                []()->ovrRequest
                {
                    ovrRequest RequestID = ovr_IAP_GetViewerPurchasesDurableCache();

                    return RequestID;
                },
                // Response Processor
                [&PurchasePages](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        PurchasePages.Clear();
                    }
                    else
                    {
                        PurchasePages.Update(ovr_Message_GetPurchaseArray(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::IAP_LaunchCheckoutFlow(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FString Sku,
    // Output
    FOvrPurchase& Purchase,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [Sku]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_IAP_LaunchCheckoutFlow(TCHAR_TO_UTF8(*Sku));

                    return RequestID;
                },
                // Response Processor
                [&Purchase](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        Purchase.Clear();
                    }
                    else
                    {
                        Purchase.Update(ovr_Message_GetPurchase(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

// ----------------------------------------------------------------------
// LanguagePack

void UOvrRequestsBlueprintLibrary::LanguagePack_GetCurrent(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Output
    FOvrAssetDetails& AssetDetails,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                []()->ovrRequest
                {
                    ovrRequest RequestID = ovr_LanguagePack_GetCurrent();

                    return RequestID;
                },
                // Response Processor
                [&AssetDetails](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        AssetDetails.Clear();
                    }
                    else
                    {
                        AssetDetails.Update(ovr_Message_GetAssetDetails(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::LanguagePack_SetCurrent(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FString Tag,
    // Output
    FOvrAssetFileDownloadResult& AssetFileDownloadResult,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [Tag]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_LanguagePack_SetCurrent(TCHAR_TO_UTF8(*Tag));

                    return RequestID;
                },
                // Response Processor
                [&AssetFileDownloadResult](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        AssetFileDownloadResult.Clear();
                    }
                    else
                    {
                        AssetFileDownloadResult.Update(ovr_Message_GetAssetFileDownloadResult(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

// ----------------------------------------------------------------------
// Leaderboard

void UOvrRequestsBlueprintLibrary::Leaderboard_Get(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FString LeaderboardName,
    // Output
    FOvrLeaderboardPages& LeaderboardPages,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [LeaderboardName]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Leaderboard_Get(TCHAR_TO_UTF8(*LeaderboardName));

                    return RequestID;
                },
                // Response Processor
                [&LeaderboardPages](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        LeaderboardPages.Clear();
                    }
                    else
                    {
                        LeaderboardPages.Update(ovr_Message_GetLeaderboardArray(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::Leaderboard_GetEntries(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FString LeaderboardName,
    int32 Limit,
    EOvrLeaderboardFilterType Filter,
    EOvrLeaderboardStartAt StartAt,
    // Output
    FOvrLeaderboardEntryPages& LeaderboardEntryPages,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [LeaderboardName, Limit, Filter, StartAt]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Leaderboard_GetEntries(TCHAR_TO_UTF8(*LeaderboardName), static_cast<int>(Limit), ConvertLeaderboardFilterType(Filter), ConvertLeaderboardStartAt(StartAt));

                    return RequestID;
                },
                // Response Processor
                [&LeaderboardEntryPages](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        LeaderboardEntryPages.Clear();
                    }
                    else
                    {
                        LeaderboardEntryPages.Update(ovr_Message_GetLeaderboardEntryArray(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::Leaderboard_GetEntriesAfterRank(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FString LeaderboardName,
    int32 Limit,
    int64 AfterRank,
    // Output
    FOvrLeaderboardEntryPages& LeaderboardEntryPages,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [LeaderboardName, Limit, AfterRank]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Leaderboard_GetEntriesAfterRank(TCHAR_TO_UTF8(*LeaderboardName), static_cast<int>(Limit), static_cast<unsigned long long>(AfterRank));

                    return RequestID;
                },
                // Response Processor
                [&LeaderboardEntryPages](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        LeaderboardEntryPages.Clear();
                    }
                    else
                    {
                        LeaderboardEntryPages.Update(ovr_Message_GetLeaderboardEntryArray(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::Leaderboard_GetEntriesByIds(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FString LeaderboardName,
    int32 Limit,
    EOvrLeaderboardStartAt StartAt,
    TArray<FOvrId> UserIDs,
    // Output
    FOvrLeaderboardEntryPages& LeaderboardEntryPages,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [LeaderboardName, Limit, StartAt, UserIDs]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Leaderboard_GetEntriesByIds(TCHAR_TO_UTF8(*LeaderboardName), static_cast<int>(Limit), ConvertLeaderboardStartAt(StartAt), OvrPlatformIdArray(UserIDs), static_cast<unsigned int>(UserIDs.Num()));

                    return RequestID;
                },
                // Response Processor
                [&LeaderboardEntryPages](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        LeaderboardEntryPages.Clear();
                    }
                    else
                    {
                        LeaderboardEntryPages.Update(ovr_Message_GetLeaderboardEntryArray(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::Leaderboard_WriteEntry(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FString LeaderboardName,
    int64 Score,
    TArray<uint8> ExtraData,
    bool ForceUpdate,
    // Output
    FOvrLeaderboardUpdateStatus& LeaderboardUpdateStatus,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [LeaderboardName, Score, ExtraData, ForceUpdate]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Leaderboard_WriteEntry(TCHAR_TO_UTF8(*LeaderboardName), static_cast<long long>(Score), OvrPlatformByteArray(ExtraData), static_cast<unsigned int>(ExtraData.Num()), ForceUpdate);

                    return RequestID;
                },
                // Response Processor
                [&LeaderboardUpdateStatus](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        LeaderboardUpdateStatus.Clear();
                    }
                    else
                    {
                        LeaderboardUpdateStatus.Update(ovr_Message_GetLeaderboardUpdateStatus(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::Leaderboard_WriteEntryWithSupplementaryMetric(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FString LeaderboardName,
    int64 Score,
    int64 SupplementaryMetric,
    TArray<uint8> ExtraData,
    bool ForceUpdate,
    // Output
    FOvrLeaderboardUpdateStatus& LeaderboardUpdateStatus,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [LeaderboardName, Score, SupplementaryMetric, ExtraData, ForceUpdate]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Leaderboard_WriteEntryWithSupplementaryMetric(TCHAR_TO_UTF8(*LeaderboardName), static_cast<long long>(Score), static_cast<long long>(SupplementaryMetric), OvrPlatformByteArray(ExtraData), static_cast<unsigned int>(ExtraData.Num()), ForceUpdate);

                    return RequestID;
                },
                // Response Processor
                [&LeaderboardUpdateStatus](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        LeaderboardUpdateStatus.Clear();
                    }
                    else
                    {
                        LeaderboardUpdateStatus.Update(ovr_Message_GetLeaderboardUpdateStatus(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

// ----------------------------------------------------------------------
// Media

void UOvrRequestsBlueprintLibrary::Media_ShareToFacebook(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FString PostTextSuggestion,
    FString FilePath,
    EOvrMediaContentType ContentType,
    // Output
    FOvrShareMediaResult& ShareMediaResult,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [PostTextSuggestion, FilePath, ContentType]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Media_ShareToFacebook(TCHAR_TO_UTF8(*PostTextSuggestion), TCHAR_TO_UTF8(*FilePath), ConvertMediaContentType(ContentType));

                    return RequestID;
                },
                // Response Processor
                [&ShareMediaResult](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        ShareMediaResult.Clear();
                    }
                    else
                    {
                        ShareMediaResult.Update(ovr_Message_GetShareMediaResult(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

// ----------------------------------------------------------------------
// Notification

void UOvrRequestsBlueprintLibrary::Notification_MarkAsRead(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FOvrId NotificationID,
    // Output
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [NotificationID]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Notification_MarkAsRead(static_cast<ovrID>(NotificationID));

                    return RequestID;
                },
                // Response Processor
                [](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // No payload in response
                }));
    }
}

// ----------------------------------------------------------------------
// Party

void UOvrRequestsBlueprintLibrary::Party_GetCurrent(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Output
    FOvrParty& Party,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                []()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Party_GetCurrent();

                    return RequestID;
                },
                // Response Processor
                [&Party](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        Party.Clear();
                    }
                    else
                    {
                        Party.Update(ovr_Message_GetParty(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

// ----------------------------------------------------------------------
// RichPresence

void UOvrRequestsBlueprintLibrary::RichPresence_Clear(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Output
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                []()->ovrRequest
                {
                    ovrRequest RequestID = ovr_RichPresence_Clear();

                    return RequestID;
                },
                // Response Processor
                [](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // No payload in response
                }));
    }
}

void UOvrRequestsBlueprintLibrary::RichPresence_GetDestinations(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Output
    FOvrDestinationPages& DestinationPages,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                []()->ovrRequest
                {
                    ovrRequest RequestID = ovr_RichPresence_GetDestinations();

                    return RequestID;
                },
                // Response Processor
                [&DestinationPages](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        DestinationPages.Clear();
                    }
                    else
                    {
                        DestinationPages.Update(ovr_Message_GetDestinationArray(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::RichPresence_Set(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FOvrRichPresenceOptions RichPresenceOptions,
    // Output
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [RichPresenceOptions]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_RichPresence_Set(FOvrRichPresenceOptionsConverter(RichPresenceOptions));

                    return RequestID;
                },
                // Response Processor
                [](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // No payload in response
                }));
    }
}

// ----------------------------------------------------------------------
// User

void UOvrRequestsBlueprintLibrary::User_Get(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FOvrId UserID,
    // Output
    FOvrUser& User,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [UserID]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_User_Get(static_cast<ovrID>(UserID));

                    return RequestID;
                },
                // Response Processor
                [&User](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        User.Clear();
                    }
                    else
                    {
                        User.Update(ovr_Message_GetUser(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::User_GetAccessToken(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Output
    FString& StringPayload,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                []()->ovrRequest
                {
                    ovrRequest RequestID = ovr_User_GetAccessToken();

                    return RequestID;
                },
                // Response Processor
                [&StringPayload](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        StringPayload = TEXT("");
                    }
                    else
                    {
                        StringPayload = UTF8_TO_TCHAR(ovr_Message_GetString(*MessagePtr));
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::User_GetBlockedUsers(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Output
    FOvrBlockedUserPages& BlockedUserPages,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                []()->ovrRequest
                {
                    ovrRequest RequestID = ovr_User_GetBlockedUsers();

                    return RequestID;
                },
                // Response Processor
                [&BlockedUserPages](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        BlockedUserPages.Clear();
                    }
                    else
                    {
                        BlockedUserPages.Update(ovr_Message_GetBlockedUserArray(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::User_GetLoggedInUser(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Output
    FOvrUser& User,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                []()->ovrRequest
                {
                    ovrRequest RequestID = ovr_User_GetLoggedInUser();

                    return RequestID;
                },
                // Response Processor
                [&User](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        User.Clear();
                    }
                    else
                    {
                        User.Update(ovr_Message_GetUser(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::User_GetLoggedInUserFriends(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Output
    FOvrUserPages& UserPages,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                []()->ovrRequest
                {
                    ovrRequest RequestID = ovr_User_GetLoggedInUserFriends();

                    return RequestID;
                },
                // Response Processor
                [&UserPages](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        UserPages.Clear();
                    }
                    else
                    {
                        UserPages.Update(ovr_Message_GetUserArray(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::User_GetLoggedInUserManagedInfo(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Output
    FOvrUser& User,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                []()->ovrRequest
                {
                    ovrRequest RequestID = ovr_User_GetLoggedInUserManagedInfo();

                    return RequestID;
                },
                // Response Processor
                [&User](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        User.Clear();
                    }
                    else
                    {
                        User.Update(ovr_Message_GetUser(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::User_GetOrgScopedID(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FOvrId UserID,
    // Output
    FOvrOrgScopedID& OrgScopedID,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [UserID]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_User_GetOrgScopedID(static_cast<ovrID>(UserID));

                    return RequestID;
                },
                // Response Processor
                [&OrgScopedID](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        OrgScopedID.Clear();
                    }
                    else
                    {
                        OrgScopedID.Update(ovr_Message_GetOrgScopedID(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::User_GetSdkAccounts(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Output
    TArray<FOvrSdkAccount>& SdkAccountArray,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                []()->ovrRequest
                {
                    ovrRequest RequestID = ovr_User_GetSdkAccounts();

                    return RequestID;
                },
                // Response Processor
                [&SdkAccountArray](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        SdkAccountArray.Empty();
                    }
                    else
                    {
                        ovrSdkAccountArrayHandle SdkAccountArrayHandle = ovr_Message_GetSdkAccountArray(*MessagePtr);
                        size_t SdkAccountArraySize = ovr_SdkAccountArray_GetSize(SdkAccountArrayHandle);
                        SdkAccountArray.Empty(SdkAccountArraySize);
                        for (size_t Index = 0; Index < SdkAccountArraySize; ++Index)
                        {
                            SdkAccountArray.Add(FOvrSdkAccount(ovr_SdkAccountArray_GetElement(SdkAccountArrayHandle, Index), MessagePtr));
                        }
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::User_GetUserProof(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Output
    FOvrUserProof& UserProof,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                []()->ovrRequest
                {
                    ovrRequest RequestID = ovr_User_GetUserProof();

                    return RequestID;
                },
                // Response Processor
                [&UserProof](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        UserProof.Clear();
                    }
                    else
                    {
                        UserProof.Update(ovr_Message_GetUserProof(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::User_LaunchBlockFlow(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FOvrId UserID,
    // Output
    FOvrLaunchBlockFlowResult& LaunchBlockFlowResult,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [UserID]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_User_LaunchBlockFlow(static_cast<ovrID>(UserID));

                    return RequestID;
                },
                // Response Processor
                [&LaunchBlockFlowResult](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        LaunchBlockFlowResult.Clear();
                    }
                    else
                    {
                        LaunchBlockFlowResult.Update(ovr_Message_GetLaunchBlockFlowResult(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::User_LaunchFriendRequestFlow(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FOvrId UserID,
    // Output
    FOvrLaunchFriendRequestFlowResult& LaunchFriendRequestFlowResult,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [UserID]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_User_LaunchFriendRequestFlow(static_cast<ovrID>(UserID));

                    return RequestID;
                },
                // Response Processor
                [&LaunchFriendRequestFlowResult](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        LaunchFriendRequestFlowResult.Clear();
                    }
                    else
                    {
                        LaunchFriendRequestFlowResult.Update(ovr_Message_GetLaunchFriendRequestFlowResult(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::User_LaunchUnblockFlow(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    FOvrId UserID,
    // Output
    FOvrLaunchUnblockFlowResult& LaunchUnblockFlowResult,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [UserID]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_User_LaunchUnblockFlow(static_cast<ovrID>(UserID));

                    return RequestID;
                },
                // Response Processor
                [&LaunchUnblockFlowResult](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        LaunchUnblockFlowResult.Clear();
                    }
                    else
                    {
                        LaunchUnblockFlowResult.Update(ovr_Message_GetLaunchUnblockFlowResult(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

// ----------------------------------------------------------------------
// UserAgeCategory

void UOvrRequestsBlueprintLibrary::UserAgeCategory_Get(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Output
    FOvrUserAccountAgeCategory& UserAccountAgeCategory,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                []()->ovrRequest
                {
                    ovrRequest RequestID = ovr_UserAgeCategory_Get();

                    return RequestID;
                },
                // Response Processor
                [&UserAccountAgeCategory](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        UserAccountAgeCategory.Clear();
                    }
                    else
                    {
                        UserAccountAgeCategory.Update(ovr_Message_GetUserAccountAgeCategory(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::UserAgeCategory_Report(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    EOvrAppAgeCategory AgeCategory,
    // Output
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [AgeCategory]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_UserAgeCategory_Report(ConvertAppAgeCategory(AgeCategory));

                    return RequestID;
                },
                // Response Processor
                [](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    // No payload in response
                }));
    }
}

// ----------------------------------------------------------------------
// Voip

void UOvrRequestsBlueprintLibrary::Voip_GetMicrophoneAvailability(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Output
    FOvrMicrophoneAvailabilityState& MicrophoneAvailabilityState,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                []()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Voip_GetMicrophoneAvailability();

                    return RequestID;
                },
                // Response Processor
                [&MicrophoneAvailabilityState](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        MicrophoneAvailabilityState.Clear();
                    }
                    else
                    {
                        MicrophoneAvailabilityState.Update(ovr_Message_GetMicrophoneAvailabilityState(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

void UOvrRequestsBlueprintLibrary::Voip_SetSystemVoipSuppressed(
    // Context
    UObject* WorldContextObject,
    EOvrRequestOutputPins& OutExecs,
    FLatentActionInfo LatentInfo,
    // Input
    bool Suppressed,
    // Output
    FOvrSystemVoipState& SystemVoipState,
    FString& ErrorMsg)
{
    if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        OvrPlatformAddNewActionWithPreemption(
            World,
            LatentInfo.CallbackTarget, LatentInfo.UUID,
            new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                // Request Generator
                [Suppressed]()->ovrRequest
                {
                    ovrRequest RequestID = ovr_Voip_SetSystemVoipSuppressed(Suppressed);

                    return RequestID;
                },
                // Response Processor
                [&SystemVoipState](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    if (bIsError)
                    {
                        SystemVoipState.Clear();
                    }
                    else
                    {
                        SystemVoipState.Update(ovr_Message_GetSystemVoipState(*MessagePtr), MessagePtr);
                    }
                }));
    }
}

