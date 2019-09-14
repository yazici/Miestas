#ifndef APPLICATION_H
#define APPLICATION_H

#include "Renderer/Renderer.h"

#include<memory>
namespace Miestas
{
	using namespace Miestas::Renderer;
	class Application
	{
	private:
		std::unique_ptr<Renderer> m_Renderer;

	public:

		void init();
	};
	
}

#endif