#include "TextureManager.h"

#include "Logger/Logger.h"

#include<algorithm>
#include<cctype>

#define STRING_TO_LOWER(x) std::transform(x.##begin(), x.##end(), x.##begin(), [](unsigned char ch){ return std::tolower(ch); });
namespace Miestas
{
	namespace Renderer
	{
		void TextureManager::loadTexture(const std::string & texturePath, aiTextureType textureType)
		{
			//std::transform(texturePath.begin(), texturePath.end(), texturePath.begin(), [](unsigned char ch) { return std::tolower(ch); });
			STRING_TO_LOWER(const_cast<std::string&>(texturePath))

			if (m_textureCache.find(texturePath) != m_textureCache.end())
			{
				MIESTAS_LOG_WARN("TextureManager: The following texture has already been loaded: {0}", texturePath)
				return;
			}

			auto texture = std::make_shared<Texture>(texturePath, textureType);
			m_textureCache.insert({ texturePath, texture });
		}

		std::shared_ptr<Texture> TextureManager::getTexture(const std::string & texturePath)
		{
			//std::transform(texturePath.begin(), texturePath.end(), texturePath.begin(), [](unsigned char ch) { return std::tolower(ch); });
			STRING_TO_LOWER(const_cast<std::string&>(texturePath))
			
			auto textureLocation = m_textureCache.find(texturePath);
			if (textureLocation == m_textureCache.end())
			{
				MIESTAS_FAILURE("TextureManager: The requested texture hasn't been loaded yet: {0}", texturePath)
			}

			return textureLocation->second;
		}

	}
}