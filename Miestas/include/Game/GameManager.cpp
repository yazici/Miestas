#include "GameManager.h"
#include "Logger/Logger.h"

#include "json/json.hpp"

#include<fstream>

namespace Miestas
{
	namespace Game
	{
		void GameManager::init(const std::string& configFilePath)
		{
			m_cityManager->init(configFilePath);
		}

		void GameManager::onEvent(std::shared_ptr<Event>)
		{
			// TODO
		}
		void GameManager::setEventQueue(EventQueue * eq)
		{
			m_eventQueue = eq;
		}

		void GameManager::emitEvent(std::shared_ptr<Event> event)
		{
			m_eventQueue->addEventToQueue(event);
		}

		void GameManager::saveGameData()
		{
		}
	}
}