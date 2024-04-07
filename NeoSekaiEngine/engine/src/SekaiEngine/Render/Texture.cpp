#include "SekaiEngine/Render/Texture.h"

namespace SekaiEngine
{
    namespace Render
    {
        Texture::Texture(const char* filename)
            :m_id(LoadTextureFromFileAndGetID(filename))
        {

        }

        Texture::Texture(const Texture& texture)
            :m_id(texture.m_id)
        {

        }

        Texture& Texture::operator=(const Texture& texture)
        {
            m_id = texture.m_id;
            return (*this);
        }

        Texture::~Texture()
        {

        }
    } // namespace Render
    
} // namespace SekaiEngine
