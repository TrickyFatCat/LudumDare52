// MIT License Copyright (c) 2022 Artyom "Tricky Fat Cat" Volkov


#include "MainMenu/MainMenuWidget.h"

#include "ButtonWidget.h"
#include "TransitionScreenWidget.h"
#include "Kismet/GameplayStatics.h"

void UMainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	QuitButton->OnButtonClick.AddDynamic(this, &UMainMenuWidget::QuitGame);
	TransitionScreen->OnShowed.AddDynamic(this, &UMainMenuWidget::OnTransitionScreenShowed);
	TransitionScreen->Hide();
}

void UMainMenuWidget::OnTransitionScreenShowed_Implementation()
{
	if (bMustBeQuit)
	{
		UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, true);
	}
}

void UMainMenuWidget::OnTransitionScreenHidden_Implementation()
{
}

void UMainMenuWidget::QuitGame(UButtonWidget* Button)
{
	bMustBeQuit =  true;
	TransitionScreen->Show();
}
