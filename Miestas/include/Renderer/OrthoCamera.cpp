#include "OrthoCamera.h"
#include "Logger/Logger.h"

namespace Miestas
{
	namespace Renderer
	{
		OrthoCamera::OrthoCamera(float left, float right, float bottom, float top, float cs): m_cameraSpeed(cs),
			m_viewMatrix(glm::mat4(1.0f))
		{
			setOrthoParameters(left, right, bottom, top);
		}

		void OrthoCamera::setOrthoParameters(float left, float right, float bottom, float top)
		{
			m_projectionMatrix = glm::ortho(left, right, bottom, top);
		}

		void OrthoCamera::setViewMatrix(const glm::mat4& vm)
		{
			m_viewMatrix = vm;
		}

		void OrthoCamera::setViewMatrix(const glm::mat4 && vm)
		{
			m_viewMatrix = std::move(vm);
		}

		void OrthoCamera::setCameraSpeed(float cs)
		{
			m_cameraSpeed = cs;
		}

		const glm::mat4& OrthoCamera::getProjection() const
		{
			return m_projectionMatrix;
		}

		const glm::mat4 & OrthoCamera::getView() const
		{
			return m_viewMatrix;
		}

		glm::mat4 OrthoCamera::getViewProjection() const
		{
			return m_projectionMatrix * m_viewMatrix;
		}






	}
}