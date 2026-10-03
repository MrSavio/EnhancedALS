// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PlayerHUDInterface.generated.h"

class UCommonActivatableWidget;


// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UPlayerHUDInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * This Interface is meant to be added to the player controller used in gameplay, it's mainly for easier readability to retrieve the widget used as your player hud
 * 
 * - This is NOT meant to be added to the PlayerHUDWidget, it's meant for the PlayerController (I recommend making a PlayerHUDWidgetInterface to easily access things on your widget)
 * 
 * - This basic Interface is intended to have easy access to your PlayerHUDWidget (CommonActivatableWidget) reference by not having to cast to a specific controller (simply GetPlayerController->GetPlayerHUD)
 * 
 * - Generally, if using the CommonUIPlayerController the PlayerHUD Widget can be the PrimaryWidgetToPush and therefor you can just return the PrimaryWidget for the GetPlayerHUD function
 * 
 * - Of course, if you decide not to have the PlayerHUD Widget as the PrimaryWidget, then you can return whichever reference you have as the PlayerHUD
 */
class SAVIOCOMMONUI_API IPlayerHUDInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	/**
	 * Returns the Player HUD Widget
	 * - Typically implemented in the PlayerController that holds a reference to your PlayerHUDWidget or initially creates the widget (PlayerController recommended)
	 */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Player HUD Interface")
	UCommonActivatableWidget* GetPlayerHUD() const;
};
