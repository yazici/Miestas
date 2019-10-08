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

	void Application::init()
	{
		// Read Config from file
		m_Config = std::make_unique<Config>();
		m_Config->init("../Miestas/configs/Config.json");

		// Initialize all the systems
		m_Window = std::make_unique<Window>(m_Config->m_applicationName, m_Config->m_windowWidth, m_Config->m_windowHeight, m_Config->m_isFullScreen);
		m_Renderer = std::make_unique<MiestasRenderer>();
		m_inputHandler = std::make_unique<InputHandler>();
		m_gameManager = std::make_unique<GameManager>();


		// Initialize m_eventQueue at the end after all the systems have been initialized
		// And then register each event with m_eventQueue
		m_appEventQueue = std::make_unique<EventQueue>();


		m_Window->init();
		m_Renderer->init();
		m_inputHandler->init();
		m_gameManager->init(m_Config->m_cityConfig);

		
		// Register None Type Event
		m_appEventQueue->registerObservable(EventType::None, m_Window.get());
		m_appEventQueue->registerObservable(EventType::None, m_Renderer.get());
		m_appEventQueue->registerObservable(EventType::None, m_gameManager.get());

		// Register Key Pressed Events
		m_appEventQueue->registerObservable(EventType::KeyPressedEvent, m_inputHandler.get());
		m_appEventQueue->registerObservable(EventType::KeyReleasedEvent, m_inputHandler.get());
		
		// Register Mouse Pressed Events
		m_appEventQueue->registerObservable(EventType::MouseButtonPressedEvent, m_inputHandler.get());

		// Register Game State Change Event
		m_appEventQueue->registerObservable(EventType::GameStateChangeEvent, m_inputHandler.get());
		m_appEventQueue->registerObservable(EventType::GameStateChangeEvent, m_Renderer.get());

		// Register Window Resize Event
		m_appEventQueue->registerObservable(EventType::WindowResizeEvent, this); // Don't think we really need to send events from Window to Application, but I'll keep it just in case 
		
		// Register Window Close Event
		m_appEventQueue->registerObservable(EventType::WindowCloseEvent, this);
		
		m_gameManager->setGameState(GameState::MainMenu);
	}


	

	void Application::run()
	{
		while (m_isRunning)
		{
			m_appEventQueue->dispatchEvents();
			m_Window->clear(0.5f, 0.6f, 0.8f, 1.0f);
			// m_Renderer->render();
			m_Window->update();
			// Nothing for now
		}
	}

	void Application::close()
	{
	}

	void Application::onEvent(std::shared_ptr<Event> event)
	{
		switch (event->getType())
		{
		case EventType::WindowCloseEvent:
			m_isRunning = false;
			break;

		case EventType::WindowResizeEvent:
			// Do nothing
			break;

		default:
			break;
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
