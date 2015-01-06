// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "PackHelper.h"
#include "PackMember.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class THEPACK_API APackMember : public ACharacter
{
	GENERATED_BODY()
	
public:
	UPROPERTY( BlueprintReadOnly, VisibleAnywhere, Category = "Pack Member Data" )
	FPackMemberData mPackMemberData;

	virtual void Tick( float delTaTime ) override;


};
