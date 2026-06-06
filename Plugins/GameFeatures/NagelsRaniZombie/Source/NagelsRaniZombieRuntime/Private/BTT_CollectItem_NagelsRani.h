// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_CollectItem_NagelsRani.generated.h"

/**
 * 
 */
UCLASS()
class UBTT_CollectItem_NagelsRani : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTT_CollectItem_NagelsRani();

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector TargetItemKey;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector ObservedItemsListKey;

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
