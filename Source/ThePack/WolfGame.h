// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "WolfGame.generated.h"


DECLARE_LOG_CATEGORY_EXTERN( Game_Init, Log, All )
DECLARE_LOG_CATEGORY_EXTERN( Pack_Init, Log, All )
DECLARE_LOG_CATEGORY_EXTERN( Pack_Info, Log, All )

// New enum
UENUM( )
enum class EWolfLogType : uint8
{
	Game_Init,
	Pack_Init,
	Pack_Info
};

USTRUCT()
struct FWolfSpawnLocation
{
	GENERATED_USTRUCT_BODY()


	UPROPERTY( BlueprintReadOnly, EditAnywhere, Category = "Spawn points", meta = ( DisplayName = "Spawn point" ) )
	FVector mSpawnLocation;

	bool mFree;
};

/**
 * 
 */
UCLASS()
class THEPACK_API AWolfGame : public AGameMode
{
	GENERATED_BODY()

	// Constructor declaration
	AWolfGame( const FObjectInitializer& ObjectInitializer );
	
public:
	UPROPERTY( BlueprintReadWrite, EditAnywhere, Category = "Pack Info" )
	TSubclassOf<class UPackManager> mDefaultPackManagerClass;
	
	UPROPERTY( BlueprintReadOnly, VisibleAnywhere, Category = "Pack Info" )
	class UPackManager* mPackManager;
	
	UPROPERTY( BlueprintReadOnly, VisibleAnywhere, Category = "Pack Info" )
	class UPackHelper* mPackHelper;

	UPROPERTY( BlueprintReadOnly, VisibleAnywhere, Category = "Pack Info" )
	TArray< FWolfSpawnLocation > mWolfSpawnLocations;

	FVector GetFreeWolfSpawnLocation();

	void WriteToScreen( EWolfLogType logType, FString message );

	void InitPackComponents( const FObjectInitializer& ObjectInitializer );

	virtual void StartPlay() override;

	virtual void Tick( float deltaTime ) override;
};
