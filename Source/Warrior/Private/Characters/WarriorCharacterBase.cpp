// Daniel McPherson All Rights Reserved


#include "Characters/WarriorCharacterBase.h"

// Sets default values
AWarriorCharacterBase::AWarriorCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = true;

}

