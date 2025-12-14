// Daniel McPherson All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/StartupData/DataAsset_StartupDataBase.h"
#include "WarriorTypes/WarriorStructTypes.h"

#include "DataAsset_HeroStartupData.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API UDataAsset_HeroStartupData : public UDataAsset_StartupDataBase
{
	GENERATED_BODY()

private:

	UPROPERTY(EditDefaultsOnly, Category = "StratUpData", meta = (TitleProperty = "InputTag"))
	TArray<FWarriorAbilitySet> HeroStartupAbilitySets;

public:

	virtual void GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1) override;
	
};
