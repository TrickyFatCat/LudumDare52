// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "CharacterBase.h"
#include "LudumDare52/Components/Attacks/AttackComponent.h"
#include "CharacterEnemy.generated.h"

class USphereComponent;
class UFocusComponent;

UCLASS()
class LUDUMDARE52_API ACharacterEnemy : public ACharacterBase
{
	GENERATED_BODY()

public:
	ACharacterEnemy();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Components")
	UFocusComponent* FocusComponent = nullptr;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Components")
	USphereComponent* AttackTriggerComponent = nullptr;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void HandleDeathStart() override;

	UFUNCTION(BlueprintCallable)
	void StartAutoAttack(UAttackComponent* AttackComponent);

	UFUNCTION(BlueprintCallable)
	void StopAutoAttack(UAttackComponent* AttackComponent);

	UFUNCTION()
	virtual void HandleAttackBeginOverlap(UPrimitiveComponent* OverlappedComponent,
	                                      AActor* OtherActor,
	                                      UPrimitiveComponent* OtherComp,
	                                      int32 OtherBodyIndex,
	                                      bool bFromSweep,
	                                      const FHitResult& SweepResult);

	UFUNCTION()
	virtual void HandleAttackEndOverlap(UPrimitiveComponent* OverlappedComponent,
	                                    AActor* OtherActor,
	                                    UPrimitiveComponent* OtherComp,
	                                    int32 OtherBodyIndex);

	UFUNCTION()
	void HandleAttentionBeginOverlap(UPrimitiveComponent* OverlappedComponent,
	                                         AActor* OtherActor,
	                                         UPrimitiveComponent* OtherComp,
	                                         int32 OtherBodyIndex,
	                                         bool bFromSweep,
	                                         const FHitResult& SweepResult);

	UFUNCTION()
	void HandleAttentionEndOverlap(UPrimitiveComponent* OverlappedComponent,
	                                       AActor* OtherActor,
	                                       UPrimitiveComponent* OtherComp,
	                                       int32 OtherBodyIndex);
};
