#ifndef CUBE_MAP_H
#define CUBE_MAP_H

#include "glad/glad.h"

#include<string>
#include<vector>

namespace Miestas
{
	namespace Renderer
	{
		class CubeMap
		{
		private:
			GLuint m_textureId;

		public:

			CubeMap() = default;

			CubeMap(const std::vector<std::string>& texturePath);

			~CubeMap();

			void bind(unsigned int textureUnit = 0) const;

			void unbind() const;
		};
	}
}

#endif