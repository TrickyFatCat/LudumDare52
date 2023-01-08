// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.


#include "PlayerRestartComponent.h"

#include "TransitionScreenWidget.h"
#include "Blueprint/UserWidget.h"

UPlayerRestartComponent::UPlayerRestartComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UPlayerRestartComponent::BeginPlay()
{
	Super::BeginPlay();

	InitialTransform = GetOwner()->GetActorTransform();

	if (TransitionWidgetClass)
	{
		TransitionScreenWidget = CreateWidget<UTransitionScreenWidget>(GetWorld(), TransitionWidgetClass);
		TransitionScreenWidget->AddToViewport();
		TransitionScreenWidget->SetVisibility(ESlateVisibility::Hidden);
		TransitionScreenWidget->OnShowed.AddDynamic(this, &UPlayerRestartComponent::FinishRestart);
	}
}

void UPlayerRestartComponent::FinishRestart()
{
	GetOwner()->SetActorTransform(InitialTransform);
	OnRestartFinished.Broadcast();
	TransitionScreenWidget->Hide();
}

void UPlayerRestartComponent::Restart() const 
{
	if (!TransitionScreenWidget)
	{
		return;
	}
	
	TransitionScreenWidget->SetVisibility(ESlateVisibility::HitTestInvisible);
	TransitionScreenWidget->Show();
	OnRestartStarted.Broadcast();
}
