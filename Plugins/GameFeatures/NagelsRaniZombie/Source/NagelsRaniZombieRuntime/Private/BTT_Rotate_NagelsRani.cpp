// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_Rotate_NagelsRani.h"
#include "AIController.h"

UBTT_Rotate_NagelsRani::UBTT_Rotate_NagelsRani()
{
	NodeName = TEXT("Rotate");
}

EBTNodeResult::Type UBTT_Rotate_NagelsRani::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	if (!AIController) return EBTNodeResult::Failed;

	APawn* Pawn = AIController->GetPawn();
	if (!Pawn) return EBTNodeResult::Failed;

	Pawn->SetActorRotation(FRotator(0.0f, Pawn->GetActorRotation().Yaw + 180.0f, 0.0f));

	return EBTNodeResult::Succeeded;
}
