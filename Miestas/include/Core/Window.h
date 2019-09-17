#ifndef WINDOW_H
#define WINDOW_H

#include<string>

#include "GLFW/glfw3.h"

#include "Core/Event/Observable.h"
#include "Core/Event/EventQueue.h"

namespace Miestas
{
	namespace Core
	{
		class Window: public Observable
		{
		private:
			std::string m_windowTitle;
			unsigned int m_Width;
			unsigned int m_Height;
			bool m_vSyncEnabled;
			GLFWwindow* m_Window;
			EventQueue* m_eventQueue;

		public:

			Window() : m_windowTitle("Miestas Debug"), m_Width(800), m_Height(600), m_Window(nullptr), m_vSyncEnabled(false) {}

			Window(const std::string& wt, unsigned int mw = 800, unsigned int mh = 600):
				m_windowTitle(wt), m_Width(mw), m_Height(mh), m_vSyncEnabled(false) {}

			~Window();

			void enableVSync();

			void disableVSync();

			void init();

			void clearWindow(float r, float g, float b, float a = 1.0f);

			void updateWindow();

			bool shouldClose() const;

			virtual void onEvent(Event* event) override;

			virtual void setEventQueue(EventQueue* eq) override;


		//private:

			virtual void emitEvent(Event* event) override;


		};
	}
}


#endif