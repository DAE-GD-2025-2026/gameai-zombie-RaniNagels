// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTD_GameAI_CanSeeEnemie.generated.h"

/**
 * 
 */
UCLASS()
class UBTD_GameAI_CanSeeEnemie : public UBTDecorator
{
	GENERATED_BODY()
	
public:
	UBTD_GameAI_CanSeeEnemie();

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector EnemyVisibleKey;

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
