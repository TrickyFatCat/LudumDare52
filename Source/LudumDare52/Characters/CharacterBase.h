﻿// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

class UDeathComponent;
class UHitPointsComponent;
class UAttackComponent;

UCLASS()
class LUDUMDARE52_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ACharacterBase();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Components")
	UHitPointsComponent* HitPointsComponent = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Components")
	UDeathComponent* DeathComponent = nullptr;

	UPROPERTY(BlueprintReadWrite)
	bool bIsAttacking = false;

	UFUNCTION(BlueprintCallable)
	void FinishAttack();

	UFUNCTION()
	virtual void HandleDeathStart();

	UFUNCTION()
	virtual void HandleDeathFinish();

	UPROPERTY(BlueprintReadOnly)
	bool bIsDead = false;

};
