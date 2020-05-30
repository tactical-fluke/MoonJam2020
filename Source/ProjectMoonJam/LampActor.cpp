// Fill out your copyright notice in the Description page of Project Settings.


#include "LampActor.h"

// Sets default values
ALampActor::ALampActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALampActor::BeginPlay()
{
	Super::BeginPlay();

	RemainingPower = MaxPower;
}

// Called every frame
void ALampActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RemainingPower -= PowerLostPerSec * DeltaTime;
}

