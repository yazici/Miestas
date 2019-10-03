#include "Application.h"
#include "Logger/Logger.h"


#include "Core/Event/KeyboardEvents.h"

namespace Miestas
{
	using namespace Miestas::Renderer;

	Application::~Application()
	{
		this->destroy();
	}

	/*The following systems need to be initialized 
		- Window
		- Renderer
		- Input Handler
		- Event Queue

	*/    
	void Application::init()
	{
		// Read Config from file
		m_Config = std::make_unique<Config>();
		m_Config->init("../Miestas/configs/Config.json");

		// Initialize all the systems
		m_Window = std::make_unique<Window>(m_Config->m_applicationName, m_Config->m_windowWidth, m_Config->m_windowHeight, m_Config->m_isFullScreen);
		m_Renderer = std::make_unique<MiestasRenderer>();
		m_inputHandler = std::make_unique<InputHandler>();


		// Initialize m_eventQueue at the end after all the systems have been initialized
		// And then register each event with m_eventQueue
		m_appEventQueue = std::make_unique<EventQueue>();


		m_Window->init();
		m_Renderer->init();
		m_inputHandler->init();

		// EventType::None for now

		m_appEventQueue->registerObservable(EventType::None, m_Window.get());

		m_appEventQueue->registerObservable(EventType::None, m_Renderer.get());

		m_appEventQueue->registerObservable(EventType::KeyPressedEvent, m_inputHandler.get());
		m_appEventQueue->registerObservable(EventType::KeyReleasedEvent, m_inputHandler.get());
		//m_appEventQueue->registerObservable(EventType::MouseMovedEvent, m_inputHandler.get());
		m_appEventQueue->registerObservable(EventType::MouseButtonPressedEvent, m_inputHandler.get());



		m_appEventQueue->registerObservable(EventType::WindowResizeEvent, this); // Don't think we really need to send events from Window to Application, but I'll keep it just in case 
		m_appEventQueue->registerObservable(EventType::WindowCloseEvent, this);


	}


	

	void Application::run()
	{
		while (m_isRunning)
		{
			m_appEventQueue->dispatchEvents();
			m_Window->clearWindow(0.5f, 0.6f, 0.8f, 1.0f);
			m_Window->updateWindow();
			// Nothing for now
		}
	}

	void Application::close()
	{
	}

	void Application::onEvent(std::shared_ptr<Event> event)
	{
		if (event->getType() == EventType::WindowCloseEvent)
		{
			MIESTAS_LOG_INFO("Received a CloseEvent.")
			m_isRunning = false;
			//return;
		}
		else if (event->getType() == EventType::WindowResizeEvent)
		{
			// do nothing for now
		}
	}

	void Application::setEventQueue(EventQueue * eq)
	{
		m_eventQueue = eq;
	}

	void Application::destroy()
	{
		// TODO: Make sure we destroy in reverse order
	}

	void Application::emitEvent(std::shared_ptr<Event> event)
	{
		m_eventQueue->addEventToQueue(event);
	}








}
