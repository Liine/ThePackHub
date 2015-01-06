// Fill out your copyright notice in the Description page of Project Settings.

#include "ThePack.h"
#include "PackManager.h"
#include "PackHelper.h"
#include "Engine/World.h"
#include "Engine.h"
#include "WolfPointOfInterest.h"
#include "NPCWolfControllerBase.h"
#include "WolfGame.h"

DEFINE_LOG_CATEGORY( Game_Init )
DEFINE_LOG_CATEGORY( Pack_Init )
DEFINE_LOG_CATEGORY( Pack_Info )


AWolfGame::AWolfGame( const FObjectInitializer& ObjectInitializer ) : 
	mPackManager( NULL ),
	mPackHelper( NULL ),
	Super( ObjectInitializer )
{
	InitPackComponents( ObjectInitializer );
}

void AWolfGame::Tick( float deltaTime )
{
	Super::Tick( deltaTime );

	if( mPackManager )
	{
		mPackManager->TickFromWolfGame( deltaTime );
	}
}

void AWolfGame::InitPackComponents( const FObjectInitializer& ObjectInitializer )
{
	if( !mPackHelper )
	{
		mPackHelper = ObjectInitializer.CreateDefaultSubobject<UPackHelper>( this, "PackHelper1" );
	}

	FString infoString = mPackHelper ? FString( TEXT( "PackHelper init success" ) ) : FString( TEXT( "PackHelper init fail" ) );

	WriteToScreen( EWolfLogType::Game_Init, infoString );
}

void AWolfGame::StartPlay()
{
	Super::StartPlay();

	FString infoString = TEXT( "" );

	if( !mPackManager )
	{
		if( mDefaultPackManagerClass != NULL )
		{
			infoString = TEXT( "mDefaultPackManagerClass valid" );

			mPackManager = ConstructObject<UPackManager>( mDefaultPackManagerClass );
		}
		else
		{
			infoString = TEXT( "mDefaultPackManagerClass invalid" );
		}

		WriteToScreen( EWolfLogType::Game_Init, infoString );
	}

	bool result = mPackHelper && mPackManager;

	infoString = result ? FString( TEXT( "Vaild PackHelper and PackManager" ) ) : FString( TEXT( "Invaild PackHelper or/and PackManager" ) );

	if( result )
	{
		for( int i = 0; i < PlayerStarts.Num(); i++ )
		{
			FWolfSpawnLocation wolfSpawnLocationInfo;

			wolfSpawnLocationInfo.mFree = true;
			wolfSpawnLocationInfo.mSpawnLocation = PlayerStarts[ i ]->GetActorLocation( );

			mWolfSpawnLocations.Add( wolfSpawnLocationInfo );
		}

		result = mPackManager->InitPackManager( mPackHelper, this );

		infoString = result ? FString( TEXT( "PackManager setup complete" ) ) : FString( TEXT( "PackManager setup failed" ) );
	}

	TArray<AWolfPointOfInterest*> pointOfInterest;

	for( TActorIterator<AWolfPointOfInterest> ActorItr( GetWorld( ) ); ActorItr; ++ActorItr )
	{
		pointOfInterest.Add( *ActorItr );
	}

	for( int i = 0; i < pointOfInterest.Num( ); i++ )
	{
		pointOfInterest[ i ]->mPositionIndex = i;
	}

	TArray<ANPCWolfControllerBase*> aiControllers;

	for( TActorIterator<ANPCWolfControllerBase> ActorItr( GetWorld( ) ); ActorItr; ++ActorItr )
	{
		aiControllers.Add( *ActorItr );
	}

	for( int i = 0; i < aiControllers.Num( ); i++ )
	{
		aiControllers[ i ]->OnNavigationSetup();
	}

	WriteToScreen( EWolfLogType::Pack_Init, infoString );
}

FVector AWolfGame::GetFreeWolfSpawnLocation()
{
	int randomIndex = FMath::RandRange( 0, mWolfSpawnLocations.Num() - 1 );
	int maxTries = 5;

	for( int i = 0; i < maxTries; i++ )
	{
		if( mWolfSpawnLocations[ randomIndex ].mFree )
		{
			mWolfSpawnLocations[ i ].mFree = false;

			return mWolfSpawnLocations[ randomIndex ].mSpawnLocation;
		}
		else
		{
			randomIndex = FMath::RandRange( 0, mWolfSpawnLocations.Num( ) - 1 );
		}
	}

	return FVector().ZeroVector;
}

void AWolfGame::WriteToScreen( EWolfLogType logType, FString message )
{
	if( !GEngine )
	{
		return;
	}

	switch( logType )
	{
	case EWolfLogType::Game_Init:
		GEngine->AddOnScreenDebugMessage( -1, 5.0f, FColor::Cyan, message );
		break;
	case EWolfLogType::Pack_Init:
		GEngine->AddOnScreenDebugMessage( -1, 5.0f, FColor::Magenta, message );
		break;
	case EWolfLogType::Pack_Info:
		GEngine->AddOnScreenDebugMessage( -1, 5.0f, FColor::Green, message );
		break;
	default:
		break;
	}
}


