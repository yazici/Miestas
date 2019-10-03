#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "Core/Event/Observable.h"
#include "Core/Event/EventQueue.h"
#include "City/CityManager.h"

#include<string>
#include<memory>

namespace Miestas
{
	namespace Game
	{
		using namespace Miestas::Core;
		
		class GameManager: public Observable
		{
		
		private:
			
			EventQueue* m_eventQueue;
			bool m_isInitialized = false;

			std::unique_ptr<CityManager> m_cityManager;
		
		public:
			void init(const std::string& cityConfigFile);

			virtual void onEvent(std::shared_ptr<Event>) override;

			virtual void setEventQueue(EventQueue* eq) override;

			virtual void emitEvent(std::shared_ptr<Event>) override;

		private:

			void saveGameData();
		};
	}
}

#endif