// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.


#include "CharacterEnemyRanged.h"

#include "LudumDare52/Components/Attacks/RangedAttackComponent.h"


ACharacterEnemyRanged::ACharacterEnemyRanged()
{
	PrimaryActorTick.bCanEverTick = true;

	RangedAttackComponent = CreateDefaultSubobject<URangedAttackComponent>("RangedAttack");
}

void ACharacterEnemyRanged::BeginPlay()
{

	Super::BeginPlay();
	RangedAttackComponent->OnAttackStarted.AddDynamic(this, &ACharacterEnemyRanged::EnterAttackState);
	RangedAttackComponent->OnAttackFinished.AddDynamic(this, &ACharacterEnemyRanged::ExitAttackState);
}

void ACharacterEnemyRanged::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACharacterEnemyRanged::HandleDeathStart()
{
	Super::HandleDeathStart();

	RangedAttackComponent->StopAutoAttack();
}

void ACharacterEnemyRanged::HandleAttackBeginOverlap(UPrimitiveComponent* OverlappedComponent,
                                                     AActor* OtherActor,
                                                     UPrimitiveComponent* OtherComp,
                                                     int32 OtherBodyIndex,
                                                     bool bFromSweep,
                                                     const FHitResult& SweepResult)
{
	Super::HandleAttackBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep,
	                                SweepResult);
	RangedAttackComponent->StartAutoAttack();
}

void ACharacterEnemyRanged::HandleAttackEndOverlap(UPrimitiveComponent* OverlappedComponent,
                                                   AActor* OtherActor,
                                                   UPrimitiveComponent* OtherComp,
                                                   int32 OtherBodyIndex)
{
	Super::HandleAttackEndOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);

	RangedAttackComponent->StopAutoAttack();
}
