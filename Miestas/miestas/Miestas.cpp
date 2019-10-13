#include<memory>

#include "Application.h"

using namespace Miestas;
using namespace Miestas::Core;
using namespace Miestas::Game;

int main()
{
	std::unique_ptr<Application> m_Application = std::make_unique<Application>();
	m_Application->init();

	m_Application->run();
	
	//std::cin.get();
}
