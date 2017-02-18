// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "InfiniteTerrain.generated.h"
class AGround;

UCLASS()
class MYPROJECT_API AInfiniteTerrain : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInfiniteTerrain();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void setUpInitialPlatformPositions();

	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere)
		AGround* platform1;
	UPROPERTY(EditAnywhere)
		AGround* platform2;
	UPROPERTY(EditAnywhere)
		AGround* platform3;
	int platformWidth;
};
