#ifndef _SEKAI_ENGINE_RENDER_REDNERER_API_H_
#define _SEKAI_ENGINE_RENDER_REDNERER_API_H_

#include "SekaiEngine/BaseType.h"
#include "SekaiEngine/Render/Color.h"
#include "SekaiEngine/Math/Vector.h"
#include "SekaiEngine/Render/Texture.h"
#include "SekaiEngine/Shape/Circle.h"
#include "SekaiEngine/Shape/Rectangle.h"
#include "SekaiEngine/Render/Font.h"

namespace SekaiEngine
{
    namespace Render
    {
        namespace API
        {
            EXTENDAPI void SetClearColor(const Color& color);
            EXTENDAPI void Clear();
            EXTENDAPI void BeginDrawing();
            EXTENDAPI void EndDrawing();
            EXTENDAPI void DrawCircle(const Shape::Circle& circle, const Color& color,
                const float& startAngle = 0.0f, const float& endAngle = 360.0f, const int& segment = 36
            );
            
            EXTENDAPI void DrawRect(const Shape::Rectangle& rect, const Color& color,
                const Math::Vector2D& origin = Math::Vector2D(), const float& rotation = 0.0f
            );

            EXTENDAPI void DrawTexture(const Render::Texture& texture, 
                const Color& color,
                const Shape::Rectangle& source = FULL_RECTANGLE,
                const Shape::Rectangle& dest = FULL_RECTANGLE,
                const Math::Vector2D& origin = Math::Vector2D(),
                const float rotation = 0.0f
            );

            EXTENDAPI void DrawText(
                const char* text,
                const Math::Vector2D& postion, const Render::Color& color,
                const float& fontSize, const Render::Font& font = Render::Font("default"),
                const float& spacing = 1.0f    
            );

        } // namespace API
        
    } // namespace Render
    
} // namespace SekaiEngine


#endif//!_SEKAI_ENGINE_RENDER_REDNERER_API_H_