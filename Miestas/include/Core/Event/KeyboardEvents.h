#ifndef KEYBOARD_EVENTS_H
#define KEYBOARD_EVENTS_H

#include "Event.h"

namespace Miestas
{
	namespace Core
	{
		struct KeyPressedEvent : public Event
		{
			REGISTER_EVENT(KeyPressedEvent)
			REGISTER_CATEGORY(ApplicationEvent)
		};

		struct KeyReleasedEvent : public Event
		{
			REGISTER_EVENT(KeyReleasedEvent)
			REGISTER_CATEGORY(ApplicationEvent)
		};
	}
}
#endif