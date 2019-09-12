#include "Logger/Logger.h"
#include "Window.h"

int main()
{	 
	Miestas::Renderer::Window window;

	window.initWindow();

	while (!window.shouldClose())
	{
		window.updateWindow();
	}
}