#ifndef CABI_HPP
#define CABI_HPP

#ifdef TGUI_SYSTEM_WINDOWS
    #define C_ABI extern "C"  __declspec(dllexport)
		#include <windows.h>
		#include <winuser.h>
#endif

#ifdef TGUI_SYSTEM_LINUX
    #define C_ABI extern "C" __attribute__((visibility("default")))
#endif

#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include <TGUI/CustomWidgetForBindings.hpp>


namespace tgui
{
	// Util
	C_ABI void ABI_STATIC_Util_deleteVector2f(Vector2f* vector);
	C_ABI void ABI_STATIC_Util_deleteVector2i(Vector2i* vector);
	C_ABI void ABI_STATIC_Util_deleteUIntRect(UIntRect* rect);
	// Color
	C_ABI Color* ABI_Color_new(int r, int g, int b, int a);
	C_ABI void ABI_STATIC_Color_delete(Color* color);
	C_ABI int ABI_Color_get_red(Color* self);
	C_ABI int ABI_Color_get_green(Color* self);
	C_ABI int ABI_Color_get_blue(Color* self);
	C_ABI int ABI_Color_get_alpha(Color* self);
	C_ABI Color* ABI_Color_applyOpacity(Color* self, float fade);
	// Outline
	C_ABI Outline* ABI_Outline_new(char* left, char* right, char* top, char* bottom);
	C_ABI void ABI_STATIC_Outline_delete(Outline* outline);
	C_ABI float ABI_Outline_getLeft(Outline* self);
	C_ABI float ABI_Outline_getRight(Outline* self);
	C_ABI float ABI_Outline_getTop(Outline* self);
	C_ABI float ABI_Outline_getBottom(Outline* self);
	// Signal
	C_ABI int ABI_Signal_connect(Signal* self, void(*f)());
	C_ABI bool ABI_Signal_disconnect(Signal* self, int f);
	C_ABI void ABI_Signal_setEnabled(Signal* self, int enabled);
	C_ABI bool ABI_Signal_isEnabled(Signal* self);
	// SignalString
	C_ABI int ABI_SignalString_connect(SignalString* self, void(*f)(const char32_t*));
	// SignalBool
	C_ABI int ABI_SignalBool_connect(SignalBool* self, void(*f)(int));
	// SignalInt
	C_ABI int ABI_SignalInt_connect(SignalInt* self, void(*f)(int));
	// SignalUInt
	C_ABI int ABI_SignalUInt_connect(SignalUInt* self, void(*f)(unsigned int));
	// SignalFloat
	C_ABI int ABI_SignalFloat_connect(SignalFloat* self, void(*f)(float));
	// SignalRange
	C_ABI int ABI_SignalRange_connect(SignalRange* self, void(*f)(float, float));
	// SignalPointer
	C_ABI int ABI_SignalPointer_connect(SignalTyped<void*>* self, void(*f)(void*));
	// SignalColor
	C_ABI int ABI_SignalColor_connect(SignalColor* self, void(*f)(void*));
	// SignalVector2f
	C_ABI int ABI_SignalVector2f_connect(SignalVector2f* self, void(*f)(void*));
	// SignalShowEffect
	C_ABI int ABI_SignalShowEffect_connect(SignalShowEffect* self, void(*f)(int, int));
	// SignalAnimationType
	C_ABI int ABI_SignalAnimationType_connect(SignalAnimationType* self, void(*f)(int));
	// SignalItem
	C_ABI int ABI_SignalItem_connect(SignalItem* self, void(*f)(const char32_t*, const char32_t*));
	// SignalItemHierarchy
	C_ABI int ABI_SignalItemHierarchy_connect(SignalItemHierarchy* self, void(*f)(void*));
	C_ABI void ABI_STATIC_SignalItemHierarchy_fetchPath(std::vector< String >* load, void(*f)(const char32_t*));
	// SignalTypedIntBoolPtr
	typedef SignalTyped2<int, bool*> SignalTypedIntBoolPtr;
	C_ABI int ABI_SignalTypedIntBoolPtr_connect(SignalTypedIntBoolPtr* self, void(*f)(int, bool*));
	// SignalTypedSizeT
	typedef SignalTyped<std::size_t> SignalTypedSizeT;
	C_ABI int ABI_SignalTypedSizeT_connect(SignalTypedSizeT* self, void(*f)(int));
	// SignalPanelListBoxItem
	C_ABI int ABI_SignalPanelListBoxItem_connect(SignalPanelListBoxItem* self, void(*f)(const char32_t*));
	// Window
	C_ABI sf::RenderWindow* ABI_Window_new(int width, int height, int style);
	C_ABI void ABI_STATIC_Window_delete(sf::RenderWindow* self);
	C_ABI void ABI_Window_close(sf::WindowBase* self);
	C_ABI bool ABI_Window_isOpen(sf::WindowBase* self);
	C_ABI void ABI_Window_setTitle(sf::WindowBase* self, char* title);
	C_ABI void ABI_Window_setSize(sf::WindowBase* self, int width, int height);
	C_ABI Vector2i* ABI_Window_getSize(sf::WindowBase* self);
	C_ABI void ABI_Window_setPosition(sf::WindowBase* self, int x, int y);
	C_ABI Vector2i* ABI_Window_getPosition(sf::WindowBase* self);
	C_ABI void ABI_Window_requestFocus(sf::WindowBase* self);
	C_ABI bool ABI_Window_hasFocus(sf::WindowBase* self);
	// BackendGui
	C_ABI void ABI_BackendGui_setTextSize(BackendGui* self, int textSize);
	C_ABI int ABI_BackendGui_getTextSize(BackendGui* self);
	C_ABI void ABI_BackendGui_setAbsoluteView(BackendGui* self, int x, int y, int w, int h);
	C_ABI void ABI_BackendGui_setRelativeView(BackendGui* self, float x, float y, float w, float h);
	C_ABI void ABI_BackendGui_getView(BackendGui* self, void(*f)(float, float, float, float));
	C_ABI void ABI_BackendGui_setAbsoluteViewport(BackendGui* self, int x, int y, int w, int h);
	C_ABI void ABI_BackendGui_setRelativeViewport(BackendGui* self, float x, float y, float w, float h);
	C_ABI void ABI_BackendGui_getViewport(BackendGui* self, void(*f)(float, float, float, float));
	C_ABI void ABI_BackendGui_setTabKeyUsageEnabled(BackendGui* self, int enabled);
	C_ABI bool ABI_BackendGui_isTabKeyUsageEnabled(BackendGui* self);
	C_ABI void ABI_BackendGui_setFont(BackendGui* self, Font* font);
	C_ABI Font* ABI_BackendGui_getFont(BackendGui* self);
	C_ABI void ABI_BackendGui_unfocusAllWidgets(BackendGui* self);
	C_ABI void ABI_BackendGui_setOpacity(BackendGui* self, float opacity);
	C_ABI float ABI_BackendGui_getOpacity(BackendGui* self);
	C_ABI void ABI_BackendGui_setOverrideMouseCursor(BackendGui* self, int mouseCursor);
	C_ABI void ABI_BackendGui_restoreOverrideMouseCursor(BackendGui* self);
	C_ABI void ABI_BackendGui_mapPixelToCoords(BackendGui* self, int x, int y, void(*f)(float, float));
	C_ABI void ABI_BackendGui_mapCoordsToPixel(BackendGui* self, float x, float y, void(*f)(float, float));
	C_ABI void ABI_BackendGui_setKeyboardNavigationEnabled(BackendGui* self, int enabled);
	C_ABI bool ABI_BackendGui_isKeyboardNavigationEnabled(BackendGui* self);
	C_ABI Signal* ABI_BackendGui_onViewChange(BackendGui* self);
	C_ABI Signal* ABI_BackendGui_onWindowFocus(BackendGui* self);
	C_ABI Signal* ABI_BackendGui_onWindowUnfocus(BackendGui* self);
	// Font
	C_ABI Font* ABI_Font_new(char * id);
	C_ABI void ABI_STATIC_Font_delete(Font* font);
	C_ABI Font* ABI_STATIC_Font_getGlobalFont();
	// Gui
	C_ABI Gui* ABI_Gui_new(sf::RenderWindow* window);
	C_ABI void ABI_STATIC_Gui_delete(Gui* self);
	C_ABI int ABI_Gui_isActive(Gui* self);
	C_ABI void ABI_Gui_pollEvents(Gui* self);
	C_ABI void ABI_Gui_draw(Gui* self);
	C_ABI void ABI_Gui_add(Gui* self, Widget::Ptr* widget, const char* name);
	C_ABI void ABI_Gui_remove(Gui* self, Widget::Ptr* widget);
	C_ABI void ABI_Gui_removeAll(Gui* self);
	C_ABI void ABI_Gui_mainLoop(Gui* self);
	C_ABI Widget::Ptr* ABI_Gui_getWidget(Gui* self, const char* name);
	C_ABI void ABI_Gui_setClearColor(Gui* self, Color* color);
	C_ABI void ABI_Gui_setClipboard(Gui* self, char* text);
	C_ABI const char32_t* ABI_Gui_getClipboard(Gui* self);
	C_ABI Vector2i* ABI_Gui_getScreenSize(Gui* self);
	// Theme
	C_ABI void ABI_STATIC_Theme_setDefault(char* theme);
	C_ABI std::shared_ptr<Theme>* ABI_STATIC_Theme_getDefault();
	C_ABI void ABI_STATIC_Theme_finalizer(std::shared_ptr<Theme>* pointer);
	C_ABI void ABI_Theme_load(std::shared_ptr<Theme>* self, char* primary);
	C_ABI Theme* ABI_STATIC_Theme_getUnshared(std::shared_ptr<Theme>* pointer);
	// Texture
	C_ABI Texture* ABI_Texture_new(char* id, int partRectX, int partRectY, int partRectW, int partRectH, int middlePartX, int middlePartY, int middlePartW, int middlePartH, int smooth);
	C_ABI void ABI_STATIC_Texture_delete(Texture* texture);
	C_ABI const char32_t* ABI_Texture_getId(Texture* self);
	C_ABI Vector2i* ABI_Texture_getImageSize(Texture* self);
	C_ABI UIntRect* ABI_Texture_getPartRect(Texture* self);
	C_ABI void ABI_Texture_setColor(Texture* self, int red, int green, int blue);
	C_ABI Color* ABI_Texture_getColor(Texture* self);
	C_ABI bool ABI_Texture_isSmooth(Texture* self);
	C_ABI void ABI_STATIC_Texture_setDefaultSmooth(int smooth);
	C_ABI bool ABI_STATIC_Texture_getDefaultSmooth();
	// Widget
	C_ABI void ABI_STATIC_Widget_finalizer(std::shared_ptr<Widget>* pointer);
	C_ABI Widget* ABI_STATIC_Widget_getUnshared(std::shared_ptr<Widget>* pointer);
	C_ABI const char32_t* ABI_STATIC_Widget_getType(Widget::Ptr* self);
	C_ABI const char32_t* ABI_Widget_getName(Widget::Ptr* self);
	C_ABI void ABI_Widget_setRenderer(Widget::Ptr* self, char* renderer);
	C_ABI void ABI_Widget_setSize(Widget::Ptr* self, const char* width, const char* height);
	C_ABI Vector2f* ABI_Widget_getSize(Widget::Ptr* self);
	C_ABI Vector2f* ABI_Widget_getFullSize(Widget::Ptr* self);
	C_ABI void ABI_Widget_setPosition(Widget::Ptr* self, const char* x, const char* y);
	C_ABI Vector2f* ABI_Widget_getPosition(Widget::Ptr* self);
	C_ABI Vector2f* ABI_Widget_getAbsolutePosition(Widget::Ptr* self);
	C_ABI void ABI_Widget_setTextSize(Widget::Ptr* self, int textSize);
	C_ABI int ABI_Widget_getTextSize(Widget::Ptr* self);
	C_ABI void ABI_Widget_setWidth(Widget::Ptr* self, char* width);
	C_ABI void ABI_Widget_setHeight(Widget::Ptr* self, char* height);
	C_ABI void ABI_Widget_setVisible(Widget::Ptr* self, int visible);
	C_ABI bool ABI_Widget_isVisible(Widget::Ptr* self);
	C_ABI void ABI_Widget_setEnabled(Widget::Ptr* self, int enabled);
	C_ABI bool ABI_Widget_isEnabled(Widget::Ptr* self);
	C_ABI void ABI_Widget_setFocused(Widget::Ptr* self, int focused);
	C_ABI bool ABI_Widget_isFocused(Widget::Ptr* self);
	C_ABI void ABI_Widget_setFocusable(Widget::Ptr* self, int focusable);
	C_ABI bool ABI_Widget_isFocusable(Widget::Ptr* self);
	C_ABI bool ABI_Widget_canGainFocus(Widget::Ptr* self);
	C_ABI bool ABI_Widget_isContainer(Widget::Ptr* self);
	C_ABI void ABI_Widget_setToolTip(Widget::Ptr* self, Widget::Ptr* tooltip);
	C_ABI Widget::Ptr* ABI_Widget_getToolTip(Widget::Ptr* self);
	C_ABI void ABI_Widget_setMouseCursor(Widget::Ptr* self, int cursor);
	C_ABI int ABI_Widget_getMouseCursor(Widget::Ptr* self);
	C_ABI void ABI_Widget_setNavigation(Widget::Ptr* self, Widget::Ptr* that, int direction);
	C_ABI Widget::Ptr* ABI_Widget_getNavigation(Widget::Ptr* self, int direction);
	C_ABI bool ABI_Widget_isMouseDown(Widget::Ptr* self);
	C_ABI void ABI_Widget_showWithEffect(Widget::Ptr* self, int effect, int duration);
	C_ABI void ABI_Widget_hideWithEffect(Widget::Ptr* self, int effect, int duration);
	C_ABI void ABI_Widget_moveWithAnimation(Widget::Ptr* self, char* x, char* y, int duration);
	C_ABI void ABI_Widget_resizeWithAnimation(Widget::Ptr* self, char* width, char* height, int duration);
	C_ABI bool ABI_Widget_isAnimationPlaying(Widget::Ptr* self);
	C_ABI void ABI_Widget_moveToFront(Widget::Ptr* self);
	C_ABI void ABI_Widget_moveToBack(Widget::Ptr* self);
	C_ABI void ABI_Widget_finishAllAnimations(Widget::Ptr* self);
	C_ABI void ABI_Widget_leftMousePressed(Widget::Ptr* self, float x, float y);
	C_ABI void ABI_Widget_leftMouseReleased(Widget::Ptr* self, float x, float y);
	C_ABI void ABI_Widget_rightMousePressed(Widget::Ptr* self, float x, float y);
	C_ABI void ABI_Widget_rightMouseReleased(Widget::Ptr* self, float x, float y);
	C_ABI void ABI_Widget_mouseMoved(Widget::Ptr* self, float x, float y);
	C_ABI void ABI_Widget_keyPressed(Widget::Ptr* self, int keyCode, int alt, int control, int shift, int system);
	C_ABI void ABI_Widget_textEntered(Widget::Ptr* self, int character);
	C_ABI void ABI_Widget_scrolled(Widget::Ptr* self, float delta, float x, float y, int touch);
	C_ABI void ABI_Widget_askToolTip(Widget::Ptr* self, float x, float y);
	C_ABI void ABI_Widget_setWidgetName(Widget::Ptr* self, char * name);
	C_ABI void ABI_Widget_setAutoLayout(Widget::Ptr* self, int autoLayout);
	C_ABI int ABI_Widget_getAutoLayout(Widget::Ptr* self);
	C_ABI const char32_t* ABI_Widget_getWidgetName(Widget::Ptr* self);
	C_ABI void ABI_Widget_setIgnoreMouseEvents(Widget::Ptr* self, int ignore);
	C_ABI bool ABI_Widget_getIgnoreMouseEvents(Widget::Ptr* self);
	C_ABI SignalVector2f* ABI_Widget_onPositionChange(Widget::Ptr* self);
	C_ABI SignalVector2f* ABI_Widget_onSizeChange(Widget::Ptr* self);
	C_ABI void ABI_Widget_setColorRendererProperty(Widget::Ptr* self, char* property, Color* value);
	C_ABI Color* ABI_Widget_getColorRendererProperty(Widget::Ptr* self, char* property);
	C_ABI void ABI_Widget_setStringRendererProperty(Widget::Ptr* self, char* property, char* value);
	C_ABI const char32_t* ABI_Widget_getStringRendererProperty(Widget::Ptr* self, char* property);
	C_ABI void ABI_Widget_setFontRendererProperty(Widget::Ptr* self, char* property, Font* value);
	C_ABI Font* ABI_Widget_getFontRendererProperty(Widget::Ptr* self, char* property);
	C_ABI void ABI_Widget_setBooleanRendererProperty(Widget::Ptr* self, char* property, int value);
	C_ABI bool ABI_Widget_getBooleanRendererProperty(Widget::Ptr* self, char* property);
	C_ABI void ABI_Widget_setFloatRendererProperty(Widget::Ptr* self, char* property, float value);
	C_ABI float ABI_Widget_getFloatRendererProperty(Widget::Ptr* self, char* property);
	C_ABI void ABI_Widget_setOutlineRendererProperty(Widget::Ptr* self, char* property, Outline* value);
	C_ABI Outline* ABI_Widget_getOutlineRendererProperty(Widget::Ptr* self, char* property);
	C_ABI void ABI_Widget_setTextureRendererProperty(Widget::Ptr* self, char* property, Texture* value);
	C_ABI Texture* ABI_Widget_getTextureRendererProperty(Widget::Ptr* self, char* property);
	C_ABI void ABI_Widget_setTextStylesRendererProperty(Widget::Ptr* self, char* property, int value);
	C_ABI int ABI_Widget_getTextStylesRendererProperty(Widget::Ptr* self, char* property);
	C_ABI Signal* ABI_Widget_onFocus(Widget::Ptr* self);
	C_ABI Signal* ABI_Widget_onUnfocus(Widget::Ptr* self);
	C_ABI Signal* ABI_Widget_onMouseEnter(Widget::Ptr* self);
	C_ABI Signal* ABI_Widget_onMouseLeave(Widget::Ptr* self);
	C_ABI SignalShowEffect* ABI_Widget_onShowEffectFinish(Widget::Ptr* self);
	C_ABI SignalAnimationType* ABI_Widget_onAnimationFinish(Widget::Ptr* self);
	// ClickableWidget
	C_ABI SignalVector2f* ABI_ClickableWidget_onMousePress(ClickableWidget::Ptr* self);
	C_ABI SignalVector2f* ABI_ClickableWidget_onMouseRelease(ClickableWidget::Ptr* self);
	C_ABI SignalVector2f* ABI_ClickableWidget_onClick(ClickableWidget::Ptr* self);
	C_ABI SignalVector2f* ABI_ClickableWidget_onRightMousePress(ClickableWidget::Ptr* self);
	C_ABI SignalVector2f* ABI_ClickableWidget_onRightMouseRelease(ClickableWidget::Ptr* self);
	C_ABI SignalVector2f* ABI_ClickableWidget_onRightClick(ClickableWidget::Ptr* self);
	// ButtonBase
	C_ABI void ABI_ButtonBase_setTextPosition(ButtonBase::Ptr* self, const char* position, const char* origin);
	C_ABI void ABI_ButtonBase_setText(ButtonBase::Ptr* self, const char* text);
	C_ABI const char32_t* ABI_ButtonBase_getText(ButtonBase::Ptr* self);
	// Button
	C_ABI Button::Ptr* ABI_Button_new();
	C_ABI Signal* ABI_Button_onPress(Button::Ptr* self);
	// BitmapButton
	C_ABI BitmapButton::Ptr* ABI_BitmapButton_new();
	C_ABI void ABI_BitmapButton_setImage(BitmapButton::Ptr* self, Texture* texture);
	C_ABI Texture* ABI_BitmapButton_getImage(BitmapButton::Ptr* self);
	C_ABI void ABI_BitmapButton_setImageScaling(BitmapButton::Ptr* self, float relativeHeight);
	C_ABI float ABI_BitmapButton_getImageScaling(BitmapButton::Ptr* self);
	// EditBox
	C_ABI EditBox::Ptr* ABI_EditBox_new();
	C_ABI void ABI_EditBox_setText(EditBox::Ptr* self, const char* text);
	C_ABI const char32_t* ABI_EditBox_getText(EditBox::Ptr* self);
	C_ABI void ABI_EditBox_setDefaultText(EditBox::Ptr* self, const char* text);
	C_ABI const char32_t* ABI_EditBox_getDefaultText(EditBox::Ptr* self);
	C_ABI void ABI_EditBox_selectText(EditBox::Ptr* self, int start, int length);
	C_ABI const char32_t* ABI_EditBox_getSelectedText(EditBox::Ptr* self);
	C_ABI void ABI_EditBox_setPasswordCharacter(EditBox::Ptr* self, char* character);
	C_ABI char ABI_EditBox_getPasswordCharacter(EditBox::Ptr* self);
	C_ABI void ABI_EditBox_setMaximumCharacters(EditBox::Ptr* self, unsigned int max);
	C_ABI unsigned int ABI_EditBox_getMaximumCharacters(EditBox::Ptr* self);
	C_ABI void ABI_EditBox_setAlignment(EditBox::Ptr* self, int alignment);
	C_ABI int ABI_EditBox_getAlignment(EditBox::Ptr* self);
	C_ABI void ABI_EditBox_setTextWidthLimited(EditBox::Ptr* self, int limit);
	C_ABI bool ABI_EditBox_isTextWidthLimited(EditBox::Ptr* self);
	C_ABI void ABI_EditBox_setReadOnly(EditBox::Ptr* self, int read_only);
	C_ABI bool ABI_EditBox_isReadOnly(EditBox::Ptr* self);
	C_ABI void ABI_EditBox_setCaretPosition(EditBox::Ptr* self, int caretPosition);
	C_ABI int ABI_EditBox_getCaretPosition(EditBox::Ptr* self);
	C_ABI void ABI_EditBox_setSuffix(EditBox::Ptr* self, char* suffix);
	C_ABI const char32_t* ABI_EditBox_getSuffix(EditBox::Ptr* self);
	C_ABI SignalString* ABI_EditBox_onTextChange(EditBox::Ptr* self);
	C_ABI SignalString* ABI_EditBox_onReturnKeyPress(EditBox::Ptr* self);
	C_ABI SignalString* ABI_EditBox_onReturnOrUnfocus(EditBox::Ptr* self);
	C_ABI SignalTypedSizeT* ABI_EditBox_onCaretPositionChange(EditBox::Ptr* self);
	// Label
	C_ABI Label::Ptr* ABI_Label_new();
	C_ABI void ABI_Label_setText(Label::Ptr* self, char* text);
	C_ABI const char32_t* ABI_Label_getText(Label::Ptr* self);
	C_ABI void ABI_Label_setHorizontalAlignment(Label::Ptr* self, int alignment);
	C_ABI int ABI_Label_getHorizontalAlignment(Label::Ptr* self);
	C_ABI void ABI_Label_setVerticalAlignment(Label::Ptr* self, int alignment);
	C_ABI int ABI_Label_getVerticalAlignment(Label::Ptr* self);
	C_ABI void ABI_Label_setScrollbarPolicy(Label::Ptr* self, int policy);
	C_ABI int ABI_Label_getScrollbarPolicy(Label::Ptr* self);
	C_ABI void ABI_Label_setScrollbarValue(Label::Ptr* self, unsigned int value);
	C_ABI int ABI_Label_getScrollbarValue(Label::Ptr* self);
	C_ABI void ABI_Label_setAutoSize(Label::Ptr* self, int auto_size);
	C_ABI bool ABI_Label_getAutoSize(Label::Ptr* self);
	C_ABI void ABI_Label_setMaximumTextWidth(Label::Ptr* self, float maximumWidth);
	C_ABI float ABI_Label_getMaximumTextWidth(Label::Ptr* self);
	// RadioButton
	C_ABI RadioButton::Ptr* ABI_RadioButton_new();
	C_ABI void ABI_RadioButton_setText(RadioButton::Ptr* self, char* text);
	C_ABI const char32_t* ABI_RadioButton_getText(RadioButton::Ptr* self);
	C_ABI void ABI_RadioButton_setChecked(RadioButton::Ptr* self, int checked);
	C_ABI bool ABI_RadioButton_isChecked(RadioButton::Ptr* self);
	C_ABI void ABI_RadioButton_setTextClickable(RadioButton::Ptr* self, int textClickable);
	C_ABI bool ABI_RadioButton_isTextClickable(RadioButton::Ptr* self);
	C_ABI SignalBool* ABI_RadioButton_onCheck(RadioButton::Ptr* self);
	C_ABI SignalBool* ABI_RadioButton_onUncheck(RadioButton::Ptr* self);
	C_ABI SignalBool* ABI_RadioButton_onChange(RadioButton::Ptr* self);
	// CheckBox
	C_ABI CheckBox::Ptr* ABI_CheckBox_new();
	// Knob
	C_ABI Knob::Ptr* ABI_Knob_new();
	C_ABI void ABI_Knob_setStartRotation(Knob::Ptr* self, float startRotation);
	C_ABI float ABI_Knob_getStartRotation(Knob::Ptr* self);
	C_ABI void ABI_Knob_setEndRotation(Knob::Ptr* self, float endRotation);
	C_ABI float ABI_Knob_getEndRotation(Knob::Ptr* self);
	C_ABI void ABI_Knob_setMinimum(Knob::Ptr* self, float minimum);
	C_ABI float ABI_Knob_getMinimum(Knob::Ptr* self);
	C_ABI void ABI_Knob_setMaximum(Knob::Ptr* self, float maximum);
	C_ABI float ABI_Knob_getMaximum(Knob::Ptr* self);
	C_ABI void ABI_Knob_setValue(Knob::Ptr* self, float value);
	C_ABI float ABI_Knob_getValue(Knob::Ptr* self);
	C_ABI void ABI_Knob_setClockwiseTurning(Knob::Ptr* self, int clockwiseTurning);
	C_ABI float ABI_Knob_getClockwiseTurning(Knob::Ptr* self);
	C_ABI SignalFloat* ABI_Knob_onValueChange(Knob::Ptr* self);
	// ChatBox
	C_ABI ChatBox::Ptr* ABI_ChatBox_new();
	C_ABI void ABI_ChatBox_addLine(ChatBox::Ptr* self, char* text, Color* color, int style);
	C_ABI const char32_t* ABI_ChatBox_getLine(ChatBox::Ptr* self, int lineIndex);
	C_ABI Color* ABI_ChatBox_getLineColor(ChatBox::Ptr* self, int lineIndex);
	C_ABI int ABI_ChatBox_getLineTextStyle(ChatBox::Ptr* self, int lineIndex);
	C_ABI bool ABI_ChatBox_removeLine(ChatBox::Ptr* self, int lineIndex);
	C_ABI void ABI_ChatBox_removeAllLines(ChatBox::Ptr* self);
	C_ABI int ABI_ChatBox_getLineAmount(ChatBox::Ptr* self);
	C_ABI void ABI_ChatBox_setLineLimit(ChatBox::Ptr* self, int maxLines);
	C_ABI int ABI_ChatBox_getLineLimit(ChatBox::Ptr* self);
	C_ABI void ABI_ChatBox_setTextColor(ChatBox::Ptr* self, Color* color);
	C_ABI Color* ABI_ChatBox_getTextColor(ChatBox::Ptr* self);
	C_ABI void ABI_ChatBox_setTextStyle(ChatBox::Ptr* self, int style);
	C_ABI int ABI_ChatBox_getTextStyle(ChatBox::Ptr* self);
	C_ABI void ABI_ChatBox_setLinesStartFromTop(ChatBox::Ptr* self, int startFromTop);
	C_ABI bool ABI_ChatBox_getLinesStartFromTop(ChatBox::Ptr* self);
	C_ABI void ABI_ChatBox_setNewLinesBelowOthers(ChatBox::Ptr* self, int newLinesBelowOthers);
	C_ABI bool ABI_ChatBox_getNewLinesBelowOthers(ChatBox::Ptr* self);
	C_ABI void ABI_ChatBox_setScrollbarValue(ChatBox::Ptr* self, int value);
	C_ABI int ABI_ChatBox_getScrollbarValue(ChatBox::Ptr* self); 
	// Container
	C_ABI void ABI_Container_get_widgets(Container::Ptr* self, void(*f)(Widget::Ptr* widget, const char32_t* type));
	C_ABI void ABI_Container_add(Container::Ptr* self, Widget::Ptr* widget, char* name);
	C_ABI Widget::Ptr* ABI_Container_get(Container::Ptr* self, char* name);
	C_ABI bool ABI_Container_remove(Container::Ptr* self, Widget::Ptr* widget);
	C_ABI void ABI_Container_removeAllWidgets(Container::Ptr* self);
	C_ABI Vector2f* ABI_Container_getInnerSize(Container::Ptr* self);
	C_ABI Vector2f* ABI_Container_getChildWidgetsOffset(Container::Ptr* self);
	C_ABI void ABI_Container_moveWidgetToFront(Container::Ptr* self, Widget::Ptr* widget);
	C_ABI void ABI_Container_moveWidgetToBack(Container::Ptr* self, Widget::Ptr* widget);
	C_ABI int ABI_Container_moveWidgetForward(Container::Ptr* self, Widget::Ptr* widget);
	C_ABI int ABI_Container_moveWidgetBackward(Container::Ptr* self, Widget::Ptr* widget);
	C_ABI bool ABI_Container_setWidgetIndex(Container::Ptr* self, Widget::Ptr* widget, int index);
	C_ABI int ABI_Container_getWidgetIndex(Container::Ptr* self, Widget::Ptr* widget);
	C_ABI Widget::Ptr* ABI_Container_getFocusedChild(Container::Ptr* self);
	C_ABI Widget::Ptr* ABI_Container_getFocusedLeaf(Container::Ptr* self);
	C_ABI Widget::Ptr* ABI_Container_getWidgetAtPos(Container::Ptr* self, float x, float y, int recursive);
	C_ABI bool ABI_Container_focusNextWidget(Container::Ptr* self, int recursive);
	C_ABI bool ABI_Container_focusPreviousWidget(Container::Ptr* self, int recursive);
	// ChildWindow
	C_ABI ChildWindow::Ptr* ABI_ChildWindow_new();
	C_ABI void ABI_ChildWindow_setClientSize(ChildWindow::Ptr* self, char* width, char* height);
	C_ABI Vector2f* ABI_ChildWindow_getClientSize(ChildWindow::Ptr* self);
	C_ABI void ABI_ChildWindow_setMaximumSize(ChildWindow::Ptr* self, float x, float y);
	C_ABI Vector2f* ABI_ChildWindow_getMaximumSize(ChildWindow::Ptr* self);
	C_ABI void ABI_ChildWindow_setMinimumSize(ChildWindow::Ptr* self, float x, float y);
	C_ABI Vector2f* ABI_ChildWindow_getMinimumSize(ChildWindow::Ptr* self);
	C_ABI void ABI_ChildWindow_setTitle(ChildWindow::Ptr* self, char* title);
	C_ABI const char32_t* ABI_ChildWindow_getTitle(ChildWindow::Ptr* self);
	C_ABI void ABI_ChildWindow_setTitleTextSize(ChildWindow::Ptr* self, unsigned int size);
	C_ABI unsigned int ABI_ChildWindow_getTitleTextSize(ChildWindow::Ptr* self);
	C_ABI void ABI_ChildWindow_setTitleAlignment(ChildWindow::Ptr* self, int alignment);
	C_ABI int ABI_ChildWindow_getTitleAlignment(ChildWindow::Ptr* self);
	C_ABI void ABI_ChildWindow_setTitleButtons(ChildWindow::Ptr* self, unsigned int buttons);
	C_ABI unsigned int ABI_ChildWindow_getTitleButtons(ChildWindow::Ptr* self);
	C_ABI void ABI_ChildWindow_close(ChildWindow::Ptr* self);
	C_ABI void ABI_ChildWindow_destroy(ChildWindow::Ptr* self);
	C_ABI void ABI_ChildWindow_setResizable(ChildWindow::Ptr* self, int resizable);
	C_ABI bool ABI_ChildWindow_isResizable(ChildWindow::Ptr* self);
	C_ABI void ABI_ChildWindow_setPositionLocked(ChildWindow::Ptr* self, int positionLocked);
	C_ABI bool ABI_ChildWindow_isPositionLocked(ChildWindow::Ptr* self);
	C_ABI void ABI_ChildWindow_setKeepInParent(ChildWindow::Ptr* self, int enabled);
	C_ABI bool ABI_ChildWindow_getKeepInParent(ChildWindow::Ptr* self);
	C_ABI Signal* ABI_ChildWindow_onMousePress(ChildWindow::Ptr* self);
	C_ABI Signal* ABI_ChildWindow_onClose(ChildWindow::Ptr* self);
	C_ABI Signal* ABI_ChildWindow_onMinimize(ChildWindow::Ptr* self);
	C_ABI Signal* ABI_ChildWindow_onMaximize(ChildWindow::Ptr* self);
	C_ABI Signal* ABI_ChildWindow_onEscapeKeyPress(ChildWindow::Ptr* self);
	C_ABI SignalTyped<bool*>* ABI_ChildWindow_onClosing(ChildWindow::Ptr* self);
	// Group
	C_ABI Group::Ptr* ABI_Group_new();
	// BoxLayout
	C_ABI Widget::Ptr* ABI_BoxLayout_getByIndex(BoxLayout::Ptr* self, int index);
	C_ABI void ABI_BoxLayout_insert(BoxLayout::Ptr* self, int index, Widget::Ptr* widget, char* name);
	C_ABI bool ABI_BoxLayout_removeByIndex(BoxLayout::Ptr* self, int index);
	// BoxLayoutRatios
	C_ABI void ABI_BoxLayoutRatios_addSpace(BoxLayoutRatios::Ptr* self, float ratio);
	C_ABI void ABI_BoxLayoutRatios_insertSpace(BoxLayoutRatios::Ptr* self, int index, float ratio);
	C_ABI void ABI_BoxLayoutRatios_setRatio(BoxLayoutRatios::Ptr* self, Widget::Ptr* widget, float ratio);
	C_ABI void ABI_BoxLayoutRatios_setRatioByIndex(BoxLayoutRatios::Ptr* self, int index, float ratio);
	C_ABI float ABI_BoxLayoutRatios_getRatio(BoxLayoutRatios::Ptr* self, Widget::Ptr* widget);
	C_ABI float ABI_BoxLayoutRatios_getRatioByIndex(BoxLayoutRatios::Ptr* self, int index);
	// HorizontalLayout
	C_ABI HorizontalLayout::Ptr* ABI_HorizontalLayout_new();
	// VerticalLayout
	C_ABI VerticalLayout::Ptr* ABI_VerticalLayout_new();
	// HorizontalWrap
	C_ABI HorizontalWrap::Ptr* ABI_HorizontalWrap_new();
	// RadioButtonGroup
	C_ABI RadioButtonGroup::Ptr* ABI_RadioButtonGroup_new();
	C_ABI void ABI_RadioButtonGroup_uncheckRadioButtons(RadioButtonGroup::Ptr* self);
	C_ABI RadioButton::Ptr* ABI_RadioButtonGroup_getCheckedRadioButton(RadioButtonGroup::Ptr* self);
	// Panel
	C_ABI Panel::Ptr* ABI_Panel_new();
	C_ABI SignalVector2f* ABI_Panel_onMousePress(Panel::Ptr* self);
	C_ABI SignalVector2f* ABI_Panel_onMouseRelease(Panel::Ptr* self);
	C_ABI SignalVector2f* ABI_Panel_onClick(Panel::Ptr* self);
	C_ABI SignalVector2f* ABI_Panel_onDoubleClick(Panel::Ptr* self);
	C_ABI SignalVector2f* ABI_Panel_onRightMousePress(Panel::Ptr* self);
	C_ABI SignalVector2f* ABI_Panel_onRightMouseRelease(Panel::Ptr* self);
	C_ABI SignalVector2f* ABI_Panel_onRightClick(Panel::Ptr* self);
	// ScrollablePanel
	C_ABI ScrollablePanel::Ptr* ABI_ScrollablePanel_new();
	C_ABI void ABI_ScrollablePanel_setContentSize(ScrollablePanel::Ptr* self, float x, float y);
	C_ABI Vector2f* ABI_ScrollablePanel_getContentSize(ScrollablePanel::Ptr* self);
	C_ABI Vector2f* ABI_ScrollablePanel_getContentOffset(ScrollablePanel::Ptr* self);
	C_ABI float ABI_ScrollablePanel_getScrollbarWidth(ScrollablePanel::Ptr* self);
	C_ABI void ABI_ScrollablePanel_setVerticalScrollbarPolicy(ScrollablePanel::Ptr* self, int policy);
	C_ABI int ABI_ScrollablePanel_getVerticalScrollbarPolicy(ScrollablePanel::Ptr* self);
	C_ABI void ABI_ScrollablePanel_setHorizontalScrollbarPolicy(ScrollablePanel::Ptr* self, int policy);
	C_ABI int ABI_ScrollablePanel_getHorizontalScrollbarPolicy(ScrollablePanel::Ptr* self);
	C_ABI void ABI_ScrollablePanel_setVerticalScrollAmount(ScrollablePanel::Ptr* self, int amount);
	C_ABI int ABI_ScrollablePanel_getVerticalScrollAmount(ScrollablePanel::Ptr* self);
	C_ABI void ABI_ScrollablePanel_setHorizontalScrollAmount(ScrollablePanel::Ptr* self, int amount);
	C_ABI int ABI_ScrollablePanel_getHorizontalScrollAmount(ScrollablePanel::Ptr* self);
	C_ABI void ABI_ScrollablePanel_setVerticalScrollbarValue(ScrollablePanel::Ptr* self, int value);
	C_ABI int ABI_ScrollablePanel_getVerticalScrollbarValue(ScrollablePanel::Ptr* self);
	C_ABI void ABI_ScrollablePanel_setHorizontalScrollbarValue(ScrollablePanel::Ptr* self, int value);
	C_ABI int ABI_ScrollablePanel_getHorizontalScrollbarValue(ScrollablePanel::Ptr* self);
	// Grid
	C_ABI Grid::Ptr* ABI_Grid_new();
	C_ABI void ABI_Grid_setAutoSize(Grid::Ptr* self, int autoSize);
	C_ABI bool ABI_Grid_isAutoSize(Grid::Ptr* self);
	C_ABI bool ABI_Grid_setWidgetCell(Grid::Ptr* self, Widget::Ptr* widget, int row, int column);
	C_ABI Widget::Ptr* ABI_Grid_getWidget(Grid::Ptr* self, int row, int column);
	C_ABI void ABI_Grid_setWidgetPadding(Grid::Ptr* self, Widget::Ptr* widget, Outline* padding);
	C_ABI Outline* ABI_Grid_getWidgetPadding(Grid::Ptr* self, Widget::Ptr* widget);
	C_ABI void ABI_Grid_setWidgetAlignment(Grid::Ptr* self, Widget::Ptr* widget, int alignment);
	C_ABI int ABI_Grid_getWidgetAlignment(Grid::Ptr* self, Widget::Ptr* widget);
	C_ABI void ABI_Grid_getWidgetLocations(Grid::Ptr* self, void(*f)(Widget::Ptr*, const char32_t*, int, int));
	// ListBox
	C_ABI ListBox::Ptr* ABI_ListBox_new();
	C_ABI int ABI_ListBox_addItem(ListBox::Ptr* self, char* itemName, char* id);
	C_ABI bool ABI_ListBox_setSelectedItem(ListBox::Ptr* self, char* itemName);
	C_ABI bool ABI_ListBox_setSelectedItemById(ListBox::Ptr* self, char* id);
	C_ABI bool ABI_ListBox_setSelectedItemByIndex(ListBox::Ptr* self, int index);
	C_ABI void ABI_ListBox_deselectItem(ListBox::Ptr* self);
	C_ABI bool ABI_ListBox_removeItem(ListBox::Ptr* self, char* itemName);
	C_ABI bool ABI_ListBox_removeItemById(ListBox::Ptr* self, char* id);
	C_ABI bool ABI_ListBox_removeItemByIndex(ListBox::Ptr* self, int index);
	C_ABI void ABI_ListBox_removeAllItems(ListBox::Ptr* self);
	C_ABI const char32_t* ABI_ListBox_getItemById(ListBox::Ptr* self, char* id);
	C_ABI const char32_t* ABI_ListBox_getItemByIndex(ListBox::Ptr* self, int index);
	C_ABI int ABI_ListBox_getIndexById(ListBox::Ptr* self, char* id);
	C_ABI const char32_t* ABI_ListBox_getIdByIndex(ListBox::Ptr* self, int index);
	C_ABI const char32_t* ABI_ListBox_getSelectedItem(ListBox::Ptr* self);
	C_ABI const char32_t* ABI_ListBox_getSelectedItemId(ListBox::Ptr* self);
	C_ABI int ABI_ListBox_getSelectedItemIndex(ListBox::Ptr* self);
	C_ABI bool ABI_ListBox_changeItem(ListBox::Ptr* self, char* originalValue, char* newValue);
	C_ABI bool ABI_ListBox_changeItemById(ListBox::Ptr* self, char* id, char* newValue);
	C_ABI bool ABI_ListBox_changeItemByIndex(ListBox::Ptr* self, int index, char* newValue);
	C_ABI int ABI_ListBox_getItemCount(ListBox::Ptr* self);
	C_ABI void ABI_ListBox_getItems(ListBox::Ptr* self, void(*f)(const char32_t*));
	C_ABI void ABI_ListBox_getItemIds(ListBox::Ptr* self, void(*f)(const char32_t*));
	C_ABI void ABI_ListBox_setItemHeight(ListBox::Ptr* self, int itemHeight);
	C_ABI int ABI_ListBox_getItemHeight(ListBox::Ptr* self);
	C_ABI void ABI_ListBox_setMaximumItems(ListBox::Ptr* self, int maximumItems);
	C_ABI int ABI_ListBox_getMaximumItems(ListBox::Ptr* self);
	C_ABI void ABI_ListBox_setAutoScroll(ListBox::Ptr* self, int autoScroll);
	C_ABI bool ABI_ListBox_getAutoScroll(ListBox::Ptr* self);
	C_ABI void ABI_ListBox_setTextAlignment(ListBox::Ptr* self, int alignment);
	C_ABI int ABI_ListBox_getTextAlignment(ListBox::Ptr* self);
	C_ABI bool ABI_ListBox_contains(ListBox::Ptr* self, char* item);
	C_ABI bool ABI_ListBox_containsId(ListBox::Ptr* self, char* id);
	C_ABI void ABI_ListBox_setScrollbarValue(ListBox::Ptr* self, int value);
	C_ABI int ABI_ListBox_getScrollbarValue(ListBox::Ptr* self);
	C_ABI SignalItem* ABI_ListBox_onItemSelect(ListBox::Ptr* self);
	C_ABI SignalItem* ABI_ListBox_onMousePress(ListBox::Ptr* self);
	C_ABI SignalItem* ABI_ListBox_onMouseRelease(ListBox::Ptr* self);
	C_ABI SignalItem* ABI_ListBox_onDoubleClick(ListBox::Ptr* self);
	C_ABI Signal* ABI_ListBox_onScroll(ListBox::Ptr* self);
	// ListView
	C_ABI ListView::Ptr* ABI_ListView_new();
	C_ABI int ABI_ListView_addColumn(ListView::Ptr* self);
	C_ABI void ABI_ListView_setColumnText(ListView::Ptr* self, int index, char* text);
	C_ABI const char32_t* ABI_ListView_getColumnText(ListView::Ptr* self, int index);
	C_ABI void ABI_ListView_setColumnWidth(ListView::Ptr* self, int index, float width);
	C_ABI float ABI_ListView_getColumnWidth(ListView::Ptr* self, int index);
	C_ABI void ABI_ListView_setColumnAlignment(ListView::Ptr* self, int index, int columnAlignment);
	C_ABI int ABI_ListView_getColumnAlignment(ListView::Ptr* self, int index);
	C_ABI void ABI_ListView_setColumnAutoResize(ListView::Ptr* self, int index, int autoResize);
	C_ABI bool ABI_ListView_getColumnAutoResize(ListView::Ptr* self, int index);
	C_ABI void ABI_ListView_setColumnExpanded(ListView::Ptr* self, int index, int expanded);
	C_ABI bool ABI_ListView_getColumnExpanded(ListView::Ptr* self, int index);
	C_ABI void ABI_ListView_removeAllColumns(ListView::Ptr* self);
	C_ABI int ABI_ListView_getColumnCount(ListView::Ptr* self);
	C_ABI void ABI_ListView_setHeaderHeight(ListView::Ptr* self, float height);
	C_ABI float ABI_ListView_getHeaderHeight(ListView::Ptr* self);
	C_ABI float ABI_ListView_getCurrentHeaderHeight(ListView::Ptr* self);
	C_ABI void ABI_ListView_setHeaderVisible(ListView::Ptr* self, int showHeader);
	C_ABI bool ABI_ListView_headerVisible(ListView::Ptr* self);
	C_ABI int ABI_ListView_addItem(ListView::Ptr* self, char*(*f)(void));
	C_ABI void ABI_ListView_insertItem(ListView::Ptr* self, int index, char*(*f)(void));
	C_ABI bool ABI_ListView_changeItem(ListView::Ptr* self, int index, char*(*f)(void));
	C_ABI bool ABI_ListView_changeSubitem(ListView::Ptr* self, int index, int column, char* item);
	C_ABI bool ABI_ListView_removeItem(ListView::Ptr* self, int index);
	C_ABI void ABI_ListView_removeAllItems(ListView::Ptr* self);
	C_ABI void ABI_ListView_setSelectedItem(ListView::Ptr* self, int index);
	C_ABI void ABI_ListView_setSelectedItems(ListView::Ptr* self, int size, int(*f)(void));
	C_ABI void ABI_ListView_deselectItems(ListView::Ptr* self);
	C_ABI int ABI_ListView_getSelectedItemIndex(ListView::Ptr* self);
	C_ABI void ABI_ListView_getSelectedItemIndices(ListView::Ptr* self, void(*f)(int));
	C_ABI void ABI_ListView_setMultiSelect(ListView::Ptr* self, int multiSelect);
	C_ABI bool ABI_ListView_multiSelect(ListView::Ptr* self);
	C_ABI void ABI_ListView_setItemIcon(ListView::Ptr* self, int index, Texture* texture);
	C_ABI Texture* ABI_ListView_getItemIcon(ListView::Ptr* self, int index);
	C_ABI int ABI_ListView_getItemCount(ListView::Ptr* self);
	C_ABI void ABI_ListView_getItemRow(ListView::Ptr* self, int index, void(*f)(const char32_t*));
	C_ABI const char32_t* ABI_ListView_getItemCell(ListView::Ptr* self, int rowIndex, int columnIndex);
	C_ABI void ABI_ListView_getItemRows(ListView::Ptr* self, void(*f)(const char32_t*, int row));
	C_ABI void ABI_ListView_setItemHeight(ListView::Ptr* self, int itemHeight);
	C_ABI int ABI_ListView_getItemHeight(ListView::Ptr* self);
	C_ABI void ABI_ListView_setHeaderTextSize(ListView::Ptr* self, int textSize);
	C_ABI int ABI_ListView_getHeaderTextSize(ListView::Ptr* self);
	C_ABI void ABI_ListView_setSeparatorWidth(ListView::Ptr* self, int width);
	C_ABI int ABI_ListView_getSeparatorWidth(ListView::Ptr* self);
	C_ABI void ABI_ListView_setHeaderSeparatorHeight(ListView::Ptr* self, int height);
	C_ABI int ABI_ListView_getHeaderSeparatorHeight(ListView::Ptr* self);
	C_ABI void ABI_ListView_setGridLinesWidth(ListView::Ptr* self, int width);
	C_ABI int ABI_ListView_getGridLinesWidth(ListView::Ptr* self);
	C_ABI void ABI_ListView_setAutoScroll(ListView::Ptr* self, int autoScroll);
	C_ABI bool ABI_ListView_autoScroll(ListView::Ptr* self);
	C_ABI void ABI_ListView_setShowVerticalGridLines(ListView::Ptr* self, int showGridLines);
	C_ABI bool ABI_ListView_showVerticalGridLines(ListView::Ptr* self);
	C_ABI void ABI_ListView_setShowHorizontalGridLines(ListView::Ptr* self, int showGridLines);
	C_ABI bool ABI_ListView_showHorizontalGridLines(ListView::Ptr* self);
	C_ABI void ABI_ListView_setVerticalScrollbarPolicy(ListView::Ptr* self, int policy);
	C_ABI int ABI_ListView_getVerticalScrollbarPolicy(ListView::Ptr* self);
	C_ABI void ABI_ListView_setHorizontalScrollbarPolicy(ListView::Ptr* self, int policy);
	C_ABI int ABI_ListView_getHorizontalScrollbarPolicy(ListView::Ptr* self);
	C_ABI void ABI_ListView_setVerticalScrollbarValue(ListView::Ptr* self, int value);
	C_ABI int ABI_ListView_getVerticalScrollbarValue(ListView::Ptr* self);
	C_ABI void ABI_ListView_setHorizontalScrollbarValue(ListView::Ptr* self, int value);
	C_ABI int ABI_ListView_getHorizontalScrollbarValue(ListView::Ptr* self);
	C_ABI void ABI_ListView_setFixedIconSize(ListView::Ptr* self, float width, float height);
	C_ABI Vector2f* ABI_ListView_getFixedIconSize(ListView::Ptr* self);
	C_ABI void ABI_ListView_setResizableColumns(ListView::Ptr* self, int resizable);
	C_ABI bool ABI_ListView_resizableColumns(ListView::Ptr* self);
	C_ABI SignalInt* ABI_ListView_onItemSelect(ListView::Ptr* self);
	C_ABI SignalInt* ABI_ListView_onDoubleClick(ListView::Ptr* self);
	C_ABI SignalInt* ABI_ListView_onRightClick(ListView::Ptr* self);
	C_ABI SignalInt* ABI_ListView_onHeaderClick(ListView::Ptr* self);
	// ComboBox
	C_ABI ComboBox::Ptr* ABI_ComboBox_new();
	C_ABI void ABI_ComboBox_setItemsToDisplay(ComboBox::Ptr* self, int itemsToDisplay);
	C_ABI int ABI_ComboBox_getItemsToDisplay(ComboBox::Ptr* self);
	C_ABI void ABI_ComboBox_addItem(ComboBox::Ptr* self, char* name, char* id);
	C_ABI bool ABI_ComboBox_setSelectedItemById(ComboBox::Ptr* self, char* id);
	C_ABI bool ABI_ComboBox_setSelectedItemByIndex(ComboBox::Ptr* self, int index);
	C_ABI void ABI_ComboBox_deselectItem(ComboBox::Ptr* self);
	C_ABI bool ABI_ComboBox_removeItemById(ComboBox::Ptr* self, char* id);
	C_ABI bool ABI_ComboBox_removeItemByIndex(ComboBox::Ptr* self, int index);
	C_ABI void ABI_ComboBox_removeAllItems(ComboBox::Ptr* self);
	C_ABI char32_t* ABI_ComboBox_getItemById(ComboBox::Ptr* self, char* id);
	C_ABI char32_t* ABI_ComboBox_getSelectedItemId(ComboBox::Ptr* self);
	C_ABI bool ABI_ComboBox_changeItemById(ComboBox::Ptr* self, char* id, char* newValue);
	C_ABI bool ABI_ComboBox_changeItemByIndex(ComboBox::Ptr* self, int index, char* newValue);
	C_ABI int ABI_ComboBox_getItemCount(ComboBox::Ptr* self);
	C_ABI void ABI_ComboBox_getItemIds(ComboBox::Ptr* self, void(*f)(char32_t*));
	C_ABI void ABI_ComboBox_setMaximumItems(ComboBox::Ptr* self, int maximumItems);
	C_ABI int ABI_ComboBox_getMaximumItems(ComboBox::Ptr* self);
	C_ABI void ABI_ComboBox_setDefaultText(ComboBox::Ptr* self, char* defaultText);
	C_ABI const char32_t* ABI_ComboBox_getDefaultText(ComboBox::Ptr* self);
	C_ABI void ABI_ComboBox_setExpandDirection(ComboBox::Ptr* self, int expandDirection);
	C_ABI int ABI_ComboBox_getExpandDirection(ComboBox::Ptr* self);
	C_ABI bool ABI_ComboBox_containsId(ComboBox::Ptr* self, char* id);
	C_ABI void ABI_ComboBox_setChangeItemOnScroll(ComboBox::Ptr* self, int changeItemOnScroll);
	C_ABI bool ABI_ComboBox_getChangeItemOnScroll(ComboBox::Ptr* self);
	C_ABI SignalItem* ABI_ComboBox_onItemSelect(ComboBox::Ptr* self);
	// ColorPicker
	C_ABI ColorPicker::Ptr* ABI_ColorPicker_new();
	C_ABI void ABI_ColorPicker_setColor(ColorPicker::Ptr* self, Color* color);
	C_ABI Color* ABI_ColorPicker_getColor(ColorPicker::Ptr* self);
	C_ABI SignalColor* ABI_ColorPicker_onColorChange(ColorPicker::Ptr* self);
	C_ABI SignalColor* ABI_ColorPicker_onOkPress(ColorPicker::Ptr* self);
	// FileDialog
	C_ABI FileDialog::Ptr* ABI_FileDialog_new();
	C_ABI void ABI_FileDialog_getSelectedPaths(FileDialog::Ptr* self, void(*f)(char32_t*));
	C_ABI void ABI_FileDialog_setPath(FileDialog::Ptr* self, char* path);
	C_ABI const char32_t* ABI_FileDialog_getPath(FileDialog::Ptr* self);
	C_ABI void ABI_FileDialog_setFilename(FileDialog::Ptr* self, char* filename);
	C_ABI const char32_t* ABI_FileDialog_getFilename(FileDialog::Ptr* self);
	C_ABI void ABI_FileDialog_setFileTypeFilters(FileDialog::Ptr* self, int size, int(*f)(void), char*(*f1)(void), int defaultFilterIndex);
	C_ABI void ABI_FileDialog_getFileTypeFilters(FileDialog::Ptr* self, void(*f)(int, const char32_t*, const char32_t*));
	C_ABI int ABI_FileDialog_getFileTypeFiltersIndex(FileDialog::Ptr* self);
	C_ABI void ABI_FileDialog_setConfirmButtonText(FileDialog::Ptr* self, char* text);
	C_ABI const char32_t* ABI_FileDialog_getConfirmButtonText(FileDialog::Ptr* self);
	C_ABI void ABI_FileDialog_setCancelButtonText(FileDialog::Ptr* self, char* text);
	C_ABI const char32_t* ABI_FileDialog_getCancelButtonText(FileDialog::Ptr* self);
	C_ABI void ABI_FileDialog_setCreateFolderButtonText(FileDialog::Ptr* self, char* text);
	C_ABI const char32_t* ABI_FileDialog_getCreateFolderButtonText(FileDialog::Ptr* self);
	C_ABI void ABI_FileDialog_setAllowCreateFolder(FileDialog::Ptr* self, int allowCreateFolder);
	C_ABI bool ABI_FileDialog_getAllowCreateFolder(FileDialog::Ptr* self);
	C_ABI void ABI_FileDialog_setFilenameLabelText(FileDialog::Ptr* self, char* labelText);
	C_ABI const char32_t* ABI_FileDialog_getFilenameLabelText(FileDialog::Ptr* self);
	C_ABI void ABI_FileDialog_setListViewColumnCaptions(FileDialog::Ptr* self, char* nameColumnText, char* sizeColumnText, char* modifiedColumnText);
	C_ABI void ABI_FileDialog_getListViewColumnCaptions(FileDialog::Ptr* self, void(*f)(const char32_t*));
	C_ABI void ABI_FileDialog_setFileMustExist(FileDialog::Ptr* self, int enforceExistence);
	C_ABI bool ABI_FileDialog_getFileMustExist(FileDialog::Ptr* self);
	C_ABI void ABI_FileDialog_setSelectingDirectory(FileDialog::Ptr* self, int selectDirectories);
	C_ABI bool ABI_FileDialog_getSelectingDirectory(FileDialog::Ptr* self);
	C_ABI void ABI_FileDialog_setMultiSelect(FileDialog::Ptr* self, int multiSelect);
	C_ABI bool ABI_FileDialog_getMultiSelect(FileDialog::Ptr* self);
	// C_ABI void ABI_FileDialog_setIconLoader(FileDialog::Ptr* self, std::shared_ptr< FileDialogIconLoader >* iconLoader);
	// C_ABI std::shared_ptr< FileDialogIconLoader >* ABI_FileDialog_getIconLoader(FileDialog::Ptr* self);
	C_ABI Signal* ABI_FileDialog_onFileSelect(FileDialog::Ptr* self);
	C_ABI Signal* ABI_FileDialog_onCancel(FileDialog::Ptr* self);
	// MessageBox
	C_ABI MessageBox::Ptr* ABI_MessageBox_new();
	C_ABI void ABI_MessageBox_setText(MessageBox::Ptr* self, char* text);
	C_ABI const char32_t* ABI_MessageBox_getText(MessageBox::Ptr* self);
	C_ABI void ABI_MessageBox_addButton(MessageBox::Ptr* self, char* button);
	C_ABI void ABI_MessageBox_changeButtons(MessageBox::Ptr* self, int size, char*(*f)(void));
	C_ABI void ABI_MessageBox_getButtons(MessageBox::Ptr* self, void(*f)(const char32_t*));
	C_ABI void ABI_MessageBox_setLabelAlignment(MessageBox::Ptr* self, int alignment);
	C_ABI int ABI_MessageBox_getLabelAlignment(MessageBox::Ptr* self);
	C_ABI void ABI_MessageBox_setButtonAlignment(MessageBox::Ptr* self, int alignment);
	C_ABI int ABI_MessageBox_getButtonAlignment(MessageBox::Ptr* self);
	C_ABI SignalString* ABI_MessageBox_onButtonPress(MessageBox::Ptr* self);
	// Picture
	C_ABI Picture::Ptr* ABI_Picture_new(Texture* texture, int transparent);
	C_ABI SignalVector2f* ABI_Picture_onDoubleClick(Picture::Ptr* self);
	// MenuBar
	C_ABI MenuBar::Ptr* ABI_MenuBar_new();
	C_ABI void ABI_MenuBar_addMenu(MenuBar::Ptr* self, char* text);
	C_ABI int ABI_MenuBar_connectMenuItem(MenuBar::Ptr* self, int hierarchySize, char*(*hierarchy)(), void(*handler)());
	C_ABI bool ABI_MenuBar_addMenuItem(MenuBar::Ptr* self, int hierarchySize, char*(*hierarchy)());
	C_ABI bool ABI_MenuBar_changeMenuItem(MenuBar::Ptr* self, int hierarchySize, char*(*hierarchy)(), char* text);
	C_ABI void ABI_MenuBar_removeAllMenus(MenuBar::Ptr* self);
	C_ABI bool ABI_MenuBar_removeMenu(MenuBar::Ptr* self, char* menu);
	C_ABI bool ABI_MenuBar_removeMenuItem(MenuBar::Ptr* self, int hierarchySize, char*(*hierarchy)());
	C_ABI bool ABI_MenuBar_removeSubMenuItems(MenuBar::Ptr* self, int hierarchySize, char*(*hierarchy)());
	C_ABI bool ABI_MenuBar_setMenuEnabled(MenuBar::Ptr* self, char* menu, int enabled);
	C_ABI bool ABI_MenuBar_getMenuEnabled(MenuBar::Ptr* self, char* menu);
	C_ABI bool ABI_MenuBar_setMenuItemEnabled(MenuBar::Ptr* self, int hierarchySize, char*(*hierarchy)(), int enabled);
	C_ABI bool ABI_MenuBar_getMenuItemEnabled(MenuBar::Ptr* self, int hierarchySize, char*(*hierarchy)());
	C_ABI void ABI_MenuBar_setMinimumSubMenuWidth(MenuBar::Ptr* self, float minimumWidth);
	C_ABI float ABI_MenuBar_getMinimumSubMenuWidth(MenuBar::Ptr* self);
	C_ABI void ABI_MenuBar_setInvertedMenuDirection(MenuBar::Ptr* self, int invertDirection);
	C_ABI bool ABI_MenuBar_getInvertedMenuDirection(MenuBar::Ptr* self);
	C_ABI void ABI_MenuBar_getMenus(MenuBar::Ptr* self, void(*m)(const char32_t*, int), void(*up)());
	C_ABI void ABI_MenuBar_closeMenu(MenuBar::Ptr* self);
	C_ABI SignalItemHierarchy* ABI_MenuBar_onMenuItemClick(MenuBar::Ptr* self);
	// PanelListBox
	C_ABI PanelListBox::Ptr* ABI_PanelListBox_new();
	C_ABI Panel::Ptr* ABI_PanelListBox_addItem(PanelListBox::Ptr* self, char* id, int index);
	C_ABI Panel::Ptr* ABI_PanelListBox_getPanelTemplate(PanelListBox::Ptr* self);
	C_ABI float ABI_PanelListBox_getItemsWidth(PanelListBox::Ptr* self);
	C_ABI void ABI_PanelListBox_setItemsHeight(PanelListBox::Ptr* self, char* height);
	C_ABI float ABI_PanelListBox_getItemsHeight(PanelListBox::Ptr* self);
	C_ABI bool ABI_PanelListBox_setSelectedItem(PanelListBox::Ptr* self, Panel::Ptr* panel);
	C_ABI bool ABI_PanelListBox_setSelectedItemById(PanelListBox::Ptr* self, char* id);
	C_ABI bool ABI_PanelListBox_setSelectedItemByIndex(PanelListBox::Ptr* self, int index);
	C_ABI void ABI_PanelListBox_deselectItem(PanelListBox::Ptr* self);
	C_ABI bool ABI_PanelListBox_removeItem(PanelListBox::Ptr* self, Panel::Ptr* panel);
	C_ABI bool ABI_PanelListBox_removeItemById(PanelListBox::Ptr* self, char* id);
	C_ABI bool ABI_PanelListBox_removeItemByIndex(PanelListBox::Ptr* self, int index);
	C_ABI void ABI_PanelLIstBox_removeAllItems(PanelListBox::Ptr* self);
	C_ABI Panel::Ptr* ABI_PanelListBox_getItemById(PanelListBox::Ptr* self, char* id);
	C_ABI Panel::Ptr* ABI_PanelListBox_getItemByIndex(PanelListBox::Ptr* self, int index);
	C_ABI int ABI_PanelListBox_getIndexById(PanelListBox::Ptr* self, char* id);
	C_ABI int ABI_PanelListBox_getIndexByItem(PanelListBox::Ptr* self, Panel::Ptr* panel);
	C_ABI const char32_t* ABI_PanelListBox_getIdByIndex(PanelListBox::Ptr* self, int index);
	C_ABI Panel::Ptr* ABI_PanelListBox_getSelectedItem(PanelListBox::Ptr* self);
	C_ABI const char32_t* ABI_PanelListBox_getSelectedItemId(PanelListBox::Ptr* self);
	C_ABI int ABI_PanelListBox_getSelectedItemIndex(PanelListBox::Ptr* self);
	C_ABI int ABI_PanelListBox_getItemCount(PanelListBox::Ptr* self);
	C_ABI void ABI_PanelListBox_getItems(PanelListBox::Ptr* self, void(*f)(Panel::Ptr*));
	C_ABI void ABI_PanelListBox_getItemIds(PanelListBox::Ptr* self, void(*f)(const char32_t*));
	C_ABI void ABI_PanelListBox_setMaximumItems(PanelListBox::Ptr* self, int maximumItems);
	C_ABI int ABI_PanelListBox_getMaximumItems(PanelListBox::Ptr* self);
	C_ABI bool ABI_PanelListBox_contains(PanelListBox::Ptr* self, Panel::Ptr* panel);
	C_ABI bool ABI_PanelListBox_containsId(PanelListBox::Ptr* self, char* id);
	C_ABI SignalPanelListBoxItem* ABI_PanelListBox_onItemSelect(PanelListBox::Ptr* self);
	// ProgressBar
	C_ABI ProgressBar::Ptr* ABI_ProgressBar_new();
	C_ABI void ABI_ProgressBar_setMinimum(ProgressBar::Ptr* self, int minimum);
	C_ABI int ABI_ProgressBar_getMinimum(ProgressBar::Ptr* self);
	C_ABI void ABI_ProgressBar_setMaximum(ProgressBar::Ptr* self, int maximum);
	C_ABI int ABI_ProgressBar_getMaximum(ProgressBar::Ptr* self);
	C_ABI void ABI_ProgressBar_setValue(ProgressBar::Ptr* self, int value);
	C_ABI int ABI_ProgressBar_getValue(ProgressBar::Ptr* self);
	C_ABI int ABI_ProgressBar_incrementValue(ProgressBar::Ptr* self);
	C_ABI void ABI_ProgressBar_setText(ProgressBar::Ptr* self, char* text);
	C_ABI const char32_t* ABI_ProgressBar_getText(ProgressBar::Ptr* self);
	C_ABI void ABI_ProgressBar_setFillDirection(ProgressBar::Ptr* self, int direction);
	C_ABI int ABI_ProgressBar_getFillDirection(ProgressBar::Ptr* self);
	C_ABI SignalUInt* ABI_ProgressBar_onValueChange(ProgressBar::Ptr* self);
	C_ABI Signal* ABI_ProgressBar_onFull(ProgressBar::Ptr* self);
	// RangeSlider
	C_ABI RangeSlider::Ptr* ABI_RangeSlider_new();
	C_ABI void ABI_RangeSlider_setMinimum(RangeSlider::Ptr* self, float minimum);
	C_ABI float ABI_RangeSlider_getMinimum(RangeSlider::Ptr* self);
	C_ABI void ABI_RangeSlider_setMaximum(RangeSlider::Ptr* self, float maximum);
	C_ABI float ABI_RangeSlider_getMaximum(RangeSlider::Ptr* self);
	C_ABI void ABI_RangeSlider_setSelectionStart(RangeSlider::Ptr* self, float value);
	C_ABI float ABI_RangeSlider_getSelectionStart(RangeSlider::Ptr* self);
	C_ABI void ABI_RangeSlider_setSelectionEnd(RangeSlider::Ptr* self, float value);
	C_ABI float ABI_RangeSlider_getSelectionEnd(RangeSlider::Ptr* self);
	C_ABI void ABI_RangeSlider_setStep(RangeSlider::Ptr* self, float step);
	C_ABI float ABI_RangeSlider_getStep(RangeSlider::Ptr* self);
	C_ABI SignalRange* ABI_RangeSlider_onRangeChange(RangeSlider::Ptr* self);
	// RichTextLabel
	C_ABI RichTextLabel::Ptr* ABI_RichTextLabel_new();
	// SeparatorLine
	C_ABI SeparatorLine::Ptr* ABI_SeparatorLine_new();
	// Slider
	C_ABI Slider::Ptr* ABI_Slider_new();
	C_ABI void ABI_Slider_setMinimum(Slider::Ptr* self, float minimum);
	C_ABI float ABI_Slider_getMinimum(Slider::Ptr* self);
	C_ABI void ABI_Slider_setMaximum(Slider::Ptr* self, float maximum);
	C_ABI float ABI_Slider_getMaximum(Slider::Ptr* self);
	C_ABI void ABI_Slider_setValue(Slider::Ptr* self, float value);
	C_ABI float ABI_Slider_getValue(Slider::Ptr* self);
	C_ABI void ABI_Slider_setStep(Slider::Ptr* self, float step);
	C_ABI float ABI_Slider_getStep(Slider::Ptr* self);
	C_ABI void ABI_Slider_setVerticalScroll(Slider::Ptr* self, int vertical);
	C_ABI bool ABI_Slider_getVerticalScroll(Slider::Ptr* self);
	C_ABI void ABI_Slider_setInvertedDirection(Slider::Ptr* self, int invertedDirection);
	C_ABI bool ABI_Slider_getInvertedDirection(Slider::Ptr* self);
	C_ABI void ABI_Slider_setChangeValueOnScroll(Slider::Ptr* self, int changeValueOnScroll);
	C_ABI bool ABI_Slider_getChangeValueOnScroll(Slider::Ptr* self);
	C_ABI SignalFloat* ABI_Slider_onValueChange(Slider::Ptr* self);
	// SpinButton
	C_ABI SpinButton::Ptr* ABI_SpinButton_new();
	C_ABI void ABI_SpinButton_setMinimum(SpinButton::Ptr* self, float minimum);
	C_ABI float ABI_SpinButton_getMinimum(SpinButton::Ptr* self);
	C_ABI void ABI_SpinButton_setMaximum(SpinButton::Ptr* self, float maximum);
	C_ABI float ABI_SpinButton_getMaximum(SpinButton::Ptr* self);
	C_ABI void ABI_SpinButton_setValue(SpinButton::Ptr* self, float value);
	C_ABI float ABI_SpinButton_getValue(SpinButton::Ptr* self);
	C_ABI void ABI_SpinButton_setStep(SpinButton::Ptr* self, float step);
	C_ABI float ABI_SpinButton_getStep(SpinButton::Ptr* self);
	C_ABI void ABI_SpinButton_setVerticalScroll(SpinButton::Ptr* self, int vertical);
	C_ABI bool ABI_SpinButton_getVerticalScroll(SpinButton::Ptr* self);
	C_ABI SignalFloat* ABI_SpinButton_onValueChange(SpinButton::Ptr* self);
	// SubwidgetContainer
	C_ABI Container::Ptr* ABI_SubwidgetContainer_getContainer(SubwidgetContainer::Ptr* self);
	// SpinControl
	C_ABI SpinControl::Ptr* ABI_SpinControl_new();
	C_ABI void ABI_SpinControl_setMinimum(SpinControl::Ptr* self, float minimum);
	C_ABI float ABI_SpinControl_getMinimum(SpinControl::Ptr* self);
	C_ABI void ABI_SpinControl_setMaximum(SpinControl::Ptr* self, float maximum);
	C_ABI float ABI_SpinControl_getMaximum(SpinControl::Ptr* self);
	C_ABI void ABI_SpinControl_setValue(SpinControl::Ptr* self, float value);
	C_ABI float ABI_SpinControl_getValue(SpinControl::Ptr* self);
	C_ABI void ABI_SpinControl_setStep(SpinControl::Ptr* self, float step);
	C_ABI float ABI_SpinControl_getStep(SpinControl::Ptr* self);
	C_ABI void ABI_SpinControl_setDecimalPlaces(SpinControl::Ptr* self, int decimalPlaces);
	C_ABI int ABI_SpinControl_getDecimalPlaces(SpinControl::Ptr* self);
	C_ABI void ABI_SpinControl_setUseWideArrows(SpinControl::Ptr* self, int useWideArrows);
	C_ABI bool ABI_SpinControl_getUseWideArrows(SpinControl::Ptr* self);
	C_ABI SignalFloat* ABI_SpinControl_onValueChange(SpinControl::Ptr* self);
	// Tabs
	C_ABI Tabs::Ptr* ABI_Tabs_new();
	C_ABI void ABI_Tabs_setAutoSize(Tabs::Ptr* self, int autoSize);
	C_ABI bool ABI_Tabs_getAutoSize(Tabs::Ptr* self);
	C_ABI int ABI_Tabs_add(Tabs::Ptr* self, char* text, int select);
	C_ABI void ABI_Tabs_insert(Tabs::Ptr* self, int index, char* text, int select);
	C_ABI const char32_t* ABI_Tabs_getText(Tabs::Ptr* self, int index);
	C_ABI bool ABI_Tabs_changeText(Tabs::Ptr* self, int index, char* text);
	C_ABI bool ABI_Tabs_select(Tabs::Ptr* self, char* text);
	C_ABI bool ABI_Tabs_selectByIndex(Tabs::Ptr* self, int index);
	C_ABI void ABI_Tabs_deselect(Tabs::Ptr* self);
	C_ABI bool ABI_Tabs_remove(Tabs::Ptr* self, char* text);
	C_ABI bool ABI_Tabs_removeByIndex(Tabs::Ptr* self, int index);
	C_ABI void ABI_Tabs_removeAll(Tabs::Ptr* self);
	C_ABI const char32_t* ABI_Tabs_getSelected(Tabs::Ptr* self);
	C_ABI int ABI_Tabs_getSelectedIndex(Tabs::Ptr* self);
	C_ABI void ABI_Tabs_setTabVisible(Tabs::Ptr* self, int index, int visible);
	C_ABI bool ABI_Tabs_getTabVisible(Tabs::Ptr* self, int index);
	C_ABI void ABI_Tabs_setTabEnabled(Tabs::Ptr* self, int index, int enabled);
	C_ABI bool ABI_Tabs_getTabEnabled(Tabs::Ptr* self, int index);
	C_ABI void ABI_Tabs_setTabHeight(Tabs::Ptr* self, float height);
	C_ABI void ABI_Tabs_setMaximumTabWidth(Tabs::Ptr* self, float maximumWidth);
	C_ABI float ABI_Tabs_getMaximumTabWidth(Tabs::Ptr* self);
	C_ABI void ABI_Tabs_setMinimumTabWidth(Tabs::Ptr* self, float minimumWidth);
	C_ABI float ABI_Tabs_getMinimumTabWidth(Tabs::Ptr* self);
	C_ABI int ABI_Tabs_getTabsCount(Tabs::Ptr* self);
	C_ABI SignalString* ABI_Tabs_onTabSelect(Tabs::Ptr* self);
	// TabContainer
	C_ABI TabContainer::Ptr* ABI_TabContainer_new();
	C_ABI void ABI_TabContainer_setTabsHeight(TabContainer::Ptr* self, char* height);
	C_ABI Panel::Ptr* ABI_TabContainer_addTab(TabContainer::Ptr* self, char* name, int select);
	C_ABI Panel::Ptr* ABI_TabContainer_insertTab(TabContainer::Ptr* self, int index, char* name, int select);
	C_ABI bool ABI_TabContainer_removeTab(TabContainer::Ptr* self, char* text);
	C_ABI bool ABI_TabContainer_removeTabByIndex(TabContainer::Ptr* self, int index);
	C_ABI void ABI_TabContainer_select(TabContainer::Ptr* self, int index);
	C_ABI int ABI_TabContainer_getPanelCount(TabContainer::Ptr* self);
	C_ABI int ABI_TabContainer_getIndex(TabContainer::Ptr* self, Panel::Ptr* ptr);
	C_ABI Panel::Ptr* ABI_TabContainer_getSelected(TabContainer::Ptr* self);
	C_ABI int ABI_TabContainer_getSelectedIndex(TabContainer::Ptr* self);
	C_ABI Panel::Ptr* ABI_TabContainer_getPanel(TabContainer::Ptr* self, int index);
	C_ABI Tabs::Ptr* ABI_TabContainer_getTabs(TabContainer::Ptr* self);
	C_ABI const char32_t* ABI_TabContainer_getTabText(TabContainer::Ptr* self, int index);
	C_ABI bool ABI_TabContainer_changeTabText(TabContainer::Ptr* self, int index, char* text);
	C_ABI void ABI_TabContainer_setTabAlignment(TabContainer::Ptr* self, int align);
	C_ABI int ABI_TabContainer_getTabAlignment(TabContainer::Ptr* self);
	C_ABI void ABI_TabContainer_setTabFixedSize(TabContainer::Ptr* self, float fixedSize);
	C_ABI float ABI_TabContainer_getTabFixedSize(TabContainer::Ptr* self);
	C_ABI SignalInt* ABI_TabContainer_onSelectionChange(TabContainer::Ptr* self);
	C_ABI SignalTypedIntBoolPtr* ABI_TabContainer_onSelectionChanging(TabContainer::Ptr* self);
	// TextArea
	C_ABI TextArea::Ptr* ABI_TextArea_new();
	C_ABI void ABI_TextArea_setText(TextArea::Ptr* self, char* text);
	C_ABI void ABI_TextArea_addText(TextArea::Ptr* self, char* text);
	C_ABI const char32_t* ABI_TextArea_getText(TextArea::Ptr* self);
	C_ABI void ABI_TextArea_setDefaultText(TextArea::Ptr* self, char* text);
	C_ABI const char32_t* ABI_TextArea_getDefaultText(TextArea::Ptr* self);
	C_ABI void ABI_TextArea_setSelectedText(TextArea::Ptr* self, int selectionStartIndex, int selectionEndIndex);
	C_ABI const char32_t* ABI_TextArea_getSelectedText(TextArea::Ptr* self);
	C_ABI int ABI_TextArea_getSelectionStart(TextArea::Ptr* self);
	C_ABI int ABI_TextArea_getSelectionEnd(TextArea::Ptr* self);
	C_ABI void ABI_TextArea_setMaximumCharacters(TextArea::Ptr* self, int maxChars);
	C_ABI int ABI_TextArea_getMaximumCharacters(TextArea::Ptr* self);
	C_ABI void ABI_TextArea_setTabString(TextArea::Ptr* self, char* tabText);
	C_ABI const char32_t* ABI_TextArea_getTabString(TextArea::Ptr* self);
	C_ABI void ABI_TextArea_setCaretPosition(TextArea::Ptr* self, int charactersBeforeCaret);
	C_ABI int ABI_TextArea_getCaretPosition(TextArea::Ptr* self);
	C_ABI int ABI_TextArea_getCaretLine(TextArea::Ptr* self);
	C_ABI int ABI_TextArea_getCaretColumn(TextArea::Ptr* self);
	C_ABI void ABI_TextArea_setReadOnly(TextArea::Ptr* self, int readOnly);
	C_ABI bool ABI_TextArea_isReadOnly(TextArea::Ptr* self);
	C_ABI int ABI_TextArea_getLinesCount(TextArea::Ptr* self);
	C_ABI void ABI_TextArea_enableMonospacedFontOptimization(TextArea::Ptr* self, int enable);
	C_ABI void ABI_TextArea_setVerticalScrollbarPolicy(TextArea::Ptr* self, int policy);
	C_ABI int ABI_TextArea_getVerticalScrollbarPolicy(TextArea::Ptr* self);
	C_ABI void ABI_TextArea_setHorizontalScrollbarPolicy(TextArea::Ptr* self, int policy);
	C_ABI int ABI_TextArea_getHorizontalScrollbarPolicy(TextArea::Ptr* self);
	C_ABI void ABI_TextArea_setVerticalScrollbarValue(TextArea::Ptr* self, int value);
	C_ABI int ABI_TextArea_getVerticalScrollbarValue(TextArea::Ptr* self);
	C_ABI void ABI_TextArea_setHorizontalScrollbarValue(TextArea::Ptr* self, int value);
	C_ABI int ABI_TextArea_getHorizontalScrollbarValue(TextArea::Ptr* self);
	C_ABI SignalString* ABI_TextArea_onTextChange(TextArea::Ptr* self);
	C_ABI Signal* ABI_TextArea_onSelectionChange(TextArea::Ptr* self);
	C_ABI Signal* ABI_TextArea_onCaretPositionChange(TextArea::Ptr* self);
	// ToggleButton
	C_ABI ToggleButton::Ptr* ABI_ToggleButton_new();
	C_ABI void ABI_ToggleButton_setDown(ToggleButton::Ptr* self, int down);
	C_ABI bool ABI_ToggleButton_isDown(ToggleButton::Ptr* self);
	C_ABI SignalBool* ABI_ToggleButton_onToggle(ToggleButton::Ptr* self);
	// ToolTip
	C_ABI void ABI_STATIC_ToolTip_setInitialDelay(int delay);
	C_ABI int ABI_STATIC_ToolTip_getInitialDelay();
	C_ABI void ABI_STATIC_ToolTip_setDistanceToMouse(float distanceX, float distanceY);
	C_ABI Vector2f* ABI_STATIC_ToolTip_getDistanceToMouse();
	C_ABI void ABI_STATIC_ToolTip_setShowOnDisabledWidget(int show);
	C_ABI bool ABI_STATIC_ToolTip_getShowOnDisabledWidget();
	// TreeView
	C_ABI TreeView::Ptr* ABI_TreeView_new();
	C_ABI bool ABI_TreeView_addItem(TreeView::Ptr* self, int hierarchySize, char*(*f)(void), int createParents);
	C_ABI bool ABI_TreeView_changeItem(TreeView::Ptr* self, int hierarchySize, char*(*f)(void), char* leafText);
	C_ABI void ABI_TreeView_expand(TreeView::Ptr* self, int hierarchySize, char*(*f)(void));
	C_ABI void ABI_TreeView_expandAll(TreeView::Ptr* self);
	C_ABI void ABI_TreeView_collapse(TreeView::Ptr* self, int hierarchySize, char*(*f)(void));
	C_ABI void ABI_TreeView_collapseAll(TreeView::Ptr* self);
	C_ABI bool ABI_TreeView_selectItem(TreeView::Ptr* self, int hierarchySize, char*(*f)(void));
	C_ABI void ABI_TreeView_deselectItem(TreeView::Ptr* self);
	C_ABI bool ABI_TreeView_removeItem(TreeView::Ptr* self, int hierarchySize, char*(*f)(void), int removeParentsWhenEmpty);
	C_ABI void ABI_TreeView_removeAllItems(TreeView::Ptr* self);
	C_ABI void ABI_TreeView_getSelectedItem(TreeView::Ptr* self, void(*f)(const char32_t*));
	C_ABI void ABI_TreeView_getNodes(TreeView::Ptr* self, void(*m)(const char32_t*, int), void(*up)());
	C_ABI void ABI_TreeView_setItemHeight(TreeView::Ptr* self, int itemHeight);
	C_ABI int ABI_TreeView_getItemHeight(TreeView::Ptr* self);
	C_ABI void ABI_TreeView_setVerticalScrollbarValue(TreeView::Ptr* self, int value);
	C_ABI int ABI_TreeView_getVerticalScrollbarValue(TreeView::Ptr* self);
	C_ABI void ABI_TreeView_setHorizontalScrollbarValue(TreeView::Ptr* self, int value);
	C_ABI int ABI_TreeView_getHorizontalScrollbarValue(TreeView::Ptr* self);
	C_ABI SignalItemHierarchy* ABI_TreeView_onItemSelect(TreeView::Ptr* self);
	C_ABI SignalItemHierarchy* ABI_TreeView_onDoubleClick(TreeView::Ptr* self);
	C_ABI SignalItemHierarchy* ABI_TreeView_onExpand(TreeView::Ptr* self);
	C_ABI SignalItemHierarchy* ABI_TreeView_onCollapse(TreeView::Ptr* self);
	C_ABI SignalItemHierarchy* ABI_TreeView_onRightClick(TreeView::Ptr* self);
	// Scrollbar
	C_ABI Scrollbar::Ptr* ABI_Scrollbar_new();
	C_ABI void ABI_Scrollbar_setMaximum(Scrollbar::Ptr* self, int maximum);
	C_ABI int ABI_Scrollbar_getMaximum(Scrollbar::Ptr* self);
	C_ABI void ABI_Scrollbar_setValue(Scrollbar::Ptr* self, int value);
	C_ABI int ABI_Scrollbar_getValue(Scrollbar::Ptr* self);
	C_ABI void ABI_Scrollbar_setViewportSize(Scrollbar::Ptr* self, int viewport);
	C_ABI int ABI_Scrollbar_getViewportSize(Scrollbar::Ptr* self);
	C_ABI void ABI_Scrollbar_setScrollAmount(Scrollbar::Ptr* self, int scrollAmount);
	C_ABI int ABI_Scrollbar_getScrollAmount(Scrollbar::Ptr* self);
	C_ABI void ABI_Scrollbar_setAutoHide(Scrollbar::Ptr* self, int autoHide);
	C_ABI bool ABI_Scrollbar_getAutoHide(Scrollbar::Ptr* self);
	C_ABI void ABI_Scrollbar_setVerticalScroll(Scrollbar::Ptr* self, int vertical);
	C_ABI bool ABI_Scrollbar_getVerticalScroll(Scrollbar::Ptr* self);
	C_ABI float ABI_Scrollbar_getDefaultWidth(Scrollbar::Ptr* self);
	C_ABI SignalUInt* ABI_Scrollbar_onValueChange(Scrollbar::Ptr* self);
	// Canvas
	C_ABI CanvasSFML::Ptr* ABI_Canvas_new();
	C_ABI void ABI_Canvas_clear(CanvasSFML::Ptr* self, Color* color);
	C_ABI void ABI_Canvas_draw(CanvasSFML::Ptr* self, sf::Drawable* drawable);
	C_ABI void ABI_Canvas_display(CanvasSFML::Ptr* self);
	// Shape
	C_ABI void ABI_Shape_setTexture(sf::Shape* self, Texture* texture);
	C_ABI Texture* ABI_Shape_getTexture(sf::Shape* self);
	C_ABI void ABI_Shape_setFillColor(sf::Shape* self, Color* color);
	C_ABI Color* ABI_Shape_getFillColor(sf::Shape* self);
	C_ABI void ABI_Shape_setOutlineColor(sf::Shape* self, Color* color);
	C_ABI Color* ABI_Shape_getOutlineColor(sf::Shape* self);
	C_ABI void ABI_Shape_setOutlineThickness(sf::Shape* self, float thickness);
	C_ABI float ABI_Shape_getOutlineThickness(sf::Shape* self);
	C_ABI void ABI_Shape_setPosition(sf::Shape* self, float x, float y);
	C_ABI Vector2f* ABI_Shape_getPosition(sf::Shape* self);
	C_ABI void ABI_Shape_setRotation(sf::Shape* self, float angle);
	C_ABI float ABI_Shape_getRotation(sf::Shape* self);
	C_ABI void ABI_Shape_setScale(sf::Shape* self, float factorX, float factorY);
	C_ABI Vector2f* ABI_Shape_getScale(sf::Shape* self);
	C_ABI void ABI_Shape_setOrigin(sf::Shape* self, float x, float y);
	C_ABI Vector2f* ABI_Shape_getOrigin(sf::Shape* self);
	C_ABI int ABI_CircleShape_getPointCount(sf::CircleShape* self);
	// CircleShape
	C_ABI sf::CircleShape* ABI_CircleShape_new();
	C_ABI void ABI_STATIC_CircleShape_delete(sf::CircleShape* self);
	C_ABI void ABI_CircleShape_setRadius(sf::CircleShape* self, float radius);
	C_ABI float ABI_CircleShape_getRadius(sf::CircleShape* self);
	C_ABI void ABI_CircleShape_setPointCount(sf::CircleShape* self, int pointCount);
	// RectangleShape
	C_ABI sf::RectangleShape* ABI_RectangleShape_new();
	C_ABI void ABI_STATIC_RectangleShape_delete(sf::RectangleShape* self);
	C_ABI void ABI_RectangleShape_setSize(sf::RectangleShape* self, float width, float height);
	C_ABI Vector2f* ABI_RectangleShape_getSize(sf::RectangleShape* self);
	// ConvexShape
	C_ABI sf::ConvexShape* ABI_ConvexShape_new();
	C_ABI void ABI_STATIC_ConvexShape_delete(sf::ConvexShape* self);
	C_ABI void ABI_ConvexShape_setPoint(sf::ConvexShape* self, int index, float x, float y);
	C_ABI void ABI_ConvexShape_setPointCount(sf::ConvexShape* self, int pointCount);
	// Text
	C_ABI sf::Text* ABI_Text_new();
	C_ABI void ABI_STATIC_Text_delete(sf::Text* self);
	C_ABI void ABI_Text_setString(sf::Text* self, char* string);
	C_ABI const char32_t* ABI_Text_getString(sf::Text* self);
	C_ABI void ABI_Text_setFont(sf::Text* self, Font* font);
	// C_ABI Font* ABI_Text_getFont(sf::Text* self);
	C_ABI void ABI_Text_setCharacterSize(sf::Text* self, int size);
	C_ABI int ABI_Text_getCharacterSize(sf::Text* self);
	C_ABI void ABI_Text_setLineSpacing(sf::Text* self, float spacing);
	C_ABI float ABI_Text_getLineSpacing(sf::Text* self);
	C_ABI void ABI_Text_setLetterSpacing(sf::Text* self, float spacing);
	C_ABI float ABI_Text_getLetterSpacing(sf::Text* self);
	C_ABI void ABI_Text_setStyle(sf::Text* self, int style);
	C_ABI int ABI_Text_getStyle(sf::Text* self);
	C_ABI void ABI_Text_setFillColor(sf::Text* self, Color* color);
	C_ABI Color* ABI_Text_getFillColor(sf::Text* self);
	C_ABI void ABI_Text_setOutlineColor(sf::Text* self, Color* color);
	C_ABI Color* ABI_Text_getOutlineColor(sf::Text* self);
	C_ABI void ABI_Text_setOutlineThickness(sf::Text* self, float thickness);
	C_ABI float ABI_Text_getOutlineThickness(sf::Text* self);
	C_ABI void ABI_Text_setPosition(sf::Text* self, float x, float y);
	C_ABI Vector2f* ABI_Text_getPosition(sf::Text* self);
	C_ABI void ABI_Text_setRotation(sf::Text* self, float angle);
	C_ABI float ABI_Text_getRotation(sf::Text* self);
	C_ABI void ABI_Text_setScale(sf::Text* self, float factorX, float factorY);
	C_ABI Vector2f* ABI_Text_getScale(sf::Text* self);
	C_ABI void ABI_Text_setOrigin(sf::Text* self, float x, float y);
	C_ABI Vector2f* ABI_Text_getOrigin(sf::Text* self);
	C_ABI Vector2f* ABI_Text_findCharacterPos(sf::Text* self, int index);
	// CustomWidget
	C_ABI CustomWidgetForBindings::Ptr* ABI_CustomWidget_new();
	C_ABI void ABI_CustomWidget_implPositionChanged(CustomWidgetForBindings::Ptr* self, void(*f)(float x, float y));
	C_ABI void ABI_CustomWidget_implSizeChanged(CustomWidgetForBindings::Ptr* self, void(*f)(float width, float height));
	C_ABI void ABI_CustomWidget_implVisibleChanged(CustomWidgetForBindings::Ptr* self, void(*f)(int visible));
	C_ABI void ABI_CustomWidget_implEnableChanged(CustomWidgetForBindings::Ptr* self, void(*f)(int enable));
	C_ABI void ABI_CustomWidget_implFocusChanged(CustomWidgetForBindings::Ptr* self, void(*f)(int focus));
	C_ABI void ABI_CustomWidget_implCanGainFocus(CustomWidgetForBindings::Ptr* self, int(*f)(void));
	C_ABI void ABI_CustomWidget_implGetFullSize(CustomWidgetForBindings::Ptr* self, float(*f)(void));
	C_ABI void ABI_CustomWidget_implGetWidgetOffset(CustomWidgetForBindings::Ptr* self, float(*f)(void));
	C_ABI void ABI_CustomWidget_implUpdateTimeFunction(CustomWidgetForBindings::Ptr* self, int(*f)(int time));
	C_ABI void ABI_CustomWidget_implMouseOnWidget(CustomWidgetForBindings::Ptr* self, int(*f)(float x, float y));
	C_ABI void ABI_CustomWidget_implLeftMousePressed(CustomWidgetForBindings::Ptr* self, int(*f)(float x, float y));
	C_ABI void ABI_CustomWidget_implLeftMouseReleased(CustomWidgetForBindings::Ptr* self, void(*f)(float x, float y));
	C_ABI void ABI_CustomWidget_implRightMousePressed(CustomWidgetForBindings::Ptr* self, void(*f)(float x, float y));
	C_ABI void ABI_CustomWidget_implRightMouseReleased(CustomWidgetForBindings::Ptr* self, void(*f)(float x, float y));
	C_ABI void ABI_CustomWidget_implMouseMoved(CustomWidgetForBindings::Ptr* self, void(*f)(float x, float y));
	C_ABI void ABI_CustomWidget_implKeyPressed(CustomWidgetForBindings::Ptr* self, void(*f)(int key, int alt, int control, int shift, int system));
	C_ABI void ABI_CustomWidget_implTextEntered(CustomWidgetForBindings::Ptr* self, void(*f)(int character));
	C_ABI void ABI_CustomWidget_implScrolled(CustomWidgetForBindings::Ptr* self, int(*f)(float delta, float x, float y, int touch));
	C_ABI void ABI_CustomWidget_implMouseNoLongerOnWidget(CustomWidgetForBindings::Ptr* self, void(*f)(void));
	C_ABI void ABI_CustomWidget_implLeftMouseButtonNoLongerDown(CustomWidgetForBindings::Ptr* self, void(*f)(void));
	C_ABI void ABI_CustomWidget_implMouseEnteredWidget(CustomWidgetForBindings::Ptr* self, void(*f)(void));
	C_ABI void ABI_CustomWidget_implMouseLeftWidget(CustomWidgetForBindings::Ptr* self, void(*f)(void));
	C_ABI void ABI_CustomWidget_implRendererChanged(CustomWidgetForBindings::Ptr* self, int(*f)(const char32_t* property));
	C_ABI void ABI_CustomWidget_implDrawFunction(CustomWidgetForBindings::Ptr* self, void(*f)(BackendRenderTarget* target, RenderStates* states));
}
#endif //CABI_HPP