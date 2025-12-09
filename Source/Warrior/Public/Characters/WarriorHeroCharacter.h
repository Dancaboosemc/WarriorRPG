// Daniel McPherson All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Characters/WarriorCharacterBase.h"
#include "WarriorHeroCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UDataAsset_InputConfig;
class UHeroCombatComponent;

struct FInputActionValue;
/**
 * 
 */
UCLASS()
class WARRIOR_API AWarriorHeroCharacter : public AWarriorCharacterBase
{
	GENERATED_BODY()

public:

	AWarriorHeroCharacter();
	
protected:

	//~Begin APwan Interface
	virtual void PossessedBy(AController* NewController) override;
	//~End APwan Interface

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void BeginPlay() override;

private:
#pragma region Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = true))
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = true))
	UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = true))
	UHeroCombatComponent* HeroCombatComponent;
#pragma endregion

#pragma region Inputs

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData", meta = (AllowPrivateAccess = true))
	UDataAsset_InputConfig* InputConfigDataAsset;

	void Input_Move(const FInputActionValue& InputActionValue);

	void Input_Look(const FInputActionValue& InputActionValue);

#pragma endregion

public:

	FORCEINLINE UHeroCombatComponent* GetHeroCombatComponent() const { return HeroCombatComponent; }

};
