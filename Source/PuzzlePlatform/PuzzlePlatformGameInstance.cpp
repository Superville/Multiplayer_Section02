// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzlePlatformGameInstance.h"

#include "Engine/Engine.h"
#include "Engine/Classes/GameFramework/PlayerController.h"
#include "Engine/LocalPlayer.h"
#include "UObject/ConstructorHelpers.h"
#include "PlatformTrigger.h"
#include "Blueprint/UserWidget.h"


UPuzzlePlatformGameInstance::UPuzzlePlatformGameInstance(const FObjectInitializer& ObjectInitializer) :
		Super(ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<UUserWidget> MenuBPClass(TEXT("/Game/MenuSystem/WBP_MainMenu"));
	if (!ensure(MenuBPClass.Class)) return;

	MenuClass = MenuBPClass.Class;
	
	UE_LOG(LogTemp, Warning, TEXT("CONSTRUCTOR! %s"), *MenuClass->GetName());
}

void UPuzzlePlatformGameInstance::Init()
{
	Super::Init();

	UE_LOG(LogTemp, Warning, TEXT("INIT!"));
}

APlayerController* UPuzzlePlatformGameInstance::GetPC()
{
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return nullptr;

	auto LP = World->GetFirstLocalPlayerFromController();
	if (!ensure(LP != nullptr)) return nullptr;

	return LP->GetPlayerController(World);
}

void UPuzzlePlatformGameInstance::LoadMenu()
{
	if (!ensure(MenuClass)) return;

	auto MenuWidget = CreateWidget<UUserWidget>(this, MenuClass);
	if (!ensure(MenuWidget)) return;

	MenuWidget->AddToViewport();

	auto PC = GetPC();
	if (!ensure(PC != nullptr)) return;

	FInputModeUIOnly InputModeData;
	InputModeData.SetWidgetToFocus(MenuWidget->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	PC->SetInputMode(InputModeData);
	PC->bShowMouseCursor = true;
}

void UPuzzlePlatformGameInstance::Host()
{
	UE_LOG(LogTemp, Warning, TEXT("HOST!"));
	UEngine* Engine = GetEngine();
	if (!ensure(Engine!= nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 2, FColor::Yellow, TEXT("Hooooost"));

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	World->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen -server");
}

void UPuzzlePlatformGameInstance::Join(const FString& Address)
{
	UE_LOG(LogTemp, Warning, TEXT("JOIN!"));

	UEngine* Engine = GetEngine();
	if (Engine == nullptr) return;

	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, FString::Printf(TEXT("JOIN %s"), *Address));

	auto PC = GetPC();
	if (!ensure(PC != nullptr)) return;
	PC->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}