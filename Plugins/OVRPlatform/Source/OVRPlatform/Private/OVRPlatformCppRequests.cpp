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

#include "OVRPlatformCppRequests.h"
#include "OVRPlatformRequestsConverters.h"
#include "OVRPlatformOptionsConverters.h"

#include "OVRPlatformSubsystem.h"

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
// CloudStorage

void OvrPlatform_CloudStorage_Delete(
    UGameInstance* GameInstance,
    FString Bucket,
    FString Key,
    OvrPlatform_CloudStorage_Delete_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_CloudStorage_Delete(TCHAR_TO_UTF8(*Bucket), TCHAR_TO_UTF8(*Key)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrCloudStorageUpdateResponsePtr ResponsePtr = MakeShared<FOvrCloudStorageUpdateResponse>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetCloudStorageUpdateResponse(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_CloudStorage_Load(
    UGameInstance* GameInstance,
    FString Bucket,
    FString Key,
    OvrPlatform_CloudStorage_Load_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_CloudStorage_Load(TCHAR_TO_UTF8(*Bucket), TCHAR_TO_UTF8(*Key)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrCloudStorageDataPtr ResponsePtr = MakeShared<FOvrCloudStorageData>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetCloudStorageData(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_CloudStorage_LoadBucketMetadata(
    UGameInstance* GameInstance,
    FString Bucket,
    OvrPlatform_CloudStorage_LoadBucketMetadata_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_CloudStorage_LoadBucketMetadata(TCHAR_TO_UTF8(*Bucket)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrCloudStorageMetadataArrayPtr ResponsePtr = MakeShared<FOvrCloudStorageMetadataPages>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetCloudStorageMetadataArray(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_CloudStorage_LoadConflictMetadata(
    UGameInstance* GameInstance,
    FString Bucket,
    FString Key,
    OvrPlatform_CloudStorage_LoadConflictMetadata_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_CloudStorage_LoadConflictMetadata(TCHAR_TO_UTF8(*Bucket), TCHAR_TO_UTF8(*Key)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrCloudStorageConflictMetadataPtr ResponsePtr = MakeShared<FOvrCloudStorageConflictMetadata>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetCloudStorageConflictMetadata(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_CloudStorage_LoadHandle(
    UGameInstance* GameInstance,
    FString Handle,
    OvrPlatform_CloudStorage_LoadHandle_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_CloudStorage_LoadHandle(TCHAR_TO_UTF8(*Handle)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrCloudStorageDataPtr ResponsePtr = MakeShared<FOvrCloudStorageData>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetCloudStorageData(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_CloudStorage_LoadMetadata(
    UGameInstance* GameInstance,
    FString Bucket,
    FString Key,
    OvrPlatform_CloudStorage_LoadMetadata_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_CloudStorage_LoadMetadata(TCHAR_TO_UTF8(*Bucket), TCHAR_TO_UTF8(*Key)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrCloudStorageMetadataPtr ResponsePtr = MakeShared<FOvrCloudStorageMetadata>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetCloudStorageMetadata(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_CloudStorage_ResolveKeepLocal(
    UGameInstance* GameInstance,
    FString Bucket,
    FString Key,
    FString RemoteHandle,
    OvrPlatform_CloudStorage_ResolveKeepLocal_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_CloudStorage_ResolveKeepLocal(TCHAR_TO_UTF8(*Bucket), TCHAR_TO_UTF8(*Key), TCHAR_TO_UTF8(*RemoteHandle)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrCloudStorageUpdateResponsePtr ResponsePtr = MakeShared<FOvrCloudStorageUpdateResponse>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetCloudStorageUpdateResponse(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_CloudStorage_ResolveKeepRemote(
    UGameInstance* GameInstance,
    FString Bucket,
    FString Key,
    FString RemoteHandle,
    OvrPlatform_CloudStorage_ResolveKeepRemote_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_CloudStorage_ResolveKeepRemote(TCHAR_TO_UTF8(*Bucket), TCHAR_TO_UTF8(*Key), TCHAR_TO_UTF8(*RemoteHandle)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrCloudStorageUpdateResponsePtr ResponsePtr = MakeShared<FOvrCloudStorageUpdateResponse>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetCloudStorageUpdateResponse(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_CloudStorage_Save(
    UGameInstance* GameInstance,
    FString Bucket,
    FString Key,
    TArray<uint8> Data,
    int64 Counter,
    FString ExtraData,
    OvrPlatform_CloudStorage_Save_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_CloudStorage_Save(TCHAR_TO_UTF8(*Bucket), TCHAR_TO_UTF8(*Key), OvrPlatformByteArray(Data), static_cast<unsigned int>(Data.Num()), static_cast<long long>(Counter), TCHAR_TO_UTF8(*ExtraData)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrCloudStorageUpdateResponsePtr ResponsePtr = MakeShared<FOvrCloudStorageUpdateResponse>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetCloudStorageUpdateResponse(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

// ----------------------------------------------------------------------
// CloudStorage2

void OvrPlatform_CloudStorage2_GetUserDirectoryPath(
    UGameInstance* GameInstance,
    OvrPlatform_CloudStorage2_GetUserDirectoryPath_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_CloudStorage2_GetUserDirectoryPath(),
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
// Matchmaking

void OvrPlatform_Matchmaking_Browse(
    UGameInstance* GameInstance,
    FString Pool,
    FOvrMatchmakingCustomQueryData CustomQueryData,
    OvrPlatform_Matchmaking_Browse_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Matchmaking_Browse(TCHAR_TO_UTF8(*Pool), OvrPlatformMatchmakingCustomQueryData(CustomQueryData)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrMatchmakingBrowseResultPtr ResponsePtr = MakeShared<FOvrMatchmakingBrowseResult>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetMatchmakingBrowseResult(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Matchmaking_Browse2(
    UGameInstance* GameInstance,
    FString Pool,
    FOvrMatchmakingOptions MatchmakingOptions,
    OvrPlatform_Matchmaking_Browse2_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Matchmaking_Browse2(TCHAR_TO_UTF8(*Pool), FOvrMatchmakingOptionsConverter(MatchmakingOptions)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrMatchmakingBrowseResultPtr ResponsePtr = MakeShared<FOvrMatchmakingBrowseResult>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetMatchmakingBrowseResult(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Matchmaking_Cancel(
    UGameInstance* GameInstance,
    FString Pool,
    FString RequestHash,
    OvrPlatform_Matchmaking_Cancel_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Matchmaking_Cancel(TCHAR_TO_UTF8(*Pool), TCHAR_TO_UTF8(*RequestHash)),
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

void OvrPlatform_Matchmaking_Cancel2(
    UGameInstance* GameInstance,
    OvrPlatform_Matchmaking_Cancel2_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Matchmaking_Cancel2(),
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

void OvrPlatform_Matchmaking_CreateAndEnqueueRoom(
    UGameInstance* GameInstance,
    FString Pool,
    int32 MaxUsers,
    bool SubscribeToUpdates,
    FOvrMatchmakingCustomQueryData CustomQueryData,
    OvrPlatform_Matchmaking_CreateAndEnqueueRoom_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Matchmaking_CreateAndEnqueueRoom(TCHAR_TO_UTF8(*Pool), static_cast<unsigned int>(MaxUsers), SubscribeToUpdates, OvrPlatformMatchmakingCustomQueryData(CustomQueryData)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrMatchmakingEnqueueResultAndRoomPtr ResponsePtr = MakeShared<FOvrMatchmakingEnqueueResultAndRoom>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetMatchmakingEnqueueResultAndRoom(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Matchmaking_CreateAndEnqueueRoom2(
    UGameInstance* GameInstance,
    FString Pool,
    FOvrMatchmakingOptions MatchmakingOptions,
    OvrPlatform_Matchmaking_CreateAndEnqueueRoom2_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Matchmaking_CreateAndEnqueueRoom2(TCHAR_TO_UTF8(*Pool), FOvrMatchmakingOptionsConverter(MatchmakingOptions)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrMatchmakingEnqueueResultAndRoomPtr ResponsePtr = MakeShared<FOvrMatchmakingEnqueueResultAndRoom>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetMatchmakingEnqueueResultAndRoom(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Matchmaking_CreateRoom(
    UGameInstance* GameInstance,
    FString Pool,
    int32 MaxUsers,
    bool SubscribeToUpdates,
    OvrPlatform_Matchmaking_CreateRoom_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Matchmaking_CreateRoom(TCHAR_TO_UTF8(*Pool), static_cast<unsigned int>(MaxUsers), SubscribeToUpdates),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrRoomPtr ResponsePtr = MakeShared<FOvrRoom>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetRoom(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Matchmaking_CreateRoom2(
    UGameInstance* GameInstance,
    FString Pool,
    FOvrMatchmakingOptions MatchmakingOptions,
    OvrPlatform_Matchmaking_CreateRoom2_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Matchmaking_CreateRoom2(TCHAR_TO_UTF8(*Pool), FOvrMatchmakingOptionsConverter(MatchmakingOptions)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrRoomPtr ResponsePtr = MakeShared<FOvrRoom>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetRoom(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Matchmaking_Enqueue(
    UGameInstance* GameInstance,
    FString Pool,
    FOvrMatchmakingCustomQueryData CustomQueryData,
    OvrPlatform_Matchmaking_Enqueue_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Matchmaking_Enqueue(TCHAR_TO_UTF8(*Pool), OvrPlatformMatchmakingCustomQueryData(CustomQueryData)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrMatchmakingEnqueueResultPtr ResponsePtr = MakeShared<FOvrMatchmakingEnqueueResult>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetMatchmakingEnqueueResult(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Matchmaking_Enqueue2(
    UGameInstance* GameInstance,
    FString Pool,
    FOvrMatchmakingOptions MatchmakingOptions,
    OvrPlatform_Matchmaking_Enqueue2_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Matchmaking_Enqueue2(TCHAR_TO_UTF8(*Pool), FOvrMatchmakingOptionsConverter(MatchmakingOptions)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrMatchmakingEnqueueResultPtr ResponsePtr = MakeShared<FOvrMatchmakingEnqueueResult>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetMatchmakingEnqueueResult(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Matchmaking_EnqueueRoom(
    UGameInstance* GameInstance,
    FOvrId RoomID,
    FOvrMatchmakingCustomQueryData CustomQueryData,
    OvrPlatform_Matchmaking_EnqueueRoom_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Matchmaking_EnqueueRoom(static_cast<ovrID>(RoomID), OvrPlatformMatchmakingCustomQueryData(CustomQueryData)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrMatchmakingEnqueueResultPtr ResponsePtr = MakeShared<FOvrMatchmakingEnqueueResult>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetMatchmakingEnqueueResult(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Matchmaking_EnqueueRoom2(
    UGameInstance* GameInstance,
    FOvrId RoomID,
    FOvrMatchmakingOptions MatchmakingOptions,
    OvrPlatform_Matchmaking_EnqueueRoom2_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Matchmaking_EnqueueRoom2(static_cast<ovrID>(RoomID), FOvrMatchmakingOptionsConverter(MatchmakingOptions)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrMatchmakingEnqueueResultPtr ResponsePtr = MakeShared<FOvrMatchmakingEnqueueResult>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetMatchmakingEnqueueResult(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Matchmaking_GetAdminSnapshot(
    UGameInstance* GameInstance,
    OvrPlatform_Matchmaking_GetAdminSnapshot_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Matchmaking_GetAdminSnapshot(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrMatchmakingAdminSnapshotPtr ResponsePtr = MakeShared<FOvrMatchmakingAdminSnapshot>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetMatchmakingAdminSnapshot(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Matchmaking_GetStats(
    UGameInstance* GameInstance,
    FString Pool,
    int32 MaxLevel,
    EOvrMatchmakingStatApproach Approach,
    OvrPlatform_Matchmaking_GetStats_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Matchmaking_GetStats(TCHAR_TO_UTF8(*Pool), static_cast<unsigned int>(MaxLevel), ConvertMatchmakingStatApproach(Approach)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrMatchmakingStatsPtr ResponsePtr = MakeShared<FOvrMatchmakingStats>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetMatchmakingStats(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Matchmaking_JoinRoom(
    UGameInstance* GameInstance,
    FOvrId RoomID,
    bool SubscribeToUpdates,
    OvrPlatform_Matchmaking_JoinRoom_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Matchmaking_JoinRoom(static_cast<ovrID>(RoomID), SubscribeToUpdates),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrRoomPtr ResponsePtr = MakeShared<FOvrRoom>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetRoom(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Matchmaking_ReportResultInsecure(
    UGameInstance* GameInstance,
    FOvrId RoomID,
    TMap<FString, FOvrVariant> Data,
    OvrPlatform_Matchmaking_ReportResultInsecure_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Matchmaking_ReportResultInsecure(static_cast<ovrID>(RoomID), OvrPlatformKeyValuePairArray(Data), int(Data.Num())),
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

void OvrPlatform_Matchmaking_StartMatch(
    UGameInstance* GameInstance,
    FOvrId RoomID,
    OvrPlatform_Matchmaking_StartMatch_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Matchmaking_StartMatch(static_cast<ovrID>(RoomID)),
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

void OvrPlatform_Notification_GetRoomInvites(
    UGameInstance* GameInstance,
    OvrPlatform_Notification_GetRoomInvites_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Notification_GetRoomInvites(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrRoomInviteNotificationArrayPtr ResponsePtr = MakeShared<FOvrRoomInviteNotificationPages>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetRoomInviteNotificationArray(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

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
// Room

void OvrPlatform_Room_CreateAndJoinPrivate(
    UGameInstance* GameInstance,
    EOvrRoomJoinPolicy JoinPolicy,
    int32 MaxUsers,
    bool SubscribeToUpdates,
    OvrPlatform_Room_CreateAndJoinPrivate_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Room_CreateAndJoinPrivate(ConvertRoomJoinPolicy(JoinPolicy), static_cast<unsigned int>(MaxUsers), SubscribeToUpdates),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrRoomPtr ResponsePtr = MakeShared<FOvrRoom>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetRoom(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Room_CreateAndJoinPrivate2(
    UGameInstance* GameInstance,
    EOvrRoomJoinPolicy JoinPolicy,
    int32 MaxUsers,
    FOvrRoomOptions RoomOptions,
    OvrPlatform_Room_CreateAndJoinPrivate2_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Room_CreateAndJoinPrivate2(ConvertRoomJoinPolicy(JoinPolicy), static_cast<unsigned int>(MaxUsers), FOvrRoomOptionsConverter(RoomOptions)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrRoomPtr ResponsePtr = MakeShared<FOvrRoom>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetRoom(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Room_Get(
    UGameInstance* GameInstance,
    FOvrId RoomID,
    OvrPlatform_Room_Get_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Room_Get(static_cast<ovrID>(RoomID)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrRoomPtr ResponsePtr = MakeShared<FOvrRoom>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetRoom(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Room_GetCurrent(
    UGameInstance* GameInstance,
    OvrPlatform_Room_GetCurrent_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Room_GetCurrent(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrRoomPtr ResponsePtr = MakeShared<FOvrRoom>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetRoom(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Room_GetCurrentForUser(
    UGameInstance* GameInstance,
    FOvrId UserID,
    OvrPlatform_Room_GetCurrentForUser_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Room_GetCurrentForUser(static_cast<ovrID>(UserID)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrRoomPtr ResponsePtr = MakeShared<FOvrRoom>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetRoom(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Room_GetModeratedRooms(
    UGameInstance* GameInstance,
    OvrPlatform_Room_GetModeratedRooms_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Room_GetModeratedRooms(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrRoomArrayPtr ResponsePtr = MakeShared<FOvrRoomPages>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetRoomArray(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Room_Join(
    UGameInstance* GameInstance,
    FOvrId RoomID,
    bool SubscribeToUpdates,
    OvrPlatform_Room_Join_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Room_Join(static_cast<ovrID>(RoomID), SubscribeToUpdates),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrRoomPtr ResponsePtr = MakeShared<FOvrRoom>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetRoom(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Room_Join2(
    UGameInstance* GameInstance,
    FOvrId RoomID,
    FOvrRoomOptions RoomOptions,
    OvrPlatform_Room_Join2_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Room_Join2(static_cast<ovrID>(RoomID), FOvrRoomOptionsConverter(RoomOptions)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrRoomPtr ResponsePtr = MakeShared<FOvrRoom>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetRoom(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Room_KickUser(
    UGameInstance* GameInstance,
    FOvrId RoomID,
    FOvrId UserID,
    int32 KickDurationSeconds,
    OvrPlatform_Room_KickUser_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Room_KickUser(static_cast<ovrID>(RoomID), static_cast<ovrID>(UserID), static_cast<int>(KickDurationSeconds)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrRoomPtr ResponsePtr = MakeShared<FOvrRoom>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetRoom(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Room_Leave(
    UGameInstance* GameInstance,
    FOvrId RoomID,
    OvrPlatform_Room_Leave_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Room_Leave(static_cast<ovrID>(RoomID)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrRoomPtr ResponsePtr = MakeShared<FOvrRoom>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetRoom(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Room_SetDescription(
    UGameInstance* GameInstance,
    FOvrId RoomID,
    FString Description,
    OvrPlatform_Room_SetDescription_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Room_SetDescription(static_cast<ovrID>(RoomID), TCHAR_TO_UTF8(*Description)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrRoomPtr ResponsePtr = MakeShared<FOvrRoom>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetRoom(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Room_UpdateDataStore(
    UGameInstance* GameInstance,
    FOvrId RoomID,
    TMap<FString, FOvrVariant> Data,
    OvrPlatform_Room_UpdateDataStore_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Room_UpdateDataStore(static_cast<ovrID>(RoomID), OvrPlatformKeyValuePairArray(Data), int(Data.Num())),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrRoomPtr ResponsePtr = MakeShared<FOvrRoom>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetRoom(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Room_UpdateMembershipLockStatus(
    UGameInstance* GameInstance,
    FOvrId RoomID,
    EOvrRoomMembershipLockStatus MembershipLockStatus,
    OvrPlatform_Room_UpdateMembershipLockStatus_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Room_UpdateMembershipLockStatus(static_cast<ovrID>(RoomID), ConvertRoomMembershipLockStatus(MembershipLockStatus)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrRoomPtr ResponsePtr = MakeShared<FOvrRoom>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetRoom(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_Room_UpdateOwner(
    UGameInstance* GameInstance,
    FOvrId RoomID,
    FOvrId UserID,
    OvrPlatform_Room_UpdateOwner_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Room_UpdateOwner(static_cast<ovrID>(RoomID), static_cast<ovrID>(UserID)),
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

void OvrPlatform_Room_UpdatePrivateRoomJoinPolicy(
    UGameInstance* GameInstance,
    FOvrId RoomID,
    EOvrRoomJoinPolicy NewJoinPolicy,
    OvrPlatform_Room_UpdatePrivateRoomJoinPolicy_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_Room_UpdatePrivateRoomJoinPolicy(static_cast<ovrID>(RoomID), ConvertRoomJoinPolicy(NewJoinPolicy)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrRoomPtr ResponsePtr = MakeShared<FOvrRoom>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetRoom(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
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

void OvrPlatform_User_GetLoggedInUserFriendsAndRooms(
    UGameInstance* GameInstance,
    OvrPlatform_User_GetLoggedInUserFriendsAndRooms_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_User_GetLoggedInUserFriendsAndRooms(),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrUserAndRoomArrayPtr ResponsePtr = MakeShared<FOvrUserAndRoomPages>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetUserAndRoomArray(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_User_GetLoggedInUserRecentlyMetUsersAndRooms(
    UGameInstance* GameInstance,
    FOvrUserOptions UserOptions,
    OvrPlatform_User_GetLoggedInUserRecentlyMetUsersAndRooms_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_User_GetLoggedInUserRecentlyMetUsersAndRooms(FOvrUserOptionsConverter(UserOptions)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrUserAndRoomArrayPtr ResponsePtr = MakeShared<FOvrUserAndRoomPages>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetUserAndRoomArray(*MessagePtr), MessagePtr);
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

// ----------------------------------------------------------------------
// UserDataStore

void OvrPlatform_UserDataStore_PrivateDeleteEntryByKey(
    UGameInstance* GameInstance,
    FOvrId UserID,
    FString Key,
    OvrPlatform_UserDataStore_PrivateDeleteEntryByKey_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_UserDataStore_PrivateDeleteEntryByKey(static_cast<ovrID>(UserID), TCHAR_TO_UTF8(*Key)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrUserDataStoreUpdateResponsePtr ResponsePtr = MakeShared<FOvrUserDataStoreUpdateResponse>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetUserDataStoreUpdateResponse(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_UserDataStore_PrivateGetEntries(
    UGameInstance* GameInstance,
    FOvrId UserID,
    OvrPlatform_UserDataStore_PrivateGetEntries_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_UserDataStore_PrivateGetEntries(static_cast<ovrID>(UserID)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrDataStorePtr ResponsePtr = MakeShared<TMap<FString, FString>>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ovrDataStoreHandle DataStoreHandle = ovr_Message_GetDataStore(*MessagePtr);
                        size_t DataStoreSize = ovr_DataStore_GetNumKeys(DataStoreHandle);
                        for (size_t Index = 0; Index < DataStoreSize; Index++)
                        {
                            const char* CKey = ovr_DataStore_GetKey(DataStoreHandle, Index);
                            (*ResponsePtr)[UTF8_TO_TCHAR(CKey)] = UTF8_TO_TCHAR(ovr_DataStore_GetValue(DataStoreHandle, CKey));
                        }
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_UserDataStore_PrivateGetEntryByKey(
    UGameInstance* GameInstance,
    FOvrId UserID,
    FString Key,
    OvrPlatform_UserDataStore_PrivateGetEntryByKey_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_UserDataStore_PrivateGetEntryByKey(static_cast<ovrID>(UserID), TCHAR_TO_UTF8(*Key)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrDataStorePtr ResponsePtr = MakeShared<TMap<FString, FString>>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ovrDataStoreHandle DataStoreHandle = ovr_Message_GetDataStore(*MessagePtr);
                        size_t DataStoreSize = ovr_DataStore_GetNumKeys(DataStoreHandle);
                        for (size_t Index = 0; Index < DataStoreSize; Index++)
                        {
                            const char* CKey = ovr_DataStore_GetKey(DataStoreHandle, Index);
                            (*ResponsePtr)[UTF8_TO_TCHAR(CKey)] = UTF8_TO_TCHAR(ovr_DataStore_GetValue(DataStoreHandle, CKey));
                        }
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_UserDataStore_PrivateWriteEntry(
    UGameInstance* GameInstance,
    FOvrId UserID,
    FString Key,
    FString Value,
    OvrPlatform_UserDataStore_PrivateWriteEntry_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_UserDataStore_PrivateWriteEntry(static_cast<ovrID>(UserID), TCHAR_TO_UTF8(*Key), TCHAR_TO_UTF8(*Value)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrUserDataStoreUpdateResponsePtr ResponsePtr = MakeShared<FOvrUserDataStoreUpdateResponse>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetUserDataStoreUpdateResponse(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_UserDataStore_PublicDeleteEntryByKey(
    UGameInstance* GameInstance,
    FOvrId UserID,
    FString Key,
    OvrPlatform_UserDataStore_PublicDeleteEntryByKey_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_UserDataStore_PublicDeleteEntryByKey(static_cast<ovrID>(UserID), TCHAR_TO_UTF8(*Key)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrUserDataStoreUpdateResponsePtr ResponsePtr = MakeShared<FOvrUserDataStoreUpdateResponse>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetUserDataStoreUpdateResponse(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_UserDataStore_PublicGetEntries(
    UGameInstance* GameInstance,
    FOvrId UserID,
    OvrPlatform_UserDataStore_PublicGetEntries_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_UserDataStore_PublicGetEntries(static_cast<ovrID>(UserID)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrDataStorePtr ResponsePtr = MakeShared<TMap<FString, FString>>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ovrDataStoreHandle DataStoreHandle = ovr_Message_GetDataStore(*MessagePtr);
                        size_t DataStoreSize = ovr_DataStore_GetNumKeys(DataStoreHandle);
                        for (size_t Index = 0; Index < DataStoreSize; Index++)
                        {
                            const char* CKey = ovr_DataStore_GetKey(DataStoreHandle, Index);
                            (*ResponsePtr)[UTF8_TO_TCHAR(CKey)] = UTF8_TO_TCHAR(ovr_DataStore_GetValue(DataStoreHandle, CKey));
                        }
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_UserDataStore_PublicGetEntryByKey(
    UGameInstance* GameInstance,
    FOvrId UserID,
    FString Key,
    OvrPlatform_UserDataStore_PublicGetEntryByKey_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_UserDataStore_PublicGetEntryByKey(static_cast<ovrID>(UserID), TCHAR_TO_UTF8(*Key)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrDataStorePtr ResponsePtr = MakeShared<TMap<FString, FString>>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ovrDataStoreHandle DataStoreHandle = ovr_Message_GetDataStore(*MessagePtr);
                        size_t DataStoreSize = ovr_DataStore_GetNumKeys(DataStoreHandle);
                        for (size_t Index = 0; Index < DataStoreSize; Index++)
                        {
                            const char* CKey = ovr_DataStore_GetKey(DataStoreHandle, Index);
                            (*ResponsePtr)[UTF8_TO_TCHAR(CKey)] = UTF8_TO_TCHAR(ovr_DataStore_GetValue(DataStoreHandle, CKey));
                        }
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
                }));
    }
}

void OvrPlatform_UserDataStore_PublicWriteEntry(
    UGameInstance* GameInstance,
    FOvrId UserID,
    FString Key,
    FString Value,
    OvrPlatform_UserDataStore_PublicWriteEntry_Delegate&& Delegate)
{
    if (UOvrPlatformSubsystem* OvrPlatform = GameInstance->GetSubsystem<UOvrPlatformSubsystem>())
    {
        OvrPlatform->AddRequestDelegate(
            ovr_UserDataStore_PublicWriteEntry(static_cast<ovrID>(UserID), TCHAR_TO_UTF8(*Key), TCHAR_TO_UTF8(*Value)),
            FOvrPlatformMessageOnComplete::CreateLambda(
                [Delegate](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                {
                    FOvrUserDataStoreUpdateResponsePtr ResponsePtr = MakeShared<FOvrUserDataStoreUpdateResponse>();
                    FString ErrMsg;
                    if (bIsError)
                    {
                        ovrErrorHandle Error = ovr_Message_GetError(*MessagePtr);
                        ErrMsg = UTF8_TO_TCHAR(ovr_Error_GetMessage(Error));
                    }
                    else
                    {
                        ResponsePtr->Update(ovr_Message_GetUserDataStoreUpdateResponse(*MessagePtr), MessagePtr);
                    }

                    Delegate.ExecuteIfBound(!bIsError, ResponsePtr, ErrMsg);
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

