// MIT License Copyright (c) 2022 Artyom "Tricky Fat Cat" Volkov

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameModeSession.h"
#include "GameplayHUD.generated.h"

class UBaseUserWidget;

/**
 * 
 */
UCLASS()
class TRICKYUSERINTERFACE_API AGameplayHUD : public AHUD
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HUD")
	TSubclassOf<UBaseUserWidget> InactiveStateWidget = nullptr;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HUD")
	TSubclassOf<UBaseUserWidget> PreparationScreenWidget = nullptr;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HUD")
	TSubclassOf<UBaseUserWidget> GameplayScreenWidget = nullptr;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HUD")
	TSubclassOf<UBaseUserWidget> PauseScreenWidget = nullptr;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HUD")
	TSubclassOf<UBaseUserWidget> FinishScreenWidget = nullptr;

private:
	UPROPERTY()
	TMap<EGameModeState, UBaseUserWidget*> UserWidgets;

	UPROPERTY()
	UBaseUserWidget* ActiveWidget = nullptr;

	UFUNCTION()
	void OnGameModeSessionChanged(EGameModeState NewState);
	
	void CreateUserWidget(const EGameModeState State, TSubclassOf<UBaseUserWidget> WidgetClass);
};
