#ifndef _SEKAI_ENGINE_RENDER_RENDER_COMMAND_H_
#define _SEKAI_ENGINE_RENDER_RENDER_COMMAND_H_

#include "SekaiEngine/BaseType.h"
#include "SekaiEngine/Render/RendererAPI.h"
#include "SekaiEngine/Render/Params/CircleRenderParams.h"
#include "SekaiEngine/Render/Params/RectangleRenderParams.h"
#include "SekaiEngine/Render/Params/TextureRenderParams.h"

namespace SekaiEngine
{
    namespace Render
    {
        namespace RenderCommand
        {

            void StartDrawing(const Color& color);
            void FinishDrawing();

            void Render(const RenderParams& params);
            void Render(const CircleRenderParams& params);
            void Render(const RectangleRenderParams& params);
            void Render(const TextureRenderParams& params);

            inline void StartDrawing(const Color& color)
            {
                Render::API::BeginDrawing();
                Render::API::SetClearColor(color);
                Render::API::Clear();
            }

            inline void FinishDrawing()
            {
                Render::API::EndDrawing();
            }

            inline void Render(const RenderParams& params)
            {
                if(dynamic_cast<const CircleRenderParams*>(&params) != nullptr)
                {
                    Render(*dynamic_cast<const CircleRenderParams*>(&params));
                }
                else if(dynamic_cast<const RectangleRenderParams*>(&params) != nullptr)
                {
                    Render(*dynamic_cast<const RectangleRenderParams*>(&params));
                }
                else if(dynamic_cast<const TextureRenderParams*>(&params) != nullptr)
                {
                    Render(*dynamic_cast<const TextureRenderParams*>(&params));
                }
            }

            inline void Render(const CircleRenderParams& params)
            {
                Render::API::DrawCircle(
                    params.DrawCircle(), params.Tint(), 
                    params.StartAngle(), params.EndAngle(), params.Segment()
                );
            }

            inline void Render(const RectangleRenderParams& params)
            {
                Render::API::DrawRect(params.DrawRect(), params.Tint(), params.Origin(), params.Rotation());
            }

            inline void Render(const TextureRenderParams& params)
            {
                Render::API::DrawTexture(params.Texture(), params.Tint(), 
                    params.Source(), params.Destination(), 
                    params.Origin(), params.Rotation()
                );
            }

        } // namespace RenderCommand
        
    } // namespace Render
    
} // namespace SekaiEngine


#endif//!_SEKAI_ENGINE_RENDER_RENDER_COMMAND_H_