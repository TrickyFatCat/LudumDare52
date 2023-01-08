// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttackComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAttackStartedSignature);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAttackFinishedSignature);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class LUDUMDARE52_API UAttackComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAttackComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable)
	FOnAttackStartedSignature OnAttackStarted;
	
	UPROPERTY(BlueprintAssignable)
	FOnAttackFinishedSignature OnAttackFinished;
	
	UFUNCTION(BlueprintCallable)
	void StartAttack();

	UFUNCTION(BlueprintCallable)
	void FinishAttack(USkeletalMeshComponent* SkeletalMeshComponent);

protected:
	UPROPERTY()
	ACharacter* Character = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<UAnimMontage*> AttackMontages;

	int32 CurrentIndex = 0;
};
