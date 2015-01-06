// Fill out your copyright notice in the Description page of Project Settings.

#include "ThePack.h"
#include "WolfGame.h"
#include "PackMember.h"
#include "NPCWolf.h"
#include "PlayerWolf.h"
#include "GameFramework/PlayerStart.h"
#include "PackManager.h"

UPackManager::UPackManager( const FObjectInitializer& ObjectInitializer )
: Super( ObjectInitializer )
{
}

bool UPackManager::InitPackManager( UPackHelper* packHelper, AWolfGame* wolfGame )
{
	if( packHelper )
	{
		mPackHelper = packHelper;
	}

	if( wolfGame )
	{
		mWolfGame = wolfGame;
	}

	if( !mPackHelper || !mWolfGame )
	{
		return false;
	}
	else
	{
		CreatePack( );

		OnPackManagerInit();
	}

	return true;
}

void UPackManager::TickFromWolfGame( float deltaTime )
{
	OnPackManagerTick( deltaTime );
}

void UPackManager::CreatePack( )
{
	FString infoString = FString( TEXT( "Pack Creation Started" ) );

	ANPCWolf* npcWolfPawn = NULL;

	mWolfGame->WriteToScreen( EWolfLogType::Pack_Init, infoString );

	int index = FMath::RandRange( 0, mNPCWolveClasses.Num() - 1 );

	npcWolfPawn = index >= 0 && mNPCWolveClasses.Num( ) > 0 ? SpawnWolf( mNPCWolveClasses[ index] ) : SpawnWolf( ANPCWolf::StaticClass() );


	//Create alphas
	if( mPackSetup.mHasInitialAlphas )
	{
		infoString = FString( TEXT( "Creating alpha Male" ) );
		mWolfGame->WriteToScreen( EWolfLogType::Pack_Init, infoString );

		npcWolfPawn = index >= 0 && mNPCWolveClasses.Num( ) > 0 ? SpawnWolf( mNPCWolveClasses[ index ] ) : SpawnWolf( ANPCWolf::StaticClass( ) );

		mPackHelper->CreateFPackMemberData( npcWolfPawn, EGender::Male, ERank::Alpha, EAge::Adult );

		mPackMembers.Add( npcWolfPawn );
		
		//setup alpha
		npcWolfPawn = index >= 0 && mNPCWolveClasses.Num( ) > 0 ? SpawnWolf( mNPCWolveClasses[ index ] ) : SpawnWolf( ANPCWolf::StaticClass( ) );

		infoString = FString( TEXT( "Creating alpha female" ) );
		mWolfGame->WriteToScreen( EWolfLogType::Pack_Init, infoString );

		mPackHelper->CreateFPackMemberData( npcWolfPawn, EGender::Female, ERank::Alpha, EAge::Adult );

			mPackMembers.Add( npcWolfPawn );

		//setup alpha
	}

	//create betas
	for( int32 i = 0; i < mPackSetup.mMaxInitialBetas; i++ )
	{
		infoString = FString( TEXT( "Creating beta " ) );
		mWolfGame->WriteToScreen( EWolfLogType::Pack_Init, infoString );

		int32 random = FMath::RandRange( 0, 100 );

		npcWolfPawn = index >= 0 && mNPCWolveClasses.Num( ) > 0 ? SpawnWolf( mNPCWolveClasses[ index ] ) : SpawnWolf( ANPCWolf::StaticClass( ) );

		mPackHelper->CreateFPackMemberData( npcWolfPawn, random > 50 ? EGender::Male : EGender::Female, ERank::Beta, EAge::Adult );

		mPackMembers.Add( npcWolfPawn );

		//setup betas
	}

	//create pups
	for( int32 i = 0; i < mPackSetup.mMaxInitialPups; i++ )
	{
		infoString = FString( TEXT( "Creating pup" ) );
		mWolfGame->WriteToScreen( EWolfLogType::Pack_Init, infoString );

		int32 random = FMath::RandRange( 0, 100 );

		npcWolfPawn = index >= 0 && mNPCWolveClasses.Num( ) > 0 ? SpawnWolf( mNPCWolveClasses[ index ] ) : SpawnWolf( ANPCWolf::StaticClass( ) );

		mPackHelper->CreateFPackMemberData( npcWolfPawn, random > 50 ? EGender::Male : EGender::Female, ERank::Pup, EAge::BabyPup );

		mPackMembers.Add( npcWolfPawn );
	}

	//create sentinels
	for( int32 i = 0; i < mPackSetup.mMaxSentielPairs ; i++ )
	{
		infoString = FString( TEXT( "Creating sentinel male" ) );
		mWolfGame->WriteToScreen( EWolfLogType::Pack_Init, infoString );

		npcWolfPawn = index >= 0 && mNPCWolveClasses.Num( ) > 0 ? SpawnWolf( mNPCWolveClasses[ index ] ) : SpawnWolf( ANPCWolf::StaticClass( ) );

		mPackHelper->CreateFPackMemberData( npcWolfPawn, EGender::Male, ERank::Sentinel, EAge::Adult );

		mPackMembers.Add( npcWolfPawn );

		//setup sentinel

		infoString = FString( TEXT( "Creating sentinel female" ) );
		mWolfGame->WriteToScreen( EWolfLogType::Pack_Init, infoString );

		npcWolfPawn = index >= 0 && mNPCWolveClasses.Num( ) > 0 ? SpawnWolf( mNPCWolveClasses[ index ] ) : SpawnWolf( ANPCWolf::StaticClass( ) );

		mPackHelper->CreateFPackMemberData( npcWolfPawn, EGender::Female, ERank::Sentinel, EAge::Adult );

		mPackMembers.Add( npcWolfPawn );

		//setup sentinel
	}

	if( mPackSetup.mHasInitialLeadWarror )
	{
		infoString = FString( TEXT( "Creating lead warrior" ) );
		mWolfGame->WriteToScreen( EWolfLogType::Pack_Init, infoString );

		int32 random = FMath::RandRange( 0, 100 );

		npcWolfPawn = index >= 0 && mNPCWolveClasses.Num( ) > 0 ? SpawnWolf( mNPCWolveClasses[ index ] ) : SpawnWolf( ANPCWolf::StaticClass( ) );

		mPackHelper->CreateFPackMemberData( npcWolfPawn, random > 50 ? EGender::Male : EGender::Female, ERank::LeadWarrior, EAge::Adult );

		mPackMembers.Add( npcWolfPawn );
	}

	if( mPackSetup.mHasInitialLeadHunter )
	{
		infoString = FString( TEXT( "Creating lead hunter" ) );
		mWolfGame->WriteToScreen( EWolfLogType::Pack_Init, infoString );

		int32 random = FMath::RandRange( 0, 100 );

		npcWolfPawn = index >= 0 && mNPCWolveClasses.Num( ) > 0 ? SpawnWolf( mNPCWolveClasses[ index ] ) : SpawnWolf( ANPCWolf::StaticClass( ) );

		mPackHelper->CreateFPackMemberData( npcWolfPawn, random > 50 ? EGender::Male : EGender::Female, ERank::LeadHunter, EAge::Adult );

		mPackMembers.Add( npcWolfPawn );
	}

	if( mPackSetup.mHasInitialLeadScout )
	{
		infoString = FString( TEXT( "Creating lead scout" ) );
		mWolfGame->WriteToScreen( EWolfLogType::Pack_Init, infoString );

		int32 random = FMath::RandRange( 0, 100 );

		npcWolfPawn = index >= 0 && mNPCWolveClasses.Num( ) > 0 ? SpawnWolf( mNPCWolveClasses[ index ] ) : SpawnWolf( ANPCWolf::StaticClass( ) );

		mPackHelper->CreateFPackMemberData( npcWolfPawn, random > 50 ? EGender::Male : EGender::Female, ERank::LeadScout, EAge::Adult );

		mPackMembers.Add( npcWolfPawn );
	}

	ResetPackInfo();

	mPackInfo.mMaxBetas = mPackSetup.mMaxInitialBetas;
	mPackInfo.mMaxSentiels = mPackSetup.mMaxSentielPairs * 2;
	mPackInfo.mMaxWarriorPct = mPackSetup.mWarriorPct;
	mPackInfo.mMaxHunterPct = mPackSetup.mHunterPct;

	UpdatePackInfo( false );

	CreateAdditionalWolves( mPackSetup.mAdditionalWolves );

	UpdatePackInfo();

	int32 genderRandom = FMath::RandRange( 0, 100 );
	int32 ageRand = FMath::RandRange( 0, 100 );

	int rankPct = mPackInfo.mMaxWarriorPct / 100;

	int desiredRankCount = mPackMembers.Num( ) * rankPct;

	if( mPackInfo.mMaxWarriorPct > 0 && GetWolvesOfRank( ERank::Warrior ).Num( ) < desiredRankCount )
	{
		for( int i = 0; i < desiredRankCount; i++  )
		{
			infoString = FString( TEXT( "Creating warrior" ) );
			mWolfGame->WriteToScreen( EWolfLogType::Pack_Init, infoString );

			npcWolfPawn = index >= 0 && mNPCWolveClasses.Num( ) > 0 ? SpawnWolf( mNPCWolveClasses[ index ] ) : SpawnWolf( ANPCWolf::StaticClass( ) );

			mPackHelper->CreateFPackMemberData( npcWolfPawn, genderRandom > 50 ? EGender::Male : EGender::Female, ERank::Warrior, ageRand < 70 ? EAge::Adolescent : EAge::Adult );

			mPackMembers.Add( npcWolfPawn );
		}		
	}

	rankPct = mPackInfo.mMaxHunterPct / 100;

	desiredRankCount = mPackMembers.Num( ) * rankPct;

	if( mPackInfo.mMaxWarriorPct > 0 && GetWolvesOfRank( ERank::Hunters ).Num( ) < desiredRankCount )
	{
		for( int i = 0; i < desiredRankCount; i++ )
		{
			infoString = FString( TEXT( "Creating hunter" ) );
			mWolfGame->WriteToScreen( EWolfLogType::Pack_Init, infoString );

			npcWolfPawn = index >= 0 && mNPCWolveClasses.Num( ) > 0 ? SpawnWolf( mNPCWolveClasses[ index ] ) : SpawnWolf( ANPCWolf::StaticClass( ) );

			mPackHelper->CreateFPackMemberData( npcWolfPawn, genderRandom > 50 ? EGender::Male : EGender::Female, ERank::Hunters, ageRand < 70 ? EAge::Adolescent : EAge::Adult );

			mPackMembers.Add( npcWolfPawn );
		}
	}

	if( mPackInfo.mAmountPups > 0 )
	{
		 desiredRankCount = FMath::Min( 1, mPackInfo.mAmountPups / 2 );

		for( int i = 0; i < desiredRankCount; i++  )
		{
			infoString = FString( TEXT( "Creating pupwatcher" ) );
			mWolfGame->WriteToScreen( EWolfLogType::Pack_Init, infoString );

			npcWolfPawn = index >= 0 && mNPCWolveClasses.Num( ) > 0 ? SpawnWolf( mNPCWolveClasses[ index ] ) : SpawnWolf( ANPCWolf::StaticClass( ) );

			mPackHelper->CreateFPackMemberData( npcWolfPawn, genderRandom > 50 ? EGender::Male : EGender::Female, ERank::PupWatchers, ageRand < 70 ? EAge::Adolescent : EAge::Adult );

			mPackMembers.Add( npcWolfPawn );
		}
	}

	infoString = FString( TEXT( "Pack Creation Done" ) );

	mWolfGame->WriteToScreen( EWolfLogType::Pack_Init, infoString );
}

void UPackManager::CreateAdditionalWolves( int amount )
{
	FPackMemberData newWolf;
	ANPCWolf* npcWolfPawn;
	int index;

	for( int32 i = 0; i < amount; i++ )
	{
		FString infoString = FString( TEXT( "Creating subordinate" ) );
		mWolfGame->WriteToScreen( EWolfLogType::Pack_Init, infoString );

		int32 randomGender = FMath::RandRange( 0, 100 );
		int32 randomAge = FMath::RandRange( 0, 100 );

		index = FMath::RandRange( 0, mNPCWolveClasses.Num() - 1 );

		npcWolfPawn = index >= 0 && mNPCWolveClasses.Num( ) > 0 ? SpawnWolf( mNPCWolveClasses[index] ) : SpawnWolf( ANPCWolf::StaticClass( ) );

		newWolf = mPackHelper->CreateFPackMemberData( npcWolfPawn, randomGender > 50 ? EGender::Male : EGender::Female, ERank::Subordinates, randomAge < 70 ? EAge::Adult : EAge::Adolescent );

		mPackMembers.Add( npcWolfPawn );
	}	
}

void UPackManager::UpdatePackInfo( bool resetPackInfo )
{
	FPackMemberData memberData;

	if( resetPackInfo )
	{
		ResetPackInfo();
	}


	for( int i = 0; i < mPackMembers.Num(); i++ )
	{
		memberData = mPackMembers[ i ]->mPackMemberData;

		switch( memberData.Rank )
		{
		case ERank::Alpha:

			if( memberData.IsMale( ) )
			{
				mPackInfo.mHasAlphaMale = true;
			}
			else
			{
				mPackInfo.mHasAlphaFemale = true;
			}

			break;

		case ERank::Beta:

			mPackInfo.mAmountBetas++;

			break;

		case ERank::Sentinel:

			mPackInfo.mAmountSentiels++;

			break;

		case ERank::Assassin:

			mPackInfo.mAmountAssassins++;

			break;

		case ERank::LeadWarrior:

			if( mPackInfo.mHasLeadWarrior )
			{
				//warn
			}

			mPackInfo.mHasLeadWarrior = true;

			break;

		case ERank::Warrior:

			mPackInfo.mAmountWarriors++;

			break;
		case ERank::LeadHunter:

			if( mPackInfo.mHasHasLeadHunter )
			{
				//warn
			}

			mPackInfo.mHasHasLeadHunter = true;

			break;

		case ERank::Scouts:

			mPackInfo.mAmountScouts++;

			break;

		case ERank::PupWatchers:

			mPackInfo.mAmountPupWatchers++;

			break;

		case ERank::Subordinates:

			mPackInfo.mAmountSubordinates++;

			break;

		case ERank::Omega:

			mPackInfo.mAmountOmegas++;

			break;

		case ERank::Pup:

			mPackInfo.mAmountPups++;

			break;
		
		default:
			break;
		}
	}
}

void UPackManager::ResetPackInfo()
{
	FCurrentPackInfo newPackInfo;

	mPackInfo = newPackInfo;
}

ANPCWolf* UPackManager::SpawnWolf( TSubclassOf< ANPCWolf > wolfClass )
{
	const FVector spawnLocation = mWolfGame->GetFreeWolfSpawnLocation( );

	return Cast< ANPCWolf >( mWolfGame->GetWorld( )->SpawnActor( wolfClass, &spawnLocation ) );
}

TArray< APackMember* > UPackManager::GetWolvesOfRank( ERank rank )
{
	TArray< APackMember* > wolvesByRank;

	for( int32 i = 0; i < mPackMembers.Num(); i++ )
	{
		if( mPackMembers[ i ]->mPackMemberData.Rank == rank )
		{
			wolvesByRank.Add( mPackMembers[ i ] );
		}

	}

	return wolvesByRank;
}

TArray< APackMember* > UPackManager::GetWolvesAboveRank( ERank rank )
{
	TArray< APackMember* > wolvesByRank;

	for( int32 i = 0; i < mPackMembers.Num( ); i++ )
	{
		if( mPackMembers[ i ]->mPackMemberData.Rank > rank )
		{
			wolvesByRank.Add( mPackMembers[ i ] );
		}

	}

	return wolvesByRank;
}

TArray< APackMember* > UPackManager::GetWolvesBelowRank( ERank rank )
{
	TArray< APackMember* > wolvesByRank;

	for( int32 i = 0; i < mPackMembers.Num( ); i++ )
	{
		if( mPackMembers[ i ]->mPackMemberData.Rank < rank )
		{
			wolvesByRank.Add( mPackMembers[ i ] );
		}

	}

	return wolvesByRank;
}

TArray< APackMember* > UPackManager::GetPackMembers( )
{
	return mPackMembers;
}

FString UPackManager::GetPackMemberPropertyString( FPackMemberData packMemberData, EPackMemberProperty packProperty )
{
	FString propertyString = TEXT( "HALP" );

	switch( packProperty )
	{
	case EPackMemberProperty::EPP_Age:
		propertyString = packMemberData.GetAgeString();
		break;
	case EPackMemberProperty::EPP_Gender:
		propertyString = packMemberData.GetGenderString();
		break;
	case EPackMemberProperty::EPP_Rank:
		propertyString = packMemberData.GetRankString( );
		break;
	default:
		propertyString = TEXT( "EPackMemberProperty ENUM FAIL" );
		break;
	}

	return propertyString;
}



