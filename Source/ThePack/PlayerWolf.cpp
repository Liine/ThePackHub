// Fill out your copyright notice in the Description page of Project Settings.

#include "ThePack.h"
#include "PlayerWolf.h"


APlayerWolf::APlayerWolf(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	mCurrentAggressionLevel = 0.0f;

	mDesiredAggressionLevel = 0.0f;

	mCurrentMaxAggressionLevel = 10.0f;

	mDesiredMaxAggressionLevel = 10.0f;
}

void APlayerWolf::Tick( float deltaTime )
{
	if( mCurrentAggressionLevel != mDesiredAggressionLevel )
	{
		mCurrentAggressionLevel = FMath::Lerp( mCurrentAggressionLevel, mDesiredAggressionLevel, deltaTime );
	}

	if( mCurrentMaxAggressionLevel != mDesiredMaxAggressionLevel )
	{
		mCurrentMaxAggressionLevel = FMath::Lerp( mCurrentMaxAggressionLevel, mDesiredMaxAggressionLevel, deltaTime );
	}

	mAggressionPct = mCurrentMaxAggressionLevel / mCurrentAggressionLevel;
}



