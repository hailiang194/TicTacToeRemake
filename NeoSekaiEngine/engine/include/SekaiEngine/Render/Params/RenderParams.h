#ifndef _SEKAI_ENGINE_RENDER_PARAMS_RENDER_PARAMS_H_
#define _SEKAI_ENGINE_RENDER_PARAMS_RENDER_PARAMS_H_

#include "SekaiEngine/BaseType.h"
#include "SekaiEngine/Render/RenderProperties.h"

namespace SekaiEngine
{
    namespace Render
    {
        class EXTENDAPI RenderParams
        {
        public:
            RenderParams(const RenderProperties& props);
            RenderParams(const RenderParams& params) = delete;
            RenderParams& operator=(const RenderParams& params) = delete;
            virtual ~RenderParams();
        protected:
            const RenderProperties& m_props; 
        };
    } // namespace Render
    
} // namespace SekaiEngine


#endif//!_SEKAI_ENGINE_RENDER_PARAMS_RENDER_PARAMS_H_