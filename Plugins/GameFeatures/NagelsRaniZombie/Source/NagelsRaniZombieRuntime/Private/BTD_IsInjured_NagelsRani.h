// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTD_IsInjured_NagelsRani.generated.h"

/**
 * 
 */
UCLASS()
class UBTD_IsInjured_NagelsRani : public UBTDecorator
{
	GENERATED_BODY()
	
public:
	UBTD_IsInjured_NagelsRani();

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
