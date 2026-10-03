Savio's Common UI Plugin Documentation

- This plugin provides a suite of handy utilities, components, and a generic setup for using the Common UI Plugin, by default Common UI will be enabled with this plugin


Project Settings

- The plugin content folder has a couple things you should assign in the project settings (unless you plan on creating your own)

Under Game/CommonInputSettings
- Assign the BP_GenericUIInputDate to the Input Data
- Due to Common UI standards, under the Platform Input section, you will see Default Gamepad Name, its recommended to change the name to "Generic" rather than "Windows"
- I also recommend creating Controller Data right away, and assigning it to the correct platform, under Platform Input in the chosen platform (ie. Windows) you will see a Controller Data Array where you can assign your CommonInputBaseControllerData - just create a child bp of CommonInputBaseControllerData, I usually make one for Keyboard, and one for Generic Gamepads

Under Plugins/CommonUIEditor
- Assign the Generic_TextStyle, Generic_ButtonStyle, and Generic_BorderStyle to the corresponding Template Stying. This will make sure whenever you create a new Common Text, Common Button Base, or Common Border that there is a default style assigned to it

Under Plugins/CommonUIInputSettings
- This isn't required, but if you ever plan on using CommonTabListWidgetBase for Tab Lists, I recommend assigning actions for UI.Action.NextTab, and UI.Action.PreviosTab, its not required to assign actions for Confirm and Cancel because that is already handled through the CommonUIInputData in the CommonInputSettings, but CommonUIInputData does not handle actions for switching tabs using the CommonTabListWidgetBase


The CommonUIData

- This is just a simple script for Enums and Structs used in the plugin

EWidgetStack
- This is used for easily getting the Primary, Secondary, and Tertiary Stacks within the UIBaseWidget


The CommonUIPlayerController

- This is a child of the PlayerController

- BP_CommonUIPlayerController is located in the plugin content folder, and if you are planning on only using blueprints, this is a perfect parent class for your Player Controller


The CommonUIInterface

- This interface contains the core functions for the managing UI within the CommonUIPlayerController

PushWidgetToStack
- Pushes a widget to the chosen Stack on the UIBaseWidget

RemoveWidgetFromStack
- Removes the input widget from the chosen Stack on the UIBaseWidget

ClearWidgetsFromStack
- Clears all widgets on the chosen Stack on the UIBaseWidget

GetUIBaseWidget
- Retrieves the UIBaseWidget created in the CommonUIComponent


The BP_UIBaseWidget

- The BP_UIBaseWidget is just a simple container for holding the core CommonActivatableWidgetStacks (uses EWidgetStack in CommonUIData for easily retrieving Primary, Secondary, and Tertiary Stacks)

- Located in the plugin Content/Widgets folder, this is an example for the minimalistic setup required for the UIBaseWidget
- It is also assigned by default in the BP_CommonUIPlayerController as a good example of how to set things up
- The main things a UIBaseWidget requires is the UIBaseWidgetInterface setup, which handles two core functions (GetWidgetStack, and GetWidgetActiveOnStack)
- This setup is required for this plugin because GetWidgetStack is highly used within the CommonUIPlayerController within the Implementation of the CommonUIInterface functions in order to get the correct Stack needed to manage the widgets, whether Pushing, Removing, or Clearing, this defines which Stack you are modifying

