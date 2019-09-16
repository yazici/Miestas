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

		void Renderer::init()
		{
			m_textureManager = std::make_unique<TextureManager>();
			m_shaderManager = std::make_unique<ShaderManager>();


		}

		void Renderer::beginScene() const
		{

		}

		void Renderer::renderScene() const
		{

		}

		void Renderer::endScene()
		{

		}


	} 
}