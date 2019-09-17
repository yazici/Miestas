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
		m_appEventQueue = std::make_unique<EventQueue>();
		
		m_eventQueue->registerObservable(EventType::WindowResizeEvent, this); // Don't think we really need to send events from Window to Application, but I'll keep it just in case 
		m_eventQueue->registerObservable(EventType::WindowCloseEvent, this);
	}

	void Application::run()
	{

	}

	void Application::close()
	{
	}

	void Application::onEvent(Event* event)
	{
		if (event->m_eventType == EventType::WindowCloseEvent)
		{
			m_isRunning = false;
			return;
		}
		else if (event->m_eventType == EventType::WindowResizeEvent)
		{
			// do nothing for now
		}
	}

	void Application::setEventQueue(EventQueue * eq)
	{
		m_eventQueue = eq;
	}

	void Application::emitEvent(Event * event)
	{
		m_eventQueue->addEventToQueue(event);
	}








}
