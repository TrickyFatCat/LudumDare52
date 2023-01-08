// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerRestartComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRestartStartedSignature);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRestartFinishedSignature);

class UTransitionScreenWidget;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class LUDUMDARE52_API UPlayerRestartComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPlayerRestartComponent();

	UPROPERTY(BlueprintAssignable)
	FOnRestartStartedSignature OnRestartStarted;

	UPROPERTY(BlueprintAssignable)
	FOnRestartFinishedSignature OnRestartFinished;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category="Character")
	TSubclassOf<UTransitionScreenWidget> TransitionWidgetClass = nullptr;

	UPROPERTY()
	UTransitionScreenWidget* TransitionScreenWidget = nullptr;

private:
	FTransform InitialTransform;

	UFUNCTION()
	void FinishRestart();

public:
	UFUNCTION()
	void Restart() const;
};
