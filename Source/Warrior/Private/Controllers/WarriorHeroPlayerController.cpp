// Daniel McPherson All Rights Reserved


#include "Controllers/WarriorHeroPlayerController.h"

AWarriorHeroPlayerController::AWarriorHeroPlayerController()
{
    HeroTeamID = FGenericTeamId(0);
}

FGenericTeamId AWarriorHeroPlayerController::GetGenericTeamId() const
{
    return HeroTeamID;
}
