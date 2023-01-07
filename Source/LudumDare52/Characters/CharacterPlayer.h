// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "CharacterBase.h"
#include "CharacterPlayer.generated.h"

class USpringArmComponent;
class UCameraComponent;
class USoulsCounterComponent;
class UPhylacteriesCounterComponent;
class UCoinsCounterComponent;

UCLASS()
class LUDUMDARE52_API ACharacterPlayer : public ACharacterBase
{
	GENERATED_BODY()

public:
	ACharacterPlayer();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Components")
	USpringArmComponent* SpringArmComponent = nullptr;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Components")
	UCameraComponent* CameraComponent = nullptr;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Components")
	USoulsCounterComponent* SoulsCounterComponent = nullptr;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Components")
	UPhylacteriesCounterComponent* PhylacteryCounterComponent = nullptr;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Components")
	UCoinsCounterComponent* CoinsCounterComponent = nullptr;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Components")
	USimpleResourceComponent* HitsCounterComponent = nullptr;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Controls", meta=(AllowPrivateAccess))
	float CameraYawSensitivity = 15.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Controls", meta=(AllowPrivateAccess))
	float CameraPitchSensitivity= 15.f;
	
	void MoveForward(const float AxisValue);
	void MoveRight(const float AxisValue);
	void LookUp(const float AxisValue);
	void LookRight(const float AxisValue);

public:
	void IncrementMaxSouls(const int32 Amount) const;
	void IncrementMaxPhylacteries(const int32 Amount) const;
	void IncrementMaxCoins(const int32 Amount) const;
};
