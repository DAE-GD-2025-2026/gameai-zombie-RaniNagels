// Fill out your copyright notice in the Description page of Project Settings.

#include "StudentPerceptorNagelsRani.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

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
	if (m_pController->GetBlackboardComponent())
		GEngine->AddOnScreenDebugMessage(5, 5.f, FColor::Black, FString::Printf(TEXT("controller is valid")));
}

void UStudentPerceptorNagelsRani::OnPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	GEngine->AddOnScreenDebugMessage(5, 1.f, FColor::Green, FString::Printf(TEXT("Saw Something!")));

	if (!Stimulus.IsValid()) return;

	// debug print lambda
	auto DebugPrint = [](const FString& type)
		{
			GEngine->AddOnScreenDebugMessage(5, 5.f, FColor::Emerald, FString::Printf(TEXT("I Saw a %s!"), *type));
		};
	
	auto name = Actor->GetName();
	if (name.Contains("BP_House"))
	{
		DebugPrint("House");
	}
	else if (name.Contains("BP_Runner"))
	{
		DebugPrint("Runner Zombie");
		if (Stimulus.IsExpired())
			ChangeAmountOfEnemies(true);
		else
			ChangeAmountOfEnemies(false);
	}
	else if (name.Contains("BP_Heavy"))
	{
		DebugPrint("Heavy Zombie");
		if (Stimulus.IsExpired())
			ChangeAmountOfEnemies(true);
		else
			ChangeAmountOfEnemies(false);
	}
	else if (name.Contains("BP_Base"))
	{
		DebugPrint("Base Zombie");
		if (Stimulus.IsExpired())
			ChangeAmountOfEnemies(true);
		else
			ChangeAmountOfEnemies(false);
	}
	else if (name.Contains("BP_Pistol"))
	{
		DebugPrint("Pistol");
	}
	else if (name.Contains("BP_Food"))
	{
		DebugPrint("Food");
	}
	else if (name.Contains("BP_Garbage"))
	{
		DebugPrint("Garbage");
	}
	else if (name.Contains("BP_Medkit"))
	{
		DebugPrint("MedKit");
	}
	else if (name.Contains("BP_Shotgun"))
	{
		DebugPrint("Shotgun");
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(5, 5.f, FColor::Green, FString::Printf(TEXT("Successfully Sensed: %s"), *name));
	}

	//AAIController* AIController = Cast<AAIController>(GetOwner());
	//if (!AIController) return;
	//
	//UBlackboardComponent* BlackboardComp = AIController->GetBlackboardComponent();
	//if (!BlackboardComp) return;
}

void UStudentPerceptorNagelsRani::ChangeAmountOfEnemies(bool substract)
{
	int currentEnemies = m_pController->GetBlackboardComponent()->GetValueAsInt("AmountOfVisibleEnemies");
	if (substract)
		--currentEnemies;
	else ++currentEnemies;
	m_pController->GetBlackboardComponent()->SetValueAsInt("AmountOfVisibleEnemies", currentEnemies);
}
