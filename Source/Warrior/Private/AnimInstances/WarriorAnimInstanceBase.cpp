// Daniel McPherson All Rights Reserved


#include "AnimInstances/WarriorAnimInstanceBase.h"
#include "WarriorFunctionLibrary.h"

bool UWarriorAnimInstanceBase::DoesOwnerHaveTag(FGameplayTag InTagToCheck) const
{
	if (APawn* OwningPawn = TryGetPawnOwner()) 
	{
		return UWarriorFunctionLibrary::NativeDoesActorHaveTag(OwningPawn,InTagToCheck);
	}
	return false;
}
