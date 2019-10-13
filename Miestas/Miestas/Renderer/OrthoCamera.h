#ifndef ORTHO_CAMERA_H
#define ORTHO_CAMERA_H

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>

namespace Miestas
{
	namespace Renderer
	{
		class OrthoCamera
		{
		private:
			glm::mat4 m_projectionMatrix;
			glm::mat4 m_viewMatrix;
			float m_cameraSpeed;

		public:
			
			OrthoCamera(float a, float b, float c, float d, float cs = 0.5f);

			void setOrthoParameters(float a, float b, float c, float d); 

			void setViewMatrix(const glm::mat4& vm);

			void setViewMatrix(const glm::mat4&& vm);

			void setCameraSpeed(float cs);

			const glm::mat4& getProjection() const;

			const glm::mat4& getView() const;

			glm::mat4 getViewProjection() const;

			// TODO: Movement and recalculating the view matrix
		private:

		};
	}
}

#endif