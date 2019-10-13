#ifndef CITY_MANAGER_H
#define CITY_MANAGER_H

#include "Game/Resource/Resource.h"

#include<string>

namespace Miestas
{
	namespace Game
	{
		class CityManager
		{
		public:
			using UInt = unsigned int;

			

		private:

			bool m_isInitialized = false;

			std::string m_configFilePath;
			// Game data
			std::string m_cityName;
			UInt m_cityPopulation;
			UInt m_cityPopulationCapacity;
			UInt m_cityHappiness;
			Resource m_cityResources;

		public:

			void init(const std::string&);

			void saveGameData();
		};
	}
}


#endif