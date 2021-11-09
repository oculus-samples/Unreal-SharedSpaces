// Copyright (c) Facebook, Inc. and its affiliates.

using UnrealBuildTool;
using System.Collections.Generic;

public class SharedSpacesEditorTarget : TargetRules
{
	public SharedSpacesEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("SharedSpaces");
	}
}
