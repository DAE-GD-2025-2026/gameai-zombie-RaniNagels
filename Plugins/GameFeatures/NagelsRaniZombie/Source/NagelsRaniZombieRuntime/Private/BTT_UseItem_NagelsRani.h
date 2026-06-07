// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include <Items/ItemType.h>
#include "BTT_UseItem_NagelsRani.generated.h"

/**
 * 
 */
UCLASS()
class UBTT_UseItem_NagelsRani : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTT_UseItem_NagelsRani();

	UPROPERTY(EditAnywhere, Category = "Values")
	EItemType ItemType;

	UPROPERTY(EditAnywhere, Category = "Value")
	int minUseAmount = 1;

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
