// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "ProjectMoonJamPlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "ProjectMoonJamCharacter.h"
#include "Engine/World.h"

AProjectMoonJamPlayerController::AProjectMoonJamPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void AProjectMoonJamPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	// keep updating the destination every tick while desired
	if (bMoveToMouseCursor)
	{
		MoveToMouseCursor();
	}
}

void AProjectMoonJamPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &AProjectMoonJamPlayerController::OnSetDestinationPressed);
	InputComponent->BindAction("SetDestination", IE_Released, this, &AProjectMoonJamPlayerController::OnSetDestinationReleased);

	// support touch devices 
	InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &AProjectMoonJamPlayerController::MoveToTouchLocation);
	InputComponent->BindTouch(EInputEvent::IE_Repeat, this, &AProjectMoonJamPlayerController::MoveToTouchLocation);

	InputComponent->BindAxis("MoveForward", this, &AProjectMoonJamPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AProjectMoonJamPlayerController::MoveRight);

	InputComponent->BindAction("ResetVR", IE_Pressed, this, &AProjectMoonJamPlayerController::OnResetVR);
}

void AProjectMoonJamPlayerController::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void AProjectMoonJamPlayerController::MoveToMouseCursor()
{
	// Trace to see what is under the mouse cursor
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);

	if (Hit.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(Hit.ImpactPoint);
	}
}

void AProjectMoonJamPlayerController::MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	FVector2D ScreenSpaceLocation(Location);

	// Trace to see what is under the touch location
	FHitResult HitResult;
	GetHitResultAtScreenPosition(ScreenSpaceLocation, CurrentClickTraceChannel, true, HitResult);
	if (HitResult.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(HitResult.ImpactPoint);
	}
}

void AProjectMoonJamPlayerController::SetNewMoveDestination(const FVector DestLocation)
{
	APawn* const MyPawn = GetPawn();
	if (MyPawn)
	{
		float const Distance = FVector::Dist(DestLocation, MyPawn->GetActorLocation());

		// We need to issue move command only if far enough in order for walk animation to play correctly
		if ((Distance > 120.0f))
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, DestLocation);
		}
	}
}

void AProjectMoonJamPlayerController::MoveRight(float Modifier)
{
	APawn* ControlledPawn = GetPawn();
	if(ControlledPawn)
	{
		const FVector Right(0, 1, 0);
		ControlledPawn->AddMovementInput(Right, Modifier);
	}
}

void AProjectMoonJamPlayerController::MoveForward(float Modifier)
{
	APawn* ControlledPawn = GetPawn();
	if(ControlledPawn)
	{
		const FVector Forward(1, 0, 0);
		ControlledPawn->AddMovementInput(Forward, Modifier);
	}
}

void AProjectMoonJamPlayerController::OnSetDestinationPressed()
{
	// set flag to keep updating destination until released
	bMoveToMouseCursor = true;
}

void AProjectMoonJamPlayerController::OnSetDestinationReleased()
{
	// clear flag to indicate we should stop updating the destination
	bMoveToMouseCursor = false;
}
