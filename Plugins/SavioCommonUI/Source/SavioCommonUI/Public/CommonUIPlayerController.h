// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CommonUIInterface.h"
#include "CommonUIPlayerController.generated.h"

class UCommonUserWidget;

/**
 * A Base Player Controller that already has the CommonUIInterface functions implemented
 * - On BeginPlay, creates the UIBaseWidget and uses AddWidget (aka. PushWidget) to add the PrimaryWidget to the Primary CommonActivatableWidgetStack on the UIBaseWidget
 */
UCLASS()
class SAVIOCOMMONUI_API ACommonUIPlayerController : public APlayerController, public ICommonUIInterface
{
	GENERATED_BODY()
	
public:
	ACommonUIPlayerController();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	/**
	 * The UIBaseWidget is the underlying CommonUserWidget used to be a container for the core CommonActivatableWidgetStack's for you to Push a CommonActivatableWidget to
	 * - This is automatically created on BeginPlay of this PlayerController
	 * - You can also assign a PrimaryWidgetClass to automatically have a widget Pushed to the Primary Stack
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CommonUI Player Controller")
	TSubclassOf<UCommonUserWidget> UIBaseWidgetClass;

	/**
	 * The ZOrder for the UIBaseWidget
	 * - The higher the number, the more on top this widget will be
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CommonUI Player Controller")
	int32 UIBaseZOrder = 0;
	
	/**
	 * See UIBaseWidgetClass for more info
	 */
	UPROPERTY(BlueprintReadOnly, Category = "CommonUI Player Controller")
	TObjectPtr<UCommonUserWidget> UIBaseWidget;
	
	/**
	 * The Primary Widget is the first widget you push to the Primary Stack on the UIBaseWidget, typically the PlayerHUD or the MainMenu, etc.
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CommonUI Player Controller")
	TSubclassOf<UCommonActivatableWidget> PrimaryWidgetToPush;
	
	/**
	 * See PrimaryWidgetClass for more info
	 */
	UPROPERTY(BlueprintReadOnly, Category = "CommonUI Player Controller")
	TObjectPtr<UCommonActivatableWidget> PrimaryWidget;
	
	/**
	 * This is called once the UIBaseWidget is created and added to the Viewport
	 * - Uses as handy override, this is useful for doing things after the UI is created
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "CommonUI Player Controller")
	void OnUICreated();
	
	
public:
	
#pragma region Common UI Interface Functions
	
	virtual UCommonActivatableWidget* PushWidgetToStack_Implementation(TSubclassOf<UCommonActivatableWidget> WidgetClass, const EWidgetStack Stack) override;
	virtual void RemoveWidgetFromStack_Implementation(UCommonActivatableWidget* WidgetToRemove, const EWidgetStack Stack) override;
	virtual void ClearWidgetsFromStack_Implementation(const EWidgetStack Stack) override;
	
	virtual UCommonUserWidget* GetUIBaseWidget_Implementation() const override;
	
#pragma endregion
};
