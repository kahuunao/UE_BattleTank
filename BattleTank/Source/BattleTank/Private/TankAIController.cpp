// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


ATank* ATankAIController::GetTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* MyTank = GetTank();
	if (MyTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI control %s"), *MyTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Tank pawn controlled by an AI"));
	}
}

