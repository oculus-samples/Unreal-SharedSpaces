// Copyright (c) Meta Platforms, Inc. and affiliates.

// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#include "OVRPlatformSubsystem.h"
#include "Misc/ConfigCacheIni.h"
#include "Misc/OutputDeviceNull.h"
#include "Misc/CommandLine.h"
#include "OVRPlatform.h"
#include "Runtime/Launch/Resources/Version.h"

#include "Engine/GameInstance.h"

#include <string>

#define TICK_SUBSYSTEM true

bool UOvrPlatformSubsystem::bFirstInstanceInit = true;

void UOvrPlatformSubsystem::StartMessagePump()
{
    bMessagePumpActivated = true;

    if (!bOculusInit && GetDoAsyncInit())
    {
        StartAsyncInit();
    }
}

bool UOvrPlatformSubsystem::ShouldCreateSubsystem (UObject * Outer) const
{
	if (IsRunningCommandlet() || GIsBuildMachine)
	{
		// Avoids initialization time expense & errors due to no local logged-in
		// user on build machines/cook runs/commandlets.
		return false;
	}

	return !HasAnyFlags(RF_Transient) && Super::ShouldCreateSubsystem(Outer);
}

void UOvrPlatformSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    UE_LOG(LogOvrPlatform, Display, TEXT("UOvrPlatformSubsystem::Initialize"));

    // Message pump waits for your authorization with a call to Start().
    bMessagePumpActivated = false;

    // Message handlers
    OnAbuseReportReportButtonPressedHandle =
        GetNotifDelegate(ovrMessage_Notification_AbuseReport_ReportButtonPressed)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnAbuseReportReportButtonPressed);

    OnApplicationLifecycleLaunchIntentChangedHandle =
        GetNotifDelegate(ovrMessage_Notification_ApplicationLifecycle_LaunchIntentChanged)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnApplicationLifecycleLaunchIntentChanged);

    OnAssetFileDownloadUpdateHandle =
        GetNotifDelegate(ovrMessage_Notification_AssetFile_DownloadUpdate)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnAssetFileDownloadUpdate);

    OnCowatchingApiNotReadyHandle =
        GetNotifDelegate(ovrMessage_Notification_Cowatching_ApiNotReady)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnCowatchingApiNotReady);

    OnCowatchingApiReadyHandle =
        GetNotifDelegate(ovrMessage_Notification_Cowatching_ApiReady)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnCowatchingApiReady);

    OnCowatchingInSessionChangedHandle =
        GetNotifDelegate(ovrMessage_Notification_Cowatching_InSessionChanged)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnCowatchingInSessionChanged);

    OnCowatchingInitializedHandle =
        GetNotifDelegate(ovrMessage_Notification_Cowatching_Initialized)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnCowatchingInitialized);

    OnCowatchingPresenterDataChangedHandle =
        GetNotifDelegate(ovrMessage_Notification_Cowatching_PresenterDataChanged)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnCowatchingPresenterDataChanged);

    OnCowatchingSessionStartedHandle =
        GetNotifDelegate(ovrMessage_Notification_Cowatching_SessionStarted)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnCowatchingSessionStarted);

    OnCowatchingSessionStoppedHandle =
        GetNotifDelegate(ovrMessage_Notification_Cowatching_SessionStopped)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnCowatchingSessionStopped);

    OnCowatchingViewersDataChangedHandle =
        GetNotifDelegate(ovrMessage_Notification_Cowatching_ViewersDataChanged)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnCowatchingViewersDataChanged);

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

    OnPartyPartyUpdateHandle =
        GetNotifDelegate(ovrMessage_Notification_Party_PartyUpdate)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnPartyPartyUpdate);

    OnVoipMicrophoneAvailabilityStateUpdateHandle =
        GetNotifDelegate(ovrMessage_Notification_Voip_MicrophoneAvailabilityStateUpdate)
        .AddUObject(this, &UOvrPlatformSubsystem::HandleOnVoipMicrophoneAvailabilityStateUpdate);

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

    bool bDoAsyncInit = GetDoAsyncInit();

    if (bDoAsyncInit && IsEmailAndPasswordAuthRequested())
    {
        UE_LOG(LogOvrPlatform, Warning,
            TEXT("Async init and standalone (Username+Password) init are incompatible.  Falling back to blocking, standaline init."));
        bDoAsyncInit = false;
    }

    if (!bDoAsyncInit)
    {
#if TICK_SUBSYSTEM
#if PLATFORM_WINDOWS
        bOculusInit = InitWithWindowsPlatform();
#elif PLATFORM_ANDROID
        bOculusInit = InitWithAndroidPlatform();
#endif
#endif

        NotifyGameInstanceThatSubsystemStarted(bOculusInit);
    }
}

void UOvrPlatformSubsystem::Deinitialize()
{
    UE_LOG(LogOvrPlatform, Display, TEXT("UOvrPlatformSubsystem::Deinitialize"));

    // Reset first instance init condition
    bFirstInstanceInit = true;

    // Detaching message handlers
    GetNotifDelegate(ovrMessage_Notification_AbuseReport_ReportButtonPressed).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_ApplicationLifecycle_LaunchIntentChanged).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_AssetFile_DownloadUpdate).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_Cowatching_ApiNotReady).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_Cowatching_ApiReady).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_Cowatching_InSessionChanged).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_Cowatching_Initialized).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_Cowatching_PresenterDataChanged).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_Cowatching_SessionStarted).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_Cowatching_SessionStopped).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_Cowatching_ViewersDataChanged).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_GroupPresence_InvitationsSent).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_GroupPresence_JoinIntentReceived).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_GroupPresence_LeaveIntentReceived).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_HTTP_Transfer).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_Livestreaming_StatusChange).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_NetSync_ConnectionStatusChanged).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_NetSync_SessionsChanged).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_Party_PartyUpdate).RemoveAll(this);
    GetNotifDelegate(ovrMessage_Notification_Voip_MicrophoneAvailabilityStateUpdate).RemoveAll(this);
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
#if ENGINE_MAJOR_VERSION == 5
#if WITH_EDITOR
    if (bFirstInstanceInit) {
        // Raise warning when running multiplayer with "Run Under One Process" enabled
        ULevelEditorPlaySettings* PlaySettings = GetMutableDefault<ULevelEditorPlaySettings>();
        if (PlaySettings != nullptr)
        {
            int32 NumberOfClients = 0;
            PlaySettings->GetPlayNumberOfClients(NumberOfClients);
            bool bRunUnderOneProcess = false;
            PlaySettings->GetRunUnderOneProcess(bRunUnderOneProcess);

			if (NumberOfClients > 1 && bRunUnderOneProcess) {
				FString InProcSupportMessage;
				InProcSupportMessage += TEXT("Meta Platform SDK is not supported when 'Run Under One Process' is enabled in Multiplayer testing \n \n");
				InProcSupportMessage += TEXT("Meta Platform SDK is not supported when 'Run Under One Process' is enabled in Multiplayer testing \n");
				InProcSupportMessage += TEXT("All spawned players will use the same Platform user. Use multiprocess mode to enable multiple users \n");
				InProcSupportMessage += TEXT("To change to multiprocess mode, go to Editor Preferences->Level Editor->Play, disable Run Under One Process \n ");
				UE_LOG(LogOvrPlatform, Error, TEXT("%s"), *InProcSupportMessage);
			}
        }
    }
#endif
#endif

    UE_LOG(LogOvrPlatform, Verbose, TEXT("UOvrPlatformSubsystem::InitWithWindowsPlatform()"));

    auto OculusAppId = GetAppId();
    if (OculusAppId.IsEmpty())
    {
        UE_LOG(LogOvrPlatform, Error, TEXT("Missing RiftAppId key in OnlineSubsystemOculus of DefaultEngine.ini"));
        return false;
    }

    // We can start in standalone mode by providing credentials via either the command line or in DefaultEngine.ini.
    FString Email, Password;
    GetAuthEmailAndPassword(Email, Password);

    if (IsEmailAndPasswordAuthRequested(Email, Password))
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

    if (bFirstInstanceInit) {
        bFirstInstanceInit = false;
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

void  UOvrPlatformSubsystem::StartAsyncInit()
{
    // :TODO: Can we move this bootstrapping onto a thread?
    auto OculusAppId = GetAppId();
    if (OculusAppId.IsEmpty())
    {
        UE_LOG(LogOvrPlatform, Error, TEXT("Missing MobileAppId key in OnlineSubsystemOculus of DefaultEngine.ini"));
        NotifyGameInstanceThatSubsystemStarted(false);
        return;
    }

    ovrRequest OvrReqId;

#if PLATFORM_WINDOWS
    {
        ovrPlatformInitializeResult Result = ovrPlatformInitialize_Unknown;
        UE_LOG(LogOvrPlatform, Display, TEXT("Invoking ovr_PlatformInitializeWindowsAsynchronous(%s)"), *OculusAppId);
        OvrReqId = ovr_PlatformInitializeWindowsAsynchronous(TCHAR_TO_ANSI(*OculusAppId), &Result);
        if (Result != ovrPlatformInitialize_Success)
        {
            char const * const  szResult  = ovrPlatformInitializeResult_ToString(Result);
            UE_LOG(LogOvrPlatform, Error, TEXT("ovr_PlatformInitializeWindowsAsynchronous() failed (%d): %s"), (int)Result, ANSI_TO_TCHAR(szResult));
            NotifyGameInstanceThatSubsystemStarted(false);
            return;
        }
    }
#elif PLATFORM_ANDROID
    {
        JNIEnv* Env = FAndroidApplication::GetJavaEnv();

        if (Env == nullptr)
        {
            UE_LOG(LogOvrPlatform, Error, TEXT("Missing JNIEnv"));
            NotifyGameInstanceThatSubsystemStarted(false);
            return;
        }

        UE_LOG(LogOvrPlatform, Display, TEXT("Invoking ovr_PlatformInitializeAndroidAsynchronous(%s, ...)"), *OculusAppId);
        OvrReqId = ovr_PlatformInitializeAndroidAsynchronous(TCHAR_TO_ANSI(*OculusAppId), FAndroidApplication::GetGameActivityThis(), Env);
    }
#endif

    AddRequestDelegate(OvrReqId, FOvrPlatformMessageOnComplete::CreateUObject(this, &UOvrPlatformSubsystem::HandleOnPlatformInitialized));
}

void UOvrPlatformSubsystem::GetAuthEmailAndPassword(FString & EmailOut, FString & PasswordOut)
{
    EmailOut.Reset();
    PasswordOut.Reset();

#if PLATFORM_WINDOWS
    // Only Windows supports standalone mode / Username + Password auth.
    if (!FParse::Value(FCommandLine::Get(), TEXT("OculusEmail"), EmailOut) ||
        !FParse::Value(FCommandLine::Get(), TEXT("OculusPassword"), PasswordOut))
    {
        EmailOut = GConfig->GetStr(TEXT("OnlineSubsystemOculus"), TEXT("OculusEmail"), GEngineIni);
        PasswordOut = GConfig->GetStr(TEXT("OnlineSubsystemOculus"), TEXT("OculusPassword"), GEngineIni);
    }
#endif // PLATFORM_WINDOWS
}

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

bool UOvrPlatformSubsystem::GetDoAsyncInit()
{
    bool bDoAsyncInit = false;
    GConfig->GetBool(TEXT("OnlineSubsystemOculus"), TEXT("DoAsyncInit"), bDoAsyncInit, GEngineIni);
    return bDoAsyncInit;
}

bool UOvrPlatformSubsystem::IsEmailAndPasswordAuthRequested()
{
    FString Email, Password;
    GetAuthEmailAndPassword(Email, Password);
    return IsEmailAndPasswordAuthRequested(Email, Password);
}

bool UOvrPlatformSubsystem::IsEmailAndPasswordAuthRequested(const FString & Email, const FString & Password)
{
#if PLATFORM_WINDOWS
    // Only Windows supports standalone mode / Username + Password auth.
    return !Email.IsEmpty() && !Password.IsEmpty();
#else
    return false;
#endif
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
    }

    bOculusInit = !bIsError;
    NotifyGameInstanceThatSubsystemStarted(!bIsError);
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

void UOvrPlatformSubsystem::HandleOnAbuseReportReportButtonPressed(TOvrMessageHandlePtr Message, bool bIsError)
{
    if (bIsError)
    {
        ovrErrorHandle Error = ovr_Message_GetError(*Message);
        FString ErrorMessage = ovr_Error_GetMessage(Error);
        UE_LOG(LogOvrPlatform, Error, TEXT("Error in HandleOnAbuseReportReportButtonPressed: %s"), *ErrorMessage);
    }
    else
    {
        FString ReportButtonPressed = UTF8_TO_TCHAR(ovr_Message_GetString(*Message));
        OnAbuseReportReportButtonPressed.Broadcast(ReportButtonPressed);
    }
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

void UOvrPlatformSubsystem::HandleOnCowatchingApiNotReady(TOvrMessageHandlePtr Message, bool bIsError)
{
    if (bIsError)
    {
        ovrErrorHandle Error = ovr_Message_GetError(*Message);
        FString ErrorMessage = ovr_Error_GetMessage(Error);
        UE_LOG(LogOvrPlatform, Error, TEXT("Error in HandleOnCowatchingApiNotReady: %s"), *ErrorMessage);
    }
    else
    {
        FString ApiNotReady = UTF8_TO_TCHAR(ovr_Message_GetString(*Message));
        OnCowatchingApiNotReady.Broadcast(ApiNotReady);
    }
}

void UOvrPlatformSubsystem::HandleOnCowatchingApiReady(TOvrMessageHandlePtr Message, bool bIsError)
{
    if (bIsError)
    {
        ovrErrorHandle Error = ovr_Message_GetError(*Message);
        FString ErrorMessage = ovr_Error_GetMessage(Error);
        UE_LOG(LogOvrPlatform, Error, TEXT("Error in HandleOnCowatchingApiReady: %s"), *ErrorMessage);
    }
    else
    {
        FString ApiReady = UTF8_TO_TCHAR(ovr_Message_GetString(*Message));
        OnCowatchingApiReady.Broadcast(ApiReady);
    }
}

void UOvrPlatformSubsystem::HandleOnCowatchingInSessionChanged(TOvrMessageHandlePtr Message, bool bIsError)
{
    if (bIsError)
    {
        ovrErrorHandle Error = ovr_Message_GetError(*Message);
        FString ErrorMessage = ovr_Error_GetMessage(Error);
        UE_LOG(LogOvrPlatform, Error, TEXT("Error in HandleOnCowatchingInSessionChanged: %s"), *ErrorMessage);
    }
    else
    {
        ovrCowatchingStateHandle Handle = ovr_Message_GetCowatchingState(*Message);
        FOvrCowatchingState InSessionChanged = FOvrCowatchingState(Handle, Message);
        OnCowatchingInSessionChanged.Broadcast(InSessionChanged);
    }
}

void UOvrPlatformSubsystem::HandleOnCowatchingInitialized(TOvrMessageHandlePtr Message, bool bIsError)
{
    if (bIsError)
    {
        ovrErrorHandle Error = ovr_Message_GetError(*Message);
        FString ErrorMessage = ovr_Error_GetMessage(Error);
        UE_LOG(LogOvrPlatform, Error, TEXT("Error in HandleOnCowatchingInitialized: %s"), *ErrorMessage);
    }
    else
    {
        FString Initialized = UTF8_TO_TCHAR(ovr_Message_GetString(*Message));
        OnCowatchingInitialized.Broadcast(Initialized);
    }
}

void UOvrPlatformSubsystem::HandleOnCowatchingPresenterDataChanged(TOvrMessageHandlePtr Message, bool bIsError)
{
    if (bIsError)
    {
        ovrErrorHandle Error = ovr_Message_GetError(*Message);
        FString ErrorMessage = ovr_Error_GetMessage(Error);
        UE_LOG(LogOvrPlatform, Error, TEXT("Error in HandleOnCowatchingPresenterDataChanged: %s"), *ErrorMessage);
    }
    else
    {
        FString PresenterDataChanged = UTF8_TO_TCHAR(ovr_Message_GetString(*Message));
        OnCowatchingPresenterDataChanged.Broadcast(PresenterDataChanged);
    }
}

void UOvrPlatformSubsystem::HandleOnCowatchingSessionStarted(TOvrMessageHandlePtr Message, bool bIsError)
{
    if (bIsError)
    {
        ovrErrorHandle Error = ovr_Message_GetError(*Message);
        FString ErrorMessage = ovr_Error_GetMessage(Error);
        UE_LOG(LogOvrPlatform, Error, TEXT("Error in HandleOnCowatchingSessionStarted: %s"), *ErrorMessage);
    }
    else
    {
        FString SessionStarted = UTF8_TO_TCHAR(ovr_Message_GetString(*Message));
        OnCowatchingSessionStarted.Broadcast(SessionStarted);
    }
}

void UOvrPlatformSubsystem::HandleOnCowatchingSessionStopped(TOvrMessageHandlePtr Message, bool bIsError)
{
    if (bIsError)
    {
        ovrErrorHandle Error = ovr_Message_GetError(*Message);
        FString ErrorMessage = ovr_Error_GetMessage(Error);
        UE_LOG(LogOvrPlatform, Error, TEXT("Error in HandleOnCowatchingSessionStopped: %s"), *ErrorMessage);
    }
    else
    {
        FString SessionStopped = UTF8_TO_TCHAR(ovr_Message_GetString(*Message));
        OnCowatchingSessionStopped.Broadcast(SessionStopped);
    }
}

void UOvrPlatformSubsystem::HandleOnCowatchingViewersDataChanged(TOvrMessageHandlePtr Message, bool bIsError)
{
    if (bIsError)
    {
        ovrErrorHandle Error = ovr_Message_GetError(*Message);
        FString ErrorMessage = ovr_Error_GetMessage(Error);
        UE_LOG(LogOvrPlatform, Error, TEXT("Error in HandleOnCowatchingViewersDataChanged: %s"), *ErrorMessage);
    }
    else
    {
        ovrCowatchViewerUpdateHandle Handle = ovr_Message_GetCowatchViewerUpdate(*Message);
        FOvrCowatchViewerUpdate ViewersDataChanged = FOvrCowatchViewerUpdate(Handle, Message);
        OnCowatchingViewersDataChanged.Broadcast(ViewersDataChanged);
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
