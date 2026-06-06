// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "../../../../../../Source/GameAI_Zombie/Items/BaseItem.h"
#include "BTT_FindItemLocation_NagelsRani.generated.h"

/**
 * 
 */
UCLASS()
class UBTT_FindItemLocation_NagelsRani : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTT_FindItemLocation_NagelsRani();

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector ObservedItemsListKey;

	UPROPERTY(EditAnywhere, Category = "Values")
	EItemType ItemType;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector TargetLocationKey;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector TargetItemKey;

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
