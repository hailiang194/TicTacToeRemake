#include "SekaiEngine/Render/Params/TextureRenderParams.h"

namespace SekaiEngine
{
    namespace Render
    {
        TextureRenderParams::TextureRenderParams(const Render::RenderProperties& props, const Render::Texture& texture, 
            const Math::Vector2D& position, const Shape::Rectangle& atlasPostion
        )
            :RenderParams(props), m_texture(texture), m_source(atlasPostion), 
            m_dest(
                Math::Vector2D(
                    props.Offset.X() + position.X() * props.Scale.X(), 
                    props.Offset.Y() + position.Y() * props.Scale.Y()
                ),
                texture.Width() * props.Scale.X(), texture.Height() * props.Scale.Y()
            )
        {
            
        }

        TextureRenderParams::~TextureRenderParams()
        {

        }
    } // namespace Render
    
} // namespace SekaiEngine
