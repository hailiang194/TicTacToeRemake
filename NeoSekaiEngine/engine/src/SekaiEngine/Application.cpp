#include "SekaiEngine/Event/Event.h"
#include "SekaiEngine/Event/WindowEvent.h"
#include "SekaiEngine/Application.h"
#include "SekaiEngine/Render/Renderer.h"
#include "SekaiEngine/Render/RenderCommand.h"
#include "SekaiEngine/Input.h"
#include "SekaiEngine/Render/Texture.h"
#include "SekaiEngine/Render/Font.h"
#include <iostream>
#include "version.h"

namespace SekaiEngine
{
    Application* Application::g_instance = nullptr;

    Application::Application()
        :window(IWindow::Create()), m_running(true), m_layerStack(), m_timer()
    {
        std::cout << "You are using NeoSekaiEngine v" << SEKAI_ENGINE_VERSION << std::endl;
        Application::g_instance = this;
        window->setEventCallbackFn(std::bind(&Application::OnEvent, this, std::placeholders::_1));
        SekaiEngine::Render::initTextures();
        SekaiEngine::Render::initFonts();
        m_timer.SetTargetFPS(60);
    }
    Application::Application(const Application& app)
        :window(app.window), m_running(app.m_running), m_layerStack(app.m_layerStack), m_timer()
    {

    }

    Application::~Application()
    {
        SekaiEngine::Render::unloadFonts();
        SekaiEngine::Render::destroyTextures();
        delete window;
    }

    void Application::OnEvent(Event::Event& event)
    {
        Event::EventDispatcher dispatcher(event);
        dispatcher.Dispatch<Event::WindowCloseEvent>(
            std::bind(&Application::OnWindowClose, this, std::placeholders::_1)
        );
        dispatcher.Dispatch<Event::WindowResizeEvent>(
            std::bind(&Application::OnWindowResize, this, std::placeholders::_1)
        );

        for(auto it = m_layerStack.end(); it != m_layerStack.begin();)
        {
            (*--it)->OnEvent(event);
            if(event.Handled)
                break;
        }
    }

    bool Application::OnWindowClose(Event::Event& event)
    {
        m_running = false;
        return true;
    }

    bool Application::OnWindowResize(Event::Event& event)
    {
        Event::WindowResizeEvent& resizeEvt = dynamic_cast<Event::WindowResizeEvent&>(event);
        Render::Renderer::OnWindowResize(resizeEvt.Width(), resizeEvt.Height());
        return false;
    }

    void Application::PushLayer(Layer::Layer* layer)
    {
        m_layerStack.PushLayer(layer);
    }

    void Application::PushOverlay(Layer::Layer* overlay)
    {
        m_layerStack.PushOverlay(overlay);
    }   

#if !defined(USE_RAYLIB) || defined(PLATFORM_WEB)
#else
    void Application::Run()
    {
        while(m_running)
        {
            loop();
        }
    }
#endif

    void Application::loop()
    {
        Timestep elipse = m_timer.update();
        window->OnUpdate();
        if(!m_running)
            return;
        
        
        for(auto it = m_layerStack.begin(); it != m_layerStack.end(); ++it)
        {
            (*it)->OnUpdate(elipse);
        }
        SekaiEngine::Render::RenderCommand::StartDrawing((SekaiEngine::Render::Color)0x000000ff);
        for(auto it = m_layerStack.begin(); it != m_layerStack.end(); ++it)
        {
            (*it)->OnRender();
        }
        SekaiEngine::Render::RenderCommand::FinishDrawing();
    }



    Application* Application::Instance()
    {
        return g_instance;
    }
} // namespace SekaiEngine
