// Daniel McPherson All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/WarriorAnimInstanceBase.h"
#include "WarriorCharacterAnimInstance.generated.h"

class AWarriorCharacterBase;
class UCharacterMovementComponent;
/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorCharacterAnimInstance : public UWarriorAnimInstanceBase
{
	GENERATED_BODY()
	
public:

	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:

	UPROPERTY()
	AWarriorCharacterBase* OwningCharacter;

	UPROPERTY()
	UCharacterMovementComponent* OwningMovementComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	float GroundSpeed;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bHasAcceleration;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	float LocomotionDirection;
};
