#ifndef CITY_MANAGER_H
#define CITY_MANAGER_H

#include<string>

namespace Miestas
{
	namespace Game
	{
		class CityManager
		{
		public:
			using UInt = unsigned int;

			struct CityResources
			{
				UInt m_Wood;
				UInt m_Diamond;
				UInt m_Food;
			};

		private:

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

			void init(const std::string&);

			void saveGameData();
		};
	}
}


#endif