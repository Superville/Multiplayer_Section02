// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MenuSystem/MainMenuInterface.h"
#include "MenuSystem/GameMenuInterface.h"
#include "PuzzlePlatformGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORM_API UPuzzlePlatformGameInstance : public UGameInstance, public IMainMenuInterface, public IGameMenuInterface
{
	GENERATED_BODY()
	
public:
	UPuzzlePlatformGameInstance(const FObjectInitializer& ObjectInitializer);
	void Init() override;

	UFUNCTION(Exec, BlueprintCallable, Category = "EXEC")
	virtual void Host();
	
	UFUNCTION(Exec, BlueprintCallable, Category = "EXEC")
	virtual void Join(const FString& Address);

	UFUNCTION(Exec, BlueprintCallable, Category = "EXEC")
	virtual void GotoMainMenu();

	UFUNCTION(Exec, BlueprintCallable, Category = "EXEC")
	virtual void LoadMainMenu();

	UFUNCTION(Exec, BlueprintCallable, Category = "EXEC")
	virtual void ToggleGameMenu();

	UFUNCTION(Exec, BlueprintCallable, Category = "EXEC")
	virtual void QuitGame();

private:
	TSubclassOf<class UUserWidget> MainMenuClass;
	class UMainMenuWidget* MainMenu;

	TSubclassOf<class UUserWidget> GameMenuClass;
	class UGameMenuWidget* GameMenu;
	bool bGameMenuActive = false;

	class APlayerController* GetPC();
};
