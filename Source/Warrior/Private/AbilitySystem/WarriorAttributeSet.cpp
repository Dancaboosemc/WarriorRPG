// Daniel McPherson All Rights Reserved


#include "AbilitySystem/WarriorAttributeSet.h"

UWarriorAttributeSet::UWarriorAttributeSet()
{
	InitMaxHealth(1.f);
	InitCurrentHealth(GetMaxHealth());
	InitMaxRage(1.f);
	InitCurrentRage(GetMaxRage());
	InitAttackPower(1.f);
	InitDefensePower(1.f);
}
