#include "SekaiEngine/Event/WindowEvent.h"

namespace SekaiEngine
{
    namespace Event
    {
        WindowResizeEvent::WindowResizeEvent(const int& width, const int& height)
            :m_width(width), m_height(height)
        {

        }

        WindowResizeEvent::WindowResizeEvent(const WindowResizeEvent& event)
            :m_width(event.m_width), m_height(event.m_height)
        {

        }

        WindowResizeEvent& WindowResizeEvent::operator=(const WindowResizeEvent& event)
        {
            m_width = event.m_width;
            m_height = event.m_height;
            return (*this);
        }

        WindowResizeEvent::~WindowResizeEvent()
        {

        }
    } // namespace Event
    
} // namespace SekaiEngine
