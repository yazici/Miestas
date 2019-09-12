#ifndef ATTRIBUTE_LAYOUT_H
#define ATTRIBUTE_LAYOUT_H

#include "glad/glad.h"

namespace Miestas
{
	namespace Renderer
	{
		struct AttributeLayout
		{
			unsigned int m_Size;
			GLenum m_Type;
			bool m_isNormalized;

			static unsigned int getTypeSize(GLenum type);

		};
	}
}

#endif