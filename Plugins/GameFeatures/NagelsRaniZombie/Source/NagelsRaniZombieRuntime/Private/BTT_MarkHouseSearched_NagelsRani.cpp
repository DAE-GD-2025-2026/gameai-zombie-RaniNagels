// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_MarkHouseSearched_NagelsRani.h"
#include "BehaviorTree/BlackboardComponent.h"
#include <Village/House/House.h>
#include <ObservedItemsList_NagelsRani.h>
#include "AIController.h"

UBTT_MarkHouseSearched_NagelsRani::UBTT_MarkHouseSearched_NagelsRani()
{
	NodeName = TEXT("Mark House Searched");
}

EBTNodeResult::Type UBTT_MarkHouseSearched_NagelsRani::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (Super::ExecuteTask(OwnerComp, NodeMemory) != EBTNodeResult::Succeeded)
		return EBTNodeResult::Failed;

	auto blackboardComp = OwnerComp.GetBlackboardComponent();
	if (!blackboardComp) return EBTNodeResult::Failed;

	auto currentHouse = blackboardComp->GetValueAsObject(CurrentHouseKey.SelectedKeyName);
	if (!currentHouse) return EBTNodeResult::Failed;

	auto observedItemsList = blackboardComp->GetValueAsObject(ObservedItemsListKey.SelectedKeyName);
	if (!observedItemsList) return EBTNodeResult::Failed;

	auto observedItemsListCasted = Cast<UObservedItemsList_NagelsRani>(observedItemsList);
	if (!observedItemsListCasted) return EBTNodeResult::Failed;

	observedItemsListCasted->CheckHouse(Cast<AHouse>(currentHouse));

	// invalidate blackboard value
	blackboardComp->ClearValue(CurrentHouseKey.SelectedKeyName);

	blackboardComp->SetValueAsBool(AllowedToWanderKey.SelectedKeyName, true);

	return EBTNodeResult::Succeeded;
}

