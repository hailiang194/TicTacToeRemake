#ifndef _SEKAI_ENGINE_SHAPE_SHAPE_H_
#define _SEKAI_ENGINE_SHAPE_SHAPE_H_

#include "SekaiEngine/BaseType.h"

namespace SekaiEngine
{
    namespace Shape
    {
        class EXTENDAPI IShape
        {
        public:
            IShape() = default;
            IShape(const IShape& shape) = default;
            IShape& operator=(const IShape& shape) = default;
            virtual ~IShape();
        };
    } // namespace Shape
    
} // namespace SekaiEngine


#endif //!_SEKAI_ENGINE_SHAPE_SHAPE_H_