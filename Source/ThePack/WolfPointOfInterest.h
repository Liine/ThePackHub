// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/TargetPoint.h"
#include "PackHelper.h"
#include "WolfPointOfInterest.generated.h"

USTRUCT( BlueprintType  )
struct FWolfRequirements
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY( BlueprintReadWrite, EditAnywhere, Category="Wolf Requirements" )
	EAge mMaxAge;

	UPROPERTY( BlueprintReadWrite, EditAnywhere, Category = "Wolf Requirements" )
	EAge mMinAge;

	UPROPERTY( BlueprintReadWrite, EditAnywhere, Category = "Wolf Requirements" )
	ERank mMaxRank;

	UPROPERTY( BlueprintReadWrite, EditAnywhere, Category = "Wolf Requirements" )
	ERank mMinRank;

	UPROPERTY( BlueprintReadWrite, EditAnywhere, Category = "Wolf Requirements" )
	EAge mRequiredAge;

	UPROPERTY( BlueprintReadWrite, EditAnywhere, Category = "Wolf Requirements" )
	ERank mRequiredRank;

	UPROPERTY( BlueprintReadWrite, EditAnywhere, Category = "Wolf Requirements" )
	bool mRequiredMale;

	UPROPERTY( BlueprintReadWrite, EditAnywhere, Category = "Wolf Requirements" )
	bool mRequiredFemale;

	FWolfRequirements() :

		mMaxAge( EAge::Elder ),
		mMinAge( EAge::BabyPup ),
		mMaxRank( ERank::Alpha ),
		mMinRank( ERank::Pup ),
		mRequiredAge( EAge::AGE_LAST_ENUM ),
		mRequiredRank( ERank::RANK_LAST_ENUM ),
		mRequiredMale( false ),
		mRequiredFemale( false )
	{

	}
};

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class THEPACK_API AWolfPointOfInterest : public ATargetPoint
{
	GENERATED_BODY( )


public:

	// Constructor declaration
	AWolfPointOfInterest( const FObjectInitializer& ObjectInitializer );

	UPROPERTY( BlueprintReadOnly, EditAnywhere, Category = "Position Index" )
	int32 mPositionIndex;

	UPROPERTY( BlueprintReadOnly, EditAnywhere, Category = "Interact Task" )
	TSubclassOf< UPackMemberBaseTask > mInteractWithTaskClass;

	UPROPERTY( BlueprintReadWrite, EditAnywhere, Category = "Debug Rank Toggle - BORK ATM" )
	ERank mDebugRank;

	UFUNCTION( BlueprintCallable, Category = "Requirements" )
	bool DoesWolfFulFillRequirements( class ANPCWolf* npcWolf, class UPackManager* packManager );

	UPROPERTY( BlueprintReadWrite, EditAnywhere, Category = "Wolf Requirements" )
	FWolfRequirements mWolfRequirements;

	UPROPERTY( BlueprintReadWrite, EditAnywhere, Category = "Amount of uses" )
	int32 mMaxAmountOfUses;

	UFUNCTION( BlueprintCallable, Category = "Interact Task" )
	bool CanInteractWithTask( UPackMemberBaseTask* packMemberTask );

	UFUNCTION( BlueprintImplementableEvent, Category = "Interact Task" )
	void OnInteractWithTask( UPackMemberBaseTask* packMemberTask );

	void InteractWithTask( UPackMemberBaseTask* packMemberTask );

	int mCurrentUses;
};
