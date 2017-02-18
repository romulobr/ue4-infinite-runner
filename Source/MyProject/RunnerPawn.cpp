// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "RunnerPawn.h"


// Sets default values
ARunnerPawn::ARunnerPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ARunnerPawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ARunnerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto location = GetActorLocation();
	location.Y += speed * DeltaTime;
	SetActorLocation(location);
}

// Called to bind functionality to input
void ARunnerPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
}
