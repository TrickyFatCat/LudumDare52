// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/SimpleResourceComponent.h"
#include "HitPointsComponent.generated.h"

class UDamageType;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class LUDUMDARE52_API UHitPointsComponent : public USimpleResourceComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Resource")
	TSet<TSubclassOf<UDamageType>> Immunities;
	
	UFUNCTION(BlueprintCallable)
	void ApplyDamage(const int32 Amount, TSubclassOf<UDamageType> DamageType);
};
