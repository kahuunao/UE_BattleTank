// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Engine/World.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::AimedAt(FVector pHitLocation, float pLaunchSpeed)
{
	if (!Barrel)
	{
		return;
	}

	//UE_LOG(LogTemp, Warning, TEXT("%s aiming from %s at %s"), *GetOwner()->GetName(), *Barrel->GetComponentLocation().ToString(), *pHitLocation.ToString());

	FVector outLaunchVelocity;
	FVector startLocation = Barrel->GetSocketLocation(FName("ProjectibleOutput"));
	if (UGameplayStatics::SuggestProjectileVelocity(
		GetWorld(), 
		outLaunchVelocity, 
		startLocation, 
		pHitLocation, 
		pLaunchSpeed,
		false,
		0.0f,
		0.0f,
		ESuggestProjVelocityTraceOption::DoNotTrace))
	{
		UE_LOG(LogTemp, Warning, TEXT("%s aiming to %s"), *GetOwner()->GetName(), *outLaunchVelocity.GetSafeNormal().ToString());
	}
} 

void UTankAimingComponent::SetBarrel(UStaticMeshComponent* pBarrel)
{
	Barrel = pBarrel;
}

