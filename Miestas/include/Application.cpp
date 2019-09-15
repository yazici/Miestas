#include "Application.h"

namespace Miestas
{
	using namespace Miestas::Renderer;

	void Application::init()
	{
		m_Renderer = std::make_unique<MiestasRenderer>();
	}

}
