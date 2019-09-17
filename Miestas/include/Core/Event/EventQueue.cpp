#include "EventQueue.h"
#include "Logger/Logger.h"

namespace Miestas
{
	namespace Core
	{
		void EventQueue::registerObservable(EventType eventType, Observable * observable)
		{
			m_eventMap[eventType].push_back(observable);
			observable->setEventQueue(this);
		}

		void EventQueue::addEventToQueue(Event * event)
		{
			m_eventList.push_back(event);
		}

		void EventQueue::dispatchEvents()
		{
			for (auto& event : m_eventList)
			{
				auto observables = m_eventMap.find(event->m_eventType);

				if (observables == m_eventMap.end())
					continue;

				for (auto& system : observables->second)
				{
					system->onEvent(event);
				}
			}

			m_eventList.clear();

			MIESTAS_LOG_INFO("Succesfully dispatched all events.")
		}


	}
}