// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.


#include "AttackComponent.h"

#include "GameFramework/Character.h"
#include "LudumDare52/Animation/AnimUtils.h"
#include "LudumDare52/Animation/FinishAttackNotify.h"


UAttackComponent::UAttackComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAttackComponent::BeginPlay()
{
	Super::BeginPlay();

	Character = Cast<ACharacter>(GetOwner());

	if (AttackMontages.Num() == 0)
	{
		return;
	}

	for (const auto& AttackMontage : AttackMontages)
	{
		if (!AttackMontage)
		{
			continue;
		}
		UFinishAttackNotify* FinishAttackNotify = UAnimUtils::FindFirstNotifyByClass<UFinishAttackNotify>(
			AttackMontage);

		if (FinishAttackNotify)
		{
			FinishAttackNotify->OnNotified.AddUObject(this, &UAttackComponent::FinishAttack);
		}
	}
}

void UAttackComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UAttackComponent::StartAttack()
{
	if (!Character || AttackMontages.Num() == 0)
	{
		return;
	}

	UAnimMontage* AttackMontage = AttackMontages[CurrentIndex];

	if (!AttackMontage)
	{
		return;
	}

	Character->PlayAnimMontage(AttackMontage);
	OnAttackStarted.Broadcast();
}

void UAttackComponent::FinishAttack(USkeletalMeshComponent* SkeletalMeshComponent)
{
	CurrentIndex++;
	CurrentIndex = CurrentIndex == AttackMontages.Num() ? 0 : CurrentIndex;

	OnAttackFinished.Broadcast();
}
