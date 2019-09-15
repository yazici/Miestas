#include "glad/glad.h"

#include "Window.h"
#include "Logger/Logger.h"
#include "Core/Event/WindowEvents.h"

#include<functional>

namespace Miestas
{
	namespace Core
	{
		Window::~Window()
		{
			glfwTerminate();
		}

		void Window::enableVSync()
		{
			if (!m_Window)
				return;

			glfwSwapInterval(1);
			m_vSyncEnabled = true;
			MIESTAS_LOG_INFO("VSync Enabled")
		}

		void Window::disableVSync()
		{
			if (!m_Window)
				return;

			glfwSwapInterval(0);
			m_vSyncEnabled = false;
			MIESTAS_LOG_INFO("VSync Disabled")
		}

		void Window::init()
		{
			if (!glfwInit())
			{
				MIESTAS_FAILURE("Failed to initialize GLFW.")
			}

			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

			m_Window = glfwCreateWindow(m_Width, m_Height, m_windowTitle.c_str(), nullptr, nullptr);

			if (!m_Window)
			{
				MIESTAS_FAILURE("Failed to create window.")
			}
			
			glfwMakeContextCurrent(m_Window);
			//TODO: Resize callback

			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			{
				MIESTAS_FAILURE("Failed to initialize GLAD")
			}

			MIESTAS_LOG_INFO("Successfully created and initialized window.")

		}

		void Window::clearWindow(float r, float g, float b, float a)
		{
			glClearColor(r, g, b, a);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::updateWindow()
		{
			glfwSwapBuffers(m_Window);
			glfwPollEvents();
		}

		bool Window::shouldClose() const
		{
			return glfwWindowShouldClose(m_Window);
		}

		void Window::onEvent(Event * event)
		{
			// TODO
		}

		void Window::setEventQueue(EventQueue * eq)
		{
			m_eventQueue = eq;
		}

		void Window::emitEvent(Event * event)
		{
			m_eventQueue->addEventToQueue(event);
		}


		

	}
}