#include "SekaiEngine/Window.h"
#ifdef USE_RAYLIB
#include "wrapper/raylib/Window.h"
#endif

namespace SekaiEngine
{
    WindowsProps::WindowsProps(const char* title, const int& width, const int& height)
        :Title(title), Width(width), Height(height)
    {

    }

    WindowsProps::WindowsProps(const WindowsProps& props)
        :Title(props.Title), Width(props.Width), Height(props.Height)
    {

    }

    WindowsProps& WindowsProps::operator=(const WindowsProps& props)
    {
        Title = props.Title;
        Width = props.Width;
        Height = props.Height;

        return (*this);
    }

    WindowsProps::~WindowsProps()
    {

    }

    IWindow::~IWindow()
    {
        
    }

    IWindow* IWindow::Create(const WindowsProps& props)
    {
#ifdef USE_RAYLIB
        return new Wrapper::Raylib::Window(props);
#else
        return nullptr;
#endif
    }

} // namespace SekaiEngine
