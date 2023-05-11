// Copyright Epic Games, Inc. All Rights Reserved.

#include "MPTestingGameMode.h"
#include "MPTestingCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMPTestingGameMode::AMPTestingGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
