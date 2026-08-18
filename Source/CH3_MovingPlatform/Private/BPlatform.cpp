#include "BPlatform.h"

ABPlatform::ABPlatform()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("/Game/LowerSector_Mod/Models/Tower8x/SM_Tower8x.SM_Tower8x"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}
	PrimaryActorTick.bCanEverTick = true;

}

void ABPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();
}

void ABPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!FMath::IsNearlyZero(MoveSpeed))
	{
		//회전 
		AddActorWorldOffset(FVector(0.0f, MoveSpeed * Direction * DeltaTime, 0.0f));
		//Y축 이동
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
		//처음 위치보다 현재 위치가 클경우 
		if (GetActorLocation().Y >= StartLocation.Y + MaxRange)
		{
			//방향 전환
			Direction = -1;
		}
		//처음 위치랑 현재 위치가 같은 경우 
		if (GetActorLocation().Y <= StartLocation.Y)
		{
			//방향 전환
			Direction = 1;
		}
	}
}

