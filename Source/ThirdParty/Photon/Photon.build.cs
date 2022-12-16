// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class Photon : ModuleRules
{
	public Photon(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;
		string IncludeDirectory = Path.Combine(ModuleDirectory, "Include");
		string Configuration = (Target.Configuration == UnrealTargetConfiguration.Shipping) ? "release" : "debug";

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			Configuration = "release"; // Correct for _ITERATOR_DEBUG_LEVEL mismatch with debug libs
			string Compiler = "vc16";
			string Platform = "x64";
			string LibDirectory = Path.Combine(ModuleDirectory, "Lib", "Windows", Platform);
			string LibSuffix = "_" + Compiler + "_" + Configuration + "_windows_md_" + Platform + ".lib";

			PublicDefinitions.Add("_EG_WINDOWS_PLATFORM");
			PublicIncludePaths.Add(IncludeDirectory);
			PublicAdditionalLibraries.AddRange(new string[] {
				Path.Combine(LibDirectory, "Chat-cpp" + LibSuffix),
				Path.Combine(LibDirectory, "Common-cpp" + LibSuffix),
				Path.Combine(LibDirectory, "LoadBalancing-cpp" + LibSuffix),
				Path.Combine(LibDirectory, "opus_egpv" + LibSuffix),
				Path.Combine(LibDirectory, "Photon-cpp" + LibSuffix),
				Path.Combine(LibDirectory, "PhotonVoice-cpp" + LibSuffix),
			});
		}
		else if (Target.Platform == UnrealTargetPlatform.Android)
		{
			string LibDirectoryV7A = Path.Combine(ModuleDirectory, "Lib", "Android", "armeabi-v7a");
			string LibDirectoryV8A = Path.Combine(ModuleDirectory, "Lib", "Android", "arm64-v8a");
			string LibSuffixV7A = "_" + Configuration + "_android_armeabi-v7a_libc++_no-rtti.a";
			string LibSuffixV8A = "_" + Configuration + "_android_arm64-v8a_libc++_no-rtti.a";

			PublicDefinitions.Add("_EG_ANDROID_PLATFORM");
			PublicIncludePaths.Add(IncludeDirectory);
			PublicAdditionalLibraries.AddRange(new string[] {
				Path.Combine(LibDirectoryV7A, "libchat-cpp-static" + LibSuffixV7A),
				Path.Combine(LibDirectoryV8A, "libchat-cpp-static" + LibSuffixV8A),
				Path.Combine(LibDirectoryV7A, "libcommon-cpp-static" + LibSuffixV7A),
				Path.Combine(LibDirectoryV8A, "libcommon-cpp-static" + LibSuffixV8A),
				Path.Combine(LibDirectoryV7A, "libcrypto" + LibSuffixV7A),
				Path.Combine(LibDirectoryV8A, "libcrypto" + LibSuffixV8A),
				Path.Combine(LibDirectoryV7A, "libloadbalancing-cpp-static" + LibSuffixV7A),
				Path.Combine(LibDirectoryV8A, "libloadbalancing-cpp-static" + LibSuffixV8A),
				Path.Combine(LibDirectoryV7A, "libopus_egpv" + LibSuffixV7A),
				Path.Combine(LibDirectoryV8A, "libopus_egpv" + LibSuffixV8A),
				Path.Combine(LibDirectoryV7A, "libphoton-cpp-static" + LibSuffixV7A),
				Path.Combine(LibDirectoryV8A, "libphoton-cpp-static" + LibSuffixV8A),
				Path.Combine(LibDirectoryV7A, "libphotonvoice-cpp-static" + LibSuffixV7A),
				Path.Combine(LibDirectoryV8A, "libphotonvoice-cpp-static" + LibSuffixV8A),
				Path.Combine(LibDirectoryV7A, "libssl" + LibSuffixV7A),
				Path.Combine(LibDirectoryV8A, "libssl" + LibSuffixV8A),
				Path.Combine(LibDirectoryV7A, "libwebsockets" + LibSuffixV7A),
				Path.Combine(LibDirectoryV8A, "libwebsockets" + LibSuffixV8A),
			});
		}
		else
		{
			System.Console.WriteLine("Photon SDK not installed for this platform");
		}
	}
}
