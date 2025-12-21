// Daniel McPherson All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Characters/WarriorCharacterBase.h"
#include "WarriorEnemyCharacter.generated.h"

class UEnemyCombatComponent;
class UEnemyUIComponent;
/**
 * 
 */
UCLASS()
class WARRIOR_API AWarriorEnemyCharacter : public AWarriorCharacterBase
{
	GENERATED_BODY()

public:

	AWarriorEnemyCharacter();

	//~Begin IPawnCombatInterface Interface
	virtual UPawnCombatComponent* GetPawnCombatComponent() const override;
	//~End IPawnCombatInterface Interface

	//~Begin IPawnUIInterface Interface
	virtual UPawnUIComponent* GetPawnUIComponent() const override;
	//~End IPawnUIInterface Interface

protected:

	//~Begin APwan Interface
	virtual void PossessedBy(AController* NewController) override;
	//~End APwan Interface

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = true))
	UEnemyCombatComponent* EnemyCombatComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI", meta = (AllowPrivateAccess = true))
	UEnemyUIComponent* EnemyUIComponent;

private:

	void InitEnemyStartUpData();

public:

	FORCEINLINE UEnemyCombatComponent* GetEnemyCombatComponent() const { return EnemyCombatComponent; }
	
};
