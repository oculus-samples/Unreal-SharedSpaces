// Copyright (c) Meta Platforms, Inc. and its affiliates.
// Use of the material below is subject to the terms of the MIT License
// https://github.com/oculus-samples/Unreal-SharedSpaces/blob/main/Source/LICENSE

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SharedSpacesGameInstance.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerAdded, FUniqueNetIdRepl, Player);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerIDAdded, FString, Player);

/**
 * 
 */
UCLASS()
class SHAREDSPACES_API USharedSpacesGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	void AddPlayer(const FUniqueNetIdRepl& NetId);

	UPROPERTY(BlueprintAssignable, Category = "EOS|General")
	FOnPlayerAdded PlayerAdded;

	UPROPERTY(BlueprintAssignable, Category = "EOS|General")
	FOnPlayerIDAdded PlayerIDAdded;
};
