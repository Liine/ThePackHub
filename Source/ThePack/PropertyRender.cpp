// Fill out your copyright notice in the Description page of Project Settings.

#include "ThePack.h"
#include "NPCWolf.h"
#include "PropertyRender.h"


APropertyRender::APropertyRender( const FObjectInitializer& ObjectInitializer )
: Super( ObjectInitializer )
{
	SetActorTickEnabled( true );

	PrimaryActorTick.bCanEverTick = true;

	RegisterAllActorTickFunctions( true, true );

}

bool APropertyRender::SetOwnerWolf( class ANPCWolf* ownerWolf )
{
	mOwnerWolf = ownerWolf;

	return mOwnerWolf != NULL;
}

