// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OVRPlatform.h"

#define LOCTEXT_NAMESPACE "FOVRPlatformModule"

DEFINE_LOG_CATEGORY(LogOvrPlatform);

void FOvrPlatformModule::StartupModule()
{
    // This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FOvrPlatformModule::ShutdownModule()
{
    // This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
    // we call this function before unloading the module.
}

bool FOvrPlatformModule::IsGameModule() const
{
    return true;
}

#undef LOCTEXT_NAMESPACE

namespace FNetworkProtocolTypes
{
	const FLazyName OvrPlatform(TEXT("Oculus"));
}

IMPLEMENT_MODULE(FOvrPlatformModule, OVRPlatform)
