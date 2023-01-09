// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "PickupNormal.h"
#include "GameFramework/Actor.h"
#include "APickupHealth.generated.h"

UCLASS()
class LUDUMDARE52_API AAPickupHealth : public APickupNormal
{
	GENERATED_BODY()

public:
	AAPickupHealth();

protected:
	virtual void BeginPlay() override;

	virtual bool PickupEffect_Implementation(AActor* OtherActor) override;

public:
	virtual void Tick(float DeltaTime) override;
	
};
