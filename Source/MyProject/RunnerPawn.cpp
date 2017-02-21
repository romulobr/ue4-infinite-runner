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
	UE_LOG(LogTemp, Warning, TEXT("Player Character initialized: power %i color %i"), pc.GetActiveColor(), pc.GetPower());
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
void ARunnerPawn::SetupPlayerInputComponent(class UInputComponent* AnInputComponent)
{
	Super::SetupPlayerInputComponent(AnInputComponent);
}
