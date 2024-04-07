#include "SekaiEngine/Input.h"
#include "raylib.h"

namespace SekaiEngine
{
    namespace Input
    {
        
        bool IsKeyPressed(int key)
        {
            return ::IsKeyDown(key);
        }

        bool IsButtonPressed(int key)
        {
            return ::IsMouseButtonDown(key);
        }

        float GetMouseX()
        {
            return static_cast<float>(::GetMouseX());
        }

        float GetMouseY()
        {
            return static_cast<float>(::GetMouseY());
        }
    } // namespace Input
    
} // namespace SekaiEngine
