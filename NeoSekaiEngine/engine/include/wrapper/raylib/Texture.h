#ifndef _WRAPPER_RAYLIB_TEXTURE_H_
#define _WRAPPER_RAYLIB_TEXTURE_H_

#ifdef USE_RAYLIB

#include "raylib.h"

namespace SekaiEngine
{
    namespace Render
    {
        ::Texture* getTexture(const int& id);
    } // namespace Render
    
} // namespace SekaiEngine

#endif


#endif//!_WRAPPER_RAYLIB_TEXTURE_H_