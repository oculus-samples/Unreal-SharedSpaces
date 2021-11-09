// Copyright (c) Facebook, Inc. and its affiliates.


#include "SharedSpacesGameModeBase.h"

AActor* ASharedSpacesGameModeBase::GetControllerStartSpot(AController* Controller)
{
	if (Controller)
	{
		return Controller->StartSpot.Get();
	}

	return nullptr;
}
