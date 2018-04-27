// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Création du système de visée
	TankAimingCmpt = CreateDefaultSubobject<UTankAimingComponent>(FName("AimingComponent"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATank::AimedAt(FVector pHitLocation)
{
	TankAimingCmpt->AimedAt(pHitLocation, LaunchSpeed);
}

void ATank::AimedAt(ATank* pTarget)
{
	if (pTarget)
	{
		TankAimingCmpt->AimedAt(pTarget->GetTargetLocation(), LaunchSpeed);
	}
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::SetupAimingComponent(UStaticMeshComponent* pBarrel)
{
	if (TankAimingCmpt)
	{
		TankAimingCmpt->SetBarrel(pBarrel);
	}
}

