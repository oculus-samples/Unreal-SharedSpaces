// Copyright (c) Meta Platforms, Inc. and its affiliates.
// Use of the material below is subject to the terms of the MIT License
// https://github.com/oculus-samples/Unreal-SharedSpaces/blob/main/Source/LICENSE


#include "SharedSpacesCharacterBase.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

// Debug macro
#define DLOG(msg) \
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5f, FColor::Green, TEXT(msg)); \
	UE_LOG(LogTemp, Warning, TEXT(msg));

ASharedSpacesCharacterBase::ASharedSpacesCharacterBase()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.8f; // For platform jumps.

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);

	// The camera follows at this distance behind the character.
	CameraBoom->TargetArmLength = 300.0f;
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

void ASharedSpacesCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

void ASharedSpacesCharacterBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void ASharedSpacesCharacterBase::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// HMD
	UsingHMD = UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled();
	if (UsingHMD)
	{
		DLOG("Using HMD");
		CameraBoom->bEnableCameraLag = true;
		CameraBoom->CameraLagMaxDistance = 1000.0;
		CameraBoom->CameraLagSpeed = 1.0;
	}

	// Set up gameplay key bindings
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	check(EnhancedInputComponent);
	
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

	EnhancedInputComponent->BindAction(MoveForwardAction, ETriggerEvent::Triggered, this, &ASharedSpacesCharacterBase::MoveForward);
	EnhancedInputComponent->BindAction(MoveRightAction, ETriggerEvent::Triggered, this, &ASharedSpacesCharacterBase::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	EnhancedInputComponent->BindAction(TurnAction, ETriggerEvent::Triggered, this, &ASharedSpacesCharacterBase::AddControllerYawInputWrapper);
	EnhancedInputComponent->BindAction(TurnRateAction, ETriggerEvent::Triggered, this, &ASharedSpacesCharacterBase::TurnAtRate);
	EnhancedInputComponent->BindAction(LookUpAction, ETriggerEvent::Triggered, this, &ASharedSpacesCharacterBase::AddControllerPitchInputWrapper);
}

void ASharedSpacesCharacterBase::TurnAtRate(const FInputActionInstance& Instance)
{
	const float Rate = Instance.GetValue().Get<float>();
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ASharedSpacesCharacterBase::AddControllerYawInputWrapper(const FInputActionInstance& Instance)
{
	const float Rate = Instance.GetValue().Get<float>();
	AddControllerYawInput(Rate);
}

void ASharedSpacesCharacterBase::AddControllerPitchInputWrapper(const FInputActionInstance& Instance)
{
	const float Rate = Instance.GetValue().Get<float>();
	AddControllerPitchInput(Rate);
}

void ASharedSpacesCharacterBase::MoveForward(const FInputActionInstance& Instance)
{
	const float Value = Instance.GetValue().Get<float>();
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ASharedSpacesCharacterBase::MoveRight(const FInputActionInstance& Instance)
{
	const float Value = Instance.GetValue().Get<float>();
	if ( (Controller != NULL) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}
