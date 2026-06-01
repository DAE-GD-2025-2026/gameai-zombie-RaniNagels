// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_GameAI_Seek_NagelsRani.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"

UBTT_GameAI_Seek_NagelsRani::UBTT_GameAI_Seek_NagelsRani()
{
	NodeName = TEXT("Seek");
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
	aiController->MoveToLocation(targetLocation, -1.f, true, true, false, true, 0, true);

	return EBTNodeResult::Succeeded;
}
