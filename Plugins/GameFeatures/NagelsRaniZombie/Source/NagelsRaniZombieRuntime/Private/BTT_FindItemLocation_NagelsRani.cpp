// Fill out your copyright notice in the Description page of Project Settings.

#include "BTT_FindItemLocation_NagelsRani.h"
#include "BehaviorTree/BlackboardComponent.h"
#include <ObservedItemsList_NagelsRani.h>
#include "AIController.h"

UBTT_FindItemLocation_NagelsRani::UBTT_FindItemLocation_NagelsRani()
{
	NodeName = TEXT("Find Item Location");
}

EBTNodeResult::Type UBTT_FindItemLocation_NagelsRani::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComp) return EBTNodeResult::Failed;

	auto ObservedItemsList = BlackboardComp->GetValueAsObject(ObservedItemsListKey.SelectedKeyName);
	if (!ObservedItemsList) return EBTNodeResult::Failed;

	auto ObservedItemsListCasted = Cast<UObservedItemsList_NagelsRani>(ObservedItemsList);
	if (!ObservedItemsListCasted) return EBTNodeResult::Failed;

	auto location = OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation();
	auto closestItem = ObservedItemsListCasted->GetClosestItem(location, ItemType);
	if (!closestItem) return EBTNodeResult::Failed;

	auto targetLocation = closestItem->GetActorLocation();
	BlackboardComp->SetValueAsVector(TargetLocationKey.SelectedKeyName, targetLocation);
	BlackboardComp->SetValueAsObject(TargetItemKey.SelectedKeyName, closestItem);

	return EBTNodeResult::Succeeded;
}
