// Copyright (c) Meta Platforms, Inc. and affiliates.  All rights reserved.

using UnrealBuildTool;
using System.IO;

public class OculusUtils : ModuleRules
{
	public OculusUtils(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		PrivateIncludePaths.Add(Path.Combine(EngineDirectory, "Plugins/Runtime/OculusXR/OculusXR/Source/OculusXRHMD/Private"));

		PublicIncludePaths.AddRange(
			new string[]
			{
				// ... add public include paths required here ...
			}
		);


		PrivateIncludePaths.AddRange(
			new string[]
			{
				// ... add other private include paths required here ...
			}
		);


		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
		);


		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"OculusXRHMD",
				"DeveloperSettings",
				"OVRPluginXR"
			}
		);

		if (Target.bBuildEditor)
		{
			PrivateDependencyModuleNames.Add("UnrealEd");
			PrivateDependencyModuleNames.Add("DetailCustomizations");
            PrivateDependencyModuleNames.Add("ToolWidgets");
        }


		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
		);

		bLegacyParentIncludePaths = true;
	}
}