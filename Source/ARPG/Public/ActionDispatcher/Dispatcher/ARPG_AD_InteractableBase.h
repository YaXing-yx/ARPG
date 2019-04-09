﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ARPG_ActionDispatcherBase.h"
#include "ARPG_AD_InteractableBase.generated.h"

class ACharacterBase;

/**
 * 
 */
UCLASS(abstract, editinlinenew, collapseCategories, meta = (DisplayName = "交互调度器"))
class ARPG_API UARPG_AD_InteractableBase : public UARPG_ActionDispatcherBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "行为|交互", meta = (ExposeOnSpawn = true))
	TSoftObjectPtr<AActor> InteractTarget;

	UPROPERTY(BlueprintReadOnly, Category = "行为|交互", meta = (ExposeOnSpawn = true))
 	TSoftObjectPtr<ACharacterBase> InteractInvoker;

public:
	void InitInteractDispatcher(AActor* InInteractTarget);

	void StartInteractDispatcher(ACharacterBase* InInteractInvoker, const FWhenDispatchFinishedNative& DispatchFinishedEvent, const FOnActionDispatcherAbortedNative& DispatcherAbortedEvent);
	void AbortInteractDispatcher(const FOnActionDispatcherAbortedNative& DispatcherAbortedEvent);

public:
	void WhenDeactived() override;

private:
	using UXD_ActionDispatcherBase::StartDispatch;
	using UXD_ActionDispatcherBase::AbortDispatch;
};