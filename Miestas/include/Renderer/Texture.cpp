#include "Texture.h"
#include "Logger/Logger.h"

#include "stb_image/stb_image.h"

namespace Miestas
{
	namespace Renderer
	{
		Texture::Texture(const std::string& texturePath, aiTextureType textureType)
		{
			addTexture(texturePath, textureType);
		}

		void Texture::addTexture(const std::string& texturePath, aiTextureType textureType)
		{
			m_textureType = textureType;

			glGenTextures(1, &m_textureId);
			glBindTexture(GL_TEXTURE_2D, m_textureId);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			int width, height, channels;
			unsigned char* textureData = stbi_load(texturePath.c_str(), &width, &height, &channels, 0);

			if (!textureData)
			{
				MIESTAS_FAILURE("Unable to load texture data. File: {0}", texturePath)
			}

			if (channels == 3)
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, textureData);
			else if (channels == 4)
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureData);
			else
				MIESTAS_LOG_ERROR("Texture has unsupported number of channels: File: {0}, Channels: {1}", texturePath, channels)

			glGenerateMipmap(GL_TEXTURE_2D);
			
			MIESTAS_LOG_INFO("Successfully load texture: {0}", texturePath)
			stbi_image_free(textureData);
		}

		Texture::~Texture()
		{
			glBindTexture(GL_TEXTURE_2D, 0);
			glDeleteTextures(1, &m_textureId);
		}

		void Texture::bind(unsigned int textureUnit) const
		{
			glActiveTexture(GL_TEXTURE0 + textureUnit);
			glBindTexture(GL_TEXTURE_2D, m_textureId);
		}

		void Texture::unbind() const
		{
			glBindTexture(GL_TEXTURE_2D, 0);
		}

		aiTextureType Texture::getTextureType() const
		{
			return m_textureType;
		}
	}
}