// Copyright Epic Games, Inc. All Rights Reserved.

#include "AutomationExampleGameMode.h"
#include "AutomationExampleCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAutomationExampleGameMode::AAutomationExampleGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
