#ifndef _WRAPPER_RAYLIB_PARSER_H_
#define _WRAPPER_RAYLIB_PARSER_H_

#ifdef USE_RAYLIB
#include "SekaiEngine/Render/Color.h"
#include "raylib.h"

::Color parseToRaylibColor(const SekaiEngine::Render::Color& color);
#endif

#endif //!_WRAPPER_RAYLIB_PARSER_H_