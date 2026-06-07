// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include <Items/ItemType.h>
#include "BTD_HasItem_NagelsRani.generated.h"

/**
 * 
 */
UCLASS()
class UBTD_HasItem_NagelsRani : public UBTDecorator
{
	GENERATED_BODY()
	
public:
	UBTD_HasItem_NagelsRani();
	virtual ~UBTD_HasItem_NagelsRani() = default;

	UPROPERTY(EditAnywhere, Category = "Values")
	EItemType ItemType;

	UPROPERTY(EditAnywhere, Category = "Value")
	int minUseAmount = 1;

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
