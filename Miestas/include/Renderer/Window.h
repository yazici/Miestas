#ifndef WINDOW_H
#define WINDOW_H

#include<string>


#include "GLFW/glfw3.h"


namespace Miestas
{
	namespace Renderer
	{
		class Window
		{
		private:
			std::string m_windowTitle;
			unsigned int m_Width;
			unsigned int m_Height;
			bool m_vSyncEnabled;
			GLFWwindow* m_Window;

		public:

			Window() : m_windowTitle("Miestas Debug"), m_Width(800), m_Height(600), m_Window(nullptr), m_vSyncEnabled(false) {}

			Window(const std::string& wt, unsigned int mw = 800, unsigned int mh = 600):
				m_windowTitle(wt), m_Width(mw), m_Height(mh), m_vSyncEnabled(false) {}

			~Window();

			void enableVSync();

			void disableVSync();

			void initWindow();

			void clearWindow(float r, float g, float b, float a = 1.0f);

			void updateWindow();

			bool shouldClose() const;
			
		};
	}
}


#endif