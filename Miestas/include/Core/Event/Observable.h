#ifndef OBSERVABLE_H
#define OBSERVABLE_H

/*
*  Observable is a pure virtual class, and any system that needs to take part in message passing needs to inherit from it.
*  Observable defines three methods:
*		- onEvent(Event*) which updates the system state based on the event received
*		- emitEvent(Event*) which adds the event to the event queue to be sent at the next frame.
*		- setEventQueue(std::shared_ptr<EventQueue> eq): This methods is used to by the EventQueue to attach itself to the Observable class, 
		  at the moment the Observable class registers itself to the EventQueue.
*/

#include "Event.h"

#include<memory>

namespace Miestas
{
	namespace Core
	{
		class EventQueue;

		class Observable
		{
		private:
			std::shared_ptr<EventQueue> m_eventQueue;

		public:

			virtual void onEvent(Event*) = 0;

			virtual void setEventQueue(EventQueue* eq) = 0;

			virtual void emitEvent(Event*) = 0;
		};
	}
}


#endif