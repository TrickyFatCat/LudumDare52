// MIT License Copyright (c) 2022 Artyom "Tricky Fat Cat" Volkov


#include "Gameplay/FinishMenuWidget.h"

#include "ButtonWidget.h"
#include "TransitionScreenWidget.h"
#include "Kismet/GameplayStatics.h"

void UFinishMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	auto BindButtonEvent = [&](UButtonWidget* ButtonWidget)
	{
		ButtonWidget->OnButtonClick.AddDynamic(this, &UFinishMenuWidget::OnButtonClicked);
	};

	BindButtonEvent(ContinueButton);
	BindButtonEvent(RestartButton);
	BindButtonEvent(QuitButton);
	TransitionScreenWidget->OnHidden.AddDynamic(this, &UFinishMenuWidget::OnTransitionScreenShowed);
}

void UFinishMenuWidget::OnButtonClicked_Implementation(UButtonWidget* Button)
{
	ClickedButton = Button;
	TransitionScreenWidget->Show();
}

void UFinishMenuWidget::Continue_Implementation()
{
	const FName CurrentLevelName = FName(UGameplayStatics::GetCurrentLevelName(this));
	UGameplayStatics::OpenLevel(this, CurrentLevelName);
}

void UFinishMenuWidget::Restart_Implementation()
{
	const FName CurrentLevelName = FName(UGameplayStatics::GetCurrentLevelName(this));
	UGameplayStatics::OpenLevel(this, CurrentLevelName);
}

void UFinishMenuWidget::Quit_Implementation()
{
	UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, true);
}

void UFinishMenuWidget::OnTransitionScreenShowed_Implementation()
{
	if (ClickedButton == ContinueButton)
	{
		Continue();
	}
	else if (ClickedButton == RestartButton)
	{
		Restart();
	}
	else if (ClickedButton == QuitButton)
	{
		Quit();
	}
}
