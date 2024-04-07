#include "SekaiEngine/Layer/Layer.h"

namespace SekaiEngine
{
    namespace Layer
    {
        Layer::Layer(const char* name)
            :m_debugName(name)
        {

        }

        Layer::Layer(const Layer& layer)
            :m_debugName(layer.m_debugName)
        {

        }

        Layer& Layer::operator=(const Layer& layer)
        {
            m_debugName = layer.m_debugName;
            return (*this);
        }

        Layer::~Layer()
        {

        }

        void Layer::OnAttach()
        {

        }

        void Layer::OnDetach()
        {

        }

        void Layer::OnUpdate(const Timestep& elipse)
        {

        }

        void Layer::OnRender()
        {

        }


        void Layer::OnEvent(Event::Event& event)
        {
            
        }
    } // namespace Layer
    
} // namespace SekaiEngine
