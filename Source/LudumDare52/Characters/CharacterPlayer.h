// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "CharacterBase.h"
#include "CharacterPlayer.generated.h"

class UDamageTriggerComponent;
class USpringArmComponent;
class UCameraComponent;
class USoulsCounterComponent;
class UPhylacteriesCounterComponent;
class UCoinsCounterComponent;
class UMeleeAttackComponent;
class URangedAttackComponent;
class UTransitionScreenWidget;
class UPlayerRestartComponent;

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Components")
	UMeleeAttackComponent* MeleeAttackComponent = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Components")
	UDamageTriggerComponent* DamageTriggerComponent = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Components")
	URangedAttackComponent* RangedAttackComponent = nullptr;

	UPROPERTY(VisibleDefaultsOnly, Category="Components")
	UPlayerRestartComponent* PlayerRestartComponent = nullptr;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Controls", meta=(AllowPrivateAccess))
	float CameraYawSensitivity = 15.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Controls", meta=(AllowPrivateAccess))
	float CameraPitchSensitivity = 15.f;

	void MoveForward(const float AxisValue);
	void MoveRight(const float AxisValue);
	void LookUp(const float AxisValue);
	void LookRight(const float AxisValue);

	UFUNCTION()
	void StartMeleeAttack();

	UFUNCTION()
	void StartRangedAttack();

	virtual void HandleDeathStart() override;
	virtual void HandleDeathFinish() override;

	UFUNCTION()
	void HandleRestart();

	void ToggleMovement(const bool bIsEnabled) const;

public:
	void IncrementMaxSouls(const int32 Amount) const;
	void IncrementMaxPhylacteries(const int32 Amount) const;
	void IncrementMaxCoins(const int32 Amount) const;

	UFUNCTION(BlueprintCallable)
	void LoadCountersValue(const int32 SoulsValue, const int32 PhylacteryValue, const int32 CoinsValue);
};
