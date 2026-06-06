// Fill out your copyright notice in the Description page of Project Settings.


#include "BTD_HasValidHouses_NagelsRani.h"
#include "BehaviorTree/BlackboardComponent.h"
#include <ObservedItemsList_NagelsRani.h>

UBTD_HasValidHouses_NagelsRani::UBTD_HasValidHouses_NagelsRani()
{
	NodeName = TEXT("Knows of Un-Searched Houses?");
}

bool UBTD_HasValidHouses_NagelsRani::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	if (!Super::CalculateRawConditionValue(OwnerComp, NodeMemory))
		return false;

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComp) return false;

	auto ObservedItemsList = BlackboardComp->GetValueAsObject(ObservedItemsListKey.SelectedKeyName);
	if (!ObservedItemsList) return false;

	auto ObservedItemsListCasted = Cast<UObservedItemsList_NagelsRani>(ObservedItemsList);
	if (!ObservedItemsListCasted) return false;

	auto ClosestHouse = ObservedItemsListCasted->GetClosestHouse(OwnerComp.GetOwner()->GetActorLocation());
	if (!ClosestHouse) return false;

	return true;
}
