// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DeathComponent.generated.h"

class UAnimMontage;
class USkeletalMeshComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeathStartedSignature);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeathFinishedSignature);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class LUDUMDARE52_API UDeathComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UDeathComponent();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(BlueprintAssignable)
	FOnDeathStartedSignature OnDeathStarted;
	
	UPROPERTY(BlueprintAssignable)
	FOnDeathFinishedSignature OnDeathFinished;

	UPROPERTY(EditDefaultsOnly, Category="Character")
	UAnimMontage* DeathMontage = nullptr;

	UFUNCTION()
	void StartDeath() const;

protected:
	void HandleDeathFinish(USkeletalMeshComponent* SkeletalMeshComponent) const;
};
