#ifndef _SEKAI_ENGINE_RENDER_RENDER_PROPERTIES_H_
#define _SEKAI_ENGINE_RENDER_RENDER_PROPERTIES_H_

#include "SekaiEngine/BaseType.h"
#include "SekaiEngine/Math/Vector.h"
#include "SekaiEngine/Render/Color.h"

namespace SekaiEngine
{
    namespace Render
    {
        class EXTENDAPI RenderProperties
        {
        public:
            RenderProperties();
            RenderProperties(const RenderProperties& props);
            RenderProperties& operator=(const RenderProperties& props);
            virtual ~RenderProperties();

            Math::Vector2D Offset;
            Math::Vector2D Scale;
            Render::Color Tint;
            Math::Vector2D Origin;
            float Rotation;
        };
    } // namespace Render
    
} // namespace SekaiEngine


#endif//!_SEKAI_ENGINE_RENDER_RENDER_PROPERTIES_H_