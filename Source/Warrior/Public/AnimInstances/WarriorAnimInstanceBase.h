// Daniel McPherson All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GameplayTagContainer.h"

#include "WarriorAnimInstanceBase.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorAnimInstanceBase : public UAnimInstance
{
	GENERATED_BODY()

protected:

	UFUNCTION(Blueprintpure, meta = (BlueprintThreadSafe))
	bool DoesOwnerHaveTag(FGameplayTag InTagToCheck) const;
	
};
