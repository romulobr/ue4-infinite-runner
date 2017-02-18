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
	backPlatform = platform1;
	frontPlatform = platform2;

	OUT FVector origin;
	OUT FVector boxExtent;
	
	frontPlatform->GetActorBounds(false, origin, boxExtent);
	platformWidth = boxExtent.Y;

	UE_LOG(LogTemp, Warning, TEXT("platform: %s %s"), *origin.ToString(), *boxExtent.ToString());
	UE_LOG(LogTemp, Warning, TEXT("platform width is: %f"), platformWidth);
	
	platform1->SetActorLocation(FVector(0, 0, 0), false);
	platform2->SetActorLocation(FVector(0, platformWidth*2, 0), false);
}

void AInfiniteTerrain::scrollPlatform(float DeltaTime, AGround* platform)
{
	auto location = platform->GetActorLocation();
	location.Y = location.Y - DeltaTime * scrollingSpeed;
	platform->SetActorLocation(location);
}

bool AInfiniteTerrain::isBackPlatformOffCamera()
{
	return backPlatform->GetActorLocation().Y <= -200;
}

void AInfiniteTerrain::moveBackPlatformToFrontAndSwitchReferences()
{
	auto frontPlatformLocation = frontPlatform->GetActorLocation();
	frontPlatformLocation.Y = frontPlatformLocation.Y + platformWidth*2;
	backPlatform->SetActorLocation(frontPlatformLocation);

	auto previouslyBackPlatform = backPlatform;
	backPlatform = frontPlatform;
	frontPlatform = previouslyBackPlatform;
}

// Called every frame
void AInfiniteTerrain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (isBackPlatformOffCamera())
	{
		moveBackPlatformToFrontAndSwitchReferences();
	}
	scrollPlatform(DeltaTime, backPlatform);
	scrollPlatform(DeltaTime, frontPlatform);
}
