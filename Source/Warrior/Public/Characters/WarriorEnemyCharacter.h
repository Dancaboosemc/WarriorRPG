// Daniel McPherson All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Characters/WarriorCharacterBase.h"
#include "WarriorEnemyCharacter.generated.h"

class UEnemyCombatComponent;
/**
 * 
 */
UCLASS()
class WARRIOR_API AWarriorEnemyCharacter : public AWarriorCharacterBase
{
	GENERATED_BODY()

public:

	AWarriorEnemyCharacter();

protected:

	//~Begin APwan Interface
	virtual void PossessedBy(AController* NewController) override;
	//~End APwan Interface

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = true))
	UEnemyCombatComponent* EnemyCombatComponent;

private:

	void InitEnemyStartUpData();

public:

	FORCEINLINE UEnemyCombatComponent* GetEnemyCombatComponent() const { return EnemyCombatComponent; }
	
};
