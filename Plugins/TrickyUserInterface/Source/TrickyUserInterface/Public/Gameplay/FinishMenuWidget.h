// MIT License Copyright (c) 2022 Artyom "Tricky Fat Cat" Volkov

#pragma once

#include "CoreMinimal.h"
#include "BaseUserWidget.h"
#include "FinishMenuWidget.generated.h"

class UButtonWidget;
class UTransitionScreenWidget;

/**
 * 
 */
UCLASS()
class TRICKYUSERINTERFACE_API UFinishMenuWidget : public UBaseUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FinishScreen", meta=(BindWidget))
	UButtonWidget* ContinueButton = nullptr;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FinishScreen", meta=(BindWidget))
	UButtonWidget* RestartButton = nullptr;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FinishScreen", meta=(BindWidget))
	UButtonWidget* QuitButton = nullptr;

	UPROPERTY()
	UButtonWidget* ClickedButton = nullptr;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FinishScreen", meta=(BindWidget))
	UTransitionScreenWidget* TransitionScreenWidget = nullptr;

	UFUNCTION(BlueprintNativeEvent, Category="FinishScreen")
	void OnButtonClicked(UButtonWidget* Button);

	virtual void OnButtonClicked_Implementation(UButtonWidget* Button);

	UFUNCTION(BlueprintNativeEvent, Category="FinishScreen")
	void Continue();

	virtual void Continue_Implementation();
	
	UFUNCTION(BlueprintNativeEvent, Category="FinishScreen")
	void Restart();

	virtual void Restart_Implementation();
	
	UFUNCTION(BlueprintNativeEvent, Category="FinishScreen")
	void Quit();

	virtual void Quit_Implementation();

	UFUNCTION(BlueprintNativeEvent, Category="FinishScreen")
	void OnTransitionScreenShowed();

	virtual void OnTransitionScreenShowed_Implementation();
};
