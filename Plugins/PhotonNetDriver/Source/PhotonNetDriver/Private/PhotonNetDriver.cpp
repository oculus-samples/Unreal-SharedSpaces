// Copyright (c) Facebook Technologies, LLC and its affiliates.  All rights reserved.

#include "PhotonNetDriver.h"

#define LOCTEXT_NAMESPACE "FPhotonNetDriverModule"

void FPhotonNetDriverModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FPhotonNetDriverModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

bool FPhotonNetDriverModule::IsGameModule() const
{
	return true;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FPhotonNetDriverModule, PhotonNetDriver)