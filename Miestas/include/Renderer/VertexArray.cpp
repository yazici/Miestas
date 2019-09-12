#include "VertexArray.h"
#include "Logger/Logger.h"

namespace Miestas
{
	namespace Renderer
	{
		VertexArray::VertexArray()
		{
			glGenVertexArrays(1, &m_arrayId);
		}

		VertexArray::~VertexArray()
		{
			glBindVertexArray(0);
			glDeleteVertexArrays(1, &m_arrayId);
		}


		void VertexArray::bindVertexBuffer(std::unique_ptr<VertexBuffer> vb)
		{
			m_vertexBuffer = std::move(vb);
			
			// Bind the vertex array first
			glBindVertexArray(m_arrayId);

			// Bind the vertex buffer
			m_vertexBuffer->bind();

			auto pointerOffset = 0;

			auto stride = m_vertexBuffer->getLayoutStride();

			auto attributeLayout = m_vertexBuffer->getAttributeLayout();

			// Enable attributes
			for (auto i = 0; i < attributeLayout.size(); i++)
			{
				const auto& layout = attributeLayout[i];

				glEnableVertexAttribArray(i);
				glVertexAttribPointer(i, layout.m_Size, layout.m_Type, layout.m_isNormalized ? GL_FALSE : GL_TRUE, stride, (const void*)pointerOffset);

				auto typeSize = AttributeLayout::getTypeSize(layout.m_Type);
				pointerOffset += layout.m_Size * typeSize;
			}

			MIESTAS_LOG_INFO("Succesfully binded the vertex buffer to vertex array.")

		}

		void VertexArray::bindIndexBuffer(std::unique_ptr<IndexBuffer> ib)
		{
			m_indexBuffer = std::move(ib);
			glBindVertexArray(m_arrayId);
			m_indexBuffer->bind();
			glBindVertexArray(0);

			MIESTAS_LOG_INFO("Successfully binded the index buffer to vertex array.")
		}

		void VertexArray::bind() const
		{
			glBindVertexArray(m_arrayId);
		}

		void VertexArray::unbind() const
		{
			glBindVertexArray(0);
		}



		void VertexArray::render() const
		{
			m_indexBuffer->render();
		}


	}
}