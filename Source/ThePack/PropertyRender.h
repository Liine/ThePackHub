// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PropertyRender.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType )
class THEPACK_API APropertyRender : public AActor
{
	GENERATED_BODY()
	
	// Constructor declaration
	APropertyRender( const FObjectInitializer& ObjectInitializer );

public:
	UPROPERTY( BlueprintReadOnly, VisibleAnywhere, Category="Owner wolf")
	class ANPCWolf* mOwnerWolf;

	UFUNCTION( BlueprintCallable, Category = "Set owner wolf" )
	bool SetOwnerWolf( class ANPCWolf* ownerWolf );
	
};
