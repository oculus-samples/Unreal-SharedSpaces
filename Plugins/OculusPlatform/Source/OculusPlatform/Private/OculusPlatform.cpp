// Copyright (c) Facebook, Inc. and its affiliates.

#include "OculusPlatform.h"
#include "OculusDeveloperTelemetry.h"

OCULUS_TELEMETRY_LOAD_MODULE("Unreal-OculusPlatform");

#define LOCTEXT_NAMESPACE "FOculusPlatformModule"

DEFINE_LOG_CATEGORY(LogOculusPlatform);

void FOculusPlatformModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FOculusPlatformModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

bool FOculusPlatformModule::IsGameModule() const
{
	return true;
}

#undef LOCTEXT_NAMESPACE
	
namespace FNetworkProtocolTypes
{
	const FLazyName OculusPlatform(TEXT("Oculus"));
}

IMPLEMENT_MODULE(FOculusPlatformModule, OculusPlatform)