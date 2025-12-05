// Copyright (c) 2025 sleepysunset


#include "Characters/Fennel/FennelPlayerState.h"

#include "AbilitySystemComponent.h"
#include "Characters/BaseAttributeSet.h"
#include "Characters/Abilities/AbilitySet.h"

UAbilitySystemComponent* AFennelPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

AFennelPlayerState::AFennelPlayerState(const FObjectInitializer&)
{
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AttributeSet = CreateDefaultSubobject<UBaseAttributeSet>(TEXT("AttributeSet"));
}

void AFennelPlayerState::BeginPlay()
{
	Super::BeginPlay();
	
	if (AbilitySet)
	{
		AbilitySet->GiveToAbilitySystem(AbilitySystemComponent);
	}
}
