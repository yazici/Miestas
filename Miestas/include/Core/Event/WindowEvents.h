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

			WindowResizeEvent(unsigned int newWidth, unsigned int newHeight) : m_newWidth(newWidth), m_newHeight(newHeight) {  }

			GET_TYPE(override)
			GET_CATEGORY(override)
		};

		struct WindowCloseEvent : public Event
		{
			REGISTER_EVENT(WindowCloseEvent)
			REGISTER_CATEGORY(ApplicationEvent)

			WindowCloseEvent() {  }

			GET_TYPE(override)
			GET_CATEGORY(override)
		};
	}
}

#endif
