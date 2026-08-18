#include "Ch3PlayerController.h"
#include "EnhancedInputSubsystems.h"

ACh3PlayerController::ACh3PlayerController()
  :InputMappingContext(nullptr),
  MoveAction(nullptr),
  JumpAction(nullptr),
  LookAction(nullptr),
  SprintAction(nullptr)
{
}
void ACh3PlayerController::BeginPlay()
{
  Super::BeginPlay();

  if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
  {
    if (UEnhancedInputLocalPlayerSubsystem* SubSystem =
      LocalPlayer->GetSubsystem <UEnhancedInputLocalPlayerSubsystem>())
    {
      if (InputMappingContext)
      {
        SubSystem->AddMappingContext(InputMappingContext, 0);
      }
    }
  }
}


