// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_GoToHouse_NagelsRani.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ObservedItemsList_NagelsRani.h"
#include "AIController.h"
#include "../../../../../../Source/GameAI_Zombie/Village/House/House.h"
#include "Navigation/PathFollowingComponent.h"

UBTT_GoToHouse_NagelsRani::UBTT_GoToHouse_NagelsRani()
{
	NodeName = TEXT("Go To House");
	bNotifyTick = true;
}

EBTNodeResult::Type UBTT_GoToHouse_NagelsRani::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto blackboardComp = OwnerComp.GetBlackboardComponent();
	if (!blackboardComp) return EBTNodeResult::Failed;

	auto ObservedItemsList = blackboardComp->GetValueAsObject(ObservedItemsListKey.SelectedKeyName);
	if (!ObservedItemsList) return EBTNodeResult::Failed;

	auto ObservedItemsListCasted = Cast<UObservedItemsList_NagelsRani>(ObservedItemsList);
	if (!ObservedItemsListCasted) return EBTNodeResult::Failed;

	auto aiController = OwnerComp.GetAIOwner();
	if (!aiController) return EBTNodeResult::Failed;

	auto location = OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation();
	auto closestHouse = ObservedItemsListCasted->GetClosestHouse(location);
	if (!closestHouse) return EBTNodeResult::Failed;

	//auto result = aiController->MoveToLocation(closestHouse->GetActorLocation(), -1.f, true, true, false, true, 0, true);
	EPathFollowingRequestResult::Type Result = aiController->MoveToLocation(closestHouse->GetActorLocation());
	blackboardComp->SetValueAsObject(CurrentHouseKey.SelectedKeyName, closestHouse);
	blackboardComp->SetValueAsVector(TargetLocationKey.SelectedKeyName, closestHouse->GetActorLocation());
	blackboardComp->SetValueAsBool(AllowedToWanderKey.SelectedKeyName, false);

	if (Result == EPathFollowingRequestResult::Failed)
		return EBTNodeResult::Failed;
	
	return EBTNodeResult::InProgress;
}

void UBTT_GoToHouse_NagelsRani::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	auto AIController = OwnerComp.GetAIOwner();
	if (!AIController)
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
		return;
	}

	if (AIController->GetMoveStatus() == EPathFollowingStatus::Idle)
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	}
}
