// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.


#include "PickupCoin.h"

#include "Components/SimpleResourceComponent.h"
#include "Kismet/GameplayStatics.h"
#include "LudumDare52/Characters/CharacterPlayer.h"
#include "LudumDare52/Components/CoinsCounterComponent.h"

APickupCoin::APickupCoin()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APickupCoin::BeginPlay()
{
	Super::BeginPlay();

	const ACharacterPlayer* PlayerCharacter = Cast<ACharacterPlayer>(UGameplayStatics::GetPlayerCharacter(this, 0));

	if (IsValid(PlayerCharacter))
	{
		PlayerCharacter->IncrementMaxCoins(CoinsAmount);
	}
}

void APickupCoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool APickupCoin::PickupEffect_Implementation(AActor* OtherActor)
{
	if (!IsValid(OtherActor))
	{
		return false;
	}

	UCoinsCounterComponent* CoinsCounterComponent = OtherActor->FindComponentByClass<UCoinsCounterComponent>();

	if (!CoinsCounterComponent)
	{
		return false;
	}

	CoinsCounterComponent->IncreaseValue(CoinsAmount, false);
	return true;
}

