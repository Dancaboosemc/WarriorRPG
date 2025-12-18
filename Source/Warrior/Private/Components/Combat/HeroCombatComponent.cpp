// Daniel McPherson All Rights Reserved


#include "Components/Combat/HeroCombatComponent.h"
#include "Items/Weapons/WarriorHeroWeapon.h"

#include "DebugHelper.h"

AWarriorHeroWeapon* UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
	return Cast<AWarriorHeroWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTag));
}

void UHeroCombatComponent::OnHitTargetActor(AActor* HitActor)
{
	Debug::print(GetOwningPawn()->GetActorNameOrLabel() + TEXT(" Hit ") + HitActor->GetActorNameOrLabel(), FColor::Green);
}

void UHeroCombatComponent::OnWeaponPulledFromTargetActor(AActor* InteractedActor)
{
	Debug::print(GetOwningPawn()->GetActorNameOrLabel() + TEXT(" Weapon pulled from ") + InteractedActor->GetActorNameOrLabel(), FColor::Red);
}
