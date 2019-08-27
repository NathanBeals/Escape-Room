// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ToggleGroupManager.generated.h"
#include "NewToggleGroup.h"

UCLASS()
class ESCAPEROOM_API AToggleGroupManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AToggleGroupManager();

	UPROPERTY(EditAnywhere)
	TArray<ANewToggleGroup> ToggleGroups = {};

	//TODO: add guards for recalculating the total time for these values when they change instead of in update

	UPROPERTY(EditAnywhere)
	float FlickCount = 10.0f;
	
	UPROPERTY(EditAnywhere)
	float FlickOnTime = 2.0f;
	
	UPROPERTY(EditAnywhere)
	float FlickOffTime = 1.0f;

	UPROPERTY(EditAnywhere)
	float PauseTime = 5.0f;

	enum AnimationStates
	{
		Starting,
		Waiting,
		On,
		Off
	};

protected:

	AnimationStates m_State = Waiting;
	ANewToggleGroup* m_CurGroup = nullptr;
	float m_RunningTime = 0.0f;
	bool m_Updating = false;
	bool m_Looping = false;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void PlayAnimation(float StartTime, bool ShouldLoop);
	void UpdateAnimation(float DeltaTime);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
