// Fill out your copyright notice in the Description page of Project Settings.


#include "NewToggleGroup.h"

void ANewToggleGroup::ToggleGroupVisibility(bool visible)
{
	for (auto x : ActorsToHide)
		if (x != nullptr)
			x->SetActorHiddenInGame(!visible);

	bIsVisibleInScene = visible;
}

// Sets default values
ANewToggleGroup::ANewToggleGroup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANewToggleGroup::BeginPlay()
{
	Super::BeginPlay();
	ToggleGroupVisibility(bIsVisibleInScene);
}

// Called every frame
void ANewToggleGroup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

