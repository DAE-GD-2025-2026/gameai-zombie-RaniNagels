// Fill out your copyright notice in the Description page of Project Settings.


#include "BTD_HasItem_NagelsRani.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ObservedItemsList_NagelsRani.h"
#include <Items/BaseItem.h>
#include <Common/InventoryComponent.h>
#include "AIController.h"

UBTD_HasItem_NagelsRani::UBTD_HasItem_NagelsRani()
{
	NodeName = "Has Item";
}

bool UBTD_HasItem_NagelsRani::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	if (!Super::CalculateRawConditionValue(OwnerComp, NodeMemory))
		return false;

	auto blackboardComp = OwnerComp.GetBlackboardComponent();
	if (!blackboardComp) return false;

	auto aiController = OwnerComp.GetAIOwner();
	if (!aiController) return false;

	auto targetActor = aiController->GetPawn();
	if (!targetActor) return false;

	auto inventoryComp = targetActor->FindComponentByClass<UInventoryComponent>();
	if (!inventoryComp) return false;

	int counter = 0;
	for (auto item : inventoryComp->GetInventory())
	{
		if (item && item->GetItemType() == ItemType)
		{
			counter++;
			if (counter >= minUseAmount)
				return true;
		}
	}

	return false;
}
