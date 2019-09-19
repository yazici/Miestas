#include "EventQueue.h"
#include "Logger/Logger.h"

#include<iostream>
namespace Miestas
{
	namespace Core
	{
		void EventQueue::registerObservable(EventType eventType, Observable * observable)
		{
			m_eventMap[eventType].push_back(observable);
			observable->setEventQueue(this);
		}

		void EventQueue::addEventToQueue(std::shared_ptr<Event> event)
		{
			m_eventList.push_back(event);
		}

		void EventQueue::dispatchEvents()
		{
			if (m_eventList.size() == 0)
				return;

			for (auto& event : m_eventList)
			{
				auto type = event->getType();
				auto observables = m_eventMap.find(type);

				if (observables == m_eventMap.end())
					continue;

				for (auto system : observables->second)
				{
					system->onEvent(event);
				}

			}

			m_eventList.clear();

		}


	}
}