// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_UseItem_NagelsRani.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ObservedItemsList_NagelsRani.h"
#include <Items/BaseItem.h>
#include <Common/InventoryComponent.h>
#include "AIController.h"

UBTT_UseItem_NagelsRani::UBTT_UseItem_NagelsRani()
{
	NodeName = TEXT("Use Item");
}

EBTNodeResult::Type UBTT_UseItem_NagelsRani::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (Super::ExecuteTask(OwnerComp, NodeMemory) != EBTNodeResult::Succeeded)
		return EBTNodeResult::Failed;

	auto blackboardComp = OwnerComp.GetBlackboardComponent();
	if (!blackboardComp) return EBTNodeResult::Failed;

	auto aiController = OwnerComp.GetAIOwner();
	if (!aiController) return EBTNodeResult::Failed;

	auto targetActor = aiController->GetPawn();
	if (!targetActor) return EBTNodeResult::Failed;

	auto inventoryComp = targetActor->FindComponentByClass<UInventoryComponent>();
	if (!inventoryComp) return EBTNodeResult::Failed;

	int counter = 0;
	int index = 0;
	// find item in inventory
	for (auto item : inventoryComp->GetInventory())
	{
		if (item)
		{
			int value = item->GetValue();
			if (value == 0)
			{
				inventoryComp->RemoveItem(index);
			}
			else if (item->GetItemType() == ItemType)
			{
				if (ItemType == EItemType::Garbage)
				{
					inventoryComp->RemoveItem(index);
				}
				
				inventoryComp->UseItem(index);
				value = item->GetValue();
				if (value == 0)
				{
					inventoryComp->RemoveItem(index);
				}

				counter++;
				if (counter >= minUseAmount)
				{
					return EBTNodeResult::Succeeded;
				}
			}

		}
		++index;
	}

	return EBTNodeResult::Succeeded;
}
