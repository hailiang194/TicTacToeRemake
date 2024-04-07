#include "SekaiEngine/Shape/Rectangle.h"

namespace SekaiEngine
{
    namespace Shape
    {
        Rectangle::Rectangle(const Math::Vector2D& position, const float& width, const float& height)
            :Position(position), Width(width), Height(height)
        {

        }

        Rectangle::Rectangle(const Rectangle& rect)
            :Position(rect.Position), Width(rect.Width), Height(rect.Height)
        {

        }

        Rectangle& Rectangle::operator=(const Rectangle& rect)
        {
            Position = rect.Position;
            Width = rect.Width;
            Height = rect.Height;

            return (*this);
        }

        Rectangle::~Rectangle()
        {

        }
    } // namespace Shape
    
} // namespace SekaiEngine
