// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzlePlatformGameInstance.h"

#include "Engine/Engine.h"
#include "Engine/Classes/GameFramework/PlayerController.h"
#include "Engine/LocalPlayer.h"


UPuzzlePlatformGameInstance::UPuzzlePlatformGameInstance(const FObjectInitializer& ObjectInitializer) :
		Super(ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("CONSTRUCTOR!"));
}

void UPuzzlePlatformGameInstance::Init()
{
	Super::Init();

	UE_LOG(LogTemp, Warning, TEXT("INIT!"));
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

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	auto LP = World->GetFirstLocalPlayerFromController();
	if (!ensure(LP != nullptr)) return;

	auto PC = LP->GetPlayerController(World);
	if (!ensure(PC != nullptr)) return;
	PC->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}