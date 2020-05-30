// Fill out your copyright notice in the Description page of Project Settings.


#include "BooleanActorBase.h"

// Sets default values
ABooleanActorBase::ABooleanActorBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABooleanActorBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABooleanActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ABooleanActorBase::IsActivated_Implementation()
{
	return false;
}


void ABooleanActorBase::OnInputChanged_Implementation(bool NewValue)
{

}
