// Daniel McPherson All Rights Reserved


#include "Components/Combat/EnemyCombatComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "WarriorGameplayTags.h"

#include "DebugHelper.h"

void UEnemyCombatComponent::OnHitTargetActor(AActor* HitActor)
{
		if (OverlappedActors.Contains(HitActor)) return;

		OverlappedActors.AddUnique(HitActor);
		//TODO: Implement block check
		bool bIsValidBlock = false;

		const bool bIsPlayerBlocking = false;
		const bool bIsAttackUnblockable = false;
		if (bIsPlayerBlocking && !bIsAttackUnblockable)
		{
			//TODO: check if block is valid
		}

		FGameplayEventData Data;
		Data.Instigator = GetOwningPawn();
		Data.Target = HitActor;

		if(bIsValidBlock)
		{
			//TODO::Handle successful block
		}
		else
		{
			UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(GetOwningPawn(), WarriorGameplayTags::Shared_Event_MeleeHit, Data);
		}
}
