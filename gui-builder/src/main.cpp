/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TGUI - Texus' Graphical User Interface
// Copyright (C) 2012-2021 Bruno Van de Velde (vdv_b@tgui.eu)
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

#include "GuiBuilder.hpp"

// SDL has its own main function on some platforms but it has a define so that we can still call our version "main".
// So if we are using the SDL backend then we must include it in this file.
#if !TGUI_HAS_BACKEND_SFML && TGUI_HAS_BACKEND_SDL
    #include <SDL_main.h>
#endif

int main(int, char* argv[])
{
    try
    {
        GuiBuilder builder(argv[0]);
        builder.mainLoop();
    }
    catch (const tgui::Exception& e)
    {
        std::cerr << "TGUI exception thrown: " << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception thrown: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "Unknown exception thrown" << std::endl;
        throw; // Throw to hopefully print some information about the exception on some platforms
    }
    return 0;
}
