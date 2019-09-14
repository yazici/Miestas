#ifndef TEXTURE_H
#define TEXTURE_H

#include "glad/glad.h"

#include "assimp/scene.h"

namespace Miestas
{
	namespace Renderer
	{
		class Texture
		{
		private:
			GLuint m_textureId;
			aiTextureType m_textureType;

		public:

			Texture() { /* Nothing */ }

			Texture(const std::string& texturePath, aiTextureType textureType);

			~Texture();

			void addTexture(const std::string& texturePath, aiTextureType textureType);

			void bind(unsigned int textureUnit = 0) const;

			void unbind() const;

			aiTextureType getTextureType() const;

		};
	}
}

#endif