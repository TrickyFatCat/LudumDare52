// MIT License Copyright (c) 2022 Artyom "Tricky Fat Cat" Volkov

#pragma once

#include "CoreMinimal.h"
#include "BaseUserWidget.h"
#include "ButtonWidget.h"
#include "MainMenuWidget.generated.h"

class UTransitionScreenWidget;
class UButtonWidget;

/**
 * 
 */
UCLASS()
class TRICKYUSERINTERFACE_API UMainMenuWidget : public UBaseUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="MainMenu", meta=(BindWidget))
	UTransitionScreenWidget* TransitionScreen;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="MainMenu", meta=(BindWidget))
	UButtonWidget* QuitButton = nullptr;
	
	UFUNCTION(BlueprintNativeEvent, Category="TrickyUserInterface")
	void OnTransitionScreenShowed();

	virtual void OnTransitionScreenShowed_Implementation();
	
	UFUNCTION(BlueprintNativeEvent, Category="TrickyUserInterface")
	void OnTransitionScreenHidden();

	virtual void OnTransitionScreenHidden_Implementation();

private:
	bool bMustBeQuit = false;
	
	UFUNCTION()
	void QuitGame(UButtonWidget* Button);
};
