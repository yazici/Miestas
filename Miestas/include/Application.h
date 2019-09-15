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
		bool m_isRunning = true;
		std::unique_ptr<Renderer> m_Renderer;

	public:

		void init();
	};
	
}

#endif