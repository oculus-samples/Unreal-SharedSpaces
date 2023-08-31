/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 * All rights reserved.
 *
 * Licensed under the Oculus SDK License Agreement (the "License");
 * you may not use the Oculus SDK except in compliance with the License,
 * which is provided at the time of installation or download, or which
 * otherwise accompanies this software in either electronic or hard copy form.
 *
 * You may obtain a copy of the License at
 *
 * https://developer.oculus.com/licenses/oculussdk/
 *
 * Unless required by applicable law or agreed to in writing, the Oculus SDK
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

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
