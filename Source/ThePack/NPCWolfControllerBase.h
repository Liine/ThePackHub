// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "NPCWolfControllerBase.generated.h"

/**
 * 
 */
UCLASS(BLueprintable,BlueprintType)
class THEPACK_API ANPCWolfControllerBase : public AAIController
{
	GENERATED_BODY()
	
	
	ANPCWolfControllerBase( const FObjectInitializer& ObjectInitializer );

public:

	UFUNCTION( BlueprintImplementableEvent, Category="Navigation Setup")
	void OnNavigationSetup();
	
};
