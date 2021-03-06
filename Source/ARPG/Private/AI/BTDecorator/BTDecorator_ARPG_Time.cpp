﻿// Fill out your copyright notice in the Description page of Project Settings.

#include "BTDecorator_ARPG_Time.h"
#include "ARPG_TimeManager.h"
#include "BlueprintNodeHelpers.h"

const TCHAR UBTDecorator_ARPG_TimeBase::TimeDescFormat[] = TEXT("[%s]至[%s]");

UBTDecorator_ARPG_TimeBase::UBTDecorator_ARPG_TimeBase()
{
	bNotifyTick = true;
}

FString UBTDecorator_ARPG_TimeBase::GetStaticDescription() const
{
	FString ReturnDesc = Super::GetStaticDescription();

	UBTDecorator_ARPG_TimeBase* CDO = (UBTDecorator_ARPG_TimeBase*)(GetClass()->GetDefaultObject());
	if (CDO)
	{
		TArray<UProperty*> PropertyData;
		UClass* StopAtClass = UBTDecorator_ARPG_TimeBase::StaticClass();
		FString PropertyDesc = BlueprintNodeHelpers::CollectPropertyDescription(this, StopAtClass, PropertyData);
		if (PropertyDesc.Len())
		{
			ReturnDesc += TEXT(":\n\n");
			ReturnDesc += PropertyDesc;
		}
	}

	return ReturnDesc;
}

void UBTDecorator_ARPG_TimeBase::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	if (!CalculateRawConditionValue(OwnerComp, NodeMemory))
	{
		OwnerComp.RequestExecution(this);
	}
}

bool UBTDecorator_ARPG_Time_InHourRange::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	if (UXD_TimeManager* TimeManager = UARPG_TimeManager::GetGameTimeManager(&OwnerComp))
	{
		return TimeManager->CurrentTime.InHourRange(StartTime, EndTime);
	}
	return false;
}

FString UBTDecorator_ARPG_Time_InHourRange::GetStaticDescription() const
{
	return FString::Printf(TimeDescFormat, *StartTime.ToString(), *EndTime.ToString());
}

bool UBTDecorator_ARPG_Time_InDayRange::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	if (UXD_TimeManager* TimeManager = UARPG_TimeManager::GetGameTimeManager(&OwnerComp))
	{
		return TimeManager->CurrentTime.InDayRange(StartTime, EndTime);
	}
	return false;
}

FString UBTDecorator_ARPG_Time_InDayRange::GetStaticDescription() const
{
	return FString::Printf(TimeDescFormat, *StartTime.ToString(), *EndTime.ToString());
}

bool UBTDecorator_ARPG_Time_InWeekRange::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	if (UXD_TimeManager* TimeManager = UARPG_TimeManager::GetGameTimeManager(&OwnerComp))
	{
		return TimeManager->CurrentTime.InWeekRange(StartTime, EndTime);
	}
	return false;
}

FString UBTDecorator_ARPG_Time_InWeekRange::GetStaticDescription() const
{
	return FString::Printf(TimeDescFormat, *StartTime.ToString(), *EndTime.ToString());
}

bool UBTDecorator_ARPG_Time_InMonthRange::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	if (UXD_TimeManager* TimeManager = UARPG_TimeManager::GetGameTimeManager(&OwnerComp))
	{
		return TimeManager->CurrentTime.InMonthRange(StartTime, EndTime);
	}
	return false;
}

FString UBTDecorator_ARPG_Time_InMonthRange::GetStaticDescription() const
{
	return FString::Printf(TimeDescFormat, *StartTime.ToString(), *EndTime.ToString());
}

bool UBTDecorator_ARPG_Time_InYearRange::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	if (UXD_TimeManager* TimeManager = UARPG_TimeManager::GetGameTimeManager(&OwnerComp))
	{
		return TimeManager->CurrentTime.InYearRange(StartTime, EndTime);
	}
	return false;
}

FString UBTDecorator_ARPG_Time_InYearRange::GetStaticDescription() const
{
	return FString::Printf(TimeDescFormat, *StartTime.ToString(), *EndTime.ToString());
}

bool UBTDecorator_ARPG_Time_InSpecialRange::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	if (UXD_TimeManager* TimeManager = UARPG_TimeManager::GetGameTimeManager(&OwnerComp))
	{
		return TimeManager->CurrentTime.InSpecialTimeRange(StartTime, EndTime);
	}
	return false;
}

FString UBTDecorator_ARPG_Time_InSpecialRange::GetStaticDescription() const
{
	return FString::Printf(TimeDescFormat, *StartTime.ToString(), *EndTime.ToString());
}
