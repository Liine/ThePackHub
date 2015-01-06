// Fill out your copyright notice in the Description page of Project Settings.

#include "ThePack.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/HUD.h"
#include "WolfGame.h"
#include "PackManager.h"
#include "WolfPointOfInterest.h"
#include "PackMemberBaseTask.h"
#include "NPCWolf.h"


ANPCWolf::ANPCWolf( const FObjectInitializer& ObjectInitializer )
: Super( ObjectInitializer )
{
	SetActorTickEnabled( true );

	PrimaryActorTick.bCanEverTick = true;

	RegisterAllActorTickFunctions( true, true );

}

void ANPCWolf::BeginPlay()
{
	Super::BeginPlay();

	if( GetWorld() && mTextRenderClass != NULL )
	{
		float radius, halfHeight;
		FVector spawnLocation = GetActorLocation( );
		FRotator spawnRotation = GetActorRotation( );
		
		GetComponentsBoundingCylinder( radius, halfHeight );

		spawnLocation.Z += halfHeight * 0.8f;

		mPropertyTextRender = GetWorld( )->SpawnActor( mTextRenderClass, &spawnLocation, &spawnRotation );

		OnPropertyRenderSpawned( mPropertyTextRender != NULL );
	}

	if( Controller == NULL )
	{
		SpawnDefaultController( );
	}

	
}

void ANPCWolf::Tick( float deltaTime )
{
	Super::Tick( deltaTime );

	if( mPropertyTextRender != NULL )
	{
		FVector propertyRenderLocation;

		float radius, halfHeight;

		GetComponentsBoundingCylinder( radius, halfHeight );

		propertyRenderLocation = GetActorLocation( );

		propertyRenderLocation.Z += halfHeight * 0.8f;

		mPropertyTextRender->SetActorLocation( propertyRenderLocation );
	}
}

bool ANPCWolf::IsValidInterestPoint( AWolfPointOfInterest* pointOfInterest )
{
	return true;
}


