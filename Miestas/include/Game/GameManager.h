#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "Core/Event/Observable.h"
#include "Core/Event/EventQueue.h"

#include<string>
#include<unordered_map>

namespace Miestas
{
	namespace Game
	{
		using namespace Miestas::Core;
		using UInt = unsigned int;

		class GameManager: public Observable
		{
		public:
			
			struct CityResources
			{
				UInt m_Wood;
				UInt m_Diamond;
				UInt m_Food;
			};

		private:
			
			EventQueue* m_eventQueue;
			bool m_isInitialized = false;
			
			std::string m_configFilePath;
			// Game data
			std::string m_cityName;
			UInt m_cityMoney;
			UInt m_cityPopulation;
			UInt m_cityPopulationCapacity;
			UInt m_cityHappiness;
			CityResources m_cityResources;
		
		public:
			void init(const std::string& gameConfigFile);

			virtual void onEvent(std::shared_ptr<Event>) override;

			virtual void setEventQueue(EventQueue* eq) override;

			virtual void emitEvent(std::shared_ptr<Event>) override;

		private:

			void saveGameData();
		};
	}
}

#endif