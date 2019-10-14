#include "Renderer.h"
#include "Logger/Logger.h"
#include "Game/Events/StateEvents.h"
#include "Game/Events/CameraEvents.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

#include "glad/glad.h"

#include<vector>

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

		void Renderer::setWireframeMode(bool mode) const
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

			m_textureManager->loadTexture("MainMenu", "../Miestas/Resources/Images/BackgroundImageMainMenu.png", aiTextureType_NONE);
			m_shaderManager->loadShader("MainMenu", "../Miestas/Resources/Shaders/MainMenu.vs", "../Miestas/Resources/Shaders/MainMenu.fs");
			
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

		void Renderer::render() const
		{
			switch (m_gameState)
			{
			case GameState::MainMenu:
				renderMainMenuScene();
				break;
			}
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
				break;
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

		void Renderer::renderMainMenuScene() const
		{
			setWireframeMode(false);
			setDepthTesting(false);

			//float vertices[] = {
			//	// positions          // texture coords
			//	 0.5f,  0.5f, 0.0f,    1.0f, 1.0f,   // top right
			//	 0.5f, -0.5f, 0.0f,    1.0f, 0.0f,   // bottom right
			//	-0.5f, -0.5f, 0.0f,    0.0f, 0.0f,   // bottom left
			//	-0.5f,  0.5f, 0.0f,    0.0f, 1.0f    // top left 
			//};

			std::vector<float> vertices = {
				1.0f, 1.0f, 0.0f, 1.0f, 1.0f,
				1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
				-1.0f, -1.0f, 0.0f,0.0f, 0.0f,
				-1.0f, 1.0f, 0.0f, 0.0f, 1.0f
			};
			
			
			/*float vertices[] = {
				0.5f, 0.5f, 0.0f,
				0.5f, -0.5f, 0.0f,
				-0.5f, -0.5f, 0.0f,
				-0.5f, 0.5f, 0.0f
			};*/

			std::vector<unsigned int> indices = {  // note that we start from 0!
				0, 1, 3,   // first triangle
				1, 2, 3    // second triangle
			};

			//unsigned int VBO, VAO, EBO;
			//glGenVertexArrays(1, &VAO);
			//glGenBuffers(1, &VBO);
			//glGenBuffers(1, &EBO);
			//// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
			//glBindVertexArray(VAO);

			//glBindBuffer(GL_ARRAY_BUFFER, VBO);
			//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

			//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
			//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

			//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
			//glEnableVertexAttribArray(0);

			//// texture coord attribute
			//glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
			//glEnableVertexAttribArray(1);

			VertexArray va;
			auto vb = std::unique_ptr<VertexBuffer>(new VertexBuffer(vertices, { {3, GL_FLOAT, false}, {2, GL_FLOAT, false} }));
			auto ib = std::make_unique<IndexBuffer>(indices);


			va.bindVertexBuffer(std::move(vb));
			va.bindIndexBuffer(std::move(ib));



			va.bind();
			m_textureManager->getTexture("MainMenu")->bind();
			m_shaderManager->getShader("MainMenu")->bind();
			m_shaderManager->getShader("MainMenu")->setUniformInt("texture1", 0);
			//glBindVertexArray(VAO);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);


		}

		void Renderer::handleGameStateChangeEvent(std::shared_ptr<GameStateChangeEvent> event)
		{
			m_gameState = event->m_newGameState;
			MIESTAS_LOG_INFO("Renderer: Received a GameStateChangedEvent.")
		}
	} 
}