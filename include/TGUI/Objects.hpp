/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TGUI - Texus's Graphical User Interface
// Copyright (C) 2012 Bruno Van de Velde (VDV_B@hotmail.com)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef _TGUI_OBJECTS_INCLUDED_
#define _TGUI_OBJECTS_INCLUDED_

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief The parent struct for every object.
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct TGUI_API OBJECT : public sf::Drawable, sf::Transformable
    {
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Default constructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        OBJECT();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Copy constructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        OBJECT(const OBJECT& copy);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Destructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual ~OBJECT();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Overload of assignment operator
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        OBJECT& operator= (const OBJECT& right);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \internal
        // This function is called when the object is created (when it is added to a group).
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void initialize();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \internal
        // Makes a copy of the object by just calling the copy constructor.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual OBJECT* clone() = 0;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the size of an object.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setSize(float width, float height) = 0;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the size of the object, unaffected by scaling.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual Vector2u getSize() const = 0;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the size of the object, after the scaling transformation.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual Vector2f getScaledSize() const = 0;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Shows the object.
        ///
        /// The object won't receive events nor will it be drawn when hidden. The object is visible by default.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void show();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Hides the object.
        ///
        /// The object won't receive events nor will it be drawn when hidden. The object is visible by default.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void hide();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns true when the object is visible.
        ///
        /// If this function returns false then the object is hidden, which means that it won't receive events and it won't be drawn.
        /// All objects are visible by default.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool isVisible();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Enables the object.
        ///
        /// The object will receive events and send callbacks again.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void enable();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Disables the object.
        ///
        /// The object will no longer receive events and it will thus no longer send callbacks.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void disable();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns true when the object is enabled.
        ///
        /// If this function returns false then the object is disabled and will longer receive events and it will thus no longer send callbacks.
        /// All objects are enabled by default.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool isEnabled();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns true when the object is disabled.
        ///
        /// This means that the object will longer receive events and it will thus no longer send callbacks.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool isDisabled();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns true when the object is loaded successfully.
        ///
        /// When an object is not loaded correctly then it will not be drawn.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool isLoaded();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \internal
        //  Get the ObjectPhases from the string read from the info file
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void extractPhases(std::string phases);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns true when the object is focused and false otherwise.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool isFocused();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the type of the object.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ObjectTypes getObjectType();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Places the object before all other objects.
        ///
        /// This will change the id of the object.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void moveToFront();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Places the object behind all other objects.
        ///
        /// This will change the id of the object.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void moveToBack();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // These functions are used to receive callback from the EventManager.
        // You normally don't need them, but you can use them to simulate an event.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual bool mouseOnObject(float x, float y);
        virtual void leftMousePressed(float x, float y);
        virtual void leftMouseReleased(float x, float y);
        virtual void mouseMoved(float x, float y);
        virtual void keyPressed(sf::Keyboard::Key key);
        virtual void textEntered(char key);
        virtual void objectFocused();
        virtual void objectUnfocused();

        virtual void mouseNotOnObject();
        virtual void mouseNoLongerDown();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    public:

        // When the id is 0 then there will be no callback. Otherwise, this will be the callbackID inside the Callback struct.
        unsigned int callbackID;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        // When an object is disabled, it will no longer receive events
        bool m_Enabled;

        // Is the object visible? When it is invisible it will not receive events and it won't be drawn.
        bool m_Visible;

        // This bool will be true from the moment that the load function is completed successfully.
        bool m_Loaded;

        // This will store the different phases that the object can have
        // e.g. if there isn't a mouse down image then a button should not try to change its image on mouse down
        unsigned char m_ObjectPhase;

        // This will point to our parent object. If there is no parent then this will be NULL.
        Group* m_Parent;

        // Is the mouse on top of the object? Did the mouse go down on the object?
        bool m_MouseHover;
        bool m_MouseDown;

        // Are you focused on the object?
        bool m_Focused;

        // Can the object be focused?
        bool m_AllowFocus;

        // Is the object a button, a listbox, a checkbox, ...
        ObjectTypes m_ObjectType;

        // This is set to true for objects that are also derived from OBJECT_ANIMATION.
        bool m_AnimatedObject;

        // This is set to true for objects that have something to be dragged around (e.g. sliders and scrollbars)
        bool m_DraggableObject;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        friend struct EventManager;
        friend struct Group;
    };


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Parent struct for every object that has borders.
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct TGUI_API OBJECT_BORDERS
    {
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Default constructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        OBJECT_BORDERS();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the size of the borders.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setBorders(unsigned int leftBorder = 0, unsigned int topBorder = 0,
                                unsigned int rightBorder = 0, unsigned int bottomBorder = 0) = 0;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the size of the borders as a tgui::Vector4u.
        ///
        /// The first element will be the size of the left border, the seconds is the size of the top border,
        /// the third is the size of the right border and the the last constains the size of the bottom border.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Vector4u getBorders();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        unsigned int m_LeftBorder;
        unsigned int m_TopBorder;
        unsigned int m_RightBorder;
        unsigned int m_BottomBorder;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    };


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Parent object for all objects that need to access the internal clock of the window.
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct TGUI_API OBJECT_ANIMATION
    {
        // The event manager will be able to change the elapsed time from any object
        friend struct EventManager;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // This function is called right after the elapsed time is changed.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void update() = 0;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        // This will store the elapsed time since the last animation
        sf::Time m_AnimationTimeElapsed;
    };


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief When you receive an action callback from an object then this struct will be passed as parameter.
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct Callback
    {
        // All objects

            // The id that was passed to the object. It is used to identify from what object the callback came from. It can'b be 0.
            unsigned int callbackID;

            // How did the callbak occur? (one of the elements from the Triggers enum)
            unsigned int trigger;

            // Pointer to the object
            OBJECT* object;


        // Checkbox and RadioButton

            // True when the checkbox is checked, false otherwise.
            bool checked;


        // Button (these members are still in there because of what I did in v0.1, but they shouldn't be used)

            // This will store the mouse position. Only used on mouse clicks.
            float mouseX;
            float mouseY;

            // When you click on an object then this contains the button
            sf::Mouse::Button mouseButton;


        // Editbox and Listbox

            // This string will contain the new string inside the editbox
            std::string text;


        // Slider, Listbox and LoadingBar

            unsigned int value;


        // This enum contains the different values for Trigger.
        enum triggers
        {
            mouseClick,        // Button, Checkbox, RadioButton
            keyPress_Space,    // Button, Checkbox, RadioButton
            keyPress_Return,   // Button, Checkbox, RadioButton
            textChanged,       // EditBox
            valueChanged,      // Slider, LoadingBar
            itemSelected,      // Listbox, ComboBox
            animationFinished, // AnimatedPicture
            closed,            // ChildWindow

            count // Keep this one last
        };
    };


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \internal
    // Get a sf::Color from a string. The string must look like: "(r, g, b)" or "(r, g, b, a)".
    // When this function fails then it will return black.
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    TGUI_API const sf::Color extractColor(std::string string);


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \internal
    // This function does exactly the opposite of extractColor.
    // The returned string will be "(r,g,b)" when a=255 or "(r,g,b,a)" when a<255.
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    TGUI_API std::string convertColorToString(const sf::Color& color);


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \internal
    // Get a Vector2f from a string. The string must look like: "(x, y)".
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    TGUI_API bool extractVector2f(std::string string, Vector2f& vector);


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \internal
    // Get a Vector4u from a string. The string must look like: "(x1, x2, x3, x4)".
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    TGUI_API bool extractVector4u(std::string string, Vector4u& vector);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif //_TGUI_OBJECTS_INCLUDED_
