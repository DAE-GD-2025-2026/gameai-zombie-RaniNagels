// Fill out your copyright notice in the Description page of Project Settings.


#include "BTD_IsAtLocation_NagelsRani.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"

UBTD_IsAtLocation_NagelsRani::UBTD_IsAtLocation_NagelsRani()
{
	NodeName = TEXT("Is At Location");
	FlowAbortMode = EBTFlowAbortMode::Both;
}

bool UBTD_IsAtLocation_NagelsRani::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	if (!Super::CalculateRawConditionValue(OwnerComp, NodeMemory))
		return false;

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComp) return false;

	AAIController* aiController = OwnerComp.GetAIOwner();
	if (!aiController) return EBTNodeResult::Failed;

	APawn* controllerPawn = aiController->GetPawn();
	if (!controllerPawn) return EBTNodeResult::Failed;

	if (!BlackboardComp->IsVectorValueSet(LocationKey.SelectedKeyName)) return true;

	FVector Location = BlackboardComp->GetValueAsVector(LocationKey.SelectedKeyName);
	FVector ActorLocation = controllerPawn->GetActorLocation();

	float distanceX = Location.X - ActorLocation.X;
	float distanceY = Location.Y - ActorLocation.Y;
	if (FMath::Abs(distanceX) + FMath::Abs(distanceY) < MinDistance)
		return true;
	else return false;
}