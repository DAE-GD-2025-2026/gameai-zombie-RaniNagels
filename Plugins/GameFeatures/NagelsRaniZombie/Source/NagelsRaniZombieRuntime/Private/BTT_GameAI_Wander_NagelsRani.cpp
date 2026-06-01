// Fill out your copyright notice in the Description page of Project Settings.

#include "BTT_GameAI_Wander_NagelsRani.h"

#include "AIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTT_GameAI_Wander_NagelsRani::UBTT_GameAI_Wander_NagelsRani()
{
	NodeName = TEXT("Find Wander Location");
}

EBTNodeResult::Type UBTT_GameAI_Wander_NagelsRani::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* aiController = OwnerComp.GetAIOwner();
	if (!aiController) return EBTNodeResult::Failed;

	APawn* controllerPawn = aiController->GetPawn();
	if (!controllerPawn) return EBTNodeResult::Failed;

	FNavLocation randomLocation;
	UNavigationSystemV1* navSystem = UNavigationSystemV1::GetCurrent(GetWorld());

	if (navSystem && navSystem->GetRandomReachablePointInRadius(controllerPawn->GetActorLocation(), WanderRadius, randomLocation))
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(TargetLocationKey.SelectedKeyName, randomLocation.Location);
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
