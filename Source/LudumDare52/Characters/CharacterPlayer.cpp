// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.


#include "CharacterPlayer.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SimpleResourceComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "LudumDare52/Components/CoinsCounterComponent.h"
#include "LudumDare52/Components/MeleeTriggerComponent.h"
#include "LudumDare52/Components/PhylacteriesCounterComponent.h"
#include "LudumDare52/Components/SoulsCounterComponent.h"
#include "LudumDare52/Components/Attacks/AttackComponent.h"
#include "LudumDare52/Components/Attacks/MeleeAttackComponent.h"


ACharacterPlayer::ACharacterPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->bUsePawnControlRotation = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera");
	CameraComponent->SetupAttachment(SpringArmComponent);

	constexpr FSimpleResourceData DefaultCountersData{0, 0, true, 0};
	SoulsCounterComponent = CreateDefaultSubobject<USoulsCounterComponent>("SoulsCounter");
	SoulsCounterComponent->SetResourceDate(DefaultCountersData);
	PhylacteryCounterComponent = CreateDefaultSubobject<UPhylacteriesCounterComponent>("PhylacteryCounter");
	PhylacteryCounterComponent->SetResourceDate(DefaultCountersData);
	CoinsCounterComponent = CreateDefaultSubobject<UCoinsCounterComponent>("CoinsCounter");
	CoinsCounterComponent->SetResourceDate(DefaultCountersData);

	MeleeAttackComponent = CreateDefaultSubobject<UMeleeAttackComponent>("MeleeAttack");

	MeleeTriggerComponent = CreateDefaultSubobject<UMeleeTriggerComponent>("MeleeTrigger");
	MeleeTriggerComponent->SetupAttachment(GetRootComponent());

	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 256.f, 0.f);
}

void ACharacterPlayer::BeginPlay()
{
	Super::BeginPlay();

	MeleeAttackComponent->OnAttackFinished.AddDynamic(this, &ACharacterPlayer::FinishAttack); 
}

void ACharacterPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACharacterPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ACharacterPlayer::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACharacterPlayer::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &ACharacterPlayer::LookUp);
	PlayerInputComponent->BindAxis("LookRight", this, &ACharacterPlayer::LookRight);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacterPlayer::Jump);
	PlayerInputComponent->BindAction("MeleeAttack", IE_Pressed, this, &ACharacterPlayer::StartMeleeAttack);
}

void ACharacterPlayer::MoveForward(const float AxisValue)
{
	const FRotator Rotation = GetCapsuleComponent()->GetComponentRotation();
	const FRotator NewYawRotation(0.f, Rotation.Yaw, 0.f);
	const FVector Direction = UKismetMathLibrary::GetForwardVector(NewYawRotation);
	AddMovementInput(Direction, AxisValue);
}

void ACharacterPlayer::MoveRight(const float AxisValue)
{
	const FRotator Rotation = GetCapsuleComponent()->GetComponentRotation();
	const FRotator NewYawRotation(0.f, Rotation.Yaw, 0.f);
	const FVector Direction = UKismetMathLibrary::GetRightVector(NewYawRotation);
	AddMovementInput(Direction, AxisValue);
}

void ACharacterPlayer::LookUp(const float AxisValue)
{
	AddControllerPitchInput(AxisValue * CameraPitchSensitivity * GetWorld()->GetDeltaSeconds());
}

void ACharacterPlayer::LookRight(const float AxisValue)
{
	AddControllerYawInput(AxisValue * CameraYawSensitivity * GetWorld()->GetDeltaSeconds());
}

void ACharacterPlayer::StartMeleeAttack()
{
	if (bIsAttacking)
	{
		return;
	}

	bIsAttacking = true;
	MeleeAttackComponent->StartAttack();
}

void ACharacterPlayer::IncrementMaxSouls(const int32 Amount) const
{
	SoulsCounterComponent->IncreaseMaxValue(Amount);
}

void ACharacterPlayer::IncrementMaxPhylacteries(const int32 Amount) const
{
	PhylacteryCounterComponent->IncreaseMaxValue(Amount);
}

void ACharacterPlayer::IncrementMaxCoins(const int32 Amount) const
{
	CoinsCounterComponent->IncreaseMaxValue(Amount);
}

void ACharacterPlayer::LoadCountersValue(const int32 SoulsValue, const int32 PhylacteryValue, const int32 CoinsValue)
{
	SoulsCounterComponent->SetValue(SoulsValue);
	PhylacteryCounterComponent->SetValue(PhylacteryValue);
	CoinsCounterComponent->SetValue(CoinsValue);
}
