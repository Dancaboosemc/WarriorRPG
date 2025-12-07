// Daniel McPherson All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "DataAsset_StartupDataBase.generated.h"

class UWarriorAbilitySystemComponent;
class UWarriorGameplayAbility;
/**
 * 
 */
UCLASS()
class WARRIOR_API UDataAsset_StartupDataBase : public UDataAsset
{
	GENERATED_BODY()

public:

	virtual void GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);

protected:

	UPROPERTY(EditDefaultsOnly, Category = "StatupData")
	TArray<TSubclassOf<UWarriorGameplayAbility>> ActivateOnGiveAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "StatupData")
	TArray<TSubclassOf<UWarriorGameplayAbility>> ReactiveAbilities;

	void GrantAbilities(const TArray<TSubclassOf<UWarriorGameplayAbility>>&  InAbilitiesToGive, UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);
	
};
