// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ARPG_ItemBase.h"
#include "ARPG_MoneyBase.generated.h"

/**
 * 
 */
UCLASS(abstract)
class ARPG_API AARPG_MoneyBase : public AARPG_ItemBase
{
	GENERATED_BODY()
	
};

UCLASS()
class ARPG_API AARPG_Money_StaticMesh : public AARPG_MoneyBase
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	AARPG_Money_StaticMesh(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
public:
	UPROPERTY()
	UStaticMeshComponent* StaticMeshComponent;

	void InitItemMesh() override { InitStaticMeshComponent(StaticMeshComponent); }
};

UCLASS()
class ARPG_API AARPG_Money_SkeletalMesh : public AARPG_MoneyBase
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	AARPG_Money_SkeletalMesh(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
public:
	UPROPERTY()
	USkeletalMeshComponent* SkeletalMeshComponent;

	void InitItemMesh() override { InitSkeletalMeshComponent(SkeletalMeshComponent); }
};
