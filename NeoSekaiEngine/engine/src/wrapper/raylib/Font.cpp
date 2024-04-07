#include "SekaiEngine/Render/Font.h"

#ifdef USE_RAYLIB
#include "raylib.h"
#include <string>
#include <unordered_map>


namespace SekaiEngine
{
    namespace Render
    {
        std::unordered_map<std::string, ::Font> fonts;

        bool Font::isValid() const
        {
            return fonts.find(std::string(m_id)) != fonts.end();
        }

        void initFonts()
        {
            fonts.clear();
            fonts.insert({std::string("default"), GetFontDefault()});
        }

        bool loadFont(const char* id, const char* filename)
        {
            ::Font font = LoadFont(filename);
            if(!IsFontReady(font))
                return false;

            if(fonts.find(std::string(id)) != fonts.end())
                return false;

            fonts.insert({std::string(id), font});
            return true;
        }

        void unloadFonts()
        {
            for(auto iter = fonts.begin(); iter != fonts.end(); ++iter)
            {
                UnloadFont(iter->second);
            }
            fonts.clear();
        }

        ::Font* getFontById(const char* id)
        {
            if(fonts.find(std::string(id)) == fonts.end())
                return nullptr;

            return &fonts.at(id);
        }
    } // namespace Render
    
} // namespace SekaiEngine


#endif