// Fill out your copyright notice in the Description page of Project Settings.


#include "GenericClickable.h"

// Sets default values
AGenericClickable::AGenericClickable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGenericClickable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGenericClickable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGenericClickable::OnClickBP_Implementation()
{

}

