// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTD_IsAllowedToWander_NagelsRani.generated.h"

/**
 * 
 */
UCLASS()
class UBTD_IsAllowedToWander_NagelsRani : public UBTDecorator
{
	GENERATED_BODY()
	
public:
	UBTD_IsAllowedToWander_NagelsRani();

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector IsAllowedToWanderKey;

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
