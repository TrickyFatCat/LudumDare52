// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/SphereComponent.h"
#include "FocusComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class LUDUMDARE52_API UFocusComponent : public USphereComponent
{
	GENERATED_BODY()

public:
	UFocusComponent();

protected:
	virtual void BeginPlay() override;

	bool bIsFocusing = false;

	UPROPERTY()
	AActor* TargetActor = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float RotationSpeed = 7.5f;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void StartFocusing();

	UFUNCTION(BlueprintCallable)
	void StopFocusing();

protected:
	UFUNCTION()
	void HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent,
	                        AActor* OtherActor,
	                        UPrimitiveComponent* OtherComp,
	                        int32 OtherBodyIndex,
	                        bool bFromSweep,
	                        const FHitResult& SweepResult);
	
	UFUNCTION()
	void HandleEndOverlap(UPrimitiveComponent* OverlappedComponent,
	                      AActor* OtherActor,
	                      UPrimitiveComponent* OtherComp,
	                      int32 OtherBodyIndex);
};
