// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "PackMemberBaseTask.h"
#include "PackHelper.generated.h"

// New enum
UENUM( )
enum class EGender : uint8
{
	Female = 0,
	Male = 1
};

// New enum
UENUM( )
enum class EAge : uint8
{
	BabyPup = 0,
	Pup = 1,
	Adolescent = 2,
	Adult = 3,
	Elder = 4 ,//seven years and older
	AGE_LAST_ENUM = 5
};

// New enum
UENUM( )
enum class ERank : uint8
{
	//Higher ranks
	Alpha = 0, //up to 2x
	Beta = 1, //up to 2x
	Sentinel = 2, //2 pairs ( total 4 )
	Assassin = 3, //up to 3

	//Lower ranks
	LeadWarrior = 4, //1x
	Warrior = 5, //% of pack size. 5 for small
	LeadHunter = 6, //1x
	Hunters = 7, //% if pack size, but everybody hunts, these are just skilled
	LeadScout = 8, //1x
	Scouts = 9, //scavengers fx. adolescents
	PupWatchers = 10, //up to 3, needs to be viscious
	Subordinates = 11, //basically unranked, still fight and hunt
	Omega = 12, //someone who fucked up or is bad at life
	Pup = 13, // x3
	UNSET = 14, // HALP
	RANK_LAST_ENUM = 15
};

USTRUCT( BlueprintType )
struct FPackMemberData
{
	GENERATED_USTRUCT_BODY()

	EGender Gender;

	EAge Age;

	ERank Rank;

	class APackMember* PackMember;

	TArray< UPackMemberBaseTask* > DefaultTasks;

	TArray< UPackMemberBaseTask* > ExtraTasks;

	FString GetAgeString()
	{
			switch( Age )
			{
			case EAge::BabyPup:
				return FString( TEXT( "BabyPup" ) );
				break;
			case EAge::Pup:
				return FString( TEXT( "Pup" ) );
				break;
			case EAge::Adolescent:
				return FString( TEXT( "Adolescent" ) );
				break;
			case EAge::Adult:
				return FString( TEXT( "Adult" ) );
				break;
			case EAge::Elder:
				return FString( TEXT( "Elder" ) );
				break;
			default:
				return FString( TEXT( "ERROR NO AGE" ) );
			}
	}

	FString GetGenderString()
	{
			switch( Gender )
			{
			case EGender::Female:
				return FString( TEXT( "Female" ) );
				break;
			case EGender::Male:
				return FString( TEXT( "Male" ) );
				break;
			default:
				return FString( TEXT( "ERROR NO GENDER" ) );
			}
	}

	FString GetRankString( )
	{
		switch( Rank )
		{
		case ERank::Alpha:
			return FString( TEXT( "Alpha" ) );
			break;
		case ERank::Beta:
			return FString( TEXT( "Beta" ) );
			break;
		case ERank::Sentinel:
			return FString( TEXT( "Sentinel" ) );
			break;
		case ERank::Assassin:
			return FString( TEXT( "Assassin" ) );
			break;
		case ERank::LeadWarrior:
			return FString( TEXT( "LeadWarrior" ) );
			break;
		case ERank::Warrior:
			return FString( TEXT( "Warrior" ) );
			break;
		case ERank::LeadHunter:
			return FString( TEXT( "LeadHunter" ) );
			break;
		case ERank::Hunters:
			return FString( TEXT( "Hunter" ) );
			break;
		case ERank::LeadScout:
			return FString( TEXT( "LeadScout" ) );
			break;
		case ERank::Scouts:
			return FString( TEXT( "Scout" ) );
			break;
		case ERank::PupWatchers:
			return FString( TEXT( "PupWatcher" ) );
			break;
		case ERank::Subordinates:
			return FString( TEXT( "Subordinate" ) );
			break;
		case ERank::Omega:
			return FString( TEXT( "Omega" ) );
			break;
		case ERank::Pup:
			return FString( TEXT( "Pup" ) );
			break;
		case ERank::UNSET:
			return FString( TEXT( "UNSET" ) );
			break;
		default:
			return FString( TEXT( "ERROR NO RANK" ) );
		}
	}


	inline bool IsMale()
	{
		return Gender == EGender::Male;
	}
};

/**
*
*/
UCLASS( BlueprintType )
class THEPACK_API UPackHelper : public UObject
{
	GENERATED_BODY()

	friend class UPackManager;
	friend class AWolfPointOfInterest;
	friend class ABaseWolfNavigationPoint;
	friend class APackMember;

	// Constructor declaration
	UPackHelper( const FObjectInitializer& ObjectInitializer );

	FPackMemberData CreateFPackMemberData( class APackMember* packMember, EGender gender, ERank rank, EAge age );

	void SetDefaultTasksForPackMember( class APackMember* packMember );

};
