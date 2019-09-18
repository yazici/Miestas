#include "InputHandler.h"
#include "Logger/Logger.h"
#include "Core/Event/KeyboardEvents.h"
#include "Core/KeyBindings.h"

namespace Miestas
{
	namespace Core
	{
		void InputHandler::init()
		{

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