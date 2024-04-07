#ifndef _SEKAI_ENGINE_RENDER_PARAMS_CIRCLE_RENDER_PARAMS_H_
#define _SEKAI_ENGINE_RENDER_PARAMS_CIRCLE_RENDER_PARAMS_H_

#include "SekaiEngine/BaseType.h"
#include "SekaiEngine/Render/Params/RenderParams.h"
#include "SekaiEngine/Shape/Circle.h"

namespace SekaiEngine
{
    namespace Render
    {
        class EXTENDAPI CircleRenderParams: public RenderParams
        {
        public:
            CircleRenderParams(const RenderProperties& props, const Shape::Circle& circle);
            CircleRenderParams(const CircleRenderParams& params) = delete;
            CircleRenderParams& operator=(const CircleRenderParams& params) = delete;
            ~CircleRenderParams();

            const Shape::Circle& DrawCircle() const;
            const Shape::Circle& DrawCircle();

            const Render::Color& Tint() const;
            const Render::Color& Tint();

            const float& StartAngle() const;
            const float& StartAngle();

            const float& EndAngle() const;
            const float& EndAngle();

            const int& Segment() const;
            const int& Segment();

        private:
            Shape::Circle m_drawCircle;
            float m_startAngle;
            float m_endAngle;
            int m_segment;
        };


        inline const Shape::Circle& CircleRenderParams::DrawCircle() const
        {
            return m_drawCircle;
        }

        inline const Shape::Circle& CircleRenderParams::DrawCircle()
        {
            return static_cast<const CircleRenderParams&>(*this).DrawCircle();
        }

        inline const Render::Color& CircleRenderParams::Tint() const
        {
            return m_props.Tint;
        }

        inline const Render::Color& CircleRenderParams::Tint()
        {
            return static_cast<const CircleRenderParams&>(*this).Tint();
        }

        inline const float& CircleRenderParams::StartAngle() const
        {
            return m_startAngle;
        }

        inline const float& CircleRenderParams::StartAngle()
        {
            return static_cast<const CircleRenderParams&>(*this).StartAngle();
        }

        inline const float& CircleRenderParams::EndAngle() const
        {
            return m_endAngle;
        }

        inline const float& CircleRenderParams::EndAngle()
        {
            return static_cast<const CircleRenderParams&>(*this).EndAngle();
        }

        inline const int& CircleRenderParams::Segment() const
        {
            return m_segment;
        }

        inline const int& CircleRenderParams::Segment()
        {
            return static_cast<const CircleRenderParams&>(*this).Segment();
        }
    } // namespace Render
    
} // namespace SekaiEngine


#endif//!_SEKAI_ENGINE_RENDER_PARAMS_CIRCLE_RENDER_PARAMS_H_