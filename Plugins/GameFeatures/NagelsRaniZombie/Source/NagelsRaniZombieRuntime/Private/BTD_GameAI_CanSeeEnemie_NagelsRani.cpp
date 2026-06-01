// Fill out your copyright notice in the Description page of Project Settings.

#include "BTD_GameAI_CanSeeEnemie_NagelsRani.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include <NagelsRaniZombieRuntime/StudentPerceptorNagelsRani.h>

UBTD_GameAI_CanSeeEnemie_NagelsRani::UBTD_GameAI_CanSeeEnemie_NagelsRani()
{
	NodeName = TEXT("Can See Enemy");
	FlowAbortMode = EBTFlowAbortMode::Both;
	EnemyVisibleKey.AddIntFilter(this,
		GET_MEMBER_NAME_CHECKED(UBTD_GameAI_CanSeeEnemie_NagelsRani, EnemyVisibleKey));
}

bool UBTD_GameAI_CanSeeEnemie_NagelsRani::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	if (!Super::CalculateRawConditionValue(OwnerComp, NodeMemory))
		return false;

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComp) return false;

	int amountOfEnemies = BlackboardComp->GetValueAsInt(EnemyVisibleKey.SelectedKeyName);
	return amountOfEnemies > 0;
}
