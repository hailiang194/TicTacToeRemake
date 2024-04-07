#include "SekaiEngine/Layer/LayerStack.h"
#include <algorithm>

namespace SekaiEngine
{
    namespace Layer
    {
        LayerStack::LayerStack()
            :m_layers(), m_layerInsert(m_layers.begin())
        {

        }

        LayerStack::LayerStack(const LayerStack& stack)
            :m_layers(stack.m_layers), m_layerInsert(stack.m_layerInsert)
        {

        }

        LayerStack& LayerStack::operator=(const LayerStack& stack)
        {
            m_layers = stack.m_layers;
            m_layerInsert = stack.m_layerInsert;

            return (*this);
        }

        LayerStack::~LayerStack()
        {
            for(auto layerIter = m_layers.begin(); layerIter != m_layers.end(); ++layerIter)
            {
                delete (*layerIter);
            }
        }

        void LayerStack::PushLayer(Layer* layer)
        {
            m_layerInsert = m_layers.emplace(m_layerInsert, layer);
        }

        void LayerStack::PushOverlay(Layer* overlay)
        {
            m_layers.emplace_back(overlay);
        }

        void LayerStack::PopLayer(Layer* layer)
        {
            auto it = std::find(m_layers.begin(), m_layers.end(), layer);
            if(it != m_layers.end())
            {
                m_layers.erase(it);
                --m_layerInsert;
            }
        }

        void LayerStack::PopOverlay(Layer* overlay)
        {
            auto it = std::find(m_layers.begin(), m_layers.end(), overlay);
            if(it != m_layers.end())
            {
                m_layers.erase(it);
            }
        }
    } // namespace Layer
    
} // namespace SekaiEngine
