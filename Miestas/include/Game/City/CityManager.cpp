#include "CityManager.h"
#include "Logger/Logger.h"

#include "json/json.hpp"

#include<fstream>

namespace Miestas
{
	namespace Game
	{
		void CityManager::init(const std::string& configFilePath)
		{
			using json = nlohmann::json;

			if (m_isInitialized)
				return;

			m_configFilePath = configFilePath;
			std::ifstream configFile(m_configFilePath);

			if (!configFile)
			{
				MIESTAS_FAILURE("Unable to open Game Config File: {0}", configFilePath);
			}

			json root;

			configFile >> root;

			m_cityName = root["CITY_NAME"];
			m_cityMoney = root["CITY_MONEY"];
			m_cityPopulation = root["CITY_POPULATION"];
			m_cityPopulationCapacity = root["CITY_POPULATION_CAPACITY"];
			m_cityHappiness = root["CITY_HAPPINESS"];
			m_cityResources.m_Wood = root["CITY_RESOURCE_WOOD"];
			m_cityResources.m_Diamond = root["CITY_RESOURCE_DIAMOND"];
			m_cityResources.m_Food = root["CITY_RESOURCE_FOOD"];

			m_isInitialized = true;

			MIESTAS_LOG_INFO("Game Manager: Successfully initialized from file {0}", configFilePath);
		}

		void CityManager::saveGameData()
		{

			using json = nlohmann::json;

			if (!m_isInitialized)
				return;

			std::ofstream configFile(m_configFilePath);

			if (!configFile)
			{
				MIESTAS_FAILURE("Unable to open Game Config File: {0}", m_configFilePath)
			}

			json root;

			root["CITY_NAME"] = m_cityName;
			root["CITY_MONEY"] = m_cityMoney;
			root["CITY_POPULATION"] = m_cityPopulation;
			root["CITY_POPULATION_CAPACITY"] = m_cityPopulationCapacity;
			root["CITY_HAPPINESS"] = m_cityHappiness;
			root["CITY_RESOURCE_WOOD"] = m_cityResources.m_Wood;
			root["CITY_RESOURCE_DIAMOND"] = m_cityResources.m_Diamond;
			root["CITY_RESOURCE_FOOD"] = m_cityResources.m_Food;

			configFile << root;

			MIESTAS_LOG_INFO("Game Manager: Successfully wrote game data to config file: {0}", m_configFilePath)
		}
	}
}