// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonInputBaseTypes.h"
#include "DualSenseControllerData.generated.h"

/**
 * 
 */
UCLASS()
class SAVIOCOMMONUI_API UDualSenseControllerData : public UCommonInputBaseControllerData
{
	GENERATED_BODY()
	
public:
	UDualSenseControllerData()
	{
		// Replace 'Generic' with desired Gamepad Name
		GamepadName = "DualSense";
	}
};
