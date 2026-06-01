// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTD_HasBeenInitialized_NagelsRani.generated.h"

/**
 * 
 */
UCLASS()
class UBTD_HasBeenInitialized_NagelsRani : public UBTDecorator
{
	GENERATED_BODY()
	
public:
	UBTD_HasBeenInitialized_NagelsRani();

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector HasBeenInitializedKey;

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
