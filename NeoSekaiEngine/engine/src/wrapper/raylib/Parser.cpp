#include "wrapper/raylib/Parser.h"

#ifdef USE_RAYLIB

::Color parseToRaylibColor(const SekaiEngine::Render::Color& color)
{
    ::Color result;
    SekaiEngine::Render::ColorParser parser;
    parser.code = color.code();
    result.a = parser.value.a;
    result.r = parser.value.r;
    result.g = parser.value.g;
    result.b = parser.value.b;

    return result;
}

#endif