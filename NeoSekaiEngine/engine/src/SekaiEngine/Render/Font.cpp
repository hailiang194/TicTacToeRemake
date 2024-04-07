#include "SekaiEngine/Render/Font.h"

namespace SekaiEngine
{
    namespace Render
    {
        Font::Font(const char* id, const char* filename)
            :m_id(id)
        {
            loadFont(id, filename);
        }

        Font::Font(const char* id)
            :m_id(id)
        {

        }

        Font::Font(const Font& font)
            :m_id(font.m_id)
        {

        }

        Font& Font::operator=(const Font& font)
        {
            m_id = font.m_id;
            return (*this);
        }

        Font::~Font()
        {

        }
    } // namespace Render
    
} // namespace SekaiEngine
