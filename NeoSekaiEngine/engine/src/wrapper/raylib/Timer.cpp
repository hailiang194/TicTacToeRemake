#include "SekaiEngine/Timer.h"

#ifdef USE_RAYLIB
#include "raylib.h"

namespace SekaiEngine
{
    void Timer::SetTargetFPS(const int& fps)
    {
        ::SetTargetFPS(fps);
    }

    void wait()
    {

    }
} // namespace SekaiEngine


#endif