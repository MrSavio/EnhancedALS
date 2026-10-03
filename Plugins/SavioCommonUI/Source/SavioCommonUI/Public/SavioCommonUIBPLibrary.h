// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "CommonUIData.h"
#include "SavioCommonUIBPLibrary.generated.h"

class AController;
class UCommonUserWidget;
class UCommonActivatableWidget;
class UCommonActivatableWidgetStack;

/* 
*	Contains Helper functions for logic related to the CommonUIPlayerController and CommonUIComponent
*/
UCLASS()
class USavioCommonUIBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

public:
	
	/**
	 *	Pushes a widget to the chosen Stack on the UIBaseWidget
	*	- This is only meant to use for the PlayerController[0], any other controller should use "PushWidgetToStack" from the "CommonUIInterface" so you can provide a direct target
	*/
	UFUNCTION(BlueprintCallable, Category = "Common UI Helper Functions", meta = (WorldContext = "WorldContext"))
	static UCommonActivatableWidget* PushWidgetToStack(const UObject* WorldContext, TSubclassOf<UCommonActivatableWidget> WidgetClass, const EWidgetStack Stack);
	
	/**
	 *	Removes the input widget from the chosen Stack on the UIBaseWidget
	*	- This is only meant to use for the PlayerController[0], any other controller should use "RemoveWidgetFromStack" from the "CommonUIInterface" so you can provide a direct target
	*/
	UFUNCTION(BlueprintCallable, Category = "Common UI Helper Functions", meta = (WorldContext = "WorldContext"))
	static void RemoveWidgetFromStack(const UObject* WorldContext, UCommonActivatableWidget* WidgetToRemove, const EWidgetStack Stack);
	
	/**
	 *	Clears all widgets on the chosen Stack on the UIBaseWidget
	*	- This is only meant to use for the PlayerController[0], any other controller should use "ClearWidgetsFromStack" from the "CommonUIInterface" so you can provide a direct target
	*/
	UFUNCTION(BlueprintCallable, Category = "Common UI Helper Functions", meta = (WorldContext = "WorldContext"))
	static void ClearWidgetsFromStack(const UObject* WorldContext, const EWidgetStack Stack);
	
	/**
	 *	Retrieves the UIBaseWidget part of the CommonUIComponent (by default this is part of the CommonUIPlayerController)
	 *	- This is only meant to retrieve from the PlayerController[0], any other controller should use "GetUIBaseWidget" from the "CommonUIInterface" so you can provide a direct target
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Common UI Helper Functions", meta = (WorldContext = "WorldContext"))
	static UCommonUserWidget* GetUIBaseWidget(const UObject* WorldContext);
	
	/**
	 *	Retrieves the CommonActivatableWidgetStack based on the chosen Stack within the UIBaseWidget
	 *	- This uses the Player Controller and GetUIBaseWidget within the CommonUIInterface in order to get the Widget Stack of your choice
	 *	- This is only meant to retrieve from the PlayerController[0], any other controller should use "GetWidgetStack" from the "UIBaseWidgetInterface" so you can provide a direct target
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Common UI Helper Functions", meta = (WorldContext = "WorldContext"))
	static UCommonActivatableWidgetStack* GetWidgetStack(const UObject* WorldContext, const EWidgetStack Stack);
	
	/**
	 *	Retrieves the CommonActivatableWidget currently Active on the chosen Stack within the UIBaseWidget
	 *	- This uses the Player Controller and GetUIBaseWidget within the CommonUIInterface in order to get the current Active Widget on the Stack of your choice
	 *	- This is only meant to retrieve from the PlayerController[0], any other controller should use "GetWidgetActiveOnStack" from the "UIBaseWidgetInterface" so you can provide a direct target
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Common UI Helper Functions", meta = (WorldContext = "WorldContext"))
	static UCommonActivatableWidget* GetWidgetActiveOnStack(const UObject* WorldContext, const EWidgetStack Stack);
	
	/**
	 *	Retrieves the PlayerHUD Widget
	 *	- This is only meant to retrieve from the PlayerController[0], any other controller should use "GetPlayerHUD" from the "PlayerHUDInterface" so you can provide a direct target
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Common UI Helper Functions", meta = (WorldContext = "WorldContext"))
	static UCommonActivatableWidget* GetPlayerHUD(const UObject* WorldContext);
	
};
