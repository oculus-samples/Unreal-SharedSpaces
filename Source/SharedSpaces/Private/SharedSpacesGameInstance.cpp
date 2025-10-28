// Copyright (c) Meta Platforms, Inc. and its affiliates.
// Use of the material below is subject to the terms of the MIT License
// https://github.com/oculus-samples/Unreal-SharedSpaces/blob/main/Source/LICENSE

#include "SharedSpacesGameInstance.h"
#include "CoreMinimal.h"

void USharedSpacesGameInstance::AddPlayer(const FUniqueNetIdRepl& NetId)
{
	PlayerAdded.Broadcast(NetId);
	const auto NetIDString = NetId->ToString();
	PlayerIDAdded.Broadcast(NetIDString);
}
