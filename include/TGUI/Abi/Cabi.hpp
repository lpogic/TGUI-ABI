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
	C_ABI_RAW int ABI_Signal_connect(Signal* signal, void(*f)());
	C_ABI_RAW bool ABI_Signal_disconnect(Signal* signal, int f);
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
	// Widget
	C_ABI_FREE void ABI_Widget_free(std::shared_ptr<Widget>* pointer);
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
	C_ABI_SIGNAL Signal* ABI_Widget_onPositionChange(Widget::Ptr* self);
	C_ABI_SIGNAL Signal* ABI_Widget_onSizeChange(Widget::Ptr* self);
	C_ABI_SIGNAL Signal* ABI_Widget_onFocus(Widget::Ptr* self);
	C_ABI_SIGNAL Signal* ABI_Widget_onUnfocus(Widget::Ptr* self);
	C_ABI_SIGNAL Signal* ABI_Widget_onMouseEnter(Widget::Ptr* self);
	C_ABI_SIGNAL Signal* ABI_Widget_onMouseLeave(Widget::Ptr* self);
	C_ABI_SIGNAL Signal* ABI_Widget_onShowEffectFinish(Widget::Ptr* self);
	C_ABI_SIGNAL Signal* ABI_Widget_onAnimationFinish(Widget::Ptr* self);
	// ClickableWidget
	C_ABI_SIGNAL Signal* ABI_ClickableWidget_onMousePress(ClickableWidget::Ptr* self);
	C_ABI_SIGNAL Signal* ABI_ClickableWidget_onMouseRelease(ClickableWidget::Ptr* self);
	C_ABI_SIGNAL Signal* ABI_ClickableWidget_onClick(ClickableWidget::Ptr* self);
	C_ABI_SIGNAL Signal* ABI_ClickableWidget_onRightMousePress(ClickableWidget::Ptr* self);
	C_ABI_SIGNAL Signal* ABI_ClickableWidget_onRightMouseRelease(ClickableWidget::Ptr* self);
	C_ABI_SIGNAL Signal* ABI_ClickableWidget_onRightClick(ClickableWidget::Ptr* self);
	// ButtonBase
	C_ABI_RAW void ABI_ButtonBase_setTextPosition(ButtonBase::Ptr* self, const char* position, const char* origin);
	// Button
	C_ABI_MAKE Button::Ptr* ABI_Button_new();
	C_ABI_SETTER void ABI_Button_setText(Button::Ptr* self, const char* text);
	C_ABI_GETTER const char32_t* ABI_Button_getText(Button::Ptr* self);
	C_ABI_SIGNAL Signal* ABI_Button_onPress(Button::Ptr* self);
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
	C_ABI_SIGNAL Signal* ABI_EditBox_onTextChange(EditBox::Ptr* self);
	C_ABI_SIGNAL Signal* ABI_EditBox_onReturnKeyPress(EditBox::Ptr* self);
	C_ABI_SIGNAL Signal* ABI_EditBox_onReturnOrUnfocus(EditBox::Ptr* self);
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
	C_ABI_METHOD Signal* ABI_RadioButton_onCheck(RadioButton::Ptr* self);
	C_ABI_METHOD Signal* ABI_RadioButton_onUncheck(RadioButton::Ptr* self);
	C_ABI_METHOD Signal* ABI_RadioButton_onChange(RadioButton::Ptr* self);
	// CheckBox
	C_ABI_MAKE CheckBox::Ptr* ABI_CheckBox_new();
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
	C_ABI_METHOD Signal* ABI_ChildWindow_onMousePress(ChildWindow::Ptr* self);
	C_ABI_METHOD Signal* ABI_ChildWindow_onClose(ChildWindow::Ptr* self);
	C_ABI_METHOD Signal* ABI_ChildWindow_onMinimize(ChildWindow::Ptr* self);
	C_ABI_METHOD Signal* ABI_ChildWindow_onMaximize(ChildWindow::Ptr* self);
	C_ABI_METHOD Signal* ABI_ChildWindow_onEscapeKeyPress(ChildWindow::Ptr* self);

    /// The window is about to be closed, unless the "abort" parameter is set to true.
    /// @code
    /// window->onClosing([](bool* abort) { *abort = true; });
    /// @endcode
//    /*SignalTyped<bool*> onClosing = { "Closing" };*/
	// Group
	C_ABI_MAKE Group::Ptr* ABI_Group_new();
	// ColorPicker
	C_ABI_MAKE ColorPicker::Ptr* ABI_ColorPicker_new();
	C_ABI_SETTER void ABI_ColorPicker_setColor(ColorPicker::Ptr* self, Color* color);
	C_ABI_GETTER Color* ABI_ColorPicker_getColor(ColorPicker::Ptr* self);
	C_ABI_SIGNAL Signal* ABI_ColorPicker_onColorChange(ColorPicker::Ptr* self);
	C_ABI_SIGNAL Signal* ABI_ColorPicker_onOkPress(ColorPicker::Ptr* self);
}

#endif //CABI_HPP