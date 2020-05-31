// Fill out your copyright notice in the Description page of Project Settings.


#include "PipePuzzlePiece.h"
#include "PipePuzzleController.h"

namespace
{
	FORCEINLINE EPuzzlePieceDirection GetOppositeDirection(EPuzzlePieceDirection direction)
	{
		return static_cast<EPuzzlePieceDirection>((direction + 2) % 4);
	}
}

// Sets default values
APipePuzzlePiece::APipePuzzlePiece()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void APipePuzzlePiece::BeginPlay()
{
	Super::BeginPlay();
	bLastTickPowered = bPowered;
}

// Called every frame
void APipePuzzlePiece::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APipePuzzlePiece::SetPowered(bool NewPower)
{
	bPowered = NewPower;
	UpdateMaterial();
}

void APipePuzzlePiece::UpdateMaterial_Implementation() {}

void APipePuzzlePiece::OnClick()
{
	Rotate();
	controller->Update();
}

void APipePuzzlePiece::Rotate()
{
	state = static_cast<EPuzzlePieceDirection>((state + 1) % 4);

	float zRotation = static_cast<int>(state) * -90.f;
	FVector rotation(0, 0, zRotation);
	SetActorRotation(FQuat::MakeFromEuler(rotation));
}

TArray<APipePuzzlePiece*> APipePuzzlePiece::GetConnections()
{
	TArray<APipePuzzlePiece*> ValidConnections;
	for (const auto& direction : ConnectionDirections)
	{
		auto newDirection = static_cast<EPuzzlePieceDirection>((direction + state) % 4);

		APipePuzzlePiece* piece = Connections[newDirection];
		auto oppdir = GetOppositeDirection(newDirection);
		if (piece != nullptr && piece->HasConnectionTowardsDirection(oppdir))
		{
			ValidConnections.Push(piece);
		}
	}
	return ValidConnections;
}

void APipePuzzlePiece::ResetConnections()
{
	SetPowered(false);
	for (auto& connection : Connections)
	{
		if (connection != nullptr && connection->bPowered)
		{
			connection->ResetConnections();
		}
	}
}

bool APipePuzzlePiece::HasConnectionTowardsDirection(EPuzzlePieceDirection direction)
{
	auto correctedDirection = static_cast<EPuzzlePieceDirection>((direction + 4 - state) % 4);
	return ConnectionDirections.Find(correctedDirection) != INDEX_NONE;
}
