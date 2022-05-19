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

using UnrealBuildTool;

public class OVRPlatform : ModuleRules
{
    public OVRPlatform(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
            new string[] {
                // ... add public include paths required here ...
            });

        PrivateIncludePaths.AddRange(
            new string[] {
                // ... add other private include paths required here ...
            });

        PublicDependencyModuleNames.AddRange(
            new string[] {
                "Core",
                "Sockets",
                "OnlineSubsystemUtils",
                "Photon",
            });

        PrivateDependencyModuleNames.AddRange(
            new string[] {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "PacketHandler",
                "OculusUtils",
            });


        DynamicallyLoadedModuleNames.AddRange(
            new string[] {
                // ... add any modules that your module loads dynamically here ...
            });

        // LibOVRPlatform dependencies.
        PublicDependencyModuleNames.AddRange(
            new string[] {
                "LibOVRPlatform"
            });

        if (Target.Platform == UnrealTargetPlatform.Win64 || Target.Platform == UnrealTargetPlatform.Win32)
        {
            if (Target.Platform == UnrealTargetPlatform.Win32)
            {
                PublicDelayLoadDLLs.Add("LibOVRPlatform32_1.dll");
            }
            else
            {
                PublicDelayLoadDLLs.Add("LibOVRPlatform64_1.dll");
            }
        }
        else if (Target.Platform != UnrealTargetPlatform.Android)
        {
            PrecompileForTargets = PrecompileTargetsType.None;
        }
        else
        {
            System.Console.WriteLine("Oculus Platform plugin not supported for this platform");
        }
    }
}
