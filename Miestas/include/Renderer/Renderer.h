#ifndef RENDERER_H
#define RENDERER_H

#include<vector>
#include<memory>

#include "Managers/TextureManager.h"
#include "Managers/ShaderManager.h"

/*
The main Renderer class. The class will contain a reference to camera objects, as well as all model data

Renderer->beginScene() will simply fetch the ProjectionView matrix from the camera class
Renderer->endScene() will update the view matrix of the camera with data coming from the input handler 
*/

namespace Miestas
{
	namespace Renderer
	{
		class Renderer
		{
		private:

			std::unique_ptr<TextureManager> m_textureManager;
			std::unique_ptr<ShaderManager> m_shaderManager;

		public:
			
			void setWireframeMode(bool mode);

			void init();

			void beginScene() const;

			void renderScene() const;

			void endScene();
		};
	}
}


#endif