// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AnimationNotifyBase.generated.h"


DECLARE_MULTICAST_DELEGATE(FOnNotifiedSignature)

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

	template <typename T>
	static T* FindFirstNotifyByClass(UAnimSequenceBase* Animation)
	{
		if (!Animation) return nullptr;

		const auto NotifyEvents = Animation->Notifies;

		for (auto NotifyEvent : NotifyEvents)
		{
			auto AnimNotify = Cast<T>(NotifyEvent.Notify);

			if (AnimNotify)
			{
				return AnimNotify;
			}
		}

		return nullptr;
	}
};
