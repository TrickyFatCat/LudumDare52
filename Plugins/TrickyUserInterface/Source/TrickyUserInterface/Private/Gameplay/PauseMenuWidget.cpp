// MIT License Copyright (c) 2022 Artyom "Tricky Fat Cat" Volkov


#include "Gameplay/PauseMenuWidget.h"

#include "ButtonWidget.h"
#include "TransitionScreenWidget.h"
#include "Kismet/GameplayStatics.h"

void UPauseMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	auto BindButtonEvent = [&](UButtonWidget* ButtonWidget)
	{
		ButtonWidget->OnButtonClick.AddDynamic(this, &UPauseMenuWidget::OnButtonClick);
	};

	BindButtonEvent(ResumeButton);
	BindButtonEvent(RestartButton);
	BindButtonEvent(QuitButton);
	TransitionScreenWidget->OnShowed.AddDynamic(this, &UPauseMenuWidget::TransitionScreenShowed);
}

void UPauseMenuWidget::OnButtonClick_Implementation(UButtonWidget* Button)
{
	if (Button == ResumeButton)
	{
		Hide();
		UGameplayStatics::SetGamePaused(this,false);
	}
	else if (Button == RestartButton || Button == QuitButton)
	{
		ClickedButton = Button;
		TransitionScreenWidget->Show();
	}
}

void UPauseMenuWidget::Restart_Implementation()
{
	const FName CurrentLevelName = FName(UGameplayStatics::GetCurrentLevelName(this));
	UGameplayStatics::OpenLevel(this, CurrentLevelName);
}

void UPauseMenuWidget::Quit_Implementation()
{
	UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, true);
}

void UPauseMenuWidget::TransitionScreenShowed_Implementation()
{
	if (ClickedButton == RestartButton)
	{
		Restart();
	}
	else if (ClickedButton == QuitButton)
	{
		Quit();
	}
}
