// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

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
	UE_LOG(LogTemp, Warning, TEXT("AimingPosition before %s"), *aimingPosition.ToString());
	GetSightRayHitLocation(aimingPosition);
	UE_LOG(LogTemp, Warning, TEXT("AimingPosition after %s"), *aimingPosition.ToString());
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocaltion) const
{
	OutHitLocaltion.X = 10;
	OutHitLocaltion.Y = 10;
	OutHitLocaltion.Z = 10;

	int32 screenWidth;
	int32 screenHeight;
	GetViewportSize(screenWidth, screenHeight);

	FVector2D crosshairLocation = FVector2D(screenWidth * CrosshairXLocation, screenHeight* CrosshairYLocation);

	return true;
}
