// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.


#include "FocusComponent.h"

#include "Kismet/KismetMathLibrary.h"

UFocusComponent::UFocusComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UFocusComponent::BeginPlay()
{
	Super::BeginPlay();

	OnComponentBeginOverlap.AddDynamic(this, &UFocusComponent::HandleBeginOverlap);
	OnComponentEndOverlap.AddDynamic(this, &UFocusComponent::HandleEndOverlap);
}

void UFocusComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (bIsFocusing && TargetActor)
	{
		const FVector Location = GetOwner()->GetActorLocation();
		const FVector TargetLocation = TargetActor->GetActorLocation();
		const FRotator Rotation = GetOwner()->GetActorRotation();
		const FRotator TargetRotation = UKismetMathLibrary::FindLookAtRotation(Location, TargetLocation);
		const FRotator NewRotation = FMath::RInterpTo(Rotation, TargetRotation, DeltaTime, RotationSpeed);
		GetOwner()->SetActorRotation(FRotator{NewRotation.Pitch, NewRotation.Yaw, NewRotation.Roll});
	}
}

void UFocusComponent::StartFocusing()
{
	if (!IsValid(TargetActor))
	{
		return;
	}

	bIsFocusing = true;
}

void UFocusComponent::StopFocusing()
{
	bIsFocusing = false;
}

void UFocusComponent::HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent,
                                         AActor* OtherActor,
                                         UPrimitiveComponent* OtherComp,
                                         int32 OtherBodyIndex,
                                         bool bFromSweep,
                                         const FHitResult& SweepResult)
{
	TargetActor = OtherActor;
	StartFocusing();
}

void UFocusComponent::HandleEndOverlap(UPrimitiveComponent* OverlappedComponent,
                                       AActor* OtherActor,
                                       UPrimitiveComponent* OtherComp,
                                       int32 OtherBodyIndex)
{
	TargetActor = nullptr;
	StopFocusing();
}
