// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Clickable.h"
#include "GenericClickable.generated.h"

UCLASS()
class PROJECTMOONJAM_API AGenericClickable : public AActor, public IClickable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGenericClickable();

	void OnClick() override
	{
		OnClickBP();
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, category = click)
	void OnClickBP();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
