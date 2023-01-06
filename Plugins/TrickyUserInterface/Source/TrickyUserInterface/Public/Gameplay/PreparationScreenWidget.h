// MIT License Copyright (c) 2022 Artyom "Tricky Fat Cat" Volkov

#pragma once

#include "CoreMinimal.h"
#include "BaseUserWidget.h"
#include "PreparationScreenWidget.generated.h"

class UTransitionScreenWidget;
class UTextBlock;

/**
 * 
 */
UCLASS()
class TRICKYUSERINTERFACE_API UPreparationScreenWidget : public UBaseUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="PreparationScreen", meta=(BindWidget))
	UTransitionScreenWidget* TransitionScreenWidget = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="PreparationScreen", meta=(BindWidget))
	UTextBlock* PreparationTimer = nullptr;
};
