#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include "glad/glad.h"

#include<memory>

#include "VertexBuffer.h"
#include "IndexBuffer.h"

namespace Miestas
{
	namespace Renderer
	{
		
		class VertexArray
		{
		private:
			GLuint m_arrayId;
			std::unique_ptr<VertexBuffer> m_vertexBuffer;
			std::unique_ptr<IndexBuffer> m_indexBuffer;
		public:

			VertexArray();

			~VertexArray();

			void bindVertexBuffer(std::unique_ptr<VertexBuffer> vb);

			void bindIndexBuffer(std::unique_ptr<IndexBuffer> ib);

			void bind() const;

			void unbind() const;

			void render() const;

			unsigned int getNumIndices() const;

		};
	}
}

#endif