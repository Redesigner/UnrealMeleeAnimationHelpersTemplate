// Copyright (c) 2025 sleepysunset

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "FennelPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class MAHTEMPLATE_API AFennelPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = Abilities, meta = (AllowPrivateAccess = true))
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;	
	
public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
};
