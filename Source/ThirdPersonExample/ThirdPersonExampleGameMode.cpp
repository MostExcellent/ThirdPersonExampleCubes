// Copyright Epic Games, Inc. All Rights Reserved.

#include "ThirdPersonExampleGameMode.h"
#include "ThirdPersonExampleCharacter.h"
#include "UObject/ConstructorHelpers.h"

AThirdPersonExampleGameMode::AThirdPersonExampleGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
