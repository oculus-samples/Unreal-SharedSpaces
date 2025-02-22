// Copyright (c) Meta Platforms, Inc. and affiliates.

// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#include "OVRPlatformCppRequests.h"
#include "OVRPlatformRequestsConverters.h"
#include "OVRPlatformOptionsConverters.h"

#include "OVRPlatformSubsystem.h"
#include "Engine/GameInstance.h"

// ----------------------------------------------------------------------
// AbuseReport

void OvrPlatform_AbuseReport_ReportRequestHandled(
    UGameInstance* GameInstance,
    EOvrReportRequestResponse Response,
    OvrPlatform_AbuseReport_ReportRequestHandled_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_AbuseReport_ReportRequestHandled(ConvertReportRequestResponse(Response)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }

                    Delegate.ExecuteIfBound(!bIsError, ErrMsg);
                }));
    }
}

// ----------------------------------------------------------------------
// Achievements

void OvrPlatform_Achievements_AddCount(
    UGameInstance* GameInstance,
    FString Name,
    int64 Count,
    OvrPlatform_Achievements_AddCount_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Achievements_AddCount(TCHAR_TO_UTF8(*Name), static_cast<unsigned long long>(Count)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrAchievementUpdatePtr ResponsePtr = MakeShared<FOvrAchievementUpdate>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetAchievementUpdate(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Achievements_AddFields(
    UGameInstance* GameInstance,
    FString Name,
    FString Fields,
    OvrPlatform_Achievements_AddFields_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Achievements_AddFields(TCHAR_TO_UTF8(*Name), TCHAR_TO_UTF8(*Fields)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrAchievementUpdatePtr ResponsePtr = MakeShared<FOvrAchievementUpdate>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetAchievementUpdate(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Achievements_GetAllDefinitions(
    UGameInstance* GameInstance,
    OvrPlatform_Achievements_GetAllDefinitions_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Achievements_GetAllDefinitions(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrAchievementDefinitionArrayPtr ResponsePtr = MakeShared<FOvrAchievementDefinitionPages>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetAchievementDefinitionArray(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Achievements_GetAllProgress(
    UGameInstance* GameInstance,
    OvrPlatform_Achievements_GetAllProgress_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Achievements_GetAllProgress(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrAchievementProgressArrayPtr ResponsePtr = MakeShared<FOvrAchievementProgressPages>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetAchievementProgressArray(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Achievements_GetDefinitionsByName(
    UGameInstance* GameInstance,
    TArray<FString> Names,
    OvrPlatform_Achievements_GetDefinitionsByName_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Achievements_GetDefinitionsByName(OvrPlatformStringArray(Names), static_cast<int>(Names.Num())),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrAchievementDefinitionArrayPtr ResponsePtr = MakeShared<FOvrAchievementDefinitionPages>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetAchievementDefinitionArray(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Achievements_GetProgressByName(
    UGameInstance* GameInstance,
    TArray<FString> Names,
    OvrPlatform_Achievements_GetProgressByName_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Achievements_GetProgressByName(OvrPlatformStringArray(Names), static_cast<int>(Names.Num())),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrAchievementProgressArrayPtr ResponsePtr = MakeShared<FOvrAchievementProgressPages>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetAchievementProgressArray(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Achievements_Unlock(
    UGameInstance* GameInstance,
    FString Name,
    OvrPlatform_Achievements_Unlock_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Achievements_Unlock(TCHAR_TO_UTF8(*Name)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrAchievementUpdatePtr ResponsePtr = MakeShared<FOvrAchievementUpdate>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetAchievementUpdate(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

// ----------------------------------------------------------------------
// Application

void OvrPlatform_Application_CancelAppDownload(
    UGameInstance* GameInstance,
    OvrPlatform_Application_CancelAppDownload_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Application_CancelAppDownload(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrAppDownloadResultPtr ResponsePtr = MakeShared<FOvrAppDownloadResult>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetAppDownloadResult(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Application_CheckAppDownloadProgress(
    UGameInstance* GameInstance,
    OvrPlatform_Application_CheckAppDownloadProgress_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Application_CheckAppDownloadProgress(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrAppDownloadProgressResultPtr ResponsePtr = MakeShared<FOvrAppDownloadProgressResult>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetAppDownloadProgressResult(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Application_GetVersion(
    UGameInstance* GameInstance,
    OvrPlatform_Application_GetVersion_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Application_GetVersion(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrApplicationVersionPtr ResponsePtr = MakeShared<FOvrApplicationVersion>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetApplicationVersion(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Application_InstallAppUpdateAndRelaunch(
    UGameInstance* GameInstance,
    FOvrApplicationOptions DeeplinkOptions,
    OvrPlatform_Application_InstallAppUpdateAndRelaunch_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Application_InstallAppUpdateAndRelaunch(FOvrApplicationOptionsConverter(DeeplinkOptions)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrAppDownloadResultPtr ResponsePtr = MakeShared<FOvrAppDownloadResult>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetAppDownloadResult(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Application_LaunchOtherApp(
    UGameInstance* GameInstance,
    FOvrId AppID,
    FOvrApplicationOptions DeeplinkOptions,
    OvrPlatform_Application_LaunchOtherApp_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Application_LaunchOtherApp(static_cast<ovrID>(AppID), FOvrApplicationOptionsConverter(DeeplinkOptions)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FStringPtr ResponsePtr = MakeShared<FString>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        *ResponsePtr = UTF8_TO_TCHAR(ovr_Message_GetString(*MessagePtr));
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Application_StartAppDownload(
    UGameInstance* GameInstance,
    OvrPlatform_Application_StartAppDownload_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Application_StartAppDownload(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrAppDownloadResultPtr ResponsePtr = MakeShared<FOvrAppDownloadResult>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetAppDownloadResult(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

// ----------------------------------------------------------------------
// ApplicationLifecycle

// ----------------------------------------------------------------------
// AssetFile

void OvrPlatform_AssetFile_Delete(
    UGameInstance* GameInstance,
    FOvrId AssetFileID,
    OvrPlatform_AssetFile_Delete_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_AssetFile_Delete(static_cast<ovrID>(AssetFileID)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrAssetFileDeleteResultPtr ResponsePtr = MakeShared<FOvrAssetFileDeleteResult>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetAssetFileDeleteResult(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_AssetFile_DeleteById(
    UGameInstance* GameInstance,
    FOvrId AssetFileID,
    OvrPlatform_AssetFile_DeleteById_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_AssetFile_DeleteById(static_cast<ovrID>(AssetFileID)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrAssetFileDeleteResultPtr ResponsePtr = MakeShared<FOvrAssetFileDeleteResult>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetAssetFileDeleteResult(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_AssetFile_DeleteByName(
    UGameInstance* GameInstance,
    FString AssetFileName,
    OvrPlatform_AssetFile_DeleteByName_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_AssetFile_DeleteByName(TCHAR_TO_UTF8(*AssetFileName)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrAssetFileDeleteResultPtr ResponsePtr = MakeShared<FOvrAssetFileDeleteResult>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetAssetFileDeleteResult(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_AssetFile_Download(
    UGameInstance* GameInstance,
    FOvrId AssetFileID,
    OvrPlatform_AssetFile_Download_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_AssetFile_Download(static_cast<ovrID>(AssetFileID)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrAssetFileDownloadResultPtr ResponsePtr = MakeShared<FOvrAssetFileDownloadResult>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetAssetFileDownloadResult(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_AssetFile_DownloadById(
    UGameInstance* GameInstance,
    FOvrId AssetFileID,
    OvrPlatform_AssetFile_DownloadById_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_AssetFile_DownloadById(static_cast<ovrID>(AssetFileID)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrAssetFileDownloadResultPtr ResponsePtr = MakeShared<FOvrAssetFileDownloadResult>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetAssetFileDownloadResult(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_AssetFile_DownloadByName(
    UGameInstance* GameInstance,
    FString AssetFileName,
    OvrPlatform_AssetFile_DownloadByName_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_AssetFile_DownloadByName(TCHAR_TO_UTF8(*AssetFileName)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrAssetFileDownloadResultPtr ResponsePtr = MakeShared<FOvrAssetFileDownloadResult>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetAssetFileDownloadResult(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_AssetFile_DownloadCancel(
    UGameInstance* GameInstance,
    FOvrId AssetFileID,
    OvrPlatform_AssetFile_DownloadCancel_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_AssetFile_DownloadCancel(static_cast<ovrID>(AssetFileID)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrAssetFileDownloadCancelResultPtr ResponsePtr = MakeShared<FOvrAssetFileDownloadCancelResult>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetAssetFileDownloadCancelResult(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_AssetFile_DownloadCancelById(
    UGameInstance* GameInstance,
    FOvrId AssetFileID,
    OvrPlatform_AssetFile_DownloadCancelById_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_AssetFile_DownloadCancelById(static_cast<ovrID>(AssetFileID)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrAssetFileDownloadCancelResultPtr ResponsePtr = MakeShared<FOvrAssetFileDownloadCancelResult>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetAssetFileDownloadCancelResult(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_AssetFile_DownloadCancelByName(
    UGameInstance* GameInstance,
    FString AssetFileName,
    OvrPlatform_AssetFile_DownloadCancelByName_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_AssetFile_DownloadCancelByName(TCHAR_TO_UTF8(*AssetFileName)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrAssetFileDownloadCancelResultPtr ResponsePtr = MakeShared<FOvrAssetFileDownloadCancelResult>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetAssetFileDownloadCancelResult(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_AssetFile_GetList(
    UGameInstance* GameInstance,
    OvrPlatform_AssetFile_GetList_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_AssetFile_GetList(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrAssetDetailsArrayPtr ResponsePtr = MakeShared<TArray<FOvrAssetDetails>>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ovrAssetDetailsArrayHandle AssetDetailsArrayHandle = ovr_Message_GetAssetDetailsArray(*MessagePtr);
                        size_t AssetDetailsArraySize = ovr_AssetDetailsArray_GetSize(AssetDetailsArrayHandle);
                        ResponsePtr->Empty(AssetDetailsArraySize);
                        for (size_t Index = 0; Index < AssetDetailsArraySize; ++Index)
                        {
                            ResponsePtr->Add(FOvrAssetDetails(ovr_AssetDetailsArray_GetElement(AssetDetailsArrayHandle, Index), MessagePtr));
                        }
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_AssetFile_Status(
    UGameInstance* GameInstance,
    FOvrId AssetFileID,
    OvrPlatform_AssetFile_Status_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_AssetFile_Status(static_cast<ovrID>(AssetFileID)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrAssetDetailsPtr ResponsePtr = MakeShared<FOvrAssetDetails>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetAssetDetails(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_AssetFile_StatusById(
    UGameInstance* GameInstance,
    FOvrId AssetFileID,
    OvrPlatform_AssetFile_StatusById_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_AssetFile_StatusById(static_cast<ovrID>(AssetFileID)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrAssetDetailsPtr ResponsePtr = MakeShared<FOvrAssetDetails>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetAssetDetails(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_AssetFile_StatusByName(
    UGameInstance* GameInstance,
    FString AssetFileName,
    OvrPlatform_AssetFile_StatusByName_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_AssetFile_StatusByName(TCHAR_TO_UTF8(*AssetFileName)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrAssetDetailsPtr ResponsePtr = MakeShared<FOvrAssetDetails>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetAssetDetails(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

// ----------------------------------------------------------------------
// Avatar

void OvrPlatform_Avatar_LaunchAvatarEditor(
    UGameInstance* GameInstance,
    FOvrAvatarEditorOptions Options,
    OvrPlatform_Avatar_LaunchAvatarEditor_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Avatar_LaunchAvatarEditor(FOvrAvatarEditorOptionsConverter(Options)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrAvatarEditorResultPtr ResponsePtr = MakeShared<FOvrAvatarEditorResult>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetAvatarEditorResult(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

// ----------------------------------------------------------------------
// Challenges

void OvrPlatform_Challenges_Create(
    UGameInstance* GameInstance,
    FString LeaderboardName,
    FOvrChallengeOptions ChallengeOptions,
    OvrPlatform_Challenges_Create_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Challenges_Create(TCHAR_TO_UTF8(*LeaderboardName), FOvrChallengeOptionsConverter(ChallengeOptions)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrChallengePtr ResponsePtr = MakeShared<FOvrChallenge>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetChallenge(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Challenges_DeclineInvite(
    UGameInstance* GameInstance,
    FOvrId ChallengeID,
    OvrPlatform_Challenges_DeclineInvite_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Challenges_DeclineInvite(static_cast<ovrID>(ChallengeID)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrChallengePtr ResponsePtr = MakeShared<FOvrChallenge>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetChallenge(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Challenges_Delete(
    UGameInstance* GameInstance,
    FOvrId ChallengeID,
    OvrPlatform_Challenges_Delete_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Challenges_Delete(static_cast<ovrID>(ChallengeID)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }

                    Delegate.ExecuteIfBound(!bIsError, ErrMsg);
                }));
    }
}

void OvrPlatform_Challenges_Get(
    UGameInstance* GameInstance,
    FOvrId ChallengeID,
    OvrPlatform_Challenges_Get_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Challenges_Get(static_cast<ovrID>(ChallengeID)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrChallengePtr ResponsePtr = MakeShared<FOvrChallenge>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetChallenge(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Challenges_GetEntries(
    UGameInstance* GameInstance,
    FOvrId ChallengeID,
    int32 Limit,
    EOvrLeaderboardFilterType Filter,
    EOvrLeaderboardStartAt StartAt,
    OvrPlatform_Challenges_GetEntries_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Challenges_GetEntries(static_cast<ovrID>(ChallengeID), static_cast<int>(Limit), ConvertLeaderboardFilterType(Filter), ConvertLeaderboardStartAt(StartAt)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrChallengeEntryArrayPtr ResponsePtr = MakeShared<FOvrChallengeEntryPages>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetChallengeEntryArray(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Challenges_GetEntriesAfterRank(
    UGameInstance* GameInstance,
    FOvrId ChallengeID,
    int32 Limit,
    int64 AfterRank,
    OvrPlatform_Challenges_GetEntriesAfterRank_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Challenges_GetEntriesAfterRank(static_cast<ovrID>(ChallengeID), static_cast<int>(Limit), static_cast<unsigned long long>(AfterRank)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrChallengeEntryArrayPtr ResponsePtr = MakeShared<FOvrChallengeEntryPages>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetChallengeEntryArray(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Challenges_GetEntriesByIds(
    UGameInstance* GameInstance,
    FOvrId ChallengeID,
    int32 Limit,
    EOvrLeaderboardStartAt StartAt,
    TArray<FOvrId> UserIDs,
    OvrPlatform_Challenges_GetEntriesByIds_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Challenges_GetEntriesByIds(static_cast<ovrID>(ChallengeID), static_cast<int>(Limit), ConvertLeaderboardStartAt(StartAt), OvrPlatformIdArray(UserIDs), static_cast<unsigned int>(UserIDs.Num())),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrChallengeEntryArrayPtr ResponsePtr = MakeShared<FOvrChallengeEntryPages>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetChallengeEntryArray(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Challenges_GetList(
    UGameInstance* GameInstance,
    FOvrChallengeOptions ChallengeOptions,
    int32 Limit,
    OvrPlatform_Challenges_GetList_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Challenges_GetList(FOvrChallengeOptionsConverter(ChallengeOptions), static_cast<int>(Limit)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrChallengeArrayPtr ResponsePtr = MakeShared<FOvrChallengePages>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetChallengeArray(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Challenges_Join(
    UGameInstance* GameInstance,
    FOvrId ChallengeID,
    OvrPlatform_Challenges_Join_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Challenges_Join(static_cast<ovrID>(ChallengeID)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrChallengePtr ResponsePtr = MakeShared<FOvrChallenge>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetChallenge(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Challenges_Leave(
    UGameInstance* GameInstance,
    FOvrId ChallengeID,
    OvrPlatform_Challenges_Leave_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Challenges_Leave(static_cast<ovrID>(ChallengeID)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrChallengePtr ResponsePtr = MakeShared<FOvrChallenge>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetChallenge(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Challenges_UpdateInfo(
    UGameInstance* GameInstance,
    FOvrId ChallengeID,
    FOvrChallengeOptions ChallengeOptions,
    OvrPlatform_Challenges_UpdateInfo_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Challenges_UpdateInfo(static_cast<ovrID>(ChallengeID), FOvrChallengeOptionsConverter(ChallengeOptions)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrChallengePtr ResponsePtr = MakeShared<FOvrChallenge>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetChallenge(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

// ----------------------------------------------------------------------
// Cowatching

void OvrPlatform_Cowatching_GetPresenterData(
    UGameInstance* GameInstance,
    OvrPlatform_Cowatching_GetPresenterData_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Cowatching_GetPresenterData(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FStringPtr ResponsePtr = MakeShared<FString>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        *ResponsePtr = UTF8_TO_TCHAR(ovr_Message_GetString(*MessagePtr));
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Cowatching_GetViewersData(
    UGameInstance* GameInstance,
    OvrPlatform_Cowatching_GetViewersData_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Cowatching_GetViewersData(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrCowatchViewerArrayPtr ResponsePtr = MakeShared<FOvrCowatchViewerPages>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetCowatchViewerArray(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Cowatching_IsInSession(
    UGameInstance* GameInstance,
    OvrPlatform_Cowatching_IsInSession_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Cowatching_IsInSession(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrCowatchingStatePtr ResponsePtr = MakeShared<FOvrCowatchingState>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetCowatchingState(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Cowatching_JoinSession(
    UGameInstance* GameInstance,
    OvrPlatform_Cowatching_JoinSession_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Cowatching_JoinSession(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }

                    Delegate.ExecuteIfBound(!bIsError, ErrMsg);
                }));
    }
}

void OvrPlatform_Cowatching_LaunchInviteDialog(
    UGameInstance* GameInstance,
    OvrPlatform_Cowatching_LaunchInviteDialog_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Cowatching_LaunchInviteDialog(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }

                    Delegate.ExecuteIfBound(!bIsError, ErrMsg);
                }));
    }
}

void OvrPlatform_Cowatching_LeaveSession(
    UGameInstance* GameInstance,
    OvrPlatform_Cowatching_LeaveSession_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Cowatching_LeaveSession(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }

                    Delegate.ExecuteIfBound(!bIsError, ErrMsg);
                }));
    }
}

void OvrPlatform_Cowatching_RequestToPresent(
    UGameInstance* GameInstance,
    OvrPlatform_Cowatching_RequestToPresent_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Cowatching_RequestToPresent(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }

                    Delegate.ExecuteIfBound(!bIsError, ErrMsg);
                }));
    }
}

void OvrPlatform_Cowatching_ResignFromPresenting(
    UGameInstance* GameInstance,
    OvrPlatform_Cowatching_ResignFromPresenting_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Cowatching_ResignFromPresenting(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }

                    Delegate.ExecuteIfBound(!bIsError, ErrMsg);
                }));
    }
}

void OvrPlatform_Cowatching_SetPresenterData(
    UGameInstance* GameInstance,
    FString VideoTitle,
    FString PresenterData,
    OvrPlatform_Cowatching_SetPresenterData_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Cowatching_SetPresenterData(TCHAR_TO_UTF8(*VideoTitle), TCHAR_TO_UTF8(*PresenterData)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }

                    Delegate.ExecuteIfBound(!bIsError, ErrMsg);
                }));
    }
}

void OvrPlatform_Cowatching_SetViewerData(
    UGameInstance* GameInstance,
    FString ViewerData,
    OvrPlatform_Cowatching_SetViewerData_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Cowatching_SetViewerData(TCHAR_TO_UTF8(*ViewerData)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }

                    Delegate.ExecuteIfBound(!bIsError, ErrMsg);
                }));
    }
}

// ----------------------------------------------------------------------
// DeviceApplicationIntegrity

void OvrPlatform_DeviceApplicationIntegrity_GetIntegrityToken(
    UGameInstance* GameInstance,
    FString ChallengeNonce,
    OvrPlatform_DeviceApplicationIntegrity_GetIntegrityToken_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_DeviceApplicationIntegrity_GetIntegrityToken(TCHAR_TO_UTF8(*ChallengeNonce)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FStringPtr ResponsePtr = MakeShared<FString>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        *ResponsePtr = UTF8_TO_TCHAR(ovr_Message_GetString(*MessagePtr));
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

// ----------------------------------------------------------------------
// Entitlement

void OvrPlatform_Entitlement_GetIsViewerEntitled(
    UGameInstance* GameInstance,
    OvrPlatform_Entitlement_GetIsViewerEntitled_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Entitlement_GetIsViewerEntitled(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }

                    Delegate.ExecuteIfBound(!bIsError, ErrMsg);
                }));
    }
}

// ----------------------------------------------------------------------
// GroupPresence

void OvrPlatform_GroupPresence_Clear(
    UGameInstance* GameInstance,
    OvrPlatform_GroupPresence_Clear_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_GroupPresence_Clear(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }

                    Delegate.ExecuteIfBound(!bIsError, ErrMsg);
                }));
    }
}

void OvrPlatform_GroupPresence_GetInvitableUsers(
    UGameInstance* GameInstance,
    FOvrInviteOptions Options,
    OvrPlatform_GroupPresence_GetInvitableUsers_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_GroupPresence_GetInvitableUsers(FOvrInviteOptionsConverter(Options)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrUserArrayPtr ResponsePtr = MakeShared<FOvrUserPages>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetUserArray(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_GroupPresence_GetSentInvites(
    UGameInstance* GameInstance,
    OvrPlatform_GroupPresence_GetSentInvites_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_GroupPresence_GetSentInvites(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrApplicationInviteArrayPtr ResponsePtr = MakeShared<FOvrApplicationInvitePages>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetApplicationInviteArray(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_GroupPresence_LaunchInvitePanel(
    UGameInstance* GameInstance,
    FOvrInviteOptions Options,
    OvrPlatform_GroupPresence_LaunchInvitePanel_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_GroupPresence_LaunchInvitePanel(FOvrInviteOptionsConverter(Options)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrInvitePanelResultInfoPtr ResponsePtr = MakeShared<FOvrInvitePanelResultInfo>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetInvitePanelResultInfo(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_GroupPresence_LaunchMultiplayerErrorDialog(
    UGameInstance* GameInstance,
    FOvrMultiplayerErrorOptions Options,
    OvrPlatform_GroupPresence_LaunchMultiplayerErrorDialog_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_GroupPresence_LaunchMultiplayerErrorDialog(FOvrMultiplayerErrorOptionsConverter(Options)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }

                    Delegate.ExecuteIfBound(!bIsError, ErrMsg);
                }));
    }
}

void OvrPlatform_GroupPresence_LaunchRejoinDialog(
    UGameInstance* GameInstance,
    FString LobbySessionId,
    FString MatchSessionId,
    FString DestinationApiName,
    OvrPlatform_GroupPresence_LaunchRejoinDialog_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_GroupPresence_LaunchRejoinDialog(TCHAR_TO_UTF8(*LobbySessionId), TCHAR_TO_UTF8(*MatchSessionId), TCHAR_TO_UTF8(*DestinationApiName)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrRejoinDialogResultPtr ResponsePtr = MakeShared<FOvrRejoinDialogResult>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetRejoinDialogResult(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_GroupPresence_LaunchRosterPanel(
    UGameInstance* GameInstance,
    FOvrRosterOptions Options,
    OvrPlatform_GroupPresence_LaunchRosterPanel_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_GroupPresence_LaunchRosterPanel(FOvrRosterOptionsConverter(Options)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }

                    Delegate.ExecuteIfBound(!bIsError, ErrMsg);
                }));
    }
}

void OvrPlatform_GroupPresence_SendInvites(
    UGameInstance* GameInstance,
    TArray<FOvrId> UserIDs,
    OvrPlatform_GroupPresence_SendInvites_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_GroupPresence_SendInvites(OvrPlatformIdArray(UserIDs), static_cast<unsigned int>(UserIDs.Num())),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrSendInvitesResultPtr ResponsePtr = MakeShared<FOvrSendInvitesResult>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetSendInvitesResult(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_GroupPresence_Set(
    UGameInstance* GameInstance,
    FOvrGroupPresenceOptions GroupPresenceOptions,
    OvrPlatform_GroupPresence_Set_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_GroupPresence_Set(FOvrGroupPresenceOptionsConverter(GroupPresenceOptions)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }

                    Delegate.ExecuteIfBound(!bIsError, ErrMsg);
                }));
    }
}

void OvrPlatform_GroupPresence_SetDeeplinkMessageOverride(
    UGameInstance* GameInstance,
    FString DeeplinkMessage,
    OvrPlatform_GroupPresence_SetDeeplinkMessageOverride_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_GroupPresence_SetDeeplinkMessageOverride(TCHAR_TO_UTF8(*DeeplinkMessage)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }

                    Delegate.ExecuteIfBound(!bIsError, ErrMsg);
                }));
    }
}

void OvrPlatform_GroupPresence_SetDestination(
    UGameInstance* GameInstance,
    FString ApiName,
    OvrPlatform_GroupPresence_SetDestination_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_GroupPresence_SetDestination(TCHAR_TO_UTF8(*ApiName)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }

                    Delegate.ExecuteIfBound(!bIsError, ErrMsg);
                }));
    }
}

void OvrPlatform_GroupPresence_SetIsJoinable(
    UGameInstance* GameInstance,
    bool IsJoinable,
    OvrPlatform_GroupPresence_SetIsJoinable_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_GroupPresence_SetIsJoinable(IsJoinable),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }

                    Delegate.ExecuteIfBound(!bIsError, ErrMsg);
                }));
    }
}

void OvrPlatform_GroupPresence_SetLobbySession(
    UGameInstance* GameInstance,
    FString Id,
    OvrPlatform_GroupPresence_SetLobbySession_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_GroupPresence_SetLobbySession(TCHAR_TO_UTF8(*Id)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }

                    Delegate.ExecuteIfBound(!bIsError, ErrMsg);
                }));
    }
}

void OvrPlatform_GroupPresence_SetMatchSession(
    UGameInstance* GameInstance,
    FString Id,
    OvrPlatform_GroupPresence_SetMatchSession_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_GroupPresence_SetMatchSession(TCHAR_TO_UTF8(*Id)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }

                    Delegate.ExecuteIfBound(!bIsError, ErrMsg);
                }));
    }
}

// ----------------------------------------------------------------------
// IAP

void OvrPlatform_IAP_ConsumePurchase(
    UGameInstance* GameInstance,
    FString Sku,
    OvrPlatform_IAP_ConsumePurchase_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_IAP_ConsumePurchase(TCHAR_TO_UTF8(*Sku)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }

                    Delegate.ExecuteIfBound(!bIsError, ErrMsg);
                }));
    }
}

void OvrPlatform_IAP_GetProductsBySKU(
    UGameInstance* GameInstance,
    TArray<FString> Skus,
    OvrPlatform_IAP_GetProductsBySKU_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_IAP_GetProductsBySKU(OvrPlatformStringArray(Skus), static_cast<int>(Skus.Num())),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrProductArrayPtr ResponsePtr = MakeShared<FOvrProductPages>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetProductArray(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_IAP_GetViewerPurchases(
    UGameInstance* GameInstance,
    OvrPlatform_IAP_GetViewerPurchases_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_IAP_GetViewerPurchases(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrPurchaseArrayPtr ResponsePtr = MakeShared<FOvrPurchasePages>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetPurchaseArray(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_IAP_GetViewerPurchasesDurableCache(
    UGameInstance* GameInstance,
    OvrPlatform_IAP_GetViewerPurchasesDurableCache_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_IAP_GetViewerPurchasesDurableCache(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrPurchaseArrayPtr ResponsePtr = MakeShared<FOvrPurchasePages>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetPurchaseArray(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_IAP_LaunchCheckoutFlow(
    UGameInstance* GameInstance,
    FString Sku,
    OvrPlatform_IAP_LaunchCheckoutFlow_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_IAP_LaunchCheckoutFlow(TCHAR_TO_UTF8(*Sku)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrPurchasePtr ResponsePtr = MakeShared<FOvrPurchase>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetPurchase(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

// ----------------------------------------------------------------------
// LanguagePack

void OvrPlatform_LanguagePack_GetCurrent(
    UGameInstance* GameInstance,
    OvrPlatform_LanguagePack_GetCurrent_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_LanguagePack_GetCurrent(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrAssetDetailsPtr ResponsePtr = MakeShared<FOvrAssetDetails>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetAssetDetails(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_LanguagePack_SetCurrent(
    UGameInstance* GameInstance,
    FString Tag,
    OvrPlatform_LanguagePack_SetCurrent_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_LanguagePack_SetCurrent(TCHAR_TO_UTF8(*Tag)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrAssetFileDownloadResultPtr ResponsePtr = MakeShared<FOvrAssetFileDownloadResult>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetAssetFileDownloadResult(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

// ----------------------------------------------------------------------
// Leaderboard

void OvrPlatform_Leaderboard_Get(
    UGameInstance* GameInstance,
    FString LeaderboardName,
    OvrPlatform_Leaderboard_Get_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Leaderboard_Get(TCHAR_TO_UTF8(*LeaderboardName)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrLeaderboardArrayPtr ResponsePtr = MakeShared<FOvrLeaderboardPages>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetLeaderboardArray(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Leaderboard_GetEntries(
    UGameInstance* GameInstance,
    FString LeaderboardName,
    int32 Limit,
    EOvrLeaderboardFilterType Filter,
    EOvrLeaderboardStartAt StartAt,
    OvrPlatform_Leaderboard_GetEntries_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Leaderboard_GetEntries(TCHAR_TO_UTF8(*LeaderboardName), static_cast<int>(Limit), ConvertLeaderboardFilterType(Filter), ConvertLeaderboardStartAt(StartAt)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrLeaderboardEntryArrayPtr ResponsePtr = MakeShared<FOvrLeaderboardEntryPages>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetLeaderboardEntryArray(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Leaderboard_GetEntriesAfterRank(
    UGameInstance* GameInstance,
    FString LeaderboardName,
    int32 Limit,
    int64 AfterRank,
    OvrPlatform_Leaderboard_GetEntriesAfterRank_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Leaderboard_GetEntriesAfterRank(TCHAR_TO_UTF8(*LeaderboardName), static_cast<int>(Limit), static_cast<unsigned long long>(AfterRank)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrLeaderboardEntryArrayPtr ResponsePtr = MakeShared<FOvrLeaderboardEntryPages>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetLeaderboardEntryArray(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Leaderboard_GetEntriesByIds(
    UGameInstance* GameInstance,
    FString LeaderboardName,
    int32 Limit,
    EOvrLeaderboardStartAt StartAt,
    TArray<FOvrId> UserIDs,
    OvrPlatform_Leaderboard_GetEntriesByIds_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Leaderboard_GetEntriesByIds(TCHAR_TO_UTF8(*LeaderboardName), static_cast<int>(Limit), ConvertLeaderboardStartAt(StartAt), OvrPlatformIdArray(UserIDs), static_cast<unsigned int>(UserIDs.Num())),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrLeaderboardEntryArrayPtr ResponsePtr = MakeShared<FOvrLeaderboardEntryPages>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetLeaderboardEntryArray(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Leaderboard_WriteEntry(
    UGameInstance* GameInstance,
    FString LeaderboardName,
    int64 Score,
    TArray<uint8> ExtraData,
    bool ForceUpdate,
    OvrPlatform_Leaderboard_WriteEntry_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Leaderboard_WriteEntry(TCHAR_TO_UTF8(*LeaderboardName), static_cast<long long>(Score), OvrPlatformByteArray(ExtraData), static_cast<unsigned int>(ExtraData.Num()), ForceUpdate),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrLeaderboardUpdateStatusPtr ResponsePtr = MakeShared<FOvrLeaderboardUpdateStatus>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetLeaderboardUpdateStatus(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Leaderboard_WriteEntryWithSupplementaryMetric(
    UGameInstance* GameInstance,
    FString LeaderboardName,
    int64 Score,
    int64 SupplementaryMetric,
    TArray<uint8> ExtraData,
    bool ForceUpdate,
    OvrPlatform_Leaderboard_WriteEntryWithSupplementaryMetric_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Leaderboard_WriteEntryWithSupplementaryMetric(TCHAR_TO_UTF8(*LeaderboardName), static_cast<long long>(Score), static_cast<long long>(SupplementaryMetric), OvrPlatformByteArray(ExtraData), static_cast<unsigned int>(ExtraData.Num()), ForceUpdate),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrLeaderboardUpdateStatusPtr ResponsePtr = MakeShared<FOvrLeaderboardUpdateStatus>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetLeaderboardUpdateStatus(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

// ----------------------------------------------------------------------
// Media

void OvrPlatform_Media_ShareToFacebook(
    UGameInstance* GameInstance,
    FString PostTextSuggestion,
    FString FilePath,
    EOvrMediaContentType ContentType,
    OvrPlatform_Media_ShareToFacebook_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Media_ShareToFacebook(TCHAR_TO_UTF8(*PostTextSuggestion), TCHAR_TO_UTF8(*FilePath), ConvertMediaContentType(ContentType)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrShareMediaResultPtr ResponsePtr = MakeShared<FOvrShareMediaResult>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetShareMediaResult(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

// ----------------------------------------------------------------------
// Notification

void OvrPlatform_Notification_MarkAsRead(
    UGameInstance* GameInstance,
    FOvrId NotificationID,
    OvrPlatform_Notification_MarkAsRead_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Notification_MarkAsRead(static_cast<ovrID>(NotificationID)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }

                    Delegate.ExecuteIfBound(!bIsError, ErrMsg);
                }));
    }
}

// ----------------------------------------------------------------------
// Party

void OvrPlatform_Party_GetCurrent(
    UGameInstance* GameInstance,
    OvrPlatform_Party_GetCurrent_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Party_GetCurrent(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrPartyPtr ResponsePtr = MakeShared<FOvrParty>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetParty(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

// ----------------------------------------------------------------------
// RichPresence

void OvrPlatform_RichPresence_Clear(
    UGameInstance* GameInstance,
    OvrPlatform_RichPresence_Clear_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_RichPresence_Clear(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }

                    Delegate.ExecuteIfBound(!bIsError, ErrMsg);
                }));
    }
}

void OvrPlatform_RichPresence_GetDestinations(
    UGameInstance* GameInstance,
    OvrPlatform_RichPresence_GetDestinations_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_RichPresence_GetDestinations(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrDestinationArrayPtr ResponsePtr = MakeShared<FOvrDestinationPages>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetDestinationArray(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_RichPresence_Set(
    UGameInstance* GameInstance,
    FOvrRichPresenceOptions RichPresenceOptions,
    OvrPlatform_RichPresence_Set_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_RichPresence_Set(FOvrRichPresenceOptionsConverter(RichPresenceOptions)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }

                    Delegate.ExecuteIfBound(!bIsError, ErrMsg);
                }));
    }
}

// ----------------------------------------------------------------------
// User

void OvrPlatform_User_Get(
    UGameInstance* GameInstance,
    FOvrId UserID,
    OvrPlatform_User_Get_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_User_Get(static_cast<ovrID>(UserID)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrUserPtr ResponsePtr = MakeShared<FOvrUser>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetUser(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_User_GetAccessToken(
    UGameInstance* GameInstance,
    OvrPlatform_User_GetAccessToken_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_User_GetAccessToken(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FStringPtr ResponsePtr = MakeShared<FString>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        *ResponsePtr = UTF8_TO_TCHAR(ovr_Message_GetString(*MessagePtr));
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_User_GetBlockedUsers(
    UGameInstance* GameInstance,
    OvrPlatform_User_GetBlockedUsers_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_User_GetBlockedUsers(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrBlockedUserArrayPtr ResponsePtr = MakeShared<FOvrBlockedUserPages>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetBlockedUserArray(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_User_GetLoggedInUser(
    UGameInstance* GameInstance,
    OvrPlatform_User_GetLoggedInUser_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_User_GetLoggedInUser(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrUserPtr ResponsePtr = MakeShared<FOvrUser>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetUser(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_User_GetLoggedInUserFriends(
    UGameInstance* GameInstance,
    OvrPlatform_User_GetLoggedInUserFriends_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_User_GetLoggedInUserFriends(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrUserArrayPtr ResponsePtr = MakeShared<FOvrUserPages>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetUserArray(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_User_GetLoggedInUserManagedInfo(
    UGameInstance* GameInstance,
    OvrPlatform_User_GetLoggedInUserManagedInfo_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_User_GetLoggedInUserManagedInfo(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrUserPtr ResponsePtr = MakeShared<FOvrUser>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetUser(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_User_GetOrgScopedID(
    UGameInstance* GameInstance,
    FOvrId UserID,
    OvrPlatform_User_GetOrgScopedID_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_User_GetOrgScopedID(static_cast<ovrID>(UserID)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrOrgScopedIDPtr ResponsePtr = MakeShared<FOvrOrgScopedID>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetOrgScopedID(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_User_GetSdkAccounts(
    UGameInstance* GameInstance,
    OvrPlatform_User_GetSdkAccounts_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_User_GetSdkAccounts(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrSdkAccountArrayPtr ResponsePtr = MakeShared<TArray<FOvrSdkAccount>>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ovrSdkAccountArrayHandle SdkAccountArrayHandle = ovr_Message_GetSdkAccountArray(*MessagePtr);
                        size_t SdkAccountArraySize = ovr_SdkAccountArray_GetSize(SdkAccountArrayHandle);
                        ResponsePtr->Empty(SdkAccountArraySize);
                        for (size_t Index = 0; Index < SdkAccountArraySize; ++Index)
                        {
                            ResponsePtr->Add(FOvrSdkAccount(ovr_SdkAccountArray_GetElement(SdkAccountArrayHandle, Index), MessagePtr));
                        }
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_User_GetUserProof(
    UGameInstance* GameInstance,
    OvrPlatform_User_GetUserProof_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_User_GetUserProof(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrUserProofPtr ResponsePtr = MakeShared<FOvrUserProof>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetUserProof(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_User_LaunchBlockFlow(
    UGameInstance* GameInstance,
    FOvrId UserID,
    OvrPlatform_User_LaunchBlockFlow_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_User_LaunchBlockFlow(static_cast<ovrID>(UserID)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrLaunchBlockFlowResultPtr ResponsePtr = MakeShared<FOvrLaunchBlockFlowResult>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetLaunchBlockFlowResult(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_User_LaunchFriendRequestFlow(
    UGameInstance* GameInstance,
    FOvrId UserID,
    OvrPlatform_User_LaunchFriendRequestFlow_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_User_LaunchFriendRequestFlow(static_cast<ovrID>(UserID)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrLaunchFriendRequestFlowResultPtr ResponsePtr = MakeShared<FOvrLaunchFriendRequestFlowResult>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetLaunchFriendRequestFlowResult(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_User_LaunchUnblockFlow(
    UGameInstance* GameInstance,
    FOvrId UserID,
    OvrPlatform_User_LaunchUnblockFlow_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_User_LaunchUnblockFlow(static_cast<ovrID>(UserID)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrLaunchUnblockFlowResultPtr ResponsePtr = MakeShared<FOvrLaunchUnblockFlowResult>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetLaunchUnblockFlowResult(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

// ----------------------------------------------------------------------
// UserAgeCategory

void OvrPlatform_UserAgeCategory_Get(
    UGameInstance* GameInstance,
    OvrPlatform_UserAgeCategory_Get_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_UserAgeCategory_Get(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrUserAccountAgeCategoryPtr ResponsePtr = MakeShared<FOvrUserAccountAgeCategory>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetUserAccountAgeCategory(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_UserAgeCategory_Report(
    UGameInstance* GameInstance,
    EOvrAppAgeCategory AgeCategory,
    OvrPlatform_UserAgeCategory_Report_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_UserAgeCategory_Report(ConvertAppAgeCategory(AgeCategory)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }

                    Delegate.ExecuteIfBound(!bIsError, ErrMsg);
                }));
    }
}

// ----------------------------------------------------------------------
// Voip

void OvrPlatform_Voip_GetMicrophoneAvailability(
    UGameInstance* GameInstance,
    OvrPlatform_Voip_GetMicrophoneAvailability_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Voip_GetMicrophoneAvailability(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrMicrophoneAvailabilityStatePtr ResponsePtr = MakeShared<FOvrMicrophoneAvailabilityState>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetMicrophoneAvailabilityState(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Voip_SetSystemVoipSuppressed(
    UGameInstance* GameInstance,
    bool Suppressed,
    OvrPlatform_Voip_SetSystemVoipSuppressed_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Voip_SetSystemVoipSuppressed(Suppressed),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrSystemVoipStatePtr ResponsePtr = MakeShared<FOvrSystemVoipState>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetSystemVoipState(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

