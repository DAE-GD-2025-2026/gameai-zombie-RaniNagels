// Fill out your copyright notice in the Description page of Project Settings.


#include "ObservedItemsList_NagelsRani.h"
#include "../../../../../../Source/GameAI_Zombie/Items/BaseItem.h"
#include "../../../../../../Source/GameAI_Zombie/Village/House/House.h"

UObservedItemsList_NagelsRani::UObservedItemsList_NagelsRani()
	: Super()
{
}

UObservedItemsList_NagelsRani::~UObservedItemsList_NagelsRani()
{
}

ABaseItem* UObservedItemsList_NagelsRani::GetClosestItem(const FVector& Location, EItemType type) const
{
	for (auto item : ObservedItems)
	{
		if (!item) continue;
		if (item->GetItemType() == type)
			return item;
	}
	return nullptr;
}

void UObservedItemsList_NagelsRani::AddItem(ABaseItem* Item)
{
	if (Item && !ObservedItems.Contains(Item))
	{
		ObservedItems.Add(Item);
	}
}

void UObservedItemsList_NagelsRani::RemoveItem(ABaseItem* Item)
{
	if (Item)
	{
		ObservedItems.Remove(Item);
	}
}

bool UObservedItemsList_NagelsRani::HasItemOfType(EItemType type) const
{
	for (auto item : ObservedItems)
	{
		if (!item) continue;
		if (item->GetItemType() == type)
			return true;
	}
	return false;
}

void UObservedItemsList_NagelsRani::AddHouse(AHouse* House)
{
	if (House && !ObservedHouses.Contains(House))
	{
		ObservedHouses.Add(House);
		CheckedHousesWithCounter.Add(TPair<bool, int>(false, 0));
	}
}

AHouse* UObservedItemsList_NagelsRani::GetClosestHouse(const FVector& Location)
{
	AHouse* closestHouse = nullptr;
	float closestDistance = TNumericLimits<float>::Max();

	for (auto house : ObservedHouses)
	{
		if (!house) continue;
		int index = ObservedHouses.Find(house);
		if (CheckedHousesWithCounter[index].Key) continue;
		float distance = FVector::Dist(house->GetActorLocation(), Location);
		if (!closestHouse || distance < closestDistance)
		{
			closestHouse = house;
			closestDistance = distance;
		}
	}

	return closestHouse;
}

void UObservedItemsList_NagelsRani::CheckHouse(AHouse* House)
{
	if (House)
	{
		int index = ObservedHouses.Find(House);
		if (index != INDEX_NONE)
		{
			CheckedHousesWithCounter[index].Key = true;
			CheckedHousesWithCounter[index].Value = 60; // reset counter to 60 seconds
		}
	}
}

void UObservedItemsList_NagelsRani::Tick(float deltaTime)
{
	for (auto& houseCounter : CheckedHousesWithCounter)
	{
		if (houseCounter.Key)
		{
			houseCounter.Value -= deltaTime;
		}
	}
}