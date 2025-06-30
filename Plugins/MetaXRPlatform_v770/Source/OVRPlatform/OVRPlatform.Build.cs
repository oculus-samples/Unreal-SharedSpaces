// Copyright (c) Meta Platforms, Inc. and affiliates.

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
                "OVRPlatformSDK",
                "OnlineSubsystemUtils",
            });

        PrivateDependencyModuleNames.AddRange(
            new string[] {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "PacketHandler",
            });

        if (Target.bBuildEditor == true)
        {
            PrivateDependencyModuleNames.Add("UnrealEd");
        }

        DynamicallyLoadedModuleNames.AddRange(
            new string[] {
                // ... add any modules that your module loads dynamically here ...
            });
    }
}
