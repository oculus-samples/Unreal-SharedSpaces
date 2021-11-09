// Copyright (c) Facebook, Inc. and its affiliates.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(LogOculusPlatform, Log, All);

class FOculusPlatformModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	virtual bool IsGameModule() const override;
};

namespace FNetworkProtocolTypes
{
	OCULUSPLATFORM_API extern const FLazyName OculusPlatform;
}
