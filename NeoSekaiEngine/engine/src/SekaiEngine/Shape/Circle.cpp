#include "SekaiEngine/Shape/Circle.h"

namespace SekaiEngine
{
    namespace Shape
    {
        Circle::Circle(const Math::Vector2D& center, const float& radius)
            :Center(center), Radius(radius)
        {

        }

        Circle::Circle(const Circle& circle)
            :Center(circle.Center), Radius(circle.Radius)
        {

        }

        Circle& Circle::operator=(const Circle& circle)
        {
            Center = circle.Center;
            Radius = circle.Radius;

            return (*this);
        }

        Circle::~Circle()
        {

        }
    } // namespace Shape
    
} // namespace SekaiEngine
