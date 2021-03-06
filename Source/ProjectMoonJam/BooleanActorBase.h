// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BooleanOutputBase.h"
#include "Clickable.h"
#include "GenericTriggerable.h"
#include "BooleanActorBase.generated.h"

UCLASS()
class PROJECTMOONJAM_API ABooleanActorBase : public AActor, public IClickable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABooleanActorBase();

	UFUNCTION(BluePrintNativeEvent, BlueprintCallable, Category = Output)
	bool IsActivated();

	virtual bool IsActivated_Implementation();

	UFUNCTION(BlueprintNativeEvent, BluePrintCallable, Category = Output)
	void OnInputChanged(bool newValue);

	void OnClick() override
	{
		OnInteraction();
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = BooleanInput)
	ABooleanActorBase* Input1;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = BooleanInput)
	ABooleanActorBase* Input2;

	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = Output)
	ABooleanActorBase* output;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, category = triggers)
	TArray<AGenericTriggerable*> triggers;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Interaction)
	void OnInteraction();

	UFUNCTION(BlueprintCallable, Category=triggers)
	void TriggerAll();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
