// Fill out your copyright notice in the Description page of Project Settings.

#include "BTD_GameAI_CanSeeEnemie_NagelsRani.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include <NagelsRaniZombieRuntime/StudentPerceptorNagelsRani.h>
#include "EnemyList_NagelsRani.h"

UBTD_GameAI_CanSeeEnemie_NagelsRani::UBTD_GameAI_CanSeeEnemie_NagelsRani()
{
	NodeName = TEXT("Can See Enemy");
	FlowAbortMode = EBTFlowAbortMode::Self;
}

bool UBTD_GameAI_CanSeeEnemie_NagelsRani::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	if (!Super::CalculateRawConditionValue(OwnerComp, NodeMemory))
		return false;

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComp) return false;

	// get all enemies and check distance
	UObject* object = BlackboardComp->GetValueAsObject(EnemyList.SelectedKeyName);
	if (!object)
	{
		UE_LOG(LogTemp, Warning, TEXT("enemyList not valid"));
		return false;
	}

	UEnemyList_NagelsRani* enemyList = Cast<UEnemyList_NagelsRani>(object);
	if (!enemyList)
	{
		UE_LOG(LogTemp, Warning, TEXT("enemyList not valid"));
		return false;
	}

	auto aiController = OwnerComp.GetAIOwner();
	if (!aiController) return false;

	FVector location = aiController->GetPawn()->GetActorLocation();

	int amountOfEnemies = enemyList->GetAmountOfEnemiesWithinRange(location, Range);
	return amountOfEnemies > 0;
}
