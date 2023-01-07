// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.


#include "AnimationNotifyBase.h"

void UAnimationNotifyBase::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	OnNotified.Broadcast();
	Super::Notify(MeshComp, Animation);
}
