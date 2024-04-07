#ifndef _SEKAI_ENGINE_RENDER_COLOR_H_
#define _SEKAI_ENGINE_RENDER_COLOR_H_

#include <stdint.h>
#include "SekaiEngine/BaseType.h"

namespace SekaiEngine
{
    namespace Render
    {
        union ColorParser
        {
            uint32_t code;
            struct parser
            {
                uint8_t a;
                uint8_t b;
                uint8_t g;
                uint8_t r;
            } value;
        };

        class EXTENDAPI Color
        {
        public:
            //Code: RRGGBBAA
            explicit Color(const uint32_t& code = 0x0);
            explicit Color(const Color& color);
            Color& operator=(const Color& color);
            Color& operator=(const uint32_t& code);
            const bool operator==(const Color& color);
            ~Color();

            const uint32_t& code() const;
            const uint32_t& code();

            const uint8_t r() const;
            const uint8_t r();

            const uint8_t g() const;
            const uint8_t g();

            const uint8_t b() const;
            const uint8_t b();

            const uint8_t a() const;
            const uint8_t a(); 
        private:
            uint32_t m_code;
        };

        inline const uint32_t& Color::code() const
        {
            return m_code;
        }

        inline const uint32_t& Color::code()
        {
            return static_cast<const Color&>(*this).code();
        }

        inline const uint8_t Color::r()
        {
            return static_cast<const Color&>(*this).r();
        }

        inline const uint8_t Color::g()
        {
            return static_cast<const Color&>(*this).g();
        }

        inline const uint8_t Color::b()
        {
            return static_cast<const Color&>(*this).b();
        }

        inline const uint8_t Color::a()
        {
            return static_cast<const Color&>(*this).a();
        }
    } // namespace Render
    
} // namespace SekaiEngine


#endif//!_SEKAI_ENGINE_RENDER_COLOR_H_