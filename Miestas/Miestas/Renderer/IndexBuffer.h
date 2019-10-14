#ifndef INDEX_BUFFER_H
#define INDEX_BUFFER_H

#include "glad/glad.h"

#include<vector>

namespace Miestas
{
	namespace Renderer
	{
		class IndexBuffer
		{
		private:
			GLuint m_bufferId;
			std::vector<unsigned int> m_bufferData;

		public:

			IndexBuffer() {}

			IndexBuffer(const std::vector<unsigned int>& bufferData);

			IndexBuffer(const std::vector<unsigned int>&& bufferData);

			~IndexBuffer();

			void bind() const;

			void unbind() const;

			void render() const;

			unsigned int getNumIndices() const;
		};
	}
}

#endif