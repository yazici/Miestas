#include "Application.h"

namespace Miestas
{
	using namespace Miestas::Renderer;

	void Application::init()
	{
		// Read Config from file
		m_Config = std::make_unique<Config>();
		m_Config->readFromFile("C:\\Users\\rdpsi\\Desktop\\Miestas\\Miestas\\include\\Core\\Config.json");

		// Initialize the window
		m_Window = std::make_unique<Window>(m_Config->m_applicationName, m_Config->m_windowWidth, m_Config->m_windowHeight);

		m_Renderer = std::make_unique<MiestasRenderer>();
		

		// Initialize m_eventQueue at the end after all the systems have been initialized
		// And then register each event with m_eventQueue
		m_eventQueue = std::make_unique<EventQueue>();
		
	}

	void Application::run()
	{

	}

	void Application::close()
	{
	}

}
