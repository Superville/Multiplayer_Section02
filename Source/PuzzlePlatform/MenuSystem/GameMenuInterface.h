// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameMenuInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGameMenuInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PUZZLEPLATFORM_API IGameMenuInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void GotoMainMenu() = 0;
	virtual void ToggleGameMenu() = 0;
	
};
