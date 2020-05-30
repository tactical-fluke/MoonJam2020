// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ProjectMoonJamCharacter.generated.h"

UCLASS(Blueprintable)
class AProjectMoonJamCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AProjectMoonJamCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns CursorToWorld subobject **/
	FORCEINLINE class UDecalComponent* GetCursorToWorld() { return CursorToWorld; }

	UFUNCTION(BluePrintCallable, Category=Energy)
	float GetCurrentEnergy() const { return CurrentEnergy; }
	UFUNCTION(BluePrintCallable, Category=Energy)
	void SetCurrentEnergy(float NewValue) { CurrentEnergy = FMath::Clamp(NewValue, 0.f, MaxEnergy); }
	UFUNCTION(BluePrintCallable, Category=Energy)
	void AddEnergy(float AdditionalEnergy) { SetCurrentEnergy(CurrentEnergy + AdditionalEnergy); }

	UFUNCTION(BluePrintCallable, Category=Energy)
	float GetMaxEnergy() const { return MaxEnergy; }

	UFUNCTION(BluePrintCallable, Category=Energy)
	float GetEnergyLossPerSecond() const { return EnergyLossPerSecond; }
	UFUNCTION(BluePrintCallable, Category=Energy)
	void SetEnergyLossPerSecond(float NewValue) { EnergyLossPerSecond = NewValue; }

protected:

	//maximum energy for the character
	UPROPERTY(EditAnywhere, Category=Energy)
	float MaxEnergy;

	//current energy held
	UPROPERTY(BlueprintReadWrite, Category=Energy)
	float CurrentEnergy;

	//energy lost per second
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Energy)
	float EnergyLossPerSecond;
	
private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** A decal that projects to the cursor location. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UDecalComponent* CursorToWorld;

	bool bShouldRefreshEnergy = true;
};

