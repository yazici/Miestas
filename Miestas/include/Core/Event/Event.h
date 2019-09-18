#ifndef EVENT_H
#define EVENT_H

#define REGISTER_EVENT(e) EventType m_eventType = EventType::##e;
#define REGISTER_CATEGORY(e) EventCategory m_eventCategory = EventCategory::##e;
#define GET_TYPE(x) virtual EventType getType() const x { return m_eventType; }

namespace Miestas
{
	namespace Core
	{
		enum class EventCategory
		{
			None = 0,
			GameEvent,
			ApplicationEvent
		};


		enum class EventType
		{
			None = 0,

			// Application Events
			WindowResizeEvent, WindowCloseEvent,
			KeyPressedEvent, KeyReleasedEvent,
			MouseMovedEvent, MouseScrollEvent, MouseButtonPressedEvent, MouseButtonReleasedEvent

			
		};

		
		struct Event
		{
			REGISTER_EVENT(None)
			REGISTER_CATEGORY(None)
			GET_TYPE()
		};


	}
}

#endif