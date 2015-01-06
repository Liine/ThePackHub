// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PackMember.h"
#include "PackHelper.h"
#include "NPCWolf.generated.h"

/**
 * 
 */
UCLASS( BlueprintType, Blueprintable )
class THEPACK_API ANPCWolf : public APackMember
{
	GENERATED_BODY()
	
	// Constructor declaration
	ANPCWolf( const FObjectInitializer& ObjectInitializer );

public:

	virtual void BeginPlay() override;

	virtual void Tick( float delTaTime ) override;

	UFUNCTION( BlueprintImplementableEvent, Category = "Property Render" )
	void OnPropertyRenderSpawned( bool success );

	UFUNCTION( BlueprintCallable, Category = "Wolf Movement Behaviour" )
	bool IsValidInterestPoint( class AWolfPointOfInterest* pointOfInterest );

	UPROPERTY( BlueprintReadOnly, EditAnywhere, Category = "Property Render" )
	TSubclassOf< class AActor > mTextRenderClass;

	UPROPERTY( BlueprintReadOnly, VisibleAnywhere, Category = "Property Render")
	class AActor* mPropertyTextRender;

};
