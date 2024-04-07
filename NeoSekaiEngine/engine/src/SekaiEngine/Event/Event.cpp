#include "SekaiEngine/Event/Event.h"

namespace SekaiEngine
{
    namespace Event
    {
        Event::Event()
            :Handled(false)
        {

        }

        Event::Event(const Event& event)
            :Handled(event.Handled)
        {

        }

        Event& Event::operator=(const Event& event)
        {
            Handled = event.Handled;
            return (*this);
        }

        Event::~Event()
        {

        }

        EventDispatcher::EventDispatcher(Event& event)
            :m_event(event)
        {
        }

        EventDispatcher::EventDispatcher(const EventDispatcher& dispatcher)
            :m_event(dispatcher.m_event)
        {

        }

        EventDispatcher& EventDispatcher::operator=(const EventDispatcher& dispatcher)
        {
            m_event = dispatcher.m_event;
            return (*this);
        }

        EventDispatcher::~EventDispatcher()
        {

        }
    } // namespace Event
    
} // namespace SekaiEngine
