// MIT License Copyright (c) 2022 Artyom "Tricky Fat Cat" Volkov


#include "ButtonWidget.h"
#include "Components/Button.h"

void UButtonWidget::NativeConstruct()
{
	Super::NativeConstruct();

	MainButton->OnClicked.AddDynamic(this, &UButtonWidget::OnButtonClicked);
}

void UButtonWidget::OnButtonClicked()
{
	OnButtonClick.Broadcast(this);
}
