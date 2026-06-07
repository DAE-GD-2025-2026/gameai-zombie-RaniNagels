// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_Aim_NagelsRani.generated.h"

/**
 * 
 */
UCLASS()
class UBTT_Aim_NagelsRani : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTT_Aim_NagelsRani();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blackboard")
	struct FBlackboardKeySelector EnemyListKey;

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
