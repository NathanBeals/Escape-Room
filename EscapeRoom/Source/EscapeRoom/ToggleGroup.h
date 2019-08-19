// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "ToggleGroup.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOM_API UToggleGroup : public USceneComponent
{
	GENERATED_BODY()

private:
	/*Can be set in editor to activate durring runtime, call the method otherwise*/
	UPROPERTY(EditAnywhere)
		bool bIsVisibleInScene = false;

public:	
	// Sets default values for this component's properties
	UToggleGroup();

	/*Actors hidden by this group*/
	UPROPERTY(EditAnywhere)
		TArray<AActor*> ActorsToHide = TArray<AActor*>();

	UFUNCTION(BlueprintCallable)
		virtual void ToggleGroupVisibility(bool visible);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;	
};
