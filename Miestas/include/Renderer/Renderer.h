#ifndef RENDERER_H
#define RENDERER_H

#include<vector>

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

		public:
			
			void setWireframeMode(bool mode);

			void initializeRenderer();

			void beginScene() const;

			void renderScene() const;

			void endScene();
		};
	}
}


#endif