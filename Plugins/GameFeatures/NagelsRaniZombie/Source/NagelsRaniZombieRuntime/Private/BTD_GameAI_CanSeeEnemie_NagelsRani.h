// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTD_GameAI_CanSeeEnemie_NagelsRani.generated.h"

/**
 * 
 */
UCLASS()
class UBTD_GameAI_CanSeeEnemie_NagelsRani : public UBTDecorator
{
	GENERATED_BODY()
	
public:
	UBTD_GameAI_CanSeeEnemie_NagelsRani();

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector EnemyList;

	UPROPERTY(EditAnywhere, Category = "Values")
	float Range = 500.f;

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
