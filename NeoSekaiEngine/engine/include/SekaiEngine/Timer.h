#ifndef _SEKAI_ENGINE_TICKER_H_
#define _SEKAI_ENGINE_TICKER_H_

#include <chrono>
#include "SekaiEngine/BaseType.h"

namespace SekaiEngine
{
    class EXTENDAPI Timestep
    {
    public:
        explicit Timestep(const float& time = 0.0f);
        Timestep(const Timestep& step);
        Timestep& operator=(const Timestep& step);
        Timestep& operator=(const float& time);
        ~Timestep();

        
        float ToSeconds() const;
        float ToSeconds();

        float ToMiliseconds() const;
        float ToMiliseconds();

    private:
        float m_time;
    };

    class Timer
    {
    public:
        Timer();
        Timer(const Timer& timer);
        Timer& operator=(const Timer& timer);
        ~Timer();
        
        void SetTargetFPS(const int& fps);
        void wait();
        Timestep update();

    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> m_latestFrameTime;
    };

    inline float Timestep::ToSeconds() const
    {
        return m_time;
    }

    inline float Timestep::ToSeconds()
    {
        return static_cast<const Timestep&>(*this).ToSeconds();
    }

    inline float Timestep::ToMiliseconds() const
    {
        return m_time * 1000;
    }

    inline float Timestep::ToMiliseconds()
    {
        return static_cast<const Timestep&>(*this).ToMiliseconds();
    }

} // namespace SekaiEngine


#endif//!_SEKAI_ENGINE_TICKER_H_