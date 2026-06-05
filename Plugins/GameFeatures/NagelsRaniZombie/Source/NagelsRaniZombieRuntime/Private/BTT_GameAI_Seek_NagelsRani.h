// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_GameAI_Seek_NagelsRani.generated.h"

/**
 * 
 */
UCLASS()
class UBTT_GameAI_Seek_NagelsRani : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTT_GameAI_Seek_NagelsRani();

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector TargetLocationKey;

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
