// Copyright (c) Facebook, Inc. and its affiliates.

using UnrealBuildTool;
using System.Collections.Generic;

public class SharedSpacesTarget : TargetRules
{
	public SharedSpacesTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("SharedSpaces");
	}
}
