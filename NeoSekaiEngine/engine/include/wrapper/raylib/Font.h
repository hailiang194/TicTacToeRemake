#ifndef _WRAPPER_RAYLIB_FONT_H_
#define _WRAPPER_RAYLIB_FONT_H_

#ifdef USE_RAYLIB
#include "raylib.h"

namespace SekaiEngine
{
    namespace Render
    {
        ::Font* getFontById(const char* id);
    } // namespace Render
    
} // namespace SekaiEngine

#endif

#endif//!_WRAPPER_RAYLIB_FONT_H_