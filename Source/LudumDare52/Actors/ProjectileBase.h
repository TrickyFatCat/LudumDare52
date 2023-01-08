// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileBase.generated.h"

class UProjectileMovementComponent;
class UDamageTriggerComponent;

UCLASS()
class LUDUMDARE52_API AProjectileBase : public AActor
{
	GENERATED_BODY()

public:
	AProjectileBase();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Components")
	UProjectileMovementComponent* ProjectileMovementComponent = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Components")
	UDamageTriggerComponent* DamageTriggerComponent = nullptr;

	UPROPERTY(EditDefaultsOnly)
	float MaxDistance = 1024.f;

	FVector InitialLocation{FVector::ZeroVector};

	UFUNCTION()
	void HandleProjectileBeginOverlap(UPrimitiveComponent* OverlappedComponent,
	                                  AActor* OtherActor,
	                                  UPrimitiveComponent* OtherComp,
	                                  int32 OtherBodyIndex,
	                                  bool bFromSweep,
	                                  const FHitResult& SweepResult);

	UFUNCTION()
	void HandleProjectileHit(UPrimitiveComponent* HitComponent,
	                         AActor* OtherActor,
	                         UPrimitiveComponent* OtherComp,
	                         FVector NormalImpulse,
	                         const FHitResult& Hit);
};
