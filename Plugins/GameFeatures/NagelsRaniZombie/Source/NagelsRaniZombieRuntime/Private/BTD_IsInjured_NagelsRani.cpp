// Fill out your copyright notice in the Description page of Project Settings.


#include "BTD_IsInjured_NagelsRani.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "Common/HealthComponent.h"

UBTD_IsInjured_NagelsRani::UBTD_IsInjured_NagelsRani()
{
	NodeName = "Is Injured?";
}

bool UBTD_IsInjured_NagelsRani::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	auto aiController = OwnerComp.GetAIOwner();
	if (!aiController) return EBTNodeResult::Failed;

	auto targetActor = aiController->GetPawn();
	if (!targetActor) return EBTNodeResult::Failed;

	auto healthComp = targetActor->FindComponentByClass<UHealthComponent>();
	if (!healthComp) return EBTNodeResult::Failed;

	int currentHealth = healthComp->GetHealth();
	int maxHealth = healthComp->GetMaxHealth();
	float healthPercentage = float(currentHealth) / float(maxHealth);

	return healthPercentage < 0.905f;
}
