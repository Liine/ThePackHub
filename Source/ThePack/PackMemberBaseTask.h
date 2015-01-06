// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "PackMemberBaseTask.generated.h"

// New enum
UENUM( )
enum class EPriority : uint8
{
	P_HIGH = 0,
	P_MEDIUM = 1,
	P_LOW = 2,
	P_NO_PRIO = 3,
	PRIORITY_LAST_ENUM = 4
};

USTRUCT( BlueprintType )
struct FTaskIntervalInfo
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY( BlueprintReadOnly, EditAnywhere, Category="Interval setup")
	float mMinInterval;

	UPROPERTY( BlueprintReadOnly, EditAnywhere, Category = "Interval setup" )
	float mMaxInterval;

	UPROPERTY( BlueprintReadOnly, EditAnywhere, Category = "Interval setup" )
	float mCurrentInterval;

	UPROPERTY( BlueprintReadOnly, EditAnywhere, Category = "Interval setup" )
	float mLastTimeStamp;

	FTaskIntervalInfo() :
		mMinInterval( 0 ),
		mMaxInterval( 0 ),
		mCurrentInterval( 0 ),
		mLastTimeStamp( 0 )
	{

	}
};


/**
 * 
 */
UCLASS( Abstract )
class THEPACK_API UPackMemberBaseTask : public UObject
{
	GENERATED_BODY()

public:	
	// Constructor declaration
	UPackMemberBaseTask( const FObjectInitializer& ObjectInitializer );

	UPROPERTY( BlueprintReadOnly, EditAnywhere, Category = "Task Base Setup" )
	float mTaskDuration;

	UPROPERTY( BlueprintReadOnly, EditAnywhere, Category = "Task Base Info" )
	float mCurrentDuration;

	UPROPERTY( BlueprintReadOnly, EditAnywhere, Category = "Task Base Info" )
	bool mCompleted;

	UPROPERTY( BlueprintReadOnly, EditAnywhere, Category = "Task Base Info" )
	bool mSuccess;

	UPROPERTY( BlueprintReadOnly, EditAnywhere, Category = "Task Base Info" )
	class APackMember* mOwnerWolf;

	UPROPERTY( BlueprintReadOnly, EditAnywhere, Category = "Task Base Info" )
	EPriority mTaskPriority;

	UFUNCTION( BlueprintCallable, Category = "Task Base Info" )
	virtual bool IsActive( );

	/******************************************************/
	/*					BLUEPRINT EVENTS				  */
	/******************************************************/

	UFUNCTION( BlueprintImplementableEvent, Category = "Task Events" )
	void OnTaskActivated( class APackMember* ownerWolf );

	UFUNCTION( BlueprintImplementableEvent, Category = "Task Events" )
	void OnTaskPaused( );

	UFUNCTION( BlueprintImplementableEvent, Category = "Task Events" )
	void OnTaskCancelled( );

	UFUNCTION( BlueprintImplementableEvent, Category = "Task Events" )
	void OnTaskCompleted( bool successs );

	UFUNCTION( BlueprintImplementableEvent, Category = "Task Events" )
	void OnTaskTick( float deltaTime );

	/******************************************************/
	/*					BLUEPRINT EVENTS				  */
	/******************************************************/

	virtual void NativeTaskTick( float deltaTime );

	UFUNCTION( BlueprintCallable, Category = "Task Control" )
	virtual bool Activate( );

	UFUNCTION( BlueprintCallable, Category = "Task Control" )
	virtual void SetPaused( bool pause );

	UFUNCTION( BlueprintCallable, Category = "Task Control" )
	virtual void Cancel( );

	UFUNCTION( BlueprintCallable, Category = "Task Control" )
	virtual void Reset( );

	UFUNCTION( BlueprintCallable, Category = "Task Control" )
	virtual void CompleteTask( );

	virtual void SetOwnerWolf( class APackMember* ownerWolf );

	bool mIsActive;
	bool mIsPaused;

};
