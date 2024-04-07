#ifndef _SEKAI_ENGINE_MATH_UTILITY_H_
#define _SEKAI_ENGINE_MATH_UTILITY_H_

#include "SekaiEngine/BaseType.h"

#define DEFAULT_EPSILON 0.0001f

namespace SekaiEngine
{
    namespace Math
    {
        /// @brief Compare 2 float
        /// @param first first number
        /// @param second second number
        /// @param epsilon epsilon distance between 2 numbers to consider they are equal
        /// @return 1 if first > second, -1 if first < second and 0 if first == second
        EXTENDAPI const int cmpFloat(const float& first, const float& second, const float& epsilon = DEFAULT_EPSILON);
    } // namespace Math
    
} // namespace SekaiEngine


#endif//!_SEKAI_ENGINE_MATH_UTILITY_H_