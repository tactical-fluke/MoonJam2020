// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LampActor.generated.h"

UCLASS()
class PROJECTMOONJAM_API ALampActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALampActor();

	FORCEINLINE float GetPowerRemaining() const { return RemainingPower; }
	FORCEINLINE float GetMaxPower() const { return MaxPower; };
	FORCEINLINE float GetPowerLossPerSecond() const { return PowerLostPerSec; }

	FORCEINLINE void SetPowerRemaining(float NewVal) { RemainingPower = FMath::Clamp(NewVal, 0.f, MaxPower); }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float PowerLostPerSec;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float MaxPower;
	
	UPROPERTY(BlueprintReadOnly)
	float RemainingPower;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
