// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "PackHelper.h"
#include "PackManager.generated.h"

UENUM()
enum class EPackMemberProperty : uint8
{
	EPP_Age = 0,
	EPP_Rank = 1,
	EPP_Gender = 3
};


USTRUCT( )
struct FPackSetupInfo
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY( BlueprintReadWrite, EditAnywhere, Category = "Pack Setup", meta = ( DisplayName = "Create alpha male and female" ) )
	bool mHasInitialAlphas;

	UPROPERTY( BlueprintReadWrite, EditAnywhere, Category = "Pack Setup", meta = ( ClampMin = "0", ClampMax = "3", DisplayName = "Initial amount of betas" ) )
	int32 mMaxInitialBetas;

	UPROPERTY( BlueprintReadWrite, EditAnywhere, Category = "Pack Setup", meta = ( ClampMin = "0", ClampMax = "6", DisplayName = "Initial amount of pubs, comes with 1 - 2 Pupwatchers( max 3) per 3-4 pups" ) )
	int32 mMaxInitialPups;

	UPROPERTY( BlueprintReadWrite, EditAnywhere, Category = "Pack Setup", meta = ( ClampMin = "0", ClampMax = "2", DisplayName = "Initial amount of sentinel pairs" ) )
	int32 mMaxSentielPairs;

	UPROPERTY( BlueprintReadWrite, EditAnywhere, Category = "Pack Setup", meta = ( DisplayName = "Create lead warrior" ) )
	bool mHasInitialLeadWarror;

	UPROPERTY( BlueprintReadWrite, EditAnywhere, Category = "Pack Setup", meta = ( ClampMin = "10", ClampMax = "25", DisplayName = "Percentage of pack as warriors" ) )
	int32 mWarriorPct;

	UPROPERTY( BlueprintReadWrite, EditAnywhere, Category = "Pack Setup", meta = ( DisplayName = "Create leader hunter" ) )
	bool mHasInitialLeadHunter;

	UPROPERTY( BlueprintReadWrite, EditAnywhere, Category = "Pack Setup", meta = ( ClampMin = "10", ClampMax = "25", DisplayName = "Percentage of pack as hunters" ) )
	int32 mHunterPct;

	UPROPERTY( BlueprintReadWrite, EditAnywhere, Category = "Pack Setup", meta = ( DisplayName = "Create scout leader" ) )
	bool mHasInitialLeadScout;

	UPROPERTY( BlueprintReadWrite, EditAnywhere, Category = "Pack Setup", meta = ( ClampMin = "0", ClampMax = "3", DisplayName = "Amount of omegas to create" ) )
	int32 mInitialOmegas;

	UPROPERTY( BlueprintReadWrite, EditAnywhere, Category = "Pack Setup", meta = ( ClampMin = "0", ClampMax = "20", DisplayName = "Additional wolves to create aside from requested wolves. Will get left over ranks" ) )
	int32 mAdditionalWolves;

};

USTRUCT( )
struct FCurrentPackInfo
{
	GENERATED_USTRUCT_BODY( )

public:
	UPROPERTY( BlueprintReadOnly, VisibleAnywhere, Category = "Pack Info", meta = ( DisplayName = "Do we have an alpha male?" ) )
	bool mHasAlphaMale;

	UPROPERTY( BlueprintReadOnly, VisibleAnywhere, Category = "Pack Info", meta = ( DisplayName = "Do we have an alpha female?" ) )
	bool mHasAlphaFemale;

	UPROPERTY( BlueprintReadOnly, VisibleAnywhere, Category = "Pack Info", meta = ( DisplayName = "Amount of betas" ) )
	int32 mAmountBetas;

	UPROPERTY( BlueprintReadOnly, VisibleAnywhere, Category = "Pack Info", meta = ( DisplayName = "Max amount of betas" ) )
	int32 mMaxBetas;

	UPROPERTY( BlueprintReadOnly, VisibleAnywhere, Category = "Pack Info", meta = ( DisplayName = "Amount of sentinels" ) )
	int32 mAmountSentiels;

	UPROPERTY( BlueprintReadOnly, VisibleAnywhere, Category = "Pack Info", meta = ( DisplayName = "Max amount of sentinels" ) )
	int32 mMaxSentiels;

	UPROPERTY( BlueprintReadOnly, VisibleAnywhere, Category = "Pack Info", meta = ( DisplayName = "Amount of assassins" ) )
	int32 mAmountAssassins;

	UPROPERTY( BlueprintReadOnly, VisibleAnywhere, Category = "Pack Info", meta = ( DisplayName = "Max amount of assassins" ) )
	int32 mMaxAssassins;

	UPROPERTY( BlueprintReadOnly, VisibleAnywhere, Category = "Pack Info", meta = ( DisplayName = "Do we have a lead warrior?" ) )
	bool mHasLeadWarrior;

	UPROPERTY( BlueprintReadOnly, VisibleAnywhere, Category = "Pack Info", meta = ( DisplayName = "Max percentage of pack as warriors" ) )
	int32 mMaxWarriorPct;

	UPROPERTY( BlueprintReadOnly, VisibleAnywhere, Category = "Pack Info", meta = ( DisplayName = "Amount of warriors" ) )
	int32 mAmountWarriors;

	UPROPERTY( BlueprintReadOnly, VisibleAnywhere, Category = "Pack Info", meta = ( DisplayName = "Do we have leader hunter" ) )
	bool mHasHasLeadHunter;

	UPROPERTY( BlueprintReadOnly, VisibleAnywhere, Category = "Pack Info", meta = ( DisplayName = "Max percentage of pack as hunters" ) )
	int32 mMaxHunterPct;

	UPROPERTY( BlueprintReadOnly, VisibleAnywhere, Category = "Pack Info", meta = ( DisplayName = "Amount of hunters" ) )
	int32 mAmountHunters;

	UPROPERTY( BlueprintReadOnly, VisibleAnywhere, Category = "Pack Info", meta = ( DisplayName = "Do we have a leader scout?" ) )
	bool mHasScoutLeader;

	UPROPERTY( BlueprintReadOnly, VisibleAnywhere, Category = "Pack Info", meta = ( DisplayName = "Amount of scouts" ) )
	int32 mAmountScouts;

	UPROPERTY( BlueprintReadOnly, VisibleAnywhere, Category = "Pack Info", meta = ( DisplayName = "Max amount of scouts" ) )
	int32 mMaxScouts;

	UPROPERTY( BlueprintReadOnly, VisibleAnywhere, Category = "Pack Info", meta = ( DisplayName = "Amount of omegas" ) )
	int32 mAmountOmegas;

	UPROPERTY( BlueprintReadOnly, VisibleAnywhere, Category = "Pack Info", meta = ( DisplayName = "Amount of pup watchers" ) )
	int32 mAmountPupWatchers;

	UPROPERTY( BlueprintReadOnly, VisibleAnywhere, Category = "Pack Info", meta = ( DisplayName = "Max amount of pup watchers" ) )
	int32 mMaxPupWatchers;

	UPROPERTY( BlueprintReadOnly, VisibleAnywhere, Category = "Pack Info", meta = ( DisplayName = "Amount of subordinates" ) )
	int32 mAmountSubordinates;

	UPROPERTY( BlueprintReadOnly, VisibleAnywhere, Category = "Pack Info", meta = ( DisplayName = "Max amount of subordinates" ) )
	int32 mMaxSubordinates;

	UPROPERTY( BlueprintReadOnly, VisibleAnywhere, Category = "Pack Info", meta = ( DisplayName = "Amount of pups" ) )
	int32 mAmountPups;

	UPROPERTY( BlueprintReadOnly, VisibleAnywhere, Category = "Pack Info", meta = ( DisplayName = "Max amount of pups" ) )
	int32 mMaxPupsAmount;

	//Constructor
	FCurrentPackInfo( ) :
		mAmountAssassins( 0 ),
		mMaxAssassins( 3 ),
		mHasAlphaMale( false ),
		mHasAlphaFemale( false ),
		mAmountBetas( 0 ),
		mMaxBetas( 2 ),
		mAmountSentiels( 0 ),
		mMaxSentiels( 4 ),
		mHasLeadWarrior( false ),
		mMaxWarriorPct( 20 ),
		mAmountWarriors( 0 ),
		mHasHasLeadHunter( false ),
		mMaxHunterPct( 15 ),
		mAmountHunters( 0 ),
		mHasScoutLeader( false ),
		mAmountScouts( 0 ),
		mMaxScouts( 4 ),
		mAmountOmegas( 0 ),
		mAmountPupWatchers( 0 ),
		mMaxSubordinates( 6 ),
		mAmountSubordinates( 0 ),
		mMaxPupsAmount( 6 ),
		mAmountPups( 0 )
	{

		mMaxPupWatchers = FMath::Min( mMaxPupsAmount / 2, 3 );
	}

};

/**
*
*/
UCLASS( BlueprintType, Blueprintable )
class THEPACK_API UPackManager : public UObject
{
	GENERATED_BODY()
	
	// Constructor declaration
	UPackManager( const FObjectInitializer& ObjectInitializer );

public:

	UPROPERTY( BlueprintReadWrite, EditAnywhere, Category = "Initial Pack Setup" )
	FPackSetupInfo mPackSetup;

	UPROPERTY( BlueprintReadOnly, VisibleAnywhere, Category = "Pack Info" )
	FCurrentPackInfo mPackInfo;

	UPROPERTY( BlueprintReadOnly, EditAnywhere, Category = "Initial Pack Setup" )
	TArray< TSubclassOf< class ANPCWolf > > mNPCWolveClasses;

	bool InitPackManager( class UPackHelper* packHelper, class AWolfGame* wolfGame );

	UFUNCTION(BlueprintCallable, Category="Pack Info", meta =( DisplayName="Get all wolves of rank"))
	TArray< class APackMember* > GetWolvesOfRank( ERank rank );

	UFUNCTION( BlueprintCallable, Category = "Pack Info", meta = ( DisplayName = "Get string property string" ) )
	FString GetPackMemberPropertyString( FPackMemberData packMemberData, EPackMemberProperty packProperty );

	UFUNCTION( BlueprintCallable, Category = "Pack Info", meta = ( DisplayName = "Get all wolves of rank" ) )
	TArray< class APackMember*  > GetWolvesBelowRank( ERank rank );

	UFUNCTION( BlueprintCallable, Category = "Pack Info", meta = ( DisplayName = "Get all wolves of rank" ) )
	TArray< class APackMember*  > GetWolvesAboveRank( ERank rank );

	UFUNCTION( BlueprintCallable, Category = "Pack Info", meta = ( DisplayName = "Get all wolves" ) )
	TArray< class APackMember*  > GetPackMembers( );

	UFUNCTION( BlueprintImplementableEvent )
	void OnPackManagerInit();

	UFUNCTION( BlueprintImplementableEvent )
	void OnPackManagerTick( float deltaTime );

	void TickFromWolfGame( float deltaTime );

private:

	//Pack info maintenance
	void CreatePack();
	void ResetPackInfo();
	void UpdatePackInfo( bool resetPackInfo = true );
	void ValidatePackData();
	void CreateAdditionalWolves( int amount );
	class ANPCWolf* SpawnWolf( TSubclassOf< class ANPCWolf > wolfClass );

	class UPackHelper* mPackHelper;
	class AWolfGame* mWolfGame;

	TArray< class APackMember* > mPackMembers;
};
