#include "SekaiEngine/Math/Vector.h"

namespace SekaiEngine
{
    namespace Math
    {

        Vector2D::Vector2D(const float& x, const float& y)
            :CommonVector<2>({x, y})
        {

        }

        Vector2D::Vector2D(const Vector2D& vt)
            :CommonVector<2>(vt)
        {

        }

        Vector2D& Vector2D::operator=(const Vector2D& vt)
        {
            CommonVector<2>::operator=(vt);
            return (*this);
        }

        Vector2D::~Vector2D()
        {

        }

        Vector3D::Vector3D(const float& x, const float& y, const float& z)
            :CommonVector<3>({x, y, z})
        {

        }

        Vector3D::Vector3D(const Vector3D& vt)
            :CommonVector<3>(vt)
        {

        }

        Vector3D& Vector3D::operator=(const Vector3D& vt)
        {
            CommonVector<3>::operator=(vt);
            return (*this);
        }

        Vector3D::~Vector3D()
        {

        }

        Vector4D::Vector4D(const float& x, const float& y, const float& z, const float& t)
            :CommonVector<4>({x, y, z, t})
        {

        }

        Vector4D::Vector4D(const Vector4D& vt)
            :CommonVector<4>(vt)
        {

        }

        Vector4D& Vector4D::operator=(const Vector4D& vt)
        {
            CommonVector<4>::operator=(vt);
            return (*this);
        }

        Vector4D::~Vector4D()
        {

        }
    } // namespace Math
    
} // namespace SekaiEngine
