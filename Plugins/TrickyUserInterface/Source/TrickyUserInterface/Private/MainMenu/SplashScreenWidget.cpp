// MIT License Copyright (c) 2022 Artyom "Tricky Fat Cat" Volkov


#include "MainMenu/SplashScreenWidget.h"
#include "TransitionScreenWidget.h"
#include "Components/Image.h"

DECLARE_LOG_CATEGORY_CLASS(LogSplashScreen, All, All);

void USplashScreenWidget::NativeConstruct()
{
	Super::NativeConstruct();

	TransitionScreenWidget->OnHidden.AddDynamic(this, &USplashScreenWidget::StartSplashTimer);
	TransitionScreenWidget->OnShowed.AddDynamic(this, &USplashScreenWidget::SwitchSplashScreen);

	if (SplashImages.Num() == 0)
	{
		UE_LOG(LogSplashScreen, Warning, TEXT("Splash screen images array is empty."));
		OnSplashFinished.Broadcast();
		return;
	}

	SplashScreenImage->SetBrushFromTexture(SplashImages[CurrentSplashIndex], true);
	TransitionScreenWidget->Hide();
}

void USplashScreenWidget::StartSplashTimer()
{
	if (!GetWorld())
	{
		return;
	}

	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle,
	                                       TransitionScreenWidget,
	                                       &UTransitionScreenWidget::Show,
	                                       SplashDuration);
}

void USplashScreenWidget::SwitchSplashScreen()
{
	CurrentSplashIndex++;

	if (CurrentSplashIndex >= SplashImages.Num())
	{
		OnSplashFinished.Broadcast();
		return;
	}

	UTexture2D* Texture = SplashImages[CurrentSplashIndex];
	
	if (Texture)
	{
		SplashScreenImage->SetBrushFromTexture(Texture, true);
		OnSplashChanged.Broadcast(CurrentSplashIndex);
	}
	else
	{
		UE_LOG(LogSplashScreen, Warning, TEXT("Splashscreen %d is nullptr. Please, set this splashscreen."), CurrentSplashIndex);
	}

	TransitionScreenWidget->Hide();
}
