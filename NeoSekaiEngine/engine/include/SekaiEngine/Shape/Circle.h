#ifndef _SEKAI_ENGINE_SHAPE_CIRCLE_H_
#define _SEKAI_ENGINE_SHAPE_CIRCLE_H_

#include "SekaiEngine/BaseType.h"
#include "SekaiEngine/Math/Vector.h"
#include "SekaiEngine/Shape/Shape.h"

namespace SekaiEngine
{
    namespace Shape
    {
        class EXTENDAPI Circle: public IShape
        {
        public:
            Circle(const Math::Vector2D& center = Math::Vector2D(), const float& radius = 0.0f);
            Circle(const Circle& circle);
            Circle& operator=(const Circle& circle);
            ~Circle();

            Math::Vector2D Center;
            float Radius;
        };
    } // namespace Shape
    
} // namespace SekaiEngine


#endif//!_SEKAI_ENGINE_SHAPE_CIRCLE_H_