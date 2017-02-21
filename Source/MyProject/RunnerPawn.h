// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "./logic/PlayerCharacter.h"
#include "RunnerPawn.generated.h"


UCLASS()

class MYPROJECT_API ARunnerPawn : public APawn
{
	GENERATED_BODY()
private:
	PlayerCharacter pc;
public:
	// Sets default values for this pawn's properties
	ARunnerPawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* AnInputComponent) override;

	UPROPERTY(EditAnywhere)
	float speed = 10.0;
};
