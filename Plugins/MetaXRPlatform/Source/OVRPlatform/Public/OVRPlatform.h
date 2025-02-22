// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(LogOvrPlatform, Log, All);

/// It's a module in the Unreal Engine that provides an interface and access to the Oculus Platform SDK ::ovrPlatformInitializeHandle.
/// It allows developers to integrate Oculus platform features into their games and applications.
class FOvrPlatformModule : public IModuleInterface
{
public:

    /// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module.
    virtual void StartupModule() override;
    /// This function may be called during shutdown to clean up your module. For modules that support dynamic reloading, we call this function before unloading the module.
    virtual void ShutdownModule() override;
    /// This function will return a boolean indicating whether the module is a game module or not.
    virtual bool IsGameModule() const override;
};

namespace FNetworkProtocolTypes
{
	OVRPLATFORM_API extern const FLazyName OvrPlatform;
}
