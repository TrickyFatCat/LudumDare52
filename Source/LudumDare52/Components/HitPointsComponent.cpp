// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.


#include "HitPointsComponent.h"

void UHitPointsComponent::ApplyDamage(const int32 Amount, TSubclassOf<UDamageType> DamageType)
{
	if (Immunities.Contains(DamageType))
	{
		return;
	}

	DecreaseValue(Amount);
}
