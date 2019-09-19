#ifndef GAME_STATE_H
#define GAME_STATE_H

namespace Miestas
{
	namespace Game
	{
		enum class GameState
		{
			None = 0,
			MainMenu,
			Playing,
			Paused
		};
	}
}

#endif