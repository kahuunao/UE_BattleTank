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
	void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	

private:
	ATank* GetTank() const;

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5f;
	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.33333333f;

	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& OutHitLocaltion) const;
};
