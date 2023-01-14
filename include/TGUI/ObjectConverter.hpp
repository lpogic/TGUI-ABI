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


#ifndef TGUI_OBJECT_CONVERTER_HPP
#define TGUI_OBJECT_CONVERTER_HPP


#include <TGUI/TextStyle.hpp>
#include <TGUI/Variant.hpp>
#include <TGUI/Outline.hpp>
#include <TGUI/Texture.hpp>
#include <TGUI/Color.hpp>
#include <TGUI/Font.hpp>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    struct RendererData;

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief Implicit converter for settable properties
    ///
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class TGUI_API ObjectConverter
    {
    public:
        enum class Type
        {
            None,
            Bool,
            Font,
            Color,
            String,
            Number,
            Outline,
            Texture,
            TextStyle,
            RendererData
        };


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Default constructor, to create an empty object
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ObjectConverter() :
            m_type{Type::None}
        {
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Stores a string for later retrieval
        ///
        /// @param string  String to store
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ObjectConverter(const char* string) :
            ObjectConverter{String{string}}
        {
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Stores a string for later retrieval
        ///
        /// @param string  String to store
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ObjectConverter(const String& string) :
            m_type      {Type::String},
            m_value     {string},
            m_serialized{true},
            m_string    {string}
        {
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Stores a font object for later retrieval
        ///
        /// @param font  Font to store
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ObjectConverter(Font font) :
            m_type {Type::Font},
            m_value{std::move(font)}
        {
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Stores a color object for later retrieval
        ///
        /// @param color  Color to store
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ObjectConverter(Color color) :
            m_type {Type::Color},
            m_value{color}
        {
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Stores a boolean for later retrieval
        ///
        /// @param value  Boolean to store
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ObjectConverter(bool value) :
            m_type {Type::Bool},
            m_value{value}
        {
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Stores a number for later retrieval
        ///
        /// @param number  Number to store
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
        ObjectConverter(T number) :
            m_type {Type::Number},
            m_value{static_cast<float>(number)}
        {
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Stores an outline object for later retrieval
        ///
        /// @param outline  Outline to store
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ObjectConverter(const Outline& outline) :
            m_type {Type::Outline},
            m_value{outline}
        {
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Stores a texture object for later retrieval
        ///
        /// @param texture  Texture to store
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ObjectConverter(const Texture& texture) :
            m_type {Type::Texture},
            m_value{texture}
        {
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Stores a single text style for later retrieval
        ///
        /// @param style  Text style to store
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ObjectConverter(TextStyle style) :
            m_type {Type::TextStyle},
            m_value{TextStyles(style)}
        {
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Stores a text style for later retrieval
        ///
        /// @param style  Text style to store
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ObjectConverter(TextStyles style) :
            m_type {Type::TextStyle},
            m_value{style}
        {
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Stores render data for later retrieval
        ///
        /// @param data  Renderer data to store
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ObjectConverter(std::shared_ptr<RendererData> data) :
            m_type {Type::RendererData},
            m_value{std::move(data)}
        {
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Retrieves the saved string
        ///
        /// @return The saved string or a serialized string
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD const String& getString();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Retrieves the saved font
        ///
        /// @return The saved font
        ///
        /// This function will assert when something other than a font was saved
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD const Font& getFont();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Retrieves the saved color
        ///
        /// @return The saved color
        ///
        /// This function will assert when something other than a color was saved
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD const Color& getColor();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Retrieves the saved outline
        ///
        /// @return The saved outline
        ///
        /// This function will assert when something other than a outline was saved
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD const Outline& getOutline();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Retrieves the saved boolean
        ///
        /// @return The saved boolean
        ///
        /// This function will assert when something other than a boolean was saved
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD bool getBool();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Retrieves the saved number
        ///
        /// @return The saved number
        ///
        /// This function will assert when something other than a number was saved
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD float getNumber();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Retrieves the saved texture
        ///
        /// @return The saved texture
        ///
        /// This function will assert when something other than a texture was saved
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD const Texture& getTexture();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Retrieves the saved text style
        ///
        /// @return Saved text style
        ///
        /// This function will assert when something other than a text style was saved
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD const TextStyles& getTextStyle();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Retrieves the saved renderer data
        ///
        /// @return Saved renderer data
        ///
        /// This function will assert when something other than a renderer data was saved
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD const std::shared_ptr<RendererData>& getRenderer();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Retrieves the type of the object that has been stored
        ///
        /// @return The stored object type
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Type getType() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Check if the object equals another one
        ///
        /// Objects with different types will always be considered as different, even if using them would have the same outcome
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD bool operator==(const ObjectConverter& right) const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Check if the object differs from another one
        ///
        /// Objects with different types will always be considered as different, even if using them would have the same outcome
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD bool operator!=(const ObjectConverter& right) const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    private:
        Type m_type = Type::None;

        Variant<String, Font, Color, Outline, bool, float, Texture, TextStyles, std::shared_ptr<RendererData>> m_value;

        bool m_serialized = false;
        String m_string;
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_OBJECT_CONVERTER_HPP
