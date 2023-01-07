// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.


#include "DeathComponent.h"

#include "GameFramework/Character.h"
#include "LudumDare52/Animation/AnimUtils.h"
#include "LudumDare52/Animation/DeathFinishedNotify.h"


UDeathComponent::UDeathComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UDeathComponent::BeginPlay()
{
	Super::BeginPlay();

	UDeathFinishedNotify* DeathFinishedNotify = UAnimUtils::FindFirstNotifyByClass<UDeathFinishedNotify>(DeathMontage);

	if (DeathFinishedNotify)
	{
		DeathFinishedNotify->OnNotified.AddUObject(this, &UDeathComponent::HandleDeathFinish);
	}
}

void UDeathComponent::StartDeath() const
{
	ACharacter* Character = Cast<ACharacter>(GetOwner());

	if (IsValid(Character) && DeathMontage)
	{
		Character->PlayAnimMontage(DeathMontage);
		OnDeathStarted.Broadcast();
	}
}

void UDeathComponent::HandleDeathFinish(USkeletalMeshComponent* SkeletalMeshComponent) const
{
	OnDeathFinished.Broadcast();
}

