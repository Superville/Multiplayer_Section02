// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuInterface.h"
#include "MainMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORM_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetMainMenuInterface(IMainMenuInterface* MenuInterface);
	void Setup();
	void Cleanup();



protected:
	virtual bool Initialize() override;

private:
	UPROPERTY(meta = (BindWidget))
	class UButton* HostButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* JoinButton;

	UFUNCTION()
	void OnHostButtonClicked();

	UFUNCTION()
	void OnJoinButtonClicked();


	IMainMenuInterface* MainMenuInterface;
};
