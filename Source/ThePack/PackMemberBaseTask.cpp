// Fill out your copyright notice in the Description page of Project Settings.

#include "ThePack.h"
#include "PackMemberBaseTask.h"



UPackMemberBaseTask::UPackMemberBaseTask( const FObjectInitializer& ObjectInitializer ) :
	mIsActive( false ),
	mIsPaused( false ),
	mCompleted( false ),
	mSuccess( false ),
	mTaskPriority( EPriority::PRIORITY_LAST_ENUM ),
	mCurrentDuration( 0.0f ),
	mTaskDuration( 0.0f ),
	mOwnerWolf( NULL ),
	Super( ObjectInitializer )
{

}

void UPackMemberBaseTask::NativeTaskTick( float deltaTime )
{
	if( IsActive() )
	{
		mCurrentDuration += deltaTime;

		OnTaskTick( deltaTime );

		if( mTaskDuration > 0.0f && mCurrentDuration >= mTaskDuration )
		{
			CompleteTask();
		}
	}
}

void UPackMemberBaseTask::CompleteTask()
{
	if( !mCompleted )
	{
		OnTaskCompleted( mSuccess );

		mCompleted = true;

		mIsActive = false;

		Reset();
	}
}

void UPackMemberBaseTask::Reset()
{
	if( IsActive() )
	{
		Cancel();
	}

	mIsActive = false;
	mIsPaused = false;
	mCompleted = false;
	mSuccess = false;
	mCurrentDuration = 0.0f;
	mTaskDuration = 0.0f;
	mOwnerWolf = NULL;

}

void UPackMemberBaseTask::SetOwnerWolf( APackMember* ownerWolf )
{
	mOwnerWolf = ownerWolf;
}

bool UPackMemberBaseTask::Activate()
{
	if( mIsActive  )
	{
		return false;
	}

	mIsActive = true;
	//do fancy stuff

	OnTaskActivated( mOwnerWolf );

	return mIsActive;
}

void UPackMemberBaseTask::SetPaused( bool paused )
{
	mIsPaused = paused;

	OnTaskPaused();

	//do fancy stuff
}


void UPackMemberBaseTask::Cancel()
{
	mIsActive = false;
	mIsPaused = false;

	OnTaskCancelled();
	//do fancy stuff
}


bool UPackMemberBaseTask::IsActive()
{
	return mIsActive && !mIsPaused;
}

