// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.


#include "DamageTriggerComponent.h"

#include "HitPointsComponent.h"
#include "GameFramework/Character.h"

void UDamageTriggerComponent::BeginPlay()
{
	Super::BeginPlay();

	OnComponentBeginOverlap.AddDynamic(this, &UDamageTriggerComponent::UDamageTriggerComponent::HandleBeginOverlap);
}

void UDamageTriggerComponent::HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent,
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

	if (!HitPointsComponent)
	{
		return;
	}

	HitPointsComponent->ApplyDamage(Damage, DamageType);

	if (bLaunchCharacter)
	{
		ACharacter* Character = Cast<ACharacter>(OtherActor);

		if (Character)
		{
			const FVector LaunchDirection = (Character->GetActorLocation() - GetOwner()->GetActorLocation()).
			                                GetUnsafeNormal().
			                                GetSignVector();
			const FVector LaunchVelocity {LaunchDirection.X * LaunchPower.X, LaunchDirection.Y * LaunchPower.Y, LaunchPower.Z};
			Character->LaunchCharacter(LaunchVelocity, true, true);
		}
	}
}
