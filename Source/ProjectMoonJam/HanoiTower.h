// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Clickable.h"
#include "HanoiTower.generated.h"

UCLASS()
class PROJECTMOONJAM_API AHanoiTower : public AActor, public IClickable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHanoiTower();

	void OnClick() override
	{
		OnClickBP();
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, category = click)
	void OnClickBP();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, category = add)
	void AddBlock(AActor* block);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, category = add)
	AActor* GetTopBlock();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
