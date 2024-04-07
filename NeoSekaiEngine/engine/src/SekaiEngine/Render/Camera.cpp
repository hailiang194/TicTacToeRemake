#include "SekaiEngine/Render/Camera.h"

namespace SekaiEngine
{
    namespace Render
    {
        Camera2D::Camera2D(const Math::Vector2D& postion, const Math::Vector2D& offset, const float& zoom, const float& rotation)
            :Position(postion), Offset(offset), Zoom(zoom), Rotation(rotation)
        {

        }

        Camera2D::Camera2D(const Camera2D& camera)
            :Position(camera.Position), Offset(camera.Offset), Zoom(camera.Zoom), Rotation(camera.Rotation)
        {

        }

        Camera2D& Camera2D::operator=(const Camera2D& camera)
        {
            Position = camera.Position;
            Offset = camera.Offset;
            Zoom = camera.Zoom;
            Rotation = camera.Rotation;

            return (*this);
        }

        Camera2D::~Camera2D()
        {

        }
    } // namespace Render
    
} // namespace SekaiEngine
