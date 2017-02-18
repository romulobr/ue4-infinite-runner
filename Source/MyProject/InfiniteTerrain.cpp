// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "InfiniteTerrain.h"
#include "Ground.h"

// Sets default values
AInfiniteTerrain::AInfiniteTerrain()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UE_LOG(LogTemp, Warning, TEXT("monkeys..."));
}

// Called when the game starts or when spawned
void AInfiniteTerrain::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("using platforms: %s, %s"), *platform1->GetName(), *platform2->GetName())
	setUpInitialPlatformPositions();
}

void AInfiniteTerrain::setUpInitialPlatformPositions()
{
	OUT FVector origin;
	OUT FVector boxExtent;
	platform1->GetActorBounds(false, origin, boxExtent);
	platformWidth = boxExtent.Y * 2;
	UE_LOG(LogTemp, Warning, TEXT("platform horizontal size is: %f"), platformWidth);
	platform1->SetActorLocation(FVector(0, 0, -30), false);
	platform2->SetActorLocation(FVector(0, 0 + platformWidth, -30), false);
	backPlatform = platform1;
	frontPlatform = platform2;
}

void AInfiniteTerrain::scrollPlatform(float DeltaTime, AGround* platform)
{
	auto location = platform->GetActorLocation();
	location.Y = location.Y - DeltaTime * scrollingSpeed;
	platform->SetActorLocation(location);
}

bool AInfiniteTerrain::isOffCamera(const FVector& location)
{
	return location.Y <= -300;
}

void AInfiniteTerrain::moveBackPlatformToFrontAndSwitchThem()
{
	auto frontPlatformLocation = frontPlatform->GetActorLocation();
	frontPlatformLocation.Y += platformWidth;
	backPlatform->SetActorLocation(frontPlatformLocation);

	auto previouslyBackPlatform = backPlatform;
	backPlatform = frontPlatform;
	frontPlatform = previouslyBackPlatform;
}

// Called every frame
void AInfiniteTerrain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (isOffCamera(backPlatform->GetActorLocation()))
	{
		moveBackPlatformToFrontAndSwitchThem();
	}
	scrollPlatform(DeltaTime, backPlatform);
	scrollPlatform(DeltaTime, frontPlatform);
}
