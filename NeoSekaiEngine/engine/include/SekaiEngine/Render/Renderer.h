#ifndef _SEKAI_ENGINE_RENDER_RENDERER_H_
#define _SEKAI_ENGINE_RENDER_RENDERER_H_

#include "SekaiEngine/Render/Camera.h"
#include "SekaiEngine/Render/RenderProperties.h"
#include "SekaiEngine/Shape/Circle.h"
#include "SekaiEngine/Shape/Rectangle.h"
#include "SekaiEngine/Render/Texture.h"

namespace SekaiEngine
{
    namespace Render
    {
        class EXTENDAPI Renderer
        {
        public:
            static void OnWindowResize(const int& width, const int& height);
        };
    } // namespace Render
    
} // namespace SekaiEngine


#endif//!_SEKAI_ENGINE_RENDER_RENDERER_H_