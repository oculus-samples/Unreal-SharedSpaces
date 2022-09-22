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

#include "OVRPlatformSubsystem.h"
#include "Misc/OutputDeviceNull.h"
#include "OVRPlatform.h"

#include <string>

#define TICK_SUBSYSTEM true

void UOvrPlatformSubsystem::StartMessagePump()
{
    bMessagePumpActivated = true;
}

void UOvrPlatformSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    UE_LOG(LogOvrPlatform, Display, TEXT("UOvrPlatformSubsystem::Initialize"));

    // Message pump waits for your authorization with a call to Start().
    bMessagePumpActivated = false;

    // Message handlers
    OnApplicationLifecycleLaunchIntentChangedHandle =
        GetNotifDelegate(ovrMessage_Notification_ApplicationLifecycle_LaunchIntentChanged)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnApplicationLifecycleLaunchIntentChanged);

    OnAssetFileDownloadUpdateHandle =
        GetNotifDelegate(ovrMessage_Notification_AssetFile_DownloadUpdate)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnAssetFileDownloadUpdate);

    OnCalFinalizeApplicationHandle =
        GetNotifDelegate(ovrMessage_Notification_Cal_FinalizeApplication)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnCalFinalizeApplication);

    OnCalProposeApplicationHandle =
        GetNotifDelegate(ovrMessage_Notification_Cal_ProposeApplication)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnCalProposeApplication);

    OnGroupPresenceInvitationsSentHandle =
        GetNotifDelegate(ovrMessage_Notification_GroupPresence_InvitationsSent)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnGroupPresenceInvitationsSent);

    OnGroupPresenceJoinIntentReceivedHandle =
        GetNotifDelegate(ovrMessage_Notification_GroupPresence_JoinIntentReceived)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnGroupPresenceJoinIntentReceived);

    OnGroupPresenceLeaveIntentReceivedHandle =
        GetNotifDelegate(ovrMessage_Notification_GroupPresence_LeaveIntentReceived)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnGroupPresenceLeaveIntentReceived);

    OnHTTPTransferHandle =
        GetNotifDelegate(ovrMessage_Notification_HTTP_Transfer)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnHTTPTransfer);

    OnLivestreamingStatusChangeHandle =
        GetNotifDelegate(ovrMessage_Notification_Livestreaming_StatusChange)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnLivestreamingStatusChange);

    OnNetSyncConnectionStatusChangedHandle =
        GetNotifDelegate(ovrMessage_Notification_NetSync_ConnectionStatusChanged)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnNetSyncConnectionStatusChanged);

    OnNetSyncSessionsChangedHandle =
        GetNotifDelegate(ovrMessage_Notification_NetSync_SessionsChanged)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnNetSyncSessionsChanged);

    OnNetworkingConnectionStateChangeHandle =
        GetNotifDelegate(ovrMessage_Notification_Networking_ConnectionStateChange)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnNetworkingConnectionStateChange);

    OnNetworkingPeerConnectRequestHandle =
        GetNotifDelegate(ovrMessage_Notification_Networking_PeerConnectRequest)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnNetworkingPeerConnectRequest);

    OnNetworkingPingResultHandle =
        GetNotifDelegate(ovrMessage_Notification_Networking_PingResult)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnNetworkingPingResult);

    OnPartyPartyUpdateHandle =
        GetNotifDelegate(ovrMessage_Notification_Party_PartyUpdate)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnPartyPartyUpdate);

    OnRoomInviteAcceptedHandle =
        GetNotifDelegate(ovrMessage_Notification_Room_InviteAccepted)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnRoomInviteAccepted);

    OnRoomInviteReceivedHandle =
        GetNotifDelegate(ovrMessage_Notification_Room_InviteReceived)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnRoomInviteReceived);

    OnRoomRoomUpdateHandle =
        GetNotifDelegate(ovrMessage_Notification_Room_RoomUpdate)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnRoomRoomUpdate);

    OnSessionInvitationsSentHandle =
        GetNotifDelegate(ovrMessage_Notification_Session_InvitationsSent)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnSessionInvitationsSent);

    OnVoipConnectRequestHandle =
        GetNotifDelegate(ovrMessage_Notification_Voip_ConnectRequest)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnVoipConnectRequest);

    OnVoipMicrophoneAvailabilityStateUpdateHandle =
        GetNotifDelegate(ovrMessage_Notification_Voip_MicrophoneAvailabilityStateUpdate)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnVoipMicrophoneAvailabilityStateUpdate);

    OnVoipStateChangeHandle =
        GetNotifDelegate(ovrMessage_Notification_Voip_StateChange)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnVoipStateChange);

    OnVoipSystemVoipStateHandle =
        GetNotifDelegate(ovrMessage_Notification_Voip_SystemVoipState)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnVoipSystemVoipState);

    OnVrcameraGetDataChannelMessageUpdateHandle =
        GetNotifDelegate(ovrMessage_Notification_Vrcamera_GetDataChannelMessageUpdate)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnVrcameraGetDataChannelMessageUpdate);

    OnVrcameraGetSurfaceUpdateHandle =
        GetNotifDelegate(ovrMessage_Notification_Vrcamera_GetSurfaceUpdate)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnVrcameraGetSurfaceUpdate);

    bOculusInit = false;

#if TICK_SUBSYSTEM
#if PLATFORM_WINDOWS
    bOculusInit = InitWithWindowsPlatform();
#elif PLATFORM_ANDROID
    bOculusInit = InitWithAndroidPlatform();
#endif
#endif

    NotifyGameInstanceThatSubsystemStarted(bOculusInit);
}

void UOvrPlatformSubsystem::Deinitialize()
{
    UE_LOG(LogOvrPlatform, Display, TEXT("UOvrPlatformSubsystem::Deinitialize"));

    // Detaching message handlers
    GetNotifDelegate(ovrMessage_Notification_ApplicationLifecycle_LaunchIntentChanged).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_AssetFile_DownloadUpdate).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_Cal_FinalizeApplication).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_Cal_ProposeApplication).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_GroupPresence_InvitationsSent).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_GroupPresence_JoinIntentReceived).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_GroupPresence_LeaveIntentReceived).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_HTTP_Transfer).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_Livestreaming_StatusChange).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_NetSync_ConnectionStatusChanged).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_NetSync_SessionsChanged).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_Networking_ConnectionStateChange).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_Networking_PeerConnectRequest).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_Networking_PingResult).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_Party_PartyUpdate).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_Room_InviteAccepted).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_Room_InviteReceived).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_Room_RoomUpdate).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_Session_InvitationsSent).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_Voip_ConnectRequest).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_Voip_MicrophoneAvailabilityStateUpdate).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_Voip_StateChange).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_Voip_SystemVoipState).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_Vrcamera_GetDataChannelMessageUpdate).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_Vrcamera_GetSurfaceUpdate).RemoveAll(this);
}

void UOvrPlatformSubsystem::NotifyGameInstanceThatSubsystemStarted(bool bOculusPlatformIsInitialized) const
{
    // IMPORTANT: The subsystem notifies the game instance when it is ready.
    FOutputDeviceNull OutputDeviceNull;
    GetGameInstance()->CallFunctionByNameWithArguments(
        *FString::Printf(TEXT("OvrPlatformSubsystemStarted %s"), bOculusInit ? TEXT("true") : TEXT("false")),
        OutputDeviceNull,
        nullptr,
        true);
}

#if PLATFORM_WINDOWS
bool UOvrPlatformSubsystem::InitWithWindowsPlatform()
{
    UE_LOG(LogOvrPlatform, Verbose, TEXT("UOvrPlatformSubsystem::InitWithWindowsPlatform()"));

    auto OculusAppId = GetAppId();
    if (OculusAppId.IsEmpty())
    {
        UE_LOG(LogOvrPlatform, Error, TEXT("Missing RiftAppId key in OnlineSubsystemOculus of DefaultEngine.ini"));
        return false;
    }

    // We can start in standalone mode by providing credentials via either the command line or in DefaultEngine.ini.
    FString Email, Password;
    if (!FParse::Value(FCommandLine::Get(), TEXT("OculusEmail"), Email) ||
        !FParse::Value(FCommandLine::Get(), TEXT("OculusPassword"), Password))
    {
        Email = GConfig->GetStr(TEXT("OnlineSubsystemOculus"), TEXT("OculusEmail"), GEngineIni);
        Password = GConfig->GetStr(TEXT("OnlineSubsystemOculus"), TEXT("OculusPassword"), GEngineIni);
    }

    if (!Email.IsEmpty() && !Password.IsEmpty())
    {
        std::string EmailANSI = TCHAR_TO_UTF8(*Email);
        std::string PasswordANSI = TCHAR_TO_UTF8(*Password);

        ovrOculusInitParams InitParams;
        InitParams.sType = ovrPlatformStructureType_OculusInitParams;
        InitParams.email = EmailANSI.c_str();
        InitParams.password = PasswordANSI.c_str();
        InitParams.appId = atoll(TCHAR_TO_UTF8(*OculusAppId));
        InitParams.uriPrefixOverride = nullptr;

        UE_LOG(LogOvrPlatform, Display, TEXT("Login with email [%s]"), *Email);

#if WITH_EDITOR
        try
#endif
        {
            ovrPlatformInitializeResult InitResult;
            ovr_Platform_InitializeStandaloneOculusEx(&InitParams, &InitResult, PLATFORM_PRODUCT_VERSION, PLATFORM_MAJOR_VERSION);

            if (InitResult == ovrPlatformInitialize_Success)
            {
                UE_LOG(LogOvrPlatform, Display, TEXT("UOvrPlatformSubsystem::InitWithWindowsPlatform: ovr_Platform_InitializeStandaloneOculusEx successful"));
            }
            else
            {
                UE_LOG(LogOvrPlatform, Error,
                    TEXT("UOvrPlatformSubsystem::InitWithWindowsPlatform: ovr_Platform_InitializeStandaloneOculusEx error: %s"),
                    ANSI_TO_TCHAR(ovrPlatformInitializeResult_ToString(InitResult)));
                return false;
            }
        }
#if WITH_EDITOR
        catch (...)
        {
            UE_LOG(LogOvrPlatform, Error, TEXT("UOvrPlatformSubsystem::InitWithWindowsPlatform: ovr_Platform_InitializeStandaloneOculusEx exception"));
            return false;
        }
#endif
    }
    else
    {
        UE_LOG(LogOvrPlatform, Display, TEXT("Login with current credentials"));

#if WITH_EDITOR
        try
#endif
        {
            auto InitResult = ovr_PlatformInitializeWindows(TCHAR_TO_UTF8(*OculusAppId));
            if (InitResult == ovrPlatformInitialize_Success)
            {
                UE_LOG(LogOvrPlatform, Display, TEXT("UOvrPlatformSubsystem::InitWithWindowsPlatform: ovr_PlatformInitializeWindows successful"));
            }
            else
            {
                UE_LOG(LogOvrPlatform, Error,
                    TEXT("UOvrPlatformSubsystem::InitWithWindowsPlatform: ovr_PlatformInitializeWindows error: %d"),
                    static_cast<int>(InitResult));
                return false;
            }
        }
#if WITH_EDITOR
        catch (...)
        {
            UE_LOG(LogOvrPlatform, Error, TEXT("UOvrPlatformSubsystem::InitWithWindowsPlatform: ovr_PlatformInitializeWindows exception"));
            return false;
        }
#endif
    }

    return true;
}
#elif PLATFORM_ANDROID
bool UOvrPlatformSubsystem::InitWithAndroidPlatform()
{
    UE_LOG(LogOvrPlatform, Verbose, TEXT("UOvrPlatformSubsystem::InitWithAndroidPlatform()"));

    auto OculusAppId = GetAppId();
    if (OculusAppId.IsEmpty())
    {
        UE_LOG(LogOvrPlatform, Error, TEXT("Missing MobileAppId key in OnlineSubsystemOculus of DefaultEngine.ini"));
        return false;
    }

    JNIEnv* Env = FAndroidApplication::GetJavaEnv();

    if (Env == nullptr)
    {
        UE_LOG(LogOvrPlatform, Error, TEXT("Missing JNIEnv"));
        return false;
    }

    auto InitResult = ovr_PlatformInitializeAndroid(TCHAR_TO_UTF8(*OculusAppId), FAndroidApplication::GetGameActivityThis(), Env);
    if (InitResult != ovrPlatformInitialize_Success)
    {
        UE_LOG(LogOvrPlatform, Error, TEXT("Failed to initialize the Oculus Platform SDK! Error code: %d"), (int)InitResult);
        return false;
    }

    return true;
}
#endif

FString UOvrPlatformSubsystem::GetAppId()
{
    // Try to get the platform specific field before the generic one
#if PLATFORM_WINDOWS
    auto AppId = GConfig->GetStr(TEXT("OnlineSubsystemOculus"), TEXT("RiftAppId"), GEngineIni);
#elif PLATFORM_ANDROID
    auto AppId = GConfig->GetStr(TEXT("OnlineSubsystemOculus"), TEXT("MobileAppId"), GEngineIni);
#endif

    if (!AppId.IsEmpty()) {
        return AppId;
    }

#if PLATFORM_WINDOWS
    UE_LOG(LogOvrPlatform, Warning, TEXT("Could not find 'RiftAppId' key in engine config.  Trying 'OculusAppId'.  Move your oculus app id to 'RiftAppId' to use in your rift app and make this warning go away."));
#elif PLATFORM_ANDROID
    UE_LOG(LogOvrPlatform, Warning, TEXT("Could not find 'MobileAppId' key in engine config.  Trying 'OculusAppId'.  Move your oculus app id to 'MobileAppId' to use in your quest/go app make this warning go away."));
#endif

    return GConfig->GetStr(TEXT("OnlineSubsystemOculus"), TEXT("OculusAppId"), GEngineIni);
}

void UOvrPlatformSubsystem::HandleOnPlatformInitialized(TOvrMessageHandlePtr Message, bool bIsError)
{
    UE_LOG(LogOvrPlatform, Verbose, TEXT("UOvrPlatformSubsystem::OnPlatformInitialized()"));

    // We no longer need the delegate.
    if (OnPlatformInitializedStandaloneHandle.IsValid())
    {
        RemoveNotifDelegate(ovrMessage_Platform_InitializeStandaloneOculus, OnPlatformInitializedStandaloneHandle);
        OnPlatformInitializedStandaloneHandle.Reset();
    }

    if (bIsError)
    {
        UE_LOG(LogOvrPlatform, Error, TEXT("The Oculus platform failed to initialize asynchronously"));
        UE_LOG(LogOvrPlatform, Error, TEXT("Check the credentials used, and entitlement to the app id provided."));
        return;
    }
}

void UOvrPlatformSubsystem::AddRequestDelegate(ovrRequest RequestId, FOvrPlatformMessageOnComplete&& Delegate)
{
    RequestDelegates.Emplace(RequestId, Delegate);
}

void UOvrPlatformSubsystem::RemoveRequestDelegate(ovrRequest RequestId)
{
    if (RequestDelegates.Contains(RequestId))
    {
        // Remove the delegate
        RequestDelegates[RequestId].Unbind();
        RequestDelegates.Remove(RequestId);
    }
}

FOvrPlatformMulticastMessageOnComplete& UOvrPlatformSubsystem::GetNotifDelegate(ovrMessageType MessageType)
{
    return NotifDelegates.FindOrAdd(MessageType);
}

void UOvrPlatformSubsystem::RemoveNotifDelegate(ovrMessageType MessageType, const FDelegateHandle& Delegate)
{
    NotifDelegates.FindOrAdd(MessageType).Remove(Delegate);
}

void UOvrPlatformSubsystem::HandleOnApplicationLifecycleLaunchIntentChanged(TOvrMessageHandlePtr Message, bool bIsError)
{
    if (bIsError)
    {
        ovrErrorHandle Error = ovr_Message_GetError(*Message);
        FString ErrorMessage = ovr_Error_GetMessage(Error);
        UE_LOG(LogOvrPlatform, Error, TEXT("Error in HandleOnApplicationLifecycleLaunchIntentChanged: %s"), *ErrorMessage);
    }
    else
    {
        FString LaunchIntentChanged = UTF8_TO_TCHAR(ovr_Message_GetString(*Message));
        OnApplicationLifecycleLaunchIntentChanged.Broadcast(LaunchIntentChanged);
    }
}

void UOvrPlatformSubsystem::HandleOnAssetFileDownloadUpdate(TOvrMessageHandlePtr Message, bool bIsError)
{
    if (bIsError)
    {
        ovrErrorHandle Error = ovr_Message_GetError(*Message);
        FString ErrorMessage = ovr_Error_GetMessage(Error);
        UE_LOG(LogOvrPlatform, Error, TEXT("Error in HandleOnAssetFileDownloadUpdate: %s"), *ErrorMessage);
    }
    else
    {
        ovrAssetFileDownloadUpdateHandle Handle = ovr_Message_GetAssetFileDownloadUpdate(*Message);
        FOvrAssetFileDownloadUpdate DownloadUpdate = FOvrAssetFileDownloadUpdate(Handle, Message);
        OnAssetFileDownloadUpdate.Broadcast(DownloadUpdate);
    }
}

void UOvrPlatformSubsystem::HandleOnCalFinalizeApplication(TOvrMessageHandlePtr Message, bool bIsError)
{
    if (bIsError)
    {
        ovrErrorHandle Error = ovr_Message_GetError(*Message);
        FString ErrorMessage = ovr_Error_GetMessage(Error);
        UE_LOG(LogOvrPlatform, Error, TEXT("Error in HandleOnCalFinalizeApplication: %s"), *ErrorMessage);
    }
    else
    {
        ovrCalApplicationFinalizedHandle Handle = ovr_Message_GetCalApplicationFinalized(*Message);
        FOvrCalApplicationFinalized FinalizeApplication = FOvrCalApplicationFinalized(Handle, Message);
        OnCalFinalizeApplication.Broadcast(FinalizeApplication);
    }
}

void UOvrPlatformSubsystem::HandleOnCalProposeApplication(TOvrMessageHandlePtr Message, bool bIsError)
{
    if (bIsError)
    {
        ovrErrorHandle Error = ovr_Message_GetError(*Message);
        FString ErrorMessage = ovr_Error_GetMessage(Error);
        UE_LOG(LogOvrPlatform, Error, TEXT("Error in HandleOnCalProposeApplication: %s"), *ErrorMessage);
    }
    else
    {
        ovrCalApplicationProposedHandle Handle = ovr_Message_GetCalApplicationProposed(*Message);
        FOvrCalApplicationProposed ProposeApplication = FOvrCalApplicationProposed(Handle, Message);
        OnCalProposeApplication.Broadcast(ProposeApplication);
    }
}

void UOvrPlatformSubsystem::HandleOnGroupPresenceInvitationsSent(TOvrMessageHandlePtr Message, bool bIsError)
{
    if (bIsError)
    {
        ovrErrorHandle Error = ovr_Message_GetError(*Message);
        FString ErrorMessage = ovr_Error_GetMessage(Error);
        UE_LOG(LogOvrPlatform, Error, TEXT("Error in HandleOnGroupPresenceInvitationsSent: %s"), *ErrorMessage);
    }
    else
    {
        ovrLaunchInvitePanelFlowResultHandle Handle = ovr_Message_GetLaunchInvitePanelFlowResult(*Message);
        FOvrLaunchInvitePanelFlowResult InvitationsSent = FOvrLaunchInvitePanelFlowResult(Handle, Message);
        OnGroupPresenceInvitationsSent.Broadcast(InvitationsSent);
    }
}

void UOvrPlatformSubsystem::HandleOnGroupPresenceJoinIntentReceived(TOvrMessageHandlePtr Message, bool bIsError)
{
    if (bIsError)
    {
        ovrErrorHandle Error = ovr_Message_GetError(*Message);
        FString ErrorMessage = ovr_Error_GetMessage(Error);
        UE_LOG(LogOvrPlatform, Error, TEXT("Error in HandleOnGroupPresenceJoinIntentReceived: %s"), *ErrorMessage);
    }
    else
    {
        ovrGroupPresenceJoinIntentHandle Handle = ovr_Message_GetGroupPresenceJoinIntent(*Message);
        FOvrGroupPresenceJoinIntent JoinIntentReceived = FOvrGroupPresenceJoinIntent(Handle, Message);
        OnGroupPresenceJoinIntentReceived.Broadcast(JoinIntentReceived);
    }
}

void UOvrPlatformSubsystem::HandleOnGroupPresenceLeaveIntentReceived(TOvrMessageHandlePtr Message, bool bIsError)
{
    if (bIsError)
    {
        ovrErrorHandle Error = ovr_Message_GetError(*Message);
        FString ErrorMessage = ovr_Error_GetMessage(Error);
        UE_LOG(LogOvrPlatform, Error, TEXT("Error in HandleOnGroupPresenceLeaveIntentReceived: %s"), *ErrorMessage);
    }
    else
    {
        ovrGroupPresenceLeaveIntentHandle Handle = ovr_Message_GetGroupPresenceLeaveIntent(*Message);
        FOvrGroupPresenceLeaveIntent LeaveIntentReceived = FOvrGroupPresenceLeaveIntent(Handle, Message);
        OnGroupPresenceLeaveIntentReceived.Broadcast(LeaveIntentReceived);
    }
}

void UOvrPlatformSubsystem::HandleOnHTTPTransfer(TOvrMessageHandlePtr Message, bool bIsError)
{
    if (bIsError)
    {
        ovrErrorHandle Error = ovr_Message_GetError(*Message);
        FString ErrorMessage = ovr_Error_GetMessage(Error);
        UE_LOG(LogOvrPlatform, Error, TEXT("Error in HandleOnHTTPTransfer: %s"), *ErrorMessage);
    }
    else
    {
        ovrHttpTransferUpdateHandle Handle = ovr_Message_GetHttpTransferUpdate(*Message);
        FOvrHttpTransferUpdate Transfer = FOvrHttpTransferUpdate(Handle, Message);
        OnHTTPTransfer.Broadcast(Transfer);
    }
}

void UOvrPlatformSubsystem::HandleOnLivestreamingStatusChange(TOvrMessageHandlePtr Message, bool bIsError)
{
    if (bIsError)
    {
        ovrErrorHandle Error = ovr_Message_GetError(*Message);
        FString ErrorMessage = ovr_Error_GetMessage(Error);
        UE_LOG(LogOvrPlatform, Error, TEXT("Error in HandleOnLivestreamingStatusChange: %s"), *ErrorMessage);
    }
    else
    {
        ovrLivestreamingStatusHandle Handle = ovr_Message_GetLivestreamingStatus(*Message);
        FOvrLivestreamingStatus StatusChange = FOvrLivestreamingStatus(Handle, Message);
        OnLivestreamingStatusChange.Broadcast(StatusChange);
    }
}

void UOvrPlatformSubsystem::HandleOnNetSyncConnectionStatusChanged(TOvrMessageHandlePtr Message, bool bIsError)
{
    if (bIsError)
    {
        ovrErrorHandle Error = ovr_Message_GetError(*Message);
        FString ErrorMessage = ovr_Error_GetMessage(Error);
        UE_LOG(LogOvrPlatform, Error, TEXT("Error in HandleOnNetSyncConnectionStatusChanged: %s"), *ErrorMessage);
    }
    else
    {
        ovrNetSyncConnectionHandle Handle = ovr_Message_GetNetSyncConnection(*Message);
        FOvrNetSyncConnection ConnectionStatusChanged = FOvrNetSyncConnection(Handle, Message);
        OnNetSyncConnectionStatusChanged.Broadcast(ConnectionStatusChanged);
    }
}

void UOvrPlatformSubsystem::HandleOnNetSyncSessionsChanged(TOvrMessageHandlePtr Message, bool bIsError)
{
    if (bIsError)
    {
        ovrErrorHandle Error = ovr_Message_GetError(*Message);
        FString ErrorMessage = ovr_Error_GetMessage(Error);
        UE_LOG(LogOvrPlatform, Error, TEXT("Error in HandleOnNetSyncSessionsChanged: %s"), *ErrorMessage);
    }
    else
    {
        ovrNetSyncSessionsChangedNotificationHandle Handle = ovr_Message_GetNetSyncSessionsChangedNotification(*Message);
        FOvrNetSyncSessionsChangedNotification SessionsChanged = FOvrNetSyncSessionsChangedNotification(Handle, Message);
        OnNetSyncSessionsChanged.Broadcast(SessionsChanged);
    }
}

void UOvrPlatformSubsystem::HandleOnNetworkingConnectionStateChange(TOvrMessageHandlePtr Message, bool bIsError)
{
    if (bIsError)
    {
        ovrErrorHandle Error = ovr_Message_GetError(*Message);
        FString ErrorMessage = ovr_Error_GetMessage(Error);
        UE_LOG(LogOvrPlatform, Error, TEXT("Error in HandleOnNetworkingConnectionStateChange: %s"), *ErrorMessage);
    }
    else
    {
        ovrNetworkingPeerHandle Handle = ovr_Message_GetNetworkingPeer(*Message);
        FOvrNetworkingPeer ConnectionStateChange = FOvrNetworkingPeer(Handle, Message);
        OnNetworkingConnectionStateChange.Broadcast(ConnectionStateChange);
    }
}

void UOvrPlatformSubsystem::HandleOnNetworkingPeerConnectRequest(TOvrMessageHandlePtr Message, bool bIsError)
{
    if (bIsError)
    {
        ovrErrorHandle Error = ovr_Message_GetError(*Message);
        FString ErrorMessage = ovr_Error_GetMessage(Error);
        UE_LOG(LogOvrPlatform, Error, TEXT("Error in HandleOnNetworkingPeerConnectRequest: %s"), *ErrorMessage);
    }
    else
    {
        ovrNetworkingPeerHandle Handle = ovr_Message_GetNetworkingPeer(*Message);
        FOvrNetworkingPeer PeerConnectRequest = FOvrNetworkingPeer(Handle, Message);
        OnNetworkingPeerConnectRequest.Broadcast(PeerConnectRequest);
    }
}

void UOvrPlatformSubsystem::HandleOnNetworkingPingResult(TOvrMessageHandlePtr Message, bool bIsError)
{
    if (bIsError)
    {
        ovrErrorHandle Error = ovr_Message_GetError(*Message);
        FString ErrorMessage = ovr_Error_GetMessage(Error);
        UE_LOG(LogOvrPlatform, Error, TEXT("Error in HandleOnNetworkingPingResult: %s"), *ErrorMessage);
    }
    else
    {
        ovrPingResultHandle Handle = ovr_Message_GetPingResult(*Message);
        FOvrPingResult PingResult = FOvrPingResult(Handle, Message);
        OnNetworkingPingResult.Broadcast(PingResult);
    }
}

void UOvrPlatformSubsystem::HandleOnPartyPartyUpdate(TOvrMessageHandlePtr Message, bool bIsError)
{
    if (bIsError)
    {
        ovrErrorHandle Error = ovr_Message_GetError(*Message);
        FString ErrorMessage = ovr_Error_GetMessage(Error);
        UE_LOG(LogOvrPlatform, Error, TEXT("Error in HandleOnPartyPartyUpdate: %s"), *ErrorMessage);
    }
    else
    {
        ovrPartyUpdateNotificationHandle Handle = ovr_Message_GetPartyUpdateNotification(*Message);
        FOvrPartyUpdateNotification PartyUpdate = FOvrPartyUpdateNotification(Handle, Message);
        OnPartyPartyUpdate.Broadcast(PartyUpdate);
    }
}

void UOvrPlatformSubsystem::HandleOnRoomInviteAccepted(TOvrMessageHandlePtr Message, bool bIsError)
{
    if (bIsError)
    {
        ovrErrorHandle Error = ovr_Message_GetError(*Message);
        FString ErrorMessage = ovr_Error_GetMessage(Error);
        UE_LOG(LogOvrPlatform, Error, TEXT("Error in HandleOnRoomInviteAccepted: %s"), *ErrorMessage);
    }
    else
    {
        FString InviteAccepted = UTF8_TO_TCHAR(ovr_Message_GetString(*Message));
        OnRoomInviteAccepted.Broadcast(InviteAccepted);
    }
}

void UOvrPlatformSubsystem::HandleOnRoomInviteReceived(TOvrMessageHandlePtr Message, bool bIsError)
{
    if (bIsError)
    {
        ovrErrorHandle Error = ovr_Message_GetError(*Message);
        FString ErrorMessage = ovr_Error_GetMessage(Error);
        UE_LOG(LogOvrPlatform, Error, TEXT("Error in HandleOnRoomInviteReceived: %s"), *ErrorMessage);
    }
    else
    {
        ovrRoomInviteNotificationHandle Handle = ovr_Message_GetRoomInviteNotification(*Message);
        FOvrRoomInviteNotification InviteReceived = FOvrRoomInviteNotification(Handle, Message);
        OnRoomInviteReceived.Broadcast(InviteReceived);
    }
}

void UOvrPlatformSubsystem::HandleOnRoomRoomUpdate(TOvrMessageHandlePtr Message, bool bIsError)
{
    if (bIsError)
    {
        ovrErrorHandle Error = ovr_Message_GetError(*Message);
        FString ErrorMessage = ovr_Error_GetMessage(Error);
        UE_LOG(LogOvrPlatform, Error, TEXT("Error in HandleOnRoomRoomUpdate: %s"), *ErrorMessage);
    }
    else
    {
        ovrRoomHandle Handle = ovr_Message_GetRoom(*Message);
        FOvrRoom RoomUpdate = FOvrRoom(Handle, Message);
        OnRoomRoomUpdate.Broadcast(RoomUpdate);
    }
}

void UOvrPlatformSubsystem::HandleOnSessionInvitationsSent(TOvrMessageHandlePtr Message, bool bIsError)
{
    if (bIsError)
    {
        ovrErrorHandle Error = ovr_Message_GetError(*Message);
        FString ErrorMessage = ovr_Error_GetMessage(Error);
        UE_LOG(LogOvrPlatform, Error, TEXT("Error in HandleOnSessionInvitationsSent: %s"), *ErrorMessage);
    }
    else
    {
        ovrLaunchInvitePanelFlowResultHandle Handle = ovr_Message_GetLaunchInvitePanelFlowResult(*Message);
        FOvrLaunchInvitePanelFlowResult InvitationsSent = FOvrLaunchInvitePanelFlowResult(Handle, Message);
        OnSessionInvitationsSent.Broadcast(InvitationsSent);
    }
}

void UOvrPlatformSubsystem::HandleOnVoipConnectRequest(TOvrMessageHandlePtr Message, bool bIsError)
{
    if (bIsError)
    {
        ovrErrorHandle Error = ovr_Message_GetError(*Message);
        FString ErrorMessage = ovr_Error_GetMessage(Error);
        UE_LOG(LogOvrPlatform, Error, TEXT("Error in HandleOnVoipConnectRequest: %s"), *ErrorMessage);
    }
    else
    {
        ovrNetworkingPeerHandle Handle = ovr_Message_GetNetworkingPeer(*Message);
        FOvrNetworkingPeer ConnectRequest = FOvrNetworkingPeer(Handle, Message);
        OnVoipConnectRequest.Broadcast(ConnectRequest);
    }
}

void UOvrPlatformSubsystem::HandleOnVoipMicrophoneAvailabilityStateUpdate(TOvrMessageHandlePtr Message, bool bIsError)
{
    if (bIsError)
    {
        ovrErrorHandle Error = ovr_Message_GetError(*Message);
        FString ErrorMessage = ovr_Error_GetMessage(Error);
        UE_LOG(LogOvrPlatform, Error, TEXT("Error in HandleOnVoipMicrophoneAvailabilityStateUpdate: %s"), *ErrorMessage);
    }
    else
    {
        FString MicrophoneAvailabilityStateUpdate = UTF8_TO_TCHAR(ovr_Message_GetString(*Message));
        OnVoipMicrophoneAvailabilityStateUpdate.Broadcast(MicrophoneAvailabilityStateUpdate);
    }
}

void UOvrPlatformSubsystem::HandleOnVoipStateChange(TOvrMessageHandlePtr Message, bool bIsError)
{
    if (bIsError)
    {
        ovrErrorHandle Error = ovr_Message_GetError(*Message);
        FString ErrorMessage = ovr_Error_GetMessage(Error);
        UE_LOG(LogOvrPlatform, Error, TEXT("Error in HandleOnVoipStateChange: %s"), *ErrorMessage);
    }
    else
    {
        ovrNetworkingPeerHandle Handle = ovr_Message_GetNetworkingPeer(*Message);
        FOvrNetworkingPeer StateChange = FOvrNetworkingPeer(Handle, Message);
        OnVoipStateChange.Broadcast(StateChange);
    }
}

void UOvrPlatformSubsystem::HandleOnVoipSystemVoipState(TOvrMessageHandlePtr Message, bool bIsError)
{
    if (bIsError)
    {
        ovrErrorHandle Error = ovr_Message_GetError(*Message);
        FString ErrorMessage = ovr_Error_GetMessage(Error);
        UE_LOG(LogOvrPlatform, Error, TEXT("Error in HandleOnVoipSystemVoipState: %s"), *ErrorMessage);
    }
    else
    {
        ovrSystemVoipStateHandle Handle = ovr_Message_GetSystemVoipState(*Message);
        FOvrSystemVoipState SystemVoipState = FOvrSystemVoipState(Handle, Message);
        OnVoipSystemVoipState.Broadcast(SystemVoipState);
    }
}

void UOvrPlatformSubsystem::HandleOnVrcameraGetDataChannelMessageUpdate(TOvrMessageHandlePtr Message, bool bIsError)
{
    if (bIsError)
    {
        ovrErrorHandle Error = ovr_Message_GetError(*Message);
        FString ErrorMessage = ovr_Error_GetMessage(Error);
        UE_LOG(LogOvrPlatform, Error, TEXT("Error in HandleOnVrcameraGetDataChannelMessageUpdate: %s"), *ErrorMessage);
    }
    else
    {
        FString GetDataChannelMessageUpdate = UTF8_TO_TCHAR(ovr_Message_GetString(*Message));
        OnVrcameraGetDataChannelMessageUpdate.Broadcast(GetDataChannelMessageUpdate);
    }
}

void UOvrPlatformSubsystem::HandleOnVrcameraGetSurfaceUpdate(TOvrMessageHandlePtr Message, bool bIsError)
{
    if (bIsError)
    {
        ovrErrorHandle Error = ovr_Message_GetError(*Message);
        FString ErrorMessage = ovr_Error_GetMessage(Error);
        UE_LOG(LogOvrPlatform, Error, TEXT("Error in HandleOnVrcameraGetSurfaceUpdate: %s"), *ErrorMessage);
    }
    else
    {
        FString GetSurfaceUpdate = UTF8_TO_TCHAR(ovr_Message_GetString(*Message));
        OnVrcameraGetSurfaceUpdate.Broadcast(GetSurfaceUpdate);
    }
}


void UOvrPlatformSubsystem::Tick(float DeltaTime)
{
    for (;;)
    {
        ovrMessageHandle Message = ovr_PopMessage();
        if (!Message)
        {
            break;
        }
        OnReceiveMessage(Message);
    }
    if (DeltaTime > 4.0f)
    {
        UE_LOG(LogOvrPlatform, Warning, TEXT("DeltaTime was %f seconds.  Time sensitive oculus notifications may time out."), DeltaTime);
    }
}

bool UOvrPlatformSubsystem::IsTickable() const
{
    // Since we are a UCLASS this will prevent us from ticking the CDO.
    return bMessagePumpActivated && !IsTemplate() && TICK_SUBSYSTEM;
}

TStatId UOvrPlatformSubsystem::GetStatId() const
{
    RETURN_QUICK_DECLARE_CYCLE_STAT(FOvrPlatformSubsystemMessagePump, STATGROUP_Tickables);
}

void UOvrPlatformSubsystem::OnReceiveMessage(ovrMessageHandle Message)
{
    auto MessagePtr = std::make_shared<TOvrMessageHandle>(Message);

    auto RequestId = ovr_Message_GetRequestID(*MessagePtr);
    bool bIsError = ovr_Message_IsError(*MessagePtr);

    if (RequestDelegates.Contains(RequestId))
    {
        RequestDelegates[RequestId].ExecuteIfBound(MessagePtr, bIsError);
        RemoveRequestDelegate(RequestId);
    }
    else
    {
        auto MessageType = ovr_Message_GetType(*MessagePtr);
        if (NotifDelegates.Contains(MessageType))
        {
            if (!bIsError)
            {
                NotifDelegates[MessageType].Broadcast(MessagePtr, bIsError);
            }
        }
        else
        {
            UE_LOG(LogOvrPlatform, Warning, TEXT("Unhandled request id: %llu type: #%010x"), RequestId, static_cast<int32>(MessageType));
        }
    }
}
