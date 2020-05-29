// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "ProjectMoonJamGameMode.h"
#include "ProjectMoonJamPlayerController.h"
#include "ProjectMoonJamCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProjectMoonJamGameMode::AProjectMoonJamGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AProjectMoonJamPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}