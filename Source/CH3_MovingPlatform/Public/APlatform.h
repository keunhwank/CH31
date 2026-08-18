#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "APlatform.generated.h"

UCLASS()
class CH3_MOVINGPLATFORM_API AAPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	AAPlatform();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category ="APlatform|MoveSpeed");
	float MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "APlatform|StartLocation");
	FVector StartLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "APlatform|MaxRange");
	float MaxRange;
	int Direction = 1;


protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "APlatform|Component");
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "APlatform|Component");
	UStaticMeshComponent* StaticMeshComp;

	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
