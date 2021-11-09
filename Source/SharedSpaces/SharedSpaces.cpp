// Copyright (c) Facebook, Inc. and its affiliates.

#include "SharedSpaces.h"
#include "Modules/ModuleManager.h"
#include "OculusDeveloperTelemetry.h"

OCULUS_TELEMETRY_LOAD_MODULE("Unreal-SharedSpaces");

IMPLEMENT_PRIMARY_GAME_MODULE(
	FDefaultGameModuleImpl,
	SharedSpaces,
	"SharedSpaces"
);
 