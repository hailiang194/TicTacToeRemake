#ifndef _SEKAI_ENGINE_SHAPE_RECTANGLE_H_
#define _SEKAI_ENGINE_SHAPE_RECTANGLE_H_

#include "SekaiEngine/BaseType.h"
#include "SekaiEngine/Shape/Shape.h"
#include "SekaiEngine/Math/Vector.h"
#include <limits>

#define FULL_RECTANGLE SekaiEngine::Shape::Rectangle( \
    Math::Vector2D(std::numeric_limits<float>::min(), std::numeric_limits<float>::min()), \
    std::numeric_limits<float>::max(), std::numeric_limits<float>::max() \
)

namespace SekaiEngine
{
    namespace Shape
    {
        class EXTENDAPI Rectangle: public IShape
        {
        public:
            Rectangle(const Math::Vector2D& position = Math::Vector2D(), const float& width = 0.0f, const float& height = 0.0f);
            Rectangle(const Rectangle& rect);
            Rectangle& operator=(const Rectangle& rect);
            ~Rectangle();

            Math::Vector2D Position;
            float Width;
            float Height;
        };
    } // namespace Shape
    
} // namespace SekaiEngine


#endif//!_SEKAI_ENGINE_SHAPE_RECTANGLE_H_