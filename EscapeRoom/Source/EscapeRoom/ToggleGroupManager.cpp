// Fill out your copyright notice in the Description page of Project Settings.


#include "ToggleGroupManager.h"

// Sets default values
AToggleGroupManager::AToggleGroupManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AToggleGroupManager::BeginPlay()
{
	Super::BeginPlay();

}

void AToggleGroupManager::PlayAnimation(float StartTime, bool ShouldLoop)
{
	if (ToggleGroups.Num() != 0)
	{
		ToggleGroups[0].ToggleGroupVisibility(true);
		m_CurGroup = &ToggleGroups[0];
	}; //Yeah this togglegroupvisibility method is names wrong whateves

	m_Looping = ShouldLoop;
	m_RunningTime = StartTime;
	m_Updating = true;
}

void AToggleGroupManager::UpdateAnimation(float DeltaTime)
{
	if (!m_Updating || m_CurGroup == nullptr) return;

	m_RunningTime += DeltaTime;

	//pause, On off - repeated, next group

	switch (m_State)
	{
	case Starting:
		if (m_RunningTime > PauseTime)
		{
			m_State = AnimationStates::On;
			m_RunningTime = 0;
			if (m_CurGroup != nullptr)
				m_CurGroup->ToggleGroupVisibility(true);
		}
		break;

	case Waiting:
		if (m_RunningTime > PauseTime)
		{
			m_State = AnimationStates::On;
			m_RunningTime = 0;
			m_CurGroup = &ToggleGroups[ToggleGroups.Find(*m_CurGroup) + 1];
			if (m_CurGroup != nullptr)
				m_CurGroup->ToggleGroupVisibility(true);
		}

		break;
	case On:
		if (m_RunningTime > FlickOnTime)
		{
			m_RunningTime = 0;
			if (m_CurGroup != nullptr)
				m_CurGroup->ToggleGroupVisibility(false);
		}
		break;

	case Off:
		if (m_RunningTime > FlickOnTime)
		{
			m_RunningTime = 0;
			if (m_CurGroup != nullptr)
				m_CurGroup->ToggleGroupVisibility(true);
		}
		break;
	}

	if (m_RunningTime > PauseTime)
	{

	}

}

// Called every frame
void AToggleGroupManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateAnimation(DeltaTime);
}

