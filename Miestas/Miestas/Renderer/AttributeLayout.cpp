#include "AttributeLayout.h"

namespace Miestas {
	namespace Renderer
	{
		unsigned int AttributeLayout::getTypeSize(GLenum type)
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
		}
	}
}
