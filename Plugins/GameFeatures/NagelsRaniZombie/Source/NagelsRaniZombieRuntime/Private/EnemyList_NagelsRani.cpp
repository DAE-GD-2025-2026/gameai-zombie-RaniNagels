// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyList_NagelsRani.h"
#include <UObject/FastReferenceCollector.h>
#include <Zombies/BaseZombie.h>
#include <Common/HealthComponent.h>

UEnemyList_NagelsRani::UEnemyList_NagelsRani()
	: Super()
{
}

UEnemyList_NagelsRani::~UEnemyList_NagelsRani()
{
}

AActor* UEnemyList_NagelsRani::GetClosestEnemy(const FVector& Location) const
{
	AActor* closestEnemy = nullptr;
	float closestDistance = TNumericLimits<float>::Max();
	for (auto enemy : KnownEnemies)
	{
		if (!enemy) continue;

		float distance = FVector::Dist(enemy->GetActorLocation(), Location);
		if (!closestEnemy || distance < closestDistance)
		{
			closestEnemy = enemy;
			closestDistance = distance;
		}
	}
	return closestEnemy;
}

void UEnemyList_NagelsRani::AddEnemy(AActor* Enemy)
{
	if (Enemy && !KnownEnemies.Contains(Enemy))
	{
		KnownEnemies.Add(Enemy);
		
		if (ABaseZombie* Zombie = Cast<ABaseZombie>(Enemy))
		{
			Zombie->OnDestroyed.AddDynamic(this, &UEnemyList_NagelsRani::OnEnemyDied);
		}
	}
}

void UEnemyList_NagelsRani::RemoveEnemy(AActor* Enemy)
{
	if (ABaseZombie* Zombie = Cast<ABaseZombie>(Enemy))
	{
		Zombie->OnDestroyed.RemoveDynamic(
			this,
			&UEnemyList_NagelsRani::OnEnemyDied);
	}
	KnownEnemies.Remove(Enemy);
}

int UEnemyList_NagelsRani::GetAmountOfEnemiesWithinRange(const FVector& Location, float range) const
{
	auto closestEnemy = GetClosestEnemy(Location);
	if (!closestEnemy) return 0;

	float distance = FVector::Dist(closestEnemy->GetActorLocation(), Location);
	if (distance < range)
	{
		int counter = 0;
		for (auto enemy : KnownEnemies)
		{
			if (!enemy) continue;

			float dist = FVector::Dist(enemy->GetActorLocation(), Location);
			if (dist < range)
				++counter;
		}
		return counter;
	}
	else
		return 0;
}

void UEnemyList_NagelsRani::OnEnemyDied(AActor* DeadEnemy)
{
	RemoveEnemy(DeadEnemy);
}
