// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.


#include "MeleeAttackComponent.h"

#include "LudumDare52/Animation/AnimUtils.h"
#include "LudumDare52/Animation/MeleeBeginNotify.h"
#include "LudumDare52/Animation/MeleeEndNotify.h"

void UMeleeAttackComponent::BeginPlay()
{
	Super::BeginPlay();

	for (const auto& AttackMontage : AttackMontages)
	{
		UMeleeBeginNotify* MeleeBeginNotify = UAnimUtils::FindFirstNotifyByClass<UMeleeBeginNotify>(AttackMontage);
		
		if (MeleeBeginNotify)
		{
			MeleeBeginNotify->OnNotified.AddUObject(this, &UMeleeAttackComponent::HandleMeleeBegin);
		}

		UMeleeEndNotify* MeleeEndNotify = UAnimUtils::FindFirstNotifyByClass<UMeleeEndNotify>(AttackMontage);

		if (MeleeEndNotify)
		{
			MeleeEndNotify->OnNotified.AddUObject(this, &UMeleeAttackComponent::HandleMeleeEnd);
		}
	}
}

void UMeleeAttackComponent::HandleMeleeBegin(USkeletalMeshComponent* SkeletalMeshComponent)
{
	OnMeleeBegin.Broadcast();
}

void UMeleeAttackComponent::HandleMeleeEnd(USkeletalMeshComponent* SkeletalMeshComponent)
{
	OnMeleeEnd.Broadcast();
}
