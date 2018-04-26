// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


ATank* ATankPlayerController::GetTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	ATank* MyTank = GetTank();
	if (MyTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player control %s"), *MyTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Tank pawn controlled by the player"));
	}
}
