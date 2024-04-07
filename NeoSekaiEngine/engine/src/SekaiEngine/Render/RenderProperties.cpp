#include "SekaiEngine/Render/RenderProperties.h"

namespace SekaiEngine
{
    namespace Render
    {
        RenderProperties::RenderProperties()
            :Offset(0.0f, 0.0f), Scale(1.0f, 1.0f), Tint(0xffffffff), Origin(0.0f, 0.0f), Rotation(0.0f) 
        {

        }

        RenderProperties::RenderProperties(const RenderProperties& props)
            :Offset(props.Offset), Scale(props.Scale), Tint(props.Tint), Origin(props.Origin), Rotation(props.Rotation)
        {

        }

        RenderProperties& RenderProperties::operator=(const RenderProperties& props)
        {
            Offset = props.Offset;
            Scale = props.Scale;
            Tint = props.Tint;
            Origin = props.Origin;
            Rotation = props.Rotation;

            return (*this);
        }

        RenderProperties::~RenderProperties()
        {

        }
    } // namespace Render
    
} // namespace SekaiEngine
