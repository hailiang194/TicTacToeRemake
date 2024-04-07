#ifndef _SEKAI_ENGINE_WINDOW_H_
#define _SEKAI_ENGINE_WINDOW_H_

#include <functional>
#include "SekaiEngine/BaseType.h"
#include "SekaiEngine/Event/Event.h"

namespace SekaiEngine 
{
    class EXTENDAPI WindowsProps
    {
    public:
        WindowsProps(const char* title = "Sekai Engine", const int& width = 1680, const int& height = 720);
        WindowsProps(const WindowsProps& props);
        WindowsProps& operator=(const WindowsProps& props);
        virtual ~WindowsProps();

        const char* Title;
        int Height;
        int Width;
    };

    class EXTENDAPI IWindow
    {
    public:
        using EventCallbackFn = std::function<void(Event::Event&)>;

        IWindow() = default;
        IWindow(const IWindow& window) = default;
        IWindow& operator=(const IWindow& window) = default;
        virtual ~IWindow();

        virtual void OnUpdate() = 0;
        virtual int GetHeight() const = 0;
        int GetHeight();
        virtual int GetWidth() const = 0;
        int GetWidth();
        virtual void setEventCallbackFn(const EventCallbackFn& fn) = 0;

        virtual void SetVSync(bool enable) = 0;
        virtual bool IsVSync() const = 0;

        static IWindow* Create(const WindowsProps& props = WindowsProps());
    };

    inline int IWindow::GetHeight()
    {
        return static_cast<const IWindow&>(*this).GetHeight();
    }

    inline int IWindow::GetWidth()
    {
        return static_cast<const IWindow&>(*this).GetWidth();
    }
}

#endif//!_SEKAI_ENGINE_WINDOW_H_