﻿// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttackComponent.h"
#include "UObject/Object.h"
#include "MeleeAttackComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMeleeBeginSingnature);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMeleeEndSignature);

class USkeletalMeshComponent;

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class LUDUMDARE52_API UMeleeAttackComponent : public UAttackComponent
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;


	void HandleMeleeBegin(USkeletalMeshComponent* SkeletalMeshComponent);
	void HandleMeleeEnd(USkeletalMeshComponent* SkeletalMeshComponent);

public:
	UPROPERTY(BlueprintAssignable)
	FOnMeleeBeginSingnature OnMeleeBegin;
	
	UPROPERTY(BlueprintAssignable)
	FOnMeleeEndSignature OnMeleeEnd;

};
