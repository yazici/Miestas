#ifndef APPLICATION_H
#define APPLICATION_H

#include "Core/Config.h"
#include "Renderer/Renderer.h" // Renderer to be included before Window, because glad.h needs to be included before GLFW. Could just import glad.h in Window.h but oh well.
#include "Core/Window.h"
#include "Core/Event/Event.h"
#include "Core/Event/EventQueue.h"
#include "Core/Event/Observable.h"
#include "Core/InputHandler.h"
#include "Core/Audio/SoundLibrary.h"
#include "Game/GameManager.h"

#include<memory>

namespace Miestas
{
	using MiestasRenderer = Miestas::Renderer::Renderer; // to resolve ambiguity
	using namespace Miestas::Renderer;
	using namespace Miestas::Core;
	using namespace Miestas::Game;

	class Application: public Observable
	{
	private:
		bool m_isRunning = true;
		EventQueue* m_eventQueue; // the EventQueue this class will use to emit event. Could just emit it to the owning pointer, but want to keep the interface consistent

		std::unique_ptr<Config> m_Config;
		std::unique_ptr<Window> m_Window;
		std::unique_ptr<MiestasRenderer> m_Renderer;
		std::unique_ptr<InputHandler> m_inputHandler;
		std::unique_ptr<GameManager> m_gameManager;
		std::unique_ptr<SoundLibrary> m_soundLibrary;

		std::unique_ptr<EventQueue> m_appEventQueue;

	public:

		~Application();

		void init();

		void run();

		void close();

		virtual void onEvent(std::shared_ptr<Event> event) override;

		virtual void setEventQueue(EventQueue* eq) override;
	private:

		void destroy();

		virtual void emitEvent(std::shared_ptr<Event> event) override;
	};
	
}

#endif