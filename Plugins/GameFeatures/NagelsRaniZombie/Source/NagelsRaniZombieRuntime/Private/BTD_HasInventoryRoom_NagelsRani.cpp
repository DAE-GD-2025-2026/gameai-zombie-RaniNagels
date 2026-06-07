// Fill out your copyright notice in the Description page of Project Settings.


#include "BTD_HasInventoryRoom_NagelsRani.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include <Common/InventoryComponent.h>

UBTD_HasInventoryRoom_NagelsRani::UBTD_HasInventoryRoom_NagelsRani()
{
	NodeName = "Has Inventory Room";
}

bool UBTD_HasInventoryRoom_NagelsRani::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	// get inventory component
	auto aiController = OwnerComp.GetAIOwner();
	if (!aiController) return EBTNodeResult::Failed;

	auto targetActor = aiController->GetPawn();
	if (!targetActor) return EBTNodeResult::Failed;

	auto inventoryComp = targetActor->FindComponentByClass<UInventoryComponent>();
	if (!inventoryComp) return EBTNodeResult::Failed;

	int counter = 0;
	for (auto slot : inventoryComp->GetInventory())
	{
		if (!slot)
			counter++;
	}

	return counter > 0;
}
