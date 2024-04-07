#include "SekaiEngine/Math/Utility.h"

#include <cmath>

namespace SekaiEngine
{
    namespace Math
    {
        const int cmpFloat(const float& first, const float& second, const float& epsilon)
        {
            if (std::fabs(first - second) < epsilon)
                return 0;

            return (first > second) ? 1 : -1;
        }
    } // namespace Math
    
} // namespace SekaiEngine
