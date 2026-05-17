// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_GameAI_Seek.generated.h"

/**
 * 
 */
UCLASS()
class UBTT_GameAI_Seek : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTT_GameAI_Seek();

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector TargetLocationKey;

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
