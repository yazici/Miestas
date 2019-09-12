#include "VertexBuffer.h"

namespace Miestas
{
	namespace Renderer
	{
		/*unsigned int AttributeLayout::getTypeSize(GLenum type)
		{
			switch (type)
			{
			case GL_FLOAT:
			case GL_UNSIGNED_INT:
				return 4;
			case GL_UNSIGNED_BYTE:
				return 1;
			default:
				return 4;
			}
		}*/

		VertexBuffer::VertexBuffer(const std::vector<float>& data, const std::vector<AttributeLayout>& la): m_bufferData(data), m_attributeLayout(std::move(la))
		{
			glGenBuffers(1, &m_bufferId);
			glBindBuffer(GL_ARRAY_BUFFER, m_bufferId);
			glBufferData(GL_ARRAY_BUFFER, m_bufferData.size() * sizeof(float), m_bufferData.data(), GL_STATIC_DRAW);
		}

		VertexBuffer::VertexBuffer(const std::vector<float>&& data, const std::vector<AttributeLayout>& la): m_bufferData(std::move(data)), m_attributeLayout(std::move(la))
		{
			glGenBuffers(1, &m_bufferId);
			glBindBuffer(GL_ARRAY_BUFFER, m_bufferId);
			glBufferData(GL_ARRAY_BUFFER, m_bufferData.size() * sizeof(float), m_bufferData.data(), GL_STATIC_DRAW);
		}

		VertexBuffer::~VertexBuffer()
		{
			glBindBuffer(GL_ARRAY_BUFFER,0);
			glDeleteBuffers(1, &m_bufferId);
		}

		void VertexBuffer::bind() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, m_bufferId);
		}

		void VertexBuffer::unbind() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

		unsigned int VertexBuffer::getLayoutStride() const
		{
			unsigned int stride = 0;

			for (const auto& layout : m_attributeLayout)
			{
				stride += layout.m_Size * AttributeLayout::getTypeSize(layout.m_Type);
			}

			return stride;
		}


		const std::vector<AttributeLayout>& VertexBuffer::getAttributeLayout() const
		{
			return m_attributeLayout;
		}

	}
}