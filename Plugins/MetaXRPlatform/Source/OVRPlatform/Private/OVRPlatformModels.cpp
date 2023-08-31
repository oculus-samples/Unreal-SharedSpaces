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

#include "OVRPlatformModels.h"
#include "OVRPlatformRequestsConverters.h"

// -----------------------------------------------------------------------------
// FOvrAbuseReportRecording

FOvrAbuseReportRecording::FOvrAbuseReportRecording()
{
    Clear();
}

FOvrAbuseReportRecording::FOvrAbuseReportRecording(ovrAbuseReportRecordingHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrAbuseReportRecording::Clear()
{
    RecordingUuid = TEXT("");
}

void FOvrAbuseReportRecording::Update(ovrAbuseReportRecordingHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    RecordingUuid = UTF8_TO_TCHAR(ovr_AbuseReportRecording_GetRecordingUuid(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrAchievementDefinition

FOvrAchievementDefinition::FOvrAchievementDefinition()
{
    Clear();
}

FOvrAchievementDefinition::FOvrAchievementDefinition(ovrAchievementDefinitionHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrAchievementDefinition::Clear()
{
    AchievementType = EOvrAchievementType::Unknown;
    ApiName = TEXT("");
    BitfieldLength = 0;
    Target = 0;
}

void FOvrAchievementDefinition::Update(ovrAchievementDefinitionHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    AchievementType = ConvertAchievementType(ovr_AchievementDefinition_GetType(OvrHandle));
    ApiName = UTF8_TO_TCHAR(ovr_AchievementDefinition_GetName(OvrHandle));
    BitfieldLength = static_cast<int32>(ovr_AchievementDefinition_GetBitfieldLength(OvrHandle));
    Target = static_cast<int64>(ovr_AchievementDefinition_GetTarget(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrAchievementDefinitionPages

FOvrAchievementDefinitionPages::FOvrAchievementDefinitionPages()
{
    Clear();
}

FOvrAchievementDefinitionPages::FOvrAchievementDefinitionPages(ovrAchievementDefinitionArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(Handle, MessageHandlePtr);
}

void FOvrAchievementDefinitionPages::Clear()
{
    PagedArrayHandle = nullptr;
    PagedArrayMessageHandlePtr.reset();
}

void FOvrAchievementDefinitionPages::Update(ovrAchievementDefinitionArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr)
{
    PagedArrayHandle = Handle;
    PagedArrayMessageHandlePtr = MessageHandlePtr;
}

FOvrAchievementDefinition UOvrAchievementDefinitionPagesMethods::AchievementDefinitionPages_GetElement(const FOvrAchievementDefinitionPages& Model, int64 Index)
{
    return FOvrAchievementDefinition(ovr_AchievementDefinitionArray_GetElement(Model.PagedArrayHandle, static_cast<size_t>(Index)), Model.PagedArrayMessageHandlePtr);
}

FString UOvrAchievementDefinitionPagesMethods::AchievementDefinitionPages_GetNextUrl(const FOvrAchievementDefinitionPages& Model)
{
    return UTF8_TO_TCHAR(ovr_AchievementDefinitionArray_GetNextUrl(Model.PagedArrayHandle));
}

int64 UOvrAchievementDefinitionPagesMethods::AchievementDefinitionPages_GetSize(const FOvrAchievementDefinitionPages& Model)
{
    return static_cast<int64>(ovr_AchievementDefinitionArray_GetSize(Model.PagedArrayHandle));
}

bool UOvrAchievementDefinitionPagesMethods::AchievementDefinitionPages_HasNextPage(const FOvrAchievementDefinitionPages& Model)
{
    return ovr_AchievementDefinitionArray_HasNextPage(Model.PagedArrayHandle);
}

// -----------------------------------------------------------------------------
// FOvrAchievementProgress

FOvrAchievementProgress::FOvrAchievementProgress()
{
    Clear();
}

FOvrAchievementProgress::FOvrAchievementProgress(ovrAchievementProgressHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrAchievementProgress::Clear()
{
    Bitfield = TEXT("");
    Count = 0;
    IsUnlocked = false;
    Name = TEXT("");
    UnlockTime = FDateTime(0);
}

void FOvrAchievementProgress::Update(ovrAchievementProgressHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Bitfield = UTF8_TO_TCHAR(ovr_AchievementProgress_GetBitfield(OvrHandle));
    Count = static_cast<int64>(ovr_AchievementProgress_GetCount(OvrHandle));
    IsUnlocked = ovr_AchievementProgress_GetIsUnlocked(OvrHandle);
    Name = UTF8_TO_TCHAR(ovr_AchievementProgress_GetName(OvrHandle));
    UnlockTime = FDateTime::FromUnixTimestamp(ovr_AchievementProgress_GetUnlockTime(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrAchievementProgressPages

FOvrAchievementProgressPages::FOvrAchievementProgressPages()
{
    Clear();
}

FOvrAchievementProgressPages::FOvrAchievementProgressPages(ovrAchievementProgressArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(Handle, MessageHandlePtr);
}

void FOvrAchievementProgressPages::Clear()
{
    PagedArrayHandle = nullptr;
    PagedArrayMessageHandlePtr.reset();
}

void FOvrAchievementProgressPages::Update(ovrAchievementProgressArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr)
{
    PagedArrayHandle = Handle;
    PagedArrayMessageHandlePtr = MessageHandlePtr;
}

FOvrAchievementProgress UOvrAchievementProgressPagesMethods::AchievementProgressPages_GetElement(const FOvrAchievementProgressPages& Model, int64 Index)
{
    return FOvrAchievementProgress(ovr_AchievementProgressArray_GetElement(Model.PagedArrayHandle, static_cast<size_t>(Index)), Model.PagedArrayMessageHandlePtr);
}

FString UOvrAchievementProgressPagesMethods::AchievementProgressPages_GetNextUrl(const FOvrAchievementProgressPages& Model)
{
    return UTF8_TO_TCHAR(ovr_AchievementProgressArray_GetNextUrl(Model.PagedArrayHandle));
}

int64 UOvrAchievementProgressPagesMethods::AchievementProgressPages_GetSize(const FOvrAchievementProgressPages& Model)
{
    return static_cast<int64>(ovr_AchievementProgressArray_GetSize(Model.PagedArrayHandle));
}

bool UOvrAchievementProgressPagesMethods::AchievementProgressPages_HasNextPage(const FOvrAchievementProgressPages& Model)
{
    return ovr_AchievementProgressArray_HasNextPage(Model.PagedArrayHandle);
}

// -----------------------------------------------------------------------------
// FOvrAchievementUpdate

FOvrAchievementUpdate::FOvrAchievementUpdate()
{
    Clear();
}

FOvrAchievementUpdate::FOvrAchievementUpdate(ovrAchievementUpdateHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrAchievementUpdate::Clear()
{
    JustUnlocked = false;
    Name = TEXT("");
}

void FOvrAchievementUpdate::Update(ovrAchievementUpdateHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    JustUnlocked = ovr_AchievementUpdate_GetJustUnlocked(OvrHandle);
    Name = UTF8_TO_TCHAR(ovr_AchievementUpdate_GetName(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrAppDownloadProgressResult

FOvrAppDownloadProgressResult::FOvrAppDownloadProgressResult()
{
    Clear();
}

FOvrAppDownloadProgressResult::FOvrAppDownloadProgressResult(ovrAppDownloadProgressResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrAppDownloadProgressResult::Clear()
{
    DownloadBytes = 0;
    DownloadedBytes = 0;
    StatusCode = EOvrAppStatus::Unknown;
}

void FOvrAppDownloadProgressResult::Update(ovrAppDownloadProgressResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    DownloadBytes = static_cast<int64>(ovr_AppDownloadProgressResult_GetDownloadBytes(OvrHandle));
    DownloadedBytes = static_cast<int64>(ovr_AppDownloadProgressResult_GetDownloadedBytes(OvrHandle));
    StatusCode = ConvertAppStatus(ovr_AppDownloadProgressResult_GetStatusCode(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrAppDownloadResult

FOvrAppDownloadResult::FOvrAppDownloadResult()
{
    Clear();
}

FOvrAppDownloadResult::FOvrAppDownloadResult(ovrAppDownloadResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrAppDownloadResult::Clear()
{
    Timestamp = 0;
}

void FOvrAppDownloadResult::Update(ovrAppDownloadResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Timestamp = static_cast<int64>(ovr_AppDownloadResult_GetTimestamp(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrApplicationVersion

FOvrApplicationVersion::FOvrApplicationVersion()
{
    Clear();
}

FOvrApplicationVersion::FOvrApplicationVersion(ovrApplicationVersionHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrApplicationVersion::Clear()
{
    CurrentCode = 0;
    CurrentName = TEXT("");
    LatestCode = 0;
    LatestName = TEXT("");
    ReleaseDate = 0;
    Size = TEXT("");
}

void FOvrApplicationVersion::Update(ovrApplicationVersionHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    CurrentCode = static_cast<int32>(ovr_ApplicationVersion_GetCurrentCode(OvrHandle));
    CurrentName = UTF8_TO_TCHAR(ovr_ApplicationVersion_GetCurrentName(OvrHandle));
    LatestCode = static_cast<int32>(ovr_ApplicationVersion_GetLatestCode(OvrHandle));
    LatestName = UTF8_TO_TCHAR(ovr_ApplicationVersion_GetLatestName(OvrHandle));
    ReleaseDate = static_cast<int64>(ovr_ApplicationVersion_GetReleaseDate(OvrHandle));
    Size = UTF8_TO_TCHAR(ovr_ApplicationVersion_GetSize(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrAssetFileDeleteResult

FOvrAssetFileDeleteResult::FOvrAssetFileDeleteResult()
{
    Clear();
}

FOvrAssetFileDeleteResult::FOvrAssetFileDeleteResult(ovrAssetFileDeleteResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrAssetFileDeleteResult::Clear()
{
    AssetFileId = 0;
    AssetId = 0;
    Filepath = TEXT("");
    Success = false;
}

void FOvrAssetFileDeleteResult::Update(ovrAssetFileDeleteResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    AssetFileId = static_cast<FOvrId>(ovr_AssetFileDeleteResult_GetAssetFileId(OvrHandle));
    AssetId = static_cast<FOvrId>(ovr_AssetFileDeleteResult_GetAssetId(OvrHandle));
    Filepath = UTF8_TO_TCHAR(ovr_AssetFileDeleteResult_GetFilepath(OvrHandle));
    Success = ovr_AssetFileDeleteResult_GetSuccess(OvrHandle);
}

// -----------------------------------------------------------------------------
// FOvrAssetFileDownloadCancelResult

FOvrAssetFileDownloadCancelResult::FOvrAssetFileDownloadCancelResult()
{
    Clear();
}

FOvrAssetFileDownloadCancelResult::FOvrAssetFileDownloadCancelResult(ovrAssetFileDownloadCancelResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrAssetFileDownloadCancelResult::Clear()
{
    AssetFileId = 0;
    AssetId = 0;
    Filepath = TEXT("");
    Success = false;
}

void FOvrAssetFileDownloadCancelResult::Update(ovrAssetFileDownloadCancelResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    AssetFileId = static_cast<FOvrId>(ovr_AssetFileDownloadCancelResult_GetAssetFileId(OvrHandle));
    AssetId = static_cast<FOvrId>(ovr_AssetFileDownloadCancelResult_GetAssetId(OvrHandle));
    Filepath = UTF8_TO_TCHAR(ovr_AssetFileDownloadCancelResult_GetFilepath(OvrHandle));
    Success = ovr_AssetFileDownloadCancelResult_GetSuccess(OvrHandle);
}

// -----------------------------------------------------------------------------
// FOvrAssetFileDownloadResult

FOvrAssetFileDownloadResult::FOvrAssetFileDownloadResult()
{
    Clear();
}

FOvrAssetFileDownloadResult::FOvrAssetFileDownloadResult(ovrAssetFileDownloadResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrAssetFileDownloadResult::Clear()
{
    AssetId = 0;
    Filepath = TEXT("");
}

void FOvrAssetFileDownloadResult::Update(ovrAssetFileDownloadResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    AssetId = static_cast<FOvrId>(ovr_AssetFileDownloadResult_GetAssetId(OvrHandle));
    Filepath = UTF8_TO_TCHAR(ovr_AssetFileDownloadResult_GetFilepath(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrAssetFileDownloadUpdate

FOvrAssetFileDownloadUpdate::FOvrAssetFileDownloadUpdate()
{
    Clear();
}

FOvrAssetFileDownloadUpdate::FOvrAssetFileDownloadUpdate(ovrAssetFileDownloadUpdateHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrAssetFileDownloadUpdate::Clear()
{
    AssetFileId = 0;
    AssetId = 0;
    BytesTotal = 0;
    BytesTransferred = 0;
    Completed = false;
}

void FOvrAssetFileDownloadUpdate::Update(ovrAssetFileDownloadUpdateHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    AssetFileId = static_cast<FOvrId>(ovr_AssetFileDownloadUpdate_GetAssetFileId(OvrHandle));
    AssetId = static_cast<FOvrId>(ovr_AssetFileDownloadUpdate_GetAssetId(OvrHandle));
    BytesTotal = static_cast<int64>(ovr_AssetFileDownloadUpdate_GetBytesTotalLong(OvrHandle));
    BytesTransferred = static_cast<int64>(ovr_AssetFileDownloadUpdate_GetBytesTransferredLong(OvrHandle));
    Completed = ovr_AssetFileDownloadUpdate_GetCompleted(OvrHandle);
}

// -----------------------------------------------------------------------------
// FOvrAvatarEditorResult

FOvrAvatarEditorResult::FOvrAvatarEditorResult()
{
    Clear();
}

FOvrAvatarEditorResult::FOvrAvatarEditorResult(ovrAvatarEditorResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrAvatarEditorResult::Clear()
{
    RequestSent = false;
}

void FOvrAvatarEditorResult::Update(ovrAvatarEditorResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    RequestSent = ovr_AvatarEditorResult_GetRequestSent(OvrHandle);
}

// -----------------------------------------------------------------------------
// FOvrBlockedUser

FOvrBlockedUser::FOvrBlockedUser()
{
    Clear();
}

FOvrBlockedUser::FOvrBlockedUser(ovrBlockedUserHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrBlockedUser::Clear()
{
    Id = 0;
}

void FOvrBlockedUser::Update(ovrBlockedUserHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Id = static_cast<FOvrId>(ovr_BlockedUser_GetId(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrBlockedUserPages

FOvrBlockedUserPages::FOvrBlockedUserPages()
{
    Clear();
}

FOvrBlockedUserPages::FOvrBlockedUserPages(ovrBlockedUserArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(Handle, MessageHandlePtr);
}

void FOvrBlockedUserPages::Clear()
{
    PagedArrayHandle = nullptr;
    PagedArrayMessageHandlePtr.reset();
}

void FOvrBlockedUserPages::Update(ovrBlockedUserArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr)
{
    PagedArrayHandle = Handle;
    PagedArrayMessageHandlePtr = MessageHandlePtr;
}

FOvrBlockedUser UOvrBlockedUserPagesMethods::BlockedUserPages_GetElement(const FOvrBlockedUserPages& Model, int64 Index)
{
    return FOvrBlockedUser(ovr_BlockedUserArray_GetElement(Model.PagedArrayHandle, static_cast<size_t>(Index)), Model.PagedArrayMessageHandlePtr);
}

FString UOvrBlockedUserPagesMethods::BlockedUserPages_GetNextUrl(const FOvrBlockedUserPages& Model)
{
    return UTF8_TO_TCHAR(ovr_BlockedUserArray_GetNextUrl(Model.PagedArrayHandle));
}

int64 UOvrBlockedUserPagesMethods::BlockedUserPages_GetSize(const FOvrBlockedUserPages& Model)
{
    return static_cast<int64>(ovr_BlockedUserArray_GetSize(Model.PagedArrayHandle));
}

bool UOvrBlockedUserPagesMethods::BlockedUserPages_HasNextPage(const FOvrBlockedUserPages& Model)
{
    return ovr_BlockedUserArray_HasNextPage(Model.PagedArrayHandle);
}

// -----------------------------------------------------------------------------
// FOvrDestination

FOvrDestination::FOvrDestination()
{
    Clear();
}

FOvrDestination::FOvrDestination(ovrDestinationHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrDestination::Clear()
{
    ApiName = TEXT("");
    DeeplinkMessage = TEXT("");
    DisplayName = TEXT("");
}

void FOvrDestination::Update(ovrDestinationHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    ApiName = UTF8_TO_TCHAR(ovr_Destination_GetApiName(OvrHandle));
    DeeplinkMessage = UTF8_TO_TCHAR(ovr_Destination_GetDeeplinkMessage(OvrHandle));
    DisplayName = UTF8_TO_TCHAR(ovr_Destination_GetDisplayName(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrDestinationPages

FOvrDestinationPages::FOvrDestinationPages()
{
    Clear();
}

FOvrDestinationPages::FOvrDestinationPages(ovrDestinationArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(Handle, MessageHandlePtr);
}

void FOvrDestinationPages::Clear()
{
    PagedArrayHandle = nullptr;
    PagedArrayMessageHandlePtr.reset();
}

void FOvrDestinationPages::Update(ovrDestinationArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr)
{
    PagedArrayHandle = Handle;
    PagedArrayMessageHandlePtr = MessageHandlePtr;
}

FOvrDestination UOvrDestinationPagesMethods::DestinationPages_GetElement(const FOvrDestinationPages& Model, int64 Index)
{
    return FOvrDestination(ovr_DestinationArray_GetElement(Model.PagedArrayHandle, static_cast<size_t>(Index)), Model.PagedArrayMessageHandlePtr);
}

FString UOvrDestinationPagesMethods::DestinationPages_GetNextUrl(const FOvrDestinationPages& Model)
{
    return UTF8_TO_TCHAR(ovr_DestinationArray_GetNextUrl(Model.PagedArrayHandle));
}

int64 UOvrDestinationPagesMethods::DestinationPages_GetSize(const FOvrDestinationPages& Model)
{
    return static_cast<int64>(ovr_DestinationArray_GetSize(Model.PagedArrayHandle));
}

bool UOvrDestinationPagesMethods::DestinationPages_HasNextPage(const FOvrDestinationPages& Model)
{
    return ovr_DestinationArray_HasNextPage(Model.PagedArrayHandle);
}

// -----------------------------------------------------------------------------
// FOvrError

FOvrError::FOvrError()
{
    Clear();
}

FOvrError::FOvrError(ovrErrorHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrError::Clear()
{
    Code = 0;
    DisplayableMessage = TEXT("");
    HttpCode = 0;
    Message = TEXT("");
}

void FOvrError::Update(ovrErrorHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Code = static_cast<int32>(ovr_Error_GetCode(OvrHandle));
    DisplayableMessage = UTF8_TO_TCHAR(ovr_Error_GetDisplayableMessage(OvrHandle));
    HttpCode = static_cast<int32>(ovr_Error_GetHttpCode(OvrHandle));
    Message = UTF8_TO_TCHAR(ovr_Error_GetMessage(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrGroupPresenceJoinIntent

FOvrGroupPresenceJoinIntent::FOvrGroupPresenceJoinIntent()
{
    Clear();
}

FOvrGroupPresenceJoinIntent::FOvrGroupPresenceJoinIntent(ovrGroupPresenceJoinIntentHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrGroupPresenceJoinIntent::Clear()
{
    DeeplinkMessage = TEXT("");
    DestinationApiName = TEXT("");
    LobbySessionId = TEXT("");
    MatchSessionId = TEXT("");
}

void FOvrGroupPresenceJoinIntent::Update(ovrGroupPresenceJoinIntentHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    DeeplinkMessage = UTF8_TO_TCHAR(ovr_GroupPresenceJoinIntent_GetDeeplinkMessage(OvrHandle));
    DestinationApiName = UTF8_TO_TCHAR(ovr_GroupPresenceJoinIntent_GetDestinationApiName(OvrHandle));
    LobbySessionId = UTF8_TO_TCHAR(ovr_GroupPresenceJoinIntent_GetLobbySessionId(OvrHandle));
    MatchSessionId = UTF8_TO_TCHAR(ovr_GroupPresenceJoinIntent_GetMatchSessionId(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrGroupPresenceLeaveIntent

FOvrGroupPresenceLeaveIntent::FOvrGroupPresenceLeaveIntent()
{
    Clear();
}

FOvrGroupPresenceLeaveIntent::FOvrGroupPresenceLeaveIntent(ovrGroupPresenceLeaveIntentHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrGroupPresenceLeaveIntent::Clear()
{
    DestinationApiName = TEXT("");
    LobbySessionId = TEXT("");
    MatchSessionId = TEXT("");
}

void FOvrGroupPresenceLeaveIntent::Update(ovrGroupPresenceLeaveIntentHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    DestinationApiName = UTF8_TO_TCHAR(ovr_GroupPresenceLeaveIntent_GetDestinationApiName(OvrHandle));
    LobbySessionId = UTF8_TO_TCHAR(ovr_GroupPresenceLeaveIntent_GetLobbySessionId(OvrHandle));
    MatchSessionId = UTF8_TO_TCHAR(ovr_GroupPresenceLeaveIntent_GetMatchSessionId(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrHttpTransferUpdate

FOvrHttpTransferUpdate::FOvrHttpTransferUpdate()
{
    Clear();
}

FOvrHttpTransferUpdate::FOvrHttpTransferUpdate(ovrHttpTransferUpdateHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrHttpTransferUpdate::Clear()
{
    Bytes = TArray<uint8>();
    ID = FOvrId();
    IsCompleted = false;
}

void FOvrHttpTransferUpdate::Update(ovrHttpTransferUpdateHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Bytes = TArray<uint8>((uint8*)ovr_HttpTransferUpdate_GetBytes(OvrHandle), ovr_HttpTransferUpdate_GetSize(OvrHandle));
    ID = static_cast<FOvrId>(ovr_HttpTransferUpdate_GetID(OvrHandle));
    IsCompleted = ovr_HttpTransferUpdate_IsCompleted(OvrHandle);
}

// -----------------------------------------------------------------------------
// FOvrInstalledApplication

FOvrInstalledApplication::FOvrInstalledApplication()
{
    Clear();
}

FOvrInstalledApplication::FOvrInstalledApplication(ovrInstalledApplicationHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrInstalledApplication::Clear()
{
    ApplicationId = TEXT("");
    PackageName = TEXT("");
    Status = TEXT("");
    VersionCode = 0;
    VersionName = TEXT("");
}

void FOvrInstalledApplication::Update(ovrInstalledApplicationHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    ApplicationId = UTF8_TO_TCHAR(ovr_InstalledApplication_GetApplicationId(OvrHandle));
    PackageName = UTF8_TO_TCHAR(ovr_InstalledApplication_GetPackageName(OvrHandle));
    Status = UTF8_TO_TCHAR(ovr_InstalledApplication_GetStatus(OvrHandle));
    VersionCode = static_cast<int32>(ovr_InstalledApplication_GetVersionCode(OvrHandle));
    VersionName = UTF8_TO_TCHAR(ovr_InstalledApplication_GetVersionName(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrInvitePanelResultInfo

FOvrInvitePanelResultInfo::FOvrInvitePanelResultInfo()
{
    Clear();
}

FOvrInvitePanelResultInfo::FOvrInvitePanelResultInfo(ovrInvitePanelResultInfoHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrInvitePanelResultInfo::Clear()
{
    InvitesSent = false;
}

void FOvrInvitePanelResultInfo::Update(ovrInvitePanelResultInfoHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    InvitesSent = ovr_InvitePanelResultInfo_GetInvitesSent(OvrHandle);
}

// -----------------------------------------------------------------------------
// FOvrLanguagePackInfo

FOvrLanguagePackInfo::FOvrLanguagePackInfo()
{
    Clear();
}

FOvrLanguagePackInfo::FOvrLanguagePackInfo(ovrLanguagePackInfoHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrLanguagePackInfo::Clear()
{
    EnglishName = TEXT("");
    NativeName = TEXT("");
    Tag = TEXT("");
}

void FOvrLanguagePackInfo::Update(ovrLanguagePackInfoHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    EnglishName = UTF8_TO_TCHAR(ovr_LanguagePackInfo_GetEnglishName(OvrHandle));
    NativeName = UTF8_TO_TCHAR(ovr_LanguagePackInfo_GetNativeName(OvrHandle));
    Tag = UTF8_TO_TCHAR(ovr_LanguagePackInfo_GetTag(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrAssetDetails

FOvrAssetDetails::FOvrAssetDetails()
{
    Clear();
}

FOvrAssetDetails::FOvrAssetDetails(ovrAssetDetailsHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrAssetDetails::Clear()
{
    AssetId = 0;
    AssetType = TEXT("");
    DownloadStatus = TEXT("");
    Filepath = TEXT("");
    IapStatus = TEXT("");
    Language.Clear();
    Metadata = TEXT("");
}

void FOvrAssetDetails::Update(ovrAssetDetailsHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    AssetId = static_cast<FOvrId>(ovr_AssetDetails_GetAssetId(OvrHandle));
    AssetType = UTF8_TO_TCHAR(ovr_AssetDetails_GetAssetType(OvrHandle));
    DownloadStatus = UTF8_TO_TCHAR(ovr_AssetDetails_GetDownloadStatus(OvrHandle));
    Filepath = UTF8_TO_TCHAR(ovr_AssetDetails_GetFilepath(OvrHandle));
    IapStatus = UTF8_TO_TCHAR(ovr_AssetDetails_GetIapStatus(OvrHandle));
    Language.Update(ovr_AssetDetails_GetLanguage(OvrHandle), MessageHandlePtr);
    Metadata = UTF8_TO_TCHAR(ovr_AssetDetails_GetMetadata(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrLaunchBlockFlowResult

FOvrLaunchBlockFlowResult::FOvrLaunchBlockFlowResult()
{
    Clear();
}

FOvrLaunchBlockFlowResult::FOvrLaunchBlockFlowResult(ovrLaunchBlockFlowResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrLaunchBlockFlowResult::Clear()
{
    DidBlock = false;
    DidCancel = false;
}

void FOvrLaunchBlockFlowResult::Update(ovrLaunchBlockFlowResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    DidBlock = ovr_LaunchBlockFlowResult_GetDidBlock(OvrHandle);
    DidCancel = ovr_LaunchBlockFlowResult_GetDidCancel(OvrHandle);
}

// -----------------------------------------------------------------------------
// FOvrLaunchFriendRequestFlowResult

FOvrLaunchFriendRequestFlowResult::FOvrLaunchFriendRequestFlowResult()
{
    Clear();
}

FOvrLaunchFriendRequestFlowResult::FOvrLaunchFriendRequestFlowResult(ovrLaunchFriendRequestFlowResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrLaunchFriendRequestFlowResult::Clear()
{
    DidCancel = false;
    DidSendRequest = false;
}

void FOvrLaunchFriendRequestFlowResult::Update(ovrLaunchFriendRequestFlowResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    DidCancel = ovr_LaunchFriendRequestFlowResult_GetDidCancel(OvrHandle);
    DidSendRequest = ovr_LaunchFriendRequestFlowResult_GetDidSendRequest(OvrHandle);
}

// -----------------------------------------------------------------------------
// FOvrLaunchReportFlowResult

FOvrLaunchReportFlowResult::FOvrLaunchReportFlowResult()
{
    Clear();
}

FOvrLaunchReportFlowResult::FOvrLaunchReportFlowResult(ovrLaunchReportFlowResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrLaunchReportFlowResult::Clear()
{
    DidCancel = false;
    UserReportId = 0;
}

void FOvrLaunchReportFlowResult::Update(ovrLaunchReportFlowResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    DidCancel = ovr_LaunchReportFlowResult_GetDidCancel(OvrHandle);
    UserReportId = static_cast<FOvrId>(ovr_LaunchReportFlowResult_GetUserReportId(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrLaunchUnblockFlowResult

FOvrLaunchUnblockFlowResult::FOvrLaunchUnblockFlowResult()
{
    Clear();
}

FOvrLaunchUnblockFlowResult::FOvrLaunchUnblockFlowResult(ovrLaunchUnblockFlowResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrLaunchUnblockFlowResult::Clear()
{
    DidCancel = false;
    DidUnblock = false;
}

void FOvrLaunchUnblockFlowResult::Update(ovrLaunchUnblockFlowResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    DidCancel = ovr_LaunchUnblockFlowResult_GetDidCancel(OvrHandle);
    DidUnblock = ovr_LaunchUnblockFlowResult_GetDidUnblock(OvrHandle);
}

// -----------------------------------------------------------------------------
// FOvrLeaderboard

FOvrLeaderboard::FOvrLeaderboard()
{
    Clear();
}

FOvrLeaderboard::FOvrLeaderboard(ovrLeaderboardHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrLeaderboard::Clear()
{
    ApiName = TEXT("");
    Destination.Clear();
    ID = 0;
}

void FOvrLeaderboard::Update(ovrLeaderboardHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    ApiName = UTF8_TO_TCHAR(ovr_Leaderboard_GetApiName(OvrHandle));
    Destination.Update(ovr_Leaderboard_GetDestination(OvrHandle), MessageHandlePtr);
    ID = static_cast<FOvrId>(ovr_Leaderboard_GetID(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrLeaderboardPages

FOvrLeaderboardPages::FOvrLeaderboardPages()
{
    Clear();
}

FOvrLeaderboardPages::FOvrLeaderboardPages(ovrLeaderboardArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(Handle, MessageHandlePtr);
}

void FOvrLeaderboardPages::Clear()
{
    PagedArrayHandle = nullptr;
    PagedArrayMessageHandlePtr.reset();
}

void FOvrLeaderboardPages::Update(ovrLeaderboardArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr)
{
    PagedArrayHandle = Handle;
    PagedArrayMessageHandlePtr = MessageHandlePtr;
}

FOvrLeaderboard UOvrLeaderboardPagesMethods::LeaderboardPages_GetElement(const FOvrLeaderboardPages& Model, int64 Index)
{
    return FOvrLeaderboard(ovr_LeaderboardArray_GetElement(Model.PagedArrayHandle, static_cast<size_t>(Index)), Model.PagedArrayMessageHandlePtr);
}

FString UOvrLeaderboardPagesMethods::LeaderboardPages_GetNextUrl(const FOvrLeaderboardPages& Model)
{
    return UTF8_TO_TCHAR(ovr_LeaderboardArray_GetNextUrl(Model.PagedArrayHandle));
}

int64 UOvrLeaderboardPagesMethods::LeaderboardPages_GetSize(const FOvrLeaderboardPages& Model)
{
    return static_cast<int64>(ovr_LeaderboardArray_GetSize(Model.PagedArrayHandle));
}

bool UOvrLeaderboardPagesMethods::LeaderboardPages_HasNextPage(const FOvrLeaderboardPages& Model)
{
    return ovr_LeaderboardArray_HasNextPage(Model.PagedArrayHandle);
}

// -----------------------------------------------------------------------------
// FOvrLeaderboardUpdateStatus

FOvrLeaderboardUpdateStatus::FOvrLeaderboardUpdateStatus()
{
    Clear();
}

FOvrLeaderboardUpdateStatus::FOvrLeaderboardUpdateStatus(ovrLeaderboardUpdateStatusHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrLeaderboardUpdateStatus::Clear()
{
    DidUpdate = false;
    UpdatedChallengeIds = TArray<FOvrId>();
}

void FOvrLeaderboardUpdateStatus::Update(ovrLeaderboardUpdateStatusHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    DidUpdate = ovr_LeaderboardUpdateStatus_GetDidUpdate(OvrHandle);
    // UpdatedChallengeIds id array transfer
    size_t updated_challenge_ids_array_size = ovr_LeaderboardUpdateStatus_GetUpdatedChallengeIdsSize(OvrHandle);
    UpdatedChallengeIds.Reserve(updated_challenge_ids_array_size);
    for (size_t i=0; i<updated_challenge_ids_array_size; i++)
    {
        UpdatedChallengeIds.Add(FOvrId(ovr_LeaderboardUpdateStatus_GetUpdatedChallengeId(OvrHandle, i)));
    }
}

// -----------------------------------------------------------------------------
// FOvrLinkedAccount

FOvrLinkedAccount::FOvrLinkedAccount()
{
    Clear();
}

FOvrLinkedAccount::FOvrLinkedAccount(ovrLinkedAccountHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrLinkedAccount::Clear()
{
    AccessToken = TEXT("");
    ServiceProvider = EOvrServiceProvider::Unknown;
    UserId = TEXT("");
}

void FOvrLinkedAccount::Update(ovrLinkedAccountHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    AccessToken = UTF8_TO_TCHAR(ovr_LinkedAccount_GetAccessToken(OvrHandle));
    ServiceProvider = ConvertServiceProvider(ovr_LinkedAccount_GetServiceProvider(OvrHandle));
    UserId = UTF8_TO_TCHAR(ovr_LinkedAccount_GetUserId(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrLivestreamingApplicationStatus

FOvrLivestreamingApplicationStatus::FOvrLivestreamingApplicationStatus()
{
    Clear();
}

FOvrLivestreamingApplicationStatus::FOvrLivestreamingApplicationStatus(ovrLivestreamingApplicationStatusHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrLivestreamingApplicationStatus::Clear()
{
    StreamingEnabled = false;
}

void FOvrLivestreamingApplicationStatus::Update(ovrLivestreamingApplicationStatusHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    StreamingEnabled = ovr_LivestreamingApplicationStatus_GetStreamingEnabled(OvrHandle);
}

// -----------------------------------------------------------------------------
// FOvrLivestreamingStartResult

FOvrLivestreamingStartResult::FOvrLivestreamingStartResult()
{
    Clear();
}

FOvrLivestreamingStartResult::FOvrLivestreamingStartResult(ovrLivestreamingStartResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrLivestreamingStartResult::Clear()
{
    StreamingResult = EOvrLivestreamingStartStatus::Unknown;
}

void FOvrLivestreamingStartResult::Update(ovrLivestreamingStartResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    StreamingResult = ConvertLivestreamingStartStatus(ovr_LivestreamingStartResult_GetStreamingResult(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrLivestreamingStatus

FOvrLivestreamingStatus::FOvrLivestreamingStatus()
{
    Clear();
}

FOvrLivestreamingStatus::FOvrLivestreamingStatus(ovrLivestreamingStatusHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrLivestreamingStatus::Clear()
{
    CommentsVisible = false;
    IsPaused = false;
    LivestreamingEnabled = false;
    LivestreamingType = 0;
    MicEnabled = false;
}

void FOvrLivestreamingStatus::Update(ovrLivestreamingStatusHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    CommentsVisible = ovr_LivestreamingStatus_GetCommentsVisible(OvrHandle);
    IsPaused = ovr_LivestreamingStatus_GetIsPaused(OvrHandle);
    LivestreamingEnabled = ovr_LivestreamingStatus_GetLivestreamingEnabled(OvrHandle);
    LivestreamingType = static_cast<int32>(ovr_LivestreamingStatus_GetLivestreamingType(OvrHandle));
    MicEnabled = ovr_LivestreamingStatus_GetMicEnabled(OvrHandle);
}

// -----------------------------------------------------------------------------
// FOvrLivestreamingVideoStats

FOvrLivestreamingVideoStats::FOvrLivestreamingVideoStats()
{
    Clear();
}

FOvrLivestreamingVideoStats::FOvrLivestreamingVideoStats(ovrLivestreamingVideoStatsHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrLivestreamingVideoStats::Clear()
{
    CommentCount = 0;
    ReactionCount = 0;
    TotalViews = TEXT("");
}

void FOvrLivestreamingVideoStats::Update(ovrLivestreamingVideoStatsHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    CommentCount = static_cast<int32>(ovr_LivestreamingVideoStats_GetCommentCount(OvrHandle));
    ReactionCount = static_cast<int32>(ovr_LivestreamingVideoStats_GetReactionCount(OvrHandle));
    TotalViews = UTF8_TO_TCHAR(ovr_LivestreamingVideoStats_GetTotalViews(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrMicrophone

FOvrMicrophone::FOvrMicrophone()
{
    Clear();
}

FOvrMicrophone::FOvrMicrophone(ovrMicrophoneHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrMicrophone::Clear()
{
    Handle = nullptr;
}

void FOvrMicrophone::Update(ovrMicrophoneHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Handle = OvrHandle;
}

void UOvrMicrophoneMethods::Microphone_SetAcceptableRecordingDelayHint(FOvrMicrophone& Model, int64 DelayMs)
{
    ovr_Microphone_SetAcceptableRecordingDelayHint(Model.Handle, static_cast<size_t>(DelayMs));
}

void UOvrMicrophoneMethods::Microphone_Start(FOvrMicrophone& Model)
{
    ovr_Microphone_Start(Model.Handle);
}

void UOvrMicrophoneMethods::Microphone_Stop(FOvrMicrophone& Model)
{
    ovr_Microphone_Stop(Model.Handle);
}

// -----------------------------------------------------------------------------
// FOvrMicrophoneAvailabilityState

FOvrMicrophoneAvailabilityState::FOvrMicrophoneAvailabilityState()
{
    Clear();
}

FOvrMicrophoneAvailabilityState::FOvrMicrophoneAvailabilityState(ovrMicrophoneAvailabilityStateHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrMicrophoneAvailabilityState::Clear()
{
    MicrophoneAvailable = false;
}

void FOvrMicrophoneAvailabilityState::Update(ovrMicrophoneAvailabilityStateHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    MicrophoneAvailable = ovr_MicrophoneAvailabilityState_GetMicrophoneAvailable(OvrHandle);
}

// -----------------------------------------------------------------------------
// FOvrNetSyncConnection

FOvrNetSyncConnection::FOvrNetSyncConnection()
{
    Clear();
}

FOvrNetSyncConnection::FOvrNetSyncConnection(ovrNetSyncConnectionHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrNetSyncConnection::Clear()
{
    ConnectionId = 0;
    DisconnectReason = EOvrNetSyncDisconnectReason::Unknown;
    SessionId = 0;
    Status = EOvrNetSyncConnectionStatus::Unknown;
    ZoneId = TEXT("");
}

void FOvrNetSyncConnection::Update(ovrNetSyncConnectionHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    ConnectionId = static_cast<int64>(ovr_NetSyncConnection_GetConnectionId(OvrHandle));
    DisconnectReason = ConvertNetSyncDisconnectReason(ovr_NetSyncConnection_GetDisconnectReason(OvrHandle));
    SessionId = static_cast<FOvrId>(ovr_NetSyncConnection_GetSessionId(OvrHandle));
    Status = ConvertNetSyncConnectionStatus(ovr_NetSyncConnection_GetStatus(OvrHandle));
    ZoneId = UTF8_TO_TCHAR(ovr_NetSyncConnection_GetZoneId(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrNetSyncSession

FOvrNetSyncSession::FOvrNetSyncSession()
{
    Clear();
}

FOvrNetSyncSession::FOvrNetSyncSession(ovrNetSyncSessionHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrNetSyncSession::Clear()
{
    ConnectionId = 0;
    Muted = false;
    SessionId = 0;
    UserId = 0;
    VoipGroup = TEXT("");
}

void FOvrNetSyncSession::Update(ovrNetSyncSessionHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    ConnectionId = static_cast<int64>(ovr_NetSyncSession_GetConnectionId(OvrHandle));
    Muted = ovr_NetSyncSession_GetMuted(OvrHandle);
    SessionId = static_cast<FOvrId>(ovr_NetSyncSession_GetSessionId(OvrHandle));
    UserId = static_cast<FOvrId>(ovr_NetSyncSession_GetUserId(OvrHandle));
    VoipGroup = UTF8_TO_TCHAR(ovr_NetSyncSession_GetVoipGroup(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrNetSyncSessionsChangedNotification

FOvrNetSyncSessionsChangedNotification::FOvrNetSyncSessionsChangedNotification()
{
    Clear();
}

FOvrNetSyncSessionsChangedNotification::FOvrNetSyncSessionsChangedNotification(ovrNetSyncSessionsChangedNotificationHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrNetSyncSessionsChangedNotification::Clear()
{
    ConnectionId = 0;
    Sessions.Empty();
}

void FOvrNetSyncSessionsChangedNotification::Update(ovrNetSyncSessionsChangedNotificationHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    ConnectionId = static_cast<int64>(ovr_NetSyncSessionsChangedNotification_GetConnectionId(OvrHandle));
    // Sessions array transfer
    ovrNetSyncSessionArrayHandle sessions_array_handle = ovr_NetSyncSessionsChangedNotification_GetSessions(OvrHandle);
    size_t sessions_array_size = ovr_NetSyncSessionArray_GetSize(sessions_array_handle);
    Sessions.Reserve(sessions_array_size);
    for (size_t i=0; i<sessions_array_size; i++)
    {
        Sessions.Add(FOvrNetSyncSession(ovr_NetSyncSessionArray_GetElement(sessions_array_handle, i), MessageHandlePtr));
    }
}

// -----------------------------------------------------------------------------
// FOvrNetSyncSetSessionPropertyResult

FOvrNetSyncSetSessionPropertyResult::FOvrNetSyncSetSessionPropertyResult()
{
    Clear();
}

FOvrNetSyncSetSessionPropertyResult::FOvrNetSyncSetSessionPropertyResult(ovrNetSyncSetSessionPropertyResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrNetSyncSetSessionPropertyResult::Clear()
{
    Session.Clear();
}

void FOvrNetSyncSetSessionPropertyResult::Update(ovrNetSyncSetSessionPropertyResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Session.Update(ovr_NetSyncSetSessionPropertyResult_GetSession(OvrHandle), MessageHandlePtr);
}

// -----------------------------------------------------------------------------
// FOvrNetSyncVoipAttenuationValue

FOvrNetSyncVoipAttenuationValue::FOvrNetSyncVoipAttenuationValue()
{
    Clear();
}

FOvrNetSyncVoipAttenuationValue::FOvrNetSyncVoipAttenuationValue(ovrNetSyncVoipAttenuationValueHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrNetSyncVoipAttenuationValue::Clear()
{
    Decibels = 0.0;
    Distance = 0.0;
}

void FOvrNetSyncVoipAttenuationValue::Update(ovrNetSyncVoipAttenuationValueHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Decibels = static_cast<float>(ovr_NetSyncVoipAttenuationValue_GetDecibels(OvrHandle));
    Distance = static_cast<float>(ovr_NetSyncVoipAttenuationValue_GetDistance(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrOrgScopedID

FOvrOrgScopedID::FOvrOrgScopedID()
{
    Clear();
}

FOvrOrgScopedID::FOvrOrgScopedID(ovrOrgScopedIDHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrOrgScopedID::Clear()
{
    ID = 0;
}

void FOvrOrgScopedID::Update(ovrOrgScopedIDHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    ID = static_cast<FOvrId>(ovr_OrgScopedID_GetID(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrPacket

FOvrPacket::FOvrPacket()
{
    Clear();
}

FOvrPacket::FOvrPacket(ovrPacketHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrPacket::Clear()
{
    Bytes = TArray<uint8>();
    SenderID = 0;
    Handle = nullptr;
}

void FOvrPacket::Update(ovrPacketHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Handle = OvrHandle;
    Bytes = TArray<uint8>((uint8*)ovr_Packet_GetBytes(OvrHandle), ovr_Packet_GetSize(OvrHandle));
    SenderID = static_cast<FOvrId>(ovr_Packet_GetSenderID(OvrHandle));
}

void UOvrPacketMethods::Packet_Free(FOvrPacket& Model)
{
    ovr_Packet_Free(Model.Handle);
}

// -----------------------------------------------------------------------------
// FOvrPartyID

FOvrPartyID::FOvrPartyID()
{
    Clear();
}

FOvrPartyID::FOvrPartyID(ovrPartyIDHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrPartyID::Clear()
{
    ID = 0;
}

void FOvrPartyID::Update(ovrPartyIDHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    ID = static_cast<FOvrId>(ovr_PartyID_GetID(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrPartyUpdateNotification

FOvrPartyUpdateNotification::FOvrPartyUpdateNotification()
{
    Clear();
}

FOvrPartyUpdateNotification::FOvrPartyUpdateNotification(ovrPartyUpdateNotificationHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrPartyUpdateNotification::Clear()
{
    Action = EOvrPartyUpdateAction::Unknown;
    PartyId = 0;
    SenderId = 0;
    UpdateTimestamp = TEXT("");
    UserAlias = TEXT("");
    UserId = 0;
    UserName = TEXT("");
}

void FOvrPartyUpdateNotification::Update(ovrPartyUpdateNotificationHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Action = ConvertPartyUpdateAction(ovr_PartyUpdateNotification_GetAction(OvrHandle));
    PartyId = static_cast<FOvrId>(ovr_PartyUpdateNotification_GetPartyId(OvrHandle));
    SenderId = static_cast<FOvrId>(ovr_PartyUpdateNotification_GetSenderId(OvrHandle));
    UpdateTimestamp = UTF8_TO_TCHAR(ovr_PartyUpdateNotification_GetUpdateTimestamp(OvrHandle));
    UserAlias = UTF8_TO_TCHAR(ovr_PartyUpdateNotification_GetUserAlias(OvrHandle));
    UserId = static_cast<FOvrId>(ovr_PartyUpdateNotification_GetUserId(OvrHandle));
    UserName = UTF8_TO_TCHAR(ovr_PartyUpdateNotification_GetUserName(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrPid

FOvrPid::FOvrPid()
{
    Clear();
}

FOvrPid::FOvrPid(ovrPidHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrPid::Clear()
{
    Id = TEXT("");
}

void FOvrPid::Update(ovrPidHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Id = UTF8_TO_TCHAR(ovr_Pid_GetId(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrPlatformInitialize

FOvrPlatformInitialize::FOvrPlatformInitialize()
{
    Clear();
}

FOvrPlatformInitialize::FOvrPlatformInitialize(ovrPlatformInitializeHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrPlatformInitialize::Clear()
{
    Result = EOvrPlatformInitializeResult::Unknown;
}

void FOvrPlatformInitialize::Update(ovrPlatformInitializeHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Result = ConvertPlatformInitializeResult(ovr_PlatformInitialize_GetResult(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrProduct

FOvrProduct::FOvrProduct()
{
    Clear();
}

FOvrProduct::FOvrProduct(ovrProductHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrProduct::Clear()
{
    Description = TEXT("");
    FormattedPrice = TEXT("");
    Name = TEXT("");
    SKU = TEXT("");
}

void FOvrProduct::Update(ovrProductHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Description = UTF8_TO_TCHAR(ovr_Product_GetDescription(OvrHandle));
    FormattedPrice = UTF8_TO_TCHAR(ovr_Product_GetFormattedPrice(OvrHandle));
    Name = UTF8_TO_TCHAR(ovr_Product_GetName(OvrHandle));
    SKU = UTF8_TO_TCHAR(ovr_Product_GetSKU(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrProductPages

FOvrProductPages::FOvrProductPages()
{
    Clear();
}

FOvrProductPages::FOvrProductPages(ovrProductArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(Handle, MessageHandlePtr);
}

void FOvrProductPages::Clear()
{
    PagedArrayHandle = nullptr;
    PagedArrayMessageHandlePtr.reset();
}

void FOvrProductPages::Update(ovrProductArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr)
{
    PagedArrayHandle = Handle;
    PagedArrayMessageHandlePtr = MessageHandlePtr;
}

FOvrProduct UOvrProductPagesMethods::ProductPages_GetElement(const FOvrProductPages& Model, int64 Index)
{
    return FOvrProduct(ovr_ProductArray_GetElement(Model.PagedArrayHandle, static_cast<size_t>(Index)), Model.PagedArrayMessageHandlePtr);
}

FString UOvrProductPagesMethods::ProductPages_GetNextUrl(const FOvrProductPages& Model)
{
    return UTF8_TO_TCHAR(ovr_ProductArray_GetNextUrl(Model.PagedArrayHandle));
}

int64 UOvrProductPagesMethods::ProductPages_GetSize(const FOvrProductPages& Model)
{
    return static_cast<int64>(ovr_ProductArray_GetSize(Model.PagedArrayHandle));
}

bool UOvrProductPagesMethods::ProductPages_HasNextPage(const FOvrProductPages& Model)
{
    return ovr_ProductArray_HasNextPage(Model.PagedArrayHandle);
}

// -----------------------------------------------------------------------------
// FOvrPurchase

FOvrPurchase::FOvrPurchase()
{
    Clear();
}

FOvrPurchase::FOvrPurchase(ovrPurchaseHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrPurchase::Clear()
{
    DeveloperPayload = TEXT("");
    ExpirationTime = FDateTime(0);
    GrantTime = FDateTime(0);
    PurchaseID = TEXT("");
    ReportingId = TEXT("");
    SKU = TEXT("");
}

void FOvrPurchase::Update(ovrPurchaseHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    DeveloperPayload = UTF8_TO_TCHAR(ovr_Purchase_GetDeveloperPayload(OvrHandle));
    ExpirationTime = FDateTime::FromUnixTimestamp(ovr_Purchase_GetExpirationTime(OvrHandle));
    GrantTime = FDateTime::FromUnixTimestamp(ovr_Purchase_GetGrantTime(OvrHandle));
    PurchaseID = UTF8_TO_TCHAR(ovr_Purchase_GetPurchaseStrID(OvrHandle));
    ReportingId = UTF8_TO_TCHAR(ovr_Purchase_GetReportingId(OvrHandle));
    SKU = UTF8_TO_TCHAR(ovr_Purchase_GetSKU(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrPurchasePages

FOvrPurchasePages::FOvrPurchasePages()
{
    Clear();
}

FOvrPurchasePages::FOvrPurchasePages(ovrPurchaseArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(Handle, MessageHandlePtr);
}

void FOvrPurchasePages::Clear()
{
    PagedArrayHandle = nullptr;
    PagedArrayMessageHandlePtr.reset();
}

void FOvrPurchasePages::Update(ovrPurchaseArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr)
{
    PagedArrayHandle = Handle;
    PagedArrayMessageHandlePtr = MessageHandlePtr;
}

FOvrPurchase UOvrPurchasePagesMethods::PurchasePages_GetElement(const FOvrPurchasePages& Model, int64 Index)
{
    return FOvrPurchase(ovr_PurchaseArray_GetElement(Model.PagedArrayHandle, static_cast<size_t>(Index)), Model.PagedArrayMessageHandlePtr);
}

FString UOvrPurchasePagesMethods::PurchasePages_GetNextUrl(const FOvrPurchasePages& Model)
{
    return UTF8_TO_TCHAR(ovr_PurchaseArray_GetNextUrl(Model.PagedArrayHandle));
}

int64 UOvrPurchasePagesMethods::PurchasePages_GetSize(const FOvrPurchasePages& Model)
{
    return static_cast<int64>(ovr_PurchaseArray_GetSize(Model.PagedArrayHandle));
}

bool UOvrPurchasePagesMethods::PurchasePages_HasNextPage(const FOvrPurchasePages& Model)
{
    return ovr_PurchaseArray_HasNextPage(Model.PagedArrayHandle);
}

// -----------------------------------------------------------------------------
// FOvrRejoinDialogResult

FOvrRejoinDialogResult::FOvrRejoinDialogResult()
{
    Clear();
}

FOvrRejoinDialogResult::FOvrRejoinDialogResult(ovrRejoinDialogResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrRejoinDialogResult::Clear()
{
    RejoinSelected = false;
}

void FOvrRejoinDialogResult::Update(ovrRejoinDialogResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    RejoinSelected = ovr_RejoinDialogResult_GetRejoinSelected(OvrHandle);
}

// -----------------------------------------------------------------------------
// FOvrSdkAccount

FOvrSdkAccount::FOvrSdkAccount()
{
    Clear();
}

FOvrSdkAccount::FOvrSdkAccount(ovrSdkAccountHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrSdkAccount::Clear()
{
    AccountType = EOvrSdkAccountType::Unknown;
    UserId = 0;
}

void FOvrSdkAccount::Update(ovrSdkAccountHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    AccountType = ConvertSdkAccountType(ovr_SdkAccount_GetAccountType(OvrHandle));
    UserId = static_cast<FOvrId>(ovr_SdkAccount_GetUserId(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrShareMediaResult

FOvrShareMediaResult::FOvrShareMediaResult()
{
    Clear();
}

FOvrShareMediaResult::FOvrShareMediaResult(ovrShareMediaResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrShareMediaResult::Clear()
{
    Status = EOvrShareMediaStatus::Unknown;
}

void FOvrShareMediaResult::Update(ovrShareMediaResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Status = ConvertShareMediaStatus(ovr_ShareMediaResult_GetStatus(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrSupplementaryMetric

FOvrSupplementaryMetric::FOvrSupplementaryMetric()
{
    Clear();
}

FOvrSupplementaryMetric::FOvrSupplementaryMetric(ovrSupplementaryMetricHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrSupplementaryMetric::Clear()
{
    ID = 0;
    Metric = 0;
}

void FOvrSupplementaryMetric::Update(ovrSupplementaryMetricHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    ID = static_cast<FOvrId>(ovr_SupplementaryMetric_GetID(OvrHandle));
    Metric = static_cast<int64>(ovr_SupplementaryMetric_GetMetric(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrSystemVoipState

FOvrSystemVoipState::FOvrSystemVoipState()
{
    Clear();
}

FOvrSystemVoipState::FOvrSystemVoipState(ovrSystemVoipStateHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrSystemVoipState::Clear()
{
    MicrophoneMuted = EOvrVoipMuteState::Unknown;
    Status = EOvrSystemVoipStatus::Unknown;
}

void FOvrSystemVoipState::Update(ovrSystemVoipStateHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    MicrophoneMuted = ConvertVoipMuteState(ovr_SystemVoipState_GetMicrophoneMuted(OvrHandle));
    Status = ConvertSystemVoipStatus(ovr_SystemVoipState_GetStatus(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrUser

FOvrUser::FOvrUser()
{
    Clear();
}

FOvrUser::FOvrUser(ovrUserHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrUser::Clear()
{
    DisplayName = TEXT("");
    ID = 0;
    ImageUrl = TEXT("");
    OculusID = TEXT("");
    Presence = TEXT("");
    PresenceDeeplinkMessage = TEXT("");
    PresenceDestinationApiName = TEXT("");
    PresenceLobbySessionId = TEXT("");
    PresenceMatchSessionId = TEXT("");
    PresenceStatus = EOvrUserPresenceStatus::Unknown;
    SmallImageUrl = TEXT("");
}

void FOvrUser::Update(ovrUserHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    DisplayName = UTF8_TO_TCHAR(ovr_User_GetDisplayName(OvrHandle));
    ID = static_cast<FOvrId>(ovr_User_GetID(OvrHandle));
    ImageUrl = UTF8_TO_TCHAR(ovr_User_GetImageUrl(OvrHandle));
    OculusID = UTF8_TO_TCHAR(ovr_User_GetOculusID(OvrHandle));
    Presence = UTF8_TO_TCHAR(ovr_User_GetPresence(OvrHandle));
    PresenceDeeplinkMessage = UTF8_TO_TCHAR(ovr_User_GetPresenceDeeplinkMessage(OvrHandle));
    PresenceDestinationApiName = UTF8_TO_TCHAR(ovr_User_GetPresenceDestinationApiName(OvrHandle));
    PresenceLobbySessionId = UTF8_TO_TCHAR(ovr_User_GetPresenceLobbySessionId(OvrHandle));
    PresenceMatchSessionId = UTF8_TO_TCHAR(ovr_User_GetPresenceMatchSessionId(OvrHandle));
    PresenceStatus = ConvertUserPresenceStatus(ovr_User_GetPresenceStatus(OvrHandle));
    SmallImageUrl = UTF8_TO_TCHAR(ovr_User_GetSmallImageUrl(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrApplicationInvite

FOvrApplicationInvite::FOvrApplicationInvite()
{
    Clear();
}

FOvrApplicationInvite::FOvrApplicationInvite(ovrApplicationInviteHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrApplicationInvite::Clear()
{
    Destination.Clear();
    ID = 0;
    IsActive = false;
    LobbySessionId = TEXT("");
    MatchSessionId = TEXT("");
    Recipient.Clear();
}

void FOvrApplicationInvite::Update(ovrApplicationInviteHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Destination.Update(ovr_ApplicationInvite_GetDestination(OvrHandle), MessageHandlePtr);
    ID = static_cast<FOvrId>(ovr_ApplicationInvite_GetID(OvrHandle));
    IsActive = ovr_ApplicationInvite_GetIsActive(OvrHandle);
    LobbySessionId = UTF8_TO_TCHAR(ovr_ApplicationInvite_GetLobbySessionId(OvrHandle));
    MatchSessionId = UTF8_TO_TCHAR(ovr_ApplicationInvite_GetMatchSessionId(OvrHandle));
    Recipient.Update(ovr_ApplicationInvite_GetRecipient(OvrHandle), MessageHandlePtr);
}

// -----------------------------------------------------------------------------
// FOvrApplicationInvitePages

FOvrApplicationInvitePages::FOvrApplicationInvitePages()
{
    Clear();
}

FOvrApplicationInvitePages::FOvrApplicationInvitePages(ovrApplicationInviteArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(Handle, MessageHandlePtr);
}

void FOvrApplicationInvitePages::Clear()
{
    PagedArrayHandle = nullptr;
    PagedArrayMessageHandlePtr.reset();
}

void FOvrApplicationInvitePages::Update(ovrApplicationInviteArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr)
{
    PagedArrayHandle = Handle;
    PagedArrayMessageHandlePtr = MessageHandlePtr;
}

FOvrApplicationInvite UOvrApplicationInvitePagesMethods::ApplicationInvitePages_GetElement(const FOvrApplicationInvitePages& Model, int64 Index)
{
    return FOvrApplicationInvite(ovr_ApplicationInviteArray_GetElement(Model.PagedArrayHandle, static_cast<size_t>(Index)), Model.PagedArrayMessageHandlePtr);
}

FString UOvrApplicationInvitePagesMethods::ApplicationInvitePages_GetNextUrl(const FOvrApplicationInvitePages& Model)
{
    return UTF8_TO_TCHAR(ovr_ApplicationInviteArray_GetNextUrl(Model.PagedArrayHandle));
}

int64 UOvrApplicationInvitePagesMethods::ApplicationInvitePages_GetSize(const FOvrApplicationInvitePages& Model)
{
    return static_cast<int64>(ovr_ApplicationInviteArray_GetSize(Model.PagedArrayHandle));
}

bool UOvrApplicationInvitePagesMethods::ApplicationInvitePages_HasNextPage(const FOvrApplicationInvitePages& Model)
{
    return ovr_ApplicationInviteArray_HasNextPage(Model.PagedArrayHandle);
}

// -----------------------------------------------------------------------------
// FOvrChallengeEntry

FOvrChallengeEntry::FOvrChallengeEntry()
{
    Clear();
}

FOvrChallengeEntry::FOvrChallengeEntry(ovrChallengeEntryHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrChallengeEntry::Clear()
{
    DisplayScore = TEXT("");
    ExtraData.Empty();
    ID = 0;
    Rank = 0;
    Score = 0;
    Timestamp = FDateTime(0);
    User.Clear();
}

void FOvrChallengeEntry::Update(ovrChallengeEntryHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    DisplayScore = UTF8_TO_TCHAR(ovr_ChallengeEntry_GetDisplayScore(OvrHandle));
    ExtraData = TArray<uint8>((uint8*)ovr_ChallengeEntry_GetExtraData(OvrHandle), ovr_ChallengeEntry_GetExtraDataLength(OvrHandle));
    ID = static_cast<FOvrId>(ovr_ChallengeEntry_GetID(OvrHandle));
    Rank = static_cast<int32>(ovr_ChallengeEntry_GetRank(OvrHandle));
    Score = static_cast<int64>(ovr_ChallengeEntry_GetScore(OvrHandle));
    Timestamp = FDateTime::FromUnixTimestamp(ovr_ChallengeEntry_GetTimestamp(OvrHandle));
    User.Update(ovr_ChallengeEntry_GetUser(OvrHandle), MessageHandlePtr);
}

// -----------------------------------------------------------------------------
// FOvrChallengeEntryPages

FOvrChallengeEntryPages::FOvrChallengeEntryPages()
{
    Clear();
}

FOvrChallengeEntryPages::FOvrChallengeEntryPages(ovrChallengeEntryArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(Handle, MessageHandlePtr);
}

void FOvrChallengeEntryPages::Clear()
{
    PagedArrayHandle = nullptr;
    PagedArrayMessageHandlePtr.reset();
}

void FOvrChallengeEntryPages::Update(ovrChallengeEntryArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr)
{
    PagedArrayHandle = Handle;
    PagedArrayMessageHandlePtr = MessageHandlePtr;
}

FOvrChallengeEntry UOvrChallengeEntryPagesMethods::ChallengeEntryPages_GetElement(const FOvrChallengeEntryPages& Model, int64 Index)
{
    return FOvrChallengeEntry(ovr_ChallengeEntryArray_GetElement(Model.PagedArrayHandle, static_cast<size_t>(Index)), Model.PagedArrayMessageHandlePtr);
}

FString UOvrChallengeEntryPagesMethods::ChallengeEntryPages_GetNextUrl(const FOvrChallengeEntryPages& Model)
{
    return UTF8_TO_TCHAR(ovr_ChallengeEntryArray_GetNextUrl(Model.PagedArrayHandle));
}

FString UOvrChallengeEntryPagesMethods::ChallengeEntryPages_GetPreviousUrl(const FOvrChallengeEntryPages& Model)
{
    return UTF8_TO_TCHAR(ovr_ChallengeEntryArray_GetPreviousUrl(Model.PagedArrayHandle));
}

int64 UOvrChallengeEntryPagesMethods::ChallengeEntryPages_GetSize(const FOvrChallengeEntryPages& Model)
{
    return static_cast<int64>(ovr_ChallengeEntryArray_GetSize(Model.PagedArrayHandle));
}

int64 UOvrChallengeEntryPagesMethods::ChallengeEntryPages_GetTotalCount(const FOvrChallengeEntryPages& Model)
{
    return static_cast<int64>(ovr_ChallengeEntryArray_GetTotalCount(Model.PagedArrayHandle));
}

bool UOvrChallengeEntryPagesMethods::ChallengeEntryPages_HasNextPage(const FOvrChallengeEntryPages& Model)
{
    return ovr_ChallengeEntryArray_HasNextPage(Model.PagedArrayHandle);
}

bool UOvrChallengeEntryPagesMethods::ChallengeEntryPages_HasPreviousPage(const FOvrChallengeEntryPages& Model)
{
    return ovr_ChallengeEntryArray_HasPreviousPage(Model.PagedArrayHandle);
}

// -----------------------------------------------------------------------------
// FOvrLeaderboardEntry

FOvrLeaderboardEntry::FOvrLeaderboardEntry()
{
    Clear();
}

FOvrLeaderboardEntry::FOvrLeaderboardEntry(ovrLeaderboardEntryHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrLeaderboardEntry::Clear()
{
    DisplayScore = TEXT("");
    ExtraData.Empty();
    ID = 0;
    Rank = 0;
    Score = 0;
    SupplementaryMetric.Clear();
    Timestamp = FDateTime(0);
    User.Clear();
}

void FOvrLeaderboardEntry::Update(ovrLeaderboardEntryHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    DisplayScore = UTF8_TO_TCHAR(ovr_LeaderboardEntry_GetDisplayScore(OvrHandle));
    ExtraData = TArray<uint8>((uint8*)ovr_LeaderboardEntry_GetExtraData(OvrHandle), ovr_LeaderboardEntry_GetExtraDataLength(OvrHandle));
    ID = static_cast<FOvrId>(ovr_LeaderboardEntry_GetID(OvrHandle));
    Rank = static_cast<int32>(ovr_LeaderboardEntry_GetRank(OvrHandle));
    Score = static_cast<int64>(ovr_LeaderboardEntry_GetScore(OvrHandle));
    SupplementaryMetric.Update(ovr_LeaderboardEntry_GetSupplementaryMetric(OvrHandle), MessageHandlePtr);
    Timestamp = FDateTime::FromUnixTimestamp(ovr_LeaderboardEntry_GetTimestamp(OvrHandle));
    User.Update(ovr_LeaderboardEntry_GetUser(OvrHandle), MessageHandlePtr);
}

// -----------------------------------------------------------------------------
// FOvrLeaderboardEntryPages

FOvrLeaderboardEntryPages::FOvrLeaderboardEntryPages()
{
    Clear();
}

FOvrLeaderboardEntryPages::FOvrLeaderboardEntryPages(ovrLeaderboardEntryArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(Handle, MessageHandlePtr);
}

void FOvrLeaderboardEntryPages::Clear()
{
    PagedArrayHandle = nullptr;
    PagedArrayMessageHandlePtr.reset();
}

void FOvrLeaderboardEntryPages::Update(ovrLeaderboardEntryArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr)
{
    PagedArrayHandle = Handle;
    PagedArrayMessageHandlePtr = MessageHandlePtr;
}

FOvrLeaderboardEntry UOvrLeaderboardEntryPagesMethods::LeaderboardEntryPages_GetElement(const FOvrLeaderboardEntryPages& Model, int64 Index)
{
    return FOvrLeaderboardEntry(ovr_LeaderboardEntryArray_GetElement(Model.PagedArrayHandle, static_cast<size_t>(Index)), Model.PagedArrayMessageHandlePtr);
}

FString UOvrLeaderboardEntryPagesMethods::LeaderboardEntryPages_GetNextUrl(const FOvrLeaderboardEntryPages& Model)
{
    return UTF8_TO_TCHAR(ovr_LeaderboardEntryArray_GetNextUrl(Model.PagedArrayHandle));
}

FString UOvrLeaderboardEntryPagesMethods::LeaderboardEntryPages_GetPreviousUrl(const FOvrLeaderboardEntryPages& Model)
{
    return UTF8_TO_TCHAR(ovr_LeaderboardEntryArray_GetPreviousUrl(Model.PagedArrayHandle));
}

int64 UOvrLeaderboardEntryPagesMethods::LeaderboardEntryPages_GetSize(const FOvrLeaderboardEntryPages& Model)
{
    return static_cast<int64>(ovr_LeaderboardEntryArray_GetSize(Model.PagedArrayHandle));
}

int64 UOvrLeaderboardEntryPagesMethods::LeaderboardEntryPages_GetTotalCount(const FOvrLeaderboardEntryPages& Model)
{
    return static_cast<int64>(ovr_LeaderboardEntryArray_GetTotalCount(Model.PagedArrayHandle));
}

bool UOvrLeaderboardEntryPagesMethods::LeaderboardEntryPages_HasNextPage(const FOvrLeaderboardEntryPages& Model)
{
    return ovr_LeaderboardEntryArray_HasNextPage(Model.PagedArrayHandle);
}

bool UOvrLeaderboardEntryPagesMethods::LeaderboardEntryPages_HasPreviousPage(const FOvrLeaderboardEntryPages& Model)
{
    return ovr_LeaderboardEntryArray_HasPreviousPage(Model.PagedArrayHandle);
}

// -----------------------------------------------------------------------------
// FOvrSendInvitesResult

FOvrSendInvitesResult::FOvrSendInvitesResult()
{
    Clear();
}

FOvrSendInvitesResult::FOvrSendInvitesResult(ovrSendInvitesResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrSendInvitesResult::Clear()
{
    Invites.Clear();
}

void FOvrSendInvitesResult::Update(ovrSendInvitesResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Invites.Update(ovr_SendInvitesResult_GetInvites(OvrHandle), MessageHandlePtr);
}

// -----------------------------------------------------------------------------
// FOvrUserAccountAgeCategory

FOvrUserAccountAgeCategory::FOvrUserAccountAgeCategory()
{
    Clear();
}

FOvrUserAccountAgeCategory::FOvrUserAccountAgeCategory(ovrUserAccountAgeCategoryHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrUserAccountAgeCategory::Clear()
{
    AgeCategory = EOvrAccountAgeCategory::Unknown;
}

void FOvrUserAccountAgeCategory::Update(ovrUserAccountAgeCategoryHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    AgeCategory = ConvertAccountAgeCategory(ovr_UserAccountAgeCategory_GetAgeCategory(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrUserPages

FOvrUserPages::FOvrUserPages()
{
    Clear();
}

FOvrUserPages::FOvrUserPages(ovrUserArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(Handle, MessageHandlePtr);
}

void FOvrUserPages::Clear()
{
    PagedArrayHandle = nullptr;
    PagedArrayMessageHandlePtr.reset();
}

void FOvrUserPages::Update(ovrUserArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr)
{
    PagedArrayHandle = Handle;
    PagedArrayMessageHandlePtr = MessageHandlePtr;
}

FOvrUser UOvrUserPagesMethods::UserPages_GetElement(const FOvrUserPages& Model, int64 Index)
{
    return FOvrUser(ovr_UserArray_GetElement(Model.PagedArrayHandle, static_cast<size_t>(Index)), Model.PagedArrayMessageHandlePtr);
}

FString UOvrUserPagesMethods::UserPages_GetNextUrl(const FOvrUserPages& Model)
{
    return UTF8_TO_TCHAR(ovr_UserArray_GetNextUrl(Model.PagedArrayHandle));
}

int64 UOvrUserPagesMethods::UserPages_GetSize(const FOvrUserPages& Model)
{
    return static_cast<int64>(ovr_UserArray_GetSize(Model.PagedArrayHandle));
}

bool UOvrUserPagesMethods::UserPages_HasNextPage(const FOvrUserPages& Model)
{
    return ovr_UserArray_HasNextPage(Model.PagedArrayHandle);
}

// -----------------------------------------------------------------------------
// FOvrChallenge

FOvrChallenge::FOvrChallenge()
{
    Clear();
}

FOvrChallenge::FOvrChallenge(ovrChallengeHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrChallenge::Clear()
{
    CreationType = EOvrChallengeCreationType::Unknown;
    Description = TEXT("");
    EndDate = FDateTime(0);
    ID = 0;
    InvitedUsers.Clear();
    Leaderboard.Clear();
    Participants.Clear();
    StartDate = FDateTime(0);
    Title = TEXT("");
    Visibility = EOvrChallengeVisibility::Unknown;
}

void FOvrChallenge::Update(ovrChallengeHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    CreationType = ConvertChallengeCreationType(ovr_Challenge_GetCreationType(OvrHandle));
    Description = UTF8_TO_TCHAR(ovr_Challenge_GetDescription(OvrHandle));
    EndDate = FDateTime::FromUnixTimestamp(ovr_Challenge_GetEndDate(OvrHandle));
    ID = static_cast<FOvrId>(ovr_Challenge_GetID(OvrHandle));
    InvitedUsers.Update(ovr_Challenge_GetInvitedUsers(OvrHandle), MessageHandlePtr);
    Leaderboard.Update(ovr_Challenge_GetLeaderboard(OvrHandle), MessageHandlePtr);
    Participants.Update(ovr_Challenge_GetParticipants(OvrHandle), MessageHandlePtr);
    StartDate = FDateTime::FromUnixTimestamp(ovr_Challenge_GetStartDate(OvrHandle));
    Title = UTF8_TO_TCHAR(ovr_Challenge_GetTitle(OvrHandle));
    Visibility = ConvertChallengeVisibility(ovr_Challenge_GetVisibility(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrChallengePages

FOvrChallengePages::FOvrChallengePages()
{
    Clear();
}

FOvrChallengePages::FOvrChallengePages(ovrChallengeArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(Handle, MessageHandlePtr);
}

void FOvrChallengePages::Clear()
{
    PagedArrayHandle = nullptr;
    PagedArrayMessageHandlePtr.reset();
}

void FOvrChallengePages::Update(ovrChallengeArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr)
{
    PagedArrayHandle = Handle;
    PagedArrayMessageHandlePtr = MessageHandlePtr;
}

FOvrChallenge UOvrChallengePagesMethods::ChallengePages_GetElement(const FOvrChallengePages& Model, int64 Index)
{
    return FOvrChallenge(ovr_ChallengeArray_GetElement(Model.PagedArrayHandle, static_cast<size_t>(Index)), Model.PagedArrayMessageHandlePtr);
}

FString UOvrChallengePagesMethods::ChallengePages_GetNextUrl(const FOvrChallengePages& Model)
{
    return UTF8_TO_TCHAR(ovr_ChallengeArray_GetNextUrl(Model.PagedArrayHandle));
}

FString UOvrChallengePagesMethods::ChallengePages_GetPreviousUrl(const FOvrChallengePages& Model)
{
    return UTF8_TO_TCHAR(ovr_ChallengeArray_GetPreviousUrl(Model.PagedArrayHandle));
}

int64 UOvrChallengePagesMethods::ChallengePages_GetSize(const FOvrChallengePages& Model)
{
    return static_cast<int64>(ovr_ChallengeArray_GetSize(Model.PagedArrayHandle));
}

int64 UOvrChallengePagesMethods::ChallengePages_GetTotalCount(const FOvrChallengePages& Model)
{
    return static_cast<int64>(ovr_ChallengeArray_GetTotalCount(Model.PagedArrayHandle));
}

bool UOvrChallengePagesMethods::ChallengePages_HasNextPage(const FOvrChallengePages& Model)
{
    return ovr_ChallengeArray_HasNextPage(Model.PagedArrayHandle);
}

bool UOvrChallengePagesMethods::ChallengePages_HasPreviousPage(const FOvrChallengePages& Model)
{
    return ovr_ChallengeArray_HasPreviousPage(Model.PagedArrayHandle);
}

// -----------------------------------------------------------------------------
// FOvrLaunchDetails

FOvrLaunchDetails::FOvrLaunchDetails()
{
    Clear();
}

FOvrLaunchDetails::FOvrLaunchDetails(ovrLaunchDetailsHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrLaunchDetails::Clear()
{
    DeeplinkMessage = TEXT("");
    DestinationApiName = TEXT("");
    LaunchSource = TEXT("");
    LaunchType = EOvrLaunchType::Unknown;
    LobbySessionID = TEXT("");
    MatchSessionID = TEXT("");
    TrackingID = TEXT("");
    Users.Clear();
}

void FOvrLaunchDetails::Update(ovrLaunchDetailsHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    DeeplinkMessage = UTF8_TO_TCHAR(ovr_LaunchDetails_GetDeeplinkMessage(OvrHandle));
    DestinationApiName = UTF8_TO_TCHAR(ovr_LaunchDetails_GetDestinationApiName(OvrHandle));
    LaunchSource = UTF8_TO_TCHAR(ovr_LaunchDetails_GetLaunchSource(OvrHandle));
    LaunchType = ConvertLaunchType(ovr_LaunchDetails_GetLaunchType(OvrHandle));
    LobbySessionID = UTF8_TO_TCHAR(ovr_LaunchDetails_GetLobbySessionID(OvrHandle));
    MatchSessionID = UTF8_TO_TCHAR(ovr_LaunchDetails_GetMatchSessionID(OvrHandle));
    TrackingID = UTF8_TO_TCHAR(ovr_LaunchDetails_GetTrackingID(OvrHandle));
    Users.Update(ovr_LaunchDetails_GetUsers(OvrHandle), MessageHandlePtr);
}

// -----------------------------------------------------------------------------
// FOvrLaunchInvitePanelFlowResult

FOvrLaunchInvitePanelFlowResult::FOvrLaunchInvitePanelFlowResult()
{
    Clear();
}

FOvrLaunchInvitePanelFlowResult::FOvrLaunchInvitePanelFlowResult(ovrLaunchInvitePanelFlowResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrLaunchInvitePanelFlowResult::Clear()
{
    InvitedUsers.Clear();
}

void FOvrLaunchInvitePanelFlowResult::Update(ovrLaunchInvitePanelFlowResultHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    InvitedUsers.Update(ovr_LaunchInvitePanelFlowResult_GetInvitedUsers(OvrHandle), MessageHandlePtr);
}

// -----------------------------------------------------------------------------
// FOvrParty

FOvrParty::FOvrParty()
{
    Clear();
}

FOvrParty::FOvrParty(ovrPartyHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrParty::Clear()
{
    ID = 0;
    InvitedUsers.Clear();
    Leader.Clear();
    Users.Clear();
}

void FOvrParty::Update(ovrPartyHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    ID = static_cast<FOvrId>(ovr_Party_GetID(OvrHandle));
    InvitedUsers.Update(ovr_Party_GetInvitedUsers(OvrHandle), MessageHandlePtr);
    Leader.Update(ovr_Party_GetLeader(OvrHandle), MessageHandlePtr);
    Users.Update(ovr_Party_GetUsers(OvrHandle), MessageHandlePtr);
}

// -----------------------------------------------------------------------------
// FOvrUserCapability

FOvrUserCapability::FOvrUserCapability()
{
    Clear();
}

FOvrUserCapability::FOvrUserCapability(ovrUserCapabilityHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrUserCapability::Clear()
{
    Description = TEXT("");
    IsEnabled = false;
    Name = TEXT("");
    ReasonCode = TEXT("");
}

void FOvrUserCapability::Update(ovrUserCapabilityHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Description = UTF8_TO_TCHAR(ovr_UserCapability_GetDescription(OvrHandle));
    IsEnabled = ovr_UserCapability_GetIsEnabled(OvrHandle);
    Name = UTF8_TO_TCHAR(ovr_UserCapability_GetName(OvrHandle));
    ReasonCode = UTF8_TO_TCHAR(ovr_UserCapability_GetReasonCode(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrUserCapabilityPages

FOvrUserCapabilityPages::FOvrUserCapabilityPages()
{
    Clear();
}

FOvrUserCapabilityPages::FOvrUserCapabilityPages(ovrUserCapabilityArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(Handle, MessageHandlePtr);
}

void FOvrUserCapabilityPages::Clear()
{
    PagedArrayHandle = nullptr;
    PagedArrayMessageHandlePtr.reset();
}

void FOvrUserCapabilityPages::Update(ovrUserCapabilityArrayHandle Handle, TOvrMessageHandlePtr MessageHandlePtr)
{
    PagedArrayHandle = Handle;
    PagedArrayMessageHandlePtr = MessageHandlePtr;
}

FOvrUserCapability UOvrUserCapabilityPagesMethods::UserCapabilityPages_GetElement(const FOvrUserCapabilityPages& Model, int64 Index)
{
    return FOvrUserCapability(ovr_UserCapabilityArray_GetElement(Model.PagedArrayHandle, static_cast<size_t>(Index)), Model.PagedArrayMessageHandlePtr);
}

FString UOvrUserCapabilityPagesMethods::UserCapabilityPages_GetNextUrl(const FOvrUserCapabilityPages& Model)
{
    return UTF8_TO_TCHAR(ovr_UserCapabilityArray_GetNextUrl(Model.PagedArrayHandle));
}

int64 UOvrUserCapabilityPagesMethods::UserCapabilityPages_GetSize(const FOvrUserCapabilityPages& Model)
{
    return static_cast<int64>(ovr_UserCapabilityArray_GetSize(Model.PagedArrayHandle));
}

bool UOvrUserCapabilityPagesMethods::UserCapabilityPages_HasNextPage(const FOvrUserCapabilityPages& Model)
{
    return ovr_UserCapabilityArray_HasNextPage(Model.PagedArrayHandle);
}

// -----------------------------------------------------------------------------
// FOvrUserDataStoreUpdateResponse

FOvrUserDataStoreUpdateResponse::FOvrUserDataStoreUpdateResponse()
{
    Clear();
}

FOvrUserDataStoreUpdateResponse::FOvrUserDataStoreUpdateResponse(ovrUserDataStoreUpdateResponseHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrUserDataStoreUpdateResponse::Clear()
{
    Success = false;
}

void FOvrUserDataStoreUpdateResponse::Update(ovrUserDataStoreUpdateResponseHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Success = ovr_UserDataStoreUpdateResponse_GetSuccess(OvrHandle);
}

// -----------------------------------------------------------------------------
// FOvrUserProof

FOvrUserProof::FOvrUserProof()
{
    Clear();
}

FOvrUserProof::FOvrUserProof(ovrUserProofHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrUserProof::Clear()
{
    Nonce = TEXT("");
}

void FOvrUserProof::Update(ovrUserProofHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Nonce = UTF8_TO_TCHAR(ovr_UserProof_GetNonce(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrUserReportID

FOvrUserReportID::FOvrUserReportID()
{
    Clear();
}

FOvrUserReportID::FOvrUserReportID(ovrUserReportIDHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrUserReportID::Clear()
{
    DidCancel = false;
    ID = 0;
}

void FOvrUserReportID::Update(ovrUserReportIDHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    DidCancel = ovr_UserReportID_GetDidCancel(OvrHandle);
    ID = static_cast<FOvrId>(ovr_UserReportID_GetID(OvrHandle));
}

// -----------------------------------------------------------------------------
// FOvrVoipDecoder

FOvrVoipDecoder::FOvrVoipDecoder()
{
    Clear();
}

FOvrVoipDecoder::FOvrVoipDecoder(ovrVoipDecoderHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrVoipDecoder::Clear()
{
    Handle = nullptr;
}

void FOvrVoipDecoder::Update(ovrVoipDecoderHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Handle = OvrHandle;
}

// -----------------------------------------------------------------------------
// FOvrVoipEncoder

FOvrVoipEncoder::FOvrVoipEncoder()
{
    Clear();
}

FOvrVoipEncoder::FOvrVoipEncoder(ovrVoipEncoderHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Update(OvrHandle, MessageHandlePtr);
}

void FOvrVoipEncoder::Clear()
{
    Handle = nullptr;
}

void FOvrVoipEncoder::Update(ovrVoipEncoderHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr)
{
    Handle = OvrHandle;
}

