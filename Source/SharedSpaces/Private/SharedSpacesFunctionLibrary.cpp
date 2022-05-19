// Copyright (c) Facebook, Inc. and its affiliates.


#include "SharedSpacesFunctionLibrary.h"
#include "Serialization/JsonReader.h"
#include <stdio.h>


DEFINE_LOG_CATEGORY(LogSharedSpaces);

namespace SSFL
{
	const FString IsLobbyKey(TEXT("is_lobby"));
	const FString MapKey(TEXT("map"));
	const FString PublicRoomNameKey(TEXT("public_room_name"));
	const FString RoomIdKey(TEXT("room"));
}

void USharedSpacesFunctionLibrary::GetIsLobby(const FString& DeepLink, bool& bIsLobby)
{
	TSharedPtr<FJsonObject> DeepLinkJson = MakeShareable(new FJsonObject());
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(DeepLink);
	
	bIsLobby = false;
	FString IsLobbyValue;

	if (FJsonSerializer::Deserialize(JsonReader, DeepLinkJson) &&
		DeepLinkJson->TryGetStringField(SSFL::IsLobbyKey, IsLobbyValue))
	{
		bIsLobby = IsLobbyValue.Equals(TEXT("true"), ESearchCase::IgnoreCase);
	}
}

void USharedSpacesFunctionLibrary::GetLaunchMap(const FString& DeepLink, const FString& OptionalDefaultMapName, bool& HasMapName, FString& MapName)
{
	TSharedPtr<FJsonObject> DeepLinkJson = MakeShareable(new FJsonObject());
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(DeepLink);
	
	HasMapName =
		FJsonSerializer::Deserialize(JsonReader, DeepLinkJson) &&
		DeepLinkJson->TryGetStringField(SSFL::MapKey, MapName);

	if (!HasMapName && !OptionalDefaultMapName.IsEmpty())
	{
		MapName = OptionalDefaultMapName;
		HasMapName = true;
	}
}

void USharedSpacesFunctionLibrary::GetPublicRoomName(const FString& DeepLink, bool& HasPublicRoomName, FString& PublicRoomName)
{
	PublicRoomName.Empty();

	TSharedPtr<FJsonObject> DeepLinkJson = MakeShareable(new FJsonObject());
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(DeepLink);
	
	HasPublicRoomName =
		FJsonSerializer::Deserialize(JsonReader, DeepLinkJson) &&
		DeepLinkJson->TryGetStringField(SSFL::PublicRoomNameKey, PublicRoomName);
}

FString USharedSpacesFunctionLibrary::GetLocalCharacterLocationAndRotation()
{
	APlayerController* PlayerController = GWorld->GetFirstPlayerController();
	if (!PlayerController) return TEXT("");

	APawn* Pawn = PlayerController->GetPawn();
	if (!Pawn) return TEXT("");

	const FVector& Loc = Pawn->GetActorLocation();
	const FRotator& Rot = Pawn->GetActorRotation();

	return FString::Printf(
		TEXT("X%+0.2fY%+0.2fZ%+0.2fP%+0.2fY%+0.2fR%+0.2f"),
		Loc.X, Loc.Y, Loc.Z,
		Rot.Pitch, Rot.Yaw, Rot.Roll);
}

bool USharedSpacesFunctionLibrary::ParseLocationAndRotation(const FString& LocationAndRotationString, FVector& Location, FRotator& Rotation)
{
	float X, Y, Z, Pitch, Yaw, Roll;

#if PLATFORM_WINDOWS
	int ParsedItems = sscanf_s(TCHAR_TO_ANSI(*LocationAndRotationString), "X%fY%fZ%fP%fY%fR%f", &X, &Y, &Z, &Pitch, &Yaw, &Roll);
#else
	int ParsedItems = sscanf(TCHAR_TO_ANSI(*LocationAndRotationString), "X%fY%fZ%fP%fY%fR%f", &X, &Y, &Z, &Pitch, &Yaw, &Roll);
#endif


	if (ParsedItems == 6)
	{
		Location = FVector(X, Y, Z);
		Rotation = FRotator(Pitch, Yaw, Roll);
		return true;
	}

	return false;
}

void USharedSpacesFunctionLibrary::SystemLog(const FString& Message)
{
	UE_LOG(LogSharedSpaces, Display, TEXT("%s"), *Message);
}