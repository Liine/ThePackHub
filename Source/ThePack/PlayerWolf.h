// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PackMember.h"
#include "PlayerWolf.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class THEPACK_API APlayerWolf : public APackMember
{
	GENERATED_BODY()

	// Constructor declaration
	APlayerWolf(const FObjectInitializer& ObjectInitializer);

public:
	UPROPERTY(BlueprintReadOnly,VisibleAnywhere,Category="Wolf")
	float mCurrentAggressionLevel;

	UPROPERTY( BlueprintReadWrite, VisibleAnywhere, Category = "Wolf" )
	float mDesiredAggressionLevel;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Wolf")
	float mCurrentMaxAggressionLevel;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Wolf")
	float mDesiredMaxAggressionLevel;

	UPROPERTY( BlueprintReadOnly, VisibleAnywhere, Category = "Wolf" )
	float mAggressionPct;

	virtual void Tick( float deltaTime ) override;
};
