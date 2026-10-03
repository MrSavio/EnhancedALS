// Fill out your copyright notice in the Description page of Project Settings.


#include "CommonUIPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "CommonUserWidget.h"
#include "CommonActivatableWidget.h"
#include "Widgets/CommonActivatableWidgetContainer.h"
#include "UIBaseWidgetInterface.h"
#include "UObject/ConstructorHelpers.h"


ACommonUIPlayerController::ACommonUIPlayerController()
{
	// Initialize the controller here with any default settings
	
	static ConstructorHelpers::FClassFinder<UCommonUserWidget> DefaultWidgetBP(TEXT("/SavioCommonUI/Widgets/CW_UIBaseWidget"));

	if (DefaultWidgetBP.Succeeded())
	{
		UIBaseWidgetClass = DefaultWidgetBP.Class;
	}
}

// Called when the game starts
void ACommonUIPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (!UIBaseWidgetClass)
	{
		return;
	}
	
	UIBaseWidget = CreateWidget<UCommonUserWidget>(this, UIBaseWidgetClass);
	if (!UIBaseWidget)
	{
		return;
	}
	
	if (!UIBaseWidget->GetClass()->ImplementsInterface(UUIBaseWidgetInterface::StaticClass()))
	{
		UE_LOG(LogTemp, Error, TEXT("UIBaseWidgetClass %s does not implement UUIBaseWidgetInterface"), *UIBaseWidgetClass->GetName());
		return;
	}
	
	UIBaseWidget->AddToViewport(UIBaseZOrder);
	
	// Create a primary widget stack here
	if (PrimaryWidgetToPush)
	{
		// Assuming we have reached this point, UIBaseWidget should have already confirmed it does Implement the UIBaseWidgetInterface
		UCommonActivatableWidgetStack* WidgetStack = IUIBaseWidgetInterface::Execute_GetWidgetStack(UIBaseWidget, EWidgetStack::Primary);
		PrimaryWidget = WidgetStack->AddWidget<UCommonActivatableWidget>(PrimaryWidgetToPush);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PrimaryWidgetToPush was null, therefor the UIBaseWidget has been created but without an initial Widget"));
	}
	
	OnUICreated();
}

#pragma region Common UI Interface Functions

UCommonActivatableWidget* ACommonUIPlayerController::PushWidgetToStack_Implementation(TSubclassOf<UCommonActivatableWidget> WidgetClass, const EWidgetStack Stack)
{
	if (!UIBaseWidget)
	{
		return nullptr;
	}
	
	UCommonActivatableWidgetStack* WidgetStack = IUIBaseWidgetInterface::Execute_GetWidgetStack(UIBaseWidget, Stack);
	if (!WidgetStack)
	{
		return nullptr;
	}
	
	return WidgetStack->AddWidget<UCommonActivatableWidget>(WidgetClass);
}

void ACommonUIPlayerController::RemoveWidgetFromStack_Implementation(UCommonActivatableWidget* WidgetToRemove, const EWidgetStack Stack)
{
	if (!UIBaseWidget)
	{
		return;
	}
	
	UCommonActivatableWidgetStack* WidgetStack = IUIBaseWidgetInterface::Execute_GetWidgetStack(UIBaseWidget, Stack);
	if (!WidgetStack)
	{
		return;
	}
	
	WidgetStack->RemoveWidget(*WidgetToRemove);
}

void ACommonUIPlayerController::ClearWidgetsFromStack_Implementation(const EWidgetStack Stack)
{
	if (!UIBaseWidget)
	{
		return;
	}
	
	UCommonActivatableWidgetStack* WidgetStack = IUIBaseWidgetInterface::Execute_GetWidgetStack(UIBaseWidget, Stack);
	if (!WidgetStack)
	{
		return;
	}
	
	WidgetStack->ClearWidgets();
}

UCommonUserWidget* ACommonUIPlayerController::GetUIBaseWidget_Implementation() const
{
	return IsValid(UIBaseWidget) ? UIBaseWidget : nullptr;
}

#pragma endregion
