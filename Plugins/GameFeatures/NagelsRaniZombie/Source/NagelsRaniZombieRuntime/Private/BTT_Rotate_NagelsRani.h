// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_Rotate_NagelsRani.generated.h"

/**
 * 
 */
UCLASS()
class UBTT_Rotate_NagelsRani : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTT_Rotate_NagelsRani();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
