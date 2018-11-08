// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORM_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	AMovingPlatform();
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float PlatformSpeed;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true), Category = "Movement")
	FVector TargetLocation;

	FVector GlobalStartLocation;
	FVector GlobalEndLocation;

	void AddActiveTrigger();
	void RemoveActiveTrigger();

protected:

private:
	UPROPERTY(EditAnywhere, Category = "Movement")
	int ActiveTriggers = 1;
};
