#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "Core/Event/Observable.h"
#include "Core/Event/EventQueue.h"
#include "Core/Event/MouseEvents.h"
#include "Core/Event/KeyboardEvents.h"
#include "Game/State/GameState.h"
#include "Game/Events/StateEvents.h"



namespace Miestas
{
	namespace Core
	{
		using namespace Miestas::Game;
		class InputHandler: public Observable
		{
		private:
			EventQueue* m_eventQueue;
			GameState m_gameState = GameState::None;
		
		public:

			void init();

			virtual void onEvent(std::shared_ptr<Event> event) override;

			virtual void setEventQueue(EventQueue* eq) override;

			virtual void emitEvent(std::shared_ptr<Event> event) override;

		private:

			void handleGameStateChangeEvent(std::shared_ptr<GameStateChangeEvent> event);

			void handleKeyPressedEvent(std::shared_ptr<KeyPressedEvent> event);

			void handleMouseButtonPressedEvent(std::shared_ptr<MouseButtonPressedEvent> event);


		};
	}
}


#endif