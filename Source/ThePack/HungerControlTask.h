// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PackMemberBaseTask.h"
#include "HungerControlTask.generated.h"

/**
 * 
 */
UCLASS( Blueprintable, BlueprintType )
class THEPACK_API UHungerControlTask : public UPackMemberBaseTask
{
	GENERATED_BODY()
	
	// Constructor declaration
	UHungerControlTask( const FObjectInitializer& ObjectInitializer );

public:
	UPROPERTY( BlueprintReadWrite, EditAnywhere, Category = "Hunger settings" )
	float mMaxHunger;

	UPROPERTY( BlueprintReadWrite, EditAnywhere, Category = "Hunger settings" )
	float mHungerIncreaseRate;
	
	UPROPERTY( BlueprintReadOnly, EditAnywhere, Category = "Hunger info" )
	float mCurrentHunger;

	UPROPERTY( BlueprintReadWrite, EditAnywhere, Category = "Hunger settings" )
	float mLookForFoodThreshold;

	UPROPERTY( BlueprintReadOnly, EditAnywhere, Category = "Hunger info" )
	float mTimesLookedForFood;

	UPROPERTY( BlueprintReadWrite, EditAnywhere, Category = "Hunger info" )
	float mChasingFood;

	virtual void Cancel( );

	virtual void Reset( );

	virtual void NativeTaskTick( float deltaTime );

	virtual void SetOwnerWolf( class APackMember* ownerWolf );

	bool LookForFoodThresholdMet( float deltaTime );

	UPROPERTY( BlueprintReadWrite, EditAnywhere, Category = "Hunger settings" )
	FTaskIntervalInfo mUpdateHungerIntervalInfo;

	void UpdateHunger( float deltaTime );

private:

	FTaskIntervalInfo mLookForFoodIntervalInfo;
};
