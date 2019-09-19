#ifndef MOUSE_EVENTS_H
#define MOUSE_EVENTS_H

#include "Event.h"

#include "Logger/Logger.h"

namespace Miestas
{
	namespace Core
	{
		struct MouseMovedEvent : public Event
		{
			REGISTER_EVENT(MouseMovedEvent)	
			REGISTER_CATEGORY(ApplicationEvent)

			float m_newX, m_newY;

			MouseMovedEvent(float newX, float newY): m_newX(newX), m_newY(newY) {  }

			GET_TYPE(override)
			GET_CATEGORY(override)

		};

		struct MouseScrollEvent : public Event
		{
			REGISTER_EVENT(MouseScrollEvent)
			REGISTER_CATEGORY(ApplicationEvent)

			float m_deltaX, m_deltaY;

			MouseScrollEvent(float deltaX, float deltaY) : m_deltaX(deltaX), m_deltaY(deltaY) {  }

			GET_TYPE(override)
			GET_CATEGORY(override)

		};

		struct MouseButtonPressedEvent : public Event
		{
			REGISTER_EVENT(MouseButtonPressedEvent)
			REGISTER_CATEGORY(ApplicationEvent)

			int m_buttonPressed;

			MouseButtonPressedEvent(int buttonPressed): m_buttonPressed(buttonPressed) {  }

			GET_TYPE(override)
			GET_CATEGORY(override)

		};

		struct MouseButtonReleasedEvent : public Event
		{
			REGISTER_EVENT(MouseButtonReleasedEvent)
			REGISTER_CATEGORY(ApplicationEvent)

			int m_buttonReleased;

			MouseButtonReleasedEvent(int buttonReleased): m_buttonReleased(buttonReleased) {  }

			GET_TYPE(override)
			GET_CATEGORY(override)
		};
	}
}

#endif