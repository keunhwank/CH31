#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BPlatform.generated.h"

UCLASS()
class CH3_MOVINGPLATFORM_API ABPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	ABPlatform();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BPlayform|StartLocation");
	FVector StartLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BPlayform|MaxRange");
	float MaxRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BPlayform|MoveSpeed");
	float MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BPlayform|RotationSpeed");
	float RotationSpeed;
	int Direction = 1;

protected:
	virtual void BeginPlay() override;
	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;

public:	
	virtual void Tick(float DeltaTime) override;

};
