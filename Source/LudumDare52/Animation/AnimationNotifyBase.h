// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AnimationNotifyBase.generated.h"

class USkeletalMeshComponent;

DECLARE_MULTICAST_DELEGATE_OneParam(FOnNotifiedSignature, USkeletalMeshComponent*)
/**
 * 
 */
UCLASS()
class LUDUMDARE52_API UAnimationNotifyBase : public UAnimNotify
{
	GENERATED_BODY()

public:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
	FOnNotifiedSignature OnNotified;
};
