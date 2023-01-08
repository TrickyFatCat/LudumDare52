// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DeathZone.generated.h"

class UBoxComponent;

UCLASS(Blueprintable, BlueprintType)
class LUDUMDARE52_API ADeathZone : public AActor
{
	GENERATED_BODY()

public:
	ADeathZone();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Components")
	UBoxComponent* TriggerComponent;

	UFUNCTION()
	void HandleOnBeginOverlap(UPrimitiveComponent* OverlappedComponent,
	                          AActor* OtherActor,
	                          UPrimitiveComponent* OtherComp,
	                          int32 OtherBodyIndex,
	                          bool bFromSweep,
	                          const FHitResult& SweepResult);
};
