// Copyright (c) Meta Platforms, Inc. and its affiliates.
// Use of the material below is subject to the terms of the MIT License
// https://github.com/oculus-samples/Unreal-SharedSpaces/blob/main/Source/LICENSE

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "EOSSubsystem.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogEOS, Log, All);


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEOSOnMasterClientChanged);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEOSOnAppEntersForeground);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEOSOnLogin, bool, bWasSuccessful);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEOSOnFindRoom, bool, bWasSuccessful);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEOSOnLogEntry, FString, Log);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEOSOnRoomDestroyed, bool, bWasSuccessful);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEOSOnPlayerJoined, FString, playerNetId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEOSOnPlayerLeft, FString, playerNetId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FEOSOnCreateRoom, bool, bWasSuccessful, bool, isMasterClient);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FEOSOnJoinRoom, bool, bWasSuccessful, FString, hostAddress);

/**
 * 
 */
UCLASS()
class SHAREDSPACES_API UEOSSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable, Category = "EOS|General")
	FEOSOnLogin OnLogin;

	UPROPERTY(BlueprintAssignable, Category = "EOS|Room")
	FEOSOnCreateRoom OnRoomCreated;

	UPROPERTY(BlueprintAssignable, Category = "EOS|Room")
	FEOSOnFindRoom OnRoomFound;

	UPROPERTY(BlueprintAssignable, Category = "EOS|Room")
	FEOSOnJoinRoom OnRoomJoined;

	UPROPERTY(BlueprintAssignable, Category = "EOS|Log")
	FEOSOnLogEntry OnLogEntry;

	UPROPERTY(BlueprintAssignable, Category = "EOS|Room")
	FEOSOnMasterClientChanged OnMasterClientChanged;

	UPROPERTY(BlueprintAssignable, Category = "EOS|Room")
	FEOSOnRoomDestroyed OnRoomDestroyed;

	UPROPERTY(BlueprintAssignable, Category = "EOS|General")
	FEOSOnPlayerJoined OnPlayerJoined;

	UPROPERTY(BlueprintAssignable, Category = "EOS|General")
	FEOSOnPlayerLeft OnPlayerLeft;

	UPROPERTY(BlueprintAssignable, Category = "EOS|General")
	FEOSOnAppEntersForeground OnAppEntersForeground;

protected:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "EOS|General")
	void Login();

	UFUNCTION(BlueprintCallable, Category = "EOS|Session")
	void CreateSession(const FName& SessionName);

	//If session is found the session name is saved.
	UFUNCTION(BlueprintCallable, Category = "EOS|Session")
	void FindSession(const FName& SessionName);

	UFUNCTION(BlueprintCallable, Category = "EOS|Session")
	void JoinSession();

	//If the user is the only one in the session, the session is destroyed. If they user is not the only one if the session, the user leaves.
	UFUNCTION(BlueprintCallable, Category = "EOS|Session")
	void DestroySession();

	UFUNCTION(BlueprintCallable, Category = "EOS|General")
	FString GetNetID();

	UFUNCTION(BlueprintCallable, Category = "EOS|General")
	FString GetHostAddress();

	void NotifyGameInstanceThatEOSInitialized(bool bEOSInit) const;

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "EOS|General")
	void OnHostSuccess(UObject* WorldContextObject, FString LevelName);

	UFUNCTION(BlueprintCallable, Category = "EOS|General")
	bool RegisterPlayer(const FUniqueNetIdRepl& PlayerId, bool bWasInvited);

private:

	IOnlineSubsystem* OnlineSubsystem;
	IOnlineIdentityPtr IdentityPtr;
	IOnlineSessionPtr SessionPtr;
	TSharedPtr<class FOnlineSessionSearch> SessionSearch;
	FOnlineSessionSearchResult SearchResult;
	FName CurrentSessionName;
	
	bool bIsMasterClient;
	bool bEnterForegroundFirstTime;
	int32 BackgroundCounter;

private:

	void OnLoginComplete(int32 NumPlayers, bool bWasSuccessful, const FUniqueNetId& UserId, const FString& Error);
	void OnCreateSessionComplete(FName NewSessionName, bool bWasSuccessful);
	void OnFindSessionsComplete(bool bWasSuccessful);
	void OnJoinSessionComplete(FName JoinedSessionName, EOnJoinSessionCompleteResult::Type Result);
	void OnDestroySessionComplete(FName SessionName, bool bWasSuccessful);
	void OnPlayerJoinedSession(FName SessionName, const FUniqueNetId& PlayerJoinedId);
	void OnPlayerLeftSession(FName SessionName, const FUniqueNetId& PlayerLeftId, EOnSessionParticipantLeftReason Reason);
	void OnPlayerJoinOrLeftSession(FName SessionName, const FUniqueNetId& UserId, bool bJoined);
	void LogEntry(const FString& LogEntry, bool bBroadcast = true);
	void LogWarning(const FString& LogEntry, bool bBroadcast = true);
	void LogError(const FString& LogEntry, bool bBroadcast = true);
	void HandleApplicationEnterBackground();
	void HandleApplicationEnterForeground();
};
