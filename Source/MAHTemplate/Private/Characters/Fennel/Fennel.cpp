// Copyright (c) 2025 sleepysunset


#include "Characters/Fennel/Fennel.h"

#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "Characters/Fennel/FennelPlayerState.h"
#include "GameFramework/SpringArmComponent.h"
#include "Hitboxes/MHHitboxComponent.h"

UAbilitySystemComponent* AFennel::GetAbilitySystemComponent() const
{
	const IAbilitySystemInterface* AbilitySystem = Cast<IAbilitySystemInterface>(GetPlayerState());
	if (!AbilitySystem)
	{
		return nullptr;
	}
	
	return AbilitySystem->GetAbilitySystemComponent();
}

AFennel::AFennel(const FObjectInitializer&)
{
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
	
	HitboxComponent = CreateDefaultSubobject<UMHHitboxComponent>(TEXT("HitboxComponent"));
}

void AFennel::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	BindActions(PlayerInputComponent);
}

void AFennel::BindActions(UInputComponent* PlayerInputComponent)
{
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
		
	EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ThisClass::Look);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::Move);
}

void AFennel::Move(const FInputActionInstance& Instance)
{
	const FVector2D Input = Instance.GetValue().Get<FVector2D>();
	if (Controller && !Input.IsNearlyZero())
	{
		const float Rotation = FollowCamera->GetComponentRotation().Yaw + 90.0f;
		const FVector2D RotatedInput = Input.GetRotated(-Rotation);
		const FVector Movement = FVector(RotatedInput.X, -RotatedInput.Y, 0.0);
		AddMovementInput(Movement);
	}
}

void AFennel::Look(const FInputActionInstance& Instance)
{
	const FVector2D Input = Instance.GetValue().Get<FVector2D>();
	const UWorld* World = GetWorld();
	
	AddControllerPitchInput(Input.Y * World->GetDeltaSeconds() * 150.0f);
	AddControllerYawInput(Input.X * World->GetDeltaSeconds() * 300.0f);
}

