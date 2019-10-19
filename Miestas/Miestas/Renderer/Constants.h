#ifndef RENDERER_CONSTANTS_H
#define RENDERER_CONSTANTS_H

#include "AttributeLayout.h"

#include<vector>

namespace Miestas
{
	namespace Renderer
	{
		static const std::vector<float> fullScreenVerticesWithTexture = {
			1.0f, 1.0f, 0.0f, 1.0f, 1.0f,
			1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
			-1.0f, -1.0f, 0.0f,0.0f, 0.0f,
			-1.0f, 1.0f, 0.0f, 0.0f, 1.0f
		};

		static const std::vector<unsigned int> fullScreenIndices = {
			0, 1, 3,   // first triangle
			1, 2, 3    // second triangle
		};

		static const std::vector<AttributeLayout> layoutFullScreenWithTextures = {
			{3, GL_FLOAT, false},
			{2, GL_FLOAT, false}
		};



	}
}


#endif