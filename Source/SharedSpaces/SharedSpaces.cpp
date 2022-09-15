// Copyright (c) Meta Platforms, Inc. and its affiliates.
// Use of the material below is subject to the terms of the MIT License
// https://github.com/oculus-samples/Unreal-SharedSpaces/Source/LICENSE


#include "SharedSpaces.h"
#include "Modules/ModuleManager.h"
#include "OculusDeveloperTelemetry.h"

OCULUS_TELEMETRY_LOAD_MODULE("Unreal-SharedSpaces");

IMPLEMENT_PRIMARY_GAME_MODULE(
	FDefaultGameModuleImpl,
	SharedSpaces,
	"SharedSpaces"
);
 