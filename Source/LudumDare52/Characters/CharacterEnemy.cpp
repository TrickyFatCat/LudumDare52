// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.


#include "CharacterEnemy.h"

#include "CharacterPlayer.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "LudumDare52/Components/HitPointsComponent.h"
#include "LudumDare52/Components/SoulsCounterComponent.h"


ACharacterEnemy::ACharacterEnemy()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACharacterEnemy::BeginPlay()
{
	Super::BeginPlay();

	const ACharacterPlayer* PlayerCharacter = Cast<ACharacterPlayer>(UGameplayStatics::GetPlayerCharacter(this, 0));

	if (IsValid(PlayerCharacter))
	{
		PlayerCharacter->IncrementMaxSouls(1);
	}

}

void ACharacterEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACharacterEnemy::HandleDeathStart()
{
	Super::HandleDeathStart();

	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	const ACharacterPlayer* PlayerCharacter = Cast<ACharacterPlayer>(UGameplayStatics::GetPlayerCharacter(this, 0));

	if (!IsValid(PlayerCharacter))
	{
		return;
	}

	USoulsCounterComponent* SoulsCounterComponent= PlayerCharacter->FindComponentByClass<USoulsCounterComponent>();

	if (SoulsCounterComponent)
	{
		SoulsCounterComponent->IncreaseValue(1, true);
	}
}

