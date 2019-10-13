#ifndef LIGHT_H
#define LIGHT_H

#include "glm/vec3.hpp"

namespace Miestas
{
	namespace Renderer
	{
		enum class LightType
		{
			DirectionalLight = 0,
			PointLight,
			SpotLight
		};

		struct Light
		{
			LightType m_Type;


			glm::vec3 m_Position;
			glm::vec3 m_Color;

			float m_ambientFactor;
			float m_diffusionFactor;
			float m_specularFactor;
			

		};
	}
}

#endif