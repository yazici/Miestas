#include "IndexBuffer.h"

namespace Miestas
{
	namespace Renderer
	{
		IndexBuffer::IndexBuffer(const std::vector<unsigned int>& bufferData): m_bufferData(bufferData)
		{
			glGenBuffers(1, &m_bufferId);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferId);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_bufferData.size() * sizeof(unsigned int), m_bufferData.data(), GL_STATIC_DRAW);
		}

		IndexBuffer::IndexBuffer(const std::vector<unsigned int>&& bufferData) : m_bufferData(std::move(bufferData))
		{
			glGenBuffers(1, &m_bufferId);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferId);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_bufferData.size() * sizeof(unsigned int), m_bufferData.data(), GL_STATIC_DRAW);
		}

		IndexBuffer::~IndexBuffer()
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
			glDeleteBuffers(1, &m_bufferId);
		}

		void IndexBuffer::bind() const
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferId);
		}

		void IndexBuffer::unbind() const
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferId);
		}

		void IndexBuffer::render() const
		{
			glDrawElements(GL_TRIANGLES, m_bufferData.size(), GL_UNSIGNED_INT, 0);
		}

		


	}
}