#include <TGUI/Abi/Cabi.hpp>
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>

namespace tgui {

    std::vector<void*> autoclean;

    // Util

    C_ABI void ABI_STATIC_Util_free(void* pointer) {
        delete pointer;
    }

    // Color

    C_ABI Color* ABI_Color_new(int r, int g, int b, int a) {
        return new Color(static_cast<uint8_t>(r), static_cast<uint8_t>(g), static_cast<uint8_t>(b), static_cast<uint8_t>(a));
    }

    C_ABI int ABI_Color_get_red(Color* self) {
        return static_cast<int>(self->getRed());
    }

    C_ABI int ABI_Color_get_green(Color* self) {
        return static_cast<int>(self->getGreen());
    }

    C_ABI int ABI_Color_get_blue(Color* self) {
        return static_cast<int>(self->getBlue());
    }

    C_ABI int ABI_Color_get_alpha(Color* self) {
        return static_cast<int>(self->getAlpha());
    }

    C_ABI Color* ABI_Color_applyOpacity(Color* self, float fade) {
        return new Color(Color::applyOpacity(*self, fade));
    }

    // Signal

    C_ABI int ABI_Signal_connect(Signal* self, void(*f)()) {
        return self->connect(f);
    }

    C_ABI bool ABI_Signal_disconnect(Signal* self, int f) {
        return self->disconnect(f);
    }

    C_ABI void ABI_Signal_setEnabled(Signal* self, int enabled) {
        self->setEnabled(enabled);
    }

	C_ABI bool ABI_Signal_isEnabled(Signal* self) {
        return self->isEnabled();
    }

    // SignalString

    C_ABI int ABI_SignalString_connect(SignalString* self, void(*f)(const char32_t*)) {
        return self->connect([=](const String& str) {
            f(str.data());
        });
    }

    // SignalBool

    C_ABI int ABI_SignalBool_connect(SignalBool* self, void(*f)(int)) {
        return self->connect(f);
    }

    // SignalInt

    C_ABI int ABI_SignalInt_connect(SignalInt* self, void(*f)(int)) {
        return self->connect(f);
    }

    // SignalUInt

	C_ABI int ABI_SignalUInt_connect(SignalUInt* self, void(*f)(unsigned int)) {
        return self->connect(f);
    }

    // SignalFloat

	C_ABI int ABI_SignalFloat_connect(SignalFloat* self, void(*f)(float)) {
        return self->connect(f);
    }

    // SignalRange

    C_ABI int ABI_SignalRange_connect(SignalRange* self, void(*f)(float, float)) {
        return self->connect(f);
    }

    // SignalColor

    C_ABI int ABI_SignalColor_connect(SignalColor* self, void(*f)(void*)) {
        return self->connect([=](Color col) {
            auto color = new Color(col);
            f(color);
        });
    }

    // SignalVector2f

    C_ABI int ABI_SignalVector2f_connect(SignalVector2f* self, void(*f)(void*)) {
        return self->connect([=](Vector2f vec) {
            auto vector = new Vector2f(vec);
            f(vector);
        });
    }

    // SignalPointer

    C_ABI int ABI_SignalPointer_connect(SignalTyped<void*>* self, void(*f)(void*)) {
        return self->connect(f);
    }

    // SignalShowEffect

    C_ABI int ABI_SignalShowEffect_connect(SignalShowEffect* self, void(*f)(int, int)) {
        return self->connect([=](ShowEffectType showEffectType, bool show) {
            f(static_cast<int>(showEffectType), static_cast<int>(show));
        });
    }

    // SignalAnimationType

    C_ABI int ABI_SignalAnimationType_connect(SignalAnimationType* self, void(*f)(int)) {
        return self->connect([=](AnimationType animationType) {
            f(static_cast<int>(animationType));
        });
    }

    // SignalItem

    C_ABI int ABI_SignalItem_connect(SignalItem* self, void(*f)(const char32_t*, const char32_t*)) {
        return self->connect([=](const String& str1, const String& str2) {
            f(str1.data(), str2.data());
        });
    }

    // SignalItemHierarchy

    C_ABI int ABI_SignalItemHierarchy_connect(SignalItemHierarchy* self, void(*f)(void*)) {
        return self->connect([=](const std::vector< String > &fullItem) {
            f((void*)&fullItem);
        });
    }

    C_ABI void ABI_STATIC_SignalItemHierarchy_fetchPath(std::vector< String >* load, void(*f)(const char32_t*)) {
        for(auto str : *load) {
            f(str.data());
        }
    }

    // SignalTypedIntBoolPtr

	C_ABI int ABI_SignalTypedIntBoolPtr_connect(SignalTypedIntBoolPtr* self, void(*f)(int, bool*)) {
        return self->connect([=](int index, bool* shouldChange) {
            f(index, shouldChange);
        });
    }

    // SignalTypedSizeT
    
	C_ABI int ABI_SignalTypedSizeT_connect(SignalTypedSizeT* self, void(*f)(int)) {
        return self->connect([=](std::size_t size) {
            f(static_cast<int>(size));
        });
    }

    // SignalPanelListBoxItem

    C_ABI int ABI_SignalPanelListBoxItem_connect(SignalPanelListBoxItem* self, void(*f)(const char32_t*)) {
        return self->connect([=](const String& str) {
            f(str.data());
        });
    }

    // Window

    C_ABI sf::RenderWindow* ABI_Window_new() {
#ifdef TGUI_SYSTEM_IOS
        return new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "No title");
#elif SFML_VERSION_MAJOR >= 3
        return new sf::RenderWindow(sf::VideoMode{ {800, 600} }, "No title");
#else
        return new sf::RenderWindow({ 800, 600 }, "No title");
#endif
    }

    C_ABI void ABI_Window_close(sf::WindowBase* self) {
        self->close();
    }

    C_ABI bool ABI_Window_isOpen(sf::WindowBase* self) {
        return self->isOpen();
    }

    // BackendGui
    
	C_ABI void ABI_BackendGui_setTextSize(BackendGui* self, int textSize) {
        self->setTextSize(textSize);
    }

	C_ABI int ABI_BackendGui_getTextSize(BackendGui* self) {
        return self->getTextSize();
    }

    C_ABI void ABI_BackendGui_setAbsoluteView(BackendGui* self, int x, int y, int w, int h) {
        self->setAbsoluteView(FloatRect((float)x, (float)y, (float)w, (float)h));
    }

	C_ABI void ABI_BackendGui_setRelativeView(BackendGui* self, float x, float y, float w, float h) {
        self->setRelativeView(FloatRect(x, y, w, h));
    }

    C_ABI void ABI_BackendGui_getView(BackendGui* self, void(*f)(float, float, float, float)) {
        auto view = self->getView();
        auto position = view.getPosition();
        auto size = view.getSize();
        f(position.x, position.y, size.x, size.y);
    }

    C_ABI void ABI_BackendGui_setAbsoluteViewport(BackendGui* self, int x, int y, int w, int h) {
        self->setAbsoluteViewport(FloatRect((float)x, (float)y, (float)w, (float)h));
    }

	C_ABI void ABI_BackendGui_setRelativeViewport(BackendGui* self, float x, float y, float w, float h) {
        self->setRelativeViewport(FloatRect(x, y, w, h));
    }

    C_ABI void ABI_BackendGui_getViewport(BackendGui* self, void(*f)(float, float, float, float)) {
        auto view = self->getViewport();
        auto position = view.getPosition();
        auto size = view.getSize();
        f(position.x, position.y, size.x, size.y);
    }

    C_ABI void ABI_BackendGui_setTabKeyUsageEnabled(BackendGui* self, int enabled) {
        self->setTabKeyUsageEnabled(enabled);
    }

	C_ABI bool ABI_BackendGui_isTabKeyUsageEnabled(BackendGui* self) {
        return self->isTabKeyUsageEnabled();
    }

	C_ABI void ABI_BackendGui_setFont(BackendGui* self, Font* font) {
        self->setFont(*font);
    }

	C_ABI Font* ABI_BackendGui_getFont(BackendGui* self) {
        return new Font(self->getFont());
    }

	C_ABI void ABI_BackendGui_unfocusAllWidgets(BackendGui* self) {
        self->unfocusAllWidgets();
    }

	C_ABI void ABI_BackendGui_setOpacity(BackendGui* self, float opacity) {
        self->setOpacity(opacity);
    }

	C_ABI float ABI_BackendGui_getOpacity(BackendGui* self) {
        return self->getOpacity();
    }

	C_ABI void ABI_BackendGui_setOverrideMouseCursor(BackendGui* self, int mouseCursor) {
        self->setOverrideMouseCursor(static_cast<Cursor::Type>(mouseCursor));
    }

	C_ABI void ABI_BackendGui_restoreOverrideMouseCursor(BackendGui* self) {
        self->restoreOverrideMouseCursor();
    }

	C_ABI void ABI_BackendGui_mapPixelToCoords(BackendGui* self, int x, int y, void(*f)(float, float)) {
        auto coords = self->mapPixelToCoords({x, y});
        f((float)coords.x, (float)coords.y);
    }

	C_ABI void ABI_BackendGui_mapCoordsToPixel(BackendGui* self, float x, float y, void(*f)(float, float)) {
        auto pixel = (*self).mapCoordsToPixel({x, y});
        f((float)pixel.x, (float)pixel.y);
    }

    C_ABI Signal* ABI_BackendGui_onViewChange(BackendGui* self) {
        return &self->onViewChange;
    }

    // Font
    
    C_ABI Font* ABI_Font_new(char* id) {
        return new Font(id);
    }

    // Gui

    C_ABI Gui* ABI_Gui_new(sf::RenderWindow* window) {
        auto gui = new Gui(*window);
        gui->getBackendRenderTarget()->setClearColor(Color(240, 240, 240));
        return gui;
    }

    C_ABI bool ABI_Gui_isActive(Gui* self) {
        return self->getWindow()->isOpen();
    }

    C_ABI void ABI_Gui_pollEvents(Gui* self) {
        auto window = self->getWindow();
        sf::Event event;
        while (window->pollEvent(event))
        {
            self->handleEvent(event);

            if (event.type == sf::Event::Closed)
                window->close();
        }
    }

    C_ABI void ABI_Gui_draw(Gui* self) {
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

    C_ABI void ABI_Gui_add(Gui* self, Widget::Ptr* widget, const char* name) {
        self->add(*widget, name);
    }

    C_ABI void ABI_Gui_remove(Gui* self, Widget::Ptr* widget) {
        self->remove(*widget);
    }

    C_ABI void ABI_Gui_removeAll(Gui* self) {
        self->removeAllWidgets();
    }

    C_ABI void ABI_Gui_mainLoop(Gui* self) {
        self->mainLoop();
    }

    C_ABI Widget::Ptr* ABI_Gui_getWidget(Gui* self, const char* name) {
        auto shared = self->get(name);
        if (shared == nullptr) {
            return nullptr;
        }
        auto ptr = new Widget::Ptr(nullptr);
        ptr->swap(shared);
        return ptr;
    }

    // Theme

    C_ABI void ABI_STATIC_Theme_setDefault(char* theme) {
        Theme::setDefault(theme);
    }

    // Texture

    C_ABI Texture* ABI_Texture_new(char* id, int partRectX, int partRectY, int partRectW, int partRectH, int middlePartX, int middlePartY, int middlePartW, int middlePartH, int smooth) {
        UIntRect partRect(partRectX, partRectY, partRectW, partRectH);
        UIntRect middlePart(middlePartX, middlePartY, middlePartW, middlePartH);
        return new Texture(id, partRect, middlePart, smooth);
    }

	C_ABI const char32_t* ABI_Texture_getId(Texture* self) {
        return (*self).getId().data();
    }

	C_ABI Vector2u* ABI_Texture_getImageSize(Texture* self) {
        return new Vector2u((*self).getImageSize());
    }

	C_ABI UIntRect* ABI_Texture_getPartRect(Texture* self) {
        return new UIntRect((*self).getPartRect());
    }

	C_ABI void ABI_Texture_setColor(Texture* self, int red, int green, int blue) {
        (*self).setColor({static_cast<uint8_t>(red), static_cast<uint8_t>(green), static_cast<uint8_t>(blue)});
    }

	C_ABI Color* ABI_Texture_getColor(Texture* self) {
        return new Color((*self).getColor());
    }

	C_ABI bool ABI_Texture_isSmooth(Texture* self) {
        return (*self).isSmooth();
    }

    C_ABI void ABI_STATIC_Texture_setDefaultSmooth(int smooth) {
        Texture::setDefaultSmooth(smooth);
    }

	C_ABI bool ABI_STATIC_Texture_getDefaultSmooth() {
        return Texture::getDefaultSmooth();
    }

    // Widget

    C_ABI void ABI_STATIC_Widget_finalizer(std::shared_ptr<Widget>* pointer) {
        (*pointer).reset();
        delete pointer;
    }

    C_ABI Widget* ABI_STATIC_Widget_getUnshared(std::shared_ptr<Widget>* pointer) {
        return &(**pointer);
    }

    C_ABI const char32_t* ABI_STATIC_Widget_getType(Widget::Ptr* self) {
        return (**self).getWidgetType().data();
    }

    C_ABI const char32_t* ABI_Widget_getName(Widget::Ptr* self) {
        auto name = new String((**self).getWidgetName());
        autoclean.push_back(name);
        return name->data();
    }

    C_ABI void ABI_Widget_setSize(Widget::Ptr* self, const char* width, const char* height) {
        (**self).setSize(width, height);
    }

    C_ABI Vector2f* ABI_Widget_getSize(Widget::Ptr* self) {
        return new Vector2f((**self).getSize());
    }

    C_ABI Vector2f* ABI_Widget_getFullSize(Widget::Ptr* self) {
        return new Vector2f((**self).getFullSize());
    }

    C_ABI void ABI_Widget_setPosition(Widget::Ptr* self, const char* x, const char* y) {
        (**self).setPosition(x, y);
    }

    C_ABI Vector2f* ABI_Widget_getPosition(Widget::Ptr* self) {
        return new Vector2f((**self).getPosition());
    }

    C_ABI Vector2f* ABI_Widget_getAbsolutePosition(Widget::Ptr* self) {
        return new Vector2f((**self).getAbsolutePosition());
    }

    C_ABI void ABI_Widget_setTextSize(Widget::Ptr* self, int textSize) {
        (**self).setTextSize(textSize);
    }

	C_ABI int ABI_Widget_getTextSize(Widget::Ptr* self) {
        return (**self).getTextSize();
    }

    C_ABI void ABI_Widget_setWidth(Widget::Ptr* self, char* width) {
        (**self).setWidth(width);
    }

    C_ABI void ABI_Widget_setHeight(Widget::Ptr* self, char* height) {
        (**self).setHeight(height);
    }

    C_ABI void ABI_Widget_setVisible(Widget::Ptr* self, int visible) {
        (**self).setVisible(visible);
    }

    C_ABI bool ABI_Widget_isVisible(Widget::Ptr* self) {
        return (**self).isVisible();
    }

    C_ABI void ABI_Widget_setEnabled(Widget::Ptr* self, int enabled) {
        (**self).setEnabled(enabled);
    }

    C_ABI bool ABI_Widget_isEnabled(Widget::Ptr* self) {
        return (**self).isEnabled();
    }

    C_ABI void ABI_Widget_setFocused(Widget::Ptr* self, int focused) {
        (**self).setFocused(focused);

    }

    C_ABI bool ABI_Widget_isFocused(Widget::Ptr* self) {
        return (**self).isFocused();
    }

    C_ABI void ABI_Widget_setFocusable(Widget::Ptr* self, int focusable) {
        (**self).setFocusable(focusable);

    }

    C_ABI bool ABI_Widget_isFocusable(Widget::Ptr* self) {
        return (**self).isFocusable();
    }

    C_ABI bool ABI_Widget_canGainFocus(Widget::Ptr* self) {
        return (**self).canGainFocus();
    }

    C_ABI bool ABI_Widget_isContainer(Widget::Ptr* self) {
        return (**self).isContainer();
    }

    C_ABI void ABI_Widget_setToolTip(Widget::Ptr* self, Widget::Ptr* tooltip) {
        (**self).setToolTip(*tooltip);
    }

	C_ABI Widget::Ptr* ABI_Widget_getToolTip(Widget::Ptr* self) {
        auto shared = (**self).getToolTip();
        if (shared == nullptr) {
            return nullptr;
        }
        auto ptr = new Widget::Ptr(nullptr);
        ptr->swap(shared);
        return ptr;
    }

    C_ABI void ABI_Widget_setMouseCursor(Widget::Ptr* self, int cursor) {
        (**self).setMouseCursor(static_cast<Cursor::Type>(cursor));
    }

	C_ABI int ABI_Widget_getMouseCursor(Widget::Ptr* self) {
        return static_cast<int>((**self).getMouseCursor());
    }

    // C_ABI bool ABI_Widget_isDraggableWidget(Widget::Ptr* self) {
    //     return (**self).isDraggableWidget();
    // }

	C_ABI bool ABI_Widget_isMouseDown(Widget::Ptr* self) {
        return (**self).isMouseDown();
    }

    C_ABI void ABI_Widget_showWithEffect(Widget::Ptr* self, int effect, int duration) {
        (**self).showWithEffect(static_cast<ShowEffectType>(effect), duration);
    }

	C_ABI void ABI_Widget_hideWithEffect(Widget::Ptr* self, int effect, int duration) {
        (**self).hideWithEffect(static_cast<ShowEffectType>(effect), duration);
    }

	C_ABI void ABI_Widget_moveWithAnimation(Widget::Ptr* self, char* x, char* y, int duration) {
        (**self).moveWithAnimation({x, y}, duration);
    }

    C_ABI void ABI_Widget_resizeWithAnimation(Widget::Ptr* self, char* width, char* height, int duration) {
        (**self).resizeWithAnimation({width, height}, duration);
    }

    C_ABI bool ABI_Widget_isAnimationPlaying(Widget::Ptr* self) {
        return (**self).isAnimationPlaying();
    }

	C_ABI void ABI_Widget_moveToFront(Widget::Ptr* self) {
        (**self).moveToFront();
    }

	C_ABI void ABI_Widget_moveToBack(Widget::Ptr* self) {
        (**self).moveToBack();
    }

    C_ABI void ABI_Widget_finishAllAnimations(Widget::Ptr* self) {
        (**self).finishAllAnimations();
    }

    C_ABI void ABI_Widget_leftMousePressed(Widget::Ptr* self, float x, float y) {
        (**self).leftMousePressed({x, y});
    }

    C_ABI void ABI_Widget_leftMouseReleased(Widget::Ptr* self, float x, float y) {
        (**self).leftMouseReleased({x, y});
    }

    C_ABI void ABI_Widget_rightMousePressed(Widget::Ptr* self, float x, float y) {
        (**self).rightMousePressed({x, y});
    }

    C_ABI void ABI_Widget_rightMouseReleased(Widget::Ptr* self, float x, float y) {
        (**self).rightMouseReleased({x, y});
    }

    C_ABI void ABI_Widget_mouseMoved(Widget::Ptr* self, float x, float y) {
        (**self).mouseMoved({x, y});
    }

	C_ABI void ABI_Widget_keyPressed(Widget::Ptr* self, int keyCode, int alt, int control, int shift, int system) {
        (**self).keyPressed({static_cast<Event::KeyboardKey>(keyCode), alt != 0, control != 0, shift != 0, system != 0});
    }

	C_ABI void ABI_Widget_textEntered(Widget::Ptr* self, int character) {
        (**self).textEntered(character);
    }

	C_ABI void ABI_Widget_scrolled(Widget::Ptr* self, float delta, float x, float y, int touch) {
        (**self).scrolled(delta, {x, y}, touch);
    }

    C_ABI void ABI_Widget_askToolTip(Widget::Ptr* self, float x, float y) {
        (**self).askToolTip({x, y});
    }

    C_ABI void ABI_Widget_setWidgetName(Widget::Ptr* self, char * name) {
        (**self).setWidgetName(name);
    }

	C_ABI const char32_t* ABI_Widget_getWidgetName(Widget::Ptr* self) {
        auto str = new String((**self).getWidgetName());
        autoclean.push_back(str);
        return str->data();
    }
    
    C_ABI SignalVector2f* ABI_Widget_onPositionChange(Widget::Ptr* self) {
        return &(**self).onPositionChange;
    }

    C_ABI SignalVector2f* ABI_Widget_onSizeChange(Widget::Ptr* self) {
        return &(**self).onSizeChange;
    }

    C_ABI Signal* ABI_Widget_onFocus(Widget::Ptr* self) {
        return &(**self).onFocus;
    }

    C_ABI Signal* ABI_Widget_onUnfocus(Widget::Ptr* self) {
        return &(**self).onUnfocus;
    }

    C_ABI Signal* ABI_Widget_onMouseEnter(Widget::Ptr* self) {
        return &(**self).onMouseEnter;
    }

    C_ABI Signal* ABI_Widget_onMouseLeave(Widget::Ptr* self) {
        return &(**self).onMouseLeave;
    }

    C_ABI SignalShowEffect* ABI_Widget_onShowEffectFinish(Widget::Ptr* self) {
        return &(**self).onShowEffectFinish;
    }

    C_ABI SignalAnimationType* ABI_Widget_onAnimationFinish(Widget::Ptr* self) {
        return &(**self).onAnimationFinish;
    }


    // ClickableWidget

    C_ABI SignalVector2f* ABI_ClickableWidget_onMousePress(ClickableWidget::Ptr* self) {
        return &(**self).onMousePress;
    }

    C_ABI SignalVector2f* ABI_ClickableWidget_onMouseRelease(ClickableWidget::Ptr* self) {
        return &(**self).onMouseRelease;
    }

    C_ABI SignalVector2f* ABI_ClickableWidget_onClick(ClickableWidget::Ptr* self) {
        return &(**self).onClick;
    }

    C_ABI SignalVector2f* ABI_ClickableWidget_onRightMousePress(ClickableWidget::Ptr* self) {
        return &(**self).onRightMousePress;
    }

    C_ABI SignalVector2f* ABI_ClickableWidget_onRightMouseRelease(ClickableWidget::Ptr* self) {
        return &(**self).onRightMouseRelease;
    }

    C_ABI SignalVector2f* ABI_ClickableWidget_onRightClick(ClickableWidget::Ptr* self) {
        return &(**self).onRightClick;
    }

    // ButtonBase

    C_ABI void ABI_ButtonBase_setTextPosition(ButtonBase::Ptr* self, const char* position, const char* origin) {
        (**self).setTextPosition(position, origin);
    }

    C_ABI void ABI_ButtonBase_setText(ButtonBase::Ptr* self, const char* text) {
        (**self).setText(text);
    }

    C_ABI const char32_t* ABI_ButtonBase_getText(ButtonBase::Ptr* self) {
        return (**self).getText().data();
    }

    // Button

    C_ABI Button::Ptr* ABI_Button_new() {
        auto self = Button::create();
        auto ptr = new Button::Ptr(nullptr);
        ptr->swap(self);
        return ptr;
    }

    C_ABI Signal* ABI_Button_onPress(Button::Ptr* self) {
        return &(**self).onPress;
    }

    // BitmapButton
	C_ABI BitmapButton::Ptr* ABI_BitmapButton_new() {
        auto self = BitmapButton::create();
        auto ptr = new BitmapButton::Ptr(nullptr);
        ptr->swap(self);
        return ptr;
    }

	C_ABI void ABI_BitmapButton_setImage(BitmapButton::Ptr* self, Texture* texture) {
        (**self).setImage(*texture);
    }

	C_ABI Texture* ABI_BitmapButton_getImage(BitmapButton::Ptr* self) {
        return new Texture((**self).getImage());
    }

	C_ABI void ABI_BitmapButton_setImageScaling(BitmapButton::Ptr* self, float relativeHeight) {
        (**self).setImageScaling(relativeHeight);
    }

	C_ABI float ABI_BitmapButton_getImageScaling(BitmapButton::Ptr* self) {
        return (**self).getImageScaling();
    }

    // EditBox

    C_ABI EditBox::Ptr* ABI_EditBox_new() {
        auto self = EditBox::create();
        auto ptr = new EditBox::Ptr(nullptr);
        ptr->swap(self);
        return ptr;
    }

    C_ABI void ABI_EditBox_setText(EditBox::Ptr* self, const char* text) {
        (**self).setText(text);
    }

    C_ABI const char32_t* ABI_EditBox_getText(EditBox::Ptr* self) {
        return (**self).getText().data();
    }

    C_ABI void ABI_EditBox_setDefaultText(EditBox::Ptr* self, const char* text) {
        (**self).setDefaultText(text);
    }

    C_ABI const char32_t* ABI_EditBox_getDefaultText(EditBox::Ptr* self) {
        return (**self).getDefaultText().data();
    }

    C_ABI void ABI_EditBox_selectText(EditBox::Ptr* self, int start, int length) {
        (**self).selectText(start, length);
    }

    C_ABI const char32_t* ABI_EditBox_getSelectedText(EditBox::Ptr* self) {
        auto text = new String((**self).getSelectedText());
        autoclean.push_back(text);
        return text->data();
    }

    C_ABI void ABI_EditBox_setPasswordCharacter(EditBox::Ptr* self, char* character) {
        (**self).setPasswordCharacter(*character);
    }

    C_ABI char ABI_EditBox_getPasswordCharacter(EditBox::Ptr* self) {
        return static_cast<char>((**self).getPasswordCharacter());
    }

    C_ABI void ABI_EditBox_setMaximumCharacters(EditBox::Ptr* self, unsigned int max) {
        (**self).setMaximumCharacters(max);
    }

    C_ABI unsigned int ABI_EditBox_getMaximumCharacters(EditBox::Ptr* self) {
        return (**self).getMaximumCharacters();
    }

    C_ABI void ABI_EditBox_setAlignment(EditBox::Ptr* self, int alignment) {
        (**self).setAlignment(static_cast<EditBox::Alignment>(alignment));
    }

    C_ABI int ABI_EditBox_getAlignment(EditBox::Ptr* self) {
        return static_cast<int>((**self).getAlignment());
    }

    C_ABI void ABI_EditBox_limitTextWidth(EditBox::Ptr* self, int limit) {
        (**self).limitTextWidth(limit);
    }

    C_ABI bool ABI_EditBox_isTextWidthLimited(EditBox::Ptr* self) {
        return (**self).isTextWidthLimited();
    }

    C_ABI void ABI_EditBox_setReadOnly(EditBox::Ptr* self, int readOnly) {
        (**self).setReadOnly(readOnly);
    }

    C_ABI bool ABI_EditBox_isReadOnly(EditBox::Ptr* self) {
        return (**self).isReadOnly();
    }

    C_ABI void ABI_EditBox_setCaretPosition(EditBox::Ptr* self, int caretPosition) {
        (**self).setCaretPosition(caretPosition);
    }

    C_ABI int ABI_EditBox_getCaretPosition(EditBox::Ptr* self) {
        return static_cast<int>((**self).getCaretPosition());
    }

    C_ABI void ABI_EditBox_setSuffix(EditBox::Ptr* self, char* suffix) {
        (**self).setSuffix(suffix);
    }

    C_ABI const char32_t* ABI_EditBox_getSuffix(EditBox::Ptr* self) {
        return (**self).getSuffix().data();
    }

    C_ABI SignalString* ABI_EditBox_onTextChange(EditBox::Ptr* self) {
        return &(**self).onTextChange;
    }

    C_ABI SignalString* ABI_EditBox_onReturnKeyPress(EditBox::Ptr* self) {
        return &(**self).onReturnKeyPress;
    }

    C_ABI SignalString* ABI_EditBox_onReturnOrUnfocus(EditBox::Ptr* self) {
        return &(**self).onReturnOrUnfocus;
    }

    C_ABI SignalTypedSizeT* ABI_EditBox_onCaretPositionChange(EditBox::Ptr* self) {
        return &(**self).onCaretPositionChange;
    }

    // Label

    C_ABI Label::Ptr* ABI_Label_new() {
        auto self = Label::create();
        auto ptr = new Label::Ptr(nullptr);
        ptr->swap(self);
        return ptr;
    }

    C_ABI void ABI_Label_setText(Label::Ptr* self, char* text) {
        (**self).setText(text);
    }

    C_ABI const char32_t* ABI_Label_getText(Label::Ptr* self) {
        return (**self).getText().data();
    }

    C_ABI void ABI_Label_setHorizontalAlignment(Label::Ptr* self, int alignment) {
        (**self).setHorizontalAlignment(static_cast<Label::HorizontalAlignment>(alignment));
    }

    C_ABI int ABI_Label_getHorizontalAlignment(Label::Ptr* self) {
        return static_cast<int>((**self).getHorizontalAlignment());
    }

    C_ABI void ABI_Label_setVerticalAlignment(Label::Ptr* self, int alignment) {
        (**self).setVerticalAlignment(static_cast<Label::VerticalAlignment>(alignment));
    }

    C_ABI int ABI_Label_getVerticalAlignment(Label::Ptr* self) {
        return static_cast<int>((**self).getVerticalAlignment());
    }

    C_ABI void ABI_Label_setScrollbarPolicy(Label::Ptr* self, int policy) {
        (**self).setScrollbarPolicy(static_cast<Scrollbar::Policy>(policy));
    }

    C_ABI int ABI_Label_getScrollbarPolicy(Label::Ptr* self) {
        return static_cast<int>((**self).getScrollbarPolicy());
    }

    C_ABI void ABI_Label_setScrollbarValue(Label::Ptr* self, unsigned int value) {
        (**self).setScrollbarValue(value);
    }

    C_ABI int ABI_Label_getScrollbarValue(Label::Ptr* self) {
        return (**self).getScrollbarValue();
    }

    C_ABI void ABI_Label_setAutoSize(Label::Ptr* self, int autoSize) {
        (**self).setAutoSize(autoSize);
    }

    C_ABI bool ABI_Label_getAutoSize(Label::Ptr* self) {
        return (**self).getAutoSize();
    }

    C_ABI void ABI_Label_setMaximumTextWidth(Label::Ptr* self, float maximumWidth) {
        (**self).setMaximumTextWidth(maximumWidth);
    }

    C_ABI float ABI_Label_getMaximumTextWidth(Label::Ptr* self) {
        return (**self).getMaximumTextWidth();
    }

    C_ABI void ABI_Label_ignoreMouseEvents(Label::Ptr* self, int ignore) {
        (**self).ignoreMouseEvents(ignore);
    }

    C_ABI bool ABI_Label_ignoringMouseEvents(Label::Ptr* self) {
        return (**self).isIgnoringMouseEvents();
    }

    // RadioButton

    C_ABI RadioButton::Ptr* ABI_RadioButton_new() {
        auto self = RadioButton::create();
        auto ptr = new RadioButton::Ptr(nullptr);
        ptr->swap(self);
        return ptr;
    }

    C_ABI void ABI_RadioButton_setText(RadioButton::Ptr* self, char* text) {
        (**self).setText(text);
    }

    C_ABI const char32_t* ABI_RadioButton_getText(RadioButton::Ptr* self) {
        return (**self).getText().data();
    }

    C_ABI void ABI_RadioButton_setChecked(RadioButton::Ptr* self, int checked) {
        (**self).setChecked(checked);
    }

    C_ABI bool ABI_RadioButton_isChecked(RadioButton::Ptr* self) {
        return (**self).isChecked();
    }

    C_ABI void ABI_RadioButton_setTextClickable(RadioButton::Ptr* self, int textClickable) {
        (**self).setTextClickable(textClickable);
    }

    C_ABI bool ABI_RadioButton_isTextClickable(RadioButton::Ptr* self) {
        return (**self).isTextClickable();
    }

    C_ABI SignalBool* ABI_RadioButton_onCheck(RadioButton::Ptr* self) {
        return &(**self).onCheck;
    }

    C_ABI SignalBool* ABI_RadioButton_onUncheck(RadioButton::Ptr* self) {
        return &(**self).onUncheck;
    }

    C_ABI SignalBool* ABI_RadioButton_onChange(RadioButton::Ptr* self) {
        return &(**self).onChange;
    }

    // CheckBox

    C_ABI CheckBox::Ptr* ABI_CheckBox_new() {
        auto self = CheckBox::create();
        auto ptr = new CheckBox::Ptr(nullptr);
        ptr->swap(self);
        return ptr;
    }

    // Knob

    C_ABI Knob::Ptr* ABI_Knob_new() {
        auto self = Knob::create();
        auto ptr = new Knob::Ptr(nullptr);
        ptr->swap(self);
        return ptr;
    }

	C_ABI void ABI_Knob_setStartRotation(Knob::Ptr* self, float startRotation) {
        (**self).setStartRotation(startRotation);
    }

	C_ABI float ABI_Knob_getStartRotation(Knob::Ptr* self) {
        return (**self).getStartRotation();
    }

	C_ABI void ABI_Knob_setEndRotation(Knob::Ptr* self, float endRotation) {
        (**self).setEndRotation(endRotation);
    }

	C_ABI float ABI_Knob_getEndRotation(Knob::Ptr* self) {
        return (**self).getEndRotation();
    }

	C_ABI void ABI_Knob_setMinimum(Knob::Ptr* self, float minimum) {
        (**self).setMinimum(minimum);
    }

	C_ABI float ABI_Knob_getMinimum(Knob::Ptr* self) {
        return (**self).getMinimum();
    }

	C_ABI void ABI_Knob_setMaximum(Knob::Ptr* self, float maximum) {
        (**self).setMaximum(maximum);
    }

	C_ABI float ABI_Knob_getMaximum(Knob::Ptr* self) {
        return (**self).getMaximum();
    }

	C_ABI void ABI_Knob_setValue(Knob::Ptr* self, float value) {
        (**self).setValue(value);
    }

	C_ABI float ABI_Knob_getValue(Knob::Ptr* self) {
        return (**self).getValue();
    }

	C_ABI void ABI_Knob_setClockwiseTurning(Knob::Ptr* self, int clockwiseTurning) {
        (**self).setClockwiseTurning(clockwiseTurning);
    }

	C_ABI float ABI_Knob_getClockwiseTurning(Knob::Ptr* self) {
        return (**self).getClockwiseTurning();
    }

	C_ABI SignalFloat* ABI_Knob_onValueChange(Knob::Ptr* self) {
        return &(**self).onValueChange;
    }

    // ChatBox
	C_ABI ChatBox::Ptr* ABI_ChatBox_new() {
        auto self = ChatBox::create();
        auto ptr = new ChatBox::Ptr(nullptr);
        ptr->swap(self);
        return ptr;
    }

	C_ABI void ABI_ChatBox_addLine(ChatBox::Ptr* self, char* text, Color* color, int style) {
        (**self).addLine(text, *color, style);
    }

	C_ABI const char32_t* ABI_ChatBox_getLine(ChatBox::Ptr* self, int lineIndex) {
        auto str = new String((**self).getLine(lineIndex));
        autoclean.push_back(str);
        return str->data();
    }

	C_ABI Color* ABI_ChatBox_getLineColor(ChatBox::Ptr* self, int lineIndex) {
        return new Color((**self).getLineColor(lineIndex));
    }

	C_ABI int ABI_ChatBox_getLineTextStyle(ChatBox::Ptr* self, int lineIndex) {
        return static_cast<int>((**self).getLineTextStyle(lineIndex));
    }

	C_ABI bool ABI_ChatBox_removeLine(ChatBox::Ptr* self, int lineIndex) {
        return (**self).removeLine(lineIndex);
    }

	C_ABI void ABI_ChatBox_removeAllLines(ChatBox::Ptr* self) {
        (**self).removeAllLines();
    }

	C_ABI int ABI_ChatBox_getLineAmount(ChatBox::Ptr* self) {
        return static_cast<int>((**self).getLineAmount());
    }

	C_ABI void ABI_ChatBox_setLineLimit(ChatBox::Ptr* self, int maxLines) {
        (**self).setLineLimit(maxLines);
    }

	C_ABI int ABI_ChatBox_getLineLimit(ChatBox::Ptr* self) {
        return static_cast<int>((**self).getLineLimit());
    }

	C_ABI void ABI_ChatBox_setTextColor(ChatBox::Ptr* self, Color* color) {
        (**self).setTextColor(*color);
    }

	C_ABI Color* ABI_ChatBox_getTextColor(ChatBox::Ptr* self) {
        return new Color((**self).getTextColor());
    }

	C_ABI void ABI_ChatBox_setTextStyle(ChatBox::Ptr* self, int style) {
        (**self).setTextStyle(style);
    }

	C_ABI int ABI_ChatBox_getTextStyle(ChatBox::Ptr* self) {
        return static_cast<int>((**self).getTextStyle());
    }

	C_ABI void ABI_ChatBox_setLinesStartFromTop(ChatBox::Ptr* self, int startFromTop) {
        (**self).setLinesStartFromTop(startFromTop);
    }

	C_ABI bool ABI_ChatBox_getLinesStartFromTop(ChatBox::Ptr* self) {
        return (**self).getLinesStartFromTop();
    }
    
	C_ABI void ABI_ChatBox_setNewLinesBelowOthers(ChatBox::Ptr* self, int newLinesBelowOthers) {
        (**self).setNewLinesBelowOthers(newLinesBelowOthers);
    }

	C_ABI bool ABI_ChatBox_getNewLinesBelowOthers(ChatBox::Ptr* self) {
        return (**self).getNewLinesBelowOthers();
    }

	C_ABI void ABI_ChatBox_setScrollbarValue(ChatBox::Ptr* self, int value) {
        (**self).setScrollbarValue(value);
    }

	C_ABI int ABI_ChatBox_getScrollbarValue(ChatBox::Ptr* self) {
        return (**self).getScrollbarValue();
    }

    // Container

    C_ABI void ABI_Container_get_widgets(Container::Ptr* self, void(*f)(Widget::Ptr* widget, const char32_t* type)) {
        for (auto w : (**self).getWidgets()) {
            auto ptr = new Widget::Ptr();
            ptr->swap(w);
            f(ptr, (**ptr).getWidgetType().data());
        }
    }

    C_ABI void ABI_Container_add(Container::Ptr* self, Widget::Ptr* widget, char* name) {
        (**self).add(*widget, name);
    }

    C_ABI Widget::Ptr* ABI_Container_get(Container::Ptr* self, char* name) {
        auto shared = (**self).get(name);
        if (shared == nullptr) {
            return nullptr;
        }
        auto ptr = new Widget::Ptr(nullptr);
        ptr->swap(shared);
        return ptr;
    }

    C_ABI bool ABI_Container_remove(Container::Ptr* self, Widget::Ptr* widget) {
        return (**self).remove(*widget);
    }

    C_ABI void ABI_Container_removeAllWidgets(Container::Ptr* self) {
        (**self).removeAllWidgets();
    }

    C_ABI Vector2f* ABI_Container_getInnerSize(Container::Ptr* self) {
        return new Vector2f((**self).getInnerSize());
    }

    C_ABI Vector2f* ABI_Container_getChildWidgetsOffset(Container::Ptr* self) {
        return new Vector2f((**self).getChildWidgetsOffset());
    }

    C_ABI void ABI_Container_moveWidgetToFront(Container::Ptr* self, Widget::Ptr* widget) {
        (**self).moveWidgetToFront(*widget);
    }

    C_ABI void ABI_Container_moveWidgetToBack(Container::Ptr* self, Widget::Ptr* widget) {
        (**self).moveWidgetToBack(*widget);
    }

    C_ABI int ABI_Container_moveWidgetForward(Container::Ptr* self, Widget::Ptr* widget) {
        return static_cast<int>((**self).moveWidgetForward(*widget));
    }

    C_ABI int ABI_Container_moveWidgetBackward(Container::Ptr* self, Widget::Ptr* widget) {
        return static_cast<int>((**self).moveWidgetBackward(*widget));
    }

    C_ABI bool ABI_Container_setWidgetIndex(Container::Ptr* self, Widget::Ptr* widget, int index) {
        return (**self).setWidgetIndex(*widget, index);
    }

    C_ABI int ABI_Container_getWidgetIndex(Container::Ptr* self, Widget::Ptr* widget) {
        return (**self).getWidgetIndex(*widget);
    }

    C_ABI Widget::Ptr* ABI_Container_getFocusedChild(Container::Ptr* self) {
        auto shared = (**self).getFocusedChild();
        if (shared == nullptr) {
            return nullptr;
        }
        auto ptr = new Widget::Ptr(nullptr);
        ptr->swap(shared);
        return ptr;
    }

    C_ABI Widget::Ptr* ABI_Container_getFocusedLeaf(Container::Ptr* self) {
        auto shared = (**self).getFocusedLeaf();
        if (shared == nullptr) {
            return nullptr;
        }
        auto ptr = new Widget::Ptr(nullptr);
        ptr->swap(shared);
        return ptr;
    }

    C_ABI Widget::Ptr* ABI_Container_getWidgetAtPosition(Container::Ptr* self, float x, float y) {
        Vector2f v(x, y);
        auto shared = (**self).getWidgetAtPosition(v);
        if (shared == nullptr) {
            return nullptr;
        }
        auto ptr = new Widget::Ptr(nullptr);
        ptr->swap(shared);
        return ptr;
    }

    C_ABI bool ABI_Container_focusNextWidget(Container::Ptr* self, int recursive) {
        return (**self).focusNextWidget(recursive);
    }

    C_ABI bool ABI_Container_focusPreviousWidget(Container::Ptr* self, int recursive) {
        return (**self).focusPreviousWidget(recursive);
    }

    C_ABI bool ABI_Container_processMouseMoveEvent(Container::Ptr* self, float x, float y) {
        return (**self).processMouseMoveEvent({x, y});
    }

    C_ABI bool ABI_Container_processMousePressEvent(Container::Ptr* self, int mouseButton, float x, float y) {
        return (**self).processMousePressEvent(static_cast<Event::MouseButton>(mouseButton), {x, y});
    }

    C_ABI bool ABI_Container_processMouseReleaseEvent(Container::Ptr* self, int mouseButton, float x, float y) {
        return (**self).processMouseReleaseEvent(static_cast<Event::MouseButton>(mouseButton), {x, y});
    }

	C_ABI bool ABI_Container_processScrollEvent(Container::Ptr* self, float delta, float x, float y, int touch) {
        return (**self).processScrollEvent(delta, {x, y}, (bool)touch);
    }

	C_ABI bool ABI_Container_processKeyPressEvent(Container::Ptr* self, int key, int alt, int control, int shift, int system) {
        return (**self).processKeyPressEvent({static_cast<Event::KeyboardKey>(key), (bool)alt, (bool)control, (bool)shift, (bool)system});
    }

	C_ABI bool ABI_Container_processTextEnteredEvent(Container::Ptr* self, int character) {
        return (**self).processTextEnteredEvent(static_cast<char32_t>(character));
    }

    // ChildWindow

    C_ABI ChildWindow::Ptr* ABI_ChildWindow_new() {
        auto self = ChildWindow::create();
        auto ptr = new ChildWindow::Ptr(nullptr);
        ptr->swap(self);
        return ptr;
    }

    C_ABI void ABI_ChildWindow_setClientSize(ChildWindow::Ptr* self, char* width, char* height) {
        (**self).setClientSize({width, height});
    }

    C_ABI Vector2f* ABI_ChildWindow_getClientSize(ChildWindow::Ptr* self) {
        return new Vector2f((**self).getClientSize());
    }

    C_ABI void ABI_ChildWindow_setMaximumSize(ChildWindow::Ptr* self, float x, float y) {
        (**self).setMaximumSize(Vector2f(x, y));
    }

    C_ABI Vector2f* ABI_ChildWindow_getMaximumSize(ChildWindow::Ptr* self) {
        return new Vector2f((**self).getMaximumSize());
    }

    C_ABI void ABI_ChildWindow_setMinimumSize(ChildWindow::Ptr* self, float x, float y) {
        (**self).setMinimumSize(Vector2f(x, y));
    }

    C_ABI Vector2f* ABI_ChildWindow_getMinimumSize(ChildWindow::Ptr* self) {
        return new Vector2f((**self).getMinimumSize());
    }

    C_ABI void ABI_ChildWindow_setTitle(ChildWindow::Ptr* self, char* title) {
        (**self).setTitle(title);
    }

    C_ABI const char32_t* ABI_ChildWindow_getTitle(ChildWindow::Ptr* self) {
        return (**self).getTitle().data();
    }

    C_ABI void ABI_ChildWindow_setTitleTextSize(ChildWindow::Ptr* self, unsigned int size) {
        (**self).setTitleTextSize(size);
    }

    C_ABI unsigned int ABI_ChildWindow_getTitleTextSize(ChildWindow::Ptr* self) {
        return (**self).getTitleTextSize();
    }

    C_ABI void ABI_ChildWindow_setTitleAlignment(ChildWindow::Ptr* self, int alignment) {
        (**self).setTitleAlignment(static_cast<ChildWindow::TitleAlignment>(alignment));
    }

    C_ABI int ABI_ChildWindow_getTitleAlignment(ChildWindow::Ptr* self) {
        return static_cast<int>((**self).getTitleAlignment());
    }

    C_ABI void ABI_ChildWindow_setTitleButtons(ChildWindow::Ptr* self, unsigned int buttons) {
        (**self).setTitleButtons(buttons);
    }

    C_ABI unsigned int ABI_ChildWindow_getTitleButtons(ChildWindow::Ptr* self) {
        return (**self).getTitleButtons();
    }

    C_ABI void ABI_ChildWindow_close(ChildWindow::Ptr* self) {
        (**self).close();
    }

    C_ABI void ABI_ChildWindow_destroy(ChildWindow::Ptr* self) {
        (**self).destroy();
    }

    C_ABI void ABI_ChildWindow_setResizable(ChildWindow::Ptr* self, int resizable) {
        (**self).setResizable(resizable);
    }

    C_ABI bool ABI_ChildWindow_isResizable(ChildWindow::Ptr* self) { 
        return (**self).isResizable();
    }

    C_ABI void ABI_ChildWindow_setPositionLocked(ChildWindow::Ptr* self, int positionLocked) {
        (**self).setPositionLocked(positionLocked);
    }

    C_ABI bool ABI_ChildWindow_isPositionLocked(ChildWindow::Ptr* self) {
        return (**self).isPositionLocked();
    }

    C_ABI void ABI_ChildWindow_setKeepInParent(ChildWindow::Ptr* self, int enabled) {
        (**self).setKeepInParent(enabled);
    }

    C_ABI bool ABI_ChildWindow_isKeptInParent(ChildWindow::Ptr* self) {
        return (**self).isKeptInParent();
    }

    C_ABI Signal* ABI_ChildWindow_onMousePress(ChildWindow::Ptr* self) {
        return &(**self).onMousePress;
    }

    C_ABI Signal* ABI_ChildWindow_onClose(ChildWindow::Ptr* self) {
        return &(**self).onClose;
    }

    C_ABI Signal* ABI_ChildWindow_onMinimize(ChildWindow::Ptr* self) {
        return &(**self).onMinimize;
    }

    C_ABI Signal* ABI_ChildWindow_onMaximize(ChildWindow::Ptr* self) {
        return &(**self).onMaximize;
    }

    C_ABI Signal* ABI_ChildWindow_onEscapeKeyPress(ChildWindow::Ptr* self) {
        return &(**self).onEscapeKeyPress;
    }

    C_ABI SignalTyped<bool*>* ABI_ChildWindow_onClosing(ChildWindow::Ptr* self) {
        return &(**self).onClosing;
    }

    // Group

    C_ABI Group::Ptr* ABI_Group_new() {
        auto self = Group::create();
        auto ptr = new Group::Ptr(nullptr);
        ptr->swap(self);
        return ptr;
    }

    // BoxLayout

    C_ABI Widget::Ptr* ABI_BoxLayout_getByIndex(BoxLayout::Ptr* self, int index) {
        auto widget = (**self).get(index);
        auto ptr = new Widget::Ptr(nullptr);
        ptr->swap(widget);
        return ptr;
    }

    C_ABI void ABI_BoxLayout_insert(BoxLayout::Ptr* self, int index, Widget::Ptr* widget, char* name) {
        (**self).insert(index, *widget, name);
    }

    C_ABI bool ABI_BoxLayout_removeByIndex(BoxLayout::Ptr* self, int index) {
        return (**self).remove(index);
    }

    // BoxLayoutRatios

    C_ABI void ABI_BoxLayoutRatios_addSpace(BoxLayoutRatios::Ptr* self, float ratio) {
        (**self).addSpace(ratio);
    }

    C_ABI void ABI_BoxLayoutRatios_insertSpace(BoxLayoutRatios::Ptr* self, int index, float ratio) {
        (**self).insertSpace(index, ratio);
    }

    C_ABI void ABI_BoxLayoutRatios_setRatio(BoxLayoutRatios::Ptr* self, Widget::Ptr* widget, float ratio) {
        (**self).setRatio(*widget, ratio);
    }

    C_ABI void ABI_BoxLayoutRatios_setRatioByIndex(BoxLayoutRatios::Ptr* self, int index, float ratio) {
        (**self).setRatio(index, ratio);
    }

    C_ABI float ABI_BoxLayoutRatios_getRatio(BoxLayoutRatios::Ptr* self, Widget::Ptr* widget) {
        return (**self).getRatio(*widget);
    }

    C_ABI float ABI_BoxLayoutRatios_getRatioByIndex(BoxLayoutRatios::Ptr* self, int index) {
        return (**self).getRatio(index);
    }

    // HorizontalLayout

    C_ABI HorizontalLayout::Ptr* ABI_HorizontalLayout_new() {
        auto layout = HorizontalLayout::create();
        auto ptr = new HorizontalLayout::Ptr(nullptr);
        ptr->swap(layout);
        return ptr;
    }

    // VerticalLayout

    C_ABI VerticalLayout::Ptr* ABI_VerticalLayout_new() {
        auto layout = VerticalLayout::create();
        auto ptr = new VerticalLayout::Ptr(nullptr);
        ptr->swap(layout);
        return ptr;
    }

    // HorizontalWrap

    C_ABI HorizontalWrap::Ptr* ABI_HorizontalWrap_new() {
        auto layout = HorizontalWrap::create();
        auto ptr = new HorizontalWrap::Ptr(nullptr);
        ptr->swap(layout);
        return ptr;
    }

    // RadioButtonGroup

    C_ABI RadioButtonGroup::Ptr* ABI_RadioButtonGroup_new() {
        auto group = RadioButtonGroup::create();
        auto ptr = new RadioButtonGroup::Ptr(nullptr);
        ptr->swap(group);
        return ptr;
    }

    C_ABI void ABI_RadioButtonGroup_uncheckRadioButtons(RadioButtonGroup::Ptr* self) {
        (**self).uncheckRadioButtons();
    }

    C_ABI RadioButton::Ptr* ABI_RadioButtonGroup_getCheckedRadioButton(RadioButtonGroup::Ptr* self) {
        auto button = (**self).getCheckedRadioButton();
        if (button == nullptr) {
            return nullptr;
        }
        auto ptr = new RadioButton::Ptr(nullptr);
        ptr->swap(button);
        return ptr;
    }

    // Panel

    C_ABI Panel::Ptr* ABI_Panel_new() {
        auto panel = Panel::create();
        auto ptr = new Panel::Ptr(nullptr);
        ptr->swap(panel);
        return ptr;
    }

    C_ABI SignalVector2f* ABI_Panel_onMousePress(Panel::Ptr* self) {
        return &(**self).onMousePress;
    }

    C_ABI SignalVector2f* ABI_Panel_onMouseRelease(Panel::Ptr* self) {
        return &(**self).onMouseRelease;
    }

    C_ABI SignalVector2f* ABI_Panel_onClick(Panel::Ptr* self) {
        return &(**self).onClick;
    }

    C_ABI SignalVector2f* ABI_Panel_onDoubleClick(Panel::Ptr* self) {
        return &(**self).onDoubleClick;
    }

    C_ABI SignalVector2f* ABI_Panel_onRightMousePress(Panel::Ptr* self) {
        return &(**self).onRightMousePress;
    }

    C_ABI SignalVector2f* ABI_Panel_onRightMouseRelease(Panel::Ptr* self) {
        return &(**self).onRightMouseRelease;
    }

    C_ABI SignalVector2f* ABI_Panel_onRightClick(Panel::Ptr* self) {
        return &(**self).onRightClick;
    }

    // ScrollablePanel

    C_ABI ScrollablePanel::Ptr* ABI_ScrollablePanel_new() {
        auto panel = ScrollablePanel::create();
        auto ptr = new ScrollablePanel::Ptr(nullptr);
        ptr->swap(panel);
        return ptr;
    }

    C_ABI void ABI_ScrollablePanel_setContentSize(ScrollablePanel::Ptr* self, float x, float y) {
        (**self).setContentSize(Vector2f(x, y));
    }

    C_ABI Vector2f* ABI_ScrollablePanel_getContentSize(ScrollablePanel::Ptr* self) {
        return new Vector2f((**self).getContentSize());
    }

    C_ABI Vector2f* ABI_ScrollablePanel_getContentOffset(ScrollablePanel::Ptr* self) {
        return new Vector2f((**self).getContentOffset());
    }

    C_ABI float ABI_ScrollablePanel_getScrollbarWidth(ScrollablePanel::Ptr* self) {
        return (**self).getScrollbarWidth();
    }

    C_ABI void ABI_ScrollablePanel_setVerticalScrollbarPolicy(ScrollablePanel::Ptr* self, int policy) {
        (**self).setVerticalScrollbarPolicy(static_cast<Scrollbar::Policy>(policy));
    }

    C_ABI int ABI_ScrollablePanel_getVerticalScrollbarPolicy(ScrollablePanel::Ptr* self) {
        return static_cast<int>((**self).getVerticalScrollbarPolicy());
    }

    C_ABI void ABI_ScrollablePanel_setHorizontalScrollbarPolicy(ScrollablePanel::Ptr* self, int policy) {
        (**self).setHorizontalScrollbarPolicy(static_cast<Scrollbar::Policy>(policy));
    }

    C_ABI int ABI_ScrollablePanel_getHorizontalScrollbarPolicy(ScrollablePanel::Ptr* self) {
        return static_cast<int>((**self).getHorizontalScrollbarPolicy());
    }

    C_ABI void ABI_ScrollablePanel_setVerticalScrollAmount(ScrollablePanel::Ptr* self, int amount) {
        (**self).setVerticalScrollAmount(amount);
    }

    C_ABI int ABI_ScrollablePanel_getVerticalScrollAmount(ScrollablePanel::Ptr* self) {
        return static_cast<int>((**self).getVerticalScrollAmount());
    }

    C_ABI void ABI_ScrollablePanel_setHorizontalScrollAmount(ScrollablePanel::Ptr* self, int amount) {
        (**self).setHorizontalScrollAmount(amount);
    }

    C_ABI int ABI_ScrollablePanel_getHorizontalScrollAmount(ScrollablePanel::Ptr* self) {
        return static_cast<int>((**self).getHorizontalScrollAmount());
    }

    C_ABI void ABI_ScrollablePanel_setVerticalScrollbarValue(ScrollablePanel::Ptr* self, int value) {
        (**self).setVerticalScrollbarValue(value);
    }

    C_ABI int ABI_ScrollablePanel_getVerticalScrollbarValue(ScrollablePanel::Ptr* self) {
        return static_cast<int>((**self).getVerticalScrollbarValue());
    }

    C_ABI void ABI_ScrollablePanel_setHorizontalScrollbarValue(ScrollablePanel::Ptr* self, int value) {
        (**self).setHorizontalScrollbarValue(value);
    }

    C_ABI int ABI_ScrollablePanel_getHorizontalScrollbarValue(ScrollablePanel::Ptr* self) {
        return static_cast<int>((**self).getHorizontalScrollbarValue());
    }

    // Grid

    C_ABI Grid::Ptr* ABI_Grid_new() {
        auto grid = Grid::create();
        auto ptr = new Grid::Ptr(nullptr);
        ptr->swap(grid);
        return ptr;
    }

	C_ABI void ABI_Grid_setAutoSize(Grid::Ptr* self, int autoSize) {
        (**self).setAutoSize(autoSize);
    }

	C_ABI bool ABI_Grid_isAutoSize(Grid::Ptr* self) {
        return (**self).getAutoSize();
    }

	C_ABI bool ABI_Grid_setWidgetCell(Grid::Ptr* self, Widget::Ptr* widget, int row, int column) {
        auto alignment = (**self).getWidgetAlignment(row, column);
        auto padding = (**self).getWidgetPadding(row, column);
        return (**self).setWidgetCell(*widget, row, column, alignment, padding);
    }

	C_ABI Widget::Ptr* ABI_Grid_getWidget(Grid::Ptr* self, int row, int column) {
        auto widget = (**self).getWidget(row, column);
        auto ptr = new Widget::Ptr(nullptr);
        ptr->swap(widget);
        return ptr;
    }

	C_ABI void ABI_Grid_setWidgetPadding(Grid::Ptr* self, Widget::Ptr* widget, char* paddingLeft, char* paddingRight, char* paddingTop, char* paddingBottom) {
        (**self).setWidgetPadding(*widget, Padding(paddingLeft, paddingRight, paddingTop, paddingBottom));
    }

	C_ABI Outline* ABI_Grid_getWidgetPadding(Grid::Ptr* self, Widget::Ptr* widget) {
        auto o = (**self).getWidgetPadding(*widget);
        return new Padding(o.getLeft(), o.getRight(), o.getTop(), o.getBottom());
    }

	C_ABI void ABI_Grid_setWidgetAlignment(Grid::Ptr* self, Widget::Ptr* widget, int alignment) {
        (**self).setWidgetAlignment(*widget, static_cast<Grid::Alignment>(alignment));
    }

	C_ABI int ABI_Grid_getWidgetAlignment(Grid::Ptr* self, Widget::Ptr* widget) {
        return static_cast<int>((**self).getWidgetAlignment(*widget));
    }

    C_ABI void ABI_Grid_getWidgetLocations(Grid::Ptr* self, void(*f)(Widget::Ptr*, const char32_t*, int, int)) {
        for(auto &it : (**self).getWidgetLocations()) {
            auto ptr = new Widget::Ptr(nullptr);
            auto widgetPtr = it.first;
            ptr->swap(widgetPtr);
            f(ptr, it.first->getWidgetType().data(), static_cast<int>(std::get<0>(it.second)), static_cast<int>(std::get<1>(it.second)));
        }
    }

    // ListBox

    C_ABI ListBox::Ptr* ABI_ListBox_new() {
        auto view = ListBox::create();
        auto ptr = new ListBox::Ptr(nullptr);
        ptr->swap(view);
        return ptr;
    }

	C_ABI int ABI_ListBox_addItem(ListBox::Ptr* self, char* itemName, char* id) {
        return static_cast<int>((**self).addItem(itemName, id));
    }

	C_ABI bool ABI_ListBox_setSelectedItem(ListBox::Ptr* self, char* itemName) {
        return (**self).setSelectedItem(itemName);
    }

	C_ABI bool ABI_ListBox_setSelectedItemById(ListBox::Ptr* self, char* id) {
        return (**self).setSelectedItemById(id);
    }

	C_ABI bool ABI_ListBox_setSelectedItemByIndex(ListBox::Ptr* self, int index) {
        return (**self).setSelectedItemByIndex(index);
    }

	C_ABI void ABI_ListBox_deselectItem(ListBox::Ptr* self) {
        (**self).deselectItem();
    }

	C_ABI bool ABI_ListBox_removeItem(ListBox::Ptr* self, char* itemName) {
        return (**self).removeItem(itemName);
    }

	C_ABI bool ABI_ListBox_removeItemById(ListBox::Ptr* self, char* id) {
        return (**self).removeItemById(id);
    }

	C_ABI bool ABI_ListBox_removeItemByIndex(ListBox::Ptr* self, int index) {
        return (**self).removeItemByIndex(index);
    }

	C_ABI void ABI_ListBox_removeAllItems(ListBox::Ptr* self) {
        (**self).removeAllItems();
    }

	C_ABI const char32_t* ABI_ListBox_getItemById(ListBox::Ptr* self, char* id) {
        auto str = new String((**self).getItemById(id));
        autoclean.push_back(str);
        return str->data();
    }

	C_ABI const char32_t* ABI_ListBox_getItemByIndex(ListBox::Ptr* self, int index) {
        auto str = new String((**self).getItemByIndex(index));
        autoclean.push_back(str);
        return str->data();
    }

	C_ABI int ABI_ListBox_getIndexById(ListBox::Ptr* self, char* id) {
        return (**self).getIndexById(id);
    }

	C_ABI const char32_t* ABI_ListBox_getIdByIndex(ListBox::Ptr* self, int index) {
        auto str = new String((**self).getIdByIndex(index));
        autoclean.push_back(str);
        return str->data();
    }

	C_ABI const char32_t* ABI_ListBox_getSelectedItem(ListBox::Ptr* self) {
        auto str = new String((**self).getSelectedItem());
        autoclean.push_back(str);
        return str->data();
    }

	C_ABI const char32_t* ABI_ListBox_getSelectedItemId(ListBox::Ptr* self) {
        auto str = new String((**self).getSelectedItemId());
        autoclean.push_back(str);
        return str->data();
    }

	C_ABI const int ABI_ListBox_getSelectedItemIndex(ListBox::Ptr* self) {
        return (**self).getSelectedItemIndex();
    }

	C_ABI bool ABI_ListBox_changeItem(ListBox::Ptr* self, char* originalValue, char* newValue) {
        return (**self).changeItem(originalValue, newValue);
    }

	C_ABI bool ABI_ListBox_changeItemById(ListBox::Ptr* self, char* id, char* newValue) {
        return (**self).changeItemById(id, newValue);
    }

	C_ABI bool ABI_ListBox_changeItemByIndex(ListBox::Ptr* self, int index, char* newValue) {
        return (**self).changeItemByIndex(index, newValue);
    }

	C_ABI int ABI_ListBox_getItemCount(ListBox::Ptr* self) {
        return static_cast<int>((**self).getItemCount());
    }

	C_ABI void ABI_ListBox_getItems(ListBox::Ptr* self, void(*f)(const char32_t*)) {
        for(auto item : (**self).getItems()) {
            f(item.data());
        }
    }

	C_ABI void ABI_ListBox_getItemIds(ListBox::Ptr* self, void(*f)(const char32_t*)) {
        for(auto item : (**self).getItemIds()) {
            f(item.data());
        }
    }

	C_ABI void ABI_ListBox_setItemHeight(ListBox::Ptr* self, int itemHeight) {
        (**self).setItemHeight(itemHeight);
    }

	C_ABI int ABI_ListBox_getItemHeight(ListBox::Ptr* self) {
        return (**self).getItemHeight();
    }

	C_ABI void ABI_ListBox_setMaximumItems(ListBox::Ptr* self, int maximumItems) {
        (**self).setMaximumItems(maximumItems);
    }

	C_ABI int ABI_ListBox_getMaximumItems(ListBox::Ptr* self) {
        return static_cast<int>((**self).getMaximumItems());
    }

	C_ABI void ABI_ListBox_setAutoScroll(ListBox::Ptr* self, int autoScroll) {
        (**self).setAutoScroll(autoScroll);
    }

	C_ABI bool ABI_ListBox_getAutoScroll(ListBox::Ptr* self){
        return (**self).getAutoScroll();
    }

	C_ABI void ABI_ListBox_setTextAlignment(ListBox::Ptr* self, int alignment) {
        (**self).setTextAlignment(static_cast<ListBox::TextAlignment>(alignment));
    }

	C_ABI int ABI_ListBox_getTextAlignment(ListBox::Ptr* self) {
        return static_cast<int>((**self).getTextAlignment());
    }

	C_ABI bool ABI_ListBox_contains(ListBox::Ptr* self, char* item) {
        return (**self).contains(item);
    }

	C_ABI bool ABI_ListBox_containsId(ListBox::Ptr* self, char* id) {
        return (**self).containsId(id);
    }

	C_ABI void ABI_ListBox_setScrollbarValue(ListBox::Ptr* self, int value) {
        (**self).setScrollbarValue(value);
    }

	C_ABI int ABI_ListBox_getScrollbarValue(ListBox::Ptr* self) {
        return (**self).getScrollbarValue();
    }

	C_ABI SignalItem* ABI_ListBox_onItemSelect(ListBox::Ptr* self) {
        return &(**self).onItemSelect;
    }

	C_ABI SignalItem* ABI_ListBox_onMousePress(ListBox::Ptr* self) {
        return &(**self).onMousePress;
    }

	C_ABI SignalItem* ABI_ListBox_onMouseRelease(ListBox::Ptr* self) {
        return &(**self).onMouseRelease;
    }

	C_ABI SignalItem* ABI_ListBox_onDoubleClick(ListBox::Ptr* self) {
        return &(**self).onDoubleClick;
    }

	C_ABI Signal* ABI_ListBox_onScroll(ListBox::Ptr* self) {
        return &(**self).onScroll;
    }

    // ListView

	C_ABI ListView::Ptr* ABI_ListView_new() {
        auto view = ListView::create();
        auto ptr = new ListView::Ptr(nullptr);
        ptr->swap(view);
        return ptr;
    }

	C_ABI int ABI_ListView_addColumn(ListView::Ptr* self) {
        return static_cast<int>((**self).addColumn(""));
    }

	C_ABI void ABI_ListView_setColumnText(ListView::Ptr* self, int index, char* text) {
        (**self).setColumnText(index, text);
    }

	C_ABI const char32_t* ABI_ListView_getColumnText(ListView::Ptr* self, int index) {
        auto str = new String((**self).getColumnText(index));
        autoclean.push_back(str);
        return str->data();
    }

	C_ABI void ABI_ListView_setColumnWidth(ListView::Ptr* self, int index, float width) {
        (**self).setColumnWidth(index, width);
    }

	C_ABI float ABI_ListView_getColumnWidth(ListView::Ptr* self, int index) {
        return (**self).getColumnWidth(index);
    }

	C_ABI void ABI_ListView_setColumnAlignment(ListView::Ptr* self, int index, int columnAlignment) {
        (**self).setColumnAlignment(index, static_cast<ListView::ColumnAlignment>(columnAlignment));
    }

	C_ABI int ABI_ListView_getColumnAlignment(ListView::Ptr* self, int index) {
        return static_cast<int>((**self).getColumnAlignment(index));
    }

    C_ABI void ABI_ListView_setColumnAutoResize(ListView::Ptr* self, int index, int autoResize) {
        (**self).setColumnAutoResize(index, autoResize);
    }

	C_ABI bool ABI_ListView_getColumnAutoResize(ListView::Ptr* self, int index) {
        return (**self).getColumnAutoResize(index);
    }

	C_ABI void ABI_ListView_setColumnExpanded(ListView::Ptr* self, int index, int expanded) {
        (**self).setColumnExpanded(index, expanded);
    }

	C_ABI bool ABI_ListView_getColumnExpanded(ListView::Ptr* self, int index) {
        return (**self).getColumnExpanded(index);
    }

	C_ABI void ABI_ListView_removeAllColumns(ListView::Ptr* self) {
        (**self).removeAllColumns();
    }

	C_ABI int ABI_ListView_getColumnCount(ListView::Ptr* self) {
        return static_cast<int>((**self).getColumnCount());
    }

	C_ABI void ABI_ListView_setHeaderHeight(ListView::Ptr* self, float height) {
        (**self).setHeaderHeight(height);
    }

	C_ABI float ABI_ListView_getHeaderHeight(ListView::Ptr* self) {
        return (**self).getHeaderHeight();
    }

	C_ABI float ABI_ListView_getCurrentHeaderHeight(ListView::Ptr* self) {
        return (**self).getCurrentHeaderHeight();
    }

	C_ABI void ABI_ListView_setHeaderVisible(ListView::Ptr* self, int showHeader) {
        (**self).setHeaderVisible(showHeader);
    }

	C_ABI bool ABI_ListView_headerVisible(ListView::Ptr* self) {
        return (**self).getHeaderVisible();
    }

	C_ABI int ABI_ListView_addItem(ListView::Ptr* self, char*(*f)(void)) {
        auto columnsCount = (**self).getColumnCount();
        std::vector<String> vec;
        for(int i = 0;i < columnsCount; ++i) {
            vec.push_back(f());
        }
        return static_cast<int>((**self).addItem(vec));
    }

	C_ABI void ABI_ListView_insertItem(ListView::Ptr* self, int index, char*(*f)(void)) {
        auto columnsCount = (**self).getColumnCount();
        std::vector<String> vec;
        for(int i = 0;i < columnsCount; ++i) {
            vec.push_back(f());
        }
        (**self).insertItem(index, vec);
    }

	C_ABI bool ABI_ListView_changeItem(ListView::Ptr* self, int index, char*(*f)(void)) {
        auto columnsCount = (**self).getColumnCount();
        std::vector<String> vec;
        for(int i = 0;i < columnsCount; ++i) {
            vec.push_back(f());
        }
        return (**self).changeItem(index, vec);
    }

	C_ABI bool ABI_ListView_changeSubitem(ListView::Ptr* self, int index, int column, char* item) {
        return (**self).changeSubItem(index, column, item);
    }

	C_ABI bool ABI_ListView_removeItem(ListView::Ptr* self, int index) {
        return (**self).removeItem(index);
    }

	C_ABI void ABI_ListView_removeAllItems(ListView::Ptr* self) {
        (**self).removeAllItems();
    }

	C_ABI void ABI_ListView_setSelectedItem(ListView::Ptr* self, int index) {
        (**self).setSelectedItem(index);
    }

	C_ABI void ABI_ListView_setSelectedItems(ListView::Ptr* self, int(*f)(void)) {
        std::set<std::size_t> indices;
        int index = f();
        while(index >= 0) {
            indices.insert(index);
            index = f();
        }
        (**self).setSelectedItems(indices);
    }

	C_ABI void ABI_ListView_deselectItems(ListView::Ptr* self) {
        (**self).deselectItems();
    }

	C_ABI int ABI_ListView_getSelectedItemIndex(ListView::Ptr* self) {
        return (**self).getSelectedItemIndex();
    }

	C_ABI void ABI_ListView_getSelectedItemIndices(ListView::Ptr* self, void(*f)(int)) {
        auto indices = (**self).getSelectedItemIndices();
        for(auto index : indices) {
            f(static_cast<int>(index));
        }
    }

	C_ABI void ABI_ListView_setMultiSelect(ListView::Ptr* self, int multiSelect) {
        (**self).setMultiSelect(multiSelect);
    }

	C_ABI bool ABI_ListView_multiSelect(ListView::Ptr* self) {
        return (**self).getMultiSelect();
    }

	C_ABI void ABI_ListView_setItemIcon(ListView::Ptr* self, int index, Texture* texture) {
        (**self).setItemIcon(index, *texture);
    }

	C_ABI Texture* ABI_ListView_getItemIcon(ListView::Ptr* self, int index) {
        return new Texture((**self).getItemIcon(index));
    }

	C_ABI int ABI_ListView_getItemCount(ListView::Ptr* self) {
        return static_cast<int>((**self).getItemCount());
    }

	C_ABI void ABI_ListView_getItemRow(ListView::Ptr* self, int index, void(*f)(const char32_t*)) {
        auto row = (**self).getItemRow(index);
        for(auto text : row) {
            f(text.data());
        }
    }

	C_ABI const char32_t* ABI_ListView_getItemCell(ListView::Ptr* self, int rowIndex, int columnIndex) {
        auto cell = new String((**self).getItemCell(rowIndex, columnIndex));
        autoclean.push_back(cell);
        return cell->data();
    }

	C_ABI void ABI_ListView_getItemRows(ListView::Ptr* self, void(*f)(const char32_t*, int row)) {
        auto rows = (**self).getItemRows();
        int rowIndex = 0;
        for(auto row : rows) {
            for(auto text : row) {
                f(text.data(), rowIndex);
            }
            ++rowIndex;
        }
    }

	C_ABI void ABI_ListView_setItemHeight(ListView::Ptr* self, int itemHeight) {
        (**self).setItemHeight(itemHeight);
    }

	C_ABI int ABI_ListView_getItemHeight(ListView::Ptr* self) {
        return (**self).getItemHeight();
    }

	C_ABI void ABI_ListView_setHeaderTextSize(ListView::Ptr* self, int textSize) {
        (**self).setHeaderTextSize(textSize);
    }

	C_ABI int ABI_ListView_getHeaderTextSize(ListView::Ptr* self) {
        return (**self).getHeaderTextSize();
    }

	C_ABI void ABI_ListView_setSeparatorWidth(ListView::Ptr* self, int width) {
        (**self).setSeparatorWidth(width);
    }

	C_ABI int ABI_ListView_getSeparatorWidth(ListView::Ptr* self) {
        return (**self).getSeparatorWidth();
    }

	C_ABI void ABI_ListView_setHeaderSeparatorHeight(ListView::Ptr* self, int height) {
        (**self).setHeaderSeparatorHeight(height);
    }

	C_ABI int ABI_ListView_getHeaderSeparatorHeight(ListView::Ptr* self) {
        return (**self).getHeaderSeparatorHeight();
    }

	C_ABI void ABI_ListView_setGridLinesWidth(ListView::Ptr* self, int width) {
        (**self).setGridLinesWidth(width);
    }

	C_ABI int ABI_ListView_getGridLinesWidth(ListView::Ptr* self) {
        return (**self).getGridLinesWidth();
    }

	C_ABI void ABI_ListView_setAutoScroll(ListView::Ptr* self, int autoScroll) {
        (**self).setAutoScroll(autoScroll);
    }

	C_ABI bool ABI_ListView_autoScroll(ListView::Ptr* self) {
        return (**self).getAutoScroll();
    }

	C_ABI void ABI_ListView_setShowVerticalGridLines(ListView::Ptr* self, int showGridLines) {
        (**self).setShowVerticalGridLines(showGridLines);
    }

	C_ABI bool ABI_ListView_showVerticalGridLines(ListView::Ptr* self) {
        return (**self).getShowVerticalGridLines();
    }

	C_ABI void ABI_ListView_setShowHorizontalGridLines(ListView::Ptr* self, int showGridLines) {
        (**self).setShowHorizontalGridLines(showGridLines);
    }

	C_ABI bool ABI_ListView_showHorizontalGridLines(ListView::Ptr* self) {
        return (**self).getShowHorizontalGridLines();
    }

	C_ABI void ABI_ListView_setVerticalScrollbarPolicy(ListView::Ptr* self, int policy) {
        (**self).setVerticalScrollbarPolicy(static_cast<Scrollbar::Policy>(policy));
    }

	C_ABI int ABI_ListView_getVerticalScrollbarPolicy(ListView::Ptr* self) {
        return static_cast<int>((**self).getVerticalScrollbarPolicy());
    }

	C_ABI void ABI_ListView_setHorizontalScrollbarPolicy(ListView::Ptr* self, int policy) {
        (**self).setHorizontalScrollbarPolicy(static_cast<Scrollbar::Policy>(policy));
    }

	C_ABI int ABI_ListView_getHorizontalScrollbarPolicy(ListView::Ptr* self) {
        return static_cast<int>((**self).getHorizontalScrollbarPolicy());
    }

	C_ABI void ABI_ListView_setVerticalScrollbarValue(ListView::Ptr* self, int value) {
        (**self).setVerticalScrollbarValue(value);
    }

	C_ABI int ABI_ListView_getVerticalScrollbarValue(ListView::Ptr* self) {
        return (**self).getVerticalScrollbarValue();
    }

	C_ABI void ABI_ListView_setHorizontalScrollbarValue(ListView::Ptr* self, int value) {
        (**self).setHorizontalScrollbarValue(value);
    }

	C_ABI int ABI_ListView_getHorizontalScrollbarValue(ListView::Ptr* self) {
        return (**self).getHorizontalScrollbarValue();
    }

	C_ABI void ABI_ListView_setFixedIconSize(ListView::Ptr* self, float width, float height) {
        (**self).setFixedIconSize(Vector2f(width, height));
    }

	C_ABI Vector2f* ABI_ListView_getFixedIconSize(ListView::Ptr* self) {
        return new Vector2f((**self).getFixedIconSize());
    }

	C_ABI void ABI_ListView_setResizableColumns(ListView::Ptr* self, int resizable) {
        (**self).setResizableColumns(resizable);
    }

	C_ABI bool ABI_ListView_resizableColumns(ListView::Ptr* self) {
        return (**self).getResizableColumns();
    }

	C_ABI SignalInt* ABI_ListView_onItemSelect(ListView::Ptr* self) {
        return &(**self).onItemSelect;
    }

	C_ABI SignalInt* ABI_ListView_onDoubleClick(ListView::Ptr* self) {
        return &(**self).onDoubleClick;
    }

	C_ABI SignalInt* ABI_ListView_onRightClick(ListView::Ptr* self) {
        return &(**self).onRightClick;
    }

	C_ABI SignalInt* ABI_ListView_onHeaderClick(ListView::Ptr* self) {
        return &(**self).onHeaderClick;
    }

    // ComboBox

	C_ABI ComboBox::Ptr* ABI_ComboBox_new() {
        auto combo = ComboBox::create();
        auto ptr = new ComboBox::Ptr(nullptr);
        ptr->swap(combo);
        return ptr;
    }

	C_ABI void ABI_ComboBox_setItemsToDisplay(ComboBox::Ptr* self, int itemsToDisplay) {
        (**self).setItemsToDisplay(itemsToDisplay);
    }

	C_ABI int ABI_ComboBox_getItemsToDisplay(ComboBox::Ptr* self) {
        return static_cast<int>((**self).getItemsToDisplay());
    }

	C_ABI void ABI_ComboBox_addItem(ComboBox::Ptr* self, char* name, char* id) {
        (**self).addItem(name, id);
    }

	C_ABI bool ABI_ComboBox_setSelectedItemById(ComboBox::Ptr* self, char* id) {
        return (**self).setSelectedItemById(id);
    }

	C_ABI bool ABI_ComboBox_setSelectedItemByIndex(ComboBox::Ptr* self, int index) {
        return (**self).setSelectedItemByIndex(index);
    }

	C_ABI void ABI_ComboBox_deselectItem(ComboBox::Ptr* self) {
        (**self).deselectItem();
    }

	C_ABI bool ABI_ComboBox_removeItemById(ComboBox::Ptr* self, char* id) {
        return (**self).removeItemById(id);
    }

	C_ABI bool ABI_ComboBox_removeItemByIndex(ComboBox::Ptr* self, int index) {
        return (**self).removeItemByIndex(index);
    }

	C_ABI void ABI_ComboBox_removeAllItems(ComboBox::Ptr* self) {
        (**self).removeAllItems();
    }

	C_ABI char32_t* ABI_ComboBox_getItemById(ComboBox::Ptr* self, char* id) {
        auto item = new String((**self).getItemById(id));
        autoclean.push_back(item);
        return item->data();
    }

	C_ABI char32_t* ABI_ComboBox_getSelectedItemId(ComboBox::Ptr* self) {
        auto id = new String((**self).getSelectedItemId());
        autoclean.push_back(id);
        return id->data();
    }

	C_ABI bool ABI_ComboBox_changeItemById(ComboBox::Ptr* self, char* id, char* newValue) {
        return (**self).changeItemById(id, newValue);
    }

	C_ABI bool ABI_ComboBox_changeItemByIndex(ComboBox::Ptr* self, int index, char* newValue) {
        return (**self).changeItemByIndex(index, newValue);
    }

	C_ABI int ABI_ComboBox_getItemCount(ComboBox::Ptr* self) {
        return static_cast<int>((**self).getItemCount());
    }

	C_ABI void ABI_ComboBox_getItemIds(ComboBox::Ptr* self, void(*f)(char32_t*)) {
        for (auto id : (**self).getItemIds()) {
            f(id.data());
        }
    }

	C_ABI void ABI_ComboBox_setMaximumItems(ComboBox::Ptr* self, int maximumItems) {
        (**self).setMaximumItems(maximumItems);
    }

	C_ABI int ABI_ComboBox_getMaximumItems(ComboBox::Ptr* self) {
        return static_cast<int>((**self).getMaximumItems());
    }

	C_ABI void ABI_ComboBox_setDefaultText(ComboBox::Ptr* self, char* defaultText) {
        (**self).setDefaultText(defaultText);
    }

	C_ABI const char32_t* ABI_ComboBox_getDefaultText(ComboBox::Ptr* self) {
        return (**self).getDefaultText().data();
    }

	C_ABI void ABI_ComboBox_setExpandDirection(ComboBox::Ptr* self, int expandDirection) {
        (**self).setExpandDirection(static_cast<ComboBox::ExpandDirection>(expandDirection));
    }

	C_ABI int ABI_ComboBox_getExpandDirection(ComboBox::Ptr* self) {
        return static_cast<int>((**self).getExpandDirection());
    }

	C_ABI bool ABI_ComboBox_containsId(ComboBox::Ptr* self, char* id) {
        return (**self).containsId(id);
    }

	C_ABI void ABI_ComboBox_setChangeItemOnScroll(ComboBox::Ptr* self, int changeItemOnScroll) {
        (**self).setChangeItemOnScroll(changeItemOnScroll);
    }

	C_ABI bool ABI_ComboBox_getChangeItemOnScroll(ComboBox::Ptr* self) {
        return (**self).getChangeItemOnScroll();
    }

	C_ABI SignalItem* ABI_ComboBox_onItemSelect(ComboBox::Ptr* self) {
        return &(**self).onItemSelect;
    }
    
    // ColorPicker

    C_ABI ColorPicker::Ptr* ABI_ColorPicker_new() {
        auto self = ColorPicker::create();
        auto ptr = new ColorPicker::Ptr(nullptr);
        ptr->swap(self);
        return ptr;
    }

    C_ABI void ABI_ColorPicker_setColor(ColorPicker::Ptr* self, Color* color) {
        (**self).setColor(*color);
    }

    C_ABI Color* ABI_ColorPicker_getColor(ColorPicker::Ptr* self) {
        return new Color((**self).getColor());
    }

    C_ABI SignalColor* ABI_ColorPicker_onColorChange(ColorPicker::Ptr* self) {
        return &(**self).onColorChange;
    }

    C_ABI SignalColor* ABI_ColorPicker_onOkPress(ColorPicker::Ptr* self) {
        return &(**self).onOkPress;
    }

    // FileDialog

    C_ABI FileDialog::Ptr* ABI_FileDialog_new() {
        auto self = FileDialog::create();
        auto ptr = new FileDialog::Ptr(nullptr);
        ptr->swap(self);
        return ptr;
    }

	C_ABI void ABI_FileDialog_getSelectedPaths(FileDialog::Ptr* self, void(*f)(char32_t*)) {
        for (auto path : (**self).getSelectedPaths()) {
            f(path.asString().data());
        }
    }

	C_ABI void ABI_FileDialog_setPath(FileDialog::Ptr* self, char* path) {
        (**self).setPath(path);
    }

	C_ABI const char32_t* ABI_FileDialog_getPath(FileDialog::Ptr* self) {
        auto path = new String((**self).getPath().asString());
        autoclean.push_back(path);
        return path->data();
    }

	C_ABI void ABI_FileDialog_setFilename(FileDialog::Ptr* self, char* filename) {
        (**self).setFilename(filename);
    }

	C_ABI const char32_t* ABI_FileDialog_getFilename(FileDialog::Ptr* self) {
        return (**self).getFilename().data();
    }

	C_ABI void ABI_FileDialog_setFileTypeFilters(FileDialog::Ptr* self, int size, int(*f)(void), char*(*f1)(void), int defaultFilterIndex) {
        std::vector< std::pair< String, std::vector< String > > > vec;
        for(int i = 0;i < size; ++i) {
            String base(f1());
            int length = f();
            std::vector<String> vec1;
            for(int j = 0; j < length; ++j) {
                vec1.push_back(f1());
            }
            std::pair pair(base, vec1);
            vec.push_back(pair);
        }
        return (**self).setFileTypeFilters(vec, defaultFilterIndex);
    }

	C_ABI void ABI_FileDialog_getFileTypeFilters(FileDialog::Ptr* self, void(*f)(int, const char32_t*, const char32_t*)) {
        int i = 0;
        for(auto pair : (**self).getFileTypeFilters()) {
            auto base = pair.first.data();
            for(auto filters : pair.second) {
                f(i, base, filters.data());
            }
            ++i;
        }
    }

	C_ABI int ABI_FileDialog_getFileTypeFiltersIndex(FileDialog::Ptr* self) {
        return static_cast<int>((**self).getFileTypeFiltersIndex());
    }

	C_ABI void ABI_FileDialog_setConfirmButtonText(FileDialog::Ptr* self, char* text) {
        (**self).setConfirmButtonText(text);
    }

	C_ABI const char32_t* ABI_FileDialog_getConfirmButtonText(FileDialog::Ptr* self) {
        return (**self).getConfirmButtonText().data();
    }

	C_ABI void ABI_FileDialog_setCancelButtonText(FileDialog::Ptr* self, char* text) {
        (**self).setCancelButtonText(text);
    }

	C_ABI const char32_t* ABI_FileDialog_getCancelButtonText(FileDialog::Ptr* self) {
        return (**self).getCancelButtonText().data();
    }

	C_ABI void ABI_FileDialog_setCreateFolderButtonText(FileDialog::Ptr* self, char* text) {
        (**self).setCreateFolderButtonText(text);
    }

	C_ABI const char32_t* ABI_FileDialog_getCreateFolderButtonText(FileDialog::Ptr* self) {
        return (**self).getCreateFolderButtonText().data();
    }

	C_ABI void ABI_FileDialog_setAllowCreateFolder(FileDialog::Ptr* self, int allowCreateFolder) {
        (**self).setAllowCreateFolder(allowCreateFolder);
    }

	C_ABI bool ABI_FileDialog_getAllowCreateFolder(FileDialog::Ptr* self) {
        return (**self).getAllowCreateFolder();
    }

	C_ABI void ABI_FileDialog_setFilenameLabelText(FileDialog::Ptr* self, char* labelText) {
        (**self).setFilenameLabelText(labelText);
    }

	C_ABI const char32_t* ABI_FileDialog_getFilenameLabelText(FileDialog::Ptr* self) {
        return (**self).getFilenameLabelText().data();
    }

	C_ABI void ABI_FileDialog_setListViewColumnCaptions(FileDialog::Ptr* self, char* nameColumnText, char* sizeColumnText, char* modifiedColumnText) {
        (**self).setListViewColumnCaptions(nameColumnText, sizeColumnText, modifiedColumnText);
    }

	C_ABI void ABI_FileDialog_getListViewColumnCaptions(FileDialog::Ptr* self, void(*f)(const char32_t*)) {
        auto captions = (**self).getListViewColumnCaptions();
        f(std::get<0>(captions).data());
        f(std::get<1>(captions).data());
        f(std::get<2>(captions).data());
    }

	C_ABI void ABI_FileDialog_setFileMustExist(FileDialog::Ptr* self, int enforceExistence) {
        (**self).setFileMustExist(enforceExistence);
    }

	C_ABI bool ABI_FileDialog_getFileMustExist(FileDialog::Ptr* self) {
        return (**self).getFileMustExist();
    }

	C_ABI void ABI_FileDialog_setSelectingDirectory(FileDialog::Ptr* self, int selectDirectories) {
        (**self).setSelectingDirectory(selectDirectories);
    }

	C_ABI bool ABI_FileDialog_getSelectingDirectory(FileDialog::Ptr* self) {
        return (**self).getSelectingDirectory();
    }

	C_ABI void ABI_FileDialog_setMultiSelect(FileDialog::Ptr* self, int multiSelect) {
        (**self).setMultiSelect(multiSelect);
    }

	C_ABI bool ABI_FileDialog_getMultiSelect(FileDialog::Ptr* self) {
        return (**self).getMultiSelect();
    }

	// C_ABI void ABI_FileDialog_setIconLoader(FileDialog::Ptr* self, std::shared_ptr< FileDialogIconLoader >* iconLoader);
	// C_ABI std::shared_ptr< FileDialogIconLoader >* ABI_FileDialog_getIconLoader(FileDialog::Ptr* self);

	C_ABI Signal* ABI_FileDialog_onFileSelect(FileDialog::Ptr* self) {
        return &(**self).onFileSelect;
    }

	C_ABI Signal* ABI_FileDialog_onCancel(FileDialog::Ptr* self) {
        return &(**self).onCancel;
    }
    
    // MessageBox

	C_ABI MessageBox::Ptr* ABI_MessageBox_new() {
        auto self = MessageBox::create();
        auto ptr = new MessageBox::Ptr(nullptr);
        ptr->swap(self);
        return ptr;
    }

	C_ABI void ABI_MessageBox_setText(MessageBox::Ptr* self, char* text) {
        (**self).setText(text);
    }

	C_ABI const char32_t* ABI_MessageBox_getText(MessageBox::Ptr* self) {
        return (**self).getText().data();
    }

	C_ABI void ABI_MessageBox_addButton(MessageBox::Ptr* self, char* button) {
        (**self).addButton(button);
    }

	C_ABI void ABI_MessageBox_changeButtons(MessageBox::Ptr* self, int size, char*(*f)(void)) {
        std::vector<String> vec;
        for(int i = 0;i < size; ++i) {
            vec.push_back(f());
        }
        return (**self).changeButtons(vec);
    }

	C_ABI void ABI_MessageBox_getButtons(MessageBox::Ptr* self, void(*f)(const char32_t*)) {
        for (auto button : (**self).getButtons()) {
            f(button.data());
        }
    }

	C_ABI void ABI_MessageBox_setLabelAlignment(MessageBox::Ptr* self, int alignment) {
        (**self).setLabelAlignment(static_cast<MessageBox::Alignment>(alignment));
    }

	C_ABI int ABI_MessageBox_getLabelAlignment(MessageBox::Ptr* self) {
        return static_cast<int>((**self).getLabelAlignment());
    }

	C_ABI void ABI_MessageBox_setButtonAlignment(MessageBox::Ptr* self, int alignment) {
        (**self).setButtonAlignment(static_cast<MessageBox::Alignment>(alignment));
    }

	C_ABI int ABI_MessageBox_getButtonAlignment(MessageBox::Ptr* self) {
        return static_cast<int>((**self).getButtonAlignment());
    }

    C_ABI SignalString* ABI_MessageBox_onButtonPress(MessageBox::Ptr* self) {
        return &(**self).onButtonPress;
    }

    // Picture

	C_ABI Picture::Ptr* ABI_Picture_new(Texture* texture, int transparent) {
        auto self = Picture::create(*texture, transparent);
        auto ptr = new Picture::Ptr(nullptr);
        ptr->swap(self);
        return ptr;
    }

	C_ABI void ABI_Picture_ignoreMouseEvents(Picture::Ptr* self, int ignore) {
        (**self).ignoreMouseEvents(ignore);
    }

    C_ABI bool ABI_Picture_isIgnoringMouseEvents(Picture::Ptr* self) {
        return (**self).isIgnoringMouseEvents();
    }

	C_ABI SignalVector2f* ABI_Picture_onDoubleClick(Picture::Ptr* self) {
        return &(**self).onDoubleClick;
    }

    // MenuBar

	C_ABI MenuBar::Ptr* ABI_MenuBar_new() {
        auto self = MenuBar::create();
        auto ptr = new MenuBar::Ptr(nullptr);
        ptr->swap(self);
        return ptr;
    }

    C_ABI void ABI_MenuBar_addMenu(MenuBar::Ptr* self, char* text) {
        (**self).addMenu(text);
    }

	C_ABI int ABI_MenuBar_connectMenuItem(MenuBar::Ptr* self, int hierarchySize, char*(*hierarchy)(), void(*handler)()) {
        std::vector<String> vec;
        for(int i = 0;i < hierarchySize; ++i) {
            vec.push_back(hierarchy());
        }
        return (**self).connectMenuItem(vec, handler);
    }

	C_ABI bool ABI_MenuBar_addMenuItem(MenuBar::Ptr* self, int hierarchySize, char*(*hierarchy)()) {
        std::vector<String> vec;
        for(int i = 0;i < hierarchySize; ++i) {
            vec.push_back(hierarchy());
        }
        return (**self).addMenuItem(vec);
    }

	C_ABI bool ABI_MenuBar_changeMenuItem(MenuBar::Ptr* self, int hierarchySize, char*(*hierarchy)(), char* text) {
        std::vector<String> vec;
        for(int i = 0;i < hierarchySize; ++i) {
            vec.push_back(hierarchy());
        }
        return (**self).changeMenuItem(vec, text);
    }

	C_ABI void ABI_MenuBar_removeAllMenus(MenuBar::Ptr* self) {
        (**self).removeAllMenus();
    }

	C_ABI bool ABI_MenuBar_removeMenu(MenuBar::Ptr* self, char* menu) {
        return (**self).removeMenu(menu);
    }

	C_ABI bool ABI_MenuBar_removeMenuItem(MenuBar::Ptr* self, int hierarchySize, char*(*hierarchy)()) {
        std::vector<String> vec;
        for(int i = 0;i < hierarchySize; ++i) {
            vec.push_back(hierarchy());
        }
        return (**self).removeMenuItem(vec);
    }

	C_ABI bool ABI_MenuBar_removeSubMenuItems(MenuBar::Ptr* self, int hierarchySize, char*(*hierarchy)()) {
        std::vector<String> vec;
        for(int i = 0;i < hierarchySize; ++i) {
            vec.push_back(hierarchy());
        }
        return (**self).removeSubMenuItems(vec);
    }

	C_ABI bool ABI_MenuBar_setMenuEnabled(MenuBar::Ptr* self, char* menu, int enabled) {
        return (**self).setMenuEnabled(menu, enabled);
    }

	C_ABI bool ABI_MenuBar_getMenuEnabled(MenuBar::Ptr* self, char* menu) {
        return (**self).getMenuEnabled(menu);
    }

	C_ABI bool ABI_MenuBar_setMenuItemEnabled(MenuBar::Ptr* self, int hierarchySize, char*(*hierarchy)(), int enabled) {
        std::vector<String> vec;
        for(int i = 0;i < hierarchySize; ++i) {
            vec.push_back(hierarchy());
        }
        return (**self).setMenuItemEnabled(vec, enabled);
    }

	C_ABI bool ABI_MenuBar_getMenuItemEnabled(MenuBar::Ptr* self, int hierarchySize, char*(*hierarchy)()) {
        std::vector<String> vec;
        for(int i = 0;i < hierarchySize; ++i) {
            vec.push_back(hierarchy());
        }
        return (**self).getMenuItemEnabled(vec);
    }

	C_ABI void ABI_MenuBar_setMinimumSubMenuWidth(MenuBar::Ptr* self, float minimumWidth) {
        (**self).setMinimumSubMenuWidth(minimumWidth);
    }

	C_ABI float ABI_MenuBar_getMinimumSubMenuWidth(MenuBar::Ptr* self) {
        return (**self).getMinimumSubMenuWidth();
    }

	C_ABI void ABI_MenuBar_setInvertedMenuDirection(MenuBar::Ptr* self, int invertDirection) {
        (**self).setInvertedMenuDirection(invertDirection);
    }

	C_ABI bool ABI_MenuBar_getInvertedMenuDirection(MenuBar::Ptr* self) {
        return (**self).getInvertedMenuDirection();
    }

    void MenuBar_yieldGetMenusElement(std::vector<MenuBar::GetMenusElement> elements, void(*m)(const char32_t*, int), void(*up)()) {
        for(auto element : elements) {
            m(element.text.data(), element.enabled);
            MenuBar_yieldGetMenusElement(element.menuItems, m, up);
            up();
        }
    }

	C_ABI void ABI_MenuBar_getMenus(MenuBar::Ptr* self, void(*m)(const char32_t*, int), void(*up)()) {
        MenuBar_yieldGetMenusElement((**self).getMenus(), m, up);
    }

	C_ABI void ABI_MenuBar_closeMenu(MenuBar::Ptr* self) {
        (**self).closeMenu();
    }

    C_ABI SignalItemHierarchy* ABI_MenuBar_onMenuItemClick(MenuBar::Ptr* self) {
        return &(**self).onMenuItemClick;
    }

    // PanelListBox

    C_ABI PanelListBox::Ptr* ABI_PanelListBox_new() {
        auto self = PanelListBox::create();
        auto ptr = new PanelListBox::Ptr(nullptr);
        ptr->swap(self);
        return ptr;
    }

	C_ABI Panel::Ptr* ABI_PanelListBox_addItem(PanelListBox::Ptr* self, char* id, int index) {
        auto panel = (**self).addItem(id, index);
        auto ptr = new Panel::Ptr(nullptr);
        ptr->swap(panel);
        return ptr;
    }

	C_ABI Panel::Ptr* ABI_PanelListBox_getPanelTemplate(PanelListBox::Ptr* self) {
        auto panel = (**self).getPanelTemplate();
        auto ptr = new Panel::Ptr(nullptr);
        ptr->swap(panel);
        return ptr;
    }

	C_ABI float ABI_PanelListBox_getItemsWidth(PanelListBox::Ptr* self) {
        return (**self).getItemsWidth().getValue();
    }

	C_ABI void ABI_PanelListBox_setItemsHeight(PanelListBox::Ptr* self, char* height) {
        (**self).setItemsHeight(height);
    }

	C_ABI float ABI_PanelListBox_getItemsHeight(PanelListBox::Ptr* self) {
        return (**self).getItemsHeight().getValue();
    }

	C_ABI bool ABI_PanelListBox_setSelectedItem(PanelListBox::Ptr* self, Panel::Ptr* panel) {
        return (**self).setSelectedItem(*panel);
    }

	C_ABI bool ABI_PanelListBox_setSelectedItemById(PanelListBox::Ptr* self, char* id) {
        return (**self).setSelectedItemById(id);
    }

	C_ABI bool ABI_PanelListBox_setSelectedItemByIndex(PanelListBox::Ptr* self, int index) {
        return (**self).setSelectedItemByIndex(index);
    }

	C_ABI void ABI_PanelListBox_deselectItem(PanelListBox::Ptr* self) {
        (**self).deselectItem();
    }

	C_ABI bool ABI_PanelListBox_removeItem(PanelListBox::Ptr* self, Panel::Ptr* panel) {
        return (**self).removeItem(*panel);
    }

	C_ABI bool ABI_PanelListBox_removeItemById(PanelListBox::Ptr* self, char* id) {
        return (**self).removeItemById(id);
    }

	C_ABI bool ABI_PanelListBox_removeItemByIndex(PanelListBox::Ptr* self, int index) {
        return (**self).removeItemByIndex(index);
    }

	C_ABI void ABI_PanelLIstBox_removeAllItems(PanelListBox::Ptr* self) {
        (**self).removeAllItems();
    }

	C_ABI Panel::Ptr* ABI_PanelListBox_getItemById(PanelListBox::Ptr* self, char* id) {
        auto panel = (**self).getItemById(id);
        auto ptr = new Panel::Ptr(nullptr);
        ptr->swap(panel);
        return ptr;
    }

	C_ABI Panel::Ptr* ABI_PanelListBox_getItemByIndex(PanelListBox::Ptr* self, int index) {
        auto panel = (**self).getItemByIndex(index);
        auto ptr = new Panel::Ptr(nullptr);
        ptr->swap(panel);
        return ptr;
    }

	C_ABI int ABI_PanelListBox_getIndexById(PanelListBox::Ptr* self, char* id) {
        return (**self).getIndexById(id);
    }

	C_ABI int ABI_PanelListBox_getIndexByItem(PanelListBox::Ptr* self, Panel::Ptr* panel) {
        return (**self).getIndexByItem(*panel);
    }

	C_ABI const char32_t* ABI_PanelListBox_getIdByIndex(PanelListBox::Ptr* self, int index) {
        auto str = new String((**self).getIdByIndex(index));
        autoclean.push_back(str);
        return str->data();
    }

	C_ABI Panel::Ptr* ABI_PanelListBox_getSelectedItem(PanelListBox::Ptr* self) {
        auto panel = (**self).getSelectedItem();
        auto ptr = new Panel::Ptr(nullptr);
        ptr->swap(panel);
        return ptr;
    }

	C_ABI const char32_t* ABI_PanelListBox_getSelectedItemId(PanelListBox::Ptr* self) {
        auto str = new String((**self).getSelectedItemId());
        autoclean.push_back(str);
        return str->data();
    }

	C_ABI int ABI_PanelListBox_getSelectedItemIndex(PanelListBox::Ptr* self) {
        return (**self).getSelectedItemIndex();
    }

	C_ABI int ABI_PanelListBox_getItemCount(PanelListBox::Ptr* self) {
        return static_cast<int>((**self).getItemCount());
    }

	C_ABI void ABI_PanelListBox_getItems(PanelListBox::Ptr* self, void(*f)(Panel::Ptr*)) {
        for(auto it : (**self).getItems()) {
            auto ptr = new Panel::Ptr(nullptr);
            ptr->swap(it);
            f(ptr);
        }
    }

	C_ABI void ABI_PanelListBox_getItemIds(PanelListBox::Ptr* self, void(*f)(const char32_t*)) {
        for(auto it : (**self).getItemIds()) {
            f(it.data());
        }
    }

	C_ABI void ABI_PanelListBox_setMaximumItems(PanelListBox::Ptr* self, int maximumItems) {
        (**self).setMaximumItems(maximumItems);
    }

	C_ABI int ABI_PanelListBox_getMaximumItems(PanelListBox::Ptr* self) {
        return static_cast<int>((**self).getMaximumItems());
    }

	C_ABI bool ABI_PanelListBox_contains(PanelListBox::Ptr* self, Panel::Ptr* panel) {
        return (**self).contains(*panel);
    }

	C_ABI bool ABI_PanelListBox_containsId(PanelListBox::Ptr* self, char* id) {
        return (**self).containsId(id);
    }

	C_ABI SignalPanelListBoxItem* ABI_PanelListBox_onItemSelect(PanelListBox::Ptr* self) {
        return &(**self).onItemSelect;
    }

    // ProgressBar

	C_ABI ProgressBar::Ptr* ABI_ProgressBar_new() {
        auto self = ProgressBar::create();
        auto ptr = new ProgressBar::Ptr(nullptr);
        ptr->swap(self);
        return ptr;
    }

	C_ABI void ABI_ProgressBar_setMinimum(ProgressBar::Ptr* self, int minimum) {
        (**self).setMinimum(minimum);
    }

	C_ABI int ABI_ProgressBar_getMinimum(ProgressBar::Ptr* self) {
        return (**self).getMinimum();
    }

	C_ABI void ABI_ProgressBar_setMaximum(ProgressBar::Ptr* self, int maximum) {
        (**self).setMaximum(maximum);
    }

	C_ABI int ABI_ProgressBar_getMaximum(ProgressBar::Ptr* self) {
        return (**self).getMaximum();
    }

	C_ABI void ABI_ProgressBar_setValue(ProgressBar::Ptr* self, int value) {
        (**self).setValue(value);
    }

	C_ABI int ABI_ProgressBar_getValue(ProgressBar::Ptr* self) {
        return (**self).getValue();
    }

	C_ABI int ABI_ProgressBar_incrementValue(ProgressBar::Ptr* self) {
        return (**self).incrementValue();
    }

	C_ABI void ABI_ProgressBar_setText(ProgressBar::Ptr* self, char* text) {
        (**self).setText(text);
    }

	C_ABI const char32_t* ABI_ProgressBar_getText(ProgressBar::Ptr* self) {
        return (**self).getText().data();
    }

	C_ABI void ABI_ProgressBar_setFillDirection(ProgressBar::Ptr* self, int direction) {
        (**self).setFillDirection(static_cast<ProgressBar::FillDirection>(direction));
    }

	C_ABI int ABI_ProgressBar_getFillDirection(ProgressBar::Ptr* self) {
        return static_cast<int>((**self).getFillDirection());
    }

	C_ABI SignalUInt* ABI_ProgressBar_onValueChange(ProgressBar::Ptr* self) {
        return &(**self).onValueChange;
    }

	C_ABI Signal* ABI_ProgressBar_onFull(ProgressBar::Ptr* self) {
        return &(**self).onFull;
    }

    // RangeSlider

	C_ABI RangeSlider::Ptr* ABI_RangeSlider_new() {
        auto self = RangeSlider::create();
        auto ptr = new RangeSlider::Ptr(nullptr);
        ptr->swap(self);
        return ptr;
    }

	C_ABI void ABI_RangeSlider_setMinimum(RangeSlider::Ptr* self, float minimum) {
        (**self).setMinimum(minimum);
    }

	C_ABI float ABI_RangeSlider_getMinimum(RangeSlider::Ptr* self) {
        return (**self).getMinimum();
    }

	C_ABI void ABI_RangeSlider_setMaximum(RangeSlider::Ptr* self, float maximum) {
        (**self).setMaximum(maximum);
    }

	C_ABI float ABI_RangeSlider_getMaximum(RangeSlider::Ptr* self) {
        return (**self).getMaximum();
    }

	C_ABI void ABI_RangeSlider_setSelectionStart(RangeSlider::Ptr* self, float value) {
        (**self).setSelectionStart(value);
    }

	C_ABI float ABI_RangeSlider_getSelectionStart(RangeSlider::Ptr* self) {
        return (**self).getSelectionStart();
    }

	C_ABI void ABI_RangeSlider_setSelectionEnd(RangeSlider::Ptr* self, float value) {
        (**self).setSelectionEnd(value);
    }

	C_ABI float ABI_RangeSlider_getSelectionEnd(RangeSlider::Ptr* self) {
        return (**self).getSelectionEnd();
    }

	C_ABI void ABI_RangeSlider_setStep(RangeSlider::Ptr* self, float step) {
        (**self).setStep(step);
    }

	C_ABI float ABI_RangeSlider_getStep(RangeSlider::Ptr* self) {
        return (**self).getStep();
    }

	C_ABI SignalRange* ABI_RangeSlider_onRangeChange(RangeSlider::Ptr* self) {
        return &(**self).onRangeChange;
    }

    // RichTextLabel

	C_ABI RichTextLabel::Ptr* ABI_RichTextLabel_new() {
        auto self = RichTextLabel::create();
        auto ptr = new RichTextLabel::Ptr(nullptr);
        ptr->swap(self);
        return ptr;
    }

    // SeparatorLine

	C_ABI SeparatorLine::Ptr* ABI_SeparatorLine_new() {
        auto self = SeparatorLine::create();
        auto ptr = new SeparatorLine::Ptr(nullptr);
        ptr->swap(self);
        return ptr;
    }

    // Slider

	C_ABI Slider::Ptr* ABI_Slider_new() {
        auto self = Slider::create();
        auto ptr = new Slider::Ptr(nullptr);
        ptr->swap(self);
        return ptr;
    }

	C_ABI void ABI_Slider_setMinimum(Slider::Ptr* self, float minimum) {
        (**self).setMinimum(minimum);
    }

	C_ABI float ABI_Slider_getMinimum(Slider::Ptr* self) {
        return (**self).getMinimum();
    }

	C_ABI void ABI_Slider_setMaximum(Slider::Ptr* self, float maximum) {
        (**self).setMaximum(maximum);
    }

	C_ABI float ABI_Slider_getMaximum(Slider::Ptr* self) {
        return (**self).getMaximum();
    }

	C_ABI void ABI_Slider_setValue(Slider::Ptr* self, float value) {
        (**self).setValue(value);
    }

	C_ABI float ABI_Slider_getValue(Slider::Ptr* self) {
        return (**self).getValue();
    }

	C_ABI void ABI_Slider_setStep(Slider::Ptr* self, float step) {
        (**self).setStep(step);
    }

	C_ABI float ABI_Slider_getStep(Slider::Ptr* self) {
        return (**self).getStep();
    }

	C_ABI void ABI_Slider_setVerticalScroll(Slider::Ptr* self, int vertical) {
        (**self).setVerticalScroll(vertical);
    }

	C_ABI bool ABI_Slider_getVerticalScroll(Slider::Ptr* self) {
        return (**self).getVerticalScroll();
    }

	C_ABI void ABI_Slider_setInvertedDirection(Slider::Ptr* self, int invertedDirection) {
        (**self).setInvertedDirection(invertedDirection);
    }

	C_ABI bool ABI_Slider_getInvertedDirection(Slider::Ptr* self) {
        return (**self).getInvertedDirection();
    }

	C_ABI void ABI_Slider_setChangeValueOnScroll(Slider::Ptr* self, int changeValueOnScroll) {
        (**self).setChangeValueOnScroll(changeValueOnScroll);
    }

	C_ABI bool ABI_Slider_getChangeValueOnScroll(Slider::Ptr* self) {
        return (**self).getChangeValueOnScroll();
    }

	C_ABI SignalFloat* ABI_Slider_onValueChange(Slider::Ptr* self) {
        return &(**self).onValueChange;
    }

    // SpinButton

	C_ABI SpinButton::Ptr* ABI_SpinButton_new() {
        auto self = SpinButton::create();
        auto ptr = new SpinButton::Ptr(nullptr);
        ptr->swap(self);
        return ptr;
    }

	C_ABI void ABI_SpinButton_setMinimum(SpinButton::Ptr* self, float minimum) {
        (**self).setMinimum(minimum);
    }

	C_ABI float ABI_SpinButton_getMinimum(SpinButton::Ptr* self) {
        return (**self).getMinimum();
    }

	C_ABI void ABI_SpinButton_setMaximum(SpinButton::Ptr* self, float maximum) {
        (**self).setMaximum(maximum);
    }

	C_ABI float ABI_SpinButton_getMaximum(SpinButton::Ptr* self) {
        return (**self).getMaximum();
    }

	C_ABI void ABI_SpinButton_setValue(SpinButton::Ptr* self, float value) {
        (**self).setValue(value);
    }

	C_ABI float ABI_SpinButton_getValue(SpinButton::Ptr* self) {
        return (**self).getValue();
    }

	C_ABI void ABI_SpinButton_setStep(SpinButton::Ptr* self, float step) {
        (**self).setStep(step);
    }

	C_ABI float ABI_SpinButton_getStep(SpinButton::Ptr* self) {
        return (**self).getStep();
    }

	C_ABI void ABI_SpinButton_setVerticalScroll(SpinButton::Ptr* self, int vertical) {
        (**self).setVerticalScroll(vertical);
    }

	C_ABI bool ABI_SpinButton_getVerticalScroll(SpinButton::Ptr* self) {
        return (**self).getVerticalScroll();
    }

	C_ABI SignalFloat* ABI_SpinButton_onValueChange(SpinButton::Ptr* self) {
        return &(**self).onValueChange;
    }

    // SubwidgetContainer

	C_ABI Container::Ptr* ABI_SubwidgetContainer_getContainer(SubwidgetContainer::Ptr* self) {
        return new Container::Ptr((**self).getContainer());
    }

    // SpinControl

    C_ABI SpinControl::Ptr* ABI_SpinControl_new() {
        auto self = SpinControl::create();
        auto ptr = new SpinControl::Ptr(nullptr);
        ptr->swap(self);
        return ptr;
    }

	C_ABI void ABI_SpinControl_setMinimum(SpinControl::Ptr* self, float minimum) {
        (**self).setMinimum(minimum);
    }

	C_ABI float ABI_SpinControl_getMinimum(SpinControl::Ptr* self) {
        return (**self).getMinimum();
    }

	C_ABI void ABI_SpinControl_setMaximum(SpinControl::Ptr* self, float maximum) {
        (**self).setMaximum(maximum);
    }

	C_ABI float ABI_SpinControl_getMaximum(SpinControl::Ptr* self) {
        return (**self).getMaximum();
    }

	C_ABI void ABI_SpinControl_setValue(SpinControl::Ptr* self, float value) {
        (**self).setValue(value);
    }

	C_ABI float ABI_SpinControl_getValue(SpinControl::Ptr* self) {
        return (**self).getValue();
    }

	C_ABI void ABI_SpinControl_setStep(SpinControl::Ptr* self, float step) {
        (**self).setStep(step);
    }

	C_ABI float ABI_SpinControl_getStep(SpinControl::Ptr* self) {
        return (**self).getStep();
    }

    C_ABI void ABI_SpinControl_setDecimalPlaces(SpinControl::Ptr* self, int decimalPlaces) {
        (**self).setDecimalPlaces(decimalPlaces);
    }

	C_ABI int ABI_SpinControl_getDecimalPlaces(SpinControl::Ptr* self) {
        return (**self).getDecimalPlaces();
    }

	C_ABI void ABI_SpinControl_setUseWideArrows(SpinControl::Ptr* self, int useWideArrows) {
        (**self).setUseWideArrows(useWideArrows);
    }

	C_ABI bool ABI_SpinControl_getUseWideArrows(SpinControl::Ptr* self) {
        return (**self).getUseWideArrows();
    }

	C_ABI SignalFloat* ABI_SpinControl_onValueChange(SpinControl::Ptr* self) {
        return &(**self).onValueChange;
    }

    // Tabs

	C_ABI Tabs::Ptr* ABI_Tabs_new() {
        auto self = Tabs::create();
        auto ptr = new Tabs::Ptr(nullptr);
        ptr->swap(self);
        return ptr;
    }

	C_ABI void ABI_Tabs_setAutoSize(Tabs::Ptr* self, int autoSize) {
        (**self).setAutoSize(autoSize);
    }

	C_ABI bool ABI_Tabs_getAutoSize(Tabs::Ptr* self) {
        return (**self).getAutoSize();
    }

	C_ABI int ABI_Tabs_add(Tabs::Ptr* self, char* text, int select) {
        return static_cast<int>((**self).add(text, select));
    }

	C_ABI void ABI_Tabs_insert(Tabs::Ptr* self, int index, char* text, int select) {
        (**self).insert(index, text, select);
    }

	C_ABI const char32_t* ABI_Tabs_getText(Tabs::Ptr* self, int index) {
        auto str = new String((**self).getText(index));
        autoclean.push_back(str);
        return str->data();
    }


	C_ABI bool ABI_Tabs_changeText(Tabs::Ptr* self, int index, char* text) {
        return (**self).changeText(index, text);
    }

	C_ABI bool ABI_Tabs_select(Tabs::Ptr* self, char* text) {
        return (**self).select(text);
    }

	C_ABI bool ABI_Tabs_selectByIndex(Tabs::Ptr* self, int index) {
        return (**self).select(index);
    }

	C_ABI void ABI_Tabs_deselect(Tabs::Ptr* self) {
        (**self).deselect();
    }

	C_ABI bool ABI_Tabs_remove(Tabs::Ptr* self, char* text) {
        return (**self).remove(text);
    }

	C_ABI bool ABI_Tabs_removeByIndex(Tabs::Ptr* self, int index) {
        return (**self).remove(index);
    }

	C_ABI void ABI_Tabs_removeAll(Tabs::Ptr* self) {
        (**self).removeAll();
    }

	C_ABI const char32_t* ABI_Tabs_getSelected(Tabs::Ptr* self) {
        auto str = new String((**self).getSelected());
        autoclean.push_back(str);
        return str->data();
    }

	C_ABI int ABI_Tabs_getSelectedIndex(Tabs::Ptr* self) {
        return (**self).getSelectedIndex();
    }

	C_ABI void ABI_Tabs_setTabVisible(Tabs::Ptr* self, int index, int visible) {
        (**self).setTabVisible(index, visible);
    }

	C_ABI bool ABI_Tabs_getTabVisible(Tabs::Ptr* self, int index) {
        return (**self).getTabVisible(index);
    }

	C_ABI void ABI_Tabs_setTabEnabled(Tabs::Ptr* self, int index, int enabled) {
        (**self).setTabEnabled(index, enabled);
    }

	C_ABI bool ABI_Tabs_getTabEnabled(Tabs::Ptr* self, int index) {
        return (**self).getTabEnabled(index);
    }

	C_ABI void ABI_Tabs_setTabHeight(Tabs::Ptr* self, float height) {
        (**self).setTabHeight(height);
    }

	C_ABI void ABI_Tabs_setMaximumTabWidth(Tabs::Ptr* self, float maximumWidth) {
        (**self).setMaximumTabWidth(maximumWidth);
    }

	C_ABI float ABI_Tabs_getMaximumTabWidth(Tabs::Ptr* self) {
        return (**self).getMaximumTabWidth();
    }

	C_ABI void ABI_Tabs_setMinimumTabWidth(Tabs::Ptr* self, float minimumWidth) {
        (**self).setMinimumTabWidth(minimumWidth);
    }

	C_ABI float ABI_Tabs_getMinimumTabWidth(Tabs::Ptr* self) {
        return (**self).getMinimumTabWidth();
    }

	C_ABI int ABI_Tabs_getTabsCount(Tabs::Ptr* self) {
        return static_cast<int>((**self).getTabsCount());
    }

	C_ABI SignalString* ABI_Tabs_onTabSelect(Tabs::Ptr* self) {
        return &(**self).onTabSelect;
    }

    // TabContainer

	C_ABI TabContainer::Ptr* ABI_TabContainer_new() {
        auto self = TabContainer::create();
        auto ptr = new TabContainer::Ptr(nullptr);
        ptr->swap(self);
        return ptr;
    }

	C_ABI void ABI_TabContainer_setTabsHeight(TabContainer::Ptr* self, char* height) {
        (**self).setTabsHeight(height);
    }

	C_ABI Panel::Ptr* ABI_TabContainer_addTab(TabContainer::Ptr* self, char* name, int select) {
        auto panel = (**self).addTab(name, select);
        auto ptr = new Panel::Ptr(nullptr);
        ptr->swap(panel);
        return ptr;
    }

	C_ABI Panel::Ptr* ABI_TabContainer_insertTab(TabContainer::Ptr* self, int index, char* name, int select) {
        auto panel = (**self).insertTab(index, name, select);
        auto ptr = new Panel::Ptr(nullptr);
        ptr->swap(panel);
        return ptr;
    }

	C_ABI bool ABI_TabContainer_removeTab(TabContainer::Ptr* self, char* text) {
        return (**self).removeTab(text);
    }

	C_ABI bool ABI_TabContainer_removeTabByIndex(TabContainer::Ptr* self, int index) {
        return (**self).removeTab(index);
    }

	C_ABI void ABI_TabContainer_select(TabContainer::Ptr* self, int index) {
        (**self).select(index);
    }

	C_ABI int ABI_TabContainer_getPanelCount(TabContainer::Ptr* self) {
        return static_cast<int>((**self).getPanelCount());
    }

	C_ABI int ABI_TabContainer_getIndex(TabContainer::Ptr* self, Panel::Ptr* ptr) {
        return (**self).getIndex(*ptr);
    }

	C_ABI Panel::Ptr* ABI_TabContainer_getSelected(TabContainer::Ptr* self) {
        auto panel = (**self).getSelected();
        auto ptr = new Panel::Ptr(nullptr);
        ptr->swap(panel);
        return ptr;
    }

	C_ABI int ABI_TabContainer_getSelectedIndex(TabContainer::Ptr* self){
        return (**self).getSelectedIndex();
    }

	C_ABI Panel::Ptr* ABI_TabContainer_getPanel(TabContainer::Ptr* self, int index) {
        auto panel = (**self).getPanel(index);
        auto ptr = new Panel::Ptr(nullptr);
        ptr->swap(panel);
        return ptr;
    }

	C_ABI Tabs::Ptr* ABI_TabContainer_getTabs(TabContainer::Ptr* self) {
        auto tabs = (**self).getTabs();
        auto ptr = new Tabs::Ptr(nullptr);
        ptr->swap(tabs);
        return ptr;
    }

	C_ABI const char32_t* ABI_TabContainer_getTabText(TabContainer::Ptr* self, int index) {
        auto str = new String((**self).getTabText(index));
        autoclean.push_back(str);
        return str->data();
    }

	C_ABI bool ABI_TabContainer_changeTabText(TabContainer::Ptr* self, int index, char* text) {
        return (**self).changeTabText(index, text);
    }

	C_ABI void ABI_TabContainer_setTabAlignment(TabContainer::Ptr* self, int align) {
        (**self).setTabAlignment(static_cast<TabContainer::TabAlign>(align));
    }

	C_ABI int ABI_TabContainer_getTabAlignment(TabContainer::Ptr* self) {
        return static_cast<TabContainer::TabAlign>((**self).getTabAlignment());
    }

	C_ABI void ABI_TabContainer_setTabFixedSize(TabContainer::Ptr* self, float fixedSize) {
        (**self).setTabFixedSize(fixedSize);
    }

	C_ABI float ABI_TabContainer_getTabFixedSize(TabContainer::Ptr* self) {
        return (**self).getTabFixedSize();
    }

	C_ABI SignalInt* ABI_TabContainer_onSelectionChange(TabContainer::Ptr* self) {
        return &(**self).onSelectionChange;
    }

	C_ABI SignalTypedIntBoolPtr* ABI_TabContainer_onSelectionChanging(TabContainer::Ptr* self) {
        return &(**self).onSelectionChanging;
    }

    // TextArea

	C_ABI TextArea::Ptr* ABI_TextArea_new() {
        auto self = TextArea::create();
        auto ptr = new TextArea::Ptr(nullptr);
        ptr->swap(self);
        return ptr;
    }

	C_ABI void ABI_TextArea_setText(TextArea::Ptr* self, char* text) {
        (**self).setText(text);
    }

	C_ABI void ABI_TextArea_addText(TextArea::Ptr* self, char* text) {
        (**self).addText(text);
    }

	C_ABI const char32_t* ABI_TextArea_getText(TextArea::Ptr* self) {
        auto str = new String((**self).getText());
        autoclean.push_back(str);
        return str->data();
    }

	C_ABI void ABI_TextArea_setDefaultText(TextArea::Ptr* self, char* text) {
        (**self).setDefaultText(text);
    }

	C_ABI const char32_t* ABI_TextArea_getDefaultText(TextArea::Ptr* self) {
        return (**self).getDefaultText().data();
    }
    
	C_ABI void ABI_TextArea_setSelectedText(TextArea::Ptr* self, int selectionStartIndex, int selectionEndIndex) {
        (**self).setSelectedText(selectionStartIndex, selectionEndIndex);
    }

	C_ABI const char32_t* ABI_TextArea_getSelectedText(TextArea::Ptr* self) {
        auto str = new String((**self).getSelectedText());
        autoclean.push_back(str);
        return str->data();
    }

	C_ABI int ABI_TextArea_getSelectionStart(TextArea::Ptr* self) {
        return static_cast<int>((**self).getSelectionStart());
    }

	C_ABI int ABI_TextArea_getSelectionEnd(TextArea::Ptr* self) {
        return static_cast<int>((**self).getSelectionEnd());
    }

	C_ABI void ABI_TextArea_setMaximumCharacters(TextArea::Ptr* self, int maxChars) {
        (**self).setMaximumCharacters(maxChars);
    }

	C_ABI int ABI_TextArea_getMaximumCharacters(TextArea::Ptr* self) {
        return static_cast<int>((**self).getMaximumCharacters());
    }

	C_ABI void ABI_TextArea_setTabString(TextArea::Ptr* self, char* tabText) {
        (**self).setTabString(tabText);
    }

	C_ABI const char32_t* ABI_TextArea_getTabString(TextArea::Ptr* self) {
        auto str = new String((**self).getTabString());
        autoclean.push_back(str);
        return str->data();
    }
    
	C_ABI void ABI_TextArea_setCaretPosition(TextArea::Ptr* self, int charactersBeforeCaret) {
        (**self).setCaretPosition(charactersBeforeCaret);
    }

	C_ABI int ABI_TextArea_getCaretPosition(TextArea::Ptr* self) {
        return static_cast<int>((**self).getCaretPosition());
    }

	C_ABI int ABI_TextArea_getCaretLine(TextArea::Ptr* self) {
        return static_cast<int>((**self).getCaretLine());
    }

	C_ABI int ABI_TextArea_getCaretColumn(TextArea::Ptr* self) {
        return static_cast<int>((**self).getCaretColumn());
    }

	C_ABI void ABI_TextArea_setReadOnly(TextArea::Ptr* self, int readOnly) {
        (**self).setReadOnly(readOnly);
    }

	C_ABI bool ABI_TextArea_isReadOnly(TextArea::Ptr* self) {
        return (**self).isReadOnly();
    }

	C_ABI int ABI_TextArea_getLinesCount(TextArea::Ptr* self) {
        return static_cast<int>((**self).getLinesCount());
    }

	C_ABI void ABI_TextArea_enableMonospacedFontOptimization(TextArea::Ptr* self, int enable) {
        (**self).enableMonospacedFontOptimization(enable);
    }

    C_ABI void ABI_TextArea_setVerticalScrollbarPolicy(TextArea::Ptr* self, int policy) {
        (**self).setVerticalScrollbarPolicy(static_cast<Scrollbar::Policy>(policy));
    }

	C_ABI int ABI_TextArea_getVerticalScrollbarPolicy(TextArea::Ptr* self) {
        return static_cast<int>((**self).getVerticalScrollbarPolicy());
    }

	C_ABI void ABI_TextArea_setHorizontalScrollbarPolicy(TextArea::Ptr* self, int policy) {
        (**self).setHorizontalScrollbarPolicy(static_cast<Scrollbar::Policy>(policy));
    }

	C_ABI int ABI_TextArea_getHorizontalScrollbarPolicy(TextArea::Ptr* self) {
        return static_cast<int>((**self).getHorizontalScrollbarPolicy());
    }

	C_ABI void ABI_TextArea_setVerticalScrollbarValue(TextArea::Ptr* self, int value) {
        (**self).setVerticalScrollbarValue(value);
    }

	C_ABI int ABI_TextArea_getVerticalScrollbarValue(TextArea::Ptr* self) {
        return (**self).getVerticalScrollbarValue();
    }

    C_ABI void ABI_TextArea_setHorizontalScrollbarValue(TextArea::Ptr* self, int value) {
        (**self).setHorizontalScrollbarValue(value);
    }

	C_ABI int ABI_TextArea_getHorizontalScrollbarValue(TextArea::Ptr* self) {
        return (**self).getHorizontalScrollbarValue();
    }

	C_ABI SignalString* ABI_TextArea_onTextChange(TextArea::Ptr* self) {
        return &(**self).onTextChange;
    }

	C_ABI Signal* ABI_TextArea_onSelectionChange(TextArea::Ptr* self) {
        return &(**self).onSelectionChange;
    }

	C_ABI Signal* ABI_TextArea_onCaretPositionChange(TextArea::Ptr* self) {
        return &(**self).onCaretPositionChange;
    }

    // ToggleButton

	C_ABI ToggleButton::Ptr* ABI_ToggleButton_new() {
        auto self = ToggleButton::create();
        auto ptr = new ToggleButton::Ptr(nullptr);
        ptr->swap(self);
        return ptr;
    }

	C_ABI void ABI_ToggleButton_setDown(ToggleButton::Ptr* self, int down) {
        (**self).setDown(down);
    }

	C_ABI bool ABI_ToggleButton_isDown(ToggleButton::Ptr* self) {
        return (**self).isDown();
    }

	C_ABI SignalBool* ABI_ToggleButton_onToggle(ToggleButton::Ptr* self) {
        return &(**self).onToggle;
    }

    // ToolTip

	C_ABI void ABI_STATIC_ToolTip_setInitialDelay(int delay) {
        ToolTip::setInitialDelay(delay);
    }

	C_ABI int ABI_STATIC_ToolTip_getInitialDelay() {
        return sf::Time(ToolTip::getInitialDelay()).asMilliseconds();
    }

	C_ABI void ABI_STATIC_ToolTip_setDistanceToMouse(float distanceX, float distanceY) {
        ToolTip::setDistanceToMouse({distanceX, distanceY});
    }

	C_ABI Vector2f* ABI_STATIC_ToolTip_getDistanceToMouse() {
        return new Vector2f(ToolTip::getDistanceToMouse());
    }

	C_ABI void ABI_STATIC_ToolTip_setShowOnDisabledWidget(int show) {
        ToolTip::setShowOnDisabledWidget(show);
    }

	C_ABI bool ABI_STATIC_ToolTip_getShowOnDisabledWidget() {
        return ToolTip::getShowOnDisabledWidget();
    }

    // TreeView

	C_ABI TreeView::Ptr* ABI_TreeView_new() {
        auto self = TreeView::create();
        auto ptr = new TreeView::Ptr(nullptr);
        ptr->swap(self);
        return ptr;
    }

	C_ABI bool ABI_TreeView_addItem(TreeView::Ptr* self, int hierarchySize, char*(*f)(void), int createParents) {
        std::vector<String> vec;
        for(int i = 0; i < hierarchySize; ++i) {
            vec.push_back(f());
        }
        return (**self).addItem(vec, createParents);
    }

	C_ABI void ABI_TreeView_expand(TreeView::Ptr* self, int hierarchySize, char*(*f)(void)) {
        std::vector<String> vec;
        for(int i = 0; i < hierarchySize; ++i) {
            vec.push_back(f());
        }
        (**self).expand(vec);
    }

	C_ABI void ABI_TreeView_expandAll(TreeView::Ptr* self) {
        (**self).expandAll();
    }

	C_ABI void ABI_TreeView_collapse(TreeView::Ptr* self, int hierarchySize, char*(*f)(void)) {
        std::vector<String> vec;
        for(int i = 0; i < hierarchySize; ++i) {
            vec.push_back(f());
        }
        (**self).collapse(vec);
    }

	C_ABI void ABI_TreeView_collapseAll(TreeView::Ptr* self) {
        (**self).collapseAll();
    }

	C_ABI bool ABI_TreeView_selectItem(TreeView::Ptr* self, int hierarchySize, char*(*f)(void)) {
        std::vector<String> vec;
        for(int i = 0; i < hierarchySize; ++i) {
            vec.push_back(f());
        }
        return (**self).selectItem(vec);
    }

	C_ABI void ABI_TreeView_deselectItem(TreeView::Ptr* self) {
        (**self).deselectItem();
    }

	C_ABI bool ABI_TreeView_removeItem(TreeView::Ptr* self, int hierarchySize, char*(*f)(void), int removeParentsWhenEmpty) {
        std::vector<String> vec;
        for(int i = 0; i < hierarchySize; ++i) {
            vec.push_back(f());
        }
        return (**self).removeItem(vec, removeParentsWhenEmpty);
    }

	C_ABI void ABI_TreeView_removeAllItems(TreeView::Ptr* self) {
        (**self).removeAllItems();
    }

	C_ABI void ABI_TreeView_getSelectedItem(TreeView::Ptr* self, void(*f)(const char32_t*)) {
        for(auto text : (**self).getSelectedItem()) {
            f(text.data());
        }
    }

    void TreeView_yieldNodes(std::vector<TreeView::ConstNode> nodes, void(*m)(const char32_t*, int), void(*up)()) {
        for(auto node : nodes) {
            m(node.text.data(), node.expanded);
            TreeView_yieldNodes(node.nodes, m, up);
            up();
        }
    }

	C_ABI void ABI_TreeView_getNodes(TreeView::Ptr* self, void(*m)(const char32_t*, int), void(*up)()) {
        TreeView_yieldNodes((**self).getNodes(), m, up);
    }

	C_ABI void ABI_TreeView_setItemHeight(TreeView::Ptr* self, int itemHeight) {
        (**self).setItemHeight(itemHeight);
    }

	C_ABI int ABI_TreeView_getItemHeight(TreeView::Ptr* self) {
        return (**self).getItemHeight();
    }

	C_ABI void ABI_TreeView_setVerticalScrollbarValue(TreeView::Ptr* self, int value) {
        (**self).setVerticalScrollbarValue(value);
    }

	C_ABI int ABI_TreeView_getVerticalScrollbarValue(TreeView::Ptr* self) {
        return (**self).getVerticalScrollbarValue();
    }

	C_ABI void ABI_TreeView_setHorizontalScrollbarValue(TreeView::Ptr* self, int value) {
        (**self).setHorizontalScrollbarValue(value);
    }

	C_ABI int ABI_TreeView_getHorizontalScrollbarValue(TreeView::Ptr* self) {
        return (**self).getHorizontalScrollbarValue();
    }

	C_ABI SignalItemHierarchy* ABI_TreeView_onItemSelect(TreeView::Ptr* self) {
        return &(**self).onItemSelect;
    }

	C_ABI SignalItemHierarchy* ABI_TreeView_onDoubleClick(TreeView::Ptr* self) {
        return &(**self).onDoubleClick;
    }

	C_ABI SignalItemHierarchy* ABI_TreeView_onExpand(TreeView::Ptr* self) {
        return &(**self).onExpand;
    }

	C_ABI SignalItemHierarchy* ABI_TreeView_onCollapse(TreeView::Ptr* self) {
        return &(**self).onCollapse;
    }

	C_ABI SignalItemHierarchy* ABI_TreeView_onRightClick(TreeView::Ptr* self) {
        return &(**self).onRightClick;
    }

    // Scrollbar

	C_ABI Scrollbar::Ptr* ABI_Scrollbar_new() {
        auto self = Scrollbar::create();
        auto ptr = new Scrollbar::Ptr(nullptr);
        ptr->swap(self);
        return ptr;
    }

	C_ABI void ABI_Scrollbar_setMaximum(Scrollbar::Ptr* self, int maximum) {
        (**self).setMaximum(maximum);
    }

	C_ABI int ABI_Scrollbar_getMaximum(Scrollbar::Ptr* self) {
        return (**self).getMaximum();
    }

	C_ABI void ABI_Scrollbar_setValue(Scrollbar::Ptr* self, int value) {
        (**self).setValue(value);
    }

	C_ABI int ABI_Scrollbar_getValue(Scrollbar::Ptr* self) {
        return (**self).getValue();
    }

	C_ABI void ABI_Scrollbar_setViewportSize(Scrollbar::Ptr* self, int viewport) {
        (**self).setViewportSize(viewport);
    }

	C_ABI int ABI_Scrollbar_getViewportSize(Scrollbar::Ptr* self) {
        return (**self).getViewportSize();
    }

	C_ABI void ABI_Scrollbar_setScrollAmount(Scrollbar::Ptr* self, int scrollAmount) {
        (**self).setScrollAmount(scrollAmount);
    }

	C_ABI int ABI_Scrollbar_getScrollAmount(Scrollbar::Ptr* self) {
        return (**self).getScrollAmount();
    }

	C_ABI void ABI_Scrollbar_setAutoHide(Scrollbar::Ptr* self, int autoHide) {
        (**self).setAutoHide(autoHide);
    }

	C_ABI bool ABI_Scrollbar_getAutoHide(Scrollbar::Ptr* self) {
        return (**self).getAutoHide();
    }

	C_ABI void ABI_Scrollbar_setVerticalScroll(Scrollbar::Ptr* self, int vertical) {
        (**self).setVerticalScroll(vertical);
    }

	C_ABI bool ABI_Scrollbar_getVerticalScroll(Scrollbar::Ptr* self) {
        return (**self).getVerticalScroll();
    }

	C_ABI float ABI_Scrollbar_getDefaultWidth(Scrollbar::Ptr* self) {
        return (**self).getDefaultWidth();
    }

	C_ABI SignalUInt* ABI_Scrollbar_onValueChange(Scrollbar::Ptr* self) {
        return &(**self).onValueChange;
    }

}