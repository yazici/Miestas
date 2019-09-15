#ifndef CONFIG_H
#define CONFIG_H

#include<string>

namespace Miestas
{
	namespace Core
	{
		struct Config
		{
			bool m_readFromFile = false;

			// CONFIG DATA
			unsigned int m_majorVersion;
			unsigned int m_minorVersion;
			std::string m_applicationName;
			
			// WINDOW DATA
			unsigned int m_windowWidth;
			unsigned int m_windowHeight;
			bool m_isFullScreen;

			// Reads config data from JSON
			void readFromFile(const std::string& filePath);
		};
	}
}

#endif