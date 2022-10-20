#include <BEngine.h>
#include "glm/glm.hpp"

class TestApp : public BEngine::Application
{
public:

	TestApp()
		: BEngine::Application("TestApp")
	{
		GetWindow()->SetVsync(true);



		std::vector<GLuint> indices{
		0,  1,  2,
		3,  4,  5,

		6,  7,  8,
		9, 10, 11,

		12, 13, 14,
		15, 16, 17,

		18, 19, 20,
		21, 22, 23,

		24, 25, 26,
		27, 28, 29,

		30, 31, 32,
		33, 34, 35,
		};

		std::vector<float> vertices{
			// Front
		    -0.5000, -0.5000,  0.5000, 0.0f, 0.0f, 1.0f,
			 0.5000, -0.5000,  0.5000, 0.0f, 0.0f, 1.0f,
			-0.5000,  0.5000,  0.5000, 0.0f, 0.0f, 1.0f,
			-0.5000,  0.5000,  0.5000, 0.0f, 0.0f, 1.0f,
			 0.5000, -0.5000,  0.5000, 0.0f, 0.0f, 1.0f,
			 0.5000,  0.5000,  0.5000, 0.0f, 0.0f, 1.0f,

			 // Back
			-0.5000, -0.5000, -0.5000, 0.0f, 0.0f, -1.0f,
			-0.5000,  0.5000, -0.5000, 0.0f, 0.0f, -1.0f,
			 0.5000, -0.5000, -0.5000, 0.0f, 0.0f, -1.0f,
			 0.5000, -0.5000, -0.5000, 0.0f, 0.0f, -1.0f,
			-0.5000,  0.5000, -0.5000, 0.0f, 0.0f, -1.0f,
			 0.5000,  0.5000, -0.5000, 0.0f, 0.0f, -1.0f,

			 // Right
			 0.5000, -0.5000, -0.5000, 1.0f, 0.0f, 0.0f,
			 0.5000,  0.5000, -0.5000, 1.0f, 0.0f, 0.0f,
			 0.5000, -0.5000,  0.5000, 1.0f, 0.0f, 0.0f,
			 0.5000, -0.5000,  0.5000, 1.0f, 0.0f, 0.0f,
			 0.5000,  0.5000, -0.5000, 1.0f, 0.0f, 0.0f,
			 0.5000,  0.5000,  0.5000, 1.0f, 0.0f, 0.0f,
									   			   
			 // Left				   			   
			-0.5000, -0.5000, -0.5000, -1.0f, 0.0f, 0.0f,
			-0.5000, -0.5000,  0.5000, -1.0f, 0.0f, 0.0f,
			-0.5000,  0.5000, -0.5000, -1.0f, 0.0f, 0.0f,
			-0.5000,  0.5000, -0.5000, -1.0f, 0.0f, 0.0f,
			-0.5000, -0.5000,  0.5000, -1.0f, 0.0f, 0.0f,
			-0.5000,  0.5000,  0.5000, -1.0f, 0.0f, 0.0f,

			// Bottom
			-0.5000, -0.5000, -0.5000, 0.0f, -1.0f, 0.0f,
			 0.5000, -0.5000, -0.5000, 0.0f, -1.0f, 0.0f,
			-0.5000, -0.5000,  0.5000, 0.0f, -1.0f, 0.0f,
			-0.5000, -0.5000,  0.5000, 0.0f, -1.0f, 0.0f,
			 0.5000, -0.5000, -0.5000, 0.0f, -1.0f, 0.0f,
			 0.5000, -0.5000,  0.5000, 0.0f, -1.0f, 0.0f,

			 // Top
			-0.5000,  0.5000, -0.5000, 0.0f, 1.0f, 0.0f,
			-0.5000,  0.5000,  0.5000, 0.0f, 1.0f, 0.0f,
			 0.5000,  0.5000, -0.5000, 0.0f, 1.0f, 0.0f,
			 0.5000,  0.5000, -0.5000, 0.0f, 1.0f, 0.0f,
			-0.5000,  0.5000,  0.5000, 0.0f, 1.0f, 0.0f,
			 0.5000,  0.5000,  0.5000, 0.0f, 1.0f, 0.0f,
		};

		m_Shader = std::make_shared<BEngine::Shader>("Assets/shader.glsl");

		m_Obj = std::make_shared<BEngine::VertexData>(std::vector<BEngine::VertexDataElement>{ {GL_FLOAT, 3}, { GL_FLOAT, 3 }}, vertices, indices);
		m_Camera = std::make_shared<BEngine::PerspectiveCamera>(90, 16.0f / 9.0f, 0.01f, 1000.0f);

		BEngine::RenderCommands::Init();
	}

	virtual void OnUpdate() override
	{
		m_Camera->SetPosition(m_Camera->GetPosition() - 
			glm::vec3(
				(BEngine::Input::IsKeyHeld(KEY_A) * 1 - BEngine::Input::IsKeyHeld(KEY_D)) * BEngine::Time::GetDeltaTime(),
				(BEngine::Input::IsKeyHeld(KEY_S) * 1 - BEngine::Input::IsKeyHeld(KEY_W)) * BEngine::Time::GetDeltaTime(),
				(BEngine::Input::IsKeyHeld(KEY_Q) * 1 - BEngine::Input::IsKeyHeld(KEY_E)) * BEngine::Time::GetDeltaTime()));

		BEngine::Renderer::BeginFrame(m_Camera);

		BEngine::RenderCommands::ClearColor({ 0.05f, 0.06f, 0.05f });
		BEngine::RenderCommands::Clear();

		BEngine::Renderer::Draw(m_Obj, m_Shader);
	}

	BEngine::RefPtr<BEngine::Shader> m_Shader;

	BEngine::RefPtr<BEngine::VertexData> m_Obj;
	BEngine::RefPtr<BEngine::PerspectiveCamera> m_Camera;
};



BEngine::Application* CreateApplication()
{
	return new TestApp;
}