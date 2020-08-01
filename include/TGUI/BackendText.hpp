/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TGUI - Texus' Graphical User Interface
// Copyright (C) 2012-2020 Bruno Van de Velde (vdv_b@tgui.eu)
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


#ifndef TGUI_BACKEND_TEXT_HPP
#define TGUI_BACKEND_TEXT_HPP

#include <TGUI/Text.hpp>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief Base class for text implementations that depend on the backend
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class TGUI_API BackendTextBase
    {
    public:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Virtual destructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual ~BackendTextBase() = default;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the size of the text
        /// @return Size of the bounding box around the text
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual Vector2f getSize() = 0;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the text
        /// @param string  Text that should be displayed
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setString(const String& string) = 0;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Sets the size of the characters
        /// @param characterSize  Maximum size available for characters above the baseline
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setCharacterSize(unsigned int characterSize) = 0;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the color of the text
        /// @param color  Text color
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setFillColor(const Color& color) = 0;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the color of the text outline
        /// @param color  Outline color
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setOutlineColor(const Color& color) = 0;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the thickness of the text outline
        /// @param thickness  Outline thickness
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setOutlineThickness(float thickness) = 0;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the text style
        /// @param style  New text style
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setStyle(TextStyle style) = 0;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the font used by the text
        /// @param font  New text font
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setFont(const Font& font) = 0;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the top-left position of the character at the provided index
        /// @param index  Index of the character for which the position should be returned
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual Vector2f findCharacterPos(std::size_t index) const = 0;
    };
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_BACKEND_TEXT_HPP
