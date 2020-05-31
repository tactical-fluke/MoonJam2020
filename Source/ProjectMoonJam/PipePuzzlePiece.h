// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Clickable.h"
#include "PipePuzzlePiece.generated.h"

UENUM()
enum EPuzzlePieceDirection
{
	DIRECTION_UP = 0,
	DIRECTION_LEFT,
	DIRECTON_DOWN,
	DIRECTION_RIGHT
};

UCLASS()
class PROJECTMOONJAM_API APipePuzzlePiece : public AActor, public IClickable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APipePuzzlePiece();

	UFUNCTION(BlueprintCallable, Category = state)
	void SetPowered(bool newPower);
	UFUNCTION(BluePrintCallable, Category = state)
	bool GetPowered() { return bPowered; }

	void ResetConnections();

	TArray<APipePuzzlePiece*> GetConnections();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = Controller)
	class APipePuzzleController* controller;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Connections)
	TArray<APipePuzzlePiece*> Connections;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Connections)
	TArray<TEnumAsByte<EPuzzlePieceDirection>> ConnectionDirections;

	UPROPERTY(BlueprintReadWrite, Category = Power)
	bool bPowered;

	EPuzzlePieceDirection state = DIRECTION_UP;

	void Rotate();

	bool HasConnectionTowardsDirection(EPuzzlePieceDirection direction);

	bool bLastTickPowered;

	UFUNCTION(BlueprintNativeEvent, category = Material)
	void UpdateMaterial();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void OnClick() override;

};
