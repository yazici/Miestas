#include "TerrainGenerator.h"
#include "Logger/Logger.h"

#include "Utils/FastNoise.h"

#include "json/json.hpp"

#include<fstream>
#include<random>

constexpr int RANDOM_MIN = 1;
constexpr int RANDOM_MAX = 10000000;

namespace Miestas
{
	namespace Renderer
	{
		void TerrainGenerator::init(const std::string& configFilePath)
		{
			using json = nlohmann::json;

			std::fstream configFile(configFilePath);

			if (!configFile)
			{
				MIESTAS_FAILURE("Unable to open Terrain Config File: {0}", configFilePath)
			}

			json root;
			configFile >> root;

			m_terrainHeight = root["TERRAIN_HEIGHT_AMPLITUDE"];
			m_terrainGridLength = root["TERRAIN_LENGTH"];
			m_terrainGridWidth = root["TERRAIN_WIDTH"];

			m_terrainScaleFactor = root["TERRAIN_SCALE_FACTOR"];

			bool isRandomTerrain = root["TERRAIN_GEN_RANDOM"];


			if (!isRandomTerrain)
			{
				m_randomSeed = root["TERRAIN_GEN_SEED"];
			}
			else
			{
				std::random_device device;
				std::mt19937 randomgen(device());

				std::uniform_int_distribution<std::mt19937::result_type> dist(RANDOM_MIN, RANDOM_MAX);

				m_randomSeed = dist(randomgen);

				root["TERRAIN_GEN_RANDOM"] = false;
				root["TERRAIN_GEN_SEED"] = m_randomSeed;

				configFile << root;
			}

			m_isInitialized = true;

			MIESTAS_LOG_INFO("TerrainGenerator: Initialized successfully.")
		}

		void TerrainGenerator::generateTerrain()
		{
			if (!m_isInitialized)
				return;

			FastNoise noiseGenerator;
			noiseGenerator.SetNoiseType(FastNoise::PerlinFractal);

			


			// GENERATE TERRAIN

			MIESTAS_LOG_INFO("TerrainGenerator: Terrain generated successfully")
		}

		const std::vector<float>& TerrainGenerator::getTerrainData() const
		{
			return m_terrainData;
		}
	}
}