// Daniel McPherson All Rights Reserved


#include "WarriorFunctionLibrary.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"


UWarriorAbilitySystemComponent* UWarriorFunctionLibrary::NativeGetWarriorASCFromActor(AActor* InActor)
{
    check(InActor);

    return CastChecked<UWarriorAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InActor));
}

void UWarriorFunctionLibrary::AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd)
{
    UWarriorAbilitySystemComponent* AbilitySystemComponent = NativeGetWarriorASCFromActor(InActor);
    if (!AbilitySystemComponent->HasMatchingGameplayTag(TagToAdd))
        AbilitySystemComponent->AddLooseGameplayTag(TagToAdd);
}

void UWarriorFunctionLibrary::RemoveGameplayTagFromActorIfFound(AActor* InActor, FGameplayTag TagToRemove)
{
    UWarriorAbilitySystemComponent* AbilitySystemComponent = NativeGetWarriorASCFromActor(InActor);
    if (AbilitySystemComponent->HasMatchingGameplayTag(TagToRemove))
        AbilitySystemComponent->RemoveLooseGameplayTag(TagToRemove);
}

bool UWarriorFunctionLibrary::NativeDoesActorHaveTag(AActor* InActor, FGameplayTag TagToFind)
{
    UWarriorAbilitySystemComponent* AbilitySystemComponent = NativeGetWarriorASCFromActor(InActor);
    return AbilitySystemComponent->HasMatchingGameplayTag(TagToFind);
}

void UWarriorFunctionLibrary::BP_DoesActorHaveTag(AActor* InActor, FGameplayTag TagToFind, EWarriorConfirmType& OutConfirmType)
{
    OutConfirmType = NativeDoesActorHaveTag(InActor, TagToFind)? EWarriorConfirmType::Yes : EWarriorConfirmType::No;
}
