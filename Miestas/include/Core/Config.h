#ifndef CONFIG_H
#define CONFIG_H

#include<string>

namespace Miestas
{
	namespace Core
	{
		struct Config
		{
			bool m_readFromFile = false; // do we really need this? Keeping it in just in case.

			// CONFIG DATA
			unsigned int m_majorVersion;
			unsigned int m_minorVersion;
			std::string m_applicationName;
			
			// WINDOW DATA
			unsigned int m_windowWidth;
			unsigned int m_windowHeight;
			bool m_isFullScreen;

			// FILE_INFO
			std::string m_modelConfig; // Path to JSON file containing all model info to be loaded
			std::string m_shaderConfig; // Path to JSON file containing all shader info to be loaded
			std::string m_terrainConfig; // Path to JSON file containing procedural terrain info
			std::string m_cameraConfig; // Path to JSON file containing camera info
			std::string m_cityConfig;


			// Reads config data from JSON
			void init(const std::string& filePath = "C:\\Users\\rdpsi\\Desktop\\Miestas\\Miestas\\configs\\Config.json");
		};
	}
}

#endif