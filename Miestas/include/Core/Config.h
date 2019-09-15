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
			std::string m_modelFileInfo; // Path to JSON file containing all model info to be loaded
			std::string m_shaderFileInfo; // Path to JSON file containing all shader info to be loaded


			// Reads config data from JSON
			void readFromFile(const std::string& filePath);
		};
	}
}

#endif