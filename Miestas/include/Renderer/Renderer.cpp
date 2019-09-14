#include "Renderer.h"

#include "glad/glad.h"

namespace Miestas
{
	namespace Renderer
	{
		void Renderer::setWireframeMode(bool mode)
		{
			if (mode)
			{
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			}
			else
			{
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			}

		}
	} 
}