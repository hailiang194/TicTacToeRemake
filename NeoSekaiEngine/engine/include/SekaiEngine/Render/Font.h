#ifndef _SEKAI_ENGINE_RENDER_FONT_H_
#define _SEKAI_ENGINE_RENDER_FONT_H_

#include "SekaiEngine/BaseType.h"

namespace SekaiEngine
{
    namespace Render
    {
        class EXTENDAPI Font
        {
        public:
            Font(const char* id, const char* filename);
            Font(const char* id);
            Font(const Font& font);
            Font& operator=(const Font& font);
            ~Font();

            const char* Id() const;
            const char* Id();

            bool isValid() const;
            bool isValid();
        private:
            const char* m_id;
        };

        void initFonts();
        bool loadFont(const char* id, const char* filename);
        void unloadFonts();

        inline const char* Font::Id() const
        {
            return m_id;
        }

        inline const char* Font::Id()
        {
            return static_cast<const Font&>(*this).Id();
        }

        inline bool Font::isValid()
        {
            return static_cast<const Font&>(*this).isValid();
        }
    } // namespace Render
    
} // namespace SekaiEngine


#endif//!_SEKAI_ENGINE_RENDER_FONT_H_