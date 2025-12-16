// Daniel McPherson All Rights Reserved


#include "Characters/WarriorEnemyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/Combat/EnemyCombatComponent.h"
#include "Engine/AssetManager.h"
#include "DataAssets/StartupData/DataAsset_StartupDataBase.h"

#include "DebugHelper.h"


AWarriorEnemyCharacter::AWarriorEnemyCharacter()
{
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bUseControllerDesiredRotation = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 180.f, 0.f);
	GetCharacterMovement()->MaxWalkSpeed = 300.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 1000.f;

	EnemyCombatComponent = CreateDefaultSubobject<UEnemyCombatComponent>(TEXT("EnemyCombatComponent"));
}

void AWarriorEnemyCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	InitEnemyStartUpData();
}

void AWarriorEnemyCharacter::InitEnemyStartUpData()
{
	if (CharacterStartupData.IsNull()) return;

	UAssetManager::GetStreamableManager().RequestAsyncLoad(
		CharacterStartupData.ToSoftObjectPath(),
		FStreamableDelegate::CreateLambda(
			[this]()
			{
				if (UDataAsset_StartupDataBase* LaodedData = CharacterStartupData.Get())
				{
					LaodedData->GiveToAbilitySystemComponent(WarriorAbilitySystemComponent);

					Debug::print(TEXT("Enemy Startup Data Loaded"), FColor::Green);
				}
			}
		)
	);
}
