#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Ch3PlayerController.h"
#include "InputActionValue.h"
#include "Drone.generated.h"

UCLASS()
class CH3_MOVINGPLATFORM_API ADrone : public APawn
{
	GENERATED_BODY()

public:
	ADrone();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USkeletalMeshComponent* SkeletalMeshComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UCameraComponent* CameraComp;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputMappingContext* DroneMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* MoveAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MoveSpeed = 500.0f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float RotationSpeed = 100.0f;

	virtual void BeginPlay() override;

	void Move(const FInputActionValue& value);

	void Look(const FInputActionValue& value);

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputConponent) override;

public:	
	virtual void Tick(float DeltaTime) override;

};
