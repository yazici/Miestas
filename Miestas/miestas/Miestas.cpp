#include "Logger/Logger.h"

#include "VertexArray.h"
#include "Shader.h"
#include "Core/Window.h"
#include "Core/Timer.h"

#include "Utils/FastNoise.h"

#include<vector>
#include<memory>
#include<iostream>

#include "Core/Event/Event.h"
#include "Core/Event/WindowEvents.h"
#include "Core/Config.h"
#include "Managers/ShaderManager.h"
#include "Core/InputHandler.h"
#include "Renderer/CubeMap.h"

#include "Application.h"
/*

std::unique_ptr<Application> m_Application = std::make_unique<Application>();
m_Application->init();
m_Application->run();

*/

#include "Core/Memory/LinearAllocator.h"

#include<cstdlib>
using namespace Miestas;
using namespace Miestas::Core;
int main()
{
	std::unique_ptr<Application> m_Application = std::make_unique<Application>();
	m_Application->init();

	m_Application->run();
	

	//std::cin.get();
}

//int main()
//{
//	using namespace Miestas;
//	using namespace Miestas::Renderer;
//	using namespace Miestas::Core;
//
//
//	Config config;
//	//config.readFromFile("C:\\Users\\rdpsi\\Desktop\\Miestas\\Miestas\\configs\\Config.json");
//	config.readFromFile("../Miestas/configs/Config.json");
//	//config.readFromFile();
//	FastNoise fnoise;
//
//	Window window(config.m_applicationName, config.m_windowWidth, config.m_windowHeight);
//	window.init();
//
//	std::vector<float> vbdata = {
//		0.5f,  0.5f, 0.0f,  // top right
//	 0.5f, -0.5f, 0.0f,  // bottom right
//	-0.5f, -0.5f, 0.0f,  // bottom left
//	-0.5f,  0.5f, 0.0f   // top left 
//	};
//
//	std::vector<unsigned int> idata = {
//		0, 1, 3,   // first triangle
//	1, 2, 3    // second triangle
//	};
//
//	//	//std::vector<float> vbdata;
//	//
//	//	//fnoise.SetNoiseType(FastNoise::Perlin);
//	//	//fnoise.SetSeed(10443);
//	//	//constexpr float SCALE_FACTOR = 0.1f;
//	//	//constexpr int MAP_SIZE = 10;
//	//
//	//	//for (int i = 0; i <= MAP_SIZE; i++)
//	//	//{
//	//	//	for (int j = 0; j <= MAP_SIZE; j++)
//	//	//	{
//	//	//		vbdata.push_back(static_cast<float>(j * SCALE_FACTOR));
//	//	//		vbdata.push_back(static_cast<float>(fnoise.GetNoise(j, i)));
//	//	//		vbdata.push_back(static_cast<float>(i * SCALE_FACTOR));
//	//	//	}
//	//	//}
//	//
//	//	//std::vector<unsigned int> idata;
//	//	////unsigned int offset = 0;
//	//	//for (int i = 0; i < MAP_SIZE; i++)
//	//	//{
//	//	//	for (int j = 0; j < MAP_SIZE; j++)
//	//	//	{
//	//	//		unsigned int r1 = i * (MAP_SIZE + 1);
//	//	//		unsigned int r2 = (i + 1) * (MAP_SIZE + 1);
//	//
//	//	//		idata.push_back(r1 + j);
//	//	//		idata.push_back(r1 + j + 1);
//	//	//		idata.push_back(r2 + j + 1);
//	//
//	//	//		idata.push_back(r1 + j);
//	//	//		idata.push_back(r2 + j + 1);
//	//	//		idata.push_back(r2 + j);
//	//	//	}
//	//	//}
//	//
//	//
//		//auto shader = std::make_unique<Shader>("TriangleTest", "C:\\Users\\rdpsi\\Desktop\\Miestas\\Miestas\\shaders\\TriangleTest.vs", "C:\\Users\\rdpsi\\Desktop\\Miestas\\Miestas\\shaders\\TriangleTest.fs");
//	ShaderManager shaderManager;
//	shaderManager.loadShader("TriangleTest", "C:\\Users\\rdpsi\\Desktop\\Miestas\\Miestas\\shaders\\TriangleTest.vs", "C:\\Users\\rdpsi\\Desktop\\Miestas\\Miestas\\shaders\\TriangleTest.fs");
//	shaderManager.loadShader("TriangleTest", "C:\\Users\\rdpsi\\Desktop\\Miestas\\Miestas\\shaders\\TriangleTest.vs", "C:\\Users\\rdpsi\\Desktop\\Miestas\\Miestas\\shaders\\TriangleTest.fs");
//	auto vbo = std::unique_ptr<VertexBuffer>(new VertexBuffer(std::move(vbdata), { {3, GL_FLOAT, false} }));
//
//	auto ibo = std::make_unique<IndexBuffer>(std::move(idata));
//
//	auto va = std::make_unique<VertexArray>();
//
//	va->bindVertexBuffer(std::move(vbo));
//	va->bindIndexBuffer(std::move(ibo));
//
//	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//	Timer timer;
//	EventQueue* eq = new EventQueue;
//	window.setEventQueue(eq);
//	while (!window.shouldClose())
//	{
//		timer.reset();
//		window.clearWindow(0.0f, 0.0f, 0.0f, 1.0f);
//		shaderManager.getShader("Triangletest")->bind();
//		//shader->bind();
//		va->bind();
//		va->render();
//		window.updateWindow();
//		timer.stop();
//	}
//}
//
////int main()
////{
////	Window* m_Window = new Window;
////	EventQueue* m_eventQueue = new EventQueue;
////	InputHandler* m_inputHandler = new InputHandler;
////
////	m_Window->init();
////	m_inputHandler->init();
////
////	m_eventQueue->registerObservable(EventType::None, m_Window);
////	m_eventQueue->registerObservable(EventType::KeyPressedEvent, m_inputHandler);
////	m_eventQueue->registerObservable(EventType::MouseMovedEvent, m_inputHandler);
////	m_eventQueue->registerObservable(EventType::MouseButtonPressedEvent, m_inputHandler);
////
////
////	std::cout << m_inputHandler << std::endl;
////	while (!m_Window->shouldClose())
////	{
////		m_eventQueue->dispatchEvents();
////		m_Window->clearWindow(0.0f, 0.0f, 0.0f, 1.0f);
////		m_Window->updateWindow();
////	}
////	std::cin.get();
////
