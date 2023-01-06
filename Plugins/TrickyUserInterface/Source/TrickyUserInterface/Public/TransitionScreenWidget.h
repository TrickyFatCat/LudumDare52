// MIT License Copyright (c) 2022 Artyom "Tricky Fat Cat" Volkov

#pragma once

#include "CoreMinimal.h"
#include "BaseUserWidget.h"
#include "TransitionScreenWidget.generated.h"

class UImage;
/**
 * 
 */
UCLASS()
class TRICKYUSERINTERFACE_API UTransitionScreenWidget : public UBaseUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="TransitionScreen", meta=(BindWidget))
	UImage* Image_Transition = nullptr;
};
