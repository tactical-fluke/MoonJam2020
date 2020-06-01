// Fill out your copyright notice in the Description page of Project Settings.


#include "HanoiController.h"
#include "HanoiBlock.h"
#include "HanoiTower.h"

// Sets default values
AHanoiController::AHanoiController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHanoiController::BeginPlay()
{
	
	Super::BeginPlay();
	int height = 5;

}

// Called every frame
void AHanoiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHanoiController::Update()
{

}
