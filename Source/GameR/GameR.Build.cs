// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GameR : ModuleRules
{
	public GameR(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "UMG", "Slate", "SlateCore", "GameplayTasks", "GameplayAbilities", "GameplayTags" });
	}
}
