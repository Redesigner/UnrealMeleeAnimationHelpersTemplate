// Copyright (c) 2025 sleepysunset


#include "Characters/Abilities/MeleeAbility.h"

#include "Abilities/Tasks/AbilityTask_PlayMontageAndWait.h"

void UMeleeAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	
	if (MeleeAnimation.IsNull())
	{
		CancelAbility(Handle, ActorInfo, ActivationInfo, false);
		return;
	}
	
	UAbilityTask_PlayMontageAndWait* PlayMontageTask = UAbilityTask_PlayMontageAndWait::CreatePlayMontageAndWaitProxy(
		this, TEXT("MeleeAnimation"), MeleeAnimation.LoadSynchronous());

	PlayMontageTask->OnCompleted.AddDynamic(this, &ThisClass::ForceEndAbility);
	PlayMontageTask->OnInterrupted.AddDynamic(this, &ThisClass::ForceEndAbility);
	PlayMontageTask->OnCancelled.AddDynamic(this, &ThisClass::ForceEndAbility);
	PlayMontageTask->ReadyForActivation();
}

void UMeleeAbility::ForceEndAbility()
{
	EndAbility(GetCurrentAbilitySpecHandle(), GetCurrentActorInfo(), GetCurrentActivationInfo(), true, false);
}
