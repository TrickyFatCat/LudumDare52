// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.


#include "PickupPhylactery.h"

#include "Kismet/GameplayStatics.h"
#include "LudumDare52/Characters/CharacterPlayer.h"
#include "LudumDare52/Components/PhylacteriesCounterComponent.h"


APickupPhylactery::APickupPhylactery()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APickupPhylactery::BeginPlay()
{
	Super::BeginPlay();

	const ACharacterPlayer* PlayerCharacter = Cast<ACharacterPlayer>(UGameplayStatics::GetPlayerCharacter(this, 0));

	if (IsValid(PlayerCharacter))
	{
		PlayerCharacter->IncrementMaxPhylacteries(1);	
	}
}

void APickupPhylactery::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool APickupPhylactery::PickupEffect_Implementation(AActor* OtherActor)
{
	if (!IsValid(OtherActor))
	{
		return false;
	}

	UPhylacteriesCounterComponent* PhylacteriesCounterComponent = OtherActor->FindComponentByClass<UPhylacteriesCounterComponent>();

	if (!PhylacteriesCounterComponent)
	{
		return false;
	}

	PhylacteriesCounterComponent->IncreaseValue(1, false);
	return true;
}
