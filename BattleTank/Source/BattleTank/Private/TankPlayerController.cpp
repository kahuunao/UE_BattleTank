// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Runtime/Engine/Classes/Engine/World.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ATank* MyTank = GetTank();
	if (!MyTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Tank pawn controlled by the player"));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetTank())
	{
		return;
	}

	FVector aimingPosition;
	if (GetSightRayHitLocation(aimingPosition))
	{
		GetTank()->AimedAt(aimingPosition);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const
{
	// Get crosshair screen location
	int32 screenWidth;
	int32 screenHeight;
	GetViewportSize(screenWidth, screenHeight);
	FVector2D crosshairLocation = FVector2D(screenWidth * CrosshairXLocation, screenHeight* CrosshairYLocation);
	
	// Get crosshair world position
	FVector worldDirection;
	if (GetLookDirection(crosshairLocation, worldDirection))
	{
		return GetLookLocation(worldDirection, OutHitLocation);
	}
	OutHitLocation = FVector::ZeroVector;
	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D &pScreenPosition, FVector &OutWorldDirection) const
{
	FVector cameraWorldLocation;
	return DeprojectScreenPositionToWorld(pScreenPosition.X, pScreenPosition.Y, cameraWorldLocation, OutWorldDirection);
}

bool ATankPlayerController::GetLookLocation(FVector &pLookDirection, FVector &OutHitLocation) const
{
	FVector start = PlayerCameraManager->GetCameraLocation();
	FVector end = start + pLookDirection * LineTraceRange;

	FHitResult hit;
	if (GetWorld()->LineTraceSingleByChannel(hit, start, end, ECollisionChannel::ECC_Visibility))
	{
		OutHitLocation = hit.Location;
		return true;
	}
	OutHitLocation = FVector::ZeroVector;
	return false;
}


