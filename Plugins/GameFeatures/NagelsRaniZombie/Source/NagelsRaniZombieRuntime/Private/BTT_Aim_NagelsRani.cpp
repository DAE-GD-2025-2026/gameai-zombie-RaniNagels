// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_Aim_NagelsRani.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include <Common/InventoryComponent.h>
#include "EnemyList_NagelsRani.h"

UBTT_Aim_NagelsRani::UBTT_Aim_NagelsRani()
{
	NodeName = TEXT("Aim");
}

EBTNodeResult::Type UBTT_Aim_NagelsRani::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// get inventory component
	auto aiController = OwnerComp.GetAIOwner();
	if (!aiController) return EBTNodeResult::Failed;

	auto targetActor = aiController->GetPawn();
	if (!targetActor) return EBTNodeResult::Failed;

	auto blackboardComp = OwnerComp.GetBlackboardComponent();
	if (!blackboardComp) return EBTNodeResult::Failed;

	auto enemyList = blackboardComp->GetValueAsObject(EnemyListKey.SelectedKeyName);
	if (!enemyList) return EBTNodeResult::Failed;

	auto enemyListCasted = Cast<UEnemyList_NagelsRani>(enemyList);
	if (!enemyListCasted) return EBTNodeResult::Failed;

	auto closestEnemy = enemyListCasted->GetClosestEnemy(targetActor->GetActorLocation());
	if (!closestEnemy) return EBTNodeResult::Failed;

	auto Direction = closestEnemy->GetActorLocation() - targetActor->GetActorLocation();
	FRotator LookAtRotation = Direction.Rotation();

	FRotator NewRotation = targetActor->GetActorRotation();
	NewRotation.Yaw = LookAtRotation.Yaw;

	targetActor->SetActorRotation(NewRotation);

	return EBTNodeResult::Succeeded;
}
