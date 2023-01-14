/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TGUI - Texus' Graphical User Interface
// Copyright (C) 2012-2023 Bruno Van de Velde (vdv_b@tgui.eu)
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


#ifndef TGUI_REL_FLOAT_RECT_HPP
#define TGUI_REL_FLOAT_RECT_HPP


#include <TGUI/AbsoluteOrRelativeValue.hpp>
#include <TGUI/Rect.hpp>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief FloatRect that can contain absolute values or values relative to the parent size
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct RelFloatRect
    {
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Default constructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        constexpr RelFloatRect() = default;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Constructs the rectangle from its position and size
        ///
        /// @param left   Left coordinate of the rectangle
        /// @param top    Top coordinate of the rectangle
        /// @param width  Width of the rectangle
        /// @param height Height of the rectangle
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        constexpr RelFloatRect(AbsoluteOrRelativeValue left, AbsoluteOrRelativeValue top,
                                    AbsoluteOrRelativeValue width, AbsoluteOrRelativeValue height) :
            m_left{left},
            m_top{top},
            m_width{width},
            m_height{height}
        {
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the left position of the rect as an absolute value
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD constexpr float getLeft() const
        {
            return m_left.getValue();
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the top position of the rect as an absolute value
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD constexpr float getTop() const
        {
            return m_top.getValue();
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the width of the rect as an absolute value
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD constexpr float getWidth() const
        {
            return m_width.getValue();
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the height of the rect as an absolute value
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD constexpr float getHeight() const
        {
            return m_height.getValue();
        }

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the size of the rect as an absolute value
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD constexpr Vector2f getPosition() const
        {
            return {m_left.getValue(), m_top.getValue()};
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the size of the rect as an absolute value
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD constexpr Vector2f getSize() const
        {
            return {m_width.getValue(), m_height.getValue()};
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the the rectangle as an absolute value
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD constexpr FloatRect getRect() const
        {
            return {m_left.getValue(), m_top.getValue(), m_width.getValue(), m_height.getValue()};
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /// @brief Update the size to which the rectangle depends on if its values are relative
        ///
        /// @param newParentSize  New size from which to take the relative value
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        constexpr void updateParentSize(Vector2f newParentSize)
        {
            m_left.updateParentSize(newParentSize.x);
            m_top.updateParentSize(newParentSize.y);
            m_width.updateParentSize(newParentSize.x);
            m_height.updateParentSize(newParentSize.y);
        }

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    private:

        AbsoluteOrRelativeValue m_left;
        AbsoluteOrRelativeValue m_top;
        AbsoluteOrRelativeValue m_width;
        AbsoluteOrRelativeValue m_height;
    };
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_REL_FLOAT_RECT_HPP
