// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CommonUIData.h"
#include "CommonUIInterface.generated.h"

class UCommonActivatableWidget;
class UCommonUserWidget;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCommonUIInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * This interface is part of the CommonUIPlayerController in order to communicate and manage your UI through CommonActivatableWidgetStacks on the UIBaseWidget
 * - Push Widget To Stack
 * - Remove Widget from Stack
 * - Clear Widgets from Stack
 * - Get UI Base Widget
 */
class SAVIOCOMMONUI_API ICommonUIInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	// Pushes a widget to the chosen Stack on the UIBaseWidget
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Common UI Interface")
	UCommonActivatableWidget* PushWidgetToStack(TSubclassOf<UCommonActivatableWidget> WidgetClass, const EWidgetStack Stack);
	
	// Removes the input widget from the chosen Stack on the UIBaseWidget
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Common UI Interface")
	void RemoveWidgetFromStack(UCommonActivatableWidget* WidgetToRemove, const EWidgetStack Stack);
	
	// Clears all widgets on the chosen Stack on the UIBaseWidget
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Common UI Interface")
	void ClearWidgetsFromStack(const EWidgetStack Stack);
	
	// Retrieves the UIBaseWidget created in the CommonUIComponent
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Common UI Interface")
	UCommonUserWidget* GetUIBaseWidget() const;
};
