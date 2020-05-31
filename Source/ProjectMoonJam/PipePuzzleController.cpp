// Fill out your copyright notice in the Description page of Project Settings.


#include "PipePuzzleController.h"
#include "Containers/Queue.h"

// Sets default values
APipePuzzleController::APipePuzzleController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void APipePuzzleController::BeginPlay()
{
	Super::BeginPlay();
	source->SetPowered(true);
}

// Called every frame
void APipePuzzleController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APipePuzzleController::Update()
{
	TQueue<APipePuzzlePiece*> queue;

	source->ResetConnections();
	source->SetPowered(true);

	queue.Enqueue(source);
	while (!queue.IsEmpty())
	{
		APipePuzzlePiece* piece;
		queue.Dequeue(piece);
		piece->SetPowered(true);

		auto connections = piece->GetConnections();
		for (auto& connection : connections)
		{
			if (!connection->GetPowered())
			{
				queue.Enqueue(connection);
			}
		}
	}

	completed = sink->GetPowered();
	if (completed)
	{
		TriggerItems();
	}
}

void APipePuzzleController::TriggerItems()
{
	for (auto& trigger : triggerables)
	{
		trigger->Trigger();
	}
}

