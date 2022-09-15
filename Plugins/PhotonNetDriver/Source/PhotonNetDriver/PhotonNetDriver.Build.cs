// Copyright (c) Meta Platforms, Inc. and its affiliates.  All rights reserved.

using System;
using System.IO;
using UnrealBuildTool;

public class PhotonNetDriver : ModuleRules
{
	public PhotonNetDriver(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		MinFilesUsingPrecompiledHeaderOverride = 1;
		//bFasterWithoutUnity = true;

		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
		);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
		);

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Sockets",
				"Engine",
				"InputCore",
				"OnlineSubsystemUtils",
				"OvrPlatform",
				"PacketHandler"
				// ... add other public dependencies that you statically link with here ...
			}
		);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Photon",
				"CoreUObject",
				"Engine",
				// ... add private dependencies that you statically link with here ...	
			}
		);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
		);

		// LibOVRPlatform dependencies.
		PublicDependencyModuleNames.AddRange(
			new string[] {
				"LibOVRPlatform"
			}
		);
	}
}
