#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include "glad/glad.h"

#include <vector>

#include "AttributeLayout.h"

namespace Miestas
{
	namespace Renderer
	{
		
		class VertexBuffer
		{
		private:
			GLuint m_bufferId;
			std::vector<float> m_bufferData;
			std::vector<AttributeLayout> m_attributeLayout;

		public:

			VertexBuffer() {}

			VertexBuffer(const std::vector<float>& data, const std::vector<AttributeLayout>& la);

			VertexBuffer(const std::vector<float>&& data, const std::vector<AttributeLayout>& la);

			~VertexBuffer();

			void bind() const;

			void unbind() const;

			unsigned int getLayoutStride() const;

			const std::vector<AttributeLayout>& getAttributeLayout() const;
			
			//void render() const; //Do we really need this?
		};
	}
}


#endif