// Copyright (c) Facebook, Inc. and its affiliates.

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
};
