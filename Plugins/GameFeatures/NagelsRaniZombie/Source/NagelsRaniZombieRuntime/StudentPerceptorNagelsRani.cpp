// Fill out your copyright notice in the Description page of Project Settings.

#include "StudentPerceptorNagelsRani.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "EnemyList_NagelsRani.h"
#include "ObservedItemsList_NagelsRani.h"
#include "../../../../../Source/GameAI_Zombie/Items/BaseItem.h"
#include "../../../../../Source/GameAI_Zombie/Village/House/House.h"

UStudentPerceptorNagelsRani::UStudentPerceptorNagelsRani()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UStudentPerceptorNagelsRani::BeginPlay()
{
	Super::BeginPlay();
	
	if (auto PerceptionComp = GetOwner()->GetComponentByClass<UAIPerceptionComponent>())
	{
		PerceptionComp->OnTargetPerceptionUpdated.AddDynamic(this, &UStudentPerceptorNagelsRani::OnPerceptionUpdated);
	}

	APawn* owner = Cast<APawn>(GetOwner());
	m_pController = Cast<AAIController>(owner->GetController());
	auto blackboardComp = m_pController->GetBlackboardComponent();
	if (blackboardComp)
		GEngine->AddOnScreenDebugMessage(5, 5.f, FColor::Black, FString::Printf(TEXT("controller is valid")));

	ObservedItemsList = NewObject<UObservedItemsList_NagelsRani>(this);
	EnemyList = NewObject<UEnemyList_NagelsRani>(this);
	blackboardComp->SetValueAsObject(TEXT("ObservedItemList"), ObservedItemsList);
	blackboardComp->SetValueAsObject(TEXT("EnemyList"), EnemyList);
}

void UStudentPerceptorNagelsRani::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (m_pController)
	{
		if (auto Blackboard = m_pController->GetBlackboardComponent())
		{
			Blackboard->ClearValue(TEXT("ObservedItemList"));
			Blackboard->ClearValue(TEXT("EnemyList"));
		}
	}

	ObservedItemsList = nullptr;
	EnemyList = nullptr;

	Super::EndPlay(EndPlayReason);
}

void UStudentPerceptorNagelsRani::OnPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	GEngine->AddOnScreenDebugMessage(5, 1.f, FColor::Green, FString::Printf(TEXT("Saw Something!")));

	if (!Stimulus.IsValid()) return;
	if (!IsValid(Actor))
	{
		UE_LOG(LogTemp, Warning, TEXT("Invalid Actor"));
		return;
	}

	// debug print lambda
	//auto DebugPrint = [](const FString& type)
	//	{
	//		GEngine->AddOnScreenDebugMessage(5, 5.f, FColor::Emerald, FString::Printf(TEXT("I Saw a %s!"), *type));
	//	};
	
	auto name = Actor->GetName();
	if (name.Contains("BP_House"))
	{
		//DebugPrint("House");
		ObserveItem(Actor, true);
	}
	else if (name.Contains("BP_Runner")
		|| name.Contains("BP_Heavy")
		|| name.Contains("BP_Base"))
	{
		//DebugPrint("Zombie");
		if (Stimulus.IsExpired()) // does not get called
			ChangeAmountOfEnemies(Actor, true);
		else
			ChangeAmountOfEnemies(Actor, false);
	}
	else if (name.Contains("BP_Pistol")
		|| name.Contains("BP_Shotgun")
		|| name.Contains("BP_Food")
		|| name.Contains("BP_Garbage")
		|| name.Contains("BP_Medkit"))
	{
		//DebugPrint(name);
		ObserveItem(Actor, false);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(5, 5.f, FColor::Green, FString::Printf(TEXT("Successfully Sensed: %s"), *name));
	}
}

void UStudentPerceptorNagelsRani::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	ObservedItemsList->Tick(DeltaTime);
}

void UStudentPerceptorNagelsRani::ChangeAmountOfEnemies(AActor* Actor, bool substract)
{
	auto blackboardComp = m_pController->GetBlackboardComponent();

	auto enemyList = Cast<UEnemyList_NagelsRani>(blackboardComp->GetValueAsObject("EnemyList"));
	if (enemyList)
	{
		if (substract)
			enemyList->RemoveEnemy(Actor);
		else
			enemyList->AddEnemy(Actor);

		blackboardComp->SetValueAsInt("AmountOfVisibleEnemies", enemyList->GetAmountOfEnemies());
	}
}

void UStudentPerceptorNagelsRani::ObserveItem(AActor* actor, bool house)
{
	auto blackboardComp = m_pController->GetBlackboardComponent();
	if (!blackboardComp) return;

	auto itemList = Cast<UObservedItemsList_NagelsRani>(blackboardComp->GetValueAsObject("ObservedItemList"));
	if (itemList)
	{
		if (house)
			itemList->AddHouse(Cast<AHouse>(actor));
		else itemList->AddItem(Cast<ABaseItem>(actor));
	}
}
