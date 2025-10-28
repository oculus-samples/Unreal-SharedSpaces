// Copyright (c) Meta Platforms, Inc. and its affiliates.
// Use of the material below is subject to the terms of the MIT License
// https://github.com/oculus-samples/Unreal-SharedSpaces/blob/main/Source/LICENSE

#include "EOSSubsystem.h"

#include "Interfaces/OnlineIdentityInterface.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/EngineVersionComparison.h"
#include "Misc/OutputDeviceNull.h"
#include "Online/OnlineSessionNames.h"

DEFINE_LOG_CATEGORY(LogEOS);

void UEOSSubsystem::Login()
{
	if (IdentityPtr)
	{
		FOnlineAccountCredentials OnlineCreds;
		OnlineCreds.Type = "deviceID";
		OnlineCreds.Id = "";
		OnlineCreds.Token = "";


		LogEntry(FString::Printf(TEXT("Attempting to login")));
		bool bLoginTaskStarted = IdentityPtr->Login(0, OnlineCreds);
		LogEntry(FString::Printf(TEXT("Login Task Started: %s"), bLoginTaskStarted? TEXT("true") : TEXT("false")));
	}
}

void UEOSSubsystem::CreateSession(const FName& SessionName)
{
	if (SessionPtr)
	{
		FOnlineSessionSettings SessionSettings{};
		SessionSettings.bUsesPresence = true;
		SessionSettings.bAllowInvites = false;
		SessionSettings.bAllowJoinInProgress = false;
		SessionSettings.bAllowJoinViaPresence = false;
		SessionSettings.bAllowJoinViaPresenceFriendsOnly = false;
		SessionSettings.bIsDedicated = false;
		SessionSettings.bIsLANMatch = false;
		SessionSettings.bShouldAdvertise = true;
		SessionSettings.bUseLobbiesIfAvailable = true;
		SessionSettings.bUseLobbiesVoiceChatIfAvailable = false;
		SessionSettings.NumPublicConnections = 8;
		SessionSettings.SessionIdOverride = SessionName.ToString();
		SessionSettings.Set(SEARCH_LOBBIES, EOnlineDataAdvertisementType::ViaOnlineServiceAndPing);
		SessionSettings.Set("LobbyName", SessionName.ToString(), EOnlineDataAdvertisementType::ViaOnlineServiceAndPing);

		LogEntry(FString::Printf(TEXT("Trying to create session with name = %s"), *SessionName.ToString()));
		SessionPtr->CreateSession(0, SessionName, SessionSettings);
	}
}

void UEOSSubsystem::FindSession(const FName& SessionName)
{
	if (SessionPtr)
	{
		SessionSearch = MakeShareable(new FOnlineSessionSearch);
		SessionSearch->bIsLanQuery = false;
		SessionSearch->MaxSearchResults = 1;
		SessionSearch->QuerySettings.Set(SEARCH_LOBBIES, true, EOnlineComparisonOp::Equals);
		SessionSearch->QuerySettings.Set("LobbyName", SessionName.ToString(), EOnlineComparisonOp::Equals);
		SessionPtr->FindSessions(0, SessionSearch.ToSharedRef());
	}
}

void UEOSSubsystem::JoinSession()
{
	if (SessionPtr)
	{
		SessionPtr->JoinSession(0, CurrentSessionName, SearchResult);
	}
}

void UEOSSubsystem::DestroySession()
{
	if (SessionPtr)
	{
		LogEntry(FString::Printf(TEXT("Attempting to Destroy Session %s "), *CurrentSessionName.ToString()));

		if (bIsMasterClient)
		{
			OnMasterClientChanged.Broadcast();
		}

		SessionPtr->DestroySession(CurrentSessionName);
	}
}

FString UEOSSubsystem::GetNetID()
{
	if (IdentityPtr)
	{
		auto Result = IdentityPtr->GetUniquePlayerId(0).Get()->ToString();
		Result.RemoveAt(0);
		return Result;
	}

	return FString();
}

FString UEOSSubsystem::GetHostAddress()
{
	FString TravelURL;
	if (SessionPtr)
	{
		SessionPtr->GetResolvedConnectString(CurrentSessionName, TravelURL);
	}

	return TravelURL;
}

void UEOSSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	bool bSuccess = true;

	OnlineSubsystem = IOnlineSubsystem::Get();
	if (!OnlineSubsystem)
		bSuccess = false;

	IdentityPtr = OnlineSubsystem->GetIdentityInterface();
	if (!IdentityPtr.IsValid())
		bSuccess = false;

	IdentityPtr->OnLoginCompleteDelegates->AddUObject(this, &UEOSSubsystem::OnLoginComplete);

	SessionPtr = OnlineSubsystem->GetSessionInterface();
	if (!SessionPtr.IsValid())
		bSuccess = false;

	SessionPtr->OnCreateSessionCompleteDelegates.AddUObject(this, &UEOSSubsystem::OnCreateSessionComplete);
	SessionPtr->OnFindSessionsCompleteDelegates.AddUObject(this, &UEOSSubsystem::OnFindSessionsComplete);
	SessionPtr->OnJoinSessionCompleteDelegates.AddUObject(this, &UEOSSubsystem::OnJoinSessionComplete);
	SessionPtr->OnDestroySessionCompleteDelegates.AddUObject(this, &UEOSSubsystem::OnDestroySessionComplete);
	SessionPtr->OnSessionParticipantJoinedDelegates.AddUObject(this, &UEOSSubsystem::OnPlayerJoinedSession);
	SessionPtr->OnSessionParticipantLeftDelegates.AddUObject(this, &UEOSSubsystem::OnPlayerLeftSession);
		
#if UE_VERSION_OLDER_THAN(5, 5, 0)
	SessionPtr->OnSessionParticipantsChangeDelegates.AddUObject(this, &UEOSSubsystem::OnPlayerJoinOrLeftSession);
#endif

	FCoreDelegates::ApplicationWillEnterBackgroundDelegate.AddUObject(this, &UEOSSubsystem::HandleApplicationEnterBackground);
	FCoreDelegates::ApplicationHasEnteredForegroundDelegate.AddUObject(this, &UEOSSubsystem::HandleApplicationEnterForeground);

	bIsMasterClient = false;
	bEnterForegroundFirstTime = true;
	BackgroundCounter = 0;

	NotifyGameInstanceThatEOSInitialized(bSuccess);
}

void UEOSSubsystem::NotifyGameInstanceThatEOSInitialized(bool bEOSInit) const
{
	//The subsystem notifies the game instance when it is ready.
	FOutputDeviceNull OutputDeviceNull;
	GetGameInstance()->CallFunctionByNameWithArguments(
		*FString::Printf(TEXT("EOSInitialized %s"), bEOSInit ? TEXT("true") : TEXT("false")),
		OutputDeviceNull,
		nullptr,
		true);
}

void UEOSSubsystem::OnHostSuccess(UObject* WorldContextObject, FString LevelName)
{
	auto CurrentWorld = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	auto NewURL = FURL(*LevelName);
	CurrentWorld->Listen(NewURL);

	LogEntry(FString("Started to listen to connections"));
}

bool UEOSSubsystem::RegisterPlayer(const FUniqueNetIdRepl& PlayerId, bool bWasInvited)
{
	if (SessionPtr)
	{
		return SessionPtr->RegisterPlayer(CurrentSessionName, *PlayerId.GetUniqueNetId(), bWasInvited);
	}
	return false;
}

void UEOSSubsystem::OnLoginComplete(int32 NumPlayers, bool bWasSuccessful, const FUniqueNetId& UserId, const FString& Error)
{
	if (bWasSuccessful)
	{
		LogEntry(FString::Printf(TEXT("Login Successful. UserID = %s"), *UserId.ToString()));
	}
	else
	{
		LogError(FString::Printf(TEXT("Login Failed. Reason = %s"), *Error));
	}

	OnLogin.Broadcast(bWasSuccessful);
};

void UEOSSubsystem::OnCreateSessionComplete(FName NewSessionName, bool bWasSuccessful)
{
	if (bWasSuccessful)
	{
		LogEntry(FString::Printf(TEXT("Session created. Session Name = %s"), *NewSessionName.ToString()));
		bIsMasterClient = true;
		CurrentSessionName = NewSessionName;
		BackgroundCounter = 0;
	}
	else
	{
		LogError(FString::Printf(TEXT("Session creation failed.")));
	}

	OnRoomCreated.Broadcast(bWasSuccessful, bIsMasterClient);
};

void UEOSSubsystem::OnFindSessionsComplete(bool bWasSuccessful)
{
	++BackgroundCounter;
	if (bWasSuccessful && SessionSearch.IsValid() && SessionSearch->SearchResults.Num() > 0)
	{
		int32 Index = 0;
		for (FOnlineSessionSearchResult Lobby : SessionSearch->SearchResults)
		{
			LogEntry(FString::Printf(TEXT("Found session with id: %s"), *Lobby.GetSessionIdStr()));

			auto CompareInt = CurrentSessionName.Compare(FName(*Lobby.GetSessionIdStr()));
			if (CompareInt != 0)
			{
				SearchResult = SessionSearch->SearchResults[Index];
				CurrentSessionName = FName(*SearchResult.GetSessionIdStr());
			}

			++Index;
		}

		OnRoomFound.Broadcast(true);
	}
	else
	{
		LogError(FString::Printf(TEXT("Couldn't find any sessions")));
		OnRoomFound.Broadcast(false);
	}
}

void UEOSSubsystem::OnJoinSessionComplete(FName JoinedSessionName, EOnJoinSessionCompleteResult::Type Result)
{
	bool bSuccess = false;
	FString TravelURL;
	if (Result == EOnJoinSessionCompleteResult::Success)
	{
		SessionPtr->GetResolvedConnectString(JoinedSessionName, TravelURL);

		LogEntry(FString::Printf(TEXT("Session Joined = %s"), *JoinedSessionName.ToString()));
		LogEntry(FString::Printf(TEXT("TURL = %s"), *TravelURL));
		CurrentSessionName = JoinedSessionName;
		bSuccess = true;
		bIsMasterClient = false;
		BackgroundCounter = 0;
	}
	else if(Result == EOnJoinSessionCompleteResult::SessionIsFull)
	{
		LogError(FString::Printf(TEXT("Unable to join session. Reason: Session is full.")));
	}
	else if (Result == EOnJoinSessionCompleteResult::SessionDoesNotExist)
	{
		LogError(FString::Printf(TEXT("Unable to join session. Reason: Session doesn't exist.")));
	}
	else if (Result == EOnJoinSessionCompleteResult::CouldNotRetrieveAddress)
	{
		LogError(FString::Printf(TEXT("Unable to join session. Reason: Could not retrieve host address.")));
	}
	else if (Result == EOnJoinSessionCompleteResult::AlreadyInSession)
	{
		LogError(FString::Printf(TEXT("Unable to join session. Reason: User is already in the session.")));
	}
	else if (Result == EOnJoinSessionCompleteResult::UnknownError)
	{
		LogError(FString::Printf(TEXT("Unable to join session. Reason: Unknown error.")));
	}

	OnRoomJoined.Broadcast(bSuccess, TravelURL);
}

void UEOSSubsystem::OnDestroySessionComplete(FName SessionName, bool bWasSuccessful)
{
	if (bWasSuccessful)
	{
		if (bIsMasterClient)
			bIsMasterClient = false;

		LogEntry(FString::Printf(TEXT("Destroyed Session %s"), *SessionName.ToString()));
	}
	else
	{
		LogError(FString::Printf(TEXT("Failed to destroy session %s"), *SessionName.ToString()));
	}

	OnRoomDestroyed.Broadcast(bWasSuccessful);
}

void UEOSSubsystem::OnPlayerJoinedSession(FName SessionName, const FUniqueNetId& PlayerJoinedID)
{
	LogEntry(FString::Printf(TEXT("Player %s joined the session %s"), *PlayerJoinedID.ToString(), *SessionName.ToString()));
	FString TravelURL;

	if (auto NamedSession = SessionPtr->GetNamedSession(SessionName))
	{
		if (NamedSession->bHosting && !bIsMasterClient)
		{
			bIsMasterClient = true;
		}

	}
	else
	{
		LogError(FString::Printf(TEXT("Failed to get named session. Can't check if the master client changed.")));
	}

	auto NetID = PlayerJoinedID.ToString();
	NetID.RemoveAt(0);
	OnPlayerJoined.Broadcast(NetID);
}

void UEOSSubsystem::OnPlayerLeftSession(FName SessionName, const FUniqueNetId& PlayerLeftID, EOnSessionParticipantLeftReason Reason)
{
	LogEntry(FString::Printf(TEXT("Player %s left the session %s"), *PlayerLeftID.ToString(), *SessionName.ToString()));
	auto NetID = PlayerLeftID.ToString();
	NetID.RemoveAt(0);
	OnPlayerLeft.Broadcast(NetID);
}

void UEOSSubsystem::OnPlayerJoinOrLeftSession(FName SessionName, const FUniqueNetId& UserId, bool bJoined)
{
	if (bJoined)
	{
		LogEntry(FString::Printf(TEXT("Player %s joined the session %s"), *UserId.ToString(), *SessionName.ToString()));
	}
	else
	{
		LogEntry(FString::Printf(TEXT("Player %s left the session %s"), *UserId.ToString(), *SessionName.ToString()));
	}
}

void UEOSSubsystem::LogEntry(const FString& LogEntry, bool bBroadcast)
{
	if (bBroadcast)
	{
		OnLogEntry.Broadcast(LogEntry);
	}

	UE_LOG(LogEOS, Display, TEXT("%s"), *LogEntry);
	
}

void UEOSSubsystem::LogWarning(const FString& LogEntry, bool bBroadcast)
{
	if (bBroadcast)
	{
		OnLogEntry.Broadcast(LogEntry);
	}

	UE_LOG(LogEOS, Warning, TEXT("%s"), *LogEntry);
}

void UEOSSubsystem::LogError(const FString& LogEntry, bool bBroadcast)
{
	if (bBroadcast)
	{
		OnLogEntry.Broadcast(LogEntry);
	}

	UE_LOG(LogEOS, Error, TEXT("%s"), *LogEntry);

}

void UEOSSubsystem::HandleApplicationEnterBackground()
{
	if (BackgroundCounter == 0)
	{
		++BackgroundCounter;
		LogEntry(TEXT("Application Entering Background/Quitting"));
		DestroySession();
		UGameplayStatics::OpenLevel(GetWorld(), "TransitionMap");
	}
}

void UEOSSubsystem::HandleApplicationEnterForeground()
{
	if (BackgroundCounter <= 1 && !bEnterForegroundFirstTime)
	{
		LogEntry(TEXT("Application Entering Foreground"));
		OnAppEntersForeground.Broadcast();
	}
	else
	{
		bEnterForegroundFirstTime = false;
	}
}
