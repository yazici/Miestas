#include "Logger/Logger.h"

#include "VertexArray.h"
#include "Shader.h"
#include "Window.h"

#include<vector>
#include<memory>

int main()
{	
	using namespace Miestas;
	using namespace Miestas::Renderer;

	Miestas::Renderer::Window window;

	window.initWindow();
	std::vector<float> vbdata = {
	 0.5f,  0.5f, 0.0f,  // top right
	 0.5f, -0.5f, 0.0f,  // bottom right
	-0.5f, -0.5f, 0.0f,  // bottom left
	-0.5f,  0.5f, 0.0f   // top left 
	};

	std::vector<unsigned int> idata = {
		 0, 1, 3,   // first triangle
	1, 2, 3    // second triangle
	};


	auto shader = std::make_unique<Shader>("TriangleTest", "C:\\Users\\rdpsi\\Desktop\\Miestas\\Miestas\\shaders\\TriangleTest.vs", "C:\\Users\\rdpsi\\Desktop\\Miestas\\Miestas\\shaders\\TriangleTest.fs");


	auto vbo = std::unique_ptr<VertexBuffer>(new VertexBuffer(std::move(vbdata), { {3, GL_FLOAT, false} }));

	auto ibo = std::make_unique<IndexBuffer>(std::move(idata));

	auto va = std::make_unique<VertexArray>();

	va->bindVertexBuffer(std::move(vbo));
	va->bindIndexBuffer(std::move(ibo));

	while (!window.shouldClose())
	{
		window.clearWindow(1.0f, 1.0f, 1.0f, 1.0f);
		shader->bind();
		va->bind();
		va->render();
		window.updateWindow();
	}
}