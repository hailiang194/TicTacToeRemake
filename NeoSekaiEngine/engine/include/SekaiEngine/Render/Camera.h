#ifndef _SEKAI_ENGINE_RENDER_CAMERA_H_
#define _SEKAI_ENGINE_RENDER_CAMERA_H_

#include "SekaiEngine/BaseType.h"
#include "SekaiEngine/Math/Vector.h"

namespace SekaiEngine
{
    namespace Render
    {
        class EXTENDAPI Camera2D
        {
        public:
            Camera2D(
                const Math::Vector2D& postion = Math::Vector2D(), 
                const Math::Vector2D& offset = Math::Vector2D(), 
                const float& zoom = 1.0f,
                const float& rotation = 0.0f
            );
            Camera2D(const Camera2D& camera);
            Camera2D& operator=(const Camera2D& camera);
            virtual ~Camera2D();

            void applyCamera();
            void unapplyCamera();

            Math::Vector2D Position;
            Math::Vector2D Offset;
            float Zoom;
            float Rotation;
        };
    } // namespace Render
    
} // namespace SekaiEngine


#endif//!_SEKAI_ENGINE_RENDER_CAMERA_H_