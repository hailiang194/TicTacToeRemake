#include "SekaiEngine/Render/Params/CircleRenderParams.h"

namespace SekaiEngine
{
    namespace Render
    {
        CircleRenderParams::CircleRenderParams(const RenderProperties& props, const Shape::Circle& circle)
            :RenderParams(props), m_drawCircle(Shape::Circle(
                Math::Vector2D(
                    props.Offset.X() + circle.Center.X() * props.Scale.X(),
                    props.Offset.Y() + circle.Center.Y() * props.Scale.Y()
                ),
                circle.Radius * m_props.Scale.X()
            )), m_startAngle(0.0f), m_endAngle(360.0f), m_segment(36)
        {

        }

        CircleRenderParams::~CircleRenderParams()
        {
            
        }
    } // namespace Render
    
} // namespace SekaiEngine
