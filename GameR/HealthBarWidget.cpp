// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthBarWidget.h"
#include "GameBaseCharacter.h"
#include "GameFramework/PlayerController.h" 
#include "Components/ProgressBar.h"
#include "Kismet/GameplayStatics.h"

void UHealthBarWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UHealthBarWidget::SetBarValuePercent(float Value)
{
    if (HealthValue)
    {
        // Ensure the value is within the expected range [0, 1] to avoid invalid progress bar values
        Value = FMath::Clamp(Value, 0.0f, 1.0f);
        HealthValue->SetPercent(Value);
    }
}



