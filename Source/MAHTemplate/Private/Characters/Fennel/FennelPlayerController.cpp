// Copyright (c) 2025 sleepysunset


#include "Characters/Fennel/FennelPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"

void AFennelPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (const ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(Player))
	{
		if (UEnhancedInputLocalPlayerSubsystem* InputSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (!InputMappingContext.IsNull())
			{
				InputSystem->AddMappingContext(InputMappingContext.LoadSynchronous(), 1);
			}
		}
	}
}
