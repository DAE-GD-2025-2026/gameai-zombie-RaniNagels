// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_GameAI_Seek.h"

UBTT_GameAI_Seek::UBTT_GameAI_Seek()
{
	NodeName = TEXT("Seek");
}

EBTNodeResult::Type UBTT_GameAI_Seek::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	return EBTNodeResult::Succeeded;
}
