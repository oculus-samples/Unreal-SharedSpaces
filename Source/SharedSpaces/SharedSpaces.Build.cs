// Copyright (c) Meta Platforms, Inc. and its affiliates.
// Use of the material below is subject to the terms of the MIT License
// https://github.com/oculus-samples/Unreal-SharedSpaces/blob/main/Source/LICENSE

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

		if (Target.Platform == UnrealTargetPlatform.Android && Target.Configuration == UnrealTargetConfiguration.Shipping) {
			var manifestFile = Path.Combine(ModuleDirectory, "AndroidSanitizePermissions_UPL.xml");
			AdditionalPropertiesForReceipt.Add("AndroidPlugin", manifestFile);
        }
	}
}
