#ifndef _SEKAI_ENGINE_EVENT_WINDOW_H_
#define _SEKAI_ENGINE_EVENT_WINDOW_H_

#include "SekaiEngine/Event/Event.h"

namespace SekaiEngine
{
    namespace Event
    {
        class WindowResizeEvent: public Event
        {
        public:
            WindowResizeEvent(const int& width, const int& height);
            WindowResizeEvent(const WindowResizeEvent& event);
            WindowResizeEvent& operator=(const WindowResizeEvent& event);
            virtual ~WindowResizeEvent();

            EVENT_CLASS_TYPE(SekaiEngine::Event::EventType::WindowResize)
            EVENT_CLASS_CATEGORY(EventCategoryApplication)

            const int& Width() const;
            const int& Width();

            const int& Height() const;
            const int& Height();

        protected:
            int m_width;
            int m_height;
        }; 

        class WindowCloseEvent: public Event
        {
        public:
            WindowCloseEvent() = default;
            WindowCloseEvent(const WindowCloseEvent& event) = default;
            WindowCloseEvent& operator=(const WindowCloseEvent& event) = default;
            ~WindowCloseEvent() {}

            EVENT_CLASS_TYPE(SekaiEngine::Event::EventType::WindowClose)
            EVENT_CLASS_CATEGORY(EventCategoryApplication)
        };

        inline const int& WindowResizeEvent::Width() const
        {
            return m_width;
        }

        inline const int& WindowResizeEvent::Width()
        {
            return static_cast<const WindowResizeEvent&>(*this).Width();
        }

        inline const int& WindowResizeEvent::Height() const
        {
            return m_height;
        }

        inline const int& WindowResizeEvent::Height()
        {
            return static_cast<const WindowResizeEvent&>(*this).Height();
        }
    } // namespace Event
    
} // namespace SekaiEngine


#endif //!_SEKAI_ENGINE_EVENT_WINDOW_H_