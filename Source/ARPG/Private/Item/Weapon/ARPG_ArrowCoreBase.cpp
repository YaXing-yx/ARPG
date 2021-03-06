﻿// Fill out your copyright notice in the Description page of Project Settings.

#include "ARPG_ArrowCoreBase.h"
#include "HumanBase.h"
#include "ARPG_ArrowBase.h"


#define LOCTEXT_NAMESPACE "ARPG_Item"

UARPG_ArrowCoreBase::UARPG_ArrowCoreBase(const FObjectInitializer& ObjectInitializer /*= FObjectInitializer::Get()*/)
	: Super(ObjectInitializer.DoNotCreateDefaultSubobject(GET_MEMBER_NAME_CHECKED(UARPG_ArrowCoreBase, AttackAnimSet)))
{

}

FText UARPG_ArrowCoreBase::GetItemTypeDesc() const
{
	return LOCTEXT("ARPG_ArrowType", "箭");
}

void UARPG_ArrowCoreBase::UseItem(ACharacterBase* ItemOwner, EUseItemInput UseItemInput)
{
	ItemOwner->EquipArrow(this, UseItemInput);
}

void UARPG_ArrowCoreBase::WhenRemoveFromInventory(class AActor* ItemOwner, int32 RemoveNumber, int32 ExistNumber)
{
	if (ExistNumber <= 0)
	{
		if (AHumanBase* Human = Cast<AHumanBase>(ItemOwner))
		{
			Human->SetArrow(nullptr);
		}
	}
}

TSubclassOf<AXD_ItemBase> UARPG_ArrowCoreBase::GetStaticMeshActor() const
{
	return AARPG_Arrow_StaticMesh::StaticClass();
}

TSubclassOf<AXD_ItemBase> UARPG_ArrowCoreBase::GetSkeletalMeshActor() const
{
	return AARPG_Arrow_SkeletalMesh::StaticClass();
}

#undef LOCTEXT_NAMESPACE