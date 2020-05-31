// Fill out your copyright notice in the Description page of Project Settings.


#include "GenericTriggerable.h"

// Sets default values
AGenericTriggerable::AGenericTriggerable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AGenericTriggerable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGenericTriggerable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGenericTriggerable::Trigger_Implementation()
{

}
