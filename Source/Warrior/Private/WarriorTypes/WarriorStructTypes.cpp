// Daniel McPherson All Rights Reserved


#include "WarriorTypes/WarriorStructTypes.h"
#include "AbilitySystem/Abilities/WarriorGameplayAbility.h"

bool FWarriorAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}

