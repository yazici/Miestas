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

			AttributeLayout(unsigned int ms, GLenum mt, bool isn) :
				m_Size(ms), m_Type(mt), m_isNormalized(isn) {}


			static unsigned int getTypeSize(GLenum type);

		};
	}
}

#endif