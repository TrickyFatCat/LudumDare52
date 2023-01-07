// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "PickupNormal.h"
#include "PickupPhylactery.generated.h"

UCLASS()
class LUDUMDARE52_API APickupPhylactery : public APickupNormal 
{
	GENERATED_BODY()

public:
	APickupPhylactery();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual bool PickupEffect_Implementation(AActor* OtherActor) override;
};
