// Copyright (c) 2025 sleepysunset

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "FennelPlayerState.generated.h"

class UAbilitySet;
class UBaseAttributeSet;
/**
 * 
 */
UCLASS()
class MAHTEMPLATE_API AFennelPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = Abilities, meta = (AllowPrivateAccess = true))
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;	
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = Abilities, meta = (AllowPrivateAccess = true))
	TObjectPtr<UBaseAttributeSet> AttributeSet;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = Abilities, meta = (AllowPrivateAccess = true))
	TObjectPtr<UAbilitySet> AbilitySet;
	
public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
private:
	AFennelPlayerState(const FObjectInitializer& ObjectInitializer);
	
	void BeginPlay() override;
};
