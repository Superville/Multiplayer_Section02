// Fill out your copyright notice in the Description page of Project Settings.

#include "GameMenuWidget.h"
#include "Components/Button.h"




bool UGameMenuWidget::Initialize()
{
	bool bSuccess = Super::Initialize();
	if (!bSuccess) return false;

	if (!ensure(GameMenuCancelButton)) return false;
	GameMenuCancelButton->OnClicked.AddDynamic(this, &UGameMenuWidget::OnCancelButtonClicked);

	if (!ensure(GameMenuQuitButton)) return false;
	GameMenuQuitButton->OnClicked.AddDynamic(this, &UGameMenuWidget::OnQuitButtonClicked);

	Setup();

	return true;
}

void UGameMenuWidget::SetMainMenuInterface(IGameMenuInterface* MenuInterface)
{
	GameMenuInterface = MenuInterface;
}

void UGameMenuWidget::OnCancelButtonClicked()
{
	if (GameMenuInterface != nullptr)
	{
		GameMenuInterface->ToggleGameMenu();
	}
}

void UGameMenuWidget::OnQuitButtonClicked()
{
	if (GameMenuInterface != nullptr)
	{
		GameMenuInterface->GotoMainMenu();
	}
}
