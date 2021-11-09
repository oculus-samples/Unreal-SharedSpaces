// Copyright (c) Facebook, Inc. and its affiliates.

using UnrealBuildTool;

public class OculusPlatform : ModuleRules
{
	public OculusPlatform(ReadOnlyTargetRules Target) : base(Target)
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
