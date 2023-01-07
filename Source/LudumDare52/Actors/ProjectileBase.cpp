// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.


#include "ProjectileBase.h"

#include "GameFramework/ProjectileMovementComponent.h"
#include "LudumDare52/Components/DamageTriggerComponent.h"


AProjectileBase::AProjectileBase()
{
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovement");
	DamageTriggerComponent = CreateDefaultSubobject<UDamageTriggerComponent>("DamageTriggerComponent");
	DamageTriggerComponent->SetupAttachment(GetRootComponent());
}

void AProjectileBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AProjectileBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

