// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CommonUIData.h"
#include "UIBaseWidgetInterface.generated.h"

class UCommonActivatableWidgetStack;
class UCommonActivatableWidget;


// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UUIBaseWidgetInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * This must be implemented in your UIBaseWidget - See BP_UIBaseWidget for an example, or just keep that as your base widget
 */
class SAVIOCOMMONUI_API IUIBaseWidgetInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	// Returns the CommonActivatableWidgetStack for the chosen EWidgetStack
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UI Base Widget Interface")
	UCommonActivatableWidgetStack* GetWidgetStack(EWidgetStack Stack) const;
	
	// Returns the CommonActivatableWidget from the chosen EWidgetStack
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UI Base Widget Interface")
	UCommonActivatableWidget* GetWidgetActiveOnStack(EWidgetStack Stack) const;
};
