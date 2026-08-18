#include "APlatform.h"

AAPlatform::AAPlatform()
{
	
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	// Static Mesh Component를 생성하고 Scene Component에 Attach
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	//메쉬 에셋 설정
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/LearningKit_Games/Assets/Architecture/Platform/SM_Platform_M_A.SM_Platform_M_A"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	//머티리얼 설정
	/*static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/LowerSector_Mod/Models/SideWalk/Materials/M_SideWalk.M_SideWalk"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0,MaterialAsset.Object);
	}*/
	
	PrimaryActorTick.bCanEverTick = true;
}

void AAPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();
}

void AAPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!FMath::IsNearlyZero(MoveSpeed))
	{
		AddActorWorldOffset(FVector(0.0f, 0.0f, MoveSpeed * Direction * DeltaTime));
		if (GetActorLocation().Z >= StartLocation.Z + MaxRange)
		{
			Direction = -1;
		}
		if (GetActorLocation().Z <= StartLocation.Z)
		{
			Direction = 1;
		}
	}
}

