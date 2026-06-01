// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTD_IsAtLocation_NagelsRani.generated.h"

/**
 * 
 */
UCLASS()
class UBTD_IsAtLocation_NagelsRani : public UBTDecorator
{
	GENERATED_BODY()
	
public:
	UBTD_IsAtLocation_NagelsRani();

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector LocationKey;
	
	// must be big enough!!
	UPROPERTY(EditAnywhere, Category = "Blackboard")
	float MinDistance = 50.0f;

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
