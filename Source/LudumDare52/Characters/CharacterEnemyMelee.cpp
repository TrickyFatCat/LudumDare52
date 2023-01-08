// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.


#include "CharacterEnemyMelee.h"

#include "LudumDare52/Components/DamageTriggerComponent.h"
#include "LudumDare52/Components/Attacks/MeleeAttackComponent.h"


ACharacterEnemyMelee::ACharacterEnemyMelee()
{
	PrimaryActorTick.bCanEverTick = true;

	MeleeAttackComponent = CreateDefaultSubobject<UMeleeAttackComponent>("MeleeAttack");
	DamageTriggerComponent = CreateDefaultSubobject<UDamageTriggerComponent>("DamageTrigger");
	DamageTriggerComponent->SetupAttachment(GetRootComponent());
}

void ACharacterEnemyMelee::BeginPlay()
{
	Super::BeginPlay();
	MeleeAttackComponent->OnAttackStarted.AddDynamic(this, &ACharacterEnemyMelee::EnterAttackState);
	MeleeAttackComponent->OnAttackFinished.AddDynamic(this, &ACharacterEnemyMelee::ExitAttackState);
	MeleeAttackComponent->OnMeleeBegin.AddDynamic(this, &ACharacterEnemyMelee::HandleAttackBegin);
	MeleeAttackComponent->OnMeleeEnd.AddDynamic(this, &ACharacterEnemyMelee::HandleAttackEnd);
}

void ACharacterEnemyMelee::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACharacterEnemyMelee::HandleAttackBeginOverlap(UPrimitiveComponent* OverlappedComponent,
                                                    AActor* OtherActor,
                                                    UPrimitiveComponent* OtherComp,
                                                    int32 OtherBodyIndex,
                                                    bool bFromSweep,
                                                    const FHitResult& SweepResult)
{
	Super::HandleAttackBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	StartAutoAttack(MeleeAttackComponent);
}

void ACharacterEnemyMelee::HandleAttackEndOverlap(UPrimitiveComponent* OverlappedComponent,
                                                  AActor* OtherActor,
                                                  UPrimitiveComponent* OtherComp,
                                                  int32 OtherBodyIndex)
{
	Super::HandleAttackEndOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
	StopAutoAttack(MeleeAttackComponent);
}

void ACharacterEnemyMelee::HandleAttackBegin()
{
	DamageTriggerComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
}

void ACharacterEnemyMelee::HandleAttackEnd()
{
	DamageTriggerComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}


