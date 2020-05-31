// Fill out your copyright notice in the Description page of Project Settings.


#include "BooleanOutputBase.h"
#include "Engine/Engine.h"

// Sets default values
ABooleanOutputBase::ABooleanOutputBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABooleanOutputBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABooleanOutputBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABooleanOutputBase::OnBooleanInputChanged_Implementation(bool NewValue)
{
#if UE_BUILD_DEBUG
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "No implementation found for OnBooleanInputChanged");
	}
#endif
}

