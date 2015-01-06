// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "WolfGameHUD.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType )
class THEPACK_API AWolfGameHUD : public AHUD
{
	GENERATED_BODY()
	
	// Constructor declaration
	AWolfGameHUD( const FObjectInitializer& ObjectInitializer );
	
};
