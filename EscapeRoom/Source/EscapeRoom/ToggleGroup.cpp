// Fill out your copyright notice in the Description page of Project Settings.

#include "ToggleGroup.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"

PRAGMA_DISABLE_OPTIMIZATION

// Sets default values for this component's properties
UToggleGroup::UToggleGroup()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UToggleGroup::ToggleGroupVisibility(bool v)
{
	for (auto x : ActorsToHide)
		if (x != nullptr)
			x->SetActorHiddenInGame(!v);

	bIsVisibleInScene = v;
}

// Called when the game starts
void UToggleGroup::BeginPlay()
{
	Super::BeginPlay();
	ToggleGroupVisibility(bIsVisibleInScene);
}

// Called every frame
void UToggleGroup::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

PRAGMA_ENABLE_OPTIMIZATION
