// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenuWidget.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableText.h"


bool UMainMenuWidget::Initialize()
{
	bool bSuccess = Super::Initialize();
	if (!bSuccess) return false;

	if (!ensure(HostButton)) return false;
	HostButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnHostButtonClicked);

	if (!ensure(MainJoinButton)) return false;
	MainJoinButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnMainJoinButtonClicked);

	if (!ensure(JoinCancelButton)) return false;
	JoinCancelButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnJoinCancelButtonClicked);

	if (!ensure(JoinButton)) return false;
	JoinButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnJoinButtonClicked);

	if (!ensure(QuitButton)) return false;
	QuitButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnQuitButtonClicked);


	OpenMainMenu();

	return true;
}

void UMainMenuWidget::SetMainMenuInterface(IMainMenuInterface* MenuInterface)
{
	MainMenuInterface = MenuInterface;
}

void UMainMenuWidget::OnHostButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("OnHostButtonClicked"));

	if (MainMenuInterface != nullptr)
	{
		MainMenuInterface->Host();
	}
}

void UMainMenuWidget::OnMainJoinButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("OnMainJoinButtonClicked"));

	OpenJoinMenu();
}

void UMainMenuWidget::OnJoinCancelButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("OnJoinCancelButtonClicked"));

	OpenMainMenu();
}


void UMainMenuWidget::OnJoinButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("OnJoinButtonClicked"));

	if (MainMenuInterface != nullptr && FieldInputIP != nullptr)
	{
		const FString& Address = FieldInputIP->GetText().ToString();
		MainMenuInterface->Join(Address);
	}
}

void UMainMenuWidget::OnQuitButtonClicked()
{
	if (MainMenuInterface != nullptr)
	{
		MainMenuInterface->QuitGame();
	}
}

void UMainMenuWidget::OpenMainMenu()
{
	if (!ensure(MenuSwitcher)) return;
	if (!ensure(MainMenu)) return;
	MenuSwitcher->SetActiveWidget(MainMenu);
}

void UMainMenuWidget::OpenJoinMenu()
{
	if (!ensure(MenuSwitcher)) return;
	if (!ensure(JoinMenu)) return;
	MenuSwitcher->SetActiveWidget(JoinMenu);
}
