#include <TGUI/Abi/Cabi.hpp>
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>

namespace tgui {

    std::vector<void*> autoclean;

    // Util

    C_ABI_STATIC void ABI_Util_free(void* pointer) {
        delete pointer;
    }

    // Color

    C_ABI_MAKE Color* ABI_Color_new(int r, int g, int b, int a) {
        return new Color(static_cast<uint8_t>(r), static_cast<uint8_t>(g), static_cast<uint8_t>(b), static_cast<uint8_t>(a));
    }

    C_ABI_GETTER int ABI_Color_get_red(Color* self) {
        return static_cast<int>(self->getRed());
    }

    C_ABI_GETTER int ABI_Color_get_green(Color* self) {
        return static_cast<int>(self->getGreen());
    }

    C_ABI_GETTER int ABI_Color_get_blue(Color* self) {
        return static_cast<int>(self->getBlue());
    }

    C_ABI_GETTER int ABI_Color_get_alpha(Color* self) {
        return static_cast<int>(self->getAlpha());
    }

    C_ABI_METHOD Color* ABI_Color_fade(Color* self, float fade) {
        return new Color(Color::applyOpacity(*self, fade));
    }

    // Signal

    C_ABI_RAW int ABI_Signal_connect(Signal* self, void(*f)()) {
        return self->connect(f);
    }

    C_ABI_RAW bool ABI_Signal_disconnect(Signal* self, int f) {
        return self->disconnect(f);
    }

    // SignalString

    C_ABI_RAW int ABI_SignalString_connect(SignalString* self, void(*f)(const char32_t*)) {
        return self->connect([=](const String& str) {
            f(str.data());
            });
    }

    // SignalBool

    C_ABI_RAW int ABI_SignalBool_connect(SignalBool* self, void(*f)(int)) {
        return self->connect(f);
    }

    // SignalInt

    C_ABI_RAW int ABI_SignalInt_connect(SignalInt* self, void(*f)(int)) {
        return self->connect(f);
    }

    // SignalColor

    C_ABI_RAW int ABI_SignalColor_connect(SignalColor* self, void(*f)(void*)) {
        return self->connect([=](Color col) {
            auto color = new Color(col);
            f(color);
            });
    }

    // SignalVector2f

    C_ABI_RAW int ABI_SignalVector2f_connect(SignalVector2f* self, void(*f)(void*)) {
        return self->connect([=](Vector2f vec) {
            auto vector = new Vector2f(vec);
            f(vector);
            });
    }

    // SignalPointer

    C_ABI_RAW int ABI_SignalPointer_connect(SignalTyped<void*>* self, void(*f)(void*)) {
        return self->connect(f);
    }

    // SignalShowEffect

    C_ABI_RAW int ABI_SignalShowEffect_connect(SignalShowEffect* self, void(*f)(int, int)) {
        return self->connect([=](ShowEffectType showEffectType, bool show) {
            f(static_cast<int>(showEffectType), static_cast<int>(show));
            });
    }

    // SignalAnimationType

    C_ABI_RAW int ABI_SignalAnimationType_connect(SignalAnimationType* self, void(*f)(int)) {
        return self->connect([=](AnimationType animationType) {
            f(static_cast<int>(animationType));
            });
    }

    // SignalItem

    C_ABI_RAW int ABI_SignalItem_connect(SignalItem* self, void(*f)(const char32_t*, const char32_t*)) {
        return self->connect([=](const String& str1, const String& str2) {
            f(str1.data(), str2.data());
            });
    }

    // Window

    C_ABI_MAKE sf::RenderWindow* ABI_Window_new() {
#ifdef TGUI_SYSTEM_IOS
        return new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "TGUI example (SFML-Graphics)");
#elif SFML_VERSION_MAJOR >= 3
        return new sf::RenderWindow(sf::VideoMode{ {800, 600} }, "TGUI example (SFML-Graphics)");
#else
        return new sf::RenderWindow({ 800, 600 }, "TGUI example (SFML-Graphics)");
#endif
    }

    C_ABI_METHOD void ABI_Window_close(sf::WindowBase* self) {
        self->close();
    }

    C_ABI_TESTER bool ABI_Window_isOpen(sf::WindowBase* self) {
        return self->isOpen();
    }

    // Gui

    C_ABI_MAKE Gui* ABI_Gui_new(sf::RenderWindow* window) {
        auto gui = new Gui(*window);
        gui->getBackendRenderTarget()->setClearColor(Color(240, 240, 240));
        return gui;
    }

    C_ABI_TESTER bool ABI_Gui_isActive(Gui* self) {
        return self->getWindow()->isOpen();
    }

    C_ABI_METHOD void ABI_Gui_pollEvents(Gui* self) {
        auto window = self->getWindow();
        sf::Event event;
        while (window->pollEvent(event))
        {
            self->handleEvent(event);

            if (event.type == sf::Event::Closed)
                window->close();
        }
    }

    C_ABI_METHOD void ABI_Gui_draw(Gui* self) {
        auto window = self->getWindow();
        self->getBackendRenderTarget()->clearScreen();
        self->draw();
        window->display();
        if (!autoclean.empty()) {
            for (auto& v : autoclean) {
                delete v;
            }
            autoclean.clear();
        }
    }

    C_ABI_METHOD void ABI_Gui_add(Gui* self, Widget::Ptr* widget, const char* name) {
        self->add(*widget, name);
    }

    C_ABI_METHOD void ABI_Gui_remove(Gui* self, Widget::Ptr* widget) {
        self->remove(*widget);
    }

    C_ABI_METHOD void ABI_Gui_removeAll(Gui* self) {
        self->removeAllWidgets();
    }

    C_ABI_METHOD void ABI_Gui_mainLoop(Gui* self) {
        self->mainLoop();
    }

    C_ABI_RAW Widget::Ptr* ABI_Gui_getWidget(Gui* self, const char* name) {
        auto shared = self->get(name);
        if (shared == nullptr) {
            return nullptr;
        }
        auto ptr = new Widget::Ptr(nullptr);
        ptr->swap(shared);
        return ptr;
    }

    // Theme

    C_ABI_STATIC void ABI_Theme_setDefault(char* theme) {
        Theme::setDefault(theme);
    }

    // Widget

    C_ABI_FREE void ABI_Widget_free(std::shared_ptr<Widget>* pointer) {
        (*pointer).reset();
        delete pointer;
    }

    C_ABI_STATIC Widget* ABI_Widget_getUnshared(std::shared_ptr<Widget>* pointer) {
        return &(**pointer);
    }

    C_ABI_STATIC const char32_t* ABI_Widget_getType(Widget::Ptr* self) {
        return (**self).getWidgetType().data();
    }

    C_ABI_GETTER const char32_t* ABI_Widget_getName(Widget::Ptr* self) {
        auto name = new String((**self).getWidgetName());
        autoclean.push_back(name);
        return name->data();
    }

    C_ABI_SETTER void ABI_Widget_setSize(Widget::Ptr* self, const char* width, const char* height) {
        (**self).setSize(width, height);
    }

    C_ABI_GETTER Vector2f* ABI_Widget_getSize(Widget::Ptr* self) {
        return new Vector2f((**self).getSize());
    }

    C_ABI_GETTER Vector2f* ABI_Widget_getFullSize(Widget::Ptr* self) {
        return new Vector2f((**self).getFullSize());
    }

    C_ABI_SETTER void ABI_Widget_setPosition(Widget::Ptr* self, const char* x, const char* y) {
        (**self).setPosition(x, y);
    }

    C_ABI_GETTER Vector2f* ABI_Widget_getPosition(Widget::Ptr* self) {
        return new Vector2f((**self).getPosition());
    }

    C_ABI_GETTER Vector2f* ABI_Widget_getAbsolutePosition(Widget::Ptr* self) {
        return new Vector2f((**self).getAbsolutePosition());
    }

    C_ABI_SETTER void ABI_Widget_setWidth(Widget::Ptr* self, const char* width) {
        (**self).setWidth(width);
    }

    C_ABI_SETTER void ABI_Widget_setHeight(Widget::Ptr* self, const char* height) {
        (**self).setHeight(height);
    }

    C_ABI_SETTER void ABI_Widget_setVisible(Widget::Ptr* self, int visible) {
        (**self).setVisible(visible);
    }

    C_ABI_TESTER bool ABI_Widget_isVisible(Widget::Ptr* self) {
        return (**self).isVisible();
    }

    C_ABI_SETTER void ABI_Widget_setEnabled(Widget::Ptr* self, int enabled) {
        (**self).setEnabled(enabled);
    }

    C_ABI_TESTER bool ABI_Widget_isEnabled(Widget::Ptr* self) {
        return (**self).isEnabled();
    }

    C_ABI_SETTER void ABI_Widget_setFocused(Widget::Ptr* self, int focused) {
        (**self).setFocused(focused);

    }

    C_ABI_TESTER bool ABI_Widget_isFocused(Widget::Ptr* self) {
        return (**self).isFocused();
    }

    C_ABI_SETTER void ABI_Widget_setFocusable(Widget::Ptr* self, int focusable) {
        (**self).setFocusable(focusable);

    }

    C_ABI_TESTER bool ABI_Widget_isFocusable(Widget::Ptr* self) {
        return (**self).isFocusable();
    }

    C_ABI_TESTER bool ABI_Widget_canGainFocus(Widget::Ptr* self) {
        return (**self).canGainFocus();
    }

    C_ABI_TESTER bool ABI_Widget_isContainer(Widget::Ptr* self) {
        return (**self).isContainer();
    }

    C_ABI_SIGNAL SignalVector2f* ABI_Widget_onPositionChange(Widget::Ptr* self) {
        return &(**self).onPositionChange;
    }

    C_ABI_SIGNAL SignalVector2f* ABI_Widget_onSizeChange(Widget::Ptr* self) {
        return &(**self).onSizeChange;
    }

    C_ABI_SIGNAL Signal* ABI_Widget_onFocus(Widget::Ptr* self) {
        return &(**self).onFocus;
    }

    C_ABI_SIGNAL Signal* ABI_Widget_onUnfocus(Widget::Ptr* self) {
        return &(**self).onUnfocus;
    }

    C_ABI_SIGNAL Signal* ABI_Widget_onMouseEnter(Widget::Ptr* self) {
        return &(**self).onMouseEnter;
    }

    C_ABI_SIGNAL Signal* ABI_Widget_onMouseLeave(Widget::Ptr* self) {
        return &(**self).onMouseLeave;
    }

    C_ABI_SIGNAL SignalShowEffect* ABI_Widget_onShowEffectFinish(Widget::Ptr* self) {
        return &(**self).onShowEffectFinish;
    }

    C_ABI_SIGNAL SignalAnimationType* ABI_Widget_onAnimationFinish(Widget::Ptr* self) {
        return &(**self).onAnimationFinish;
    }


    // ClickableWidget

    C_ABI_SIGNAL SignalVector2f* ABI_ClickableWidget_onMousePress(ClickableWidget::Ptr* self) {
        return &(**self).onMousePress;
    }

    C_ABI_SIGNAL SignalVector2f* ABI_ClickableWidget_onMouseRelease(ClickableWidget::Ptr* self) {
        return &(**self).onMouseRelease;
    }

    C_ABI_SIGNAL SignalVector2f* ABI_ClickableWidget_onClick(ClickableWidget::Ptr* self) {
        return &(**self).onClick;
    }

    C_ABI_SIGNAL SignalVector2f* ABI_ClickableWidget_onRightMousePress(ClickableWidget::Ptr* self) {
        return &(**self).onRightMousePress;
    }

    C_ABI_SIGNAL SignalVector2f* ABI_ClickableWidget_onRightMouseRelease(ClickableWidget::Ptr* self) {
        return &(**self).onRightMouseRelease;
    }

    C_ABI_SIGNAL SignalVector2f* ABI_ClickableWidget_onRightClick(ClickableWidget::Ptr* self) {
        return &(**self).onRightClick;
    }

    // ButtonBase

    C_ABI_RAW void ABI_ButtonBase_setTextPosition(ButtonBase::Ptr* self, const char* position, const char* origin) {
        (**self).setTextPosition(position, origin);
    }

    // Button

    C_ABI_MAKE Button::Ptr* ABI_Button_new() {
        auto self = Button::create();
        auto ptr = new Button::Ptr(nullptr);
        ptr->swap(self);
        return ptr;
    }

    C_ABI_SETTER void ABI_Button_setText(Button::Ptr* self, const char* text) {
        (**self).setText(text);
    }

    C_ABI_GETTER const char32_t* ABI_Button_getText(Button::Ptr* self) {
        return (**self).getText().data();
    }

    C_ABI_SIGNAL Signal* ABI_Button_onPress(Button::Ptr* self) {
        return &(**self).onPress;
    }

    // EditBox

    C_ABI_MAKE EditBox::Ptr* ABI_EditBox_new() {
        auto self = EditBox::create();
        auto ptr = new EditBox::Ptr(nullptr);
        ptr->swap(self);
        return ptr;
    }

    C_ABI_SETTER void ABI_EditBox_setText(EditBox::Ptr* self, const char* text) {
        (**self).setText(text);
    }

    C_ABI_GETTER const char32_t* ABI_EditBox_getText(EditBox::Ptr* self) {
        return (**self).getText().data();
    }

    C_ABI_SETTER void ABI_EditBox_setDefaultText(EditBox::Ptr* self, const char* text) {
        (**self).setDefaultText(text);
    }

    C_ABI_GETTER const char32_t* ABI_EditBox_getDefaultText(EditBox::Ptr* self) {
        return (**self).getDefaultText().data();
    }

    C_ABI_METHOD void ABI_EditBox_selectText(EditBox::Ptr* self, int start, int length) {
        (**self).selectText(start, length);
    }

    C_ABI_GETTER const char32_t* ABI_EditBox_getSelectedText(EditBox::Ptr* self) {
        auto text = new String((**self).getSelectedText());
        autoclean.push_back(text);
        return text->data();
    }

    C_ABI_SETTER void ABI_EditBox_setPasswordCharacter(EditBox::Ptr* self, char* character) {
        (**self).setPasswordCharacter(*character);
    }

    C_ABI_GETTER char ABI_EditBox_getPasswordCharacter(EditBox::Ptr* self) {
        return static_cast<char>((**self).getPasswordCharacter());
    }

    C_ABI_SETTER void ABI_EditBox_setMaximumCharacters(EditBox::Ptr* self, unsigned int max) {
        (**self).setMaximumCharacters(max);
    }

    C_ABI_GETTER unsigned int ABI_EditBox_getMaximumCharacters(EditBox::Ptr* self) {
        return (**self).getMaximumCharacters();
    }

    C_ABI_RAW void ABI_EditBox_setAlignment(EditBox::Ptr* self, int alignment) {
        (**self).setAlignment(static_cast<EditBox::Alignment>(alignment));
    }

    C_ABI_RAW int ABI_EditBox_getAlignment(EditBox::Ptr* self) {
        return static_cast<int>((**self).getAlignment());
    }

    C_ABI_SETTER void ABI_EditBox_limitTextWidth(EditBox::Ptr* self, int limit) {
        (**self).limitTextWidth(limit);
    }

    C_ABI_TESTER bool ABI_EditBox_isTextWidthLimited(EditBox::Ptr* self) {
        return (**self).isTextWidthLimited();
    }

    C_ABI_SETTER void ABI_EditBox_setReadOnly(EditBox::Ptr* self, int readOnly) {
        (**self).setReadOnly(readOnly);
    }

    C_ABI_TESTER bool ABI_EditBox_isReadOnly(EditBox::Ptr* self) {
        return (**self).isReadOnly();
    }

    C_ABI_SETTER void ABI_EditBox_setCaretPosition(EditBox::Ptr* self, int caretPosition) {
        (**self).setCaretPosition(caretPosition);
    }
    C_ABI_GETTER int ABI_EditBox_getCaretPosition(EditBox::Ptr* self) {
        return static_cast<int>((**self).getCaretPosition());
    }

    C_ABI_SETTER void ABI_EditBox_setSuffix(EditBox::Ptr* self, char* suffix) {
        (**self).setSuffix(suffix);
    }

    C_ABI_GETTER const char32_t* ABI_EditBox_getSuffix(EditBox::Ptr* self) {
        return (**self).getSuffix().data();
    }

    C_ABI_SIGNAL SignalString* ABI_EditBox_onTextChange(EditBox::Ptr* self) {
        return &(**self).onTextChange;
    }

    C_ABI_SIGNAL SignalString* ABI_EditBox_onReturnKeyPress(EditBox::Ptr* self) {
        return &(**self).onReturnKeyPress;
    }

    C_ABI_SIGNAL SignalString* ABI_EditBox_onReturnOrUnfocus(EditBox::Ptr* self) {
        return &(**self).onReturnOrUnfocus;
    }

    // Label

    C_ABI_MAKE Label::Ptr* ABI_Label_new(char* text) {
        auto self = Label::create(text);
        auto ptr = new Label::Ptr(nullptr);
        ptr->swap(self);
        return ptr;
    }

    C_ABI_SETTER void ABI_Label_setText(Label::Ptr* self, char* text) {
        (**self).setText(text);
    }

    C_ABI_GETTER const char32_t* ABI_Label_getText(Label::Ptr* self) {
        return (**self).getText().data();
    }

    C_ABI_SETTER void ABI_Label_setHorizontalAlignment(Label::Ptr* self, int alignment) {
        (**self).setHorizontalAlignment(static_cast<Label::HorizontalAlignment>(alignment));
    }

    C_ABI_GETTER int ABI_Label_getHorizontalAlignment(Label::Ptr* self) {
        return static_cast<int>((**self).getHorizontalAlignment());
    }

    C_ABI_SETTER void ABI_Label_setVerticalAlignment(Label::Ptr* self, int alignment) {
        (**self).setVerticalAlignment(static_cast<Label::VerticalAlignment>(alignment));
    }

    C_ABI_GETTER int ABI_Label_getVerticalAlignment(Label::Ptr* self) {
        return static_cast<int>((**self).getVerticalAlignment());
    }

    C_ABI_SETTER void ABI_Label_setScrollbarPolicy(Label::Ptr* self, int policy) {
        (**self).setScrollbarPolicy(static_cast<Scrollbar::Policy>(policy));
    }

    C_ABI_GETTER int ABI_Label_getScrollbarPolicy(Label::Ptr* self) {
        return static_cast<int>((**self).getScrollbarPolicy());
    }

    C_ABI_SETTER void ABI_Label_setScrollbarValue(Label::Ptr* self, unsigned int value) {
        (**self).setScrollbarValue(value);
    }

    C_ABI_GETTER int ABI_Label_getScrollbarValue(Label::Ptr* self) {
        return (**self).getScrollbarValue();
    }

    C_ABI_SETTER void ABI_Label_setAutoSize(Label::Ptr* self, int autoSize) {
        (**self).setAutoSize(autoSize);
    }

    C_ABI_GETTER bool ABI_Label_getAutoSize(Label::Ptr* self) {
        return (**self).getAutoSize();
    }

    C_ABI_SETTER void ABI_Label_setMaximumTextWidth(Label::Ptr* self, float maximumWidth) {
        (**self).setMaximumTextWidth(maximumWidth);
    }

    C_ABI_GETTER float ABI_Label_getMaximumTextWidth(Label::Ptr* self) {
        return (**self).getMaximumTextWidth();
    }

    C_ABI_SETTER void ABI_Label_ignoreMouseEvents(Label::Ptr* self, int ignore) {
        (**self).ignoreMouseEvents(ignore);
    }

    C_ABI_TESTER bool ABI_Label_ignoringMouseEvents(Label::Ptr* self) {
        return (**self).isIgnoringMouseEvents();
    }

    // RadioButton

    C_ABI_MAKE RadioButton::Ptr* ABI_RadioButton_new() {
        auto self = RadioButton::create();
        auto ptr = new RadioButton::Ptr(nullptr);
        ptr->swap(self);
        return ptr;
    }

    C_ABI_SETTER void ABI_RadioButton_setText(RadioButton::Ptr* self, char* text) {
        (**self).setText(text);
    }

    C_ABI_GETTER const char32_t* ABI_RadioButton_getText(RadioButton::Ptr* self) {
        return (**self).getText().data();
    }

    C_ABI_SETTER void ABI_RadioButton_setChecked(RadioButton::Ptr* self, int checked) {
        (**self).setChecked(checked);
    }

    C_ABI_TESTER bool ABI_RadioButton_isChecked(RadioButton::Ptr* self) {
        return (**self).isChecked();
    }

    C_ABI_SETTER void ABI_RadioButton_setTextClickable(RadioButton::Ptr* self, int textClickable) {
        (**self).setTextClickable(textClickable);
    }

    C_ABI_TESTER bool ABI_RadioButton_isTextClickable(RadioButton::Ptr* self) {
        return (**self).isTextClickable();
    }

    C_ABI_SIGNAL SignalBool* ABI_RadioButton_onCheck(RadioButton::Ptr* self) {
        return &(**self).onCheck;
    }

    C_ABI_SIGNAL SignalBool* ABI_RadioButton_onUncheck(RadioButton::Ptr* self) {
        return &(**self).onUncheck;
    }

    C_ABI_SIGNAL SignalBool* ABI_RadioButton_onChange(RadioButton::Ptr* self) {
        return &(**self).onChange;
    }

    // CheckBox

    C_ABI_MAKE CheckBox::Ptr* ABI_CheckBox_new() {
        auto self = CheckBox::create();
        auto ptr = new CheckBox::Ptr(nullptr);
        ptr->swap(self);
        return ptr;
    }

    // Container

    C_ABI_RAW void ABI_Container_get_widgets(Container::Ptr* self, void(*f)(Widget::Ptr* widget, const char32_t* type)) {
        for (auto w : (**self).getWidgets()) {
            auto ptr = new Widget::Ptr();
            ptr->swap(w);
            f(ptr, (**ptr).getWidgetType().data());
        }
    }

    C_ABI_METHOD void ABI_Container_add(Container::Ptr* self, Widget::Ptr* widget, char* name) {
        (**self).add(*widget, name);
    }

    C_ABI_RAW Widget::Ptr* ABI_Container_get(Container::Ptr* self, char* name) {
        auto shared = (**self).get(name);
        if (shared == nullptr) {
            return nullptr;
        }
        auto ptr = new Widget::Ptr(nullptr);
        ptr->swap(shared);
        return ptr;
    }

    C_ABI_METHOD bool ABI_Container_remove(Container::Ptr* self, Widget::Ptr* widget) {
        return (**self).remove(*widget);
    }

    C_ABI_METHOD void ABI_Container_removeAllWidgets(Container::Ptr* self) {
        (**self).removeAllWidgets();
    }

    C_ABI_GETTER Vector2f* ABI_Container_getInnerSize(Container::Ptr* self) {
        return new Vector2f((**self).getInnerSize());
    }

    C_ABI_GETTER Vector2f* ABI_Container_getChildWidgetsOffset(Container::Ptr* self) {
        return new Vector2f((**self).getChildWidgetsOffset());
    }

    C_ABI_METHOD void ABI_Container_moveWidgetToFront(Container::Ptr* self, Widget::Ptr* widget) {
        (**self).moveWidgetToFront(*widget);
    }

    C_ABI_METHOD void ABI_Container_moveWidgetToBack(Container::Ptr* self, Widget::Ptr* widget) {
        (**self).moveWidgetToBack(*widget);
    }

    C_ABI_METHOD int ABI_Container_moveWidgetForward(Container::Ptr* self, Widget::Ptr* widget) {
        return static_cast<int>((**self).moveWidgetForward(*widget));
    }

    C_ABI_METHOD int ABI_Container_moveWidgetBackward(Container::Ptr* self, Widget::Ptr* widget) {
        return static_cast<int>((**self).moveWidgetBackward(*widget));
    }

    C_ABI_SETTER bool ABI_Container_setWidgetIndex(Container::Ptr* self, Widget::Ptr* widget, int index) {
        return (**self).setWidgetIndex(*widget, index);
    }

    C_ABI_GETTER int ABI_Container_getWidgetIndex(Container::Ptr* self, Widget::Ptr* widget) {
        return (**self).getWidgetIndex(*widget);
    }

    C_ABI_GETTER Widget::Ptr* ABI_Container_getFocusedChild(Container::Ptr* self) {
        auto shared = (**self).getFocusedChild();
        if (shared == nullptr) {
            return nullptr;
        }
        auto ptr = new Widget::Ptr(nullptr);
        ptr->swap(shared);
        return ptr;
    }

    C_ABI_GETTER Widget::Ptr* ABI_Container_getFocusedLeaf(Container::Ptr* self) {
        auto shared = (**self).getFocusedLeaf();
        if (shared == nullptr) {
            return nullptr;
        }
        auto ptr = new Widget::Ptr(nullptr);
        ptr->swap(shared);
        return ptr;
    }

    C_ABI_GETTER Widget::Ptr* ABI_Container_getWidgetAtPosition(Container::Ptr* self, float x, float y) {
        Vector2f v(x, y);
        auto shared = (**self).getWidgetAtPosition(v);
        if (shared == nullptr) {
            return nullptr;
        }
        auto ptr = new Widget::Ptr(nullptr);
        ptr->swap(shared);
        return ptr;
    }

    C_ABI_METHOD bool ABI_Container_focusNextWidget(Container::Ptr* self, int recursive) {
        return (**self).focusNextWidget(recursive);
    }

    C_ABI_METHOD bool ABI_Container_focusPreviousWidget(Container::Ptr* self, int recursive) {
        return (**self).focusPreviousWidget(recursive);
    }

    C_ABI_SETTER void ABI_Container_setFocused(Container::Ptr* self, int focused) {
        (**self).setFocused(focused);
    }

    // ChildWindow

    C_ABI_MAKE ChildWindow::Ptr* ABI_ChildWindow_new() {
        auto self = ChildWindow::create();
        auto ptr = new ChildWindow::Ptr(nullptr);
        ptr->swap(self);
        return ptr;
    }

    C_ABI_SETTER void ABI_ChildWindow_setClientSize(ChildWindow::Ptr* self, char* size) {
        (**self).setClientSize(size);
    }

    C_ABI_GETTER Vector2f* ABI_ChildWindow_getClientSize(ChildWindow::Ptr* self) {
        return new Vector2f((**self).getClientSize());
    }

    C_ABI_SETTER void ABI_ChildWindow_setMaximumSize(ChildWindow::Ptr* self, float x, float y) {
        (**self).setMaximumSize(Vector2f(x, y));
    }

    C_ABI_GETTER Vector2f* ABI_ChildWindow_getMaximumSize(ChildWindow::Ptr* self) {
        return new Vector2f((**self).getMaximumSize());
    }

    C_ABI_SETTER void ABI_ChildWindow_setMinimumSize(ChildWindow::Ptr* self, float x, float y) {
        (**self).setMinimumSize(Vector2f(x, y));
    }

    C_ABI_GETTER Vector2f* ABI_ChildWindow_getMinimumSize(ChildWindow::Ptr* self) {
        return new Vector2f((**self).getMinimumSize());
    }

    C_ABI_SETTER void ABI_ChildWindow_setTitle(ChildWindow::Ptr* self, char* title) {
        (**self).setTitle(title);
    }

    C_ABI_GETTER const char32_t* ABI_ChildWindow_getTitle(ChildWindow::Ptr* self) {
        return (**self).getTitle().data();
    }

    C_ABI_SETTER void ABI_ChildWindow_setTitleTextSize(ChildWindow::Ptr* self, unsigned int size) {
        (**self).setTitleTextSize(size);
    }

    C_ABI_GETTER unsigned int ABI_ChildWindow_getTitleTextSize(ChildWindow::Ptr* self) {
        return (**self).getTitleTextSize();
    }

    C_ABI_RAW void ABI_ChildWindow_setTitleAlignment(ChildWindow::Ptr* self, int alignment) {
        (**self).setTitleAlignment(static_cast<ChildWindow::TitleAlignment>(alignment));
    }

    C_ABI_RAW int ABI_ChildWindow_getTitleAlignment(ChildWindow::Ptr* self) {
        return static_cast<int>((**self).getTitleAlignment());
    }

    C_ABI_RAW void ABI_ChildWindow_setTitleButtons(ChildWindow::Ptr* self, unsigned int buttons) {
        (**self).setTitleButtons(buttons);
    }

    C_ABI_RAW unsigned int ABI_ChildWindow_getTitleButtons(ChildWindow::Ptr* self) {
        return (**self).getTitleButtons();
    }

    C_ABI_METHOD void ABI_ChildWindow_close(ChildWindow::Ptr* self) {
        (**self).close();
    }

    C_ABI_METHOD void ABI_ChildWindow_destroy(ChildWindow::Ptr* self) {
        (**self).destroy();
    }

    C_ABI_SETTER void ABI_ChildWindow_setResizable(ChildWindow::Ptr* self, int resizable) {
        (**self).setResizable(resizable);
    }

    C_ABI_TESTER bool ABI_ChildWindow_isResizable(ChildWindow::Ptr* self) { 
        return (**self).isResizable();
    }

    C_ABI_SETTER void ABI_ChildWindow_setPositionLocked(ChildWindow::Ptr* self, int positionLocked) {
        (**self).setPositionLocked(positionLocked);
    }

    C_ABI_TESTER bool ABI_ChildWindow_isPositionLocked(ChildWindow::Ptr* self) {
        return (**self).isPositionLocked();
    }

    C_ABI_SETTER void ABI_ChildWindow_setKeepInParent(ChildWindow::Ptr* self, int enabled) {
        (**self).setKeepInParent(enabled);
    }

    C_ABI_TESTER bool ABI_ChildWindow_isKeptInParent(ChildWindow::Ptr* self) {
        return (**self).isKeptInParent();
    }

    C_ABI_SIGNAL Signal* ABI_ChildWindow_onMousePress(ChildWindow::Ptr* self) {
        return &(**self).onMousePress;
    }

    C_ABI_SIGNAL Signal* ABI_ChildWindow_onClose(ChildWindow::Ptr* self) {
        return &(**self).onClose;
    }

    C_ABI_SIGNAL Signal* ABI_ChildWindow_onMinimize(ChildWindow::Ptr* self) {
        return &(**self).onMinimize;
    }

    C_ABI_SIGNAL Signal* ABI_ChildWindow_onMaximize(ChildWindow::Ptr* self) {
        return &(**self).onMaximize;
    }

    C_ABI_SIGNAL Signal* ABI_ChildWindow_onEscapeKeyPress(ChildWindow::Ptr* self) {
        return &(**self).onEscapeKeyPress;
    }

    C_ABI_SIGNAL SignalTyped<bool*>* ABI_ChildWindow_onClosing(ChildWindow::Ptr* self) {
        return &(**self).onClosing;
    }

    // Group

    C_ABI_MAKE Group::Ptr* ABI_Group_new() {
        auto self = Group::create();
        auto ptr = new Group::Ptr(nullptr);
        ptr->swap(self);
        return ptr;
    }

    // BoxLayout

    C_ABI_RAW Widget::Ptr* ABI_BoxLayout_getByIndex(BoxLayout::Ptr* self, int index) {
        auto widget = (**self).get(index);
        auto ptr = new Widget::Ptr(nullptr);
        ptr->swap(widget);
        return ptr;
    }

    C_ABI_METHOD void ABI_BoxLayout_insert(BoxLayout::Ptr* self, int index, Widget::Ptr* widget, char* name) {
        (**self).insert(index, *widget, name);
    }

    C_ABI_RAW bool ABI_BoxLayout_removeByIndex(BoxLayout::Ptr* self, int index) {
        return (**self).remove(index);
    }

    // BoxLayoutRatios

    C_ABI_METHOD void ABI_BoxLayoutRatios_addSpace(BoxLayoutRatios::Ptr* self, float ratio) {
        (**self).addSpace(ratio);
    }

    C_ABI_METHOD void ABI_BoxLayoutRatios_insertSpace(BoxLayoutRatios::Ptr* self, int index, float ratio) {
        (**self).insertSpace(index, ratio);
    }

    C_ABI_RAW void ABI_BoxLayoutRatios_setRatio(BoxLayoutRatios::Ptr* self, Widget::Ptr* widget, float ratio) {
        (**self).setRatio(*widget, ratio);
    }

    C_ABI_RAW void ABI_BoxLayoutRatios_setRatioByIndex(BoxLayoutRatios::Ptr* self, int index, float ratio) {
        (**self).setRatio(index, ratio);
    }

    C_ABI_RAW float ABI_BoxLayoutRatios_getRatio(BoxLayoutRatios::Ptr* self, Widget::Ptr* widget) {
        return (**self).getRatio(*widget);
    }

    C_ABI_RAW float ABI_BoxLayoutRatios_getRatioByIndex(BoxLayoutRatios::Ptr* self, int index) {
        return (**self).getRatio(index);
    }

    // HorizontalLayout

    C_ABI_MAKE HorizontalLayout::Ptr* ABI_HorizontalLayout_create() {
        auto layout = HorizontalLayout::create();
        auto ptr = new HorizontalLayout::Ptr(nullptr);
        ptr->swap(layout);
        return ptr;
    }

    // VerticalLayout

    C_ABI_MAKE VerticalLayout::Ptr* ABI_VerticalLayout_create() {
        auto layout = VerticalLayout::create();
        auto ptr = new VerticalLayout::Ptr(nullptr);
        ptr->swap(layout);
        return ptr;
    }

    // HorizontalWrap

    C_ABI_MAKE HorizontalWrap::Ptr* ABI_HorizontalWrap_create() {
        auto layout = HorizontalWrap::create();
        auto ptr = new HorizontalWrap::Ptr(nullptr);
        ptr->swap(layout);
        return ptr;
    }

    // RadioButtonGroup

    C_ABI_MAKE RadioButtonGroup::Ptr* ABI_RadioButtonGroup_create() {
        auto group = RadioButtonGroup::create();
        auto ptr = new RadioButtonGroup::Ptr(nullptr);
        ptr->swap(group);
        return ptr;
    }

    C_ABI_METHOD void ABI_RadioButtonGroup_uncheckRadioButtons(RadioButtonGroup::Ptr* self) {
        (**self).uncheckRadioButtons();
    }

    C_ABI_GETTER RadioButton::Ptr* ABI_RadioButtonGroup_getCheckedRadioButton(RadioButtonGroup::Ptr* self) {
        auto button = (**self).getCheckedRadioButton();
        if (button == nullptr) {
            return nullptr;
        }
        auto ptr = new RadioButton::Ptr(nullptr);
        ptr->swap(button);
        return ptr;
    }

    // Panel

    C_ABI_MAKE Panel::Ptr* ABI_Panel_create() {
        auto panel = Panel::create();
        auto ptr = new Panel::Ptr(nullptr);
        ptr->swap(panel);
        return ptr;
    }

    C_ABI_SIGNAL SignalVector2f* ABI_Panel_onMousePress(Panel::Ptr* self) {
        return &(**self).onMousePress;
    }

    C_ABI_SIGNAL SignalVector2f* ABI_Panel_onMouseRelease(Panel::Ptr* self) {
        return &(**self).onMouseRelease;
    }

    C_ABI_SIGNAL SignalVector2f* ABI_Panel_onClick(Panel::Ptr* self) {
        return &(**self).onClick;
    }

    C_ABI_SIGNAL SignalVector2f* ABI_Panel_onDoubleClick(Panel::Ptr* self) {
        return &(**self).onDoubleClick;
    }

    C_ABI_SIGNAL SignalVector2f* ABI_Panel_onRightMousePress(Panel::Ptr* self) {
        return &(**self).onRightMousePress;
    }

    C_ABI_SIGNAL SignalVector2f* ABI_Panel_onRightMouseRelease(Panel::Ptr* self) {
        return &(**self).onRightMouseRelease;
    }

    C_ABI_SIGNAL SignalVector2f* ABI_Panel_onRightClick(Panel::Ptr* self) {
        return &(**self).onRightClick;
    }

    // ScrollablePanel

    C_ABI_MAKE ScrollablePanel::Ptr* ABI_ScrollablePanel_create() {
        auto panel = ScrollablePanel::create();
        auto ptr = new ScrollablePanel::Ptr(nullptr);
        ptr->swap(panel);
        return ptr;
    }

    C_ABI_SETTER void ABI_ScrollablePanel_setContentSize(ScrollablePanel::Ptr* self, float x, float y) {
        (**self).setContentSize(Vector2f(x, y));
    }

    C_ABI_GETTER Vector2f* ABI_ScrollablePanel_getContentSize(ScrollablePanel::Ptr* self) {
        return new Vector2f((**self).getContentSize());
    }

    C_ABI_GETTER Vector2f* ABI_ScrollablePanel_getContentOffset(ScrollablePanel::Ptr* self) {
        return new Vector2f((**self).getContentOffset());
    }

    C_ABI_GETTER float ABI_ScrollablePanel_getScrollbarWidth(ScrollablePanel::Ptr* self) {
        return (**self).getScrollbarWidth();
    }

    C_ABI_SETTER void ABI_ScrollablePanel_setVerticalScrollbarPolicy(ScrollablePanel::Ptr* self, int policy) {
        (**self).setVerticalScrollbarPolicy(static_cast<Scrollbar::Policy>(policy));
    }

    C_ABI_GETTER int ABI_ScrollablePanel_getVerticalScrollbarPolicy(ScrollablePanel::Ptr* self) {
        return static_cast<int>((**self).getVerticalScrollbarPolicy());
    }

    C_ABI_SETTER void ABI_ScrollablePanel_setHorizontalScrollbarPolicy(ScrollablePanel::Ptr* self, int policy) {
        (**self).setHorizontalScrollbarPolicy(static_cast<Scrollbar::Policy>(policy));
    }

    C_ABI_GETTER int ABI_ScrollablePanel_getHorizontalScrollbarPolicy(ScrollablePanel::Ptr* self) {
        return static_cast<int>((**self).getHorizontalScrollbarPolicy());
    }

    C_ABI_SETTER void ABI_ScrollablePanel_setVerticalScrollAmount(ScrollablePanel::Ptr* self, int amount) {
        (**self).setVerticalScrollAmount(amount);
    }

    C_ABI_GETTER int ABI_ScrollablePanel_getVerticalScrollAmount(ScrollablePanel::Ptr* self) {
        return static_cast<int>((**self).getVerticalScrollAmount());
    }

    C_ABI_SETTER void ABI_ScrollablePanel_setHorizontalScrollAmount(ScrollablePanel::Ptr* self, int amount) {
        (**self).setHorizontalScrollAmount(amount);
    }

    C_ABI_GETTER int ABI_ScrollablePanel_getHorizontalScrollAmount(ScrollablePanel::Ptr* self) {
        return static_cast<int>((**self).getHorizontalScrollAmount());
    }

    C_ABI_SETTER void ABI_ScrollablePanel_setVerticalScrollbarValue(ScrollablePanel::Ptr* self, int value) {
        (**self).setVerticalScrollbarValue(value);
    }

    C_ABI_GETTER int ABI_ScrollablePanel_getVerticalScrollbarValue(ScrollablePanel::Ptr* self) {
        return static_cast<int>((**self).getVerticalScrollbarValue());
    }

    C_ABI_SETTER void ABI_ScrollablePanel_setHorizontalScrollbarValue(ScrollablePanel::Ptr* self, int value) {
        (**self).setHorizontalScrollbarValue(value);
    }

    C_ABI_GETTER int ABI_ScrollablePanel_getHorizontalScrollbarValue(ScrollablePanel::Ptr* self) {
        return static_cast<int>((**self).getHorizontalScrollbarValue());
    }

    // Grid

    C_ABI_MAKE Grid::Ptr* ABI_Grid_make() {
        auto grid = Grid::create();
        auto ptr = new Grid::Ptr(nullptr);
        ptr->swap(grid);
        return ptr;
    }

	C_ABI_SETTER void ABI_Grid_setAutoSize(Grid::Ptr* self, int autoSize) {
        (**self).setAutoSize(autoSize);
    }

	C_ABI_TESTER bool ABI_Grid_isAutoSize(Grid::Ptr* self) {
        return (**self).getAutoSize();
    }

	C_ABI_RAW bool ABI_Grid_setWidgetCell(Grid::Ptr* self, Widget::Ptr* widget, int row, int column) {
        auto alignment = (**self).getWidgetAlignment(row, column);
        auto padding = (**self).getWidgetPadding(row, column);
        return (**self).setWidgetCell(*widget, row, column, alignment, padding);
    }

	C_ABI_RAW Widget::Ptr* ABI_Grid_getWidget(Grid::Ptr* self, int row, int column) {
        auto widget = (**self).getWidget(row, column);
        auto ptr = new Widget::Ptr(nullptr);
        ptr->swap(widget);
        return ptr;
    }

	C_ABI_RAW void ABI_Grid_setWidgetPadding(Grid::Ptr* self, Widget::Ptr* widget, char* paddingLeft, char* paddingRight, char* paddingTop, char* paddingBottom) {
        (**self).setWidgetPadding(*widget, Padding(paddingLeft, paddingRight, paddingTop, paddingBottom));
    }

	C_ABI_RAW Outline* ABI_Grid_getWidgetPadding(Grid::Ptr* self, Widget::Ptr* widget) {
        auto o = (**self).getWidgetPadding(*widget);
        return new Padding(o.getLeft(), o.getRight(), o.getTop(), o.getBottom());
    }

	C_ABI_RAW void ABI_Grid_setWidgetAlignment(Grid::Ptr* self, Widget::Ptr* widget, int alignment) {
        (**self).setWidgetAlignment(*widget, static_cast<Grid::Alignment>(alignment));
    }

	C_ABI_RAW int ABI_Grid_getWidgetAlignment(Grid::Ptr* self, Widget::Ptr* widget) {
        return static_cast<int>((**self).getWidgetAlignment(*widget));
    }

    // ListView

	C_ABI_MAKE ListView::Ptr* ABI_ListView_make() {
        auto view = ListView::create();
        auto ptr = new ListView::Ptr(nullptr);
        ptr->swap(view);
        return ptr;
    }

	C_ABI_METHOD int ABI_ListView_addColumn(ListView::Ptr* self) {
        return static_cast<int>((**self).addColumn(""));
    }

	C_ABI_SETTER void ABI_ListView_setColumnText(ListView::Ptr* self, int index, char* text) {
        (**self).setColumnText(index, text);
    }

	C_ABI_GETTER const char32_t* ABI_ListView_getColumnText(ListView::Ptr* self, int index) {
        auto str = new String((**self).getColumnText(index));
        autoclean.push_back(str);
        return str->data();
    }

	C_ABI_SETTER void ABI_ListView_setColumnWidth(ListView::Ptr* self, int index, float width) {
        (**self).setColumnWidth(index, width);
    }

	C_ABI_GETTER float ABI_ListView_getColumnWidth(ListView::Ptr* self, int index) {
        return (**self).getColumnWidth(index);
    }

	C_ABI_RAW void ABI_ListView_setColumnAlignment(ListView::Ptr* self, int index, int columnAlignment) {
        (**self).setColumnAlignment(index, static_cast<ListView::ColumnAlignment>(columnAlignment));
    }

	C_ABI_RAW int ABI_ListView_getColumnAlignment(ListView::Ptr* self, int index) {
        return static_cast<int>((**self).getColumnAlignment(index));
    }

	C_ABI_METHOD void ABI_ListView_removeAllColumns(ListView::Ptr* self) {
        (**self).removeAllColumns();
    }

	C_ABI_GETTER int ABI_ListView_getColumnCount(ListView::Ptr* self) {
        return static_cast<int>((**self).getColumnCount());
    }

	C_ABI_SETTER void ABI_ListView_setHeaderHeight(ListView::Ptr* self, float height) {
        (**self).setHeaderHeight(height);
    }

	C_ABI_GETTER float ABI_ListView_getHeaderHeight(ListView::Ptr* self) {
        return (**self).getHeaderHeight();
    }

	C_ABI_GETTER float ABI_ListView_getCurrentHeaderHeight(ListView::Ptr* self) {
        return (**self).getCurrentHeaderHeight();
    }

	C_ABI_SETTER void ABI_ListView_setHeaderVisible(ListView::Ptr* self, int showHeader) {
        (**self).setHeaderVisible(showHeader);
    }

	C_ABI_TESTER bool ABI_ListView_headerVisible(ListView::Ptr* self) {
        return (**self).getHeaderVisible();
    }

	C_ABI_RAW int ABI_ListView_addItem(ListView::Ptr* self, char*(*f)(void)) {
        auto columnsCount = (**self).getColumnCount();
        std::vector<String> vec;
        for(int i = 0;i < columnsCount; ++i) {
            vec.push_back(f());
        }
        return static_cast<int>((**self).addItem(vec));
    }

	C_ABI_RAW void ABI_ListView_insertItem(ListView::Ptr* self, int index, char*(*f)(void)) {
        auto columnsCount = (**self).getColumnCount();
        std::vector<String> vec;
        for(int i = 0;i < columnsCount; ++i) {
            vec.push_back(f());
        }
        (**self).insertItem(index, vec);
    }

	C_ABI_RAW bool ABI_ListView_changeItem(ListView::Ptr* self, int index, char*(*f)(void)) {
        auto columnsCount = (**self).getColumnCount();
        std::vector<String> vec;
        for(int i = 0;i < columnsCount; ++i) {
            vec.push_back(f());
        }
        return (**self).changeItem(index, vec);
    }

	C_ABI_RAW bool ABI_ListView_changeSubitem(ListView::Ptr* self, int index, int column, char* item) {
        return (**self).changeSubItem(index, column, item);
    }

	C_ABI_RAW bool ABI_ListView_removeItem(ListView::Ptr* self, int index) {
        return (**self).removeItem(index);
    }

	C_ABI_METHOD void ABI_ListView_removeAllItems(ListView::Ptr* self) {
        (**self).removeAllItems();
    }

	C_ABI_SETTER void ABI_ListView_setSelectedItem(ListView::Ptr* self, int index) {
        (**self).setSelectedItem(index);
    }

	C_ABI_RAW void ABI_ListView_setSelectedItems(ListView::Ptr* self, int(*f)(void)) {
        std::set<std::size_t> indices;
        int index = f();
        while(index >= 0) {
            indices.insert(index);
            index = f();
        }
        (**self).setSelectedItems(indices);
    }

	C_ABI_METHOD void ABI_ListView_deselectItems(ListView::Ptr* self) {
        (**self).deselectItems();
    }

	C_ABI_GETTER int ABI_ListView_getSelectedItemIndex(ListView::Ptr* self) {
        return (**self).getSelectedItemIndex();
    }

	C_ABI_RAW void ABI_ListView_getSelectedItemIndices(ListView::Ptr* self, void(*f)(int)) {
        auto indices = (**self).getSelectedItemIndices();
        for(auto index : indices) {
            f(static_cast<int>(index));
        }
    }

	C_ABI_SETTER void ABI_ListView_setMultiSelect(ListView::Ptr* self, int multiSelect) {
        (**self).setMultiSelect(multiSelect);
    }

	C_ABI_TESTER bool ABI_ListView_multiSelect(ListView::Ptr* self) {
        return (**self).getMultiSelect();
    }

	C_ABI_SETTER void ABI_ListView_setItemIcon(ListView::Ptr* self, int index, Texture* texture) {
        (**self).setItemIcon(index, *texture);
    }

	C_ABI_GETTER Texture* ABI_ListView_getItemIcon(ListView::Ptr* self, int index) {
        return new Texture((**self).getItemIcon(index));
    }

	C_ABI_GETTER int ABI_ListView_getItemCount(ListView::Ptr* self) {
        return static_cast<int>((**self).getItemCount());
    }

	C_ABI_RAW void ABI_ListView_getItemRow(ListView::Ptr* self, int index, void(*f)(const char32_t*)) {
        auto row = (**self).getItemRow(index);
        for(auto text : row) {
            f(text.data());
        }
    }

	C_ABI_GETTER const char32_t* ABI_ListView_getItemCell(ListView::Ptr* self, int rowIndex, int columnIndex) {
        auto cell = new String((**self).getItemCell(rowIndex, columnIndex));
        autoclean.push_back(cell);
        return cell->data();
    }

	C_ABI_RAW void ABI_ListView_getItemRows(ListView::Ptr* self, void(*f)(const char32_t*, int row)) {
        auto rows = (**self).getItemRows();
        int rowIndex = 0;
        for(auto row : rows) {
            for(auto text : row) {
                f(text.data(), rowIndex);
            }
            ++rowIndex;
        }
    }

	C_ABI_SETTER void ABI_ListView_setItemHeight(ListView::Ptr* self, int itemHeight) {
        (**self).setItemHeight(itemHeight);
    }

	C_ABI_GETTER int ABI_ListView_getItemHeight(ListView::Ptr* self) {
        return (**self).getItemHeight();
    }

	C_ABI_SETTER void ABI_ListView_setHeaderTextSize(ListView::Ptr* self, int textSize) {
        (**self).setHeaderTextSize(textSize);
    }

	C_ABI_GETTER int ABI_ListView_getHeaderTextSize(ListView::Ptr* self) {
        return (**self).getHeaderTextSize();
    }

	C_ABI_SETTER void ABI_ListView_setSeparatorWidth(ListView::Ptr* self, int width) {
        (**self).setSeparatorWidth(width);
    }

	C_ABI_GETTER int ABI_ListView_getSeparatorWidth(ListView::Ptr* self) {
        return (**self).getSeparatorWidth();
    }

	C_ABI_SETTER void ABI_ListView_setHeaderSeparatorHeight(ListView::Ptr* self, int height) {
        (**self).setHeaderSeparatorHeight(height);
    }

	C_ABI_GETTER int ABI_ListView_getHeaderSeparatorHeight(ListView::Ptr* self) {
        return (**self).getHeaderSeparatorHeight();
    }

	C_ABI_SETTER void ABI_ListView_setGridLinesWidth(ListView::Ptr* self, int width) {
        (**self).setGridLinesWidth(width);
    }

	C_ABI_GETTER int ABI_ListView_getGridLinesWidth(ListView::Ptr* self) {
        return (**self).getGridLinesWidth();
    }

	C_ABI_SETTER void ABI_ListView_setAutoScroll(ListView::Ptr* self, int autoScroll) {
        (**self).setAutoScroll(autoScroll);
    }

	C_ABI_TESTER bool ABI_ListView_autoScroll(ListView::Ptr* self) {
        return (**self).getAutoScroll();
    }

	C_ABI_SETTER void ABI_ListView_setShowVerticalGridLines(ListView::Ptr* self, int showGridLines) {
        (**self).setShowVerticalGridLines(showGridLines);
    }

	C_ABI_TESTER bool ABI_ListView_showVerticalGridLines(ListView::Ptr* self) {
        return (**self).getShowVerticalGridLines();
    }

	C_ABI_SETTER void ABI_ListView_setShowHorizontalGridLines(ListView::Ptr* self, int showGridLines) {
        (**self).setShowHorizontalGridLines(showGridLines);
    }

	C_ABI_TESTER bool ABI_ListView_showHorizontalGridLines(ListView::Ptr* self) {
        return (**self).getShowHorizontalGridLines();
    }

	C_ABI_SETTER void ABI_ListView_setExpandLastColumn(ListView::Ptr* self, int expand) {
        (**self).setExpandLastColumn(expand);
    }

	C_ABI_TESTER bool ABI_ListView_expandLastColumn(ListView::Ptr* self) {
        return (**self).getExpandLastColumn();
    }

	C_ABI_SETTER void ABI_ListView_setVerticalScrollbarPolicy(ListView::Ptr* self, int policy) {
        (**self).setVerticalScrollbarPolicy(static_cast<Scrollbar::Policy>(policy));
    }

	C_ABI_GETTER int ABI_ListView_getVerticalScrollbarPolicy(ListView::Ptr* self) {
        return static_cast<int>((**self).getVerticalScrollbarPolicy());
    }

	C_ABI_SETTER void ABI_ListView_setHorizontalScrollbarPolicy(ListView::Ptr* self, int policy) {
        (**self).setHorizontalScrollbarPolicy(static_cast<Scrollbar::Policy>(policy));
    }

	C_ABI_GETTER int ABI_ListView_getHorizontalScrollbarPolicy(ListView::Ptr* self) {
        return static_cast<int>((**self).getHorizontalScrollbarPolicy());
    }

	C_ABI_SETTER void ABI_ListView_setVerticalScrollbarValue(ListView::Ptr* self, int value) {
        (**self).setVerticalScrollbarValue(value);
    }

	C_ABI_GETTER int ABI_ListView_getVerticalScrollbarValue(ListView::Ptr* self) {
        return (**self).getVerticalScrollbarValue();
    }

	C_ABI_SETTER void ABI_ListView_setHorizontalScrollbarValue(ListView::Ptr* self, int value) {
        (**self).setHorizontalScrollbarValue(value);
    }

	C_ABI_GETTER int ABI_ListView_getHorizontalScrollbarValue(ListView::Ptr* self) {
        return (**self).getHorizontalScrollbarValue();
    }

	C_ABI_SETTER void ABI_ListView_setFixedIconSize(ListView::Ptr* self, float width, float height) {
        (**self).setFixedIconSize(Vector2f(width, height));
    }

	C_ABI_GETTER Vector2f* ABI_ListView_getFixedIconSize(ListView::Ptr* self) {
        return new Vector2f((**self).getFixedIconSize());
    }

	C_ABI_SETTER void ABI_ListView_setResizableColumns(ListView::Ptr* self, int resizable) {
        (**self).setResizableColumns(resizable);
    }

	C_ABI_TESTER bool ABI_ListView_resizableColumns(ListView::Ptr* self) {
        return (**self).getResizableColumns();
    }

	C_ABI_SIGNAL SignalInt* ABI_ListView_onItemSelect(ListView::Ptr* self) {
        return &(**self).onItemSelect;
    }

	C_ABI_SIGNAL SignalInt* ABI_ListView_onDoubleClick(ListView::Ptr* self) {
        return &(**self).onDoubleClick;
    }

	C_ABI_SIGNAL SignalInt* ABI_ListView_onRightClick(ListView::Ptr* self) {
        return &(**self).onRightClick;
    }

	C_ABI_SIGNAL SignalInt* ABI_ListView_onHeaderClick(ListView::Ptr* self) {
        return &(**self).onHeaderClick;
    }

    // ComboBox

	C_ABI_MAKE ComboBox::Ptr* ABI_ComboBox_make() {
        auto combo = ComboBox::create();
        auto ptr = new ComboBox::Ptr(nullptr);
        ptr->swap(combo);
        return ptr;
    }

	C_ABI_SETTER void ABI_ComboBox_setItemsToDisplay(ComboBox::Ptr* self, int itemsToDisplay) {
        (**self).setItemsToDisplay(itemsToDisplay);
    }

	C_ABI_GETTER int ABI_ComboBox_getItemsToDisplay(ComboBox::Ptr* self) {
        return static_cast<int>((**self).getItemsToDisplay());
    }

	C_ABI_METHOD void ABI_ComboBox_addItem(ComboBox::Ptr* self, char* name, char* id) {
        (**self).addItem(name, id);
    }

	C_ABI_RAW bool ABI_ComboBox_setSelectedItemById(ComboBox::Ptr* self, char* id) {
        return (**self).setSelectedItemById(id);
    }

	C_ABI_RAW bool ABI_ComboBox_setSelectedItemByIndex(ComboBox::Ptr* self, int index) {
        return (**self).setSelectedItemByIndex(index);
    }

	C_ABI_METHOD void ABI_ComboBox_deselectItem(ComboBox::Ptr* self) {
        (**self).deselectItem();
    }

	C_ABI_RAW bool ABI_ComboBox_removeItemById(ComboBox::Ptr* self, char* id) {
        return (**self).removeItemById(id);
    }

	C_ABI_RAW bool ABI_ComboBox_removeItemByIndex(ComboBox::Ptr* self, int index) {
        return (**self).removeItemByIndex(index);
    }

	C_ABI_METHOD void ABI_ComboBox_removeAllItems(ComboBox::Ptr* self) {
        (**self).removeAllItems();
    }

	C_ABI_RAW char32_t* ABI_ComboBox_getItemById(ComboBox::Ptr* self, char* id) {
        auto item = new String((**self).getItemById(id));
        autoclean.push_back(item);
        return item->data();
    }

	C_ABI_RAW char32_t* ABI_ComboBox_getSelectedItemId(ComboBox::Ptr* self) {
        auto id = new String((**self).getSelectedItemId());
        autoclean.push_back(id);
        return id->data();
    }

	C_ABI_METHOD bool ABI_ComboBox_changeItemById(ComboBox::Ptr* self, char* id, char* newValue) {
        return (**self).changeItemById(id, newValue);
    }

	C_ABI_METHOD bool ABI_ComboBox_changeItemByIndex(ComboBox::Ptr* self, int index, char* newValue) {
        return (**self).changeItemByIndex(index, newValue);
    }

	C_ABI_GETTER int ABI_ComboBox_getItemCount(ComboBox::Ptr* self) {
        return static_cast<int>((**self).getItemCount());
    }

	C_ABI_RAW void ABI_ComboBox_getItemIds(ComboBox::Ptr* self, void(*f)(char32_t*)) {
        for (auto id : (**self).getItemIds()) {
            f(id.data());
        }
    }

	C_ABI_SETTER void ABI_ComboBox_setMaximumItems(ComboBox::Ptr* self, int maximumItems) {
        (**self).setMaximumItems(maximumItems);
    }

	C_ABI_GETTER int ABI_ComboBox_getMaximumItems(ComboBox::Ptr* self) {
        return static_cast<int>((**self).getMaximumItems());
    }

	C_ABI_SETTER void ABI_ComboBox_setDefaultText(ComboBox::Ptr* self, char* defaultText) {
        (**self).setDefaultText(defaultText);
    }

	C_ABI_GETTER const char32_t* ABI_ComboBox_getDefaultText(ComboBox::Ptr* self) {
        return (**self).getDefaultText().data();
    }

	C_ABI_SETTER void ABI_ComboBox_setExpandDirection(ComboBox::Ptr* self, int expandDirection) {
        (**self).setExpandDirection(static_cast<ComboBox::ExpandDirection>(expandDirection));
    }

	C_ABI_GETTER int ABI_ComboBox_getExpandDirection(ComboBox::Ptr* self) {
        return static_cast<int>((**self).getExpandDirection());
    }

	C_ABI_METHOD bool ABI_ComboBox_containsId(ComboBox::Ptr* self, char* id) {
        return (**self).containsId(id);
    }

	C_ABI_SETTER void ABI_ComboBox_setChangeItemOnScroll(ComboBox::Ptr* self, int changeItemOnScroll) {
        (**self).setChangeItemOnScroll(changeItemOnScroll);
    }

	C_ABI_GETTER bool ABI_ComboBox_getChangeItemOnScroll(ComboBox::Ptr* self) {
        return (**self).getChangeItemOnScroll();
    }

	C_ABI_SIGNAL SignalItem* ABI_ComboBox_onItemSelect(ComboBox::Ptr* self) {
        return &(**self).onItemSelect;
    }
    
    // ColorPicker

    C_ABI_MAKE ColorPicker::Ptr* ABI_ColorPicker_new() {
        auto self = ColorPicker::create();
        auto ptr = new ColorPicker::Ptr(nullptr);
        ptr->swap(self);
        return ptr;
    }

    C_ABI_SETTER void ABI_ColorPicker_setColor(ColorPicker::Ptr* self, Color* color) {
        (**self).setColor(*color);
    }

    C_ABI_GETTER Color* ABI_ColorPicker_getColor(ColorPicker::Ptr* self) {
        return new Color((**self).getColor());
    }

    C_ABI_SIGNAL SignalColor* ABI_ColorPicker_onColorChange(ColorPicker::Ptr* self) {
        return &(**self).onColorChange;
    }

    C_ABI_SIGNAL SignalColor* ABI_ColorPicker_onOkPress(ColorPicker::Ptr* self) {
        return &(**self).onOkPress;
    }
}