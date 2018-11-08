// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"


AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);

		GlobalStartLocation = GetActorLocation();
		GlobalEndLocation = GetTransform().TransformPosition(TargetLocation);
	}
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (ActiveTriggers > 0)
	{
		if (HasAuthority())
		{
			auto ActorLocation = GetActorLocation();
			auto Direction = (GlobalEndLocation - GlobalStartLocation).GetSafeNormal();
			ActorLocation += Direction * PlatformSpeed * DeltaTime;
			SetActorLocation(ActorLocation);

			auto dotP = FVector::DotProduct(Direction, GlobalEndLocation - ActorLocation);
			if (dotP < 0)
			{
				auto SwapLocation = GlobalStartLocation;
				GlobalStartLocation = GlobalEndLocation;
				GlobalEndLocation = SwapLocation;
			}
		}
	}
}

void AMovingPlatform::AddActiveTrigger()
{
	ActiveTriggers++;
}

void AMovingPlatform::RemoveActiveTrigger()
{
	if (ActiveTriggers > 0)
	{
		ActiveTriggers--;
	}
}