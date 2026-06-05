// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ObservedItemsList_NagelsRani.generated.h"

/**
 * 
 */

class ABaseItem;
class AHouse;
enum class EItemType : uint8;

UCLASS()
class UObservedItemsList_NagelsRani : public UObject
{
	GENERATED_BODY()
	
public:
	UObservedItemsList_NagelsRani();

	ABaseItem* GetClosestItem(const FVector& Location, EItemType type) const;
	void AddItem(ABaseItem* Item);
	void RemoveItem(ABaseItem* Item);
	bool HasItemOfType(EItemType type) const;

	void AddHouse(AHouse* House);
	AHouse* GetClosestHouse(const FVector& Location);
	void CheckHouse(AHouse* House);

private:
	TArray<ABaseItem*> ObservedItems;
	TArray<AHouse*> ObservedHouses;
	// bool paired with counter for that bool
	TArray<TPair<bool, int>> CheckedHousesWithCounter; // resets every 60 seconds
	float WorldTimeAtLastCheck = 0.0f;
	float TimeSinceLastCheck = 0.0f;
};
