#ifndef KEYBOARD_EVENTS_H
#define KEYBOARD_EVENTS_H

#include "Event.h"

#include "Core/KeyBindings.h"
#include "Logger/Logger.h"

namespace Miestas
{
	namespace Core
	{
		struct KeyPressedEvent : public Event
		{
			REGISTER_EVENT(KeyPressedEvent)
			REGISTER_CATEGORY(ApplicationEvent)

			int m_keyPressed;
			bool m_isRepeated;

			KeyPressedEvent(int keyPressed, bool isRepeated = false) : m_keyPressed(keyPressed), m_isRepeated(isRepeated) { MIESTAS_LOG_INFO("Generated a KeyPressedEvent: {0}", m_keyPressed) }

			GET_TYPE(override)
		};

		struct KeyReleasedEvent : public Event
		{
			REGISTER_EVENT(KeyReleasedEvent)
			REGISTER_CATEGORY(ApplicationEvent)

			int m_keyReleased;

			KeyReleasedEvent(int keyReleased) : m_keyReleased(keyReleased) { MIESTAS_LOG_INFO("Generated a KeyReleasedEvent: {0}", m_keyReleased) }

			GET_TYPE(override)

		};
	}
}
#endif