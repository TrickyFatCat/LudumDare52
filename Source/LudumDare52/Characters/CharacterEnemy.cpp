// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.


#include "CharacterEnemy.h"

#include "CharacterPlayer.h"
#include "Components/CapsuleComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "LudumDare52/Components/FocusComponent.h"
#include "LudumDare52/Components/HitPointsComponent.h"
#include "LudumDare52/Components/SoulsCounterComponent.h"


ACharacterEnemy::ACharacterEnemy()
{
	PrimaryActorTick.bCanEverTick = true;

	AttackTriggerComponent = CreateDefaultSubobject<USphereComponent>("AttackTrigger");
	AttackTriggerComponent->SetupAttachment(GetRootComponent());
	FocusComponent = CreateDefaultSubobject<UFocusComponent>("AttentionTrigger");
	FocusComponent->SetupAttachment(GetRootComponent());
}

void ACharacterEnemy::BeginPlay()
{
	Super::BeginPlay();

	const ACharacterPlayer* PlayerCharacter = Cast<ACharacterPlayer>(UGameplayStatics::GetPlayerCharacter(this, 0));

	if (IsValid(PlayerCharacter))
	{
		PlayerCharacter->IncrementMaxSouls(1);
	}

	AttackTriggerComponent->OnComponentBeginOverlap.AddDynamic(this, &ACharacterEnemy::HandleAttackBeginOverlap);
	AttackTriggerComponent->OnComponentEndOverlap.AddDynamic(this, &ACharacterEnemy::HandleAttackEndOverlap);
	FocusComponent->OnComponentBeginOverlap.AddDynamic(this, &ACharacterEnemy::HandleAttentionBeginOverlap);
	FocusComponent->OnComponentEndOverlap.AddDynamic(this, &ACharacterEnemy::HandleAttentionEndOverlap);
	HitPointsComponent->OnResourceValueZero.AddDynamic(FocusComponent, &UFocusComponent::StopFocusing);
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

	USoulsCounterComponent* SoulsCounterComponent = PlayerCharacter->FindComponentByClass<USoulsCounterComponent>();

	if (SoulsCounterComponent)
	{
		SoulsCounterComponent->IncreaseValue(1, true);
	}
}

void ACharacterEnemy::StartAutoAttack(UAttackComponent* AttackComponent)
{
	if (bIsAttacking)
	{
		return;
	}

	AttackComponent->StartAutoAttack();
	EnterAttackState();
}

void ACharacterEnemy::StopAutoAttack(UAttackComponent* AttackComponent)
{
	AttackComponent->StopAutoAttack();
}

void ACharacterEnemy::EnterAttackState()
{ 
	bIsAttacking = true;
	FocusComponent->StopFocusing();
}

void ACharacterEnemy::ExitAttackState()
{
	// FinishAttack();
	bIsAttacking = false;
	FocusComponent->StartFocusing();
}

void ACharacterEnemy::HandleAttackBeginOverlap(UPrimitiveComponent* OverlappedComponent,
                                               AActor* OtherActor,
                                               UPrimitiveComponent* OtherComp,
                                               int32 OtherBodyIndex,
                                               bool bFromSweep,
                                               const FHitResult& SweepResult)
{
}

void ACharacterEnemy::HandleAttackEndOverlap(UPrimitiveComponent* OverlappedComponent,
                                             AActor* OtherActor,
                                             UPrimitiveComponent* OtherComp,
                                             int32 OtherBodyIndex)
{
}

void ACharacterEnemy::HandleAttentionBeginOverlap(UPrimitiveComponent* OverlappedComponent,
                                                  AActor* OtherActor,
                                                  UPrimitiveComponent* OtherComp,
                                                  int32 OtherBodyIndex,
                                                  bool bFromSweep,
                                                  const FHitResult& SweepResult)
{
}

void ACharacterEnemy::HandleAttentionEndOverlap(UPrimitiveComponent* OverlappedComponent,
                                                AActor* OtherActor,
                                                UPrimitiveComponent* OtherComp,
                                                int32 OtherBodyIndex)
{
}
