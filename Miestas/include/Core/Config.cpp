#include "Config.h"
#include "Logger/Logger.h"

#include "json/json.hpp"

#include<fstream>

namespace Miestas
{
	namespace Core
	{	
		using json = nlohmann::json;
		void Config::readFromFile(const std::string& filePath)
		{
			std::ifstream configFile(filePath);
			
			if (!configFile)
			{
				MIESTAS_FAILURE("Unable to open Config file: {0}", filePath)
			}

			json root;
			configFile >> root;

			m_majorVersion = root["MAJOR_VERSION"];
			m_minorVersion = root["MINOR_VERSION"];
			m_applicationName = root["APPLICATION_NAME"];

			m_windowWidth = root["WINDOW_WIDTH"];
			m_windowHeight = root["WINDOW_HEIGHT"];
			m_isFullScreen = root["WINDOW_FULLSCREEN"];

			m_modelConfig = root["MODEL_CONFIG"];
			m_shaderConfig = root["SHADER_CONFIG"];
			m_terrainConfig = root["TERRAIN_CONFIG"];
			m_cameraConfig = root["CAMERA_CONFIG"];

			MIESTAS_LOG_INFO("Succesfully loaded Config file: {0} ", filePath)
			MIESTAS_LOG_INFO("Major Version: {0}", m_majorVersion)
			MIESTAS_LOG_INFO("Minor Version: {0}", m_minorVersion)
			MIESTAS_LOG_INFO("Application Name: {0}\n\n", m_applicationName)

			m_readFromFile = true;
		}
	}
}