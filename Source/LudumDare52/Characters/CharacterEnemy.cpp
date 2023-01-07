// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.


#include "CharacterEnemy.h"

#include "CharacterPlayer.h"
#include "Kismet/GameplayStatics.h"


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

