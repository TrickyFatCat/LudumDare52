// MIT License Copyright (c) 2022 Artyom "Tricky Fat Cat" Volkov


#include "CapsuleInteractionComponent.h"

UCapsuleInteractionComponent::UCapsuleInteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	UPrimitiveComponent::SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	UPrimitiveComponent::SetCollisionObjectType(ECC_WorldDynamic);
	UPrimitiveComponent::SetCollisionResponseToAllChannels(ECR_Ignore);
	UPrimitiveComponent::SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
}

void UCapsuleInteractionComponent::SetInteractionData(const FInteractionData& Value)
{
	InteractionData = Value;
}

void UCapsuleInteractionComponent::SetInteractionMessage(AActor* Actor, const FString& Message)
{
	InteractionData.InteractionMessage = Message;
	UInteractionLibrary::UpdateInteractionMessage(Actor, GetOwner(), Message);
}

FInteractionData UCapsuleInteractionComponent::GetInteractionData() const
{
	return InteractionData;
}

void UCapsuleInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	OnComponentBeginOverlap.AddDynamic(this, &UCapsuleInteractionComponent::OnBeginOverlap);
	OnComponentEndOverlap.AddDynamic(this, &UCapsuleInteractionComponent::OnEndOverlap);
}

void UCapsuleInteractionComponent::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent,
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

	if (UInteractionLibrary::AddToInteractionQueue(OtherActor, GetOwner(), InteractionData))
	{
		OnActorAdded.Broadcast(OtherActor);
	}
}

void UCapsuleInteractionComponent::OnEndOverlap(UPrimitiveComponent* OverlappedComponent,
                                                AActor* OtherActor,
                                                UPrimitiveComponent* OtherComp,
                                                int32 OtherBodyIndex)
{
	if (!IsValid(OtherActor))
	{
		return;
	}

	if (UInteractionLibrary::RemoveFromInteractionQueue(OtherActor, GetOwner()))
	{
		OnActorRemoved.Broadcast(OtherActor);
	}
}