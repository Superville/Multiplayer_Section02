// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"
#include "GameMenuInterface.h"
#include "GameMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORM_API UGameMenuWidget : public UMenuWidget
{
	GENERATED_BODY()
	
public:
	void SetMainMenuInterface(IGameMenuInterface* MenuInterface);
	
protected:
	virtual bool Initialize() override;
	
private:
	UPROPERTY(meta = (BindWidget))
	class UButton* GameMenuCancelButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* GameMenuQuitButton;

	UFUNCTION()
	void OnCancelButtonClicked();

	UFUNCTION()
	void OnQuitButtonClicked();

	IGameMenuInterface* GameMenuInterface;
};
