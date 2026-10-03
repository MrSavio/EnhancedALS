// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonUIData.generated.h"

/**
 * 
 */

#pragma region Enums

UENUM(BlueprintType)
enum class EWidgetStack : uint8
{
	Primary				UMETA(DisplayName = "Primary"),
	Secondary			UMETA(DisplayName = "Secondary"),
	Tertiary			UMETA(DisplayName = "Tertiary"),
};

#pragma endregion
