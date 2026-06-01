// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_GameAI_Seek_NagelsRani.h"

UBTT_GameAI_Seek_NagelsRani::UBTT_GameAI_Seek_NagelsRani()
{
	NodeName = TEXT("Seek");
}

EBTNodeResult::Type UBTT_GameAI_Seek_NagelsRani::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	return EBTNodeResult::Succeeded;
}
