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

#include "OVRPlatformFunctions.h"
#include "OVRPlatformRequestsConverters.h"
#include "OVRPlatformOptionsConverters.h"


// ----------------------------------------------------------------------
// ApplicationLifecycle

FOvrLaunchDetails UOvrFunctionsBlueprintLibrary::ApplicationLifecycle_GetLaunchDetails()
{
    return FOvrLaunchDetails(ovr_ApplicationLifecycle_GetLaunchDetails(), TOvrMessageHandlePtr());
}

void UOvrFunctionsBlueprintLibrary::ApplicationLifecycle_LogDeeplinkResult(FString TrackingID, EOvrLaunchResult Result)
{
    ovr_ApplicationLifecycle_LogDeeplinkResult(TCHAR_TO_UTF8(*TrackingID), ConvertLaunchResult(Result));
}

// ----------------------------------------------------------------------
// Networking

void UOvrFunctionsBlueprintLibrary::Net_Accept(FOvrId PeerID)
{
    ovr_Net_Accept(static_cast<ovrID>(PeerID));
}

bool UOvrFunctionsBlueprintLibrary::Net_AcceptForCurrentRoom()
{
    return ovr_Net_AcceptForCurrentRoom();
}

void UOvrFunctionsBlueprintLibrary::Net_Close(FOvrId PeerID)
{
    ovr_Net_Close(static_cast<ovrID>(PeerID));
}

void UOvrFunctionsBlueprintLibrary::Net_CloseForCurrentRoom()
{
    ovr_Net_CloseForCurrentRoom();
}

void UOvrFunctionsBlueprintLibrary::Net_Connect(FOvrId PeerID)
{
    ovr_Net_Connect(static_cast<ovrID>(PeerID));
}

bool UOvrFunctionsBlueprintLibrary::Net_IsConnected(FOvrId PeerID)
{
    return ovr_Net_IsConnected(static_cast<ovrID>(PeerID));
}

FOvrId UOvrFunctionsBlueprintLibrary::Net_Ping(FOvrId PeerID)
{
    return static_cast<FOvrId>(ovr_Net_Ping(static_cast<ovrID>(PeerID)));
}

FOvrPacket UOvrFunctionsBlueprintLibrary::Net_ReadPacket()
{
    return FOvrPacket(ovr_Net_ReadPacket(), TOvrMessageHandlePtr());
}

bool UOvrFunctionsBlueprintLibrary::Net_SendPacket(FOvrId UserID, TArray<uint8> Bytes, EOvrSendPolicy Policy)
{
    size_t Length = static_cast<size_t>(Bytes.Num());
    return ovr_Net_SendPacket(static_cast<ovrID>(UserID), Length, OvrPlatformByteArray(Bytes), ConvertSendPolicy(Policy));
}

bool UOvrFunctionsBlueprintLibrary::Net_SendPacketToCurrentRoom(TArray<uint8> Bytes, EOvrSendPolicy Policy)
{
    size_t Length = static_cast<size_t>(Bytes.Num());
    return ovr_Net_SendPacketToCurrentRoom(Length, OvrPlatformByteArray(Bytes), ConvertSendPolicy(Policy));
}

// ----------------------------------------------------------------------
// Voip

void UOvrFunctionsBlueprintLibrary::Voip_Accept(FOvrId UserID)
{
    ovr_Voip_Accept(static_cast<ovrID>(UserID));
}

EOvrVoipDtxState UOvrFunctionsBlueprintLibrary::Voip_GetIsConnectionUsingDtx(FOvrId PeerID)
{
    return ConvertVoipDtxState(ovr_Voip_GetIsConnectionUsingDtx(static_cast<ovrID>(PeerID)));
}

EOvrVoipBitrate UOvrFunctionsBlueprintLibrary::Voip_GetLocalBitrate(FOvrId PeerID)
{
    return ConvertVoipBitrate(ovr_Voip_GetLocalBitrate(static_cast<ovrID>(PeerID)));
}

int64 UOvrFunctionsBlueprintLibrary::Voip_GetOutputBufferMaxSize()
{
    return static_cast<int64>(ovr_Voip_GetOutputBufferMaxSize());
}

int64 UOvrFunctionsBlueprintLibrary::Voip_GetPCMSize(FOvrId SenderID)
{
    return static_cast<int64>(ovr_Voip_GetPCMSize(static_cast<ovrID>(SenderID)));
}

EOvrVoipBitrate UOvrFunctionsBlueprintLibrary::Voip_GetRemoteBitrate(FOvrId PeerID)
{
    return ConvertVoipBitrate(ovr_Voip_GetRemoteBitrate(static_cast<ovrID>(PeerID)));
}

int32 UOvrFunctionsBlueprintLibrary::Voip_GetSyncTimestamp(FOvrId UserID)
{
    return static_cast<int32>(ovr_Voip_GetSyncTimestamp(static_cast<ovrID>(UserID)));
}

int64 UOvrFunctionsBlueprintLibrary::Voip_GetSyncTimestampDifference(int32 Lhs, int32 Rhs)
{
    return static_cast<int64>(ovr_Voip_GetSyncTimestampDifference(static_cast<uint32_t>(Lhs), static_cast<uint32_t>(Rhs)));
}

EOvrVoipMuteState UOvrFunctionsBlueprintLibrary::Voip_GetSystemVoipMicrophoneMuted()
{
    return ConvertVoipMuteState(ovr_Voip_GetSystemVoipMicrophoneMuted());
}

EOvrSystemVoipStatus UOvrFunctionsBlueprintLibrary::Voip_GetSystemVoipStatus()
{
    return ConvertSystemVoipStatus(ovr_Voip_GetSystemVoipStatus());
}

void UOvrFunctionsBlueprintLibrary::Voip_SetMicrophoneMuted(EOvrVoipMuteState State)
{
    ovr_Voip_SetMicrophoneMuted(ConvertVoipMuteState(State));
}

void UOvrFunctionsBlueprintLibrary::Voip_SetNewConnectionOptions(FOvrVoipOptions VoipOptions)
{
    ovr_Voip_SetNewConnectionOptions(FOvrVoipOptionsConverter(VoipOptions));
}

void UOvrFunctionsBlueprintLibrary::Voip_SetOutputSampleRate(EOvrVoipSampleRate Rate)
{
    ovr_Voip_SetOutputSampleRate(ConvertVoipSampleRate(Rate));
}

void UOvrFunctionsBlueprintLibrary::Voip_Start(FOvrId UserID)
{
    ovr_Voip_Start(static_cast<ovrID>(UserID));
}

void UOvrFunctionsBlueprintLibrary::Voip_Stop(FOvrId UserID)
{
    ovr_Voip_Stop(static_cast<ovrID>(UserID));
}

bool UOvrFunctionsBlueprintLibrary::Platform_IsInitialized()
{
    return ovr_IsPlatformInitialized();
}

FOvrId UOvrFunctionsBlueprintLibrary::Platform_GetLoggedInUserID()
{
    return FOvrId(ovr_GetLoggedInUserID());
}

FString UOvrFunctionsBlueprintLibrary::Platform_GetLoggedInUserLocale()
{
    return UTF8_TO_TCHAR(ovr_GetLoggedInUserLocale());
}

void UOvrFunctionsBlueprintLibrary::Platform_SetDeveloperAccessToken(FString AccessToken)
{
    ovr_SetDeveloperAccessToken(TCHAR_TO_UTF8(*AccessToken));
}
