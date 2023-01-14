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


#ifndef TGUI_RADIO_BUTTON_RENDERER_HPP
#define TGUI_RADIO_BUTTON_RENDERER_HPP


#include <TGUI/Renderers/WidgetRenderer.hpp>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    class TGUI_API RadioButtonRenderer : public WidgetRenderer
    {
    public:

        using WidgetRenderer::WidgetRenderer;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the size of the borders
        ///
        /// @param borders  Size of the borders
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setBorders(const Borders& borders);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the size of the borders
        ///
        /// @return border size
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Borders getBorders() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the relative distance between the radio button and the text next to it
        ///
        /// @param ratio  The ratio of the distance based on the width of the radio button
        ///
        /// The default value is 0.2 which means that if the width of the radio button would be 50 pixels then
        /// the gap between the radio button and the text will be 10 pixels.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextDistanceRatio(float ratio);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief The relative distance between the radio button and the text next to it
        ///
        /// @return The ratio of the distance based on the width of the radio button
        ///
        /// @see setTextDistanceRatio
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD float getTextDistanceRatio() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the color of the text
        ///
        /// @param color  New text color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextColor(Color color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the text color
        ///
        /// @return text color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Color getTextColor() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the color of the text in hover state (mouse is standing on top of the radio button)
        ///
        /// @param color  New text color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextColorHover(Color color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the text color in the hover state (mouse on radio button)
        ///
        /// @return text color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Color getTextColorHover() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the color of the text when the radio button is disabled
        ///
        /// @param color  New text color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextColorDisabled(Color color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the text color when the radio button is disabled
        ///
        /// @return text color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Color getTextColorDisabled() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the color of the text when the radio button is checked
        ///
        /// @param color  New text color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextColorChecked(Color color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the text color when the radio button is checked
        ///
        /// @return text color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Color getTextColorChecked() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the color of the text in hover state when the radio button is checked
        ///
        /// @param color  New text color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextColorCheckedHover(Color color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the text color in the hover state when the radio button is checked
        ///
        /// @return text color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Color getTextColorCheckedHover() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the color of the text when the radio button is checked and disabled
        ///
        /// @param color  New text color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextColorCheckedDisabled(Color color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the text color when the radio button is checked and disabled
        ///
        /// @return text color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Color getTextColorCheckedDisabled() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the background color
        ///
        /// @param color  New background color
        ///
        /// This color is ignored when checked and unchecked images are set.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setBackgroundColor(Color color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the background color
        ///
        /// @return background color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Color getBackgroundColor() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the background color in hover state (mouse is standing on top of the radio button)
        ///
        /// @param color  New background color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setBackgroundColorHover(Color color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the background color in the hover state (mouse on radio button)
        ///
        /// @return background color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Color getBackgroundColorHover() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the background color when the radio button is disabled
        ///
        /// @param color  New background color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setBackgroundColorDisabled(Color color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the background color when the radio button is disabled
        ///
        /// @return background color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Color getBackgroundColorDisabled() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the background color used when the radio button is checked
        ///
        /// @param color  New background color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setBackgroundColorChecked(Color color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the background color used when the radio button is checked
        ///
        /// @return background color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Color getBackgroundColorChecked() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the background color in hover state used when the radio button is checked
        ///
        /// @param color  New background color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setBackgroundColorCheckedHover(Color color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the background color in the hover state used when the radio button is checked
        ///
        /// @return background color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Color getBackgroundColorCheckedHover() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the background color when the radio button is checked and disabled
        ///
        /// @param color  New background color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setBackgroundColorCheckedDisabled(Color color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the background color when the radio button is checked and disabled
        ///
        /// @return background color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Color getBackgroundColorCheckedDisabled() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the border color
        ///
        /// @param color  New border color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setBorderColor(Color color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the border color
        ///
        /// @return border color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Color getBorderColor() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the border color in hover state (mouse is standing on top of the radio button)
        ///
        /// @param color  New border color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setBorderColorHover(Color color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the border color in the hover state (mouse on radio button)
        ///
        /// @return border color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Color getBorderColorHover() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the border color when the radio button is disabled
        ///
        /// @param color  New border color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setBorderColorDisabled(Color color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the border color when the radio button is disabled
        ///
        /// @return border color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Color getBorderColorDisabled() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the color of the borders that is used when the radio button is focused (while not hovered)
        /// @param color  New border color
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setBorderColorFocused(Color color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the color of the borders that is used when the radio button is focused
        /// @return Border color
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Color getBorderColorFocused() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the border color used when the radio button is checked
        ///
        /// @param color  New border color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setBorderColorChecked(Color color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the border color used when the radio button is checked
        ///
        /// @return border color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Color getBorderColorChecked() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the border color in hover state used when the radio button is checked
        ///
        /// @param color  New border color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setBorderColorCheckedHover(Color color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the border color in the hover state used when the radio button is checked
        ///
        /// @return border color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Color getBorderColorCheckedHover() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the border color when the radio button is checked and disabled
        ///
        /// @param color  New border color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setBorderColorCheckedDisabled(Color color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the border color when the radio button is checked and disabled
        ///
        /// @return border color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Color getBorderColorCheckedDisabled() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the color of the borders that is used when the radio button is checked and focused (while not hovered)
        /// @param color  New border color
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setBorderColorCheckedFocused(Color color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the color of the borders that is used when the radio button is checked and focused
        /// @return Border color
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Color getBorderColorCheckedFocused() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the color that is used to fill the radio button when it is checked
        ///
        /// @param color  New check color
        ///
        /// This color is ignored when checked and unchecked images are set.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setCheckColor(Color color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the check color
        ///
        /// @return check color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Color getCheckColor() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the color that is used to fill the radio button when the mouse is on top of it
        ///
        /// @param color  New check color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setCheckColorHover(Color color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the check color used to fill the radio button when the mouse is on top of it
        ///
        /// @return check color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Color getCheckColorHover() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the color that is used to fill the radio button when the radio button is disabled
        ///
        /// @param color  New check color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setCheckColorDisabled(Color color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the check color used to fill the radio button when the radio button is disabled
        ///
        /// @return check color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Color getCheckColorDisabled() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the image that is displayed when the checkbox is not checked
        ///
        /// @param texture  The new unchecked texture
        ///
        /// When checked and unchecked images are set, the background and check color properties will be ignored.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextureUnchecked(const Texture& texture);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the image that is displayed when the checkbox is not checked
        ///
        /// @return unchecked texture
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD const Texture& getTextureUnchecked() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the image that is displayed when the checkbox is checked
        ///
        /// @param texture  The new checked texture
        ///
        /// When checked and unchecked images are set, the background and check color properties will be ignored.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextureChecked(const Texture& texture);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the image that is displayed when the checkbox is checked
        ///
        /// @return checked texture
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD const Texture& getTextureChecked() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the image that is displayed when the checkbox is not checked and the mouse is on top of the checkbox
        ///
        /// @param texture  The new unchecked hover texture
        ///
        /// This only has effect when the normal checked and unchecked images are also set.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextureUncheckedHover(const Texture& texture);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the image that is displayed when the checkbox is not checked and the mouse is on top of the checkbox
        ///
        /// @return unchecked hover texture
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD const Texture& getTextureUncheckedHover() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the image that is displayed when the checkbox is checked and the mouse is on top of the checkbox
        ///
        /// @param texture  The new checked hover texture
        ///
        /// This only has effect when the normal checked and unchecked images are also set.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextureCheckedHover(const Texture& texture);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the image that is displayed when the checkbox is checked and the mouse is on top of the checkbox
        ///
        /// @return checked hover texture
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD const Texture& getTextureCheckedHover() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the image that is displayed when the checkbox is not checked and the checkbox is disabled
        ///
        /// @param texture  The new unchecked disabled texture
        ///
        /// This only has effect when the normal checked and unchecked images are also set.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextureUncheckedDisabled(const Texture& texture);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the image that is displayed when the checkbox is not checked and the checkbox is disabled
        ///
        /// @return unchecked disabled texture
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD const Texture& getTextureUncheckedDisabled() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the image that is displayed when the checkbox is checked and the checkbox is disabled
        ///
        /// @param texture  The new checked disabled texture
        ///
        /// This only has effect when the normal checked and unchecked images are also set.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextureCheckedDisabled(const Texture& texture);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the image that is displayed when the checkbox is checked and the checkbox is disabled
        ///
        /// @return checked disabled texture
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD const Texture& getTextureCheckedDisabled() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the image that is displayed on top of the checkbox when it is unchecked and focused
        /// @param texture  The new focused texture
        ///
        /// This only has effect when the normal checked and unchecked images are also set.
        /// Pass an empty texture to unset the image.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextureUncheckedFocused(const Texture& texture);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the image that is displayed on top of the checkbox when it is unchecked and focused
        /// @return focused texture
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD const Texture& getTextureUncheckedFocused() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the image that is displayed on top of the checkbox when it is checked and focused
        /// @param texture  The new focused texture
        ///
        /// This only has effect when the normal checked and unchecked images are also set.
        /// Pass an empty texture to unset the image.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextureCheckedFocused(const Texture& texture);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the image that is displayed on top of the checkbox when it is checked and focused
        /// @return focused texture
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD const Texture& getTextureCheckedFocused() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the text style
        ///
        /// @param style  New text style
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextStyle(TextStyles style);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns text style
        ///
        /// @return Style of the text
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD TextStyles getTextStyle() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the text style in the checked state
        ///
        /// @param style  New text style
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextStyleChecked(TextStyles style);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns text style in the checked state
        ///
        /// @return Style of the text
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD TextStyles getTextStyleChecked() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_RADIO_BUTTON_RENDERER_HPP
