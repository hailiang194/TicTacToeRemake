#include "SekaiEngine/Render/Color.h"

namespace SekaiEngine
{
    namespace Render
    {
        

        Color::Color(const uint32_t& code)
            :m_code(code)
        {

        }

        Color::Color(const Color& color)
            :m_code(color.m_code)
        {

        }

        Color& Color::operator=(const Color& color)
        {
            m_code = color.m_code;
            return (*this);
        }

        Color& Color::operator=(const uint32_t& code)
        {
            m_code = code;
            return (*this);
        }

        const bool Color::operator==(const Color& color)
        {
            return m_code == color.m_code;
        }

        Color::~Color()
        {

        }

        const uint8_t Color::r() const
        {
            ColorParser parser;
            parser.code = m_code;
            return parser.value.r;
        }

        const uint8_t Color::g() const
        {
            ColorParser parser;
            parser.code = m_code;
            return parser.value.g;
        }

        const uint8_t Color::b() const
        {
            ColorParser parser;
            parser.code = m_code;
            return parser.value.b;
        }

        const uint8_t Color::a() const
        {
            ColorParser parser;
            parser.code = m_code;
            return parser.value.a;
        }
    } // namespace Render
    
} // namespace SekaiEngine
