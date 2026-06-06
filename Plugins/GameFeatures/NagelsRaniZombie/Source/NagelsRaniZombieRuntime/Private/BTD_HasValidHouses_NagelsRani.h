// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTD_HasValidHouses_NagelsRani.generated.h"

/**
 * will check if the survivor knows houses that it has not checked recently
 */
UCLASS()
class UBTD_HasValidHouses_NagelsRani : public UBTDecorator
{
	GENERATED_BODY()
	
public:
	UBTD_HasValidHouses_NagelsRani();

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector ObservedItemsListKey;

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
