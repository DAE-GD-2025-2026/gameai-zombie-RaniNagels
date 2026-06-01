// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_InitBlackboardValues_NagelsRani.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTT_InitBlackboardValues_NagelsRani::UBTT_InitBlackboardValues_NagelsRani()
{
	NodeName = TEXT("Initialize Blackboard Values");
	TargetLocationKey.AddVectorFilter(this,
		GET_MEMBER_NAME_CHECKED(UBTT_InitBlackboardValues_NagelsRani, TargetLocationKey));
}

EBTNodeResult::Type UBTT_InitBlackboardValues_NagelsRani::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (Super::ExecuteTask(OwnerComp, NodeMemory) != EBTNodeResult::Succeeded)
		return EBTNodeResult::Failed;

	auto blackboardComp = OwnerComp.GetBlackboardComponent();
	if (!blackboardComp) return EBTNodeResult::Failed;

	auto ownerLocation = OwnerComp.GetOwner()->GetActorLocation();

	blackboardComp->SetValueAsVector(TargetLocationKey.SelectedKeyName, ownerLocation);
	blackboardComp->SetValueAsBool(IsInitialized.SelectedKeyName, true);
	return EBTNodeResult::Succeeded;
}
