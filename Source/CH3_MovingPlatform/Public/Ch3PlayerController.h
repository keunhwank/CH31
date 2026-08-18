#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Ch3PlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class CH3_MOVINGPLATFORM_API ACh3PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ACh3PlayerController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputMappingContext* InputMappingContext;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* MoveAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* JumpAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* LookAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* SprintAction;

protected:
	virtual void BeginPlay() override;
};
