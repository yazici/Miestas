#include "Logger/Logger.h"

#include "VertexArray.h"
#include "Shader.h"
#include "Core/Window.h"
#include "Core/Timer.h"

#include "Utils/FastNoise.h"

#include<vector>
#include<memory>

#include "Core/Event/Event.h"
#include "Core/Event/WindowEvents.h"
#include "Core/Config.h"
/*

std::unique_ptr<Application> m_Application;
m_Application->initializeApplication();
m_Application->run();

*/

int main()
{
	using namespace Miestas;
	using namespace Miestas::Renderer;
	using namespace Miestas::Core;

	Config config;
	config.readFromFile("C:\\Users\\rdpsi\\Desktop\\Miestas\\Miestas\\include\\Core\\Config.json");

	FastNoise fnoise;

	Window window(config.m_applicationName, config.m_windowWidth, config.m_windowHeight);
	window.init();

	std::vector<float> vbdata;

	fnoise.SetNoiseType(FastNoise::Perlin);
	fnoise.SetSeed(10443);
	constexpr float SCALE_FACTOR = 0.1f;
	constexpr int MAP_SIZE = 10;

	for (int i = 0; i <= MAP_SIZE; i++)
	{
		for (int j = 0; j <= MAP_SIZE; j++)
		{
			vbdata.push_back(static_cast<float>(j * SCALE_FACTOR));
			vbdata.push_back(static_cast<float>(fnoise.GetNoise(j, i)));
			vbdata.push_back(static_cast<float>(i * SCALE_FACTOR));
		}
	}

	std::vector<unsigned int> idata;
	//unsigned int offset = 0;
	for (int i = 0; i < MAP_SIZE; i++)
	{
		for (int j = 0; j < MAP_SIZE; j++)
		{
			unsigned int r1 = i * (MAP_SIZE + 1);
			unsigned int r2 = (i + 1) * (MAP_SIZE + 1);

			idata.push_back(r1 + j);
			idata.push_back(r1 + j + 1);
			idata.push_back(r2 + j + 1);

			idata.push_back(r1 + j);
			idata.push_back(r2 + j + 1);
			idata.push_back(r2 + j);
		}
	}


	auto shader = std::make_unique<Shader>("TriangleTest", "C:\\Users\\rdpsi\\Desktop\\Miestas\\Miestas\\shaders\\TriangleTest.vs", "C:\\Users\\rdpsi\\Desktop\\Miestas\\Miestas\\shaders\\TriangleTest.fs");

	auto vbo = std::unique_ptr<VertexBuffer>(new VertexBuffer(std::move(vbdata), { {3, GL_FLOAT, false} }));

	auto ibo = std::make_unique<IndexBuffer>(std::move(idata));

	auto va = std::make_unique<VertexArray>();

	va->bindVertexBuffer(std::move(vbo));
	va->bindIndexBuffer(std::move(ibo));

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	Timer timer;

	Event* wrevent = new WindowResizeEvent(800, 600);

	MIESTAS_LOG_INFO("{0}", wrevent->m_eventType == EventType::None ? "None" : "WindowResize")

	auto w = static_cast<WindowResizeEvent*>(wrevent);
	MIESTAS_LOG_INFO("{0}", w->m_eventType == EventType::None ? "None" : "WindowResize")
	MIESTAS_LOG_INFO("{0}", w->m_newHeight)

	while (!window.shouldClose())
	{
		timer.reset();
		window.clearWindow(0.0f, 0.0f, 0.0f, 1.0f);
		shader->bind();
		va->bind();
		va->render();
		window.updateWindow();
		timer.stop();
	}

}