// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NewToggleGroup.generated.h"

UCLASS()
class ESCAPEROOM_API ANewToggleGroup : public AActor
{
	GENERATED_BODY()
	
private:
	/*Can be set in editor to activate durring runtime, call the method otherwise*/
	UPROPERTY(EditAnywhere)
		bool bIsVisibleInScene = false;

public:
	/*Actors hidden by this group*/
	UPROPERTY(EditAnywhere)
		TArray<AActor*> ActorsToHide = TArray<AActor*>();

	UFUNCTION(BlueprintCallable)
		virtual void ToggleGroupVisibility(bool visible);

public:	
	// Sets default values for this actor's properties
	ANewToggleGroup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
