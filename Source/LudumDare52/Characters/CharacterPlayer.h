// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "CharacterBase.h"
#include "CharacterPlayer.generated.h"

class USimpleResourceComponent;
class USpringArmComponent;
class UCameraComponent;

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
	USimpleResourceComponent* SoulsCounterComponent = nullptr;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Components")
	USimpleResourceComponent* PhylacteryCounterComponent = nullptr;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Components")
	USimpleResourceComponent* CoinsCounterComponent = nullptr;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Components")
	USimpleResourceComponent* HitsCounterComponent = nullptr;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Controls", meta=(AllowPrivateAccess))
	float CameraYawSensitivity = 10.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Controls", meta=(AllowPrivateAccess))
	float CameraPitchSensitivity= 10.f;
	
	void MoveForward(const float AxisValue);
	void MoveRight(const float AxisValue);
	void LookUp(const float AxisValue);
	void LookRight(const float AxisValue);
};
