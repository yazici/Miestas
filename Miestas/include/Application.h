#ifndef APPLICATION_H
#define APPLICATION_H

#include "Renderer/Renderer.h"

#include<memory>

namespace Miestas
{
	using MiestasRenderer = Miestas::Renderer::Renderer;
	using namespace Miestas::Renderer;
	class Application
	{
	private:
		bool m_isRunning = true;
		std::unique_ptr<MiestasRenderer> m_Renderer;

	public:

		void init();
	};
	
}

#endif