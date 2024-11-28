// Fill out your copyright notice in the Description page of Project Settings.


#include "GameBaseCharacter.h"
#include "Math/Vector.h"
#include "Components/WidgetComponent.h"
#include "Blueprint/UserWidget.h"
#include "HealthBarWidget.h"
#include "UObject/ConstructorHelpers.h"
#include "AbilitySystemInterface.h" 
#include "AbilitySystemComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h" 
#include "InputMappingContext.h"


const float HealthBarZ = 100.0f;

AGameBaseCharacter::AGameBaseCharacter():
	AbilitySystemComponent{ CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystem")) },
	WidgetComponent{CreateDefaultSubobject<UWidgetComponent>(TEXT("HealthValue"))},
	Health{MaxHealth}

{
	PrimaryActorTick.bCanEverTick = true;
	if (WidgetComponent)
	{
		WidgetComponent->SetupAttachment(RootComponent);
		WidgetComponent->SetWidgetSpace(EWidgetSpace::World);
		WidgetComponent->SetRelativeLocation(FVector(0.0f, 0.0f, HealthBarZ));
		static ConstructorHelpers::FClassFinder<UUserWidget>WidgetClass{ TEXT("/Game/UI/HealthBar")};
		if (WidgetClass.Succeeded())
		{
			WidgetComponent->SetWidgetClass((WidgetClass.Class));
		}
	}


}

void AGameBaseCharacter::TryActiveFirstAbility()
{
	TryActivateAbility(0);
}

void AGameBaseCharacter::TryActiveSecondAbility()
{
	TryActivateAbility(1);
}

void AGameBaseCharacter::TryActiveThirdAbility()
{
	TryActivateAbility(2);
}

void AGameBaseCharacter::TryActiveFourthAbility()
{
	TryActivateAbility(3);
}

void AGameBaseCharacter::TryActivateAbility(int AbilityIndex)
{
	check(AbilityIndex >= 0 && AbilityIndex < AbilityToAcquires.Num());
	AbilitySystemComponent->TryActivateAbilityByClass(AbilityToAcquires[AbilityIndex]);
}

void AGameBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
}



// Called when the game starts or when spawned
void AGameBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (AbilitySystemComponent)
	{
		if (AbilityToAcquires.Num() > 0)
		{
			for (const TSubclassOf<UGameplayAbility> AbilityClass : AbilityToAcquires)
			{
				FGameplayAbilitySpec Spec(AbilityClass);
				AbilitySystemComponent->GiveAbility(Spec);
			}
		}
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
}

// Called every frame
void AGameBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (UUserWidget* widget = Cast<UUserWidget>(WidgetComponent->GetUserWidgetObject()))
	{
		if (UHealthBarWidget* HealthWidget = Cast<UHealthBarWidget>(widget)) 
		{ 
			HealthWidget->SetBarValuePercent(Health / MaxHealth); 
		}
	}

}

// Called to bind functionality to input
void AGameBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Ability 1", IE_Pressed, this, &AGameBaseCharacter::TryActiveFirstAbility); 
	PlayerInputComponent->BindAction("Ability 2", IE_Pressed, this, &AGameBaseCharacter::TryActiveSecondAbility); 
	PlayerInputComponent->BindAction("Ability 3", IE_Pressed, this, &AGameBaseCharacter::TryActiveThirdAbility); 
	PlayerInputComponent->BindAction("Ability 4", IE_Pressed, this, &AGameBaseCharacter::TryActiveFourthAbility);
}

float AGameBaseCharacter::GetHealth() const
{
	return Health;
}

float AGameBaseCharacter::GetMaxHealth() const
{
	return MaxHealth;
}

void AGameBaseCharacter::SetHealth(float const NewHealth)
{
	Health = NewHealth;
}

