// Fill out your copyright notice in the Description page of Project Settings.

#include "ThePack.h"
#include "NPCWolf.h"
#include "PackManager.h"
#include "WolfPointOfInterest.h"

AWolfPointOfInterest::AWolfPointOfInterest( const FObjectInitializer& ObjectInitializer ) :
	mPositionIndex( -1 ),
	Super( ObjectInitializer )
{

}

bool AWolfPointOfInterest::CanInteractWithTask( UPackMemberBaseTask* packMemberTask )
{
	if( !mInteractWithTaskClass )
	{
		return false;
	}

	return packMemberTask->GetClass() == mInteractWithTaskClass;
}

void AWolfPointOfInterest::InteractWithTask( UPackMemberBaseTask* packMemberTask )
{

}


bool AWolfPointOfInterest::DoesWolfFulFillRequirements( ANPCWolf* npcWolf, UPackManager* packManager )

{
	ERank DEBUGRANK = ERank::RANK_LAST_ENUM;

	DEBUGRANK = mDebugRank;

	bool allRequirementsMet, minRankMet, maxRankMet, requiredRankMet, minAgeMet, maxAgeMet, requiredAgeMet, genderRequirementMet;

	if( packManager == NULL )
	{
		return false;
	}

	minRankMet = mWolfRequirements.mMinRank <= npcWolf->mPackMemberData.Rank;

	maxRankMet = mWolfRequirements.mMaxRank >= npcWolf->mPackMemberData.Rank;

	requiredRankMet = mWolfRequirements.mRequiredRank == ERank::RANK_LAST_ENUM ? true : mWolfRequirements.mRequiredRank == npcWolf->mPackMemberData.Rank;

	minAgeMet = mWolfRequirements.mMinAge <= npcWolf->mPackMemberData.Age;

	maxAgeMet = mWolfRequirements.mMaxAge >= npcWolf->mPackMemberData.Age;

	requiredAgeMet = mWolfRequirements.mRequiredAge == EAge::AGE_LAST_ENUM ? true : mWolfRequirements.mRequiredAge == npcWolf->mPackMemberData.Age;

	genderRequirementMet = mWolfRequirements.mRequiredMale ? npcWolf->mPackMemberData.IsMale( ) : true && mWolfRequirements.mRequiredFemale ? !npcWolf->mPackMemberData.IsMale( ) : true;


	if( DEBUGRANK == npcWolf->mPackMemberData.Rank )
	{
		FString rankString = FString( "Wolf with rank: " );
		rankString += packManager->GetPackMemberPropertyString( npcWolf->mPackMemberData, EPackMemberProperty::EPP_Rank );

		FString ageString = FString( ", age: " );
		ageString += packManager->GetPackMemberPropertyString( npcWolf->mPackMemberData, EPackMemberProperty::EPP_Age );

		FString genderString = FString( " and gender: " );
		genderString += packManager->GetPackMemberPropertyString( npcWolf->mPackMemberData, EPackMemberProperty::EPP_Gender );

		UE_LOG( LogTemp, Log, TEXT( "%s%s%s" ), &rankString, &ageString, &genderString );
	}
	

	allRequirementsMet = minRankMet && maxRankMet && requiredRankMet && minAgeMet &&  maxAgeMet && requiredAgeMet && genderRequirementMet;

	return allRequirementsMet;
}


