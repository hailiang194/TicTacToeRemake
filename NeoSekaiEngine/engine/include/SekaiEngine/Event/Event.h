#ifndef _SEKAI_ENGINE_EVENT_EVENT_H_
#define _SEKAI_ENGINE_EVENT_EVENT_H_

#include <functional>
#include "SekaiEngine/BaseType.h"

namespace SekaiEngine
{
    namespace Event
    {
        enum class EventType
        {
            None = 0,
            WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
            AppTick, AppUpdate, AppRender,
            KeyPressed, KeyRelease,
            MouseButtonPressed, MouseButtonRelease, MouseMoved, MouseScrolled
        };

        enum EventCategory
        {
            None = 0,
            EventCategoryApplication = 0x1,
            EventCategoryInput = 0x2,
            EventCategoryKeyboard = 0x4,
            EventCategoryMouse = 0x8,
            EventCategoryMouseButton = 0xf
        };

#define EVENT_CLASS_TYPE(type)  static EventType GetStaticType() { return type; } \
                                virtual EventType GetEventType() const override { return GetStaticType(); } \
                                virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

        class EXTENDAPI Event
        {
        public:
            Event();
            Event(const Event& event);
            Event& operator=(const Event& event);
            virtual ~Event();

            virtual EventType GetEventType() const = 0;
            virtual const char* GetName() const = 0;
            virtual int GetCategoryFlags() const = 0;
            bool IsInCategory(EventCategory category);

            bool Handled;
        };

        class EventDispatcher
        {
            template<typename T>
            using EventFn = std::function<bool(T&)>;
        public:
            EventDispatcher(Event& event);
            EventDispatcher(const EventDispatcher& dispatcher);
            EventDispatcher& operator=(const EventDispatcher& dispatcher);
            ~EventDispatcher();

            template<typename T, typename F>
            bool Dispatch(const F& func);

        private:
            Event& m_event;
        };

        inline bool Event::IsInCategory(EventCategory category)
        {
            return GetCategoryFlags() & category;
        }

        template<typename T, typename F>
        inline bool EventDispatcher::Dispatch(const F& func)
        {
            if(m_event.GetEventType() == T::GetStaticType())
            {
                m_event.Handled |= func(static_cast<T&>(m_event));
                return true;
            }

            return false;
        }
    } // namespace Event
    
} // namespace SekaiEngine


#endif//!_SEKAI_ENGINE_EVENT_EVENT_H_