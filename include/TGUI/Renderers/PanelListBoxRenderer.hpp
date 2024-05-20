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


#ifndef TGUI_PANEL_LIST_BOX_RENDERER_HPP
#define TGUI_PANEL_LIST_BOX_RENDERER_HPP


#include <TGUI/Renderers/ScrollablePanelRenderer.hpp>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TGUI_MODULE_EXPORT namespace tgui
{

    class TGUI_API PanelListBoxRenderer : public ScrollablePanelRenderer
    {
    public:
        using ScrollablePanelRenderer::ScrollablePanelRenderer;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the items background color of the panel list box
        ///
        /// @param itemsBackgroundColor  The new background color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setItemsBackgroundColor(Color itemsBackgroundColor);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the items background color
        ///
        /// @return Background color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Color getItemsBackgroundColor() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the background color used for the item below the mouse
        ///
        /// @param itemsBackgroundColor  The new hover background color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setItemsBackgroundColorHover(Color itemsBackgroundColor);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the background color used for the item below the mouse
        ///
        /// @return Background color of hovered item
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Color getItemsBackgroundColorHover() const;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the background color of the selected item
        ///
        /// @param itemsBackgroundColor  The new selected item background color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setSelectedItemsBackgroundColor(Color itemsBackgroundColor);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the background color of the selected item
        ///
        /// @return Selected item background color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Color getSelectedItemsBackgroundColor() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the background color used for the selected item when the mouse hovers over it
        ///
        /// @param backgroundColor  The new selected hover background color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setSelectedItemsBackgroundColorHover(Color backgroundColor);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the background color used for the selected item when the mouse hovers over it
        ///
        /// @return Background color of selected item in hover state
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Color getSelectedItemsBackgroundColorHover() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_PANEL_LIST_BOX_RENDERER_HPP
