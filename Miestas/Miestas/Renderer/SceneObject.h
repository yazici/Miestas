#ifndef SCENE_OBJECT_H
#define SCENE_OJBECT_H

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "AttributeLayout.h"

#include<memory>
#include<string>

namespace Miestas
{
	namespace Renderer
	{
		struct SceneObject
		{
			std::unique_ptr<VertexArray> m_vertexArray;
			std::string m_textureName;
			std::string m_shaderName;

			unsigned int m_Instances;

			~SceneObject() = default;

			SceneObject() = default;

			SceneObject(std::unique_ptr<VertexArray>&& vertexArray, const std::string& textureName, 
				const std::string& shaderName, unsigned int numInstances) :
				m_vertexArray(std::move(vertexArray)), m_textureName(std::move(textureName)),
				m_shaderName(std::move(shaderName)),
				m_Instances(numInstances)
			{}
		};
	}
}

#endif