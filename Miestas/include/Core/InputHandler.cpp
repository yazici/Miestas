#include "InputHandler.h"
#include "Logger/Logger.h"
#include "Core/Event/KeyboardEvents.h"
#include "Core/Event/WindowEvents.h"
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
			case EventType::MouseMovedEvent:
				MIESTAS_LOG_INFO("Input Handler: Mouse Moved")
				break;
			case EventType::MouseButtonPressedEvent:
				MIESTAS_LOG_INFO("Input Handler: Mouse Clicked")
				break;

			case EventType::KeyPressedEvent:
				auto a = STATIC_PTR_CAST(KeyPressedEvent, event)
				MIESTAS_LOG_INFO(a->m_keyPressed)
				if (a->m_keyPressed == MIESTAS_KEY_A)
				{
					emitEvent(std::make_shared<WindowCloseEvent>());
					return;
				}
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
	}
}