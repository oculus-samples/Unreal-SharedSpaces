// Copyright (c) Facebook, Inc. and its affiliates.

#pragma once

#include "CoreMinimal.h"
#include "OVR_Platform.h"
#include "Misc/CString.h"
#include "OculusPlatformTypes.generated.h"


USTRUCT(BlueprintType)
struct OCULUSPLATFORM_API FOculusId
{
	GENERATED_BODY()

	FOculusId(): Id(0) {}
	FOculusId(ovrID ID): Id(ID) {}
	FOculusId(const FString& StrId): Id(FCString::Strtoui64(*StrId, nullptr, 10)) {}

	operator ovrID() const { return Id; }

private:

	ovrID Id;
};

UENUM(BlueprintType)
enum class EUserPresenceStatus : uint8
{
	UserPresenceStatus_Unknown,
	UserPresenceStatus_Online,
	UserPresenceStatus_Offline,

	UserPresenceStatus_Count UMETA(Hidden, DisplayName = "<INVALID>")
};

UENUM(BlueprintType)
enum class EUserEntitlementStatus : uint8 {
	UserEntitlementStatus_Pending,
	UserEntitlementStatus_Authorized,
	UserEntitlementStatus_Unauthorized,

	UserEntitlementStatus_Count UMETA(Hidden, DisplayName = "<INVALID>")
};

UENUM(BlueprintType)
enum class ERoomJoinPolicy : uint8 {
	RoomJoinPolicy_None,
	RoomJoinPolicy_Everyone,
	RoomJoinPolicy_FriendsOfMembers,
	RoomJoinPolicy_FriendsOfOwner,
	RoomJoinPolicy_InvitedUsers,
	RoomJoinPolicy_Unknown,

	RoomJoinPolicy_Count UMETA(Hidden, DisplayName = "<INVALID>")
};

UENUM(BlueprintType)
enum class ELaunchType : uint8 {
	LaunchType_Unknown,
	LaunchType_Normal,
	LaunchType_Invite,
	LaunchType_Coordinated,
	LaunchType_Deeplink
};

USTRUCT(BlueprintType)
struct OCULUSPLATFORM_API FOculusPlatformLaunchDetails
{
	GENERATED_USTRUCT_BODY()

	// If provided, the intended destination the user would like to go to
	UPROPERTY(BlueprintReadOnly, Category = "OculusPlatform|LaunchDetails")
	FString DestinationApiName;

	// An opaque string provided by the developer to help them deeplink to content
	// on app startup.
	UPROPERTY(BlueprintReadOnly, Category = "OculusPlatform|LaunchDetails")
	FString DeepLinkMessage;

	// If provided, the intended lobby the user would like to be in
	UPROPERTY(BlueprintReadOnly, Category = "OculusPlatform|LaunchDetails")
	FString LobbySessionId;

	// If provided, the intended session the user would like to be in
	UPROPERTY(BlueprintReadOnly, Category = "OculusPlatform|LaunchDetails")
	FString MatchSessionId;

	/// If provided, the intended room the user would like to be in
	UPROPERTY(BlueprintReadOnly, Category = "OculusPlatform|LaunchDetails")
	FOculusId RoomId;

	// A unique identifer to keep track of a user going through the deeplinking
	// flow
	UPROPERTY(BlueprintReadOnly, Category = "OculusPlatform|LaunchDetails")
	FString TrackingId;

	// If provided, the intended users the user would like to be with
	// This method may return null. This indicates that the value is not present or that the curent
	// app or user is not permitted to access it.
	UPROPERTY(BlueprintReadOnly, Category = "OculusPlatform|LaunchDetails")
	TArray<FOculusId> ExpectedUsers;

	// A string typically used to distinguish where the deeplink came from. For
	// instance, a DEEPLINK launch type could be coming from events or rich
	// presence.
	UPROPERTY(BlueprintReadOnly, Category = "OculusPlatform|LaunchDetails")
	FString LaunchSource;

	// Launch type.  
	UPROPERTY(BlueprintReadOnly, Category = "OculusPlatform|LaunchDetails")
	ELaunchType LaunchType;
};

USTRUCT(BlueprintType)
struct OCULUSPLATFORM_API FOculusPlatformRoomInfo
{
	GENERATED_USTRUCT_BODY()

	// Room numerical identifier from ovr_Room_GetID()
	UPROPERTY(BlueprintReadOnly, Category = "OculusPlatform|Room")
	FOculusId RoomId;

	// Room owner.
	UPROPERTY(BlueprintReadOnly, Category = "OculusPlatform|Room")
	FOculusId RoomOwnerId;

	// Room description.
	UPROPERTY(BlueprintReadOnly, Category = "OculusPlatform|Room")
	FString Description;

	// Maximum number of users.
	UPROPERTY(BlueprintReadOnly, Category = "OculusPlatform|Room")
	int32 MaxUsers;

	// Room users.
	UPROPERTY(BlueprintReadOnly, Category = "OculusPlatform|Room")
	TArray<FOculusId> RoomUsers;

	// Join policy.
	UPROPERTY(BlueprintReadOnly, Category = "OculusPlatform|Room")
	ERoomJoinPolicy JoinPolicy;

	// Joinability.
	UPROPERTY(BlueprintReadOnly, Category = "OculusPlatform|Room")
	bool bCanJoin;

	// Datastore
	UPROPERTY(BlueprintReadOnly, Category = "OculusPlatform|Room")
	TMap<FString, FString> Datastore;
};

USTRUCT(BlueprintType)
struct OCULUSPLATFORM_API FOculusPlatformDestination
{
	GENERATED_USTRUCT_BODY()

	// API name
	UPROPERTY(BlueprintReadOnly, Category = "OculusPlatform|RichPresence")
	FString ApiName;

	// Deeplink message
	UPROPERTY(BlueprintReadOnly, Category = "OculusPlatform|RichPresence")
	FString DeeplinkMessage;

	// Display name
	UPROPERTY(BlueprintReadOnly, Category = "OculusPlatform|RichPresence")
	FString DisplayName;
};

USTRUCT(BlueprintType)
struct OCULUSPLATFORM_API FOculusPlatformUserInfo
{
	GENERATED_USTRUCT_BODY()

	// User numerical identifier from ovr_User_GetID()
	UPROPERTY(BlueprintReadOnly, Category = "OculusPlatform|User")
	FOculusId AccountId;

	// User string identifier from ovr_User_GetOculusID()
	UPROPERTY(BlueprintReadOnly, Category = "OculusPlatform|User")
	FString AccountName;

	// A potentially non unique displayable name chosen by the user. Could also be
	// the same as the oculus_ID
	UPROPERTY(BlueprintReadOnly, Category = "OculusPlatform|User")
	FString DisplayName;

	// Human readable string of what the user is currently doing. Not intended to
	// be parsed as it might change at anytime or be translated
	UPROPERTY(BlueprintReadOnly, Category = "OculusPlatform|User")
	FString DisplayPresence;

	// Intended to be parsed and used to deep link to parts of the app
	UPROPERTY(BlueprintReadOnly, Category = "OculusPlatform|User")
	FString PresenceDeeplink;

	// If provided, the destination this user is currently at in the app
	UPROPERTY(BlueprintReadOnly, Category = "OculusPlatform|User")
	FString PresenceDestinationApiName;

	// If provided, the lobby session this user is currently at in the app
	UPROPERTY(BlueprintReadOnly, Category = "OculusPlatform|User")
	FString PresenceLobbySessionId;

	// If provided, the match session this user is currently at in the app
	UPROPERTY(BlueprintReadOnly, Category = "OculusPlatform|User")
	FString PresenceMatchSessionId;

	// Enum value of what the user is currently doing.
	UPROPERTY(BlueprintReadOnly, Category = "OculusPlatform|User")
	EUserPresenceStatus PresenceStatus;

	// User images.
	UPROPERTY(BlueprintReadOnly, Category = "OculusPlatform|User")
	FString UserImageUrl;
	UPROPERTY(BlueprintReadOnly, Category = "OculusPlatform|User")
	FString UserSmallImageUrl;

	// Invite token.
	UPROPERTY(BlueprintReadOnly, Category = "OculusPlatform|User")
	FString UserInviteToken;
};
