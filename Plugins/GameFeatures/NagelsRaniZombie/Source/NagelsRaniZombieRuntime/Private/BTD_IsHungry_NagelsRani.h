// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTD_IsHungry_NagelsRani.generated.h"

/**
 * 
 */
UCLASS()
class UBTD_IsHungry_NagelsRani : public UBTDecorator
{
	GENERATED_BODY()
	
public:
	UBTD_IsHungry_NagelsRani();

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
