// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "CharacterEnemy.h"
#include "GameFramework/Actor.h"
#include "CharacterEnemyMelee.generated.h"

class UDamageTriggerComponent;
class UMeleeAttackComponent;

UCLASS()
class LUDUMDARE52_API ACharacterEnemyMelee : public ACharacterEnemy
{
	GENERATED_BODY()

public:
	ACharacterEnemyMelee();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Components")
	UMeleeAttackComponent* MeleeAttackComponent = nullptr;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Components")
	UDamageTriggerComponent* DamageTriggerComponent = nullptr;

	virtual void HandleAttackBeginOverlap(UPrimitiveComponent* OverlappedComponent,
	                                      AActor* OtherActor,
	                                      UPrimitiveComponent* OtherComp,
	                                      int32 OtherBodyIndex,
	                                      bool bFromSweep,
	                                      const FHitResult& SweepResult) override;

	virtual void HandleAttackEndOverlap(UPrimitiveComponent* OverlappedComponent,
	                                    AActor* OtherActor,
	                                    UPrimitiveComponent* OtherComp,
	                                    int32 OtherBodyIndex) override;
	UFUNCTION()
	void HandleAttackBegin();

	UFUNCTION()
	void HandleAttackEnd();

	virtual void HandleDeathStart() override;
};
