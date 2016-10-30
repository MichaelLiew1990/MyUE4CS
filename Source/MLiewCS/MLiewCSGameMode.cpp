// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "MLiewCS.h"
#include "MLiewCSGameMode.h"
#include "MLiewCSHUD.h"
#include "MLiewCSCharacter.h"

AMLiewCSGameMode::AMLiewCSGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/Pawns/PlayerPawn"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AMLiewCSHUD::StaticClass();
}
