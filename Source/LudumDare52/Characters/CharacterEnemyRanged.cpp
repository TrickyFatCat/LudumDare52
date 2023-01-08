// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.


#include "CharacterEnemyRanged.h"


// Sets default values
ACharacterEnemyRanged::ACharacterEnemyRanged()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACharacterEnemyRanged::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacterEnemyRanged::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

