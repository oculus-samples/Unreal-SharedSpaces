// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class OVRPlatformSDK : ModuleRules
{
    public OVRPlatformSDK(ReadOnlyTargetRules Target) : base(Target)
    {
        Type = ModuleType.External;

        string LibOVRPlatformDir = "$(ModuleDir)/LibOVRPlatform/";

        bool isLibrarySupported = false;

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            PublicAdditionalLibraries.Add(LibOVRPlatformDir + "lib/LibOVRPlatformImpl64_1.lib");
            PublicDelayLoadDLLs.Add("LibOVRPlatformImpl64_1.dll");
            isLibrarySupported = true;
        }
        else if (Target.Platform == UnrealTargetPlatform.Android)
        {
            PublicAdditionalLibraries.Add(LibOVRPlatformDir + "lib/arm64-v8a/libovrplatformloader.so");
            string ModulePath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
            AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(ModulePath, "LibOVRPlatform_APL.xml"));
            isLibrarySupported = true;
        }

        if (isLibrarySupported)
        {
            PublicIncludePaths.Add(Path.Combine(LibOVRPlatformDir, "include"));
        }
        else
        {
            System.Console.WriteLine("Oculus Platform plugin not supported for this platform");
        }

    }
}
