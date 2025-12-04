// Copyright (c) 2025 sleepysunset

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "NativeGameplayTags.h"
#include "GameFramework/Character.h"
#include "Fennel.generated.h"

class UMHHitboxComponent;
class UInputMappingContext;
struct FInputActionInstance;
class UInputAction;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class MAHTEMPLATE_API AFennel : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = true))
	TObjectPtr<USpringArmComponent> CameraBoom;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = true))
	TObjectPtr<UCameraComponent> FollowCamera;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = true))
	TObjectPtr<UInputAction> MoveAction;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = true))
	TObjectPtr<UInputAction> LookAction;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = Abilities, meta = (AllowPrivateAccess = true))
	TObjectPtr<UMHHitboxComponent> HitboxComponent;

public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
private:
	AFennel(const FObjectInitializer& ObjectInitializer);

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	void BindActions(UInputComponent* PlayerInputComponent);
	
	// Native input actions
	void Move(const FInputActionInstance& Instance);
	void Look(const FInputActionInstance& Instance);

};
