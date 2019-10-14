#ifndef SCENE_H
#define SCENE_H

#include "SceneObject.h"

#include<vector>

namespace Miestas
{
	namespace Renderer
	{
		class Scene
		{
		private:
			std::vector<std::unique_ptr<SceneObject>> m_sceneObjects;

		public:

			Scene() = default;

			void addSceneObject(std::unique_ptr<SceneObject>&& object);

			const std::vector<std::unique_ptr<SceneObject>>& getSceneObjects() const;
		};
	}
}


#endif