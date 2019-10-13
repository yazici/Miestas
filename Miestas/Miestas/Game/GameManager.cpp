#include "GameManager.h"
#include "Logger/Logger.h"
#include "Game/Events/StateEvents.h"

#include "json/json.hpp"

#include<fstream>

namespace Miestas
{
	namespace Game
	{
		void GameManager::init(const std::string& configFilePath)
		{
			m_cityManager = std::make_unique<CityManager>();
			m_stateManager = std::make_unique<StateManager>(GameState::MainMenu);

			//m_cityManager->init(configFilePath);


			m_isInitialized = true;
			MIESTAS_LOG_INFO("GameManager: Successfully initialized.")
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
			// TODO
		}

		GameState GameManager::getGameState() const
		{
			return m_stateManager->m_currentState;
		}

		void GameManager::setGameState(GameState gameState)
		{
			m_stateManager->m_currentState = gameState;
			emitEvent(std::move(std::make_shared<GameStateChangeEvent>(gameState)));
		}


	}
}