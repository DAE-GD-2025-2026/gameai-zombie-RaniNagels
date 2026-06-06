// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISenseConfig_Damage.h"
#include "Perception/AISense_Damage.h"
#include "Private/ObservedItemsList_NagelsRani.h"
#include "Private/EnemyList_NagelsRani.h"
#include "StudentPerceptorNagelsRani.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class NAGELSRANIZOMBIERUNTIME_API UStudentPerceptorNagelsRani : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UStudentPerceptorNagelsRani();
	
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UFUNCTION()
	virtual void OnPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	void ChangeAmountOfEnemies(AActor* Actor, bool substract);
	void ObserveItem(AActor* actor, bool house);
	AAIController* m_pController = nullptr;

	UObservedItemsList_NagelsRani* ObservedItemsList = nullptr;
	UEnemyList_NagelsRani* EnemyList = nullptr;
};
