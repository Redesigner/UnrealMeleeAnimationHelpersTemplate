// Copyright (c) 2025 sleepysunset

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FennelPlayerController.generated.h"

class UInputMappingContext;
/**
 * 
 */
UCLASS()
class MAHTEMPLATE_API AFennelPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = true))
	TSoftObjectPtr<UInputMappingContext> InputMappingContext;

	virtual void BeginPlay() override;
};
