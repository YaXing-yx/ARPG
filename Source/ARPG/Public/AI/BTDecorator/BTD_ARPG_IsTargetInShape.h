﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Decorators/BTDecorator_BlackboardBase.h"
#include "BTD_ARPG_IsTargetInShape.generated.h"

/**
 * 
 */
UCLASS(abstract)
class ARPG_API UBTD_ARPG_InShapeBase : public UBTDecorator_BlackboardBase
{
	GENERATED_BODY()
public:
	UBTD_ARPG_InShapeBase();
	void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};

UCLASS(meta = (DisplayName = "目标在球形中"))
class ARPG_API UBTD_ARPG_InSphere : public UBTD_ARPG_InShapeBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "配置")
	FVector RelativeLocation;

	UPROPERTY(EditAnywhere, Category = "配置")
	float Radius = 100.f;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category = "配置")
	uint8 bShowDebugSphere : 1;
#endif

	bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;

	FString GetStaticDescription() const override;
};

UCLASS(meta = (DisplayName = "目标在矩形中"))
class ARPG_API UBTD_ARPG_InBox : public UBTD_ARPG_InShapeBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "配置")
	FVector RelativeLocation;

	UPROPERTY(EditAnywhere, Category = "配置")
	FRotator RelativeRotation;

	UPROPERTY(EditAnywhere, Category = "配置")
	FVector BoxExtent = FVector(100.f, 100.f, 100.f);

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category = "配置")
	uint8 bShowDebugBox : 1;
#endif

	bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;

	FString GetStaticDescription() const override;
};
