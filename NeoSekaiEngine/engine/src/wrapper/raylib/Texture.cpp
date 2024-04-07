#include "SekaiEngine/Render/Texture.h"
#include "wrapper/raylib/Texture.h"

#ifdef USE_RAYLIB
#include "raylib.h"
#include <unordered_map>
#include <stdexcept>

namespace SekaiEngine
{
    namespace Render
    {
            int Texture::Width() const
            {
                ::Texture* texture = getTexture(m_id);
                return texture != nullptr ? texture->width : 0;
            }
            

            int Texture::Height() const
            {
                ::Texture* texture = getTexture(m_id);
                return texture != nullptr ? texture->height : 0;
            }

        std::unordered_map<int,::Texture> textures;
        void initTextures()
        {
            textures.clear();
        }

        int LoadTextureFromFileAndGetID(const char * filename)
        {
            ::Texture texture = LoadTexture(filename);
            if(texture.id == 0)
                return texture.id;

            textures.insert({texture.id, texture});
            return texture.id;
        }


        ::Texture* getTexture(const int& id)
        {
            try
            {
                return &textures.at(id);
            }catch(const std::out_of_range& e)
            {
                return nullptr;
            }
        }

        void destroyTextures()
        {
            for(auto iter = textures.begin(); iter != textures.end(); ++iter)
            {
                UnloadTexture(iter->second);
            }
            textures.clear();
        }
    } // namespace Render
    
} // namespace SekaiEngine


#endif