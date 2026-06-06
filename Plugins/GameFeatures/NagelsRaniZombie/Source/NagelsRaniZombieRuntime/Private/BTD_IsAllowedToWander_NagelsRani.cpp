// Fill out your copyright notice in the Description page of Project Settings.


#include "BTD_IsAllowedToWander_NagelsRani.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTD_IsAllowedToWander_NagelsRani::UBTD_IsAllowedToWander_NagelsRani()
{
	NodeName = TEXT("Is Allowed To Wander?");
	FlowAbortMode = EBTFlowAbortMode::Self;
}

bool UBTD_IsAllowedToWander_NagelsRani::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	if (!Super::CalculateRawConditionValue(OwnerComp, NodeMemory))
		return false;

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComp) return false;

	//if (BlackboardComp->Clear)

	return BlackboardComp->GetValueAsBool(IsAllowedToWanderKey.SelectedKeyName);
}
