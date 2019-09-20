#include "TerrainGenerator.h"
#include "Logger/Logger.h"

#include "Utils/FastNoise.h"

#include "json/json.hpp"

#include<fstream>

namespace Miestas
{
	namespace Renderer
	{
		void TerrainGenerator::init(const std::string& configFilePath)
		{
			using json = nlohmann::json;

			std::ifstream configFile(configFilePath);

			if (!configFile)
			{
				MIESTAS_FAILURE("Unable to open Terrain Config File: {0}", configFilePath)
			}

			json root;
			configFile >> root;

			m_terrainHeight = root["TERRAIN_HEIGHT_AMPLITUDE"];
			bool isRandomTerrain = root["TERRAIN_GEN_RANDOM"];

			if (!isRandomTerrain)
			{
				m_randomSeed = root["TERRAIN_GEN_SEED"];
			}
			else
			{
				// TODO: Random seed generation
			}

			m_isInitialized = true;

			MIESTAS_LOG_INFO("TerrainGenerator: Initialized successfully.")
		}

		void TerrainGenerator::generateTerrain()
		{
			if (!m_isInitialized)
				return;

			// GENERATE TERRAIN

			MIESTAS_LOG_INFO("TerrainGenerator: Terrain generated successfully")
		}

		const std::vector<float>& TerrainGenerator::getTerrainData() const
		{
			return m_terrainData;
		}
	}
}