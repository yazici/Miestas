#include "InputHandler.h"
#include "Logger/Logger.h"
#include "Core/Event/KeyboardEvents.h"
#include "Core/Event/WindowEvents.h"
#include "Game/Events/StateEvents.h"
#include "Core/KeyBindings.h"

namespace Miestas
{
	namespace Core
	{
		void InputHandler::init()
		{
			return;
		}


		void InputHandler::onEvent(std::shared_ptr<Event> event)
		{
			switch (event->getType())
			{
			case EventType::GameStateChangeEvent:
			{
				auto e = STATIC_PTR_CAST(GameStateChangeEvent, event)
				handleGameStateChangeEvent(e);
				break;
			}

			case EventType::MouseMovedEvent:
				
				MIESTAS_LOG_INFO("Input Handler: Mouse Moved")
				break;
			
			case EventType::MouseButtonPressedEvent:
			{
				auto e = STATIC_PTR_CAST(MouseButtonPressedEvent, event)
				handleMouseButtonPressedEvent(e);
				break;
			}
			case EventType::KeyPressedEvent:
			
				auto e = STATIC_PTR_CAST(KeyPressedEvent, event)
				handleKeyPressedEvent(e);
				break;
			}
		}

		void InputHandler::setEventQueue(EventQueue * eq)
		{
			m_eventQueue = eq;
		}

		void InputHandler::emitEvent(std::shared_ptr<Event> event)
		{
			m_eventQueue->addEventToQueue(std::move(event));
		}

		void InputHandler::handleGameStateChangeEvent(std::shared_ptr<GameStateChangeEvent> event)
		{
			m_gameState = event->m_newGameState;
			MIESTAS_LOG_INFO("InputHandler: Received a GameStateChangeEvent.")
		}

		void InputHandler::handleKeyPressedEvent(std::shared_ptr<KeyPressedEvent> event)
		{
			switch (event->m_keyPressed)
			{
				case MIESTAS_KEY_ESCAPE:
				{
					emitEvent(std::move(std::make_shared<WindowCloseEvent>()));
					break;
				}

				// TODO
			}

		}

		void InputHandler::handleMouseButtonPressedEvent(std::shared_ptr<MouseButtonPressedEvent> event)
		{
			// TODO
		}
	}
}