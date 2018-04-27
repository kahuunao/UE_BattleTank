// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
public:
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	

private:
	ATank* GetTank() const;

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5f;
	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.33333333f;
	UPROPERTY(EditAnywhere)
	float LineTraceRange = 100000.0f; //10km


	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& OutHitLocaltion) const;
	bool GetLookDirection(FVector2D &pScreenPosition, FVector &OutWorldDirection) const;
	bool GetLookLocation(FVector &pLookDirection, FVector &OutHitLocaltion) const;
};
