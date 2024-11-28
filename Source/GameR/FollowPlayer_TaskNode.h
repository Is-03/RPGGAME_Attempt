// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "FollowPlayer_TaskNode.generated.h"

/**
 * 
 */
UCLASS()
class GAMER_API UFollowPlayer_TaskNode : public UBTTaskNode
{
	GENERATED_BODY()
	

public:
	UFollowPlayer_TaskNode();

	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector PlayerKey;

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
