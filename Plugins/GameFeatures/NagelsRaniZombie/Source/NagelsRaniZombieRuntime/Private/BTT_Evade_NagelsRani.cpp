// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_Evade_NagelsRani.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "EnemyList_NagelsRani.h"

UBTT_Evade_NagelsRani::UBTT_Evade_NagelsRani()
{
	NodeName = TEXT("Evade");
}

EBTNodeResult::Type UBTT_Evade_NagelsRani::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (Super::ExecuteTask(OwnerComp, NodeMemory) != EBTNodeResult::Succeeded)
		return EBTNodeResult::Failed;

	auto blackboardComp = OwnerComp.GetBlackboardComponent();
	if (!blackboardComp) return EBTNodeResult::Failed;

	auto aiController = OwnerComp.GetAIOwner();
	if (!aiController) return EBTNodeResult::Failed;

	UEnemyList_NagelsRani* enemyList = Cast<UEnemyList_NagelsRani>(blackboardComp->GetValueAsObject(EnemyList.SelectedKeyName));
	if (!enemyList) return EBTNodeResult::Failed;

	AActor* actorToEvade = enemyList->GetClosestEnemy(aiController->GetPawn()->GetActorLocation());
	if (!actorToEvade) return EBTNodeResult::Failed;

	// calculate where the actor to evade is going to be in the future
	FVector actorToEvadeLocation = actorToEvade->GetActorLocation();
	FVector survivorLocation = aiController->GetPawn()->GetActorLocation();
	FVector distance = actorToEvadeLocation - survivorLocation;

	if (distance.Size() < evadeDistance)
	{
		// find a location in the opposite direction of the actor to evade
		FVector evadeDirection = -distance.GetSafeNormal();
		FVector evadeLocation = survivorLocation + evadeDirection * evadeDistance;
		aiController->MoveToLocation(evadeLocation, -1.f, true, true, false, true, 0, true);
	}

	return EBTNodeResult::Succeeded;
}
