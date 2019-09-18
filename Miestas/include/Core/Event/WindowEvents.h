#ifndef WINDOW_EVENTS_H
#define WINDOW_EVENTS_H

#include "Event.h"

#include "Logger/Logger.h"

namespace Miestas
{
	namespace Core
	{
		struct WindowResizeEvent : public Event
		{
			REGISTER_EVENT(WindowResizeEvent)
			REGISTER_CATEGORY(ApplicationEvent)

			unsigned int m_newWidth, m_newHeight;

			WindowResizeEvent(unsigned int newWidth, unsigned int newHeight) : m_newWidth(newWidth), m_newHeight(newHeight) { MIESTAS_LOG_INFO("Generated a WindowResizeEvent.") }

			GET_TYPE(override)
		};

		struct WindowCloseEvent : public Event
		{
			REGISTER_EVENT(WindowCloseEvent)
			REGISTER_CATEGORY(ApplicationEvent)

			WindowCloseEvent() { MIESTAS_LOG_INFO("Generated a WindowCloseEvent.") }

			GET_TYPE(override)
		};
	}
}

#endif
