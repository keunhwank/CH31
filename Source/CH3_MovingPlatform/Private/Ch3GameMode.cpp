#include "Ch3GameMode.h"
#include "Ch3Character.h"
#include "Drone.h"
#include "Ch3PlayerController.h"

ACh3GameMode::ACh3GameMode()
{
  DefaultPawnClass = ADrone::StaticClass();
  PlayerControllerClass = ACh3PlayerController::StaticClass();
}

