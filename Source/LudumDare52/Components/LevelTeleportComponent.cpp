﻿// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.


#include "LevelTeleportComponent.h"

#include "GameModeSession.h"
#include "TransitionScreenWidget.h"
#include "TrickyGameModeLibrary.h"
#include "Kismet/GameplayStatics.h"


ULevelTeleportComponent::ULevelTeleportComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


void ULevelTeleportComponent::BeginPlay()
{
	Super::BeginPlay();

	if (TransitionWidgetClass)
	{
		TransitionScreenWidget = CreateWidget<UTransitionScreenWidget>(GetWorld(), TransitionWidgetClass);
		TransitionScreenWidget->AddToViewport();
		TransitionScreenWidget->SetVisibility(ESlateVisibility::Hidden);
		TransitionScreenWidget->OnShowed.AddDynamic(this, &ULevelTeleportComponent::FinishTeleportation);
	}
}

void ULevelTeleportComponent::FinishTeleportation()
{
	UGameplayStatics::OpenLevel(this, TargetLevelName);
}

void ULevelTeleportComponent::StartTeleportation()
{
	OnTeleportationStarted.Broadcast();

	AGameModeSession* GameModeSession = UTrickyGameModeLibrary::GetSessionGameMode(this);

	if (GameModeSession)
	{
		GameModeSession->FinishSession(true);
	}
	
	if (!TransitionScreenWidget)
	{
		return;
	}

	TransitionScreenWidget->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
	TransitionScreenWidget->Show();
}
