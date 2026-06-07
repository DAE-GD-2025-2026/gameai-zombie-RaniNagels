// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTD_HasInventoryRoom_NagelsRani.generated.h"

/**
 * 
 */
UCLASS()
class UBTD_HasInventoryRoom_NagelsRani : public UBTDecorator
{
	GENERATED_BODY()

public:
	UBTD_HasInventoryRoom_NagelsRani();
	
protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
