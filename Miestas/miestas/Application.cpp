#include "Logger/Logger.h"

#include "VertexArray.h"
#include "Shader.h"
#include "Core/Window.h"
#include "Core/Timer.h"

#include "Utils/FastNoise.h"

#include<vector>
#include<memory>

// This file will eventually have an Application that will run the game.
// For now, we're using it to test stuff.

int main()
{	
	using namespace Miestas;
	using namespace Miestas::Renderer;
	using namespace Miestas::Core;

	FastNoise fnoise;

	Window window("Debug", 1920, 1080);

	window.initWindow();
	/*std::vector<float> vbdata = {
	 0.5f,  0.5f, 0.0f,  // top right
	 0.5f, -0.5f, 0.0f,  // bottom right
	-0.5f, -0.5f, 0.0f,  // bottom left
	-0.5f,  0.5f, 0.0f   // top left 
	};

	std::vector<unsigned int> idata = {
		 0, 1, 3,   // first triangle
	1, 2, 3    // second triangle
	};*/

	std::vector<float> vbdata;
	//vbdata.resize(100);

	fnoise.SetNoiseType(FastNoise::Perlin);
	fnoise.SetSeed(10443);
	constexpr float SCALE_FACTOR = 0.1f;
	constexpr int MAP_SIZE = 1000;
	
	for (int i = 0; i <= MAP_SIZE; i++)
	{
		for (int j = 0; j <= MAP_SIZE; j++)
		{
			vbdata.push_back(static_cast<float>(j * SCALE_FACTOR));
			vbdata.push_back(fnoise.GetNoise(j, i));
			vbdata.push_back(static_cast<float>(i * SCALE_FACTOR));
		}
	}

	std::vector<unsigned int> idata;
	//unsigned int offset = 0;
	for (int i = 0; i < MAP_SIZE  ;i++)
	{
		for (int j = 0; j < MAP_SIZE; j++)
		{
			unsigned int r1 = i * (MAP_SIZE+1);
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