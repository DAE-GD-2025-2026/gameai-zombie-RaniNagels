// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_GameAI_Seek_NagelsRani.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Navigation/PathFollowingComponent.h"

UBTT_GameAI_Seek_NagelsRani::UBTT_GameAI_Seek_NagelsRani()
{
	NodeName = TEXT("Seek");
	bNotifyTick = true;
}

EBTNodeResult::Type UBTT_GameAI_Seek_NagelsRani::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (Super::ExecuteTask(OwnerComp, NodeMemory) != EBTNodeResult::Succeeded)
		return EBTNodeResult::Failed;

	auto blackboardComp = OwnerComp.GetBlackboardComponent();
	if (!blackboardComp) return EBTNodeResult::Failed;

	auto aiController = OwnerComp.GetAIOwner();
	if (!aiController) return EBTNodeResult::Failed;

	auto targetLocation = blackboardComp->GetValueAsVector(TargetLocationKey.SelectedKeyName);
	EPathFollowingRequestResult::Type Result = aiController->MoveToLocation(targetLocation);

	if (Result == EPathFollowingRequestResult::Failed)
		return EBTNodeResult::Failed;

	return EBTNodeResult::InProgress;
}

void UBTT_GameAI_Seek_NagelsRani::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	auto AIController = OwnerComp.GetAIOwner();
	if (!AIController)
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
		return;
	}

	if (AIController->GetMoveStatus() == EPathFollowingStatus::Idle)
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	}
}
