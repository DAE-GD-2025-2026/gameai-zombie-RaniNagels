#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_GameAI_Wander_NagelsRani.generated.h"

/**
 * 
 */
UCLASS()
class UBTT_GameAI_Wander_NagelsRani: public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTT_GameAI_Wander_NagelsRani();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	float WanderRadius = 1000.f;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector TargetLocationKey;
	
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
