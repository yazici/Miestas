#ifndef TERRAIN_GENERATOR_H
#define TERRAIN_GENERATOR_H

#include<vector>
#include<string>

namespace Miestas
{
	namespace Renderer
	{
		class TerrainGenerator
		{
		private:
			int m_randomSeed;
			float m_terrainHeight;
			std::vector<float> m_terrainData;
			bool m_isInitialized = false;

		public:

			TerrainGenerator() = default;

			void init(const std::string& configFilePath);

			void generateTerrain();

			const std::vector<float>& getTerrainData() const;
		};
	}
}

#endif