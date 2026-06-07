// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_CollectItem_NagelsRani.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ObservedItemsList_NagelsRani.h"
#include <Items/BaseItem.h>
#include <Common/InventoryComponent.h>
#include "AIController.h"

UBTT_CollectItem_NagelsRani::UBTT_CollectItem_NagelsRani()
{
	NodeName = TEXT("Collect Item");
}

EBTNodeResult::Type UBTT_CollectItem_NagelsRani::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (Super::ExecuteTask(OwnerComp, NodeMemory) != EBTNodeResult::Succeeded)
		return EBTNodeResult::Failed;

	auto blackboardComp = OwnerComp.GetBlackboardComponent();
	if (!blackboardComp) return EBTNodeResult::Failed;

	auto targetItem = blackboardComp->GetValueAsObject(TargetItemKey.SelectedKeyName);
	if (!targetItem) return EBTNodeResult::Failed;

	auto observedItemsList = blackboardComp->GetValueAsObject(ObservedItemsListKey.SelectedKeyName);
	if (!observedItemsList) return EBTNodeResult::Failed;

	auto observedItemsListCasted = Cast<UObservedItemsList_NagelsRani>(observedItemsList);
	if (!observedItemsListCasted) return EBTNodeResult::Failed;

	auto targetItemCasted = Cast<ABaseItem>(targetItem);
	if (!targetItemCasted) return EBTNodeResult::Failed;

	if (targetItemCasted->GetValue() == 0)
	{
		targetItemCasted->Destroy();
		observedItemsListCasted->RemoveItem(targetItemCasted);
		blackboardComp->ClearValue(TargetItemKey.SelectedKeyName);
		return EBTNodeResult::Succeeded;
	}

	// get inventory component
	auto aiController = OwnerComp.GetAIOwner();
	if (!aiController) return EBTNodeResult::Failed;

	auto targetActor = aiController->GetPawn();
	if (!targetActor) return EBTNodeResult::Failed;

	auto inventoryComp = targetActor->FindComponentByClass<UInventoryComponent>();
	if (!inventoryComp) return EBTNodeResult::Failed;

	// find first empty slot
	int index = 0;
	for (auto slot : inventoryComp->GetInventory())
	{
		if (!slot)
		{
			inventoryComp->GrabItem(index, targetItemCasted);
			observedItemsListCasted->RemoveItem(targetItemCasted);
			break;
		}
		index++;
	}

	// invalidate blackboard value
	blackboardComp->ClearValue(TargetItemKey.SelectedKeyName);

	return EBTNodeResult::Succeeded;
}