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


#include <TGUI/Backends/SFML/BackendTextureSFML.hpp>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    bool BackendTextureSFML::loadFromFile(const String& filename)
    {
        image = std::make_unique<sf::Image>();
        if (!image->loadFromFile(filename.toAnsiString()))
        {
            image = nullptr;
            return false;
        }

        if (!texture.loadFromImage(*image))
        {
            image = nullptr;
            return false;
        }

        return true;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    bool BackendTextureSFML::loadFromPixelData(Vector2u size, const std::uint8_t* pixels)
    {
        if (Vector2u{texture.getSize()} != size)
        {
            if (!texture.create(size.x, size.y))
                return false;

            image = nullptr;
        }

        texture.update(pixels);
        return true;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Vector2u BackendTextureSFML::getSize() const
    {
        return Vector2u{texture.getSize()};
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void BackendTextureSFML::setSmooth(bool smooth)
    {
        texture.setSmooth(smooth);
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    bool BackendTextureSFML::isSmooth() const
    {
        return texture.isSmooth();
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    bool BackendTextureSFML::isTransparentPixel(Vector2u pixel) const
    {
        if (!image)
            return false;

        return (image->getPixel(pixel.x, pixel.y).a == 0);
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    sf::Texture& BackendTextureSFML::getInternalTexture()
    {
        return texture;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    const sf::Texture& BackendTextureSFML::getInternalTexture() const
    {
        return texture;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
