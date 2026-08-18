#include "Drone.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

// Sets default values
ADrone::ADrone()
{
	PrimaryActorTick.bCanEverTick = false;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComp"));
	SetRootComponent(CapsuleComp);
	CapsuleComp->SetSimulatePhysics(false);

	SkeletalMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	SkeletalMeshComp->SetupAttachment(CapsuleComp);
	SkeletalMeshComp->SetSimulatePhysics(false);


	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SprinArm"));
	SpringArmComp->SetupAttachment(CapsuleComp);
	
	

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(SpringArmComp);
	

}

// Called when the game starts or when spawned
void ADrone::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	if (PlayerController)
	{
		ULocalPlayer* LocalPlayer = PlayerController->GetLocalPlayer();
		if (LocalPlayer)
		{
			UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
			if (Subsystem)
			{
				Subsystem->AddMappingContext(DroneMappingContext, 0);
			}
		}
	}

	
}

void ADrone::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (EnhancedInputComponent)
	{
		if (MoveAction)
		{
			EnhancedInputComponent->BindAction(
				MoveAction,
				ETriggerEvent::Triggered,
				this,
				&ADrone::Move
			);
		}

		if (LookAction)
		{
			EnhancedInputComponent->BindAction(
				LookAction,
				ETriggerEvent::Triggered,
				this,
				&ADrone::Look
			);
		}
	}
}


void ADrone::Move(const FInputActionValue& value)
{
	if (!Controller) return;

	const FVector2D MoveInput = value.Get<FVector2D>();

	FVector MoveDirection =	GetActorForwardVector() * MoveInput.X +	GetActorRightVector() * MoveInput.Y ;
	
	float DeltaSeconds = GetWorld()->GetDeltaSeconds();

	FVector MoveOffset = MoveDirection * MoveSpeed * DeltaSeconds;

	AddActorWorldOffset(MoveOffset);
}

void ADrone::Look(const FInputActionValue& Value)
{
	FVector2D LookInput = Value.Get<FVector2D>();

	float DeltaSeconds = GetWorld()->GetDeltaSeconds();

	float Yaw = LookInput.X * RotationSpeed * DeltaSeconds;
	float Pitch = LookInput.Y * RotationSpeed * DeltaSeconds;
	FRotator CurrentRotation = GetActorRotation();
	float CurrentPitch = CurrentRotation.Pitch;

	float NewPitch = FMath::Clamp(
		CurrentPitch + Pitch, 
		-60.0f, 60.0f);

	float PitchDelta = NewPitch - CurrentPitch;

	FRotator RotationDelta(PitchDelta, Yaw, 0.0f);

	AddActorLocalRotation(RotationDelta);
}

void ADrone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


