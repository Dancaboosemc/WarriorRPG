// Daniel McPherson All Rights Reserved


#include "DataAssets/StartupData/DataAsset_HeroStartupData.h"
#include "AbilitySystem/Abilities/WarriorGameplayAbility.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"


bool FWarriorAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}

void UDataAsset_HeroStartupData::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);

	for (const FWarriorAbilitySet& AbilitySet : HeroStartupAbilitySets)
	{
		if (!AbilitySet.IsValid()) continue;

		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);

		InASCToGive->GiveAbility(AbilitySpec);
	}
}
