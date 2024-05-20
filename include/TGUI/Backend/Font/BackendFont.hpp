/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TGUI - Texus' Graphical User Interface
// Copyright (C) 2012-2024 Bruno Van de Velde (vdv_b@tgui.eu)
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


#ifndef TGUI_BACKEND_FONT_HPP
#define TGUI_BACKEND_FONT_HPP

#include <TGUI/Font.hpp>
#include <TGUI/String.hpp>
#include <TGUI/Global.hpp>
#include <TGUI/Backend/Renderer/BackendTexture.hpp>

#if !TGUI_EXPERIMENTAL_USE_STD_MODULE
    #include <cstdint>
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TGUI_MODULE_EXPORT namespace tgui
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief Base class for font implementations that depend on the backend
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class TGUI_API BackendFont
    {
    public:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Default constructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        BackendFont();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Copy constructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        BackendFont(const BackendFont&);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Move constructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        BackendFont(BackendFont&& other) noexcept;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Virtual destructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual ~BackendFont();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Copy assignment operator
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        BackendFont& operator=(const BackendFont& other);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Move assignment operator
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        BackendFont& operator=(BackendFont&& other) noexcept;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Loads a font from a file
        ///
        /// @param filename  Filename of the font to load
        ///
        /// @return True if the font was loaded successfully, false otherwise
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual bool loadFromFile(const String& filename);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Loads a font from memory
        ///
        /// @param data         Moved pointer to the file data in memory
        /// @param sizeInBytes  Size of the data to load, in bytes
        ///
        /// @return True if the font was loaded successfully, false otherwise
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual bool loadFromMemory(std::unique_ptr<std::uint8_t[]> data, std::size_t sizeInBytes) = 0;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Loads a font from memory
        ///
        /// @param data         Pointer to the file data in memory
        /// @param sizeInBytes  Size of the data to load, in bytes
        ///
        /// @return True if the font was loaded successfully, false otherwise
        ///
        /// This function makes a copy of the data. Use the overload with a unique_ptr when possible to move instead of copy.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool loadFromMemory(const void* data, std::size_t sizeInBytes);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns whether a font contains a certain glyph
        ///
        /// @param codePoint  Character to check
        ///
        /// @return Does the font contain this character?
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD virtual bool hasGlyph(char32_t codePoint) const = 0;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Retrieve a glyph of the font
        ///
        /// If the font is a bitmap font, not all character sizes might be available. If the glyph is not available at the
        /// requested size, an empty glyph is returned.
        ///
        /// @param codePoint        Unicode code point of the character to get
        /// @param characterSize    Reference character size
        /// @param bold             Retrieve the bold version or the regular one?
        /// @param outlineThickness Thickness of outline (when != 0 the glyph will not be filled)
        ///
        /// @return The glyph corresponding to codePoint and characterSize
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD virtual FontGlyph getGlyph(char32_t codePoint, unsigned int characterSize, bool bold, float outlineThickness = 0) = 0;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the kerning offset of two glyphs
        ///
        /// The kerning is an extra offset (negative) to apply between two glyphs when rendering them, to make the pair look
        /// more "natural". For example, the pair "AV" have a special kerning to make them closer than other characters.
        /// Most of the glyphs pairs have a kerning offset of zero, though.
        ///
        /// @param first         Unicode code point of the first character
        /// @param second        Unicode code point of the second character
        /// @param characterSize Size of the characters
        /// @param bold          Are the glyphs bold or regular?
        ///
        /// @return Kerning value for first and second, in pixels
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD virtual float getKerning(char32_t first, char32_t second, unsigned int characterSize, bool bold) = 0;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the line spacing
        ///
        /// Line spacing is the vertical offset to apply between two consecutive lines of text.
        ///
        /// @param characterSize Size of the characters
        ///
        /// @return Line spacing, in pixels
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD virtual float getLineSpacing(unsigned int characterSize) = 0;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the height required to render a line of text
        ///
        /// @param characterSize  Size of the characters
        ///
        /// @return Sum of font ascent and descent
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD virtual float getFontHeight(unsigned int characterSize) = 0;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the maximum height of a glyph above the baseline
        ///
        /// @param characterSize  Size of the characters
        ///
        /// @return Ascent of the font
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD virtual float getAscent(unsigned int characterSize) = 0;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the maximum height of a glyph below the baseline
        ///
        /// @param characterSize  Size of the characters
        ///
        /// @return Descent of the font
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD virtual float getDescent(unsigned int characterSize) = 0;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Get the position of the underline
        ///
        /// Underline position is the vertical offset to apply between the baseline and the underline.
        ///
        /// @param characterSize  Reference character size
        ///
        /// @return Underline position, in pixels
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD virtual float getUnderlinePosition(unsigned int characterSize) = 0;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Get the thickness of the underline
        ///
        /// Underline thickness is the vertical size of the underline.
        ///
        /// @param characterSize  Reference character size
        ///
        /// @return Underline thickness, in pixels
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD virtual float getUnderlineThickness(unsigned int characterSize) = 0;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the texture that is used to store glyphs of the given character size
        ///
        /// @param characterSize  Size of the characters that should be part of the texture
        /// @param textureVersion Counter that is incremented each time the texture is changed, returned by this function
        ///
        /// @return Texture to render text glyphs with
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD virtual std::shared_ptr<BackendTexture> getTexture(unsigned int characterSize, unsigned int& textureVersion) = 0;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the size of the texture that is used to store glyphs of the given character size
        ///
        /// @param characterSize  Size of the characters that should be part of the texture
        ///
        /// @return Size of the texture that holds the glyphs
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD virtual Vector2u getTextureSize(unsigned int characterSize) = 0;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Enable or disable the smooth filter
        ///
        /// When the filter is activated, the font appears smoother so that pixels are less noticeable. However if you want
        /// the font to look exactly the same as its source file then you should disable it.
        /// The smooth filter is enabled by default.
        ///
        /// @param smooth  True to enable smoothing, false to disable it
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setSmooth(bool smooth);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Tell whether the smooth filter is enabled or not
        ///
        /// @return True if smoothing is enabled, false if it is disabled
        ///
        /// @see setSmooth
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD bool isSmooth() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /// @brief Sets the scale at which to render each glyph, to allow rendering text at a higher resolution
        ///
        /// Text may be rendered blurry if the font scale doesn't match the ratio between the window size and gui view.
        /// Default scaling is 1. If the scale is set to 1.5 then a font with text size 20 would be internally rendered at 30px.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setFontScale(float scale);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the scale at which glyphs are rendered
        ///
        /// Text may be rendered blurry if the font scale doesn't match the ratio between the window size and gui view.
        /// Default scaling is 1. If the scale is set to 1.5 then a font with text size 20 would be internally rendered at 30px.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD float getFontScale() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Creates a key for each unique character to render
        ///
        /// @param codePoint        Unicode code of the character
        /// @param characterSize    Reference character size
        /// @param bold             Whether the character has to be rendered with a bold font
        /// @param outlineThickness Thickness of the outline to draw around the character (0 means no outline)
        ///
        /// @return Id that is specific to the provided parameters
        ///
        /// Calling this function with the same parameters results in the same id, while other parameters result in another id.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD std::uint64_t constructGlyphKey(char32_t codePoint, unsigned int characterSize, bool bold, float outlineThickness) const;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        bool m_isSmooth = true;
        float m_fontScale = 1;
    };
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_BACKEND_FONT_HPP
