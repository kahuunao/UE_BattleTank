// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Runtime/Engine/Classes/Engine/World.h"


ATank* ATankAIController::GetTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	APlayerController* player = GetWorld()->GetFirstPlayerController();
	ATank* tank = nullptr;
	if (player)
	{
		tank = Cast<ATank>(player->GetPawn());
	}
	return tank;
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

	ATank* playerTank = GetPlayerTank();
	if (MyTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player found"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player not found"));
	}
}

