// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Abilities/GameplayAbility.h"
#include "InputMappingContext.h" 
#include "InputAction.h"
#include "GameBaseCharacter.generated.h"

UCLASS()
class GAMER_API AGameBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override
	{
		return AbilitySystemComponent;
	}

public:

	AGameBaseCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	float GetHealth() const;
	float GetMaxHealth() const;

	void SetHealth(float const NewHealth);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Ability)
	class UAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
	TArray<TSubclassOf<class UGameplayAbility>> AbilityToAcquires;

	void TryActivateAbility(int AbilityIndex);

	virtual void PossessedBy(AController* NewController) override;

	void TryActiveFirstAbility();
	void TryActiveSecondAbility();
	void TryActiveThirdAbility();
	void TryActiveFourthAbility();
	void TryActiveAbility(int AbilityIndex);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "EnhancedInput") 
	UInputMappingContext* InputMappingContext;


protected:

	virtual void BeginPlay() override;

private:
	UPROPERTY()
	class UWidgetComponent* WidgetComponent;
	float const MaxHealth{ 100.f };
	float Health;



};
