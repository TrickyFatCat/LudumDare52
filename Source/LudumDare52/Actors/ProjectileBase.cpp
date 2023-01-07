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
	InitialLifeSpan = 1.f;
}

void AProjectileBase::BeginPlay()
{
	Super::BeginPlay();

	DamageTriggerComponent->OnComponentBeginOverlap.AddDynamic(this, &AProjectileBase::HandleProjectileHit);
}

void AProjectileBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AProjectileBase::HandleProjectileHit(UPrimitiveComponent* OverlappedComponent,
                                          AActor* OtherActor,
                                          UPrimitiveComponent* OtherComp,
                                          int32 OtherBodyIndex,
                                          bool bFromSweep,
                                          const FHitResult& SweepResult)
{
	Destroy();
}
