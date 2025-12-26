// Daniel McPherson All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GenericTeamAgentInterface.h"

#include "WarriorHeroPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API AWarriorHeroPlayerController : public APlayerController, public IGenericTeamAgentInterface
{
	GENERATED_BODY()
	
	public:

		AWarriorHeroPlayerController();

		/**Begin IGenericTeamAgentInterface Interface**/
		virtual FGenericTeamId GetGenericTeamId() const override;
		/**End IGenericTeamAgentInterface Interface**/

private:

	FGenericTeamId HeroTeamID;
};
