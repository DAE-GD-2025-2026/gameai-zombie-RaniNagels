// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_Evade_NagelsRani.generated.h"

/**
 * 
 */
UCLASS()
class UBTT_Evade_NagelsRani : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTT_Evade_NagelsRani();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blackboard")
	struct FBlackboardKeySelector EnemyList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blackboard")
	float evadeDistance = 500.f;

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
