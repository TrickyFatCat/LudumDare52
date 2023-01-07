// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.


#include "AttackComponent.h"

#include "GameFramework/Character.h"
#include "LudumDare52/Animation/FinishAttackNotify.h"


UAttackComponent::UAttackComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UAttackComponent::BeginPlay()
{
	Super::BeginPlay();

	Character = Cast<ACharacter>(GetOwner());

	UFinishAttackNotify* FinishAttackNotify = UFinishAttackNotify::FindFirstNotifyByClass<
		UFinishAttackNotify>(AnimMontage);

	if (FinishAttackNotify)
	{
		FinishAttackNotify->OnNotified.AddUObject(this, &UAttackComponent::FinishAttack);
	}
}

void UAttackComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UAttackComponent::StartAttack()
{
	if (!Character)
	{
		return;
	}

	Character->PlayAnimMontage(AnimMontage);
	OnAttackStarted.Broadcast();
}

void UAttackComponent::FinishAttack()
{
	OnAttackFinished.Broadcast();
}