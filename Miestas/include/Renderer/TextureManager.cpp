#include "TextureManager.h"

#include "Logger/Logger.h"

#include<algorithm>
#include<cctype>

namespace Miestas
{
	namespace Renderer
	{
		void TextureManager::loadTexture(std::string & texturePath, aiTextureType textureType)
		{
			std::transform(texturePath.begin(), texturePath.end(), texturePath.begin(), [](unsigned char ch) { return std::tolower(ch); });

			if (m_textureCache.find(texturePath) != m_textureCache.end())
			{
				MIESTAS_LOG_WARN("TextureManager: The following texture has already been loaded: {0}", texturePath)
				return;
			}

			auto texture = std::make_shared<Texture>(texturePath, textureType);
			m_textureCache.insert({ texturePath, texture });
		}

		std::shared_ptr<Texture> TextureManager::getTexture(std::string & texturePath)
		{
			std::transform(texturePath.begin(), texturePath.end(), texturePath.begin(), [](unsigned char ch) { return std::tolower(ch); });

			auto textureLocation = m_textureCache.find(texturePath);
			if (textureLocation == m_textureCache.end())
			{
				MIESTAS_FAILURE("TextureManager: The requested texture hasn't been loaded yet: {0}", texturePath)
			}

			return textureLocation->second;
		}

	}
}