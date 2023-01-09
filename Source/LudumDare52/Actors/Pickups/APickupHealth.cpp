// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.


#include "APickupHealth.h"

#include "LudumDare52/Components/HitPointsComponent.h"


AAPickupHealth::AAPickupHealth()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AAPickupHealth::BeginPlay()
{
	Super::BeginPlay();
}

bool AAPickupHealth::PickupEffect_Implementation(AActor* OtherActor)
{
	if (!IsValid(OtherActor))
	{
		return false;
	}

	UHitPointsComponent* HitPointsComponent = OtherActor->FindComponentByClass<UHitPointsComponent>();

	if (!HitPointsComponent)
	{
		return false;
	}

	if (HitPointsComponent->GetValue() == HitPointsComponent->GetMaxValue())
	{
		return false;
	}
	HitPointsComponent->IncreaseValue(1, true);
	return true;
}

void AAPickupHealth::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
