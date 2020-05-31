// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PipePuzzlePiece.h"
#include "GenericTriggerable.h"
#include "PipePuzzleController.generated.h"

UCLASS()
class PROJECTMOONJAM_API APipePuzzleController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APipePuzzleController();

	void Update();

	UFUNCTION(BluePrintCallable, Category=success)
	bool IsComplete() { return completed; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = statics)
	APipePuzzlePiece* source;

	UPROPERTY(EditAnywhere, Category = statics)
	APipePuzzlePiece* sink;

	UPROPERTY(EditAnywhere, category = success)
	TArray<AGenericTriggerable*> triggerables;

	bool completed = false;

	void TriggerItems();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
