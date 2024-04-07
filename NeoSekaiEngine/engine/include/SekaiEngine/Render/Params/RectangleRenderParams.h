#ifndef _SEKAI_ENGINE_RENDER_PARAMS_RECTANGLE_RENDER_PARAMS_H_
#define _SEKAI_ENGINE_RENDER_PARAMS_RECTANGLE_RENDER_PARAMS_H_

#include "SekaiEngine/BaseType.h"
#include "SekaiEngine/Render/Params/RenderParams.h"
#include "SekaiEngine/Shape/Rectangle.h"

namespace SekaiEngine
{
    namespace Render
    {
        class EXTENDAPI RectangleRenderParams: public RenderParams
        {
        public:
            RectangleRenderParams(const RenderProperties& props, const Shape::Rectangle& rect);
            RectangleRenderParams(const RectangleRenderParams& params) = delete;
            RectangleRenderParams& operator=(const RectangleRenderParams& params) = delete;
            ~RectangleRenderParams();

            const Shape::Rectangle& DrawRect() const;
            const Shape::Rectangle& DrawRect();

            const Render::Color& Tint() const;
            const Render::Color& Tint();

            const Math::Vector2D& Origin() const;
            const Math::Vector2D& Origin();

            const float& Rotation() const;
            const float& Rotation();

        private:
            Shape::Rectangle m_drawRect;
        };

        inline const Shape::Rectangle& RectangleRenderParams::DrawRect() const
        {
            return m_drawRect;
        }

        inline const Shape::Rectangle& RectangleRenderParams::DrawRect()
        {
            return static_cast<const RectangleRenderParams&>(*this).DrawRect();
        }

        inline const Render::Color& RectangleRenderParams::Tint() const
        {
            return m_props.Tint;
        }

        inline const Render::Color& RectangleRenderParams::Tint()
        {
            return static_cast<const RectangleRenderParams&>(*this).Tint();
        }

        inline const Math::Vector2D& RectangleRenderParams::Origin() const
        {
            return m_props.Origin;
        }

        inline const Math::Vector2D& RectangleRenderParams::Origin()
        {
            return static_cast<const RectangleRenderParams&>(*this).Origin();
        }

        inline const float& RectangleRenderParams::Rotation() const
        {
            return m_props.Rotation;
        }

        inline const float& RectangleRenderParams::Rotation()
        {
            return static_cast<const RectangleRenderParams&>(*this).Rotation();
        }
    } // namespace Render
    
} // namespace SekaiEngine


#endif//!_SEKAI_ENGINE_RENDER_PARAMS_RECTANGLE_RENDER_PARAMS_H_