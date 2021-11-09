// Copyright (c) Facebook, Inc. and its affiliates.

using UnrealBuildTool;
using System.IO;

public class SharedSpaces : ModuleRules
{
	public SharedSpaces(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[] {
				"Core",
				"CoreUObject",
				"Engine",
				"InputCore",
				"SlateCore",
				"HeadMountedDisplay",
				"UMG",
				"OnlineSubsystem",
				"OnlineSubsystemNull",
				"OnlineSubsystemUtils",
			});

		PrivateDependencyModuleNames.AddRange(
			new string[] {
				"Json",
				"JsonUtilities",
				"LibOVRPlatform",
				"OculusUtils",
			});

		if (Target.Platform == UnrealTargetPlatform.Android) {
			var manifestFile = Path.Combine(ModuleDirectory, "AndroidSanitizePermissions_UPL.xml");
			AdditionalPropertiesForReceipt.Add("AndroidPlugin", manifestFile);
        }
	}
}
