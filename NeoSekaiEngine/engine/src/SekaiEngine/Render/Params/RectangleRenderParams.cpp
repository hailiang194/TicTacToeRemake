#include "SekaiEngine/Render/Params/RectangleRenderParams.h"

namespace SekaiEngine
{
    namespace Render
    {
        RectangleRenderParams::RectangleRenderParams(const RenderProperties& props, const Shape::Rectangle& rect)
            :RenderParams(props), m_drawRect(
                Math::Vector2D(
                    props.Offset.X() + rect.Position.X() * props.Scale.X(),
                    props.Offset.Y() + rect.Position.Y() * props.Scale.Y()
                ),
                rect.Width * props.Scale.X(), rect.Height * props.Scale.Y()
            )
        {

        }

        RectangleRenderParams::~RectangleRenderParams()
        {

        }
    } // namespace Render
    
} // namespace SekaiEngine
