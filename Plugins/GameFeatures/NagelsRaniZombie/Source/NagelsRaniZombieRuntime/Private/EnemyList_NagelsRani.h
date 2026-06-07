// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EnemyList_NagelsRani.generated.h"

/**
 * 
 */
UCLASS()
class UEnemyList_NagelsRani : public UObject
{
	GENERATED_BODY()
	
public:
	UEnemyList_NagelsRani();
	virtual ~UEnemyList_NagelsRani();

	AActor* GetClosestEnemy(const FVector& Location) const;
	void AddEnemy(AActor* Enemy);
	void RemoveEnemy(AActor* Enemy);
	int GetAmountOfEnemies() const { return KnownEnemies.Num(); }
	int GetAmountOfEnemiesWithinRange(const FVector& Location, float range) const;

private:
	UFUNCTION()
	void OnEnemyDied(AActor* DeadEnemy);

	UPROPERTY()
	TArray<TObjectPtr<AActor>> KnownEnemies;
};
