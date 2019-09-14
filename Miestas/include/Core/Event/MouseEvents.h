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

			MouseMovedEvent(float newX, float newY): m_newX(newX), m_newY(newY) { MIESTAS_LOG_INFO("Generated a MouseMovedEvent.") }

		};

		struct MouseScrollEvent : public Event
		{
			REGISTER_EVENT(MouseScrollEvent)
			REGISTER_CATEGORY(ApplicationEvent)

			float m_deltaY;

			MouseScrollEvent(float deltaY) : m_deltaY(deltaY) { MIESTAS_LOG_INFO("Generated a MouseScrollEvent.") }

		};
	}
}

#endif