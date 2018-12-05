// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ComponentVisualizer.h"

class UInteractableActorManager_Simple;

/**
 * 
 */
struct HInteractableActorManagerSimpleVisProxy : public HComponentVisProxy
{
	DECLARE_HIT_PROXY();

	HInteractableActorManagerSimpleVisProxy(const UActorComponent* InComponent)
		: HComponentVisProxy(InComponent, HPP_Wireframe)
	{}
};

class ARPG_EDITOR_API FInteractableActorManagerSimpleVisualizer : public FComponentVisualizer
{
public:
	void DrawVisualization(const UActorComponent* Component, const FSceneView* View, FPrimitiveDrawInterface* PDI) override;
	bool VisProxyHandleClick(FEditorViewportClient* InViewportClient, HComponentVisProxy* VisProxy, const FViewportClick& Click) override;
	bool GetWidgetLocation(const FEditorViewportClient* ViewportClient, FVector& OutLocation) const override;
	bool HandleInputDelta(FEditorViewportClient* ViewportClient, FViewport* Viewport, FVector& DeltaTranslate, FRotator& DeltalRotate, FVector& DeltaScale) override;
	void EndEditing() override;

	uint8 bIsEditing : 1;

	TWeakObjectPtr<UInteractableActorManager_Simple> InteractableActorManager_Simple;
};
