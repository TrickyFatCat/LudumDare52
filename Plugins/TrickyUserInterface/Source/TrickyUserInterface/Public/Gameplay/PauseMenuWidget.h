// MIT License Copyright (c) 2022 Artyom "Tricky Fat Cat" Volkov

#pragma once

#include "CoreMinimal.h"
#include "BaseUserWidget.h"
#include "PauseMenuWidget.generated.h"

class UButtonWidget;
class UTransitionScreenWidget;

/**
 * 
 */
UCLASS()
class TRICKYUSERINTERFACE_API UPauseMenuWidget : public UBaseUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="PauseMenu", meta=(BindWidget))
	UButtonWidget* ResumeButton = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="PauseMenu", meta=(BindWidget))
	UButtonWidget* RestartButton = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="PauseMenu", meta=(BindWidget))
	UButtonWidget* QuitButton = nullptr;

	UPROPERTY()
	UButtonWidget* ClickedButton = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="PauseMenu", meta=(BindWidget))
	UTransitionScreenWidget* TransitionScreenWidget = nullptr;

	UFUNCTION(BlueprintNativeEvent, Category="PauseMenu")
	void OnButtonClick(UButtonWidget* Button);

	virtual void OnButtonClick_Implementation(UButtonWidget* Button);

	UFUNCTION(BlueprintNativeEvent, Category="PauseMenu")
	void Restart();

	virtual void Restart_Implementation();

	UFUNCTION(BlueprintNativeEvent, Category="PauseMenu")
	void Quit();

	virtual void Quit_Implementation();

	UFUNCTION(BlueprintNativeEvent, Category="PauseMenu")
	void TransitionScreenShowed();

	virtual void TransitionScreenShowed_Implementation();
};
