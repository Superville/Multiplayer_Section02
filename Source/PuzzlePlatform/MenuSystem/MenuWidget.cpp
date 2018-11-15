// Fill out your copyright notice in the Description page of Project Settings.

#include "MenuWidget.h"

void UMenuWidget::Setup()
{
	AddToViewport();

	auto World = GetWorld();
	if (!ensure(World != nullptr)) return;

	auto PC = World->GetFirstPlayerController();
	if (PC != nullptr)
	{
		FInputModeUIOnly InputModeData;
		InputModeData.SetWidgetToFocus(TakeWidget());
		InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
		PC->SetInputMode(InputModeData);
		PC->bShowMouseCursor = true;
	}
}

void UMenuWidget::Cleanup()
{
	RemoveFromViewport();

	auto World = GetWorld();
	if (!ensure(World != nullptr)) return;

	auto PC = World->GetFirstPlayerController();
	if (PC != nullptr)
	{
		FInputModeGameOnly InputModeData;
		PC->SetInputMode(InputModeData);
		PC->bShowMouseCursor = false;
	}
}
