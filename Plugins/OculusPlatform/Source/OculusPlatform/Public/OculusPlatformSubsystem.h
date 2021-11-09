// Copyright (c) Facebook, Inc. and its affiliates.

#pragma once

#include "CoreMinimal.h"
#include "Tickable.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "OVRPlatformSDK.h"
#include "OculusPlatformTypes.h"
#include "OculusPlatformSubsystem.generated.h"

#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#endif


// Message pump delegates.
DECLARE_DELEGATE_TwoParams(FOculusPlatformMessageOnComplete, ovrMessageHandle, bool);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOculusPlatformMulticastMessageOnComplete, ovrMessageHandle, bool);

// Launch intent.
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOculusPlatformOnLaunchIntentChanged, const FString&, LaunchIntent, const FOculusPlatformLaunchDetails&, LaunchDetails);

// In-game logging.
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOculusPlatformLogUpdated, const TArray<FString>&, Log);

// Identity delegates.
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOculusPlatformOnLoginComplete, bool, Successful, FOculusId, AuthenticatedId, FString, AuthenticatedAccount);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOculusPlatformOnLogoutComplete, bool, Successful);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOculusPlatformOnEntitlementChecked, bool, Successful);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOculusPlatformGetListOfFriendsComplete, bool, Successful, const TArray<FOculusId>&, Friends);

// Room  delegates.
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOculusPlatformOnRoomCreationComplete, bool, Successful, FOculusId, RoomId);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOculusPlatformOnRoomJoinComplete, bool, Successful);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOculusPlatformOnRoomLeaveComplete, bool, Successful);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOculusPlatformOnRequestRoomInfoComplete, bool, Successful, FOculusId, RoomId);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOculusPlatformOnRoomDatastoreUpdateComplete, bool, Successful);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOculusPlatformOnRoomDescriptionUpdateComplete, bool, Successful);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOculusPlatformOnRoomChanged, FOculusId, RoomId, bool, bOwnerHasChanged);

// Matchmaking  delegates.
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOculusPlatformOnBrowseRoomComplete, bool, Successful, const TArray<FOculusId>&, RoomIds);

// Rich presence.
DECLARE_DYNAMIC_DELEGATE_OneParam(FOculusPlatformOnRichPresenceCleared, bool, Successful);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOculusPlatformOnRichPresenceGetDestinationsComplete, bool, Successful, const TArray<FOculusPlatformDestination>&, Destinations);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOculusPlatformOnRichPresenceGetDestinationByNameComplete, bool, Successful, const FOculusPlatformDestination&, Destination);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOculusPlatformOnRichPresenceSet, bool, Successful);

// Group presence.
DECLARE_DYNAMIC_DELEGATE_OneParam(FOculusPlatformOnGroupPresenceSet, bool, Successful);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOculusPlatformOnGroupPresenceCleared, bool, Successful);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOculusPlatformOnGroupPresenceInvitePanelComplete, bool, Successful, bool, InvitesHaveBeenSent);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOculusPlatformOnGroupPresenceRosterPanelComplete, bool, Successful);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOculusPlatformOnGroupJoinIntentReceived,
	const FString&, DestinationApiName, const FString&, DeeplinkMessage, const FString&, LobbyId, const FString&, MatchId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOculusPlatformOnGroupLeaveIntentReceived,
	const FString&, DestinationApiName, const FString&, LobbyId, const FString&, MatchId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOculusPlatformOnGroupInvitationsSent, const TArray<FOculusId>&, InvitedUsers);

// Livestreaming
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(
	FOculusPlatformOnLivestreamingChanged,
	bool, bCommentsVisible,
	bool, bIsPaused,
	bool, bLivestreamingEnabled,
	int32, LivestreamingType,
	bool, bMicEnabled);

// Subsystem
UCLASS(Blueprintable)
class OCULUSPLATFORM_API UOculusPlatformSubsystem
	: public UGameInstanceSubsystem
	, public FTickableGameObject
{
	GENERATED_BODY()

public:

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

private:

// -----------------------------------------------------------------------------
// Application Life-Cycle

public:
	
	/**
	 * Delegate called on reception of ovrMessage_Notification_ApplicationLifecycle_LaunchIntentChanged.
	 */
	UPROPERTY(BlueprintAssignable, Category = "OculusPlatform|ApplicationLifeCycle")
	FOculusPlatformOnLaunchIntentChanged OnLaunchIntentChanged;

	/**
	 * Call to retrieve the current launch details.
	 * @return FOculusPlatformLaunchDetails including presence and deeplink information.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusPlatform|ApplicationLifeCycle")
	const FOculusPlatformLaunchDetails& GetLaunchDetails();

private:

	// Launch type converters
	ELaunchType ConvertLaunchType(ovrLaunchType JoinPolicy) const;
	ovrLaunchType ConvertLaunchType(ELaunchType JoinPolicy) const;

	// Updated each time we receive a new launch intent.
	FOculusPlatformLaunchDetails LaunchDetails;

	// Debugging.
	void LogLaunchDetails();

	// OVR Notifications (delegate, handle and handler)
	FDelegateHandle OnLaunchIntentChangedHandle;
	void HandleOnLaunchIntentChanged(ovrMessageHandle Message, bool bIsError);

	// Notification to the game instance that we are ready.
	void NotifyGameInstanceSubsystemStarted(bool bOculusPlatformIsInitialized) const;

// -----------------------------------------------------------------------------
// Oculus Room

public:

	/**
	 * Delegate called on reception of ovrMessage_Notification_Room_RoomUpdate.
	 */
	UPROPERTY(BlueprintAssignable, Category = "OculusPlatform|Room")
	FOculusPlatformOnRoomChanged OnRoomChanged;

	/**
	 * Call to retrieve the FOculusPlatformRoomInfo of the last joined Oculus room.
	 * @param RoomInfo - FOculusPlatformRoomInfo structure to be populated.
	 * @return A boolean that indicates if we have the requested room info.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusPlatform|Room")
	UPARAM(DisplayName = "RoomFound") bool GetLastJoinedRoom(FOculusPlatformRoomInfo& RoomInfo);

	/**
	 * Same as GetLastJoinedRoom with an additional test for ownership.
	 * @param RoomInfo - FOculusPlatformRoomInfo structure to be populated.
	 * @return A boolean that indicates if we have the requested room info and that we own it.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusPlatform|Room")
	UPARAM(DisplayName = "HasOwnedRoom") bool GetOwnedRoom(FOculusPlatformRoomInfo& RoomInfo);

	/**
	 * Returns room information from our local cache.
	 * @param RoomId - Id of the room.
	 * @param RoomInfo - FOculusPlatformRoomInfo structure to be populated.
	 * @return A boolean that indicates if we have the requested room info.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusPlatform|Room")
	UPARAM(DisplayName = "RoomFound") bool GetRoomInfo(FOculusId RoomId, FOculusPlatformRoomInfo& RoomInfo);

	/**
	 * Returns the network address linked to an Oculus room id, which is based on the id of the room owner.
	 * @param RoomId - Id of the room.
	 * @param RoomInfo - FOculusPlatformRoomInfo structure to be populated.
	 * @return A boolean that indicates if we have the requested room info.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusPlatform|Room")
	UPARAM(DisplayName = "RoomFound") bool GetRoomHostAddress(FOculusId RoomId, FString& HostAddress);

public: // server requests
	
	/**
	 * Creates and automatically joins a new Oculus room.
	 * @param PoolName - The name of pool where the room will be created.
	 * @param JoinPolicy - Who can join the room.
	 * @param MaxUsers - The maximum number of users.
	 * @param Callback - Called asynchronously with the result of the call.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusPlatform|Room")
	void CreateAndJoinRoom(FString PoolName, ERoomJoinPolicy JoinPolicy, int32 MaxUsers, const FOculusPlatformOnRoomCreationComplete& Callback);

	/**
	 * Joins an existing room.
	 * @param RoomId - Id of the room to join.
	 * @param Callback - Called asynchronously with the result of the call.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusPlatform|Room")
	void JoinRoom(FOculusId RoomId, const FOculusPlatformOnRoomJoinComplete& Callback);

	/**
	 * Retrieves the currently joined room.
	 * @param Callback - Called asynchronously with the result of the call.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusPlatform|Room")
	void RequestCurrentRoom(const FOculusPlatformOnRequestRoomInfoComplete& Callback);

	/**
	 * Request to leave the room.
	 * @param RoomId - Room to leave.
	 * @param OptionalMap - Optional.  When provided, causes a client travel to the specified level. 
	 * @param Callback - Called asynchronously with the result of the call.
	 */	
	UFUNCTION(BlueprintCallable, Category = "OculusPlatform|Room")
	void LeaveRoom(FOculusId RoomId, const FString& OptionalMap, const FOculusPlatformOnRoomLeaveComplete& Callback);

	/**
	 * Retrieves information about a specific room.
	 * @param RoomId - Id of the room to query.
	 * @param Callback - Called asynchronously with the result of the call.
	 */	
	UFUNCTION(BlueprintCallable, Category = "OculusPlatform|Room")
	void RequestRoomInfo(FOculusId RoomId, const FOculusPlatformOnRequestRoomInfoComplete& Callback);

	/**
	 * Updates a key/value pair in the datastore of a room.
	 * @param RoomId - Id of the room to query.
	 * @param Key - String.
	 * @param Value - String.
	 * @param Callback - Called asynchronously with the result of the call.
	 */	
	UFUNCTION(BlueprintCallable, Category = "OculusPlatform|Room", Meta = (AutoCreateRefTerm = "Callback"))
	void UpdateRoomDatastoreString(FOculusId RoomId, const FString& Key, const FString& Value, const FOculusPlatformOnRoomDatastoreUpdateComplete& Callback);

	/**
	 * Updates the description of the specified room.
	 * @param RoomId - Id of the room to query.
	 * @param Description - String.
	 * @param Callback - Called asynchronously with the result of the call.
	 */	
	UFUNCTION(BlueprintCallable, Category = "OculusPlatform|Room", Meta = (AutoCreateRefTerm = "Callback"))
	void UpdateRoomDescription(FOculusId RoomId, const FString& Description, const FOculusPlatformOnRoomDescriptionUpdateComplete& Callback);

private:

	// Keeping track of last joined room.
	FOculusId LastJoinedRoom;

	// Room join policy converters
	ERoomJoinPolicy ConvertJoinPolicy(ovrRoomJoinPolicy JoinPolicy) const;
	ovrRoomJoinPolicy ConvertJoinPolicy(ERoomJoinPolicy JoinPolicy) const;

	// Map of ovrID to room information.
	TMap<FOculusId, FOculusPlatformRoomInfo> RoomInfos;

	// Update RoomInfos with data associated with the RoomHandle.
	const FOculusPlatformRoomInfo& CreateOrUpdateRoomInfo(ovrRoomHandle RoomHandle);
	
	// OVR Notifications (delegate, handle and handler)
	FDelegateHandle OnRoomChangedHandle;
	void HandleOnRoomChanged(ovrMessageHandle Message, bool bIsError);

// -----------------------------------------------------------------------------
// Oculus Matchmaking (only to query available Oculus rooms)

public:

	/**
	 * Browse all rooms created in the specified pool.
	 * @param bLog - Will log by default.
	 * @param Callback - Called asynchronously with the result of the call.
	 */	
	UFUNCTION(BlueprintCallable, Category = "OculusPlatform|Room", Meta = (bLog="true"))
	void BrowseRooms(const FString& PoolName, bool bLog, const FOculusPlatformOnBrowseRoomComplete& Callback);

	/**
	 * Helper function to filter rooms by description.
	 * @param RoomIds - Array of room ids.
	 * @param Description - Description to match.
	 * @param bFilterOutCurrentRoom - Whether to ignore the currently joined room.
	 * @param bLog - Will log by default.
	 * @param FilteredRoomIds - Trimmed down list of room ids that match the description provided.
	 */	
	UFUNCTION(BlueprintCallable, Category = "OculusPlatform|Room", Meta = (bFilterOutCurrentRoom="true", bLog="true"))
	void FilterRoomsByDescription(const TArray<FOculusId>& RoomIds, const FString& Description, bool bFilterOutCurrentRoom, bool bLog, TArray<FOculusId>& FilteredRoomIds);

// -----------------------------------------------------------------------------
// Identity

public:

	/** Id of the user authenticated during login. */
	UPROPERTY(BlueprintReadonly, Category = "OculusPlatform|Identity")
	FOculusId AuthenticatedAccountId;

	/** Account name of the user authenticated during login. */
	UPROPERTY(BlueprintReadonly, Category = "OculusPlatform|Identity")
	FString AuthenticatedAccountName;

	/**
	 * Retrieves the entitlement status of the currently logged in user.
	 * @param Callback - Called asynchronously with the result of the call.
	 */	
	UFUNCTION(BlueprintCallable, Category = "OculusPlatform|Identity")
	void GetEntitlementStatus(const FOculusPlatformOnEntitlementChecked& Callback);

	/**
	 * Retrieves the user's list of friends.
	 * @param Callback - Called asynchronously with the result of the call.
	 */	
	UFUNCTION(BlueprintCallable, Category = "OculusPlatform|Identity")
	void GetListOfFriends(const FOculusPlatformGetListOfFriendsComplete& Callback);

	/**
	 * Retrieves the info of the specified user.
	 * @param UserId - Id of the user queried.
	 * @param UserInfo - Info of the specified user.
	 */	
	UFUNCTION(BlueprintCallable, Category = "OculusPlatform|Identity")
	void GetUserInfo(FOculusId UserId, bool& UserExists, FOculusPlatformUserInfo& UserInfo);

	/**
	 * Retrieves the info of the current authenticated user.
	 * @param UserInfo - Info of the authenticated user.
	 */	
	UFUNCTION(BlueprintCallable, Category = "OculusPlatform|Identity")
	UPARAM(DisplayName = "Authenticated") bool GetMyUserInfo(FOculusPlatformUserInfo& UserInfo);

	/**
	 * Delegate called at the end of the login process.
	 */
	UPROPERTY(BlueprintAssignable, Category = "OculusPlatform|Identity")
	FOculusPlatformOnLoginComplete OnLoginComplete;

private:

	// Ensure login.
	void Login();

	// Map of player index to ovrID. Populated via various calls.
	TMap<int32, FOculusId> UserIds;

	// List of friends, updated when calling GetListOfFriends().
	TArray<FOculusId> ListOfFriends;

	// Map of ovrID to player account information.
	TMap<FOculusId, FOculusPlatformUserInfo> UserInfos;

	// Function to convert ovrUserPresenceStatus to blueprint enum.
	EUserPresenceStatus ConvertPresenceStatus(ovrUserPresenceStatus Status) const;
	ovrUserPresenceStatus ConvertPresenceStatus(EUserPresenceStatus Status) const;

	// Ensures that we have an updated record for that user in UserInfos.
	const FOculusPlatformUserInfo& CreateOrUpdateUserInfo(ovrUserHandle UserHandle);

// -----------------------------------------------------------------------------
// Rich Presence

public:

	/**
	 * Clears the rich presence information.
	 * @param Callback - Called asynchronously with the result of the call.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusPlatform|RichPresence", Meta = (AutoCreateRefTerm = "Callback", DeprecatedFunction, DeprecationMessage="use group presence instead"))
	void RichPresenceClear(const FOculusPlatformOnRichPresenceCleared& Callback);

	/**
	 * Request for all existing destinations linked to this application.
	 * @param Callback - Called asynchronously with the result of the call.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusPlatform|RichPresence", Meta = (AutoCreateRefTerm = "Callback"))
	void RichPresenceGetDestinations(const FOculusPlatformOnRichPresenceGetDestinationsComplete& Callback);

	/**
	 * Request for a specific destination linked to this application.
	 * @param DestinationApiName - Destination name.
	 * @param Callback - Called asynchronously with the result of the call.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusPlatform|RichPresence", Meta = (AutoCreateRefTerm = "Callback"))
	void RichPresenceGetDestinationByName(const FString& DestinationApiName, const FOculusPlatformOnRichPresenceGetDestinationByNameComplete& Callback);

	/**
	 * Set the user's rich presence.
	 * @param DestinationApiName - Destination name.
	 * @param DeeplinkMessageOverride - Leave empty unless you want to override the deeplink specified with this destination.
	 * @param LobbyId - String.
	 * @param MatchId - String.
	 * @param bIsJoinable - Whether the user can be joined by others.
	 * @param bIsIdle - Whether the user is currently idle.
	 * @param CurrentCapacity - How many users can join the current destination.
	 * @param MaxCapacity - The total number of users allowed at this destination.
	 * @param Callback - Called asynchronously with the result of the call.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusPlatform|RichPresence", Meta = (bIsJoinable="true", AutoCreateRefTerm = "Callback", DeprecatedFunction, DeprecationMessage="use group presence instead"))
	void RichPresenceSet(
		FString DestinationApiName,
		FString DeeplinkMessageOverride,
		FString LobbyId,
		FString MatchId,
		bool bIsJoinable,
		bool bIsIdle,
		int32 CurrentCapacity,
		int32 MaxCapacity,
		const FOculusPlatformOnRichPresenceSet& Callback);

private:

	// List of destinations.
	TArray<FOculusPlatformDestination> Destinations;

// -----------------------------------------------------------------------------
// Group Presence

public:
	
	/**
	 * Delegate called on ovrMessage_Notification_GroupPresence_JoinIntentReceived.
	 * This is the normal path for processing a launch intent with destination, lobby, match and deeplink information.
	 */
	UPROPERTY(BlueprintAssignable, Category = "OculusPlatform|GroupPresence")
	FOculusPlatformOnGroupJoinIntentReceived OnGroupJoinIntentReceived;

	/**
	 * Delegate called on ovrMessage_Notification_GroupPresence_LeaveIntentReceived.
	 */
	UPROPERTY(BlueprintAssignable, Category = "OculusPlatform|GroupPresence")
	FOculusPlatformOnGroupLeaveIntentReceived OnGroupLeaveIntentReceived;

	/**
	 * Delegate called on ovrMessage_Notification_GroupPresence_InvitationsSent.
	 */
	UPROPERTY(BlueprintAssignable, Category = "OculusPlatform|GroupPresence")
	FOculusPlatformOnGroupInvitationsSent OnGroupInvitationsSent;

	/**
	 * Clears the group presence information.
	 * @param Callback - Called asynchronously with the result of the call.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusPlatform|GroupPresence", Meta = (AutoCreateRefTerm = "Callback"))
	void GroupPresenceClear(const FOculusPlatformOnGroupPresenceCleared& Callback);

	/**
	 * Set the user's group presence.
	 * @param DestinationApiName - Destination name.
	 * @param LobbyId - String.
	 * @param MatchId - String.
	 * @param bIsJoinable - Whether the user can be joined by others.
	 * @param Callback - Called asynchronously with the result of the call.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusPlatform|GroupPresence", Meta = (AutoCreateRefTerm = "Callback"))
	void GroupPresenceSet(
		FString DestinationApiName,
		bool bIsJoinable,
		FString LobbyId,
		FString MatchId,
		const FOculusPlatformOnGroupPresenceSet& Callback);

	/**
	 * Updates the destination of the user's group presence.
	 * @param DestinationApiName - Destination name.
	 * @param Callback - Called asynchronously with the result of the call.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusPlatform|GroupPresence", Meta = (AutoCreateRefTerm = "Callback"))
	void GroupPresenceSetDestination(
		FString DestinationApiName,
		const FOculusPlatformOnGroupPresenceSet& Callback);

	/**
	 * Updates the joinability of the user's group presence.
	 * @param bIsJoinable - Whether the user can be joined by others.
	 * @param Callback - Called asynchronously with the result of the call.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusPlatform|GroupPresence", Meta = (AutoCreateRefTerm = "Callback"))
	void GroupPresenceSetIsJoinable(
		bool bIsJoinable,
		const FOculusPlatformOnGroupPresenceSet& Callback);

	/**
	 * Updates the lobby id of the user's group presence.
	 * @param LobbyId - String.
	 * @param Callback - Called asynchronously with the result of the call.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusPlatform|GroupPresence", Meta = (AutoCreateRefTerm = "Callback"))
	void GroupPresenceSetLobbyId(
		FString LobbyId,
		const FOculusPlatformOnGroupPresenceSet& Callback);

	/**
	 * Updates the match id of the user's group presence.
	 * @param MatchId - String.
	 * @param Callback - Called asynchronously with the result of the call.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusPlatform|GroupPresence", Meta = (AutoCreateRefTerm = "Callback"))
	void GroupPresenceSetMatchId(
		FString MatchId,
		const FOculusPlatformOnGroupPresenceSet& Callback);

	/**
	 * Launch the system invite panel from which you can send invites with your group presence to other users.
	 * @param SuggestedUsers - Optionally you can supplement your request with additional user ids.
	 * @param Callback - Called asynchronously with the result of the call.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusPlatform|GroupPresence", Meta = (AutoCreateRefTerm = "SuggestedUsers,Callback"))
	void GroupPresenceLaunchInvitePanel(
		const TArray<FOculusId>& SuggestedUsers,
		const FOculusPlatformOnGroupPresenceInvitePanelComplete& Callback);

	/**
	 * Launch the system roster panel from which you can see who is currently in your roster.
	 * It is also possible to launch the invite panel from there.
	 * @param SuggestedUsers - Optionally you can supplement your request with additional user ids.
	 * @param Callback - Called asynchronously with the result of the call.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusPlatform|GroupPresence", Meta = (AutoCreateRefTerm = "SuggestedUsers,Callback"))
	void GroupPresenceLaunchRosterPanel(
		const TArray<FOculusId>& SuggestedUsers,
		const FOculusPlatformOnGroupPresenceRosterPanelComplete& Callback);

	/**
	 * Returns the most recently set group presence.
	 * @param DestinationApiName - Destination name.
	 * @param LobbyId - String.
	 * @param MatchId - String.
	 * @param bIsJoinable - Whether the user can be joined by others.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusPlatform|GroupPresence")
	UPARAM(DisplayName = "bIsSet") bool GroupPresenceGetCurrent(
		FString& DestinationApiName,
		bool& bIsJoinable,
		FString& LobbyId,
		FString& MatchId);

private:

	FString LastGroupPresence_DestinationApiName;
	bool    LastGroupPresence_IsJoinable;
	FString LastGroupPresence_LobbyId;
	FString LastGroupPresence_MatchId;

private:

	// OVR Notifications (delegate, handle and handler)
	FDelegateHandle OnGroupPresenceJoinIntentReceivedHandle;
	void HandleOnGroupPresenceJoinIntentReceived(ovrMessageHandle Message, bool bIsError);

	FDelegateHandle OnGroupPresenceLeaveIntentReceivedHandle;
	void HandleOnGroupPresenceLeaveIntentReceived(ovrMessageHandle Message, bool bIsError);

	FDelegateHandle OnGroupPresenceInvitationsSentHandle;
	void HandleOnGroupPresenceInvitationsSent(ovrMessageHandle Message, bool bIsError);

// -----------------------------------------------------------------------------
// Livestreaming

public:

	UPROPERTY(BlueprintAssignable, Category = "OculusPlatform|Livestreaming")
	FOculusPlatformOnLivestreamingChanged OnLivestreamingChanged;

private:

	FDelegateHandle OnLivestreamingChangedHandle;
	void HandleOnLivestreamingChanged(ovrMessageHandle Message, bool bIsError);

// -----------------------------------------------------------------------------
// Platform Initialization

private:

	bool bOculusInit;

	FString OCULUS_BUILD_VALUE;
	FString OCULUS_POOL_VALUE;

#if PLATFORM_WINDOWS
	bool InitWithWindowsPlatform();
#elif PLATFORM_ANDROID
	bool InitWithAndroidPlatform();
#endif
	FString GetAppId();

	// OVR Notifications (handle and handler)
	FDelegateHandle OnPlatformInitializedStandaloneHandle;
	void HandleOnPlatformInitialized(ovrMessageHandle Message, bool bIsError);

// -----------------------------------------------------------------------------
// Message Pump and Callbacks

public:

	// You can make direct OVR requests and register for responses.
	void AddRequestDelegate(ovrRequest RequestId, FOculusPlatformMessageOnComplete&& Delegate);

	// You can also register to be notified of any message type.
	FOculusPlatformMulticastMessageOnComplete& GetNotifDelegate(ovrMessageType MessageType);
	void RemoveNotifDelegate(ovrMessageType MessageType, const FDelegateHandle& Delegate);

private:

	// Message pump.
	virtual void Tick(float DeltaTime) override;
	virtual bool IsTickable() const override;
	virtual TStatId GetStatId() const override;
	void OnReceiveMessage(ovrMessageHandle Message);

	/** Map of a specific request id to a specific delegate. */
	TMap<uint64, FOculusPlatformMessageOnComplete> RequestDelegates;

	/** Map of message type to multicast delegate. */
	TMap<ovrMessageType, FOculusPlatformMulticastMessageOnComplete> NotifDelegates;

// -----------------------------------------------------------------------------
// Logging
//
// Resilient to travel so that we can show log messages across levels.

public:

	/**
	 * Clear the permanent log and reset the maximum number of log lines to keep track of.
	 * @param LineLength - Maximum length per log line (longer lines will be wrapped around).
	 * @param NumLines - Number of lines to keep track of.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusPlatform|Log")
	void ClearLog(int32 LineLength, int32 NumLines);

	/**
	 * Logs a message on the permanent log.  Long lines will end up on multiple lines.
	 * @param Message - String.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusPlatform|Log")
	void LogMessage(FString Message);

	/**
	 * Array of strings containing the most recently logged messages.
	 */
	UPROPERTY(BlueprintReadonly, Category = "OculusPlatform|Log")
	TArray<FString> Log;

	/**
	 * Delegate called whenever the permanent log is updated.
	 */
	UPROPERTY(BlueprintAssignable, Category = "OculusPlatform|Log")
	FOculusPlatformLogUpdated OnLogUpdated;

private:
	
	UPROPERTY()
	int32 LogLineLength;

	UPROPERTY()
	int32 LogNumLines;

	void LogLine(const FString& Line);

	void LogEntry(const FString& LogEntry, bool bBroadcast = true);
	void LogWarning(const FString& LogEntry, bool bBroadcast = true);
	void LogError(const FString& LogEntry, bool bBroadcast = true);

	void LogMessageInternal(FString Message, bool bBroadcast, ELogVerbosity::Type Verbosity);
};
