#ifndef MOUSE_EVENTS_H
#define MOUSE_EVENTS_H

#include "Event.h"

namespace Miestas
{
	namespace Core
	{
		struct MouseMovedEvent : public Event
		{
			REGISTER_EVENT(MouseMovedEvent)	
			REGISTER_CATEGORY(ApplicationEvent)

			float m_newX, m_newY;

			MouseMovedEvent(float newX, float newY): m_newX(newX), m_newY(newY) {}

		};

		struct MouseScrollEvent : public Event
		{
			REGISTER_EVENT(MouseScrollEvent)
			REGISTER_CATEGORY(ApplicationEvent)

			float m_deltaY;

			MouseScrollEvent(float deltaY) : m_deltaY(deltaY) {}

		};
	}
}

#endif