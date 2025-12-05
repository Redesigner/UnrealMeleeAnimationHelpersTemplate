// Copyright (c) 2025 sleepysunset

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "MeleeAbility.generated.h"

/**
 * 
 */
UCLASS()
class MAHTEMPLATE_API UMeleeAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = Melee, meta = (AllowPrivateAccess = true))
	TSoftObjectPtr<UAnimMontage> MeleeAnimation;
	
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	UFUNCTION()
	void ForceEndAbility();
};
