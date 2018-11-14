// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenuWidget.h"
#include "Components/Button.h"


bool UMainMenuWidget::Initialize()
{
	bool bSuccess = Super::Initialize();
	if (!bSuccess) return false;

	if (!ensure(HostButton)) return false;
	HostButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnHostButtonClicked);

	if (!ensure(JoinButton)) return false;
	JoinButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnJoinButtonClicked);


	return true;
}

void UMainMenuWidget::SetMainMenuInterface(IMainMenuInterface* MenuInterface)
{
	MainMenuInterface = MenuInterface;
}

void UMainMenuWidget::Setup()
{
	AddToViewport();

	auto World = GetWorld();
	if (!ensure(World != nullptr)) return;

	auto PC = World->GetFirstPlayerController();
	if (!ensure(PC != nullptr)) return;

	FInputModeUIOnly InputModeData;
	InputModeData.SetWidgetToFocus(TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	PC->SetInputMode(InputModeData);
	PC->bShowMouseCursor = true;

	UE_LOG(LogTemp, Warning, TEXT("SETUP!"));
}

void UMainMenuWidget::Cleanup()
{
	RemoveFromViewport();

	auto World = GetWorld();
	if (!ensure(World != nullptr)) return;

	auto PC = World->GetFirstPlayerController();
	if (!ensure(PC != nullptr)) return;

	FInputModeGameOnly InputModeData;
	PC->SetInputMode(InputModeData);

	PC->bShowMouseCursor = false;

	UE_LOG(LogTemp, Warning, TEXT("CLEANUP!"));
}

void UMainMenuWidget::OnHostButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("OnHostButtonClicked"));

	if (MainMenuInterface != nullptr)
	{
		MainMenuInterface->Host();
	}
}

void UMainMenuWidget::OnJoinButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("OnJoinButtonClicked"));

	if (MainMenuInterface != nullptr)
	{
		//MainMenuInterface->Join();
	}
}