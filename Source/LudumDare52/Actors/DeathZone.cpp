// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.


#include "DeathZone.h"

#include "Components/BoxComponent.h"
#include "LudumDare52/Components/HitPointsComponent.h"


ADeathZone::ADeathZone()
{
	PrimaryActorTick.bCanEverTick = true;

	TriggerComponent = CreateDefaultSubobject<UBoxComponent>("DeathTrigger");
	SetRootComponent(TriggerComponent);
}

void ADeathZone::BeginPlay()
{
	Super::BeginPlay();

	TriggerComponent->OnComponentBeginOverlap.AddDynamic(this, &ADeathZone::HandleOnBeginOverlap);
}

void ADeathZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADeathZone::HandleOnBeginOverlap(UPrimitiveComponent* OverlappedComponent,
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
		HitPointsComponent->ApplyDamage(HitPointsComponent->GetValue(), nullptr);
	}
}
