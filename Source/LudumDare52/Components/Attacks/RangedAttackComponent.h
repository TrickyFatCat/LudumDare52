// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttackComponent.h"
#include "Components/ActorComponent.h"
#include "RangedAttackComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnProcjectileSpawnedSignature);

class USkeletalMeshComponent;
class AProjectileBase;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class LUDUMDARE52_API URangedAttackComponent : public UAttackComponent 
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(BlueprintAssignable)
	FOnProcjectileSpawnedSignature OnProjectileSpawned;

	UFUNCTION()
	void HandleProjectileSpawn(USkeletalMeshComponent* SkeletalMeshComponent);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<AProjectileBase> ProjectileClass = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName SpawnSocketName = NAME_None;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool bUseForwardVector = false;
};
