#include "CubeMap.h"
#include "Logger/Logger.h"

#include "Renderer/stb_image/stb_image.h"

namespace Miestas
{
	namespace Renderer
	{
		CubeMap::CubeMap(const std::vector<std::string>& texturePath)
		{
			glGenTextures(1, &m_textureId);

			for (auto i = 0; i < texturePath.size(); i++)
			{
				int width, height, channels;
				unsigned char* textureData = stbi_load(texturePath[i].c_str(), &width, &height, &channels, 0);

				if (!textureData)
				{
					MIESTAS_FAILURE("Unable to load texture: {0}", texturePath[i])
				}

				if (channels == 3)
					glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGBA8, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, textureData);
				else if (channels == 4)
					glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureData);
				else
					MIESTAS_LOG_ERROR("Texture has unsupported number of channels. File: {0}, Channels: {1}", texturePath[i], channels)
			}

			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

			MIESTAS_LOG_INFO("Successfully create CubeMap.")
		}

		CubeMap::~CubeMap()
		{
			glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
			glDeleteTextures(1, &m_textureId);
		}

		void CubeMap::bind(unsigned int textureUnit) const
		{
			glActiveTexture(GL_TEXTURE0 + textureUnit);
			glBindTexture(GL_TEXTURE_CUBE_MAP, m_textureId);
		}

		void CubeMap::unbind() const
		{
			glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
		}
	}
}