// MIT License Copyright (c) 2022 Artyom "Tricky Fat Cat" Volkov

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseUserWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnShowedSignature);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHiddenSignature);

/**
 * 
 */
UCLASS()
class TRICKYUSERINTERFACE_API UBaseUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeOnInitialized() override;

	UFUNCTION(BlueprintCallable)
	void Show();

	UFUNCTION(BlueprintCallable)
	void Hide();

	UPROPERTY(BlueprintAssignable, Category="Animation")
	FOnShowedSignature OnShowed;
	
	UPROPERTY(BlueprintAssignable, Category="Animation")
	FOnHiddenSignature OnHidden;

protected:
	UPROPERTY(Transient, meta=(BindWidgetAnim))
	UWidgetAnimation* ShowAnimation = nullptr;
	
	UPROPERTY(Transient, meta=(BindWidgetAnim))
	UWidgetAnimation* HideAnimation = nullptr;

	virtual void OnAnimationStarted_Implementation(const UWidgetAnimation* Animation) override;
	
	virtual void OnAnimationFinished_Implementation(const UWidgetAnimation* Animation) override;
	
	float CalculateStartTime(const UWidgetAnimation* CurrentAnimation, const UWidgetAnimation* NewAnimation) const;
};
