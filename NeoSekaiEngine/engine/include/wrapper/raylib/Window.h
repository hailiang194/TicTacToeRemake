#ifndef _SEKAI_ENGINE_WRAPPER_RAYLIB_WINDOW_H_
#define _SEKAI_ENGINE_WRAPPER_RAYLIB_WINDOW_H_

#ifdef USE_RAYLIB

#include "SekaiEngine/Window.h"

namespace Wrapper
{
    namespace Raylib
    {
        class Window: public SekaiEngine::IWindow
        {
        public:
            Window(const SekaiEngine::WindowsProps& props);
            Window(const Window& window);
            Window& operator=(const Window& window);
            virtual ~Window();  

            void OnUpdate() override;
            int GetHeight() const override;
            int GetWidth() const override;
            void setEventCallbackFn(const EventCallbackFn& fn) override;

            void SetVSync(bool enable) override;
            bool IsVSync() const override;
        private:
            unsigned int m_flag;
            IWindow::EventCallbackFn m_eventCallbackFn;

            void _pollEvent();
        };

        inline void Window::setEventCallbackFn(const EventCallbackFn& fn)
        {
            m_eventCallbackFn = fn;
        }
    } // namespace Raylib
    
} // namespace Wrapper

#endif//USE_RAYLIB

#endif //!_SEKAI_ENGINE_WRAPPER_RAYLIB_WINDOW_H_