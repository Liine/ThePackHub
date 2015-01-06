// Fill out your copyright notice in the Description page of Project Settings.

#include "ThePack.h"
#include "PackManager.h"
#include "WolfGame.h"
#include "PackMember.h"
#include "HungerControlTask.h"
#include "PackHelper.h"

UPackHelper::UPackHelper( const FObjectInitializer& ObjectInitializer )
: Super( ObjectInitializer )
{
}

FPackMemberData UPackHelper::CreateFPackMemberData( APackMember* packMember, EGender gender, ERank rank, EAge age )
{
	FPackMemberData newPackMemberData;

	newPackMemberData.Gender = gender;
	newPackMemberData.Rank = rank;
	newPackMemberData.PackMember = packMember;
	newPackMemberData.Age = age;

	packMember->mPackMemberData = newPackMemberData;

	SetDefaultTasksForPackMember( packMember );

	return newPackMemberData;
}


void UPackHelper::SetDefaultTasksForPackMember( APackMember* packMember)
{
	//@TODO: Think of pretty way to not have hardcoded PackMember default tasks, so they can be set thru editor / blueprint

	packMember->mPackMemberData.DefaultTasks.Empty( );

	if( packMember->mPackMemberData.Rank == ERank::LeadHunter )
	{
		//special hunger task that triggers pack hunt ????
	}
	else
	{
		packMember->mPackMemberData.DefaultTasks.Add( ConstructObject<UHungerControlTask>( UHungerControlTask::StaticClass( ) ) );
	}
	
	switch( packMember->mPackMemberData.Rank )
	{
	case ERank::Alpha:
		//Give order( task ? ) tasks
		//mate tasks
		break;
	default:
		break;
	}

	switch( packMember->mPackMemberData.Age )
	{
	case EAge::Adult:
		break;
	default:
		break;
	}

	if( packMember->mPackMemberData.IsMale() )
	{
	}
	else
	{

	}
}

