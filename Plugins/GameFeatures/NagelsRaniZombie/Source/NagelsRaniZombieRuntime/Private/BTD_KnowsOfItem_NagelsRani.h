// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "../../../../../../Source/GameAI_Zombie/Items/BaseItem.h"
#include "BTD_KnowsOfItem_NagelsRani.generated.h"

/**
 * 
 */
UCLASS()
class UBTD_KnowsOfItem_NagelsRani : public UBTDecorator
{
	GENERATED_BODY()

public:
	UBTD_KnowsOfItem_NagelsRani();

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector ObservedItemsListKey;

	UPROPERTY(EditAnywhere, Category = "Values")
	EItemType ItemType;

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
	
};
