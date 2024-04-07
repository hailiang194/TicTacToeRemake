#ifndef _SEKAI_ENGINE_ENTRY_POINT_H_
#define _SEKAI_ENGINE_ENTRY_POINT_H_

#ifdef HAS_ENTRY_POINT

extern SekaiEngine::Application* SekaiEngine::CreateApplication();

int main(int argc, char**argv)
{
    auto app = SekaiEngine::CreateApplication();
    app->Run();
    delete app;
    return 0;
}

#endif

#endif//!_SEKAI_ENGINE_ENTRY_POINT_H_