// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_InitBlackboardValues_NagelsRani.generated.h"

/**
 * 
 */
UCLASS()
class UBTT_InitBlackboardValues_NagelsRani: public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTT_InitBlackboardValues_NagelsRani();

	// list all properties that need to be initialized!
	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector TargetLocationKey;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector IsInitialized;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector AllowedToWanderKey;

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
