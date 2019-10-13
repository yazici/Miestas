#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include "GameState.h"

namespace Miestas
{
	namespace Game
	{
		/*
		* The StateManager is only to keep track of the current state of the game
		* Probably overkill, might rethink this later
		*/

		struct StateManager
		{
		
			GameState m_currentState = GameState::None;

			StateManager() = default;

			StateManager(GameState gameState) : m_currentState(gameState)
			{}

		};
	}
}

#endif