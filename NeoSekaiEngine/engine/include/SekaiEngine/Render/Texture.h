#ifndef _SEKAI_ENGINE_RENDER_TEXTURE_H_
#define _SEKAI_ENGINE_RENDER_TEXTURE_H_

#include "SekaiEngine/BaseType.h"

namespace SekaiEngine
{
    namespace Render
    {
        class EXTENDAPI Texture
        {
        public:
            Texture(const char* filename);
            Texture(const Texture& texture);
            Texture& operator=(const Texture& texture);
            ~Texture();

            bool IsValidTexture();

            const int& Id() const;
            const int& Id();

            int Width() const;
            int Width();

            int Height() const;
            int Height();
        private:
            int m_id;
        };

        void initTextures();
        int LoadTextureFromFileAndGetID(const char * filename);
        void destroyTextures();

        inline bool Texture::IsValidTexture()
        {
            return m_id != 0;
        }

        inline const int& Texture::Id() const
        {
            return m_id;
        }

        inline const int& Texture::Id()
        {
            return static_cast<const Texture&>(*this).Id();
        }

        inline int Texture::Width()
        {
            return static_cast<const Texture&>(*this).Width();
        }

        inline int Texture::Height()
        {
            return static_cast<const Texture&>(*this).Height();
        }

    } // namespace Render
    
} // namespace SekaiEngine


#endif//!_SEKAI_ENGINE_RENDER_TEXTURE_H_