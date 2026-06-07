// Fill out your copyright notice in the Description page of Project Settings.


#include "BTD_IsHungry_NagelsRani.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "Common/StaminaComponent.h"

UBTD_IsHungry_NagelsRani::UBTD_IsHungry_NagelsRani()
{
	NodeName = "Is Hungry";
}

bool UBTD_IsHungry_NagelsRani::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	auto aiController = OwnerComp.GetAIOwner();
	if (!aiController) return EBTNodeResult::Failed;

	auto targetActor = aiController->GetPawn();
	if (!targetActor) return EBTNodeResult::Failed;

	auto staminaComp = targetActor->FindComponentByClass<UStaminaComponent>();
	if (!staminaComp) return EBTNodeResult::Failed;

	float currentStamina = staminaComp->GetCurrentStamina();
	float maxStamina = staminaComp->GetMaxStamina();
	float staminaPercentage = currentStamina / maxStamina;

	return staminaPercentage < 0.905f;
}

