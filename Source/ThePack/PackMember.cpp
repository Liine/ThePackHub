// Fill out your copyright notice in the Description page of Project Settings.

#include "ThePack.h"
#include "PackMember.h"

void APackMember::Tick( float deltaTime )
{
	Super::Tick( deltaTime );

	for( int i = 0; i < mPackMemberData.DefaultTasks.Num( ); i++ )
	{
		if( mPackMemberData.DefaultTasks[ i ]->mOwnerWolf != this )
		{
			mPackMemberData.DefaultTasks[ i ]->SetOwnerWolf( this );
		}

		mPackMemberData.DefaultTasks[ i ]->NativeTaskTick( deltaTime );
	}

	for( int i = 0; i < mPackMemberData.ExtraTasks.Num( ); i++ )
	{
		if( mPackMemberData.ExtraTasks[ i ]->mOwnerWolf != this )
		{
			mPackMemberData.ExtraTasks[ i ]->SetOwnerWolf( this );
		}

		mPackMemberData.ExtraTasks[ i ]->NativeTaskTick( deltaTime );
	}

}




