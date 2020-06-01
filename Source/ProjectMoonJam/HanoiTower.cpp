// Fill out your copyright notice in the Description page of Project Settings.


#include "HanoiTower.h"

// Sets default values
AHanoiTower::AHanoiTower()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHanoiTower::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHanoiTower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHanoiTower::OnClickBP_Implementation()
{

}

void AHanoiTower::AddBlock_Implementation(AActor* block)
{

}

AActor* AHanoiTower::GetTopBlock_Implementation()
{
	return nullptr;
}
