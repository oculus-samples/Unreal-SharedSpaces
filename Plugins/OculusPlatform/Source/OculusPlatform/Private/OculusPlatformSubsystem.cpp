// Copyright (c) Facebook, Inc. and its affiliates.


#include "OculusPlatformSubsystem.h"
#include "IPAddressOculus.h"
#include "OculusPlatform.h"
#include "OculusPlatformFunctionLibrary.h"
#include "Misc/OutputDeviceNull.h"
#include <string>

// Key constants.
const static FName OCULUS_POOL_KEY = TEXT("OCULUSPOOL");
const static FName OCULUS_BUILD_KEY = TEXT("OCULUSSESSIONBUILDUNIQUEID");

void UOculusPlatformSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	// Set the defaults for the subsystem log.  Must be called before any logging.
	ClearLog(50, 53);

	LogEntry(TEXT("Oculus Platform Subsystem Initialization"));

	// Service Config.
	OCULUS_BUILD_VALUE = GConfig->GetStr(TEXT("OculusPlatform"), TEXT("OculusBuild"), GEngineIni);
	OCULUS_POOL_VALUE = GConfig->GetStr(TEXT("OculusPlatform"), TEXT("OculusPool"), GEngineIni);
	
	// Application events to investigate.
	// FCoreDelegates::FApplicationLifetimeDelegate FCoreDelegates::ApplicationWillDeactivateDelegate;
	// FCoreDelegates::FApplicationLifetimeDelegate FCoreDelegates::ApplicationHasReactivatedDelegate;
	// FCoreDelegates::FApplicationLifetimeDelegate FCoreDelegates::ApplicationWillEnterBackgroundDelegate;
	// FCoreDelegates::FApplicationLifetimeDelegate FCoreDelegates::ApplicationHasEnteredForegroundDelegate;
	// FCoreDelegates::FApplicationLifetimeDelegate FCoreDelegates::ApplicationWillTerminateDelegate;
	// FCoreDelegates::FApplicationLifetimeDelegate FCoreDelegates::ApplicationShouldUnloadResourcesDelegate;
	// FCoreDelegates::FBackgroundTickDelegate FCoreDelegates::MobileBackgroundTickDelegate;

	// Message Handlers.
	OnLaunchIntentChangedHandle =
		GetNotifDelegate(ovrMessage_Notification_ApplicationLifecycle_LaunchIntentChanged)
		.AddUObject(this, &UOculusPlatformSubsystem::HandleOnLaunchIntentChanged);

	OnGroupPresenceJoinIntentReceivedHandle =
		GetNotifDelegate(ovrMessage_Notification_GroupPresence_JoinIntentReceived)
		.AddUObject(this, &UOculusPlatformSubsystem::HandleOnGroupPresenceJoinIntentReceived);

	OnGroupPresenceLeaveIntentReceivedHandle =
		GetNotifDelegate(ovrMessage_Notification_GroupPresence_LeaveIntentReceived)
		.AddUObject(this, &UOculusPlatformSubsystem::HandleOnGroupPresenceLeaveIntentReceived);

	OnGroupPresenceInvitationsSentHandle =
		GetNotifDelegate(ovrMessage_Notification_GroupPresence_InvitationsSent)
		.AddUObject(this, &UOculusPlatformSubsystem::HandleOnGroupPresenceInvitationsSent);

	OnPlatformInitializedStandaloneHandle =
		GetNotifDelegate(ovrMessage_Platform_InitializeStandaloneOculus)
		.AddUObject(this, &UOculusPlatformSubsystem::HandleOnPlatformInitialized);

	OnRoomChangedHandle =
		GetNotifDelegate(ovrMessage_Notification_Room_RoomUpdate)
		.AddUObject(this, &UOculusPlatformSubsystem::HandleOnRoomChanged);

	OnLivestreamingChangedHandle =
		GetNotifDelegate(ovrMessage_Notification_Livestreaming_StatusChange)
		.AddUObject(this, &UOculusPlatformSubsystem::HandleOnLivestreamingChanged);

	bOculusInit = false;
#if PLATFORM_WINDOWS
	bOculusInit = InitWithWindowsPlatform();
#elif PLATFORM_ANDROID
	bOculusInit = InitWithAndroidPlatform();
#endif

	ovrID OculusUserId = ovr_GetLoggedInUserID();
	if (OculusUserId != 0)
	{
		// The platform is initialized and we have an Oculus identifier.
		UE_LOG(LogOculusPlatform, Display, TEXT("We are logged in as Oculus ID %lld."), OculusUserId);

		// Retrieve logged in user info after synchronous init.
		Login();
	}
	else if (bOculusInit)
	{
		// We are initializing the platform in standalone mode (Windows only) with specific credentials.
		UE_LOG(LogOculusPlatform, Display, TEXT("Waiting for Oculus platform to initialize asynchronously."));
	}
	else
	{
		// The OVR Platform failed to initialize properly.  We see this on Windows.  Bad drivers?
		// NOTE: This is too early to have the time to register for OnLoginComplete, so this situation has to
		// be handled in the game instance on event OculusPlatformSubsystemIsReady by looking at the
		// extra parameter indicating if the OVR platform has properly initialized.
		UE_LOG(LogOculusPlatform, Display, TEXT("Oculus platform did not initialize properly."));
	}

	NotifyGameInstanceSubsystemStarted(bOculusInit);
}

void UOculusPlatformSubsystem::NotifyGameInstanceSubsystemStarted(bool bOculusPlatformIsInitialized) const
{
	// IMPORTANT: The subsystem notifies the game instance when it is ready.
	FOutputDeviceNull OutputDeviceNull;
	GetGameInstance()->CallFunctionByNameWithArguments(
		*FString::Printf(TEXT("OculusPlatformSubsystemStarted %s"), bOculusInit ? TEXT("true") : TEXT("false")),
		OutputDeviceNull,
		nullptr,
		true);
}

void UOculusPlatformSubsystem::Deinitialize()
{
	LogEntry(TEXT("Oculus Platform Subsystem Deinitialization"));

	GetNotifDelegate(ovrMessage_Platform_InitializeStandaloneOculus).RemoveAll(this);
	GetNotifDelegate(ovrMessage_Notification_ApplicationLifecycle_LaunchIntentChanged).RemoveAll(this);
	GetNotifDelegate(ovrMessage_Notification_Room_RoomUpdate).RemoveAll(this);
}

// -----------------------------------------------------------------------------
// Application Life-Cycle

const FOculusPlatformLaunchDetails& UOculusPlatformSubsystem::GetLaunchDetails()
{
	ovrLaunchDetailsHandle LaunchDetailsHandle = ovr_ApplicationLifecycle_GetLaunchDetails();

	LaunchDetails.DestinationApiName = ovr_LaunchDetails_GetDestinationApiName(LaunchDetailsHandle);
	LaunchDetails.DeepLinkMessage = ovr_LaunchDetails_GetDeeplinkMessage(LaunchDetailsHandle);
	LaunchDetails.LobbySessionId = ovr_LaunchDetails_GetLobbySessionID(LaunchDetailsHandle);
	LaunchDetails.MatchSessionId = ovr_LaunchDetails_GetMatchSessionID(LaunchDetailsHandle);
	LaunchDetails.RoomId = ovr_LaunchDetails_GetRoomID(LaunchDetailsHandle);
	LaunchDetails.TrackingId = ovr_LaunchDetails_GetTrackingID(LaunchDetailsHandle);
	LaunchDetails.LaunchSource = ovr_LaunchDetails_GetLaunchSource(LaunchDetailsHandle);
	LaunchDetails.LaunchType = ConvertLaunchType(ovr_LaunchDetails_GetLaunchType(LaunchDetailsHandle));

	LaunchDetails.ExpectedUsers.Empty();
	ovrUserArrayHandle UserArrayHandle = ovr_LaunchDetails_GetUsers(LaunchDetailsHandle);
	for (size_t Index = 0, TotalIndices = ovr_UserArray_GetSize(UserArrayHandle); Index < TotalIndices; ++Index)
	{
		const FOculusPlatformUserInfo& UserInfo = CreateOrUpdateUserInfo(ovr_UserArray_GetElement(UserArrayHandle, Index));
		LaunchDetails.ExpectedUsers.Add(UserInfo.AccountId);
	}

	return LaunchDetails;
}

void UOculusPlatformSubsystem::LogLaunchDetails()
{
	LogEntry(TEXT("Oculus Platform Launch Details"));
	LogEntry(FString::Printf(TEXT("  DestinationApiName [%s]"), *LaunchDetails.DestinationApiName));
	LogEntry(FString::Printf(TEXT("  DeepLinkMessage [%s]"), *LaunchDetails.DeepLinkMessage));
	LogEntry(FString::Printf(TEXT("  LobbySessionId [%s]"), *LaunchDetails.LobbySessionId));
	LogEntry(FString::Printf(TEXT("  MatchSessionId [%s]"), *LaunchDetails.MatchSessionId));
	LogEntry(FString::Printf(TEXT("  RoomId [%llu]"), LaunchDetails.RoomId));
	LogEntry(FString::Printf(TEXT("  TrackingId [%s]"), *LaunchDetails.TrackingId));
	LogEntry(FString::Printf(TEXT("  LaunchSource [%s]"), *LaunchDetails.LaunchSource));

	ovrLaunchType LaunchType = ConvertLaunchType(LaunchDetails.LaunchType);
	LogEntry(FString::Printf(TEXT("  LaunchType [%s]"), ANSI_TO_TCHAR(ovrLaunchType_ToString(LaunchType))));

	FString ListOfUsers;
	for (int32 User = 0, TotalUsers = LaunchDetails.ExpectedUsers.Num(); User < TotalUsers; ++User)
	{
		if (User > 0) ListOfUsers.Append(TEXT(", "));
		FOculusId UserId = LaunchDetails.ExpectedUsers[User];
		ListOfUsers.Append(FString::Printf(TEXT("%llu"), UserId));
		if (UserInfos.Contains(UserId))
		{
			ListOfUsers.Append(TEXT(":"));
			ListOfUsers.Append(*UserInfos[UserId].AccountName);
		}
	}

	LogEntry(FString::Printf(TEXT("  ExpectedUsers [%s]"), *ListOfUsers));
}

void UOculusPlatformSubsystem::HandleOnLaunchIntentChanged(ovrMessageHandle Message, bool bIsError)
{
	UE_LOG(LogOculusPlatform, Verbose, TEXT("UOculusPlatformSubsystem::HandleOnLaunchIntentChanged"));

	if (bIsError)
	{
		ovrErrorHandle Error = ovr_Message_GetError(Message);
		FString ErrorMessage = ovr_Error_GetMessage(Error);
		LogError(FString::Printf(TEXT("Error on launch intent changed: %s"), *ErrorMessage));		
	}
	else
	{
		FString LaunchIntent = ovr_Message_GetString(Message);
		
		LogEntry(FString::Printf(TEXT("Received Launch Intent [%s]"), *LaunchIntent));
		GetLaunchDetails();
		LogLaunchDetails();

		OnLaunchIntentChanged.Broadcast(LaunchIntent, LaunchDetails);
	}
}

ELaunchType UOculusPlatformSubsystem::ConvertLaunchType(ovrLaunchType LaunchType) const
{
	switch (LaunchType)
	{
		case ovrLaunchType_Normal:
			return ELaunchType::LaunchType_Normal;
		case ovrLaunchType_Invite:
			return ELaunchType::LaunchType_Invite;
		case ovrLaunchType_Coordinated:
			return ELaunchType::LaunchType_Coordinated;
		case ovrLaunchType_Deeplink:
			return ELaunchType::LaunchType_Deeplink;
		default:
			return ELaunchType::LaunchType_Unknown;
	}
}

ovrLaunchType UOculusPlatformSubsystem::ConvertLaunchType(ELaunchType LaunchType) const
{
	switch (LaunchType)
	{
		case ELaunchType::LaunchType_Normal:
			return ovrLaunchType_Normal;
		case ELaunchType::LaunchType_Invite:
			return ovrLaunchType_Invite;
		case ELaunchType::LaunchType_Coordinated:
			return ovrLaunchType_Coordinated;
		case ELaunchType::LaunchType_Deeplink:
			return ovrLaunchType_Deeplink;
		default:
			return ovrLaunchType_Unknown;
	}
}

// -----------------------------------------------------------------------------
// Room

void UOculusPlatformSubsystem::CreateAndJoinRoom(FString PoolName, ERoomJoinPolicy JoinPolicy, int32 MaxUsers, const FOculusPlatformOnRoomCreationComplete& Callback)
{
	UE_LOG(LogOculusPlatform, Verbose, TEXT("UOculusPlatformSubsystem::CreateAndJoinRoom"));

	ovrMatchmakingOptionsHandle MatchmakingOptionsHandle = ovr_MatchmakingOptions_Create();
	ovr_MatchmakingOptions_SetCreateRoomJoinPolicy(MatchmakingOptionsHandle, ConvertJoinPolicy(JoinPolicy));
	ovr_MatchmakingOptions_SetCreateRoomMaxUsers(MatchmakingOptionsHandle, MaxUsers);
	
	LastJoinedRoom = 0;

	AddRequestDelegate(
		ovr_Matchmaking_CreateAndEnqueueRoom2(TCHAR_TO_UTF8(*PoolName), MatchmakingOptionsHandle),
		FOculusPlatformMessageOnComplete::CreateLambda(
			[this, Callback](ovrMessageHandle Message, bool bIsError)
			{
				FString ErrorMessage;

				if (bIsError)
				{
					ovrErrorHandle Error = ovr_Message_GetError(Message);
					ErrorMessage = ovr_Error_GetMessage(Error);
					LogError(FString::Printf(TEXT("Failed room creation: %s"), *ErrorMessage));
				}
				else
				{
					// Extracting Payload
					ovrMatchmakingEnqueueResultAndRoomHandle EnqueueResultAndRoomHandle = ovr_Message_GetMatchmakingEnqueueResultAndRoom(Message);
					ovrRoomHandle RoomHandle = ovr_MatchmakingEnqueueResultAndRoom_GetRoom(EnqueueResultAndRoomHandle);
					// ovrMatchmakingEnqueueResultHandle EnqueueResultHandle = ovr_MatchmakingEnqueueResultAndRoom_GetMatchmakingEnqueueResult(EnqueueResultAndRoomHandle);
					const FOculusPlatformRoomInfo& RoomInfo = CreateOrUpdateRoomInfo(RoomHandle);
					LastJoinedRoom = RoomInfo.RoomId;

					FString HostAddress;
					GetRoomHostAddress(RoomInfo.RoomId, HostAddress);
					FURL URL;
					URL.Host = HostAddress;

					// We start listening for connections
					GWorld->Listen(URL);

					LogEntry(FString::Printf(TEXT("Created room %llu host address %s"),
						LastJoinedRoom,
						*HostAddress));
				}

				// Notify listeners of join result.
				Callback.ExecuteIfBound(!bIsError, LastJoinedRoom);
			}));

	ovr_MatchmakingOptions_Destroy(MatchmakingOptionsHandle);
}

void UOculusPlatformSubsystem::JoinRoom(FOculusId RoomId, const FOculusPlatformOnRoomJoinComplete& Callback)
{
	UE_LOG(LogOculusPlatform, Verbose, TEXT("UOculusPlatformSubsystem::JoinRoom"));

	LogEntry(FString::Printf(TEXT("Joining room %lld"), RoomId));

	ovrRoomOptionsHandle RoomOptions = ovr_RoomOptions_Create();
	// ovr_RoomOptions_SetTurnOffUpdates(RoomOptions, false);

	LastJoinedRoom = 0;

	AddRequestDelegate(ovr_Room_Join2(RoomId, RoomOptions), FOculusPlatformMessageOnComplete::CreateLambda(
		[this, RoomId, Callback](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				ovrErrorHandle Error = ovr_Message_GetError(Message);
				FString ErrorMessage = ovr_Error_GetMessage(Error);
				LogError(FString::Printf(TEXT("Failed room %lld join: %s"), RoomId, *ErrorMessage));
			}
			else
			{
				// Extracting Payload
				ovrRoomHandle RoomHandle = ovr_Message_GetRoom(Message);
				const FOculusPlatformRoomInfo& RoomInfo = CreateOrUpdateRoomInfo(RoomHandle);
				LastJoinedRoom = RoomInfo.RoomId;
				LogEntry(FString::Printf(TEXT("Joined room %lld"), RoomInfo.RoomId));

				// We start listening for connections
				FString HostAddress;
				GetRoomHostAddress(RoomInfo.RoomId, HostAddress);
				GWorld->GetFirstPlayerController()->ClientTravel(*HostAddress, TRAVEL_Absolute, true);
				LogEntry(FString::Printf(TEXT("Traveling to address %s"), *HostAddress));
			}

			// Notify listeners of join result.
			Callback.ExecuteIfBound(!bIsError);
		}));

	ovr_RoomOptions_Destroy(RoomOptions);
}

void UOculusPlatformSubsystem::RequestCurrentRoom(const FOculusPlatformOnRequestRoomInfoComplete& Callback)
{
	UE_LOG(LogOculusPlatform, Verbose, TEXT("UOculusPlatformSubsystem::RequestCurrentRoom"));

	AddRequestDelegate(ovr_Room_GetCurrent(), FOculusPlatformMessageOnComplete::CreateLambda(
		[this, Callback](ovrMessageHandle Message, bool bIsError)
		{
			FOculusId RoomId;

			if (bIsError)
			{
				ovrErrorHandle Error = ovr_Message_GetError(Message);
				FString ErrorMessage = ovr_Error_GetMessage(Error);
				LogError(FString::Printf(TEXT("Failed to get current room: %s"), *ErrorMessage));
			}
			else
			{
				// Extracting Payload
				ovrRoomHandle RoomHandle = ovr_Message_GetRoom(Message);
				const FOculusPlatformRoomInfo& RoomInfo = CreateOrUpdateRoomInfo(RoomHandle);
				RoomId = RoomInfo.RoomId;
			}

			// Notify listeners of login result.
			Callback.ExecuteIfBound(!bIsError, RoomId);
		}));
}

void UOculusPlatformSubsystem::LeaveRoom(FOculusId RoomId, const FString& OptionalMap, const FOculusPlatformOnRoomLeaveComplete& Callback)
{
	UE_LOG(LogOculusPlatform, Verbose, TEXT("UOculusPlatformSubsystem::LeaveRoom"));

	LogEntry(FString::Printf(TEXT("Leaving room %lld"), RoomId));

	AddRequestDelegate(ovr_Room_Leave(RoomId), FOculusPlatformMessageOnComplete::CreateLambda(
		[this, RoomId, OptionalMap, Callback](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				ovrErrorHandle Error = ovr_Message_GetError(Message);
				FString ErrorMessage = ovr_Error_GetMessage(Error);
				LogError(FString::Printf(TEXT("Failed to leave room %lld: %s"), RoomId, *ErrorMessage));
			}
			else
			{
				// Extracting Payload
				ovrRoomHandle RoomHandle = ovr_Message_GetRoom(Message);
				const FOculusPlatformRoomInfo& RoomInfo = CreateOrUpdateRoomInfo(RoomHandle);

				// We travel to the new map if supplied.
				if (!OptionalMap.IsEmpty())
				{
					GWorld->GetFirstPlayerController()->ClientTravel(*OptionalMap, TRAVEL_Absolute, true);
					LogEntry(FString::Printf(TEXT("Left room %lld and now traveling to level %s"), RoomInfo.RoomId, *OptionalMap));
				}
				else
				{
					LogEntry(FString::Printf(TEXT("Left room %lld with no travel"), RoomInfo.RoomId));
				}
			}

			// Notify listeners of login result.
			Callback.ExecuteIfBound(!bIsError);
		}));
}

const FOculusPlatformRoomInfo& UOculusPlatformSubsystem::CreateOrUpdateRoomInfo(ovrRoomHandle RoomHandle)
{
	FOculusId RoomId = ovr_Room_GetID(RoomHandle);
	if (!RoomInfos.Contains(RoomId))
	{
		RoomInfos.Add(RoomId);
	}

	const FOculusPlatformUserInfo& RoomOwnerInfo = CreateOrUpdateUserInfo(ovr_Room_GetOwner(RoomHandle));

	FOculusPlatformRoomInfo& RoomInfo = RoomInfos[RoomId];
	RoomInfo.RoomId = RoomId;
	RoomInfo.RoomOwnerId = RoomOwnerInfo.AccountId;

	RoomInfo.Description = UTF8_TO_TCHAR(ovr_Room_GetDescription(RoomHandle));
	RoomInfo.JoinPolicy = ConvertJoinPolicy(ovr_Room_GetJoinPolicy(RoomHandle));
	RoomInfo.bCanJoin = ovr_Room_GetJoinability(RoomHandle) == ovrRoom_JoinabilityCanJoin;
	RoomInfo.MaxUsers = ovr_Room_GetMaxUsers(RoomHandle);

	ovrDataStoreHandle DataStoreHandle = ovr_Room_GetDataStore(RoomHandle);
	RoomInfo.Datastore.Empty();
	for (int32 Index = 0, NumKeys = ovr_DataStore_GetNumKeys(DataStoreHandle); Index < NumKeys; ++Index)
	{
		const char* Key = ovr_DataStore_GetKey(DataStoreHandle, Index);
		const char* Value = ovr_DataStore_GetValue(DataStoreHandle, Key);
		RoomInfo.Datastore.Add(UTF8_TO_TCHAR(Key), UTF8_TO_TCHAR(Value));
	}

	//ovrUserArrayHandle ovr_Room_GetInvitedUsers(RoomHandle);
	//ovrMatchmakingEnqueuedUserArrayHandle ovr_Room_GetMatchedUsers(const ovrRoomHandle obj);
	//ovrTeamArrayHandle ovr_Room_GetTeams(const ovrRoomHandle obj);
	//ovrUserArrayHandle ovr_Room_GetUsers(const ovrRoomHandle obj);
	//ovrID ovr_Room_GetApplicationID(const ovrRoomHandle obj);
	//ovrID ovr_Room_GetID(const ovrRoomHandle obj);
	//bool ovr_Room_GetIsMembershipLocked(const ovrRoomHandle obj);
	//const char* ovr_Room_GetName(const ovrRoomHandle obj);
	//ovrRoomType ovr_Room_GetType(const ovrRoomHandle obj);
	//unsigned int ovr_Room_GetVersion(const ovrRoomHandle obj);

	RoomInfo.RoomUsers.Empty();
	ovrUserArrayHandle UserArrayHandle = ovr_Room_GetUsers(RoomHandle);
	for (size_t Index = 0, TotalIndices = ovr_UserArray_GetSize(UserArrayHandle); Index < TotalIndices; ++Index)
	{
		const FOculusPlatformUserInfo& RoomUserInfo = CreateOrUpdateUserInfo(ovr_UserArray_GetElement(UserArrayHandle, Index));
		RoomInfo.RoomUsers.Add(RoomUserInfo.AccountId);
	}

	return RoomInfo;
}

void UOculusPlatformSubsystem::HandleOnRoomChanged(ovrMessageHandle Message, bool bIsError)
{
	UE_LOG(LogOculusPlatform, Verbose, TEXT("UOculusPlatformSubsystem::HandleOnRoomChanged"));

	if (bIsError)
	{
		ovrErrorHandle Error = ovr_Message_GetError(Message);
		FString ErrorMessage = ovr_Error_GetMessage(Error);
		LogError(FString::Printf(TEXT("Error on room changed: %s"), *ErrorMessage));		
	}
	else
	{
		ovrRoomHandle RoomHandle = ovr_Message_GetRoom(Message);

		FOculusId UpdatedRoomId = ovr_Room_GetID(RoomHandle);
		bool bRoomExistsBeforeUpdate = RoomInfos.Contains(UpdatedRoomId);
		FOculusId OwnerBeforeUpdate = bRoomExistsBeforeUpdate ? RoomInfos[UpdatedRoomId].RoomOwnerId : FOculusId(0);

		const FOculusPlatformRoomInfo& Room = CreateOrUpdateRoomInfo(RoomHandle);

		bool bOwnerHasChanged = bRoomExistsBeforeUpdate && (OwnerBeforeUpdate != Room.RoomOwnerId);
		if (bOwnerHasChanged)
		{
			if (Room.RoomOwnerId != 0 && UserInfos.Contains(Room.RoomOwnerId))
			{
				LogEntry(FString::Printf(TEXT("Room %lld changed owner from %s to %s"),
					*UserInfos[OwnerBeforeUpdate].AccountName,
					*UserInfos[Room.RoomOwnerId].AccountName));	
			}
			else
			{
				LogWarning(FString::Printf(TEXT("Room %lld changed owner from %s to unknown user %lld"),
					*UserInfos[OwnerBeforeUpdate].AccountName,
					Room.RoomOwnerId));
			}
		}

		OnRoomChanged.Broadcast(UpdatedRoomId, bOwnerHasChanged);
	}
}

bool UOculusPlatformSubsystem::GetOwnedRoom(FOculusPlatformRoomInfo& RoomInfo)
{
	return GetLastJoinedRoom(RoomInfo) && RoomInfo.RoomOwnerId == AuthenticatedAccountId;
}

bool UOculusPlatformSubsystem::GetLastJoinedRoom(FOculusPlatformRoomInfo& RoomInfo)
{
	return GetRoomInfo(LastJoinedRoom, RoomInfo);
}

bool UOculusPlatformSubsystem::GetRoomInfo(FOculusId RoomId, FOculusPlatformRoomInfo& RoomInfo)
{
	bool RoomExists = RoomInfos.Contains(RoomId);
	if (RoomExists)
	{
		RoomInfo = RoomInfos[RoomId];
	}
	return RoomExists;
}

void UOculusPlatformSubsystem::RequestRoomInfo(FOculusId RoomId, const FOculusPlatformOnRequestRoomInfoComplete& Callback)
{
	UE_LOG(LogOculusPlatform, Verbose, TEXT("UOculusPlatformSubsystem::RequestRoomInfo"));

	LogEntry(FString::Printf(TEXT("Requesting info for room %lld"), RoomId));

	AddRequestDelegate(ovr_Room_Get(RoomId), FOculusPlatformMessageOnComplete::CreateLambda(
		[this, RoomId, Callback](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				ovrErrorHandle Error = ovr_Message_GetError(Message);
				FString ErrorMessage = ovr_Error_GetMessage(Error);
				LogError(FString::Printf(TEXT("Failed to retrieve info for room %lld: %s"), RoomId, *ErrorMessage));
			}
			else
			{
				// Extracting Payload
				ovrRoomHandle RoomHandle = ovr_Message_GetRoom(Message);
				const FOculusPlatformRoomInfo& RoomInfo = CreateOrUpdateRoomInfo(RoomHandle);
				LogEntry(FString::Printf(TEXT("Received infos for room %lld"), RoomInfo.RoomId));
			}

			// Notify listeners of login result.
			Callback.ExecuteIfBound(!bIsError, RoomId);
		}));
}

bool UOculusPlatformSubsystem::GetRoomHostAddress(FOculusId RoomId, FString& HostAddress)
{
	bool RoomExists = RoomInfos.Contains(RoomId);
	if (RoomExists)
	{
		HostAddress = FInternetAddrOculus(RoomInfos[RoomId].RoomOwnerId).ToString(false);
	}
	return RoomExists;
}

ERoomJoinPolicy UOculusPlatformSubsystem::ConvertJoinPolicy(ovrRoomJoinPolicy JoinPolicy) const
{
	switch (JoinPolicy)
	{
		case ovrRoom_JoinPolicyNone:
			return ERoomJoinPolicy::RoomJoinPolicy_None;
		case ovrRoom_JoinPolicyEveryone:
			return ERoomJoinPolicy::RoomJoinPolicy_Everyone;
		case ovrRoom_JoinPolicyFriendsOfMembers:
			return ERoomJoinPolicy::RoomJoinPolicy_FriendsOfMembers;
		case ovrRoom_JoinPolicyFriendsOfOwner:
			return ERoomJoinPolicy::RoomJoinPolicy_FriendsOfOwner;
		case ovrRoom_JoinPolicyInvitedUsers:
			return ERoomJoinPolicy::RoomJoinPolicy_InvitedUsers;
		default:
			return ERoomJoinPolicy::RoomJoinPolicy_Unknown;
	}
}

ovrRoomJoinPolicy UOculusPlatformSubsystem::ConvertJoinPolicy(ERoomJoinPolicy JoinPolicy) const
{
	switch (JoinPolicy)
	{
		case ERoomJoinPolicy::RoomJoinPolicy_None:
			return ovrRoom_JoinPolicyNone;
		case ERoomJoinPolicy::RoomJoinPolicy_Everyone:
			return ovrRoom_JoinPolicyEveryone;
		case ERoomJoinPolicy::RoomJoinPolicy_FriendsOfMembers:
			return ovrRoom_JoinPolicyFriendsOfMembers;
		case ERoomJoinPolicy::RoomJoinPolicy_FriendsOfOwner:
			return ovrRoom_JoinPolicyFriendsOfOwner;
		case ERoomJoinPolicy::RoomJoinPolicy_InvitedUsers:
			return ovrRoom_JoinPolicyInvitedUsers;
		default:
			return ovrRoom_JoinPolicyUnknown;
	}
}

void UOculusPlatformSubsystem::UpdateRoomDatastoreString(FOculusId RoomId, const FString& Key, const FString& Value, const FOculusPlatformOnRoomDatastoreUpdateComplete& Callback)
{
	LogEntry(FString::Printf(TEXT("Updating room %llu datastore with \"%s\" = \"%s\""), RoomId, *Key, *Value));

	ovrKeyValuePair KV = ovrKeyValuePair_makeString(TCHAR_TO_UTF8(*Key), TCHAR_TO_UTF8(*Value));
	AddRequestDelegate(ovr_Room_UpdateDataStore(RoomId, &KV, 1), FOculusPlatformMessageOnComplete::CreateLambda(
		[this, RoomId, Callback](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				ovrErrorHandle Error = ovr_Message_GetError(Message);
				FString ErrorMessage = ovr_Error_GetMessage(Error);
				LogError(FString::Printf(TEXT("Failed to update datastore for room %llu: %s"), RoomId, *ErrorMessage));
			}
			else
			{
				// Extracting Payload
				ovrRoomHandle RoomHandle = ovr_Message_GetRoom(Message);
				FOculusId ReceivedRoomId = CreateOrUpdateRoomInfo(RoomHandle).RoomId;
			}

			// Notify listeners of login result.
			Callback.ExecuteIfBound(!bIsError);
		}));
}

void UOculusPlatformSubsystem::UpdateRoomDescription(FOculusId RoomId, const FString& Description, const FOculusPlatformOnRoomDescriptionUpdateComplete& Callback)
{
	LogEntry(FString::Printf(TEXT("Updating room %llu description with \"%s\""), RoomId, *Description));

	AddRequestDelegate(ovr_Room_SetDescription(RoomId, TCHAR_TO_UTF8(*Description)), FOculusPlatformMessageOnComplete::CreateLambda(
		[this, RoomId, Callback](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				ovrErrorHandle Error = ovr_Message_GetError(Message);
				FString ErrorMessage = ovr_Error_GetMessage(Error);
				LogError(FString::Printf(TEXT("Failed to update description for room %llu: %s"), RoomId, *ErrorMessage));
			}
			else
			{
				// Extracting Payload
				ovrRoomHandle RoomHandle = ovr_Message_GetRoom(Message);
				FOculusId ReceivedRoomId = CreateOrUpdateRoomInfo(RoomHandle).RoomId;
			}

			// Notify listeners of login result.
			Callback.ExecuteIfBound(!bIsError);
		}));
}

// -----------------------------------------------------------------------------
// Matchmaking

void UOculusPlatformSubsystem::BrowseRooms(const FString& PoolName, bool bLog, const FOculusPlatformOnBrowseRoomComplete& Callback)
{
	LogEntry(FString::Printf(TEXT("Requesting available rooms for pool %s"), *PoolName), bLog);

	// ovrMatchmakingOptionsHandle MatchmakingOptionsHandle = ovr_MatchmakingOptions_Create();
		
	AddRequestDelegate(ovr_Matchmaking_Browse2(TCHAR_TO_UTF8(*PoolName), nullptr /* MatchmakingOptionsHandle */), FOculusPlatformMessageOnComplete::CreateLambda(
		[this, PoolName, bLog, Callback](ovrMessageHandle Message, bool bIsError)
		{
			TArray<FOculusId> RoomIds;

			if (bIsError)
			{
				ovrErrorHandle Error = ovr_Message_GetError(Message);
				FString ErrorMessage = ovr_Error_GetMessage(Error);
				LogError(FString::Printf(TEXT("Failed to retrieve rooms for pool %s: %s"), *PoolName, *ErrorMessage));
			}
			else
			{
				// Extracting Payload
				ovrMatchmakingBrowseResultHandle BrowseResult = ovr_Message_GetMatchmakingBrowseResult(Message);
				ovrMatchmakingRoomArrayHandle MatchRoomArray = ovr_MatchmakingBrowseResult_GetRooms(BrowseResult);
				int32 TotalRooms = ovr_MatchmakingRoomArray_GetSize(MatchRoomArray);
				for (size_t Index = 0; Index < TotalRooms; ++Index)
				{
					ovrMatchmakingRoomHandle MatchRoomHandle = ovr_MatchmakingRoomArray_GetElement(MatchRoomArray, Index);

					ovrRoomHandle RoomHandle = ovr_MatchmakingRoom_GetRoom(MatchRoomHandle);
					bool HasPingTime = ovr_MatchmakingRoom_HasPingTime(MatchRoomHandle);
					int32 PingTime = ovr_MatchmakingRoom_GetPingTime(MatchRoomHandle);

					const FOculusPlatformRoomInfo& RoomInfo = CreateOrUpdateRoomInfo(RoomHandle);
					if (HasPingTime)
					{
						LogEntry(FString::Printf(TEXT("Received infos for room %lld (ping %d)"), RoomInfo.RoomId, PingTime), bLog);
					}
					else
					{
						LogEntry(FString::Printf(TEXT("Received infos for room %lld (no ping available)"), RoomInfo.RoomId), bLog);
					}

					RoomIds.Add(RoomInfo.RoomId);
				}

				LogEntry(FString::Printf(TEXT("End of browse response for %d room%s."), TotalRooms, TotalRooms==1 ? TEXT("") : TEXT("s")), bLog);
			}

			// Notify listeners of login result.
			Callback.ExecuteIfBound(!bIsError, RoomIds);
		}));
}

void UOculusPlatformSubsystem::FilterRoomsByDescription(const TArray<FOculusId>& RoomIds, const FString& Description, bool bFilterOutCurrentRoom, bool bLog, TArray<FOculusId>& FilteredRoomIds)
{
	LogEntry(FString::Printf(TEXT("Filter: looking for description [%s]"), *Description), bLog);

	for (int32 Index = 0, NumRooms = RoomIds.Num(); Index < NumRooms; ++Index)
	{
		FOculusId RoomId = RoomIds[Index];
		if (RoomInfos.Contains(RoomId))
		{
			if (bFilterOutCurrentRoom && RoomId == LastJoinedRoom)
			{
				LogEntry(FString::Printf(TEXT("   current room %lld is excluded"), RoomId), bLog);
			}
			else if (RoomInfos[RoomId].Description == Description)
			{
				FilteredRoomIds.Add(RoomId);
				LogEntry(FString::Printf(TEXT("   room %lld is a match"), RoomId), bLog);
			}
			else
			{
				LogEntry(FString::Printf(TEXT("   room %lld doesn't match with description [%s]"), RoomId, *RoomInfos[RoomId].Description), bLog);
			}
		}
		else
		{
			LogError(FString::Printf(TEXT("   room %lld has no infos."), RoomId), bLog);
		}
	}
}

// -----------------------------------------------------------------------------
// Identity

void UOculusPlatformSubsystem::Login()
{
	UE_LOG(LogOculusPlatform, Verbose, TEXT("UOculusPlatformSubsystem::Login"));

	// Immediately add the Oculus ovrID to the cache.
	ovrID UserId = ovr_GetLoggedInUserID();
	if (UserId == 0)
	{
		LogError(TEXT("Cannot retrieve loggged in user since the platform is not initialized."));
		AuthenticatedAccountName = TEXT("Unauthenticated Player");
		OnLoginComplete.Broadcast(false, 0, TEXT(""));
	}
	else
	{
		UserIds.Add(0, UserId);
		AddRequestDelegate(ovr_User_GetLoggedInUser(), FOculusPlatformMessageOnComplete::CreateLambda(
			[this, UserId](ovrMessageHandle Message, bool bIsError)
			{
				FString ErrorMessage;

				if (bIsError)
				{
					ovrErrorHandle Error = ovr_Message_GetError(Message);
					ErrorMessage = ovr_Error_GetMessage(Error);
					LogError(FString::Printf(TEXT("Login failed: %s"), *ErrorMessage));
				}
				else
				{
					// Extracting Payload
					ovrUserHandle UserHandle = ovr_Message_GetUser(Message);
					const FOculusPlatformUserInfo& UserInfo = CreateOrUpdateUserInfo(UserHandle);
					
					// Calls described in Engine\Source\ThirdParty\Oculus\LibOVRPlatform\LibOVRPlatform\include\OVR_User.h
					AuthenticatedAccountId = UserInfo.AccountId;
					AuthenticatedAccountName = UserInfo.AccountName;

					LogEntry(FString::Printf(TEXT("Login successful with id %llu and account %s"), AuthenticatedAccountId, *AuthenticatedAccountName));
					OnLoginComplete.Broadcast(true, AuthenticatedAccountId, AuthenticatedAccountName);
				}
			}));
	}
}

void UOculusPlatformSubsystem::GetEntitlementStatus(const FOculusPlatformOnEntitlementChecked& Callback)
{
	UE_LOG(LogOculusPlatform, Verbose, TEXT("UOculusPlatformSubsystem::GetEntitlementStatus"));

	// Check for entitlement
	AddRequestDelegate(ovr_Entitlement_GetIsViewerEntitled(), FOculusPlatformMessageOnComplete::CreateLambda(
		[this, Callback](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				ovrErrorHandle Error = ovr_Message_GetError(Message);
				FString ErrorMessage(ovr_Error_GetMessage(Error));
				LogError(FString::Printf(TEXT("Failed the entitlement check: %s"), *ErrorMessage));
			}
			else
			{
				LogEntry(TEXT("User is entitled to app"));
			}

			Callback.ExecuteIfBound(!bIsError);
		}));
}

void UOculusPlatformSubsystem::GetListOfFriends(const FOculusPlatformGetListOfFriendsComplete& Callback)
{
	UE_LOG(LogOculusPlatform, Verbose, TEXT("UOculusPlatformSubsystem::GetListOfFriends"));

	AddRequestDelegate(ovr_User_GetLoggedInUserFriends(), FOculusPlatformMessageOnComplete::CreateLambda(
		[this, Callback](ovrMessageHandle Message, bool bIsError)
		{
			ListOfFriends.Empty();

			if (bIsError)
			{
				ovrErrorHandle Error = ovr_Message_GetError(Message);
				FString ErrorMessage(ovr_Error_GetMessage(Error));
				LogError(FString::Printf(TEXT("Error on retrieving list of friends: %s"), *ErrorMessage));
			}
			else
			{
				ovrUserArrayHandle UserArrayHandle = ovr_Message_GetUserArray(Message);

				for (size_t Index = 0, TotalIndices = ovr_UserArray_GetSize(UserArrayHandle); Index < TotalIndices; ++Index)
				{
					ovrUserHandle UserHandle = ovr_UserArray_GetElement(UserArrayHandle, Index);
					const FOculusPlatformUserInfo& UserInfo = CreateOrUpdateUserInfo(UserHandle);
					// Adding the friend to our list of accounts.
					FOculusId FriendId = UserInfo.AccountId;
					FString FriendName = UserInfo.AccountName;
					ListOfFriends.Add(FriendId);
					UE_LOG(LogOculusPlatform, Verbose, TEXT("Friend %llu:%s"), FriendId, *FriendName);
				}

				// NOTE - There are two other API calls that take ovrUserArrayHandle:
				// const char* ovr_UserArray_GetNextUrl(const ovrUserArrayHandle obj)
				// bool ovr_UserArray_HasNextPage(const ovrUserArrayHandle obj)
			}

			Callback.ExecuteIfBound(!bIsError, ListOfFriends);
		}));
}

void UOculusPlatformSubsystem::GetUserInfo(FOculusId UserId, bool& UserExists, FOculusPlatformUserInfo& UserInfo)
{
	UserExists = UserInfos.Contains(UserId);
	if (UserExists)
	{
		UserInfo = UserInfos[UserId];
	}
}

bool UOculusPlatformSubsystem::GetMyUserInfo(FOculusPlatformUserInfo& UserInfo)
{
	if (UserInfos.Contains(AuthenticatedAccountId))
	{
		UserInfo = UserInfos[AuthenticatedAccountId];
		return true;
	}

	return false;
}

EUserPresenceStatus UOculusPlatformSubsystem::ConvertPresenceStatus(ovrUserPresenceStatus Status) const
{
	switch (Status)
	{
		case ovrUserPresenceStatus_Online:
			return EUserPresenceStatus::UserPresenceStatus_Online;
		case ovrUserPresenceStatus_Offline:
			return EUserPresenceStatus::UserPresenceStatus_Offline;
		default:
			return EUserPresenceStatus::UserPresenceStatus_Unknown;
	}
}

ovrUserPresenceStatus UOculusPlatformSubsystem::ConvertPresenceStatus(EUserPresenceStatus Status) const
{
	switch (Status)
	{
		case EUserPresenceStatus::UserPresenceStatus_Online:
			return ovrUserPresenceStatus_Online;
		case EUserPresenceStatus::UserPresenceStatus_Offline:
			return ovrUserPresenceStatus_Offline;
		default:
			return ovrUserPresenceStatus_Unknown;
	}
}

const FOculusPlatformUserInfo&  UOculusPlatformSubsystem::CreateOrUpdateUserInfo(ovrUserHandle UserHandle)
{
	FOculusId AccountId = ovr_User_GetID(UserHandle);

	// Check if we already have a record for this user.
	if (!UserInfos.Contains(AccountId))
	{
		UserInfos.Add(AccountId);
	}

	FOculusPlatformUserInfo& UserInfo = UserInfos[AccountId];
	UserInfo.AccountId = AccountId;
	UserInfo.AccountName = UTF8_TO_TCHAR(ovr_User_GetOculusID(UserHandle));

	// A potentially non unique displayable name chosen by the user. Could also be
	// the same as the oculus_ID
	UserInfo.DisplayName = UTF8_TO_TCHAR(ovr_User_GetDisplayName(UserHandle));

	// Human readable string of what the user is currently doing. Not intended to
	// be parsed as it might change at anytime or be translated
	UserInfo.DisplayPresence = UTF8_TO_TCHAR(ovr_User_GetPresence(UserHandle));

	// Intended to be parsed and used to deep-link to parts of the app
	UserInfo.PresenceDeeplink = UTF8_TO_TCHAR(ovr_User_GetPresenceDeeplinkMessage(UserHandle));

	// If provided, the destination this user is currently at in the app
	UserInfo.PresenceDestinationApiName = UTF8_TO_TCHAR(ovr_User_GetPresenceDestinationApiName(UserHandle));

	// If provided, the lobby session this user is currently at in the app
	UserInfo.PresenceLobbySessionId = UTF8_TO_TCHAR(ovr_User_GetPresenceLobbySessionId(UserHandle));

	// If provided, the match session this user is currently at in the app
	UserInfo.PresenceMatchSessionId = UTF8_TO_TCHAR(ovr_User_GetPresenceMatchSessionId(UserHandle));

	// Enum value of what the user is currently doing.
	UserInfo.PresenceStatus = ConvertPresenceStatus(ovr_User_GetPresenceStatus(UserHandle));
	// FString PresenceStatusStr(ovrUserPresenceStatus_ToString(PresenceStatus));

	// Images.
	UserInfo.UserImageUrl = UTF8_TO_TCHAR(ovr_User_GetImageUrl(UserHandle));
	UserInfo.UserSmallImageUrl = UTF8_TO_TCHAR(ovr_User_GetSmallImageUrl(UserHandle));

	// Invite token.
	UserInfo.UserInviteToken = UTF8_TO_TCHAR(ovr_User_GetInviteToken(UserHandle));

	return UserInfo;
}

// -----------------------------------------------------------------------------
// Rich Presence

void UOculusPlatformSubsystem::RichPresenceClear(const FOculusPlatformOnRichPresenceCleared& Callback)
{
	UE_LOG(LogOculusPlatform, Verbose, TEXT("UOculusPlatformSubsystem::RichPresenceClear"));

	AddRequestDelegate(ovr_RichPresence_Clear(), FOculusPlatformMessageOnComplete::CreateLambda(
		[this, Callback](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				ovrErrorHandle Error = ovr_Message_GetError(Message);
				FString ErrorMessage(ovr_Error_GetMessage(Error));
				LogError(FString::Printf(TEXT("Error clearing rich presence: %s"), *ErrorMessage));
			}
			else
			{
				LogEntry(TEXT("Rich presence cleared."));
			}

			Callback.ExecuteIfBound(!bIsError);
		}));
}

void UOculusPlatformSubsystem::RichPresenceGetDestinations(const FOculusPlatformOnRichPresenceGetDestinationsComplete& Callback)
{
	UE_LOG(LogOculusPlatform, Verbose, TEXT("UOculusPlatformSubsystem::RichPresenceGetDestinations"));
	Destinations.Empty();

	AddRequestDelegate(ovr_RichPresence_GetDestinations(), FOculusPlatformMessageOnComplete::CreateLambda(
		[this, Callback](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				ovrErrorHandle Error = ovr_Message_GetError(Message);
				FString ErrorMessage(ovr_Error_GetMessage(Error));
				LogError(FString::Printf(TEXT("Error getting rich presence destinations: %s"), *ErrorMessage));
			}
			else
			{
				UE_LOG(LogOculusPlatform, Verbose, TEXT("Rich presence destinations received."));
				ovrDestinationArrayHandle DestinationArrayHandle = ovr_Message_GetDestinationArray(Message);

				for (size_t Index = 0, TotalIndices = ovr_DestinationArray_GetSize(DestinationArrayHandle); Index < TotalIndices; ++Index)
				{
					ovrDestinationHandle DestinationHandle = ovr_DestinationArray_GetElement(DestinationArrayHandle, Index);

					FOculusPlatformDestination Destination;
					Destination.ApiName = ovr_Destination_GetApiName(DestinationHandle);
					Destination.DeeplinkMessage = ovr_Destination_GetDeeplinkMessage(DestinationHandle);
					Destination.DisplayName = ovr_Destination_GetDisplayName(DestinationHandle);

					Destinations.Add(Destination);
				}

				// NOTE - There are two other API calls that take ovrDestinationArrayHandle:
				// const char* ovr_DestinationArray_GetNextUrl(const ovrUserArrayHandle obj)
				// bool ovr_DestinationArray_HasNextPage(const ovrUserArrayHandle obj)

			}

			Callback.ExecuteIfBound(!bIsError, Destinations);
		}));
}

void UOculusPlatformSubsystem::RichPresenceGetDestinationByName(const FString& DestinationApiName, const FOculusPlatformOnRichPresenceGetDestinationByNameComplete& Callback)
{
	UE_LOG(LogOculusPlatform, Verbose, TEXT("UOculusPlatformSubsystem::RichPresenceGetDestinationByName"));

	AddRequestDelegate(ovr_RichPresence_GetDestinations(), FOculusPlatformMessageOnComplete::CreateLambda(
		[this, DestinationApiName, Callback](ovrMessageHandle Message, bool bIsError)
		{
			bool bDestinationFound = false;
			FOculusPlatformDestination Destination;

			if (bIsError)
			{
				ovrErrorHandle Error = ovr_Message_GetError(Message);
				FString ErrorMessage(ovr_Error_GetMessage(Error));
				LogError(FString::Printf(TEXT("Error getting rich presence destinations (by name): %s"), *ErrorMessage));
			}
			else
			{
				UE_LOG(LogOculusPlatform, Verbose, TEXT("Rich presence destinations received."));

				ovrDestinationArrayHandle DestinationArrayHandle = ovr_Message_GetDestinationArray(Message);
				for (size_t Index = 0, TotalIndices = ovr_DestinationArray_GetSize(DestinationArrayHandle); Index < TotalIndices; ++Index)
				{
					ovrDestinationHandle DestinationHandle = ovr_DestinationArray_GetElement(DestinationArrayHandle, Index);

					FString ApiName = ovr_Destination_GetApiName(DestinationHandle);
					if (ApiName == DestinationApiName)
					{
						bDestinationFound = true;

						Destination.ApiName = ApiName;
						Destination.DeeplinkMessage = ovr_Destination_GetDeeplinkMessage(DestinationHandle);
						Destination.DisplayName = ovr_Destination_GetDisplayName(DestinationHandle);

						break;
					}
				}

				// NOTE - There are two other API calls that take ovrDestinationArrayHandle:
				// const char* ovr_DestinationArray_GetNextUrl(const ovrUserArrayHandle obj)
				// bool ovr_DestinationArray_HasNextPage(const ovrUserArrayHandle obj)
			}

			Callback.ExecuteIfBound(!bIsError && bDestinationFound, Destination);
		}));
}


void UOculusPlatformSubsystem::RichPresenceSet(
	FString DestinationApiName,
	FString DeeplinkMessageOverride,
	FString LobbyId,
	FString MatchId,
	bool bIsJoinable,
	bool bIsIdle,
	int32 CurrentCapacity,
	int32 MaxCapacity,
	const FOculusPlatformOnRichPresenceSet& Callback)
{
	UE_LOG(LogOculusPlatform, Verbose, TEXT("UOculusPlatformSubsystem::RichPresenceSetDestination"));

	ovrRichPresenceOptionsHandle RichPresenceOptions = ovr_RichPresenceOptions_Create();

	// All empty parameters are ignored on the ovr side.
	// The only parameters that are always set are IsJoinable and IsIdle.
	ovr_RichPresenceOptions_SetApiName(RichPresenceOptions, TCHAR_TO_UTF8(*DestinationApiName));
	ovr_RichPresenceOptions_SetDeeplinkMessageOverride(RichPresenceOptions, TCHAR_TO_UTF8(*DeeplinkMessageOverride));
	ovr_RichPresenceOptions_SetLobbySessionId(RichPresenceOptions, TCHAR_TO_UTF8(*LobbyId));
	ovr_RichPresenceOptions_SetMatchSessionId(RichPresenceOptions, TCHAR_TO_UTF8(*MatchId));
	ovr_RichPresenceOptions_SetIsJoinable(RichPresenceOptions, bIsJoinable);
	ovr_RichPresenceOptions_SetIsIdle(RichPresenceOptions, bIsIdle);
	ovr_RichPresenceOptions_SetCurrentCapacity(RichPresenceOptions, CurrentCapacity);
	ovr_RichPresenceOptions_SetMaxCapacity(RichPresenceOptions, MaxCapacity);

	LogEntry(TEXT("Setting rich presence [OBSOLETE: USE GROUP PRESENCE INSTEAD]"));
	LogEntry(FString::Printf(TEXT("  DestinationApiName [%s]"), *DestinationApiName));
	LogEntry(FString::Printf(TEXT("  DeepLinkMessageOverride [%s]"), *DeeplinkMessageOverride));
	LogEntry(FString::Printf(TEXT("  LobbySessionId [%s]"), *LobbyId));
	LogEntry(FString::Printf(TEXT("  MatchSessionId [%s]"), *MatchId));
	LogEntry(FString::Printf(TEXT("  IsJoinable [%s]"), bIsJoinable?TEXT("true"):TEXT("false")));
	LogEntry(FString::Printf(TEXT("  IsIdle [%s]"), bIsIdle?TEXT("true"):TEXT("false")));
	LogEntry(FString::Printf(TEXT("  CurrentCapacity [%d]"), CurrentCapacity));
	LogEntry(FString::Printf(TEXT("  MaxCapacity [%d]"), MaxCapacity));

	AddRequestDelegate(ovr_RichPresence_Set(RichPresenceOptions), FOculusPlatformMessageOnComplete::CreateLambda(
		[this, Callback](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				ovrErrorHandle Error = ovr_Message_GetError(Message);
				FString ErrorMessage(ovr_Error_GetMessage(Error));
				LogError(FString::Printf(TEXT("Error setting rich presence: %s"), *ErrorMessage));
			}
			else
			{
				LogEntry(TEXT("Rich presence set."));
			}

			Callback.ExecuteIfBound(!bIsError);
		}));

	ovr_RichPresenceOptions_Destroy(RichPresenceOptions);
}

// -----------------------------------------------------------------------------
// Group Presence

void UOculusPlatformSubsystem::GroupPresenceClear(const FOculusPlatformOnGroupPresenceCleared& Callback)
{
	UE_LOG(LogOculusPlatform, Verbose, TEXT("UOculusPlatformSubsystem::GroupPresenceClear"));

	AddRequestDelegate(ovr_GroupPresence_Clear(), FOculusPlatformMessageOnComplete::CreateLambda(
		[this, Callback](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				ovrErrorHandle Error = ovr_Message_GetError(Message);
				FString ErrorMessage(ovr_Error_GetMessage(Error));
				LogError(FString::Printf(TEXT("Error clearing group presence: %s"), *ErrorMessage));
			}
			else
			{
				LastGroupPresence_DestinationApiName.Empty();
				LastGroupPresence_IsJoinable = false;
				LastGroupPresence_LobbyId.Empty();
				LastGroupPresence_MatchId.Empty();

				LogEntry(TEXT("Group presence cleared."));
			}

			Callback.ExecuteIfBound(!bIsError);
		}));
}

void UOculusPlatformSubsystem::GroupPresenceSet(
	FString DestinationApiName,
	bool bIsJoinable,
	FString LobbyId,
	FString MatchId,
	const FOculusPlatformOnGroupPresenceSet& Callback)
{
	UE_LOG(LogOculusPlatform, Verbose, TEXT("UOculusPlatformSubsystem::GroupPresenceSet"));

	LogEntry(TEXT("Setting group presence"));
	LogEntry(FString::Printf(TEXT("  DestinationApiName [%s]"), *DestinationApiName));
	LogEntry(FString::Printf(TEXT("  LobbySessionId [%s]"), *LobbyId));
	LogEntry(FString::Printf(TEXT("  MatchSessionId [%s]"), *MatchId));
	LogEntry(FString::Printf(TEXT("  IsJoinable [%s]"), bIsJoinable?TEXT("true"):TEXT("false")));

	ovrGroupPresenceOptionsHandle GroupPresenceOptions = ovr_GroupPresenceOptions_Create();
	ovr_GroupPresenceOptions_SetDestinationApiName(GroupPresenceOptions, TCHAR_TO_UTF8(*DestinationApiName));
	ovr_GroupPresenceOptions_SetLobbySessionId(GroupPresenceOptions, TCHAR_TO_UTF8(*LobbyId));
	ovr_GroupPresenceOptions_SetMatchSessionId(GroupPresenceOptions, TCHAR_TO_UTF8(*MatchId));
	ovr_GroupPresenceOptions_SetIsJoinable(GroupPresenceOptions, bIsJoinable);

	AddRequestDelegate(ovr_GroupPresence_Set(GroupPresenceOptions),
		FOculusPlatformMessageOnComplete::CreateLambda(
		[this, DestinationApiName, bIsJoinable, LobbyId, MatchId, Callback](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				ovrErrorHandle Error = ovr_Message_GetError(Message);
				FString ErrorMessage(ovr_Error_GetMessage(Error));
				LogError(FString::Printf(TEXT("Error setting group presence: %s"), *ErrorMessage));
			}
			else
			{
				LastGroupPresence_DestinationApiName = DestinationApiName;
				LastGroupPresence_IsJoinable = bIsJoinable;
				LastGroupPresence_LobbyId = LobbyId;
				LastGroupPresence_MatchId = MatchId;

				LogEntry(TEXT("Group presence set."));
			}

			Callback.ExecuteIfBound(!bIsError);
		}));

	ovr_GroupPresenceOptions_Destroy(GroupPresenceOptions);
}

void UOculusPlatformSubsystem::GroupPresenceSetDestination(FString DestinationApiName, const FOculusPlatformOnGroupPresenceSet& Callback)
{
	UE_LOG(LogOculusPlatform, Verbose, TEXT("UOculusPlatformSubsystem::GroupPresenceSetDestination"));

	LogEntry(FString::Printf(TEXT("Setting group presence destination [%s]"), *DestinationApiName));

	AddRequestDelegate(ovr_GroupPresence_SetDestination(TCHAR_TO_UTF8(*DestinationApiName)),
		FOculusPlatformMessageOnComplete::CreateLambda(
		[this, DestinationApiName, Callback](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				ovrErrorHandle Error = ovr_Message_GetError(Message);
				FString ErrorMessage(ovr_Error_GetMessage(Error));
				LogError(FString::Printf(TEXT("Could not set group presence destination: %s"), *ErrorMessage));
			}
			else
			{
				LastGroupPresence_DestinationApiName = DestinationApiName;

				LogEntry(TEXT("Group presence destination set."));
			}

			Callback.ExecuteIfBound(!bIsError);
		}));
}

void UOculusPlatformSubsystem::GroupPresenceSetIsJoinable(bool bIsJoinable, const FOculusPlatformOnGroupPresenceSet& Callback)
{
	UE_LOG(LogOculusPlatform, Verbose, TEXT("UOculusPlatformSubsystem::GroupPresenceSetIsJoinable"));

	LogEntry(FString::Printf(TEXT("Setting group presence to%sjoinable"), (bIsJoinable?TEXT(" "):TEXT(" not "))));

	AddRequestDelegate(ovr_GroupPresence_SetIsJoinable(bIsJoinable),
		FOculusPlatformMessageOnComplete::CreateLambda(
		[this, bIsJoinable, Callback](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				ovrErrorHandle Error = ovr_Message_GetError(Message);
				FString ErrorMessage(ovr_Error_GetMessage(Error));
				LogError(FString::Printf(TEXT("Error setting group presence joinability: %s"), *ErrorMessage));
			}
			else
			{
				LastGroupPresence_IsJoinable = bIsJoinable;

				LogEntry(TEXT("Group presence joinability set."));
			}

			Callback.ExecuteIfBound(!bIsError);
		}));
}

void UOculusPlatformSubsystem::GroupPresenceSetLobbyId(FString LobbyId, const FOculusPlatformOnGroupPresenceSet& Callback)
{
	UE_LOG(LogOculusPlatform, Verbose, TEXT("UOculusPlatformSubsystem::GroupPresenceSetLobbyId"));

	LogEntry(FString::Printf(TEXT("Setting group presence lobby id [%s]"), *LobbyId));

	AddRequestDelegate(ovr_GroupPresence_SetLobbySession(TCHAR_TO_UTF8(*LobbyId)),
		FOculusPlatformMessageOnComplete::CreateLambda(
		[this, LobbyId, Callback](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				ovrErrorHandle Error = ovr_Message_GetError(Message);
				FString ErrorMessage(ovr_Error_GetMessage(Error));
				LogError(FString::Printf(TEXT("Error setting group presence lobby id: %s"), *ErrorMessage));
			}
			else
			{
				LastGroupPresence_LobbyId = LobbyId;

				LogEntry(TEXT("Group presence lobby id set."));
			}

			Callback.ExecuteIfBound(!bIsError);
		}));

}

void UOculusPlatformSubsystem::GroupPresenceSetMatchId(FString MatchId, const FOculusPlatformOnGroupPresenceSet& Callback)
{
	UE_LOG(LogOculusPlatform, Verbose, TEXT("UOculusPlatformSubsystem::GroupPresenceSetMatchId"));

	LogEntry(FString::Printf(TEXT("Setting group presence match id [%s]"), *MatchId));

	AddRequestDelegate(ovr_GroupPresence_SetLobbySession(TCHAR_TO_UTF8(*MatchId)),
		FOculusPlatformMessageOnComplete::CreateLambda(
		[this, MatchId, Callback](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				ovrErrorHandle Error = ovr_Message_GetError(Message);
				FString ErrorMessage(ovr_Error_GetMessage(Error));
				LogError(FString::Printf(TEXT("Error setting group presence match id: %s"), *ErrorMessage));
			}
			else
			{
				LastGroupPresence_MatchId = MatchId;

				LogEntry(TEXT("Group presence match id set."));
			}

			Callback.ExecuteIfBound(!bIsError);
		}));
}

UFUNCTION(BlueprintCallable, Category = "OculusPlatform|GroupPresence")
bool UOculusPlatformSubsystem::GroupPresenceGetCurrent(
	FString& DestinationApiName,
	bool& bIsJoinable,
	FString& LobbyId,
	FString& MatchId)
{
	DestinationApiName = LastGroupPresence_DestinationApiName;
	bIsJoinable = LastGroupPresence_IsJoinable;
	LobbyId = LastGroupPresence_LobbyId;
	MatchId = LastGroupPresence_MatchId;

	return !DestinationApiName.IsEmpty();
}

void UOculusPlatformSubsystem::GroupPresenceLaunchInvitePanel(
	const TArray<FOculusId>& SuggestedUsers,
	const FOculusPlatformOnGroupPresenceInvitePanelComplete& Callback)
{
	UE_LOG(LogOculusPlatform, Verbose, TEXT("UOculusPlatformSubsystem::GroupPresenceLaunchInvitePanel"));

	ovrInviteOptionsHandle InviteOptions = ovr_InviteOptions_Create();

	for (int32 UserIndex = 0, TotalUsers = SuggestedUsers.Num(); UserIndex < TotalUsers; ++UserIndex)
	{
		ovr_InviteOptions_AddSuggestedUser(InviteOptions, SuggestedUsers[UserIndex]);
	}

	LogEntry(TEXT("Launching invite panel."));

	AddRequestDelegate(ovr_GroupPresence_LaunchInvitePanel(InviteOptions), FOculusPlatformMessageOnComplete::CreateLambda(
		[this, Callback](ovrMessageHandle Message, bool bIsError)
		{
			bool bInvitesHaveBeenSent = false;

			if (bIsError)
			{
				ovrErrorHandle Error = ovr_Message_GetError(Message);
				FString ErrorMessage(ovr_Error_GetMessage(Error));
				LogError(FString::Printf(TEXT("Error launching group presence invite panel: %s"), *ErrorMessage));
			}
			else
			{
				ovrInvitePanelResultInfoHandle InvitePanelResultInfoHandle = ovr_Message_GetInvitePanelResultInfo(Message);
				bInvitesHaveBeenSent = ovr_InvitePanelResultInfo_GetInvitesSent(InvitePanelResultInfoHandle);

				LogEntry(FString::Printf(TEXT("Group presence invite panel launch complete.  %s sent."), bInvitesHaveBeenSent?TEXT("Invites"):TEXT("No invites")));
			}

			Callback.ExecuteIfBound(!bIsError, bInvitesHaveBeenSent);
		}));

	ovr_InviteOptions_Destroy(InviteOptions);
}

void UOculusPlatformSubsystem::GroupPresenceLaunchRosterPanel(
	const TArray<FOculusId>& SuggestedUsers,
	const FOculusPlatformOnGroupPresenceRosterPanelComplete& Callback)
{
	UE_LOG(LogOculusPlatform, Verbose, TEXT("UOculusPlatformSubsystem::GroupPresenceLaunchRosterPanel"));

	ovrRosterOptionsHandle RosterOptions = ovr_RosterOptions_Create();

	for (int32 UserIndex = 0, TotalUsers = SuggestedUsers.Num(); UserIndex < TotalUsers; ++UserIndex)
	{
		ovr_RosterOptions_AddSuggestedUser(RosterOptions, SuggestedUsers[UserIndex]);
	}

	LogEntry(FString::Printf(TEXT("Launching roster panel with %d user suggestions."), SuggestedUsers.Num()));

	AddRequestDelegate(ovr_GroupPresence_LaunchRosterPanel(RosterOptions), FOculusPlatformMessageOnComplete::CreateLambda(
		[this, Callback](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				ovrErrorHandle Error = ovr_Message_GetError(Message);
				FString ErrorMessage(ovr_Error_GetMessage(Error));
				LogError(FString::Printf(TEXT("Error launching group presence invite panel: %s"), *ErrorMessage));
			}
			else
			{
				LogEntry(TEXT("Group presence invite panel launch complete."));
			}

			Callback.ExecuteIfBound(!bIsError);
		}));

	ovr_RosterOptions_Destroy(RosterOptions);
}

void UOculusPlatformSubsystem::HandleOnGroupPresenceJoinIntentReceived(ovrMessageHandle Message, bool bIsError)
{
	UE_LOG(LogOculusPlatform, Verbose, TEXT("UOculusPlatformSubsystem::HandleOnGroupPresenceJoinIntentReceived"));

	if (bIsError)
	{
		ovrErrorHandle Error = ovr_Message_GetError(Message);
		FString ErrorMessage = ovr_Error_GetMessage(Error);
		LogError(FString::Printf(TEXT("Error on join intent received: %s"), *ErrorMessage));		
	}
	else
	{
		ovrGroupPresenceJoinIntentHandle JoinIntentHandle = ovr_Message_GetGroupPresenceJoinIntent(Message);
		
		FString DestinationApi = UTF8_TO_TCHAR(ovr_GroupPresenceJoinIntent_GetDestinationApiName(JoinIntentHandle));
		FString DeeplinkMessage = UTF8_TO_TCHAR(ovr_GroupPresenceJoinIntent_GetDeeplinkMessage(JoinIntentHandle));
		FString LobbyId = UTF8_TO_TCHAR(ovr_GroupPresenceJoinIntent_GetLobbySessionId(JoinIntentHandle));
		FString MatchId = UTF8_TO_TCHAR(ovr_GroupPresenceJoinIntent_GetMatchSessionId(JoinIntentHandle));

		LogEntry(TEXT("Group Presence Join Intent Received"));
		LogEntry(FString::Printf(TEXT("  DestinationApiName [%s]"), *DestinationApi));
		LogEntry(FString::Printf(TEXT("  DeepLinkMessage [%s]"), *DeeplinkMessage));
		LogEntry(FString::Printf(TEXT("  LobbySessionId [%s]"), *LobbyId));
		LogEntry(FString::Printf(TEXT("  MatchSessionId [%s]"), *MatchId));

		OnGroupJoinIntentReceived.Broadcast(DestinationApi, DeeplinkMessage, LobbyId, MatchId);
	}
}

void UOculusPlatformSubsystem::HandleOnGroupPresenceLeaveIntentReceived(ovrMessageHandle Message, bool bIsError)
{
	UE_LOG(LogOculusPlatform, Verbose, TEXT("UOculusPlatformSubsystem::HandleOnGroupPresenceLeaveIntentReceived"));

	if (bIsError)
	{
		ovrErrorHandle Error = ovr_Message_GetError(Message);
		FString ErrorMessage = ovr_Error_GetMessage(Error);
		LogError(FString::Printf(TEXT("Error on leave intent received: %s"), *ErrorMessage));		
	}
	else
	{
		ovrGroupPresenceLeaveIntentHandle LeaveIntentHandle = ovr_Message_GetGroupPresenceLeaveIntent(Message);
		
		FString DestinationApi = UTF8_TO_TCHAR(ovr_GroupPresenceLeaveIntent_GetDestinationApiName(LeaveIntentHandle));
		FString LobbyId = UTF8_TO_TCHAR(ovr_GroupPresenceLeaveIntent_GetLobbySessionId(LeaveIntentHandle));
		FString MatchId = UTF8_TO_TCHAR(ovr_GroupPresenceLeaveIntent_GetMatchSessionId(LeaveIntentHandle));

		LogEntry(TEXT("Group Presence Leave Intent Received"));
		LogEntry(FString::Printf(TEXT("  DestinationApiName [%s]"), *DestinationApi));
		LogEntry(FString::Printf(TEXT("  LobbySessionId [%s]"), *LobbyId));
		LogEntry(FString::Printf(TEXT("  MatchSessionId [%s]"), *MatchId));

		OnGroupLeaveIntentReceived.Broadcast(DestinationApi, LobbyId, MatchId);
	}
}

void UOculusPlatformSubsystem::HandleOnGroupPresenceInvitationsSent(ovrMessageHandle Message, bool bIsError)
{
	UE_LOG(LogOculusPlatform, Verbose, TEXT("UOculusPlatformSubsystem::HandleOnGroupPresenceInvitationsSent"));

	if (bIsError)
	{
		ovrErrorHandle Error = ovr_Message_GetError(Message);
		FString ErrorMessage = ovr_Error_GetMessage(Error);
		LogError(FString::Printf(TEXT("Error on invitations sent: %s"), *ErrorMessage));		
	}
	else
	{
		ovrLaunchInvitePanelFlowResultHandle LaunchInvitePanelFlowResultHandle = ovr_Message_GetLaunchInvitePanelFlowResult(Message);

		LogEntry(TEXT("Group Presence Invitations Sent"));
		TArray<FOculusId> InvitedUsers;
		ovrUserArrayHandle UserArrayHandle = ovr_LaunchInvitePanelFlowResult_GetInvitedUsers(LaunchInvitePanelFlowResultHandle);
		for (size_t Index = 0, TotalIndices = ovr_UserArray_GetSize(UserArrayHandle); Index < TotalIndices; ++Index)
		{
			const FOculusPlatformUserInfo& UserInfo = CreateOrUpdateUserInfo(ovr_UserArray_GetElement(UserArrayHandle, Index));
			InvitedUsers.Add(UserInfo.AccountId);
			LogEntry(FString::Printf(TEXT("  Invite sent to id %llu [%s]"), UserInfo.AccountId, *UserInfo.AccountName));
		}

		OnGroupInvitationsSent.Broadcast(InvitedUsers);
	}
}

// -----------------------------------------------------------------------------
// Livestreaming

void UOculusPlatformSubsystem::HandleOnLivestreamingChanged(ovrMessageHandle Message, bool bIsError)
{
	static bool LAST_bCommentsVisible = false;
	static bool LAST_bIsPaused = false;
	static bool LAST_bLivestreamingEnabled = false;
	static int32 LAST_LivestreamingType = 0;
	static bool LAST_bMicEnabled = false;

	if (bIsError)
	{
		ovrErrorHandle Error = ovr_Message_GetError(Message);
		FString ErrorMessage = ovr_Error_GetMessage(Error);
		LogError(FString::Printf(TEXT("Error on livestreaming change: %s"), *ErrorMessage));		
	}
	else
	{
		ovrLivestreamingStatusHandle LivestreamingStatusHandle = ovr_Message_GetLivestreamingStatus(Message);

		bool bCommentsVisible = ovr_LivestreamingStatus_GetCommentsVisible(LivestreamingStatusHandle);
		bool bIsPaused = ovr_LivestreamingStatus_GetIsPaused(LivestreamingStatusHandle);
		bool bLivestreamingEnabled = ovr_LivestreamingStatus_GetLivestreamingEnabled(LivestreamingStatusHandle);
		int32 LivestreamingType = ovr_LivestreamingStatus_GetLivestreamingType(LivestreamingStatusHandle);
		bool bMicEnabled = ovr_LivestreamingStatus_GetMicEnabled(LivestreamingStatusHandle);

		if (bCommentsVisible != LAST_bCommentsVisible ||
			bIsPaused != LAST_bIsPaused ||
			bLivestreamingEnabled != LAST_bLivestreamingEnabled ||
			LivestreamingType != LAST_LivestreamingType ||
			bMicEnabled != LAST_bMicEnabled)
		{
			LogEntry(FString::Printf(TEXT("Livestreaming status change: comments visible [%s] paused [%s] enabled [%s] type [%d] mic [%s]"),
				bCommentsVisible ? TEXT("yes") : TEXT("no"),
				bIsPaused ? TEXT("yes") : TEXT("no"),
				bLivestreamingEnabled ? TEXT("yes") : TEXT("no"),
				LivestreamingType,
				bMicEnabled ? TEXT("yes") : TEXT("no")));

			OnLivestreamingChanged.Broadcast(bCommentsVisible, bIsPaused, bLivestreamingEnabled, LivestreamingType, bMicEnabled);

			LAST_bCommentsVisible = bCommentsVisible;
			LAST_bIsPaused = bIsPaused;
			LAST_bLivestreamingEnabled = bLivestreamingEnabled;
			LAST_LivestreamingType = LivestreamingType;
			LAST_bMicEnabled = bMicEnabled;
		}
	}
}

// -----------------------------------------------------------------------------
// Platform Initialization

#if PLATFORM_WINDOWS
bool UOculusPlatformSubsystem::InitWithWindowsPlatform()
{
	UE_LOG(LogOculusPlatform, Verbose, TEXT("UOculusPlatformSubsystem::InitWithWindowsPlatform()"));

	auto OculusAppId = GetAppId();
	if (OculusAppId.IsEmpty())
	{
		LogError(TEXT("Missing RiftAppId key in OnlineSubsystemOculus of DefaultEngine.ini"));
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

		LogEntry(FString::Printf(TEXT("Login with email [%s]"), *Email));

#if WITH_EDITOR
		try
#endif
		{
			ovrPlatformInitializeResult InitResult;
			ovr_Platform_InitializeStandaloneOculusEx(&InitParams, &InitResult, PLATFORM_PRODUCT_VERSION, PLATFORM_MAJOR_VERSION);
			
			if (InitResult == ovrPlatformInitialize_Success)
			{
				LogEntry(TEXT("UOculusPlatformSubsystem::InitWithWindowsPlatform: ovr_Platform_InitializeStandaloneOculusEx successful"));
			}
			else
			{
				LogError(FString::Printf(TEXT("UOculusPlatformSubsystem::InitWithWindowsPlatform: ovr_Platform_InitializeStandaloneOculusEx error: %s"),
					ANSI_TO_TCHAR(ovrPlatformInitializeResult_ToString(InitResult))));
				return false;
			}
		}
#if WITH_EDITOR
		catch (...)
		{
			LogError(FString::Printf(TEXT("UOculusPlatformSubsystem::InitWithWindowsPlatform: ovr_Platform_InitializeStandaloneOculusEx exception")));
			return false;
		}
#endif
	}
	else
	{
		LogEntry(TEXT("Login with current credentials"));

#if WITH_EDITOR
		try 
#endif
		{
			auto InitResult = ovr_PlatformInitializeWindows(TCHAR_TO_UTF8(*OculusAppId));
			if (InitResult == ovrPlatformInitialize_Success)
			{
				LogEntry(TEXT("UOculusPlatformSubsystem::InitWithWindowsPlatform: ovr_PlatformInitializeWindows successful"));
			}
			else
			{
				LogError(FString::Printf(
					TEXT("UOculusPlatformSubsystem::InitWithWindowsPlatform: ovr_PlatformInitializeWindows error: %d"),
					static_cast<int>(InitResult)));
				return false;
			}
		}
#if WITH_EDITOR
		catch (...) 
		{
			LogError(FString::Printf(TEXT("UOculusPlatformSubsystem::InitWithWindowsPlatform: ovr_PlatformInitializeWindows exception")));
			return false;
		}
#endif
	}

	return true;
}
#elif PLATFORM_ANDROID
bool UOculusPlatformSubsystem::InitWithAndroidPlatform()
{
	UE_LOG(LogOculusPlatform, Verbose, TEXT("UOculusPlatformSubsystem::InitWithAndroidPlatform()"));

	auto OculusAppId = GetAppId();
	if (OculusAppId.IsEmpty())
	{
		LogError(TEXT("Missing MobileAppId key in OnlineSubsystemOculus of DefaultEngine.ini"));
		return false;
	}

	JNIEnv* Env = FAndroidApplication::GetJavaEnv();

	if (Env == nullptr)
	{
		LogError(TEXT("Missing JNIEnv"));
		return false;
	}

	auto InitResult = ovr_PlatformInitializeAndroid(TCHAR_TO_UTF8(*OculusAppId), FAndroidApplication::GetGameActivityThis(), Env);
	if (InitResult != ovrPlatformInitialize_Success)
	{
		LogError(FString::Printf(TEXT("Failed to initialize the Oculus Platform SDK! Error code: %d"), (int)InitResult));
		return false;
	}

	return true;
}
#endif

FString UOculusPlatformSubsystem::GetAppId()
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
	LogWarning(TEXT("Could not find 'RiftAppId' key in engine config.  Trying 'OculusAppId'.  Move your oculus app id to 'RiftAppId' to use in your rift app and make this warning go away."));
#elif PLATFORM_ANDROID
	LogWarning(TEXT("Could not find 'MobileAppId' key in engine config.  Trying 'OculusAppId'.  Move your oculus app id to 'MobileAppId' to use in your quest/go app make this warning go away."));
#endif

	return GConfig->GetStr(TEXT("OnlineSubsystemOculus"), TEXT("OculusAppId"), GEngineIni);
}

void UOculusPlatformSubsystem::HandleOnPlatformInitialized(ovrMessageHandle Message, bool bIsError)
{
	UE_LOG(LogOculusPlatform, Verbose, TEXT("UOculusPlatformSubsystem::OnPlatformInitialized()"));

	// We no longer need the delegate.
	if (OnPlatformInitializedStandaloneHandle.IsValid())
	{
		RemoveNotifDelegate(ovrMessage_Platform_InitializeStandaloneOculus, OnPlatformInitializedStandaloneHandle);
		OnPlatformInitializedStandaloneHandle.Reset();
	}

	if (bIsError)
	{
		LogError(FString::Printf(TEXT("The Oculus platform failed to initialize asynchronously")));
		LogError(FString::Printf(TEXT("Check the credentials used, and entitlement to the app id provided.")));
		return;
	}
	else
	{
		// Retrieve logged in user info after asynchronous init.
		Login();
	}
}

// -----------------------------------------------------------------------------
// Message Pump and Callbacks

void UOculusPlatformSubsystem::AddRequestDelegate(ovrRequest RequestId, FOculusPlatformMessageOnComplete&& Delegate)
{
	RequestDelegates.Emplace(RequestId, Delegate);
}

FOculusPlatformMulticastMessageOnComplete& UOculusPlatformSubsystem::GetNotifDelegate(ovrMessageType MessageType)
{
	return NotifDelegates.FindOrAdd(MessageType);
}

void UOculusPlatformSubsystem::RemoveNotifDelegate(ovrMessageType MessageType, const FDelegateHandle& Delegate)
{
	NotifDelegates.FindOrAdd(MessageType).Remove(Delegate);
}

TStatId UOculusPlatformSubsystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(FOculusPlatformubsystemMessagePump, STATGROUP_Tickables);
}

bool UOculusPlatformSubsystem::IsTickable() const
{
	// Since we are a UCLASS this will prevent us from ticking the CDO.
	return !IsTemplate();
}

void UOculusPlatformSubsystem::Tick(float DeltaTime)
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
		LogWarning(FString::Printf(TEXT("DeltaTime was %f seconds.  Time sensitive oculus notifications may time out."), DeltaTime));
	}
}

void UOculusPlatformSubsystem::OnReceiveMessage(ovrMessageHandle Message)
{
	auto RequestId = ovr_Message_GetRequestID(Message);
	bool bIsError = ovr_Message_IsError(Message);

	if (RequestDelegates.Contains(RequestId))
	{
		RequestDelegates[RequestId].ExecuteIfBound(Message, bIsError);

		// Remove the delegate
		RequestDelegates[RequestId].Unbind();
		RequestDelegates.Remove(RequestId);
	}
	else
	{
		auto MessageType = ovr_Message_GetType(Message);
		if (NotifDelegates.Contains(MessageType))
		{
			if (!bIsError)
			{
				NotifDelegates[MessageType].Broadcast(Message, bIsError);
			}
		}
		else
		{
			LogWarning(FString::Printf(TEXT("Unhandled request id: %llu type: #%010x"), RequestId, static_cast<int32>(MessageType)));
		}
	}
	ovr_FreeMessage(Message);
}

void UOculusPlatformSubsystem::ClearLog(int32 LineLength, int32 NumLines)
{
	LogLineLength = LineLength;
	LogNumLines = NumLines;
	Log.SetNum(NumLines, false);
}

void UOculusPlatformSubsystem::LogMessageInternal(FString Message, bool bBroadcast, ELogVerbosity::Type Verbosity)
{
	// Logcat support
	if (Verbosity != ELogVerbosity::NoLogging)
	{
		switch (Verbosity)
		{
		case ELogVerbosity::Error:
			UE_LOG(LogOculusPlatform, Error, TEXT("%s"), *Message);
			break;
		case ELogVerbosity::Warning:
			UE_LOG(LogOculusPlatform, Warning, TEXT("%s"), *Message);
			break;
		default:
			UE_LOG(LogOculusPlatform, Log, TEXT("%s"), *Message);
			break;
		}
	}

	// This goes to our subsystem log which can be shown in game.
	if (bBroadcast)
	{
		static int32 LineNumber = 0;
		const int32 PrefixLen = 6;
		const int32 LineSegmentLen = LogLineLength-PrefixLen;
		bool bIsFirstLine = true;

		while (!Message.IsEmpty())
		{
			int CutPoint = Message.Len() <= LineSegmentLen ? LineSegmentLen : Message.Find(TEXT(" "), ESearchCase::IgnoreCase, ESearchDir::FromEnd, LineSegmentLen);
			if (CutPoint == INDEX_NONE || CutPoint == 0)
				CutPoint = LineSegmentLen;
			else
				CutPoint++;

			FString SubMessage = Message.Left(CutPoint);
			Message.RemoveFromStart(*SubMessage);

			if (bIsFirstLine)
			{
				LogLine(FString::Printf(TEXT("%04d> %s"), ++LineNumber, *SubMessage));
				bIsFirstLine = false;
			}
			else
			{
				LogLine(FString::Printf(TEXT("      %s"), *SubMessage));
			}
		}

		OnLogUpdated.Broadcast(Log);
	}
}

void UOculusPlatformSubsystem::LogLine(const FString& Line)
{
	// Shift
	for (int32 Index = 0; Index < Log.Num() - 1; ++Index)
	{
		Log[Index] = Log[Index+1];
	}

	// Write at the end
	Log[Log.Num()-1] = Line;
}

void UOculusPlatformSubsystem::LogMessage(FString Message)
{
	LogMessageInternal(Message, true, ELogVerbosity::Log);
}

void UOculusPlatformSubsystem::LogEntry(const FString& LogEntry, bool bBroadcast /* = true */)
{
	LogMessageInternal(LogEntry, bBroadcast, ELogVerbosity::Log);
}

void UOculusPlatformSubsystem::LogWarning(const FString& LogEntry, bool bBroadcast /* = true */)
{
	LogMessageInternal(LogEntry, bBroadcast, ELogVerbosity::Warning);
}

void UOculusPlatformSubsystem::LogError(const FString& LogEntry, bool bBroadcast /* = true */)
{
	LogMessageInternal(LogEntry, bBroadcast, ELogVerbosity::Error);
}
