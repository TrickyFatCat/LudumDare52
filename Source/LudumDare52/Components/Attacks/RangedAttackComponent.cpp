// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.


#include "RangedAttackComponent.h"

#include "LudumDare52/Animation/AnimUtils.h"
#include "LudumDare52/Animation/SpawnProjectileNotify.h"


void URangedAttackComponent::BeginPlay()
{
	Super::BeginPlay();

	for (const auto& AttackMontage : AttackMontages)
	{
		if (!AttackMontage)
		{
			continue;
		}

		USpawnProjectileNotify* SpawnProjectileNotify = UAnimUtils::FindFirstNotifyByClass<USpawnProjectileNotify>(AttackMontage);

		if (SpawnProjectileNotify)
		{
			SpawnProjectileNotify->OnNotified.AddUObject(this, &URangedAttackComponent::HandleProjectileSpawn);
		}
	}
}

void URangedAttackComponent::HandleProjectileSpawn(USkeletalMeshComponent* SkeletalMeshComponent) const
{
	OnProjectileSpawned.Broadcast();
}
