// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_MarkHouseSearched_NagelsRani.generated.h"

/**
 * 
 */
UCLASS()
class UBTT_MarkHouseSearched_NagelsRani : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTT_MarkHouseSearched_NagelsRani();

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector CurrentHouseKey;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector ObservedItemsListKey;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector AllowedToWanderKey;
	
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
