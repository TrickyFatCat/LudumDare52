// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LevelTeleportComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTeleportationStartedSignatue);

class UTransitionScreenWidget;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class LUDUMDARE52_API ULevelTeleportComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	ULevelTeleportComponent();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName TargetLevelName = NAME_None;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UTransitionScreenWidget> TransitionWidgetClass = nullptr;

	UPROPERTY()
	UTransitionScreenWidget* TransitionScreenWidget = nullptr;

	UFUNCTION()
	void FinishTeleportation();

public:
	UPROPERTY(BlueprintAssignable)
	FOnTeleportationStartedSignatue OnTeleportationStarted;

	UFUNCTION(BlueprintCallable)
	void StartTeleportation();
};