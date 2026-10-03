// Copyright Epic Games, Inc. All Rights Reserved.

#include "SavioCommonUIBPLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "CommonUserWidget.h"
#include "CommonUIInterface.h"
#include "UIBaseWidgetInterface.h"
#include "PlayerHUDInterface.h"
#include "GameFramework/Actor.h"


USavioCommonUIBPLibrary::USavioCommonUIBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}


UCommonActivatableWidget* USavioCommonUIBPLibrary::PushWidgetToStack(const UObject* WorldContext, TSubclassOf<UCommonActivatableWidget> WidgetClass, const EWidgetStack Stack)
{
	APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContext, 0);
	if (!PC)
	{
		return nullptr;
	}
	
	if (!PC->GetClass()->ImplementsInterface(UCommonUIInterface::StaticClass()))
	{
		return nullptr;
	}
	
	return ICommonUIInterface::Execute_PushWidgetToStack(PC, WidgetClass, Stack);
}


void USavioCommonUIBPLibrary::RemoveWidgetFromStack(const UObject* WorldContext,UCommonActivatableWidget* WidgetToRemove, const EWidgetStack Stack)
{
	APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContext, 0);
	if (!PC)
	{
		return;
	}
	
	if (!PC->GetClass()->ImplementsInterface(UCommonUIInterface::StaticClass()))
	{
		return;
	}
	
	ICommonUIInterface::Execute_RemoveWidgetFromStack(PC, WidgetToRemove, Stack);
}


void USavioCommonUIBPLibrary::ClearWidgetsFromStack(const UObject* WorldContext, const EWidgetStack Stack)
{
	APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContext, 0);
	if (!PC)
	{
		return;
	}
	
	if (!PC->GetClass()->ImplementsInterface(UCommonUIInterface::StaticClass()))
	{
		return;
	}
	
	ICommonUIInterface::Execute_ClearWidgetsFromStack(PC, Stack);
}


UCommonUserWidget* USavioCommonUIBPLibrary::GetUIBaseWidget(const UObject* WorldContext)
{
	const APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContext, 0);
	if (!PC)
	{
		return nullptr;
	}
	
	if (!PC->GetClass()->ImplementsInterface(UCommonUIInterface::StaticClass()))
	{
		return nullptr;
	}
	
	return ICommonUIInterface::Execute_GetUIBaseWidget(PC);
}


UCommonActivatableWidget* USavioCommonUIBPLibrary::GetPlayerHUD(const UObject* WorldContext)
{
	const APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContext, 0);
	if (!PC)
	{
		return nullptr;
	}
	
	if (!PC->GetClass()->ImplementsInterface(UPlayerHUDInterface::StaticClass()))
	{
		return nullptr;
	}
	
	return IPlayerHUDInterface::Execute_GetPlayerHUD(PC);
}


UCommonActivatableWidgetStack* USavioCommonUIBPLibrary::GetWidgetStack(const UObject* WorldContext, const EWidgetStack Stack)
{
	const APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContext, 0);
	if (!PC)
	{
		return nullptr;
	}
	
	if (!PC->GetClass()->ImplementsInterface(UCommonUIInterface::StaticClass()))
	{
		return nullptr;
	}
	
	const UCommonUserWidget* UIBase = ICommonUIInterface::Execute_GetUIBaseWidget(PC);
	if (!UIBase)
	{
		return nullptr;
	}
	
	if (!UIBase->GetClass()->ImplementsInterface(UUIBaseWidgetInterface::StaticClass()))
	{
		return nullptr;
	}
		
	return IUIBaseWidgetInterface::Execute_GetWidgetStack(UIBase, Stack);
}


UCommonActivatableWidget* USavioCommonUIBPLibrary::GetWidgetActiveOnStack(const UObject* WorldContext, const EWidgetStack Stack)
{
	const APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContext, 0);
	if (!PC)
	{
		return nullptr;
	}
	
	if (!PC->GetClass()->ImplementsInterface(UCommonUIInterface::StaticClass()))
	{
		return nullptr;
	}
	
	const UCommonUserWidget* UIBase = ICommonUIInterface::Execute_GetUIBaseWidget(PC);
	if (!UIBase)
	{
		return nullptr;
	}
	
	if (!UIBase->GetClass()->ImplementsInterface(UUIBaseWidgetInterface::StaticClass()))
	{
		return nullptr;
	}
		
	return IUIBaseWidgetInterface::Execute_GetWidgetActiveOnStack(UIBase, Stack);
}
