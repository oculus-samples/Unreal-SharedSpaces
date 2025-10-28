// Copyright (c) Meta Platforms, Inc. and its affiliates.
// Use of the material below is subject to the terms of the MIT License
// https://github.com/oculus-samples/Unreal-SharedSpaces/blob/main/Source/LICENSE


#include "SharedSpacesGameModeBase.h"
#include "OnlineSubsystemUtils.h"
#include "OnlineSubsystem.h"
#include "SharedSpacesGameInstance.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "Kismet/GameplayStatics.h"

AActor* ASharedSpacesGameModeBase::GetControllerStartSpot(AController* Controller)
{
	if (Controller)
	{
		return Controller->StartSpot.Get();
	}

	return nullptr;
}

void ASharedSpacesGameModeBase::PostLogin(APlayerController* NewPlayer)
{
	check(IsValid(NewPlayer));

	FUniqueNetIdRepl UniqueNetIdRepl;
	if (NewPlayer->IsLocalPlayerController())
	{
		ULocalPlayer *LocalPlayer = NewPlayer->GetLocalPlayer();
		if (IsValid(LocalPlayer))
		{
			UniqueNetIdRepl = LocalPlayer->GetPreferredUniqueNetId();
		}
		else
		{
			UNetConnection *RemoteNetConnection = Cast<UNetConnection>(NewPlayer->Player);
			check(IsValid(RemoteNetConnection));
			UniqueNetIdRepl = RemoteNetConnection->PlayerId;
		}
	}
	else
	{
		UNetConnection *RemoteNetConnection = Cast<UNetConnection>(NewPlayer->Player);
		check(IsValid(RemoteNetConnection));
		UniqueNetIdRepl = RemoteNetConnection->PlayerId;
	}

	TSharedPtr<const FUniqueNetId> UniqueNetId = UniqueNetIdRepl.GetUniqueNetId();
	if(UniqueNetId != nullptr)
	{
		auto GameInstance = Cast<USharedSpacesGameInstance>(UGameplayStatics::GetGameInstance(NewPlayer->GetWorld()));
		GameInstance->AddPlayer(UniqueNetIdRepl);
	}

	Super::PostLogin(NewPlayer);
}
