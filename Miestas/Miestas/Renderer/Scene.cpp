#include "Scene.h"

namespace Miestas
{
	namespace Renderer
	{

		void Scene::addSceneObject(std::unique_ptr<SceneObject>&& object)
		{
			m_sceneObjects.push_back(std::move(object));
		}

		const std::vector<std::unique_ptr<SceneObject>>& Scene::getSceneObjects() const
		{
			return m_sceneObjects;
		}

	}
}