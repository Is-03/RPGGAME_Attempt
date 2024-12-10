// Fill out your copyright notice in the Description page of Project Settings.


#include "GAnimNotify.h"
#include "GameRCharacter.h"

void UGAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
    if (AGameRCharacter* Character = Cast<AGameRCharacter>(MeshComp->GetOwner()))
    {
        Character->OnAttackNotify(); // Call the function to handle the notify
    }
}
