#include "Renderer.h"
#include "Logger/Logger.h"
#include "Game/Events/StateEvents.h"
#include "Game/Events/CameraEvents.h"

#include "glad/glad.h"

namespace Miestas
{
	namespace Renderer
	{
		
		void Renderer::setDepthTesting(bool mode) const
		{
			if (mode)
			{
				glEnable(GL_DEPTH_TEST);
			}
			else
			{
				glDisable(GL_DEPTH_TEST);
			}
		}

		void Renderer::setWireframeMode(bool mode)
		{
			if (mode)
			{
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			}
			else
			{
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			}

		}

		void Renderer::init()
		{
			m_textureManager = std::make_unique<TextureManager>();
			m_shaderManager = std::make_unique<ShaderManager>();
			m_orthoCamera = std::make_unique<OrthoCamera>(-400.0f, 400.0f, 0.01f, 100.0f); // for now

			MIESTAS_LOG_INFO("Renderer: Successfully initiliazed Renderer")
		}

		void Renderer::beginScene()
		{
			m_viewProjectionMatrix = m_orthoCamera->getViewProjection();
		}

		void Renderer::renderScene() const
		{
			// TODO: Rendering code
		}

		void Renderer::endScene()
		{
			// Empty for now
			// One idea for endScene is to update the view matrix of the camera at the end of every call
		}

		void Renderer::onEvent(std::shared_ptr<Event> event)
		{
			// Receives transformations from the game state and applies to objects (?)

			switch (event->getType())
			{
			case EventType::GameStateChangeEvent:
			{
				auto e = STATIC_PTR_CAST(GameStateChangeEvent, event)
				handleGameStateChangeEvent(e);
			}
			}
		}

		void Renderer::setEventQueue(EventQueue * eq)
		{
			m_eventQueue = eq;
		}

		void Renderer::emitEvent(std::shared_ptr<Event> event)
		{
			m_eventQueue->addEventToQueue(std::move(event));
		}

		void Renderer::handleGameStateChangeEvent(std::shared_ptr<GameStateChangeEvent> event)
		{
			m_gameState = event->m_newGameState;
			MIESTAS_LOG_INFO("Renderer: Received a GameStateChangedEvent.")
		}
	} 
}