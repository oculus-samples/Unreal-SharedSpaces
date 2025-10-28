// Copyright (c) Meta Platforms, Inc. and its affiliates.
// Use of the material below is subject to the terms of the MIT License
// https://github.com/oculus-samples/Unreal-SharedSpaces/blob/main/Source/LICENSE

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/PlayerController.h"
#include "SharedSpacesGameModeBase.generated.h"

UCLASS()
class SHAREDSPACES_API ASharedSpacesGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	/**
	 * Retrieves the last start spot set on the controller.
	 * @param Controller - The player controller to inspect.
	 * @return The actor that represents the last start spot set on the controller.
	 */
	UFUNCTION(BlueprintCallable, Category = "SharedSpaces|Spawn")
	static AActor* GetControllerStartSpot(AController* Controller);

	/**
	 * Used to register the player to the custom gameinstance for a fallback when EOS isn't working.
	 * This is the case when not using the UE-Meta Fork
	 * @param NewPlayer The local player
	 */
	virtual void PostLogin(APlayerController* NewPlayer) override;
};
