#ifndef _SEKAI_ENGINE_LAYER_LAYER_STACK_H_
#define _SEKAI_ENGINE_LAYER_LAYER_STACK_H_

#include <vector>
#include "SekaiEngine/BaseType.h"
#include "SekaiEngine/Layer/Layer.h"

namespace SekaiEngine
{
    namespace Layer
    {
        class LayerStack 
        {
        public:
            EXTENDAPI LayerStack();
            LayerStack(const LayerStack& stack);
            LayerStack& operator=(const LayerStack& stack);
            EXTENDAPI ~LayerStack();

            EXTENDAPI void PushLayer(Layer* layer);
            EXTENDAPI void PushOverlay(Layer* overlay);
            EXTENDAPI void PopLayer(Layer* layer);
            EXTENDAPI void PopOverlay(Layer* overlay);

            std::vector<Layer*>::iterator begin();
            std::vector<Layer*>::iterator end();
        private:
            std::vector<Layer*> m_layers;
            std::vector<Layer*>::iterator m_layerInsert;
        };

        inline std::vector<Layer*>::iterator LayerStack::begin()
        {
            return m_layers.begin();
        }

        inline std::vector<Layer*>::iterator LayerStack::end()
        {
            return m_layers.end();
        }
    } // namespace Layer
    
} // namespace SekaiEngine


#endif//!_SEKAI_ENGINE_LAYER_LAYER_STACK_H_