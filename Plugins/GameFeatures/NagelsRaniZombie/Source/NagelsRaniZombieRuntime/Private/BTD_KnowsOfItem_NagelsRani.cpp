// Fill out your copyright notice in the Description page of Project Settings.


#include "BTD_KnowsOfItem_NagelsRani.h"
#include "BehaviorTree/BlackboardComponent.h"
#include <ObservedItemsList_NagelsRani.h>

UBTD_KnowsOfItem_NagelsRani::UBTD_KnowsOfItem_NagelsRani()
{
	// name based on ItemType
	auto name = UEnum::GetValueAsString(ItemType);
	NodeName = FString::Printf(TEXT("Knows of %s?"), *name);
}

bool UBTD_KnowsOfItem_NagelsRani::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	if (!Super::CalculateRawConditionValue(OwnerComp, NodeMemory))
		return false;

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComp) return false;

	auto ObservedItemsList = BlackboardComp->GetValueAsObject(ObservedItemsListKey.SelectedKeyName);
	if (!ObservedItemsList) return false;

	auto ObservedItemsListCasted = Cast<UObservedItemsList_NagelsRani>(ObservedItemsList);
	if (!ObservedItemsListCasted) return false;

	return ObservedItemsListCasted->HasItemOfType(ItemType);
}
