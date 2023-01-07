// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.


#include "MeleeTriggerComponent.h"

#include "HitPointsComponent.h"

void UMeleeTriggerComponent::BeginPlay()
{
	Super::BeginPlay();

	OnComponentBeginOverlap.AddDynamic(this, &UMeleeTriggerComponent::UMeleeTriggerComponent::HandleBeginOverlap);
}

void UMeleeTriggerComponent::HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent,
                                                AActor* OtherActor,
                                                UPrimitiveComponent* OtherComp,
                                                int32 OtherBodyIndex,
                                                bool bFromSweep,
                                                const FHitResult& SweepResult)
{
	if (!IsValid(OtherActor))
	{
		return;
	}

	UHitPointsComponent* HitPointsComponent = OtherActor->FindComponentByClass<UHitPointsComponent>();

	if (HitPointsComponent)
	{
		HitPointsComponent->ApplyDamage(Damage, DamageType);
	}
}
