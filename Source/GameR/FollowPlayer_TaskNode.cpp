// Fill out your copyright notice in the Description page of Project Settings.


#include "FollowPlayer_TaskNode.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

UFollowPlayer_TaskNode::UFollowPlayer_TaskNode()
{
	NodeName = "Follow Player";
}

EBTNodeResult::Type UFollowPlayer_TaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (APawn* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0))
	{
		auto Blackboard = OwnerComp.GetBlackboardComponent();
		Blackboard->SetValueAsObject(PlayerKey.SelectedKeyName, Player);

		return EBTNodeResult::Succeeded;

	}
	
	return EBTNodeResult::Failed;
}