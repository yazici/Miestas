#ifndef EVENT_QUEUE_H
#define EVENT_QUEUE_H

#include<vector>
#include<unordered_map>

#include "Core/Event/Observable.h"
#include "Event.h"

namespace Miestas
{
	namespace Core
	{
		class EventQueue
		{
		private:
			std::vector<Event*> m_eventList; // The event list is dispatched at the start of every frame
			std::unordered_map<EventType, std::vector<Observable*>> m_eventMap;

		public:
			void registerObservable(EventType eventType, Observable* observable);

			void addEventToQueue(Event* event);

			void dispatchEvents();


		};
	}
}


#endif