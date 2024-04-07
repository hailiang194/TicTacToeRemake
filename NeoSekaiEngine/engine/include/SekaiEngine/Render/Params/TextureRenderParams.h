#ifndef _SEKAI_ENGINE_RENDER_PARAMS_TEXTURE_RENDER_PARAMS_H_
#define _SEKAI_ENGINE_RENDER_PARAMS_TEXTURE_RENDER_PARAMS_H_

#include "SekaiEngine/BaseType.h"
#include "SekaiEngine/Render/Params/RenderParams.h"
#include "SekaiEngine/Render/Texture.h"
#include "SekaiEngine/Math/Vector.h"
#include "SekaiEngine/Shape/Rectangle.h"
#include "SekaiEngine/Render/Color.h"

namespace SekaiEngine
{
    namespace Render
    {
        class EXTENDAPI TextureRenderParams: public RenderParams
        {
        public:
            TextureRenderParams(const Render::RenderProperties& props, const Texture& texture, 
                const Math::Vector2D& position = Math::Vector2D(),
                const Shape::Rectangle& atlasPostion = FULL_RECTANGLE
            );
            TextureRenderParams(const TextureRenderParams& params) = delete;
            TextureRenderParams& operator=(const TextureRenderParams& params) = delete;
            ~TextureRenderParams();

            const Render::Texture& Texture() const;
            const Render::Texture& Texture();

            const Render::Color& Tint() const;
            const Render::Color& Tint();

            const Shape::Rectangle& Source() const;
            const Shape::Rectangle& Source();

            const Shape::Rectangle& Destination() const;
            const Shape::Rectangle& Destination();

            const Math::Vector2D& Origin() const;
            const Math::Vector2D& Origin();

            const float& Rotation() const;
            const float& Rotation();

        private:
            Shape::Rectangle m_source;
            Shape::Rectangle m_dest;
            Render::Texture m_texture;
        };

        inline const Render::Texture& TextureRenderParams::Texture() const
        {
            return m_texture;
        }

        inline const Render::Texture& TextureRenderParams::Texture()
        {
            return static_cast<const TextureRenderParams&>(*this).Texture();
        }

        inline const Render::Color& TextureRenderParams::Tint() const
        {
            return m_props.Tint;
        }

        inline const Render::Color& TextureRenderParams::Tint()
        {
            return static_cast<const TextureRenderParams&>(*this).Tint();
        }

        inline const Shape::Rectangle& TextureRenderParams::Source() const
        {
            return m_source;
        }

        inline const Shape::Rectangle& TextureRenderParams::Source()
        {
            return static_cast<const TextureRenderParams&>(*this).Source();
        }

        inline const Shape::Rectangle& TextureRenderParams::Destination() const
        {
            return m_dest;
        }

        inline const Shape::Rectangle& TextureRenderParams::Destination()
        {
            return static_cast<const TextureRenderParams&>(*this).Destination();
        }

        inline const Math::Vector2D& TextureRenderParams::Origin() const
        {
            return m_props.Origin;
        }

        inline const Math::Vector2D& TextureRenderParams::Origin()
        {
            return static_cast<const TextureRenderParams&>(*this).Origin();
        }

        inline const float& TextureRenderParams::Rotation() const
        {
            return m_props.Rotation;
        }

        inline const float& TextureRenderParams::Rotation()
        {
            return static_cast<const TextureRenderParams&>(*this).Rotation();
        }

    } // namespace Render
    
} // namespace SekaiEngine


#endif//!_SEKAI_ENGINE_RENDER_PARAMS_TEXTURE_RENDER_PARAMS_H_