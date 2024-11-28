// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameRGameMode.h"
#include "GameRCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGameRGameMode::AGameRGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
