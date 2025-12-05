// Copyright (c) 2025 sleepysunset

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "EnemyCharacter.generated.h"

class UAbilitySet;
class UBaseAttributeSet;
class UAbilitySystemComponent;

/**
 * @brief A character that has its own ASC, attribute set, and ability set.
 * Should be used for NPCs or other characters that don't have an associated
 * PlayerState to store these components in.
 */
UCLASS()
class MAHTEMPLATE_API AEnemyCharacter : public ACharacter, public IAbilitySystemInterface
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
	AEnemyCharacter();
	
	virtual void BeginPlay() override;
};
