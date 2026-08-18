#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Ch3Character.generated.h"

class USpringArmComponent;
class UCameraComponent;
struct FinputActionValue;

UCLASS()
class CH3_MOVINGPLATFORM_API ACh3Character : public ACharacter
{
	GENERATED_BODY()

public:
	ACh3Character();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ACh3Character | Camera");
	USpringArmComponent* SpringArmComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ACh3Character | Camera");
	UCameraComponent* CameraComp;

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)override;

	UFUNCTION()
	void Move(const FInputActionValue& value);
	UFUNCTION()
	void StartJump(const FInputActionValue& value);
	UFUNCTION()
	void StopJump(const FInputActionValue& value);
	UFUNCTION()
	void Look(const FInputActionValue& value);
	UFUNCTION()
	void StartSprint(const FInputActionValue& value);
	UFUNCTION()
	void StopSprint(const FInputActionValue& value);

private:
	float NormalSpeed;
	float SprintSpeedMultiplier;
	float SprintSpeed;

};
