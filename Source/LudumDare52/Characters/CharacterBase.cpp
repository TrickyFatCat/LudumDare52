// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.


#include "CharacterBase.h"

#include "LudumDare52/Components/HitPointsComponent.h"
#include "LudumDare52/Components/Attacks/AttackComponent.h"


ACharacterBase::ACharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

	constexpr FSimpleResourceData DefaultData{1, 1};
	HitPointsComponent = CreateDefaultSubobject<UHitPointsComponent>("HitPoints");
	HitPointsComponent->SetResourceDate(DefaultData);
}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ACharacterBase::FinishAttack()
{
	bIsAttacking = false;
}

void ACharacterBase::DecreaseHitPoints(const int32 Amount)
{
	HitPointsComponent->DecreaseValue(Amount);
}
