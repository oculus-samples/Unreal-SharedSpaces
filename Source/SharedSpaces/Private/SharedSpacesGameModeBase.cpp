// Copyright (c) Meta Platforms, Inc. and its affiliates.
// Use of the material below is subject to the terms of the MIT License
// https://github.com/oculus-samples/Unreal-SharedSpaces/Source/LICENSE


#include "SharedSpacesGameModeBase.h"

AActor* ASharedSpacesGameModeBase::GetControllerStartSpot(AController* Controller)
{
	if (Controller)
	{
		return Controller->StartSpot.Get();
	}

	return nullptr;
}
