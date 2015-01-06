// Fill out your copyright notice in the Description page of Project Settings.

#include "ThePack.h"
#include "PackMember.h"
#include "HungerControlTask.h"


UHungerControlTask::UHungerControlTask( const FObjectInitializer& ObjectInitializer ) :
	mLookForFoodThreshold( 50.0f ),
	mMaxHunger( 100 ),
	mCurrentHunger( 0 ),
	mTimesLookedForFood( 0 ),
	mHungerIncreaseRate( 0.05 ),
	Super( ObjectInitializer )
{
	//make sure we set default values if none specified
	if( mUpdateHungerIntervalInfo.mMinInterval == 0.0f )
	{
		mUpdateHungerIntervalInfo.mMinInterval = 5.0f;
		mUpdateHungerIntervalInfo.mMaxInterval = 15.0f;
	}

	mUpdateHungerIntervalInfo.mCurrentInterval = FMath::FRandRange( mUpdateHungerIntervalInfo.mMinInterval, mUpdateHungerIntervalInfo.mMaxInterval );
}


void UHungerControlTask::SetOwnerWolf( APackMember* ownerWolf )
{
	Super::SetOwnerWolf( ownerWolf );

	if( mOwnerWolf )
	{
		mUpdateHungerIntervalInfo.mLastTimeStamp = mOwnerWolf->GetWorld()->TimeSeconds;
	}
}

void UHungerControlTask::NativeTaskTick( float deltaTime )
{
	Super::NativeTaskTick( deltaTime );

	if( IsActive() )
	{
		UpdateHunger( deltaTime );

		if( LookForFoodThresholdMet( deltaTime ) )
		{
			//Inititate Look for food
		}
	}
}

void UHungerControlTask::UpdateHunger( float deltaTime )
{
	float currentSec = mOwnerWolf->GetWorld()->TimeSeconds;

	if( currentSec - mUpdateHungerIntervalInfo.mLastTimeStamp >= mUpdateHungerIntervalInfo.mCurrentInterval )
	{
		mCurrentHunger += mMaxHunger * mHungerIncreaseRate;
	}
}

bool UHungerControlTask::LookForFoodThresholdMet( float deltaTime )
{
	return mCurrentHunger >= mLookForFoodThreshold;
}

void UHungerControlTask::Cancel()
{

}

void UHungerControlTask::Reset()
{
	Super::Reset();

	mLookForFoodThreshold = 50.0f;
	mMaxHunger = 100;
	mCurrentHunger = 0;
	mTimesLookedForFood = 0;
	mHungerIncreaseRate = 0.5f;
}