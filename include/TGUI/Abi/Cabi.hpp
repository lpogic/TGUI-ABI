#ifndef CABI_HPP
#define CABI_HPP

#define C_ABI_RAW extern "C"  __declspec(dllexport)
#define C_ABI_METHOD extern "C"  __declspec(dllexport)
#define C_ABI_STATIC extern "C"  __declspec(dllexport)
#define C_ABI_SETTER extern "C"  __declspec(dllexport)
#define C_ABI_GETTER extern "C"  __declspec(dllexport)
#define C_ABI_TESTER extern "C"  __declspec(dllexport)
#define C_ABI_MAKE extern "C"  __declspec(dllexport)
#define C_ABI_FREE extern "C"  __declspec(dllexport)
#define C_ABI_SIGNAL extern "C"  __declspec(dllexport)

#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>


namespace tgui
{
	typedef SignalTyped2<int, bool*> SignalTypedIntBoolPtr;

	// Util
	C_ABI_STATIC void ABI_Util_free(void* pointer);
	// Color
	C_ABI_MAKE Color* ABI_Color_new(int r, int g, int b, int a);
	C_ABI_GETTER int ABI_Color_get_red(Color* self);
	C_ABI_GETTER int ABI_Color_get_green(Color* self);
	C_ABI_GETTER int ABI_Color_get_blue(Color* self);
	C_ABI_GETTER int ABI_Color_get_alpha(Color* self);
	C_ABI_METHOD Color* ABI_Color_fade(Color* self, float fade);
	// Signal
	C_ABI_RAW int ABI_Signal_connect(Signal* self, void(*f)());
	C_ABI_RAW bool ABI_Signal_disconnect(Signal* self, int f);
	// SignalString
	C_ABI_RAW int ABI_SignalString_connect(SignalString* self, void(*f)(const char32_t*));
	// SignalBool
	C_ABI_RAW int ABI_SignalBool_connect(SignalBool* self, void(*f)(int));
	// SignalInt
	C_ABI_RAW int ABI_SignalInt_connect(SignalInt* self, void(*f)(int));
	// SignalUInt
	C_ABI_RAW int ABI_SignalUInt_connect(SignalUInt* self, void(*f)(unsigned int));
	// SignalFloat
	C_ABI_RAW int ABI_SignalFloat_connect(SignalFloat* self, void(*f)(float));
	// SignalRange
	C_ABI_RAW int ABI_SignalRange_connect(SignalRange* self, void(*f)(float, float));
	// SignalPointer
	C_ABI_RAW int ABI_SignalPointer_connect(SignalTyped<void*>* self, void(*f)(void*));
	// SignalColor
	C_ABI_RAW int ABI_SignalColor_connect(SignalColor* self, void(*f)(void*));
	// SignalVector2f
	C_ABI_RAW int ABI_SignalVector2f_connect(SignalVector2f* self, void(*f)(void*));
	// SignalShowEffect
	C_ABI_RAW int ABI_SignalShowEffect_connect(SignalShowEffect* self, void(*f)(int, int));
	// SignalAnimationType
	C_ABI_RAW int ABI_SignalAnimationType_connect(SignalAnimationType* self, void(*f)(int));
	// SignalItem
	C_ABI_RAW int ABI_SignalItem_connect(SignalItem* self, void(*f)(const char32_t*, const char32_t*));
	// SignalItemHierarchy
	C_ABI_RAW int ABI_SignalItemHierarchy_connect(SignalItemHierarchy* self, void(*f)(void*));
	C_ABI_STATIC void ABI_SignalItemHierarchy_fetchPath(std::vector< String >* load, void(*f)(const char32_t*));
	// SignalTypedIntBoolPtr
	C_ABI_RAW int ABI_SignalTypedIntBoolPtr_connect(SignalTypedIntBoolPtr* self, void(*f)(int, bool*));
	// Window
	C_ABI_MAKE sf::RenderWindow* ABI_Window_new();
	C_ABI_METHOD void ABI_Window_close(sf::WindowBase* self);
	C_ABI_TESTER bool ABI_Window_isOpen(sf::WindowBase* self);
	// Gui
	C_ABI_MAKE Gui* ABI_Gui_new(sf::RenderWindow* window);
	C_ABI_TESTER bool ABI_Gui_isActive(Gui* self);
	C_ABI_METHOD void ABI_Gui_pollEvents(Gui* self);
	C_ABI_METHOD void ABI_Gui_draw(Gui* self);
	C_ABI_METHOD void ABI_Gui_add(Gui* self, Widget::Ptr* widget, const char* name);
	C_ABI_METHOD void ABI_Gui_remove(Gui* self, Widget::Ptr* widget);
	C_ABI_METHOD void ABI_Gui_removeAll(Gui* self);
	C_ABI_METHOD void ABI_Gui_mainLoop(Gui* self);
	C_ABI_RAW Widget::Ptr* ABI_Gui_getWidget(Gui* self, const char* name);
	// Theme
	C_ABI_STATIC void ABI_Theme_setDefault(char* theme);
	// Texture
	C_ABI_MAKE Texture* ABI_Texture_new(char* id, int partRectX, int partRectY, int partRectW, int partRectH, int middlePartX, int middlePartY, int middlePartW, int middlePartH, int smooth);
	C_ABI_GETTER const char32_t* ABI_Texture_getId(Texture* self);
	C_ABI_GETTER Vector2u* ABI_Texture_getImageSize(Texture* self);
	C_ABI_GETTER UIntRect* ABI_Texture_getPartRect(Texture* self);
	C_ABI_SETTER void ABI_Texture_setColor(Texture* self, int red, int green, int blue);
	C_ABI_GETTER Color* ABI_Texture_getColor(Texture* self);
	C_ABI_TESTER bool ABI_Texture_isSmooth(Texture* self);
	// Widget
	C_ABI_FREE void ABI_Widget_free(std::shared_ptr<Widget>* pointer);
	C_ABI_STATIC Widget* ABI_Widget_getUnshared(std::shared_ptr<Widget>* pointer);
	C_ABI_STATIC const char32_t* ABI_Widget_getType(Widget::Ptr* self);
	C_ABI_GETTER const char32_t* ABI_Widget_getName(Widget::Ptr* self);
	C_ABI_SETTER void ABI_Widget_setSize(Widget::Ptr* self, const char* width, const char* height);
	C_ABI_GETTER Vector2f* ABI_Widget_getSize(Widget::Ptr* self);
	C_ABI_GETTER Vector2f* ABI_Widget_getFullSize(Widget::Ptr* self);
	C_ABI_SETTER void ABI_Widget_setPosition(Widget::Ptr* self, const char* x, const char* y);
	C_ABI_GETTER Vector2f* ABI_Widget_getPosition(Widget::Ptr* self);
	C_ABI_GETTER Vector2f* ABI_Widget_getAbsolutePosition(Widget::Ptr* self);
	C_ABI_SETTER void ABI_Widget_setWidth(Widget::Ptr* self, const char* width);
	C_ABI_SETTER void ABI_Widget_setHeight(Widget::Ptr* self, const char* height);
	C_ABI_SETTER void ABI_Widget_setVisible(Widget::Ptr* self, int visible);
	C_ABI_TESTER bool ABI_Widget_isVisible(Widget::Ptr* self);
	C_ABI_SETTER void ABI_Widget_setEnabled(Widget::Ptr* self, int enabled);
	C_ABI_TESTER bool ABI_Widget_isEnabled(Widget::Ptr* self);
	C_ABI_SETTER void ABI_Widget_setFocused(Widget::Ptr* self, int focused);
	C_ABI_TESTER bool ABI_Widget_isFocused(Widget::Ptr* self);
	C_ABI_SETTER void ABI_Widget_setFocusable(Widget::Ptr* self, int focusable);
	C_ABI_TESTER bool ABI_Widget_isFocusable(Widget::Ptr* self);
	C_ABI_TESTER bool ABI_Widget_canGainFocus(Widget::Ptr* self);
	C_ABI_TESTER bool ABI_Widget_isContainer(Widget::Ptr* self);
	C_ABI_SIGNAL SignalVector2f* ABI_Widget_onPositionChange(Widget::Ptr* self);
	C_ABI_SIGNAL SignalVector2f* ABI_Widget_onSizeChange(Widget::Ptr* self);
	C_ABI_SIGNAL Signal* ABI_Widget_onFocus(Widget::Ptr* self);
	C_ABI_SIGNAL Signal* ABI_Widget_onUnfocus(Widget::Ptr* self);
	C_ABI_SIGNAL Signal* ABI_Widget_onMouseEnter(Widget::Ptr* self);
	C_ABI_SIGNAL Signal* ABI_Widget_onMouseLeave(Widget::Ptr* self);
	C_ABI_SIGNAL SignalShowEffect* ABI_Widget_onShowEffectFinish(Widget::Ptr* self);
	C_ABI_SIGNAL SignalAnimationType* ABI_Widget_onAnimationFinish(Widget::Ptr* self);
	// ClickableWidget
	C_ABI_SIGNAL SignalVector2f* ABI_ClickableWidget_onMousePress(ClickableWidget::Ptr* self);
	C_ABI_SIGNAL SignalVector2f* ABI_ClickableWidget_onMouseRelease(ClickableWidget::Ptr* self);
	C_ABI_SIGNAL SignalVector2f* ABI_ClickableWidget_onClick(ClickableWidget::Ptr* self);
	C_ABI_SIGNAL SignalVector2f* ABI_ClickableWidget_onRightMousePress(ClickableWidget::Ptr* self);
	C_ABI_SIGNAL SignalVector2f* ABI_ClickableWidget_onRightMouseRelease(ClickableWidget::Ptr* self);
	C_ABI_SIGNAL SignalVector2f* ABI_ClickableWidget_onRightClick(ClickableWidget::Ptr* self);
	// ButtonBase
	C_ABI_RAW void ABI_ButtonBase_setTextPosition(ButtonBase::Ptr* self, const char* position, const char* origin);
	// Button
	C_ABI_MAKE Button::Ptr* ABI_Button_new();
	C_ABI_SETTER void ABI_Button_setText(Button::Ptr* self, const char* text);
	C_ABI_GETTER const char32_t* ABI_Button_getText(Button::Ptr* self);
	C_ABI_SIGNAL Signal* ABI_Button_onPress(Button::Ptr* self);
	// BitmapButton
	C_ABI_MAKE BitmapButton::Ptr* ABI_BitmapButton_new();
	C_ABI_RAW void ABI_BitmapButton_setImage(BitmapButton::Ptr* self, Texture* texture);
	C_ABI_GETTER Texture* ABI_BitmapButton_getImage(BitmapButton::Ptr* self);
	C_ABI_SETTER void ABI_BitmapButton_setImageScaling(BitmapButton::Ptr* self, float relativeHeight);
	C_ABI_GETTER float ABI_BitmapButton_getImageScaling(BitmapButton::Ptr* self);
	// EditBox
	C_ABI_MAKE EditBox::Ptr* ABI_EditBox_new();
	C_ABI_SETTER void ABI_EditBox_setText(EditBox::Ptr* self, const char* text);
	C_ABI_GETTER const char32_t* ABI_EditBox_getText(EditBox::Ptr* self);
	C_ABI_SETTER void ABI_EditBox_setDefaultText(EditBox::Ptr* self, const char* text);
	C_ABI_GETTER const char32_t* ABI_EditBox_getDefaultText(EditBox::Ptr* self);
	C_ABI_METHOD void ABI_EditBox_selectText(EditBox::Ptr* self, int start, int length);
	C_ABI_GETTER const char32_t* ABI_EditBox_getSelectedText(EditBox::Ptr* self);
	C_ABI_SETTER void ABI_EditBox_setPasswordCharacter(EditBox::Ptr* self, char* character);
	C_ABI_GETTER char ABI_EditBox_getPasswordCharacter(EditBox::Ptr* self);
	C_ABI_SETTER void ABI_EditBox_setMaximumCharacters(EditBox::Ptr* self, unsigned int max);
	C_ABI_GETTER unsigned int ABI_EditBox_getMaximumCharacters(EditBox::Ptr* self);
	C_ABI_RAW void ABI_EditBox_setAlignment(EditBox::Ptr* self, int alignment);
	C_ABI_RAW int ABI_EditBox_getAlignment(EditBox::Ptr* self);
	C_ABI_SETTER void ABI_EditBox_limitTextWidth(EditBox::Ptr* self, int limit);
	C_ABI_TESTER bool ABI_EditBox_isTextWidthLimited(EditBox::Ptr* self);
	C_ABI_SETTER void ABI_EditBox_setReadOnly(EditBox::Ptr* self, int read_only);
	C_ABI_TESTER bool ABI_EditBox_isReadOnly(EditBox::Ptr* self);
	C_ABI_SETTER void ABI_EditBox_setCaretPosition(EditBox::Ptr* self, int caretPosition);
	C_ABI_GETTER int ABI_EditBox_getCaretPosition(EditBox::Ptr* self);
	C_ABI_SETTER void ABI_EditBox_setSuffix(EditBox::Ptr* self, char* suffix);
	C_ABI_GETTER const char32_t* ABI_EditBox_getSuffix(EditBox::Ptr* self);
	C_ABI_SIGNAL SignalString* ABI_EditBox_onTextChange(EditBox::Ptr* self);
	C_ABI_SIGNAL SignalString* ABI_EditBox_onReturnKeyPress(EditBox::Ptr* self);
	C_ABI_SIGNAL SignalString* ABI_EditBox_onReturnOrUnfocus(EditBox::Ptr* self);
	// Label
	C_ABI_MAKE Label::Ptr* ABI_Label_new(char* text);
    C_ABI_SETTER void ABI_Label_setText(Label::Ptr* self, char* text);
    C_ABI_GETTER const char32_t* ABI_Label_getText(Label::Ptr* self);
    C_ABI_RAW void ABI_Label_setHorizontalAlignment(Label::Ptr* self, int alignment);
    C_ABI_RAW int ABI_Label_getHorizontalAlignment(Label::Ptr* self);
    C_ABI_RAW void ABI_Label_setVerticalAlignment(Label::Ptr* self, int alignment);
    C_ABI_RAW int ABI_Label_getVerticalAlignment(Label::Ptr* self);
	C_ABI_RAW void ABI_Label_setScrollbarPolicy(Label::Ptr* self, int policy);
	C_ABI_RAW int ABI_Label_getScrollbarPolicy(Label::Ptr* self);
	C_ABI_SETTER void ABI_Label_setScrollbarValue(Label::Ptr* self, unsigned int value);
	C_ABI_GETTER int ABI_Label_getScrollbarValue(Label::Ptr* self);
	C_ABI_SETTER void ABI_Label_setAutoSize(Label::Ptr* self, int auto_size);
	C_ABI_GETTER bool ABI_Label_getAutoSize(Label::Ptr* self);
	C_ABI_SETTER void ABI_Label_setMaximumTextWidth(Label::Ptr* self, float maximumWidth);
	C_ABI_GETTER float ABI_Label_getMaximumTextWidth(Label::Ptr* self);
	C_ABI_SETTER void ABI_Label_ignoreMouseEvents(Label::Ptr* self, int ignore);
	C_ABI_TESTER bool ABI_Label_ignoringMouseEvents(Label::Ptr* self);
	// RadioButton
	C_ABI_MAKE RadioButton::Ptr* ABI_RadioButton_new();
	C_ABI_SETTER void ABI_RadioButton_setText(RadioButton::Ptr* self, char* text);
	C_ABI_GETTER const char32_t* ABI_RadioButton_getText(RadioButton::Ptr* self);
	C_ABI_SETTER void ABI_RadioButton_setChecked(RadioButton::Ptr* self, int checked);
	C_ABI_TESTER bool ABI_RadioButton_isChecked(RadioButton::Ptr* self);
	C_ABI_SETTER void ABI_RadioButton_setTextClickable(RadioButton::Ptr* self, int textClickable);
	C_ABI_TESTER bool ABI_RadioButton_isTextClickable(RadioButton::Ptr* self);
	C_ABI_SIGNAL SignalBool* ABI_RadioButton_onCheck(RadioButton::Ptr* self);
	C_ABI_SIGNAL SignalBool* ABI_RadioButton_onUncheck(RadioButton::Ptr* self);
	C_ABI_SIGNAL SignalBool* ABI_RadioButton_onChange(RadioButton::Ptr* self);
	// CheckBox
	C_ABI_MAKE CheckBox::Ptr* ABI_CheckBox_new();
	// Knob
	C_ABI_MAKE Knob::Ptr* ABI_Knob_new();
	C_ABI_SETTER void ABI_Knob_setStartRotation(Knob::Ptr* self, float startRotation);
	C_ABI_GETTER float ABI_Knob_getStartRotation(Knob::Ptr* self);
	C_ABI_SETTER void ABI_Knob_setEndRotation(Knob::Ptr* self, float endRotation);
	C_ABI_GETTER float ABI_Knob_getEndRotation(Knob::Ptr* self);
	C_ABI_SETTER void ABI_Knob_setMinimum(Knob::Ptr* self, float minimum);
	C_ABI_GETTER float ABI_Knob_getMinimum(Knob::Ptr* self);
	C_ABI_SETTER void ABI_Knob_setMaximum(Knob::Ptr* self, float maximum);
	C_ABI_GETTER float ABI_Knob_getMaximum(Knob::Ptr* self);
	C_ABI_SETTER void ABI_Knob_setValue(Knob::Ptr* self, float value);
	C_ABI_GETTER float ABI_Knob_getValue(Knob::Ptr* self);
	C_ABI_SETTER void ABI_Knob_setClockwiseTurning(Knob::Ptr* self, int clockwiseTurning);
	C_ABI_TESTER float ABI_Knob_getClockwiseTurning(Knob::Ptr* self);
	C_ABI_SIGNAL SignalFloat* ABI_Knob_onValueChange(Knob::Ptr* self);
	//// ChatBox
	//C_ABI_MAKE ChatBox::Ptr* ABI_ChatBox_make();
	//C_ABI_METHOD void ABI_ChatBox_add_line(ChatBox::Ptr* self, char* text, char* color, unsigned int style);
	//void addLine(const String& text, Color color, TextStyles style);
 //   TGUI_NODISCARD String getLine(std::size_t lineIndex) const;
 //   TGUI_NODISCARD Color getLineColor(std::size_t lineIndex) const;
 //   TGUI_NODISCARD TextStyles getLineTextStyle(std::size_t lineIndex) const;
 //   bool removeLine(std::size_t lineIndex);
 //   void removeAllLines();
 //   TGUI_NODISCARD std::size_t getLineAmount();
 //   void setLineLimit(std::size_t maxLines);
 //   TGUI_NODISCARD std::size_t getLineLimit();
 //   void setTextColor(Color color);
 //   TGUI_NODISCARD const Color& getTextColor() const;
 //   void setTextStyle(TextStyles style);
 //   TGUI_NODISCARD TextStyles getTextStyle() const;
 //   void setLinesStartFromTop(bool startFromTop = true);
 //   TGUI_NODISCARD bool getLinesStartFromTop() const;
 //   void setNewLinesBelowOthers(bool newLinesBelowOthers = true);
 //   TGUI_NODISCARD bool getNewLinesBelowOthers() const;
 //   void setScrollbarValue(unsigned int value);
 //   TGUI_NODISCARD unsigned int getScrollbarValue() const;
 
	// Container
	C_ABI_RAW void ABI_Container_get_widgets(Container::Ptr* self, void(*f)(Widget::Ptr* widget, const char32_t* type));
	C_ABI_METHOD void ABI_Container_add(Container::Ptr* self, Widget::Ptr* widget, char* name);
	C_ABI_RAW Widget::Ptr* ABI_Container_get(Container::Ptr* self, char* name);
	C_ABI_METHOD bool ABI_Container_remove(Container::Ptr* self, Widget::Ptr* widget);
	C_ABI_METHOD void ABI_Container_removeAllWidgets(Container::Ptr* self);
	C_ABI_GETTER Vector2f* ABI_Container_getInnerSize(Container::Ptr* self);
	C_ABI_GETTER Vector2f* ABI_Container_getChildWidgetsOffset(Container::Ptr* self);
	C_ABI_METHOD void ABI_Container_moveWidgetToFront(Container::Ptr* self, Widget::Ptr* widget);
	C_ABI_METHOD void ABI_Container_moveWidgetToBack(Container::Ptr* self, Widget::Ptr* widget);
	C_ABI_METHOD int ABI_Container_moveWidgetForward(Container::Ptr* self, Widget::Ptr* widget);
	C_ABI_METHOD int ABI_Container_moveWidgetBackward(Container::Ptr* self, Widget::Ptr* widget);
	C_ABI_SETTER bool ABI_Container_setWidgetIndex(Container::Ptr* self, Widget::Ptr* widget, int index);
	C_ABI_GETTER int ABI_Container_getWidgetIndex(Container::Ptr* self, Widget::Ptr* widget);
	C_ABI_GETTER Widget::Ptr* ABI_Container_getFocusedChild(Container::Ptr* self);
	C_ABI_GETTER Widget::Ptr* ABI_Container_getFocusedLeaf(Container::Ptr* self);
	C_ABI_GETTER Widget::Ptr* ABI_Container_getWidgetAtPosition(Container::Ptr* self, float x, float y);
	C_ABI_METHOD bool ABI_Container_focusNextWidget(Container::Ptr* self, int recursive);
	C_ABI_METHOD bool ABI_Container_focusPreviousWidget(Container::Ptr* self, int recursive);
	C_ABI_SETTER void ABI_Container_setFocused(Container::Ptr* self, int focused);
	// ChildWindow
	C_ABI_MAKE ChildWindow::Ptr* ABI_ChildWindow_new();
    C_ABI_SETTER void ABI_ChildWindow_setClientSize(ChildWindow::Ptr* self, char* size);
	C_ABI_GETTER Vector2f* ABI_ChildWindow_getClientSize(ChildWindow::Ptr* self);
    C_ABI_SETTER void ABI_ChildWindow_setMaximumSize(ChildWindow::Ptr* self, float x, float y);
    C_ABI_GETTER Vector2f* ABI_ChildWindow_getMaximumSize(ChildWindow::Ptr* self);
    C_ABI_SETTER void ABI_ChildWindow_setMinimumSize(ChildWindow::Ptr* self, float x, float y);
	C_ABI_GETTER Vector2f* ABI_ChildWindow_getMinimumSize(ChildWindow::Ptr* self);
    C_ABI_SETTER void ABI_ChildWindow_setTitle(ChildWindow::Ptr* self, char* title);
	C_ABI_GETTER const char32_t* ABI_ChildWindow_getTitle(ChildWindow::Ptr* self);
    C_ABI_SETTER void ABI_ChildWindow_setTitleTextSize(ChildWindow::Ptr* self, unsigned int size);
	C_ABI_GETTER unsigned int ABI_ChildWindow_getTitleTextSize(ChildWindow::Ptr* self);
    C_ABI_RAW void ABI_ChildWindow_setTitleAlignment(ChildWindow::Ptr* self, int alignment);
	C_ABI_RAW int ABI_ChildWindow_getTitleAlignment(ChildWindow::Ptr* self);
    C_ABI_RAW void ABI_ChildWindow_setTitleButtons(ChildWindow::Ptr* self, unsigned int buttons);
    C_ABI_RAW unsigned int ABI_ChildWindow_getTitleButtons(ChildWindow::Ptr* self);
    C_ABI_METHOD void ABI_ChildWindow_close(ChildWindow::Ptr* self);
    C_ABI_METHOD void ABI_ChildWindow_destroy(ChildWindow::Ptr* self);
    C_ABI_SETTER void ABI_ChildWindow_setResizable(ChildWindow::Ptr* self, int resizable);
	C_ABI_TESTER bool ABI_ChildWindow_isResizable(ChildWindow::Ptr* self);
    C_ABI_SETTER void ABI_ChildWindow_setPositionLocked(ChildWindow::Ptr* self, int positionLocked);
	C_ABI_TESTER bool ABI_ChildWindow_isPositionLocked(ChildWindow::Ptr* self);
    C_ABI_SETTER void ABI_ChildWindow_setKeepInParent(ChildWindow::Ptr* self, int enabled);
	C_ABI_TESTER bool ABI_ChildWindow_isKeptInParent(ChildWindow::Ptr* self);
	C_ABI_SIGNAL Signal* ABI_ChildWindow_onMousePress(ChildWindow::Ptr* self);
	C_ABI_SIGNAL Signal* ABI_ChildWindow_onClose(ChildWindow::Ptr* self);
	C_ABI_SIGNAL Signal* ABI_ChildWindow_onMinimize(ChildWindow::Ptr* self);
	C_ABI_SIGNAL Signal* ABI_ChildWindow_onMaximize(ChildWindow::Ptr* self);
	C_ABI_SIGNAL Signal* ABI_ChildWindow_onEscapeKeyPress(ChildWindow::Ptr* self);
	C_ABI_SIGNAL SignalTyped<bool*>* ABI_ChildWindow_onClosing(ChildWindow::Ptr* self);
	// Group
	C_ABI_MAKE Group::Ptr* ABI_Group_new();
	// BoxLayout
	C_ABI_RAW Widget::Ptr* ABI_BoxLayout_getByIndex(BoxLayout::Ptr* self, int index);
	C_ABI_METHOD void ABI_BoxLayout_insert(BoxLayout::Ptr* self, int index, Widget::Ptr* widget, char* name);
	C_ABI_RAW bool ABI_BoxLayout_removeByIndex(BoxLayout::Ptr* self, int index);
	// BoxLayoutRatios
	C_ABI_METHOD void ABI_BoxLayoutRatios_addSpace(BoxLayoutRatios::Ptr* self, float ratio);
	C_ABI_METHOD void ABI_BoxLayoutRatios_insertSpace(BoxLayoutRatios::Ptr* self, int index, float ratio);
	C_ABI_RAW void ABI_BoxLayoutRatios_setRatio(BoxLayoutRatios::Ptr* self, Widget::Ptr* widget, float ratio);
	C_ABI_RAW void ABI_BoxLayoutRatios_setRatioByIndex(BoxLayoutRatios::Ptr* self, int index, float ratio);
	C_ABI_RAW float ABI_BoxLayoutRatios_getRatio(BoxLayoutRatios::Ptr* self, Widget::Ptr* widget);
	C_ABI_RAW float ABI_BoxLayoutRatios_getRatioByIndex(BoxLayoutRatios::Ptr* self, int index);
	// HorizontalLayout
	C_ABI_MAKE HorizontalLayout::Ptr* ABI_HorizontalLayout_create();
	// VerticalLayout
	C_ABI_MAKE VerticalLayout::Ptr* ABI_VerticalLayout_create();
	// HorizontalWrap
	C_ABI_MAKE HorizontalWrap::Ptr* ABI_HorizontalWrap_create();
	// RadioButtonGroup
	C_ABI_MAKE RadioButtonGroup::Ptr* ABI_RadioButtonGroup_create();
	C_ABI_METHOD void ABI_RadioButtonGroup_uncheckRadioButtons(RadioButtonGroup::Ptr* self);
	C_ABI_GETTER RadioButton::Ptr* ABI_RadioButtonGroup_getCheckedRadioButton(RadioButtonGroup::Ptr* self);
	// Panel
	C_ABI_MAKE Panel::Ptr* ABI_Panel_create();
	C_ABI_SIGNAL SignalVector2f* ABI_Panel_onMousePress(Panel::Ptr* self);
	C_ABI_SIGNAL SignalVector2f* ABI_Panel_onMouseRelease(Panel::Ptr* self);
	C_ABI_SIGNAL SignalVector2f* ABI_Panel_onClick(Panel::Ptr* self);
	C_ABI_SIGNAL SignalVector2f* ABI_Panel_onDoubleClick(Panel::Ptr* self);
	C_ABI_SIGNAL SignalVector2f* ABI_Panel_onRightMousePress(Panel::Ptr* self);
	C_ABI_SIGNAL SignalVector2f* ABI_Panel_onRightMouseRelease(Panel::Ptr* self);
	C_ABI_SIGNAL SignalVector2f* ABI_Panel_onRightClick(Panel::Ptr* self);
	// ScrollablePanel
	C_ABI_MAKE ScrollablePanel::Ptr* ABI_ScrollablePanel_create();
	C_ABI_SETTER void ABI_ScrollablePanel_setContentSize(ScrollablePanel::Ptr* self, float x, float y);
	C_ABI_GETTER Vector2f* ABI_ScrollablePanel_getContentSize(ScrollablePanel::Ptr* self);
	C_ABI_GETTER Vector2f* ABI_ScrollablePanel_getContentOffset(ScrollablePanel::Ptr* self);
	C_ABI_GETTER float ABI_ScrollablePanel_getScrollbarWidth(ScrollablePanel::Ptr* self);
	C_ABI_SETTER void ABI_ScrollablePanel_setVerticalScrollbarPolicy(ScrollablePanel::Ptr* self, int policy);
	C_ABI_GETTER int ABI_ScrollablePanel_getVerticalScrollbarPolicy(ScrollablePanel::Ptr* self);
	C_ABI_SETTER void ABI_ScrollablePanel_setHorizontalScrollbarPolicy(ScrollablePanel::Ptr* self, int policy);
	C_ABI_GETTER int ABI_ScrollablePanel_getHorizontalScrollbarPolicy(ScrollablePanel::Ptr* self);
	C_ABI_SETTER void ABI_ScrollablePanel_setVerticalScrollAmount(ScrollablePanel::Ptr* self, int amount);
	C_ABI_GETTER int ABI_ScrollablePanel_getVerticalScrollAmount(ScrollablePanel::Ptr* self);
	C_ABI_SETTER void ABI_ScrollablePanel_setHorizontalScrollAmount(ScrollablePanel::Ptr* self, int amount);
	C_ABI_GETTER int ABI_ScrollablePanel_getHorizontalScrollAmount(ScrollablePanel::Ptr* self);
	C_ABI_SETTER void ABI_ScrollablePanel_setVerticalScrollbarValue(ScrollablePanel::Ptr* self, int value);
	C_ABI_GETTER int ABI_ScrollablePanel_getVerticalScrollbarValue(ScrollablePanel::Ptr* self);
	C_ABI_SETTER void ABI_ScrollablePanel_setHorizontalScrollbarValue(ScrollablePanel::Ptr* self, int value);
	C_ABI_GETTER int ABI_ScrollablePanel_getHorizontalScrollbarValue(ScrollablePanel::Ptr* self);
	// Grid
	C_ABI_MAKE Grid::Ptr* ABI_Grid_make();
	C_ABI_SETTER void ABI_Grid_setAutoSize(Grid::Ptr* self, int autoSize);
	C_ABI_GETTER bool ABI_Grid_isAutoSize(Grid::Ptr* self);
	C_ABI_RAW bool ABI_Grid_setWidgetCell(Grid::Ptr* self, Widget::Ptr* widget, int row, int column);
	C_ABI_RAW Widget::Ptr* ABI_Grid_getWidget(Grid::Ptr* self, int row, int column);
	C_ABI_RAW void ABI_Grid_setWidgetPadding(Grid::Ptr* self, Widget::Ptr* widget, char* paddingLeft, char* paddingRight, char* paddingTop, char* paddingBottom);
	C_ABI_RAW Outline* ABI_Grid_getWidgetPadding(Grid::Ptr* self, Widget::Ptr* widget);
	C_ABI_RAW void ABI_Grid_setWidgetAlignment(Grid::Ptr* self, Widget::Ptr* widget, int alignment);
	C_ABI_RAW int ABI_Grid_getWidgetAlignment(Grid::Ptr* self, Widget::Ptr* widget);
	// ListBox
	C_ABI_MAKE ListBox::Ptr* ABI_ListBox_new();
	C_ABI_METHOD int ABI_ListBox_addItem(ListBox::Ptr* self, char* itemName, char* id);
	C_ABI_SETTER bool ABI_ListBox_setSelectedItem(ListBox::Ptr* self, char* itemName);
	C_ABI_SETTER bool ABI_ListBox_setSelectedItemById(ListBox::Ptr* self, char* id);
	C_ABI_SETTER bool ABI_ListBox_setSelectedItemByIndex(ListBox::Ptr* self, int index);
	C_ABI_METHOD void ABI_ListBox_deselectItem(ListBox::Ptr* self);
	C_ABI_METHOD bool ABI_ListBox_removeItem(ListBox::Ptr* self, char* itemName);
	C_ABI_METHOD bool ABI_ListBox_removeItemById(ListBox::Ptr* self, char* id);
	C_ABI_METHOD bool ABI_ListBox_removeItemByIndex(ListBox::Ptr* self, int index);
	C_ABI_METHOD void ABI_ListBox_removeAllItems(ListBox::Ptr* self);
	C_ABI_GETTER const char32_t* ABI_ListBox_getItemById(ListBox::Ptr* self, char* id);
	C_ABI_GETTER const char32_t* ABI_ListBox_getItemByIndex(ListBox::Ptr* self, int index);
	C_ABI_GETTER int ABI_ListBox_getIndexById(ListBox::Ptr* self, char* id);
	C_ABI_GETTER const char32_t* ABI_ListBox_getIdByIndex(ListBox::Ptr* self, int index);
	C_ABI_GETTER const char32_t* ABI_ListBox_getSelectedItem(ListBox::Ptr* self);
	C_ABI_GETTER const char32_t* ABI_ListBox_getSelectedItemId(ListBox::Ptr* self);
	C_ABI_GETTER const int ABI_ListBox_getSelectedItemIndex(ListBox::Ptr* self);
	C_ABI_METHOD bool ABI_ListBox_changeItem(ListBox::Ptr* self, char* originalValue, char* newValue);
	C_ABI_METHOD bool ABI_ListBox_changeItemById(ListBox::Ptr* self, char* id, char* newValue);
	C_ABI_METHOD bool ABI_ListBox_changeItemByIndex(ListBox::Ptr* self, int index, char* newValue);
	C_ABI_GETTER int ABI_ListBox_getItemCount(ListBox::Ptr* self);
	C_ABI_RAW void ABI_ListBox_getItems(ListBox::Ptr* self, void(*f)(const char32_t*));
	C_ABI_RAW void ABI_ListBox_getItemIds(ListBox::Ptr* self, void(*f)(const char32_t*));
	C_ABI_SETTER void ABI_ListBox_setItemHeight(ListBox::Ptr* self, int itemHeight);
	C_ABI_GETTER int ABI_ListBox_getItemHeight(ListBox::Ptr* self);
	C_ABI_SETTER void ABI_ListBox_setMaximumItems(ListBox::Ptr* self, int maximumItems);
	C_ABI_GETTER int ABI_ListBox_getMaximumItems(ListBox::Ptr* self);
	C_ABI_SETTER void ABI_ListBox_setAutoScroll(ListBox::Ptr* self, int autoScroll);
	C_ABI_TESTER bool ABI_ListBox_getAutoScroll(ListBox::Ptr* self);
	C_ABI_RAW void ABI_ListBox_setTextAlignment(ListBox::Ptr* self, int alignment);
	C_ABI_RAW int ABI_ListBox_getTextAlignment(ListBox::Ptr* self);
	C_ABI_TESTER bool ABI_ListBox_contains(ListBox::Ptr* self, char* item);
	C_ABI_TESTER bool ABI_ListBox_containsId(ListBox::Ptr* self, char* id);
	C_ABI_SETTER void ABI_ListBox_setScrollbarValue(ListBox::Ptr* self, int value);
	C_ABI_GETTER int ABI_ListBox_getScrollbarValue(ListBox::Ptr* self);
	C_ABI_SIGNAL SignalItem* onItemSelect(ListBox::Ptr* self);
	C_ABI_SIGNAL SignalItem* onMousePress(ListBox::Ptr* self);
	C_ABI_SIGNAL SignalItem* onMouseRelease(ListBox::Ptr* self);
	C_ABI_SIGNAL SignalItem* onDoubleClick(ListBox::Ptr* self);
	C_ABI_SIGNAL Signal* onScroll(ListBox::Ptr* self);
	// ListView
	C_ABI_MAKE ListView::Ptr* ABI_ListView_make();
	C_ABI_METHOD int ABI_ListView_addColumn(ListView::Ptr* self);
	C_ABI_SETTER void ABI_ListView_setColumnText(ListView::Ptr* self, int index, char* text);
	C_ABI_GETTER const char32_t* ABI_ListView_getColumnText(ListView::Ptr* self, int index);
	C_ABI_SETTER void ABI_ListView_setColumnWidth(ListView::Ptr* self, int index, float width);
	C_ABI_GETTER float ABI_ListView_getColumnWidth(ListView::Ptr* self, int index);
	C_ABI_RAW void ABI_ListView_setColumnAlignment(ListView::Ptr* self, int index, int columnAlignment);
	C_ABI_RAW int ABI_ListView_getColumnAlignment(ListView::Ptr* self, int index);
	C_ABI_METHOD void ABI_ListView_removeAllColumns(ListView::Ptr* self);
	C_ABI_GETTER int ABI_ListView_getColumnCount(ListView::Ptr* self);
	C_ABI_SETTER void ABI_ListView_setHeaderHeight(ListView::Ptr* self, float height);
	C_ABI_GETTER float ABI_ListView_getHeaderHeight(ListView::Ptr* self);
	C_ABI_GETTER float ABI_ListView_getCurrentHeaderHeight(ListView::Ptr* self);
	C_ABI_SETTER void ABI_ListView_setHeaderVisible(ListView::Ptr* self, int showHeader);
	C_ABI_TESTER bool ABI_ListView_headerVisible(ListView::Ptr* self);
	C_ABI_RAW int ABI_ListView_addItem(ListView::Ptr* self, char*(*f)(void));
	C_ABI_RAW void ABI_ListView_insertItem(ListView::Ptr* self, int index, char*(*f)(void));
	C_ABI_RAW bool ABI_ListView_changeItem(ListView::Ptr* self, int index, char*(*f)(void));
	C_ABI_RAW bool ABI_ListView_changeSubitem(ListView::Ptr* self, int index, int column, char* item);
	C_ABI_RAW bool ABI_ListView_removeItem(ListView::Ptr* self, int index);
	C_ABI_METHOD void ABI_ListView_removeAllItems(ListView::Ptr* self);
	C_ABI_SETTER void ABI_ListView_setSelectedItem(ListView::Ptr* self, int index);
	C_ABI_RAW void ABI_ListView_setSelectedItems(ListView::Ptr* self, int(*f)(void));
	C_ABI_METHOD void ABI_ListView_deselectItems(ListView::Ptr* self);
	C_ABI_GETTER int ABI_ListView_getSelectedItemIndex(ListView::Ptr* self);
	C_ABI_RAW void ABI_ListView_getSelectedItemIndices(ListView::Ptr* self, void(*f)(int));
	C_ABI_SETTER void ABI_ListView_setMultiSelect(ListView::Ptr* self, int multiSelect);
	C_ABI_TESTER bool ABI_ListView_multiSelect(ListView::Ptr* self);
	C_ABI_METHOD void ABI_ListView_setItemIcon(ListView::Ptr* self, int index, Texture* texture);
	C_ABI_GETTER Texture* ABI_ListView_getItemIcon(ListView::Ptr* self, int index);
	C_ABI_GETTER int ABI_ListView_getItemCount(ListView::Ptr* self);
	C_ABI_RAW void ABI_ListView_getItemRow(ListView::Ptr* self, int index, void(*f)(const char32_t*));
	C_ABI_GETTER const char32_t* ABI_ListView_getItemCell(ListView::Ptr* self, int rowIndex, int columnIndex);
	C_ABI_RAW void ABI_ListView_getItemRows(ListView::Ptr* self, void(*f)(const char32_t*, int row));
	C_ABI_SETTER void ABI_ListView_setItemHeight(ListView::Ptr* self, int itemHeight);
	C_ABI_GETTER int ABI_ListView_getItemHeight(ListView::Ptr* self);
	C_ABI_SETTER void ABI_ListView_setHeaderTextSize(ListView::Ptr* self, int textSize);
	C_ABI_GETTER int ABI_ListView_getHeaderTextSize(ListView::Ptr* self);
	C_ABI_SETTER void ABI_ListView_setSeparatorWidth(ListView::Ptr* self, int width);
	C_ABI_GETTER int ABI_ListView_getSeparatorWidth(ListView::Ptr* self);
	C_ABI_SETTER void ABI_ListView_setHeaderSeparatorHeight(ListView::Ptr* self, int height);
	C_ABI_GETTER int ABI_ListView_getHeaderSeparatorHeight(ListView::Ptr* self);
	C_ABI_SETTER void ABI_ListView_setGridLinesWidth(ListView::Ptr* self, int width);
	C_ABI_GETTER int ABI_ListView_getGridLinesWidth(ListView::Ptr* self);
	C_ABI_SETTER void ABI_ListView_setAutoScroll(ListView::Ptr* self, int autoScroll);
	C_ABI_TESTER bool ABI_ListView_autoScroll(ListView::Ptr* self);
	C_ABI_SETTER void ABI_ListView_setShowVerticalGridLines(ListView::Ptr* self, int showGridLines);
	C_ABI_TESTER bool ABI_ListView_showVerticalGridLines(ListView::Ptr* self);
	C_ABI_SETTER void ABI_ListView_setShowHorizontalGridLines(ListView::Ptr* self, int showGridLines);
	C_ABI_TESTER bool ABI_ListView_showHorizontalGridLines(ListView::Ptr* self);
	C_ABI_SETTER void ABI_ListView_setExpandLastColumn(ListView::Ptr* self, int expand);
	C_ABI_TESTER bool ABI_ListView_expandLastColumn(ListView::Ptr* self);
	C_ABI_SETTER void ABI_ListView_setVerticalScrollbarPolicy(ListView::Ptr* self, int policy);
	C_ABI_GETTER int ABI_ListView_getVerticalScrollbarPolicy(ListView::Ptr* self);
	C_ABI_SETTER void ABI_ListView_setHorizontalScrollbarPolicy(ListView::Ptr* self, int policy);
	C_ABI_GETTER int ABI_ListView_getHorizontalScrollbarPolicy(ListView::Ptr* self);
	C_ABI_SETTER void ABI_ListView_setVerticalScrollbarValue(ListView::Ptr* self, int value);
	C_ABI_GETTER int ABI_ListView_getVerticalScrollbarValue(ListView::Ptr* self);
	C_ABI_SETTER void ABI_ListView_setHorizontalScrollbarValue(ListView::Ptr* self, int value);
	C_ABI_GETTER int ABI_ListView_getHorizontalScrollbarValue(ListView::Ptr* self);
	C_ABI_SETTER void ABI_ListView_setFixedIconSize(ListView::Ptr* self, float width, float height);
	C_ABI_GETTER Vector2f* ABI_ListView_getFixedIconSize(ListView::Ptr* self);
	C_ABI_SETTER void ABI_ListView_setResizableColumns(ListView::Ptr* self, int resizable);
	C_ABI_TESTER bool ABI_ListView_resizableColumns(ListView::Ptr* self);
	C_ABI_SIGNAL SignalInt* ABI_ListView_onItemSelect(ListView::Ptr* self);
	C_ABI_SIGNAL SignalInt* ABI_ListView_onDoubleClick(ListView::Ptr* self);
	C_ABI_SIGNAL SignalInt* ABI_ListView_onRightClick(ListView::Ptr* self);
	C_ABI_SIGNAL SignalInt* ABI_ListView_onHeaderClick(ListView::Ptr* self);
	// ComboBox
	C_ABI_MAKE ComboBox::Ptr* ABI_ComboBox_make();
	C_ABI_SETTER void ABI_ComboBox_setItemsToDisplay(ComboBox::Ptr* self, int itemsToDisplay);
	C_ABI_GETTER int ABI_ComboBox_getItemsToDisplay(ComboBox::Ptr* self);
	C_ABI_METHOD void ABI_ComboBox_addItem(ComboBox::Ptr* self, char* name, char* id);
	C_ABI_RAW bool ABI_ComboBox_setSelectedItemById(ComboBox::Ptr* self, char* id);
	C_ABI_RAW bool ABI_ComboBox_setSelectedItemByIndex(ComboBox::Ptr* self, int index);
	C_ABI_METHOD void ABI_ComboBox_deselectItem(ComboBox::Ptr* self);
	C_ABI_RAW bool ABI_ComboBox_removeItemById(ComboBox::Ptr* self, char* id);
	C_ABI_RAW bool ABI_ComboBox_removeItemByIndex(ComboBox::Ptr* self, int index);
	C_ABI_METHOD void ABI_ComboBox_removeAllItems(ComboBox::Ptr* self);
	C_ABI_RAW char32_t* ABI_ComboBox_getItemById(ComboBox::Ptr* self, char* id);
	C_ABI_RAW char32_t* ABI_ComboBox_getSelectedItemId(ComboBox::Ptr* self);
	C_ABI_RAW bool ABI_ComboBox_changeItemById(ComboBox::Ptr* self, char* id, char* newValue);
	C_ABI_RAW bool ABI_ComboBox_changeItemByIndex(ComboBox::Ptr* self, int index, char* newValue);
	C_ABI_GETTER int ABI_ComboBox_getItemCount(ComboBox::Ptr* self);
	C_ABI_RAW void ABI_ComboBox_getItemIds(ComboBox::Ptr* self, void(*f)(char32_t*));
	C_ABI_SETTER void ABI_ComboBox_setMaximumItems(ComboBox::Ptr* self, int maximumItems);
	C_ABI_GETTER int ABI_ComboBox_getMaximumItems(ComboBox::Ptr* self);
	C_ABI_SETTER void ABI_ComboBox_setDefaultText(ComboBox::Ptr* self, char* defaultText);
	C_ABI_GETTER const char32_t* ABI_ComboBox_getDefaultText(ComboBox::Ptr* self);
	C_ABI_SETTER void ABI_ComboBox_setExpandDirection(ComboBox::Ptr* self, int expandDirection);
	C_ABI_GETTER int ABI_ComboBox_getExpandDirection(ComboBox::Ptr* self);
	C_ABI_RAW bool ABI_ComboBox_containsId(ComboBox::Ptr* self, char* id);
	C_ABI_SETTER void ABI_ComboBox_setChangeItemOnScroll(ComboBox::Ptr* self, int changeItemOnScroll);
	C_ABI_GETTER bool ABI_ComboBox_getChangeItemOnScroll(ComboBox::Ptr* self);
	C_ABI_SIGNAL SignalItem* ABI_ComboBox_onItemSelect(ComboBox::Ptr* self);
	// ColorPicker
	C_ABI_MAKE ColorPicker::Ptr* ABI_ColorPicker_new();
	C_ABI_SETTER void ABI_ColorPicker_setColor(ColorPicker::Ptr* self, Color* color);
	C_ABI_GETTER Color* ABI_ColorPicker_getColor(ColorPicker::Ptr* self);
	C_ABI_SIGNAL SignalColor* ABI_ColorPicker_onColorChange(ColorPicker::Ptr* self);
	C_ABI_SIGNAL SignalColor* ABI_ColorPicker_onOkPress(ColorPicker::Ptr* self);
	// FileDialog
	C_ABI_MAKE FileDialog::Ptr* ABI_FileDialog_new();
	C_ABI_RAW void ABI_FileDialog_getSelectedPaths(FileDialog::Ptr* self, void(*f)(char32_t*));
	C_ABI_SETTER void ABI_FileDialog_setPath(FileDialog::Ptr* self, char* path);
	C_ABI_GETTER const char32_t* ABI_FileDialog_getPath(FileDialog::Ptr* self);
	C_ABI_SETTER void ABI_FileDialog_setFilename(FileDialog::Ptr* self, char* filename);
	C_ABI_GETTER const char32_t* ABI_FileDialog_getFilename(FileDialog::Ptr* self);
	C_ABI_RAW void ABI_FileDialog_setFileTypeFilters(FileDialog::Ptr* self, int size, int(*f)(void), char*(*f1)(void), int defaultFilterIndex);
	C_ABI_RAW void ABI_FileDialog_getFileTypeFilters(FileDialog::Ptr* self, void(*f)(int, const char32_t*, const char32_t*));
	C_ABI_GETTER int ABI_FileDialog_getFileTypeFiltersIndex(FileDialog::Ptr* self);
	C_ABI_SETTER void ABI_FileDialog_setConfirmButtonText(FileDialog::Ptr* self, char* text);
	C_ABI_GETTER const char32_t* ABI_FileDialog_getConfirmButtonText(FileDialog::Ptr* self);
	C_ABI_SETTER void ABI_FileDialog_setCancelButtonText(FileDialog::Ptr* self, char* text);
	C_ABI_GETTER const char32_t* ABI_FileDialog_getCancelButtonText(FileDialog::Ptr* self);
	C_ABI_SETTER void ABI_FileDialog_setCreateFolderButtonText(FileDialog::Ptr* self, char* text);
	C_ABI_GETTER const char32_t* ABI_FileDialog_getCreateFolderButtonText(FileDialog::Ptr* self);
	C_ABI_SETTER void ABI_FileDialog_setAllowCreateFolder(FileDialog::Ptr* self, int allowCreateFolder);
	C_ABI_TESTER bool ABI_FileDialog_getAllowCreateFolder(FileDialog::Ptr* self);
	C_ABI_SETTER void ABI_FileDialog_setFilenameLabelText(FileDialog::Ptr* self, char* labelText);
	C_ABI_GETTER const char32_t* ABI_FileDialog_getFilenameLabelText(FileDialog::Ptr* self);
	C_ABI_SETTER void ABI_FileDialog_setListViewColumnCaptions(FileDialog::Ptr* self, char* nameColumnText, char* sizeColumnText, char* modifiedColumnText);
	C_ABI_RAW void ABI_FileDialog_getListViewColumnCaptions(FileDialog::Ptr* self, void(*f)(const char32_t*));
	C_ABI_SETTER void ABI_FileDialog_setFileMustExist(FileDialog::Ptr* self, int enforceExistence);
	C_ABI_TESTER bool ABI_FileDialog_getFileMustExist(FileDialog::Ptr* self);
	C_ABI_SETTER void ABI_FileDialog_setSelectingDirectory(FileDialog::Ptr* self, int selectDirectories);
	C_ABI_TESTER bool ABI_FileDialog_getSelectingDirectory(FileDialog::Ptr* self);
	C_ABI_SETTER void ABI_FileDialog_setMultiSelect(FileDialog::Ptr* self, int multiSelect);
	C_ABI_TESTER bool ABI_FileDialog_getMultiSelect(FileDialog::Ptr* self);
	// C_ABI_SETTER void ABI_FileDialog_setIconLoader(FileDialog::Ptr* self, std::shared_ptr< FileDialogIconLoader >* iconLoader);
	// C_ABI_GETTER std::shared_ptr< FileDialogIconLoader >* ABI_FileDialog_getIconLoader(FileDialog::Ptr* self);
	C_ABI_SIGNAL Signal* ABI_FileDialog_onFileSelect(FileDialog::Ptr* self);
	C_ABI_SIGNAL Signal* ABI_FileDialog_onCancel(FileDialog::Ptr* self);
	// MessageBox
	C_ABI_MAKE MessageBox::Ptr* ABI_MessageBox_new();
	C_ABI_SETTER void ABI_MessageBox_setText(MessageBox::Ptr* self, char* text);
	C_ABI_GETTER const char32_t* ABI_MessageBox_getText(MessageBox::Ptr* self);
	C_ABI_RAW void ABI_MessageBox_addButton(MessageBox::Ptr* self, char* button);
	C_ABI_RAW void ABI_MessageBox_changeButtons(MessageBox::Ptr* self, int size, char*(*f)(void));
	C_ABI_RAW void ABI_MessageBox_getButtons(MessageBox::Ptr* self, void(*f)(const char32_t*));
	C_ABI_RAW void ABI_MessageBox_setLabelAlignment(MessageBox::Ptr* self, int alignment);
	C_ABI_RAW int ABI_MessageBox_getLabelAlignment(MessageBox::Ptr* self);
	C_ABI_RAW void ABI_MessageBox_setButtonAlignment(MessageBox::Ptr* self, int alignment);
	C_ABI_RAW int ABI_MessageBox_getButtonAlignment(MessageBox::Ptr* self);
	C_ABI_SIGNAL SignalString* ABI_MessageBox_onButtonPress(MessageBox::Ptr* self);
	// Picture
	C_ABI_MAKE Picture::Ptr* ABI_Picture_new(Texture* texture, int transparent);
	C_ABI_SETTER void ABI_Picture_ignoreMouseEvents(Picture::Ptr* self, int ignore);
	C_ABI_TESTER bool ABI_Picture_isIgnoringMouseEvents(Picture::Ptr* self);
	C_ABI_SIGNAL SignalVector2f* ABI_Picture_onDoubleClick(Picture::Ptr* self);
	// MenuBar
	C_ABI_MAKE MenuBar::Ptr* ABI_MenuBar_new();
	C_ABI_METHOD void ABI_MenuBar_addMenu(MenuBar::Ptr* self, char* text);
	C_ABI_RAW int ABI_MenuBar_connectMenuItem(MenuBar::Ptr* self, int hierarchySize, char*(*hierarchy)(), void(*handler)());
	C_ABI_RAW bool ABI_MenuBar_addMenuItem(MenuBar::Ptr* self, int hierarchySize, char*(*hierarchy)());
	C_ABI_RAW bool ABI_MenuBar_changeMenuItem(MenuBar::Ptr* self, int hierarchySize, char*(*hierarchy)(), char* text);
	C_ABI_METHOD void ABI_MenuBar_removeAllMenus(MenuBar::Ptr* self);
	C_ABI_METHOD bool ABI_MenuBar_removeMenu(MenuBar::Ptr* self, char* menu);
	C_ABI_RAW bool ABI_MenuBar_removeMenuItem(MenuBar::Ptr* self, int hierarchySize, char*(*hierarchy)());
	C_ABI_RAW bool ABI_MenuBar_removeSubMenuItems(MenuBar::Ptr* self, int hierarchySize, char*(*hierarchy)());
	C_ABI_SETTER bool ABI_MenuBar_setMenuEnabled(MenuBar::Ptr* self, char* menu, int enabled);
	C_ABI_TESTER bool ABI_MenuBar_getMenuEnabled(MenuBar::Ptr* self, char* menu);
	C_ABI_RAW bool ABI_MenuBar_setMenuItemEnabled(MenuBar::Ptr* self, int hierarchySize, char*(*hierarchy)(), int enabled);
	C_ABI_RAW bool ABI_MenuBar_getMenuItemEnabled(MenuBar::Ptr* self, int hierarchySize, char*(*hierarchy)());
	C_ABI_SETTER void ABI_MenuBar_setMinimumSubMenuWidth(MenuBar::Ptr* self, float minimumWidth);
	C_ABI_GETTER float ABI_MenuBar_getMinimumSubMenuWidth(MenuBar::Ptr* self);
	C_ABI_SETTER void ABI_MenuBar_setInvertedMenuDirection(MenuBar::Ptr* self, int invertDirection);
	C_ABI_TESTER bool ABI_MenuBar_getInvertedMenuDirection(MenuBar::Ptr* self);
	C_ABI_RAW void ABI_MenuBar_getMenus(MenuBar::Ptr* self, void(*m)(const char32_t*, int), void(*up)());
	C_ABI_METHOD void ABI_MenuBar_closeMenu(MenuBar::Ptr* self);
	C_ABI_SIGNAL SignalItemHierarchy* ABI_MenuBar_onMenuItemClick(MenuBar::Ptr* self);
	// PanelListBox
	C_ABI_MAKE PanelListBox::Ptr* ABI_PanelListBox_new();
	C_ABI_METHOD Panel::Ptr* ABI_PanelListBox_addItem(PanelListBox::Ptr* self, char* id, int index);
	C_ABI_GETTER Panel::Ptr* ABI_PanelListBox_getPanelTemplate(PanelListBox::Ptr* self);
	C_ABI_GETTER float ABI_PanelListBox_getItemsWidth(PanelListBox::Ptr* self);
	C_ABI_SETTER void ABI_PanelListBox_setItemsHeight(PanelListBox::Ptr* self, float height);
	C_ABI_GETTER float ABI_PanelListBox_getItemsHeight(PanelListBox::Ptr* self);
	C_ABI_SETTER bool ABI_PanelListBox_setSelectedItem(PanelListBox::Ptr* self, Panel::Ptr* panel);
	C_ABI_SETTER bool ABI_PanelListBox_setSelectedItemById(PanelListBox::Ptr* self, char* id);
	C_ABI_SETTER bool ABI_PanelListBox_setSelectedItemByIndex(PanelListBox::Ptr* self, int index);
	C_ABI_METHOD void ABI_PanelListBox_deselectItem(PanelListBox::Ptr* self);
	C_ABI_METHOD bool ABI_PanelListBox_removeItem(PanelListBox::Ptr* self, Panel::Ptr* panel);
	C_ABI_METHOD bool ABI_PanelListBox_removeItemById(PanelListBox::Ptr* self, char* id);
	C_ABI_METHOD bool ABI_PanelListBox_removeItemByIndex(PanelListBox::Ptr* self, int index);
	C_ABI_METHOD void ABI_PanelLIstBox_removeAllItems(PanelListBox::Ptr* self);
	C_ABI_GETTER Panel::Ptr* ABI_PanelListBox_getItemById(PanelListBox::Ptr* self, char* id);
	C_ABI_GETTER Panel::Ptr* ABI_PanelListBox_getItemByIndex(PanelListBox::Ptr* self, int index);
	C_ABI_GETTER int ABI_PanelListBox_getIndexById(PanelListBox::Ptr* self, char* id);
	C_ABI_GETTER int ABI_PanelListBox_getIndexByItem(PanelListBox::Ptr* self, Panel::Ptr* panel);
	C_ABI_GETTER const char32_t* ABI_PanelListBox_getIdByIndex(PanelListBox::Ptr* self, int index);
	C_ABI_GETTER Panel::Ptr* ABI_PanelListBox_getSelectedItem(PanelListBox::Ptr* self);
	C_ABI_GETTER const char32_t* ABI_PanelListBox_getSelectedItemId(PanelListBox::Ptr* self);
	C_ABI_GETTER int ABI_PanelListBox_getSelectedItemIndex(PanelListBox::Ptr* self);
	C_ABI_GETTER int ABI_PanelListBox_getItemCount(PanelListBox::Ptr* self);
	C_ABI_RAW void ABI_PanelListBox_getItems(PanelListBox::Ptr* self, void(*f)(Panel::Ptr*));
	C_ABI_RAW void ABI_PanelListBox_getItemIds(PanelListBox::Ptr* self, void(*f)(const char32_t*));
	C_ABI_SETTER void ABI_PanelListBox_setMaximumItems(PanelListBox::Ptr* self, int maximumItems);
	C_ABI_GETTER int ABI_PanelListBox_getMaximumItems(PanelListBox::Ptr* self);
	C_ABI_TESTER bool ABI_PanelListBox_contains(PanelListBox::Ptr* self, Panel::Ptr* panel);
	C_ABI_TESTER bool ABI_PanelListBox_containsId(PanelListBox::Ptr* self, char* id);
	C_ABI_SIGNAL SignalPanelListBoxItem* ABI_PanelListBox_onItemSelect(PanelListBox::Ptr* self);
	// ProgressBar
	C_ABI_MAKE ProgressBar::Ptr* ABI_ProgressBar_new();
	C_ABI_SETTER void ABI_ProgressBar_setMinimum(ProgressBar::Ptr* self, int minimum);
	C_ABI_GETTER int ABI_ProgressBar_getMinimum(ProgressBar::Ptr* self);
	C_ABI_SETTER void ABI_ProgressBar_setMaximum(ProgressBar::Ptr* self, int maximum);
	C_ABI_GETTER int ABI_ProgressBar_getMaximum(ProgressBar::Ptr* self);
	C_ABI_SETTER void ABI_ProgressBar_setValue(ProgressBar::Ptr* self, int value);
	C_ABI_GETTER int ABI_ProgressBar_getValue(ProgressBar::Ptr* self);
	C_ABI_METHOD int ABI_ProgressBar_incrementValue(ProgressBar::Ptr* self);
	C_ABI_SETTER void ABI_ProgressBar_setText(ProgressBar::Ptr* self, char* text);
	C_ABI_GETTER const char32_t* ABI_ProgressBar_getText(ProgressBar::Ptr* self);
	C_ABI_RAW void ABI_ProgressBar_setFillDirection(ProgressBar::Ptr* self, int direction);
	C_ABI_RAW int ABI_ProgressBar_getFillDirection(ProgressBar::Ptr* self);
	C_ABI_SIGNAL SignalUInt* ABI_ProgressBar_onValueChange(ProgressBar::Ptr* self);
	C_ABI_SIGNAL Signal* ABI_ProgressBar_onFull(ProgressBar::Ptr* self);
	// RangeSlider
	C_ABI_MAKE RangeSlider::Ptr* ABI_RangeSlider_new();
	C_ABI_SETTER void ABI_RangeSlider_setMinimum(RangeSlider::Ptr* self, float minimum);
	C_ABI_GETTER float ABI_RangeSlider_getMinimum(RangeSlider::Ptr* self);
	C_ABI_SETTER void ABI_RangeSlider_setMaximum(RangeSlider::Ptr* self, float maximum);
	C_ABI_GETTER float ABI_RangeSlider_getMaximum(RangeSlider::Ptr* self);
	C_ABI_SETTER void ABI_RangeSlider_setSelectionStart(RangeSlider::Ptr* self, float value);
	C_ABI_GETTER float ABI_RangeSlider_getSelectionStart(RangeSlider::Ptr* self);
	C_ABI_SETTER void ABI_RangeSlider_setSelectionEnd(RangeSlider::Ptr* self, float value);
	C_ABI_GETTER float ABI_RangeSlider_getSelectionEnd(RangeSlider::Ptr* self);
	C_ABI_SETTER void ABI_RangeSlider_setStep(RangeSlider::Ptr* self, float step);
	C_ABI_GETTER float ABI_RangeSlider_getStep(RangeSlider::Ptr* self);
	C_ABI_SIGNAL SignalRange* ABI_RangeSlider_onRangeChange(RangeSlider::Ptr* self);
	// RichTextLabel
	C_ABI_MAKE RichTextLabel::Ptr* ABI_RichTextLabel_new();
	// SeparatorLine
	C_ABI_MAKE SeparatorLine::Ptr* ABI_SeparatorLine_new();
	// Slider
	C_ABI_MAKE Slider::Ptr* ABI_Slider_new();
	C_ABI_SETTER void ABI_Slider_setMinimum(Slider::Ptr* self, float minimum);
	C_ABI_GETTER float ABI_Slider_getMinimum(Slider::Ptr* self);
	C_ABI_SETTER void ABI_Slider_setMaximum(Slider::Ptr* self, float maximum);
	C_ABI_GETTER float ABI_Slider_getMaximum(Slider::Ptr* self);
	C_ABI_SETTER void ABI_Slider_setValue(Slider::Ptr* self, float value);
	C_ABI_GETTER float ABI_Slider_getValue(Slider::Ptr* self);
	C_ABI_SETTER void ABI_Slider_setStep(Slider::Ptr* self, float step);
	C_ABI_GETTER float ABI_Slider_getStep(Slider::Ptr* self);
	C_ABI_SETTER void ABI_Slider_setVerticalScroll(Slider::Ptr* self, int vertical);
	C_ABI_TESTER bool ABI_Slider_getVerticalScroll(Slider::Ptr* self);
	C_ABI_SETTER void ABI_Slider_setInvertedDirection(Slider::Ptr* self, int invertedDirection);
	C_ABI_TESTER bool ABI_Slider_getInvertedDirection(Slider::Ptr* self);
	C_ABI_SETTER void ABI_Slider_setChangeValueOnScroll(Slider::Ptr* self, int changeValueOnScroll);
	C_ABI_TESTER bool ABI_Slider_getChangeValueOnScroll(Slider::Ptr* self);
	C_ABI_SIGNAL SignalFloat* ABI_Slider_onValueChange(Slider::Ptr* self);
	// SpinButton
	C_ABI_MAKE SpinButton::Ptr* ABI_SpinButton_new();
	C_ABI_SETTER void ABI_SpinButton_setMinimum(SpinButton::Ptr* self, float minimum);
	C_ABI_GETTER float ABI_SpinButton_getMinimum(SpinButton::Ptr* self);
	C_ABI_SETTER void ABI_SpinButton_setMaximum(SpinButton::Ptr* self, float maximum);
	C_ABI_GETTER float ABI_SpinButton_getMaximum(SpinButton::Ptr* self);
	C_ABI_SETTER void ABI_SpinButton_setValue(SpinButton::Ptr* self, float value);
	C_ABI_GETTER float ABI_SpinButton_getValue(SpinButton::Ptr* self);
	C_ABI_SETTER void ABI_SpinButton_setStep(SpinButton::Ptr* self, float step);
	C_ABI_GETTER float ABI_SpinButton_getStep(SpinButton::Ptr* self);
	C_ABI_SETTER void ABI_SpinButton_setVerticalScroll(SpinButton::Ptr* self, int vertical);
	C_ABI_TESTER bool ABI_SpinButton_getVerticalScroll(SpinButton::Ptr* self);
	C_ABI_SIGNAL SignalFloat* ABI_SpinButton_onValueChange(SpinButton::Ptr* self);
	// SubwidgetContainer
	C_ABI_GETTER Container::Ptr* ABI_SubwidgetContainer_getContainer(SubwidgetContainer::Ptr* self);
	// SpinControl
	C_ABI_MAKE SpinControl::Ptr* ABI_SpinControl_new();
	C_ABI_SETTER void ABI_SpinControl_setMinimum(SpinControl::Ptr* self, float minimum);
	C_ABI_GETTER float ABI_SpinControl_getMinimum(SpinControl::Ptr* self);
	C_ABI_SETTER void ABI_SpinControl_setMaximum(SpinControl::Ptr* self, float maximum);
	C_ABI_GETTER float ABI_SpinControl_getMaximum(SpinControl::Ptr* self);
	C_ABI_SETTER void ABI_SpinControl_setValue(SpinControl::Ptr* self, float value);
	C_ABI_GETTER float ABI_SpinControl_getValue(SpinControl::Ptr* self);
	C_ABI_SETTER void ABI_SpinControl_setStep(SpinControl::Ptr* self, float step);
	C_ABI_GETTER float ABI_SpinControl_getStep(SpinControl::Ptr* self);
	C_ABI_SETTER void ABI_SpinControl_setDecimalPlaces(SpinControl::Ptr* self, int decimalPlaces);
	C_ABI_GETTER int ABI_SpinControl_getDecimalPlaces(SpinControl::Ptr* self);
	C_ABI_SETTER void ABI_SpinControl_setUseWideArrows(SpinControl::Ptr* self, int useWideArrows);
	C_ABI_GETTER bool ABI_SpinControl_getUseWideArrows(SpinControl::Ptr* self);
	C_ABI_SIGNAL SignalFloat* ABI_SpinControl_onValueChange(SpinControl::Ptr* self);
	// Tabs
	C_ABI_MAKE Tabs::Ptr* ABI_Tabs_new();
	C_ABI_SETTER void ABI_Tabs_setAutoSize(Tabs::Ptr* self, int autoSize);
	C_ABI_TESTER bool ABI_Tabs_getAutoSize(Tabs::Ptr* self);
	C_ABI_METHOD int ABI_Tabs_add(Tabs::Ptr* self, char* text, int select);
	C_ABI_METHOD void ABI_Tabs_insert(Tabs::Ptr* self, int index, char* text, int select);
	C_ABI_GETTER const char32_t* ABI_Tabs_getText(Tabs::Ptr* self, int index);
	C_ABI_METHOD bool ABI_Tabs_changeText(Tabs::Ptr* self, int index, char* text);
	C_ABI_METHOD bool ABI_Tabs_select(Tabs::Ptr* self, char* text);
	C_ABI_METHOD bool ABI_Tabs_selectByIndex(Tabs::Ptr* self, int index);
	C_ABI_METHOD void ABI_Tabs_deselect(Tabs::Ptr* self);
	C_ABI_METHOD bool ABI_Tabs_remove(Tabs::Ptr* self, char* text);
	C_ABI_METHOD bool ABI_Tabs_removeByIndex(Tabs::Ptr* self, int index);
	C_ABI_METHOD void ABI_Tabs_removeAll(Tabs::Ptr* self);
	C_ABI_GETTER const char32_t* ABI_Tabs_getSelected(Tabs::Ptr* self);
	C_ABI_GETTER int ABI_Tabs_getSelectedIndex(Tabs::Ptr* self);
	C_ABI_SETTER void ABI_Tabs_setTabVisible(Tabs::Ptr* self, int index, int visible);
	C_ABI_GETTER bool ABI_Tabs_getTabVisible(Tabs::Ptr* self, int index);
	C_ABI_SETTER void ABI_Tabs_setTabEnabled(Tabs::Ptr* self, int index, int enabled);
	C_ABI_GETTER bool ABI_Tabs_getTabEnabled(Tabs::Ptr* self, int index);
	C_ABI_SETTER void ABI_Tabs_setTabHeight(Tabs::Ptr* self, float height);
	C_ABI_SETTER void ABI_Tabs_setMaximumTabWidth(Tabs::Ptr* self, float maximumWidth);
	C_ABI_GETTER float ABI_Tabs_getMaximumTabWidth(Tabs::Ptr* self);
	C_ABI_SETTER void ABI_Tabs_setMinimumTabWidth(Tabs::Ptr* self, float minimumWidth);
	C_ABI_GETTER float ABI_Tabs_getMinimumTabWidth(Tabs::Ptr* self);
	C_ABI_GETTER int ABI_Tabs_getTabsCount(Tabs::Ptr* self);
	C_ABI_SIGNAL SignalString* ABI_Tabs_onTabSelect(Tabs::Ptr* self);
	// TabContainer
	C_ABI_MAKE TabContainer::Ptr* ABI_TabContainer_new();
	C_ABI_SETTER void ABI_TabContainer_setTabsHeight(TabContainer::Ptr* self, char* height);
	C_ABI_METHOD Panel::Ptr* ABI_TabContainer_addTab(TabContainer::Ptr* self, char* name, int select);
	C_ABI_METHOD Panel::Ptr* ABI_TabContainer_insertTab(TabContainer::Ptr* self, int index, char* name, int select);
	C_ABI_METHOD bool ABI_TabContainer_removeTab(TabContainer::Ptr* self, char* text);
	C_ABI_METHOD bool ABI_TabContainer_removeTabByIndex(TabContainer::Ptr* self, int index);
	C_ABI_METHOD void ABI_TabContainer_select(TabContainer::Ptr* self, int index);
	C_ABI_GETTER int ABI_TabContainer_getPanelCount(TabContainer::Ptr* self);
	C_ABI_GETTER int ABI_TabContainer_getIndex(TabContainer::Ptr* self, Panel::Ptr* ptr);
	C_ABI_GETTER Panel::Ptr* ABI_TabContainer_getSelected(TabContainer::Ptr* self);
	C_ABI_GETTER int ABI_TabContainer_getSelectedIndex(TabContainer::Ptr* self);
	C_ABI_GETTER Panel::Ptr* ABI_TabContainer_getPanel(TabContainer::Ptr* self, int index);
	C_ABI_GETTER Tabs::Ptr* ABI_TabContainer_getTabs(TabContainer::Ptr* self);
	C_ABI_GETTER const char32_t* ABI_TabContainer_getTabText(TabContainer::Ptr* self, int index);
	C_ABI_METHOD bool ABI_TabContainer_changeTabText(TabContainer::Ptr* self, int index, char* text);
	C_ABI_RAW void ABI_TabContainer_setTabAlignment(TabContainer::Ptr* self, int align);
	C_ABI_RAW int ABI_TabContainer_getTabAlignment(TabContainer::Ptr* self);
	C_ABI_SETTER void ABI_TabContainer_setTabFixedSize(TabContainer::Ptr* self, float fixedSize);
	C_ABI_GETTER float ABI_TabContainer_getTabFixedSize(TabContainer::Ptr* self);
	C_ABI_SIGNAL SignalInt* ABI_TabContainer_onSelectionChange(TabContainer::Ptr* self);
	C_ABI_SIGNAL SignalTypedIntBoolPtr* ABI_TabContainer_onSelectionChanging(TabContainer::Ptr* self);
	// TextArea
	C_ABI_MAKE TextArea::Ptr* ABI_TextArea_new();
	C_ABI_SETTER void ABI_TextArea_setText(TextArea::Ptr* self, char* text);
	C_ABI_METHOD void ABI_TextArea_addText(TextArea::Ptr* self, char* text);
	C_ABI_GETTER const char32_t* ABI_TextArea_getText(TextArea::Ptr* self);
	C_ABI_SETTER void ABI_TextArea_setDefaultText(TextArea::Ptr* self, char* text);
	C_ABI_GETTER const char32_t* ABI_TextArea_getDefaultText(TextArea::Ptr* self);
	C_ABI_SETTER void ABI_TextArea_setSelectedText(TextArea::Ptr* self, int selectionStartIndex, int selectionEndIndex);
	C_ABI_GETTER const char32_t* ABI_TextArea_getSelectedText(TextArea::Ptr* self);
	C_ABI_GETTER int ABI_TextArea_getSelectionStart(TextArea::Ptr* self);
	C_ABI_GETTER int ABI_TextArea_getSelectionEnd(TextArea::Ptr* self);
	C_ABI_SETTER void ABI_TextArea_setMaximumCharacters(TextArea::Ptr* self, int maxChars);
	C_ABI_GETTER int ABI_TextArea_getMaximumCharacters(TextArea::Ptr* self);
	C_ABI_SETTER void ABI_TextArea_setTabString(TextArea::Ptr* self, char* tabText);
	C_ABI_GETTER const char32_t* ABI_TextArea_getTabString(TextArea::Ptr* self);
	C_ABI_SETTER void ABI_TextArea_setCaretPosition(TextArea::Ptr* self, int charactersBeforeCaret);
	C_ABI_GETTER int ABI_TextArea_getCaretPosition(TextArea::Ptr* self);
	C_ABI_GETTER int ABI_TextArea_getCaretLine(TextArea::Ptr* self);
	C_ABI_GETTER int ABI_TextArea_getCaretColumn(TextArea::Ptr* self);
	C_ABI_SETTER void ABI_TextArea_setReadOnly(TextArea::Ptr* self, int readOnly);
	C_ABI_TESTER bool ABI_TextArea_isReadOnly(TextArea::Ptr* self);
	C_ABI_GETTER int ABI_TextArea_getLinesCount(TextArea::Ptr* self);
	C_ABI_SETTER void ABI_TextArea_enableMonospacedFontOptimization(TextArea::Ptr* self, int enable);
	C_ABI_SETTER void ABI_TextArea_setVerticalScrollbarPolicy(TextArea::Ptr* self, int policy);
	C_ABI_GETTER int ABI_TextArea_getVerticalScrollbarPolicy(TextArea::Ptr* self);
	C_ABI_SETTER void ABI_TextArea_setHorizontalScrollbarPolicy(TextArea::Ptr* self, int policy);
	C_ABI_GETTER int ABI_TextArea_getHorizontalScrollbarPolicy(TextArea::Ptr* self);
	C_ABI_SETTER void ABI_TextArea_setVerticalScrollbarValue(TextArea::Ptr* self, int value);
	C_ABI_GETTER int ABI_TextArea_getVerticalScrollbarValue(TextArea::Ptr* self);
	C_ABI_SETTER void ABI_TextArea_setHorizontalScrollbarValue(TextArea::Ptr* self, int value);
	C_ABI_GETTER int ABI_TextArea_getHorizontalScrollbarValue(TextArea::Ptr* self);
	C_ABI_SIGNAL SignalString* ABI_TextArea_onTextChange(TextArea::Ptr* self);
	C_ABI_SIGNAL Signal* ABI_TextArea_onSelectionChange(TextArea::Ptr* self);
	C_ABI_SIGNAL Signal* ABI_TextArea_onCaretPositionChange(TextArea::Ptr* self);
}
#endif //CABI_HPP