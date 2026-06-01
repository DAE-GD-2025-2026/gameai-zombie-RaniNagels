// Fill out your copyright notice in the Description page of Project Settings.


#include "BTD_HasBeenInitialized_NagelsRani.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTD_HasBeenInitialized_NagelsRani::UBTD_HasBeenInitialized_NagelsRani()
{
	NodeName = TEXT("Initialized?");
	FlowAbortMode = EBTFlowAbortMode::Both;
	HasBeenInitializedKey.AddBoolFilter(this,
		GET_MEMBER_NAME_CHECKED(UBTD_HasBeenInitialized_NagelsRani, HasBeenInitializedKey));
}

bool UBTD_HasBeenInitialized_NagelsRani::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	if (!Super::CalculateRawConditionValue(OwnerComp, NodeMemory))
		return false;

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComp) return false;

	return !BlackboardComp->GetValueAsBool(HasBeenInitializedKey.SelectedKeyName);
}