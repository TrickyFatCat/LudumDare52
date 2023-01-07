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

	DamageTriggerComponent->OnComponentHit.AddDynamic(this, &AProjectileBase::HandleProjectileHit);
	InitialLocation = GetActorLocation();
}

void AProjectileBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const FVector Difference = InitialLocation - GetActorLocation();

	if (Difference.Size() >= MaxDistance)
	{
		Destroy();
	}
}

void AProjectileBase::HandleProjectileHit(UPrimitiveComponent* HitComponent,
                                          AActor* OtherActor,
                                          UPrimitiveComponent* OtherComp,
                                          FVector NormalImpulse,
                                          const FHitResult& Hit)
{
	Destroy();
}