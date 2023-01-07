// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.


#include "RangedAttackComponent.h"

#include "Kismet/GameplayStatics.h"
#include "LudumDare52/Actors/ProjectileBase.h"
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

		USpawnProjectileNotify* SpawnProjectileNotify = UAnimUtils::FindFirstNotifyByClass<USpawnProjectileNotify>(
			AttackMontage);

		if (SpawnProjectileNotify)
		{
			SpawnProjectileNotify->OnNotified.AddUObject(this, &URangedAttackComponent::HandleProjectileSpawn);
		}
	}
}

void URangedAttackComponent::HandleProjectileSpawn(USkeletalMeshComponent* SkeletalMeshComponent)
{
	if (!SkeletalMeshComponent || !ProjectileClass)
	{
		return;
	}
	OnProjectileSpawned.Broadcast();

	FTransform SpawnTransform;
	SpawnTransform.SetLocation(SkeletalMeshComponent->GetSocketLocation(SpawnSocketName));
	SpawnTransform.SetRotation(FQuat(SkeletalMeshComponent->GetSocketRotation(SpawnSocketName)));
	// SpawnTransform.SetRotation(FQuat(SkeletalMeshComponent->GetOwner()->GetActorForwardVector().Rotation()));
	GetWorld()->SpawnActor<AProjectileBase>(ProjectileClass, SpawnTransform);
}
