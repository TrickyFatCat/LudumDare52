// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "CharacterEnemy.h"
#include "GameFramework/Actor.h"
#include "CharacterEnemyRanged.generated.h"

class URangedAttackComponent;

UCLASS()
class LUDUMDARE52_API ACharacterEnemyRanged : public ACharacterEnemy
{
	GENERATED_BODY()

public:
	ACharacterEnemyRanged();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Components")
	URangedAttackComponent* RangedAttackComponent = nullptr;

	virtual void HandleDeathStart() override;

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
};
