#ifndef APPLICATION_H
#define APPLICATION_H

#include "Core/Config.h"
#include "Renderer/Renderer.h" // Renderer to be included before Window, because glad.h needs to be included before GLFW. Could just import glad.h in Window.h but oh well.
#include "Core/Window.h"
#include "Core/Event/EventQueue.h"

#include<memory>

namespace Miestas
{
	using MiestasRenderer = Miestas::Renderer::Renderer; // to resolve ambiguity
	using namespace Miestas::Renderer;
	using namespace Miestas::Core;

	class Application
	{
	private:
		bool m_isRunning = true;

		std::unique_ptr<Config> m_Config;
		std::unique_ptr<Window> m_Window;
		std::unique_ptr<MiestasRenderer> m_Renderer;
		std::unique_ptr<EventQueue> m_eventQueue;

	public:

		void init();

		void run();

		void close();
	};
	
}

#endif