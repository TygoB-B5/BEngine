#include <BEngine.h>
#include "glm/glm.hpp"
#include "glad/glad.h"

class TestApp : public BEngine::Application
{
public:
	virtual BEngine::Window::WindowProperties SetupWindowProperties() override
	{
		return { "MyTestApp", 1280, 720, true };
	}

	virtual void OnInit() override
	{
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
			-0.5000, -0.5000,  0.5000, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
			 0.5000, -0.5000,  0.5000, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
			-0.5000,  0.5000,  0.5000, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
			-0.5000,  0.5000,  0.5000, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
			 0.5000, -0.5000,  0.5000, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
			 0.5000,  0.5000,  0.5000, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,

			 // Back
			-0.5000, -0.5000, -0.5000, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
			-0.5000,  0.5000, -0.5000, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f,
			 0.5000, -0.5000, -0.5000, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f,
			 0.5000, -0.5000, -0.5000, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f,
			-0.5000,  0.5000, -0.5000, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f,
			 0.5000,  0.5000, -0.5000, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f,

			 // Right
			 0.5000, -0.5000, -0.5000, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
			 0.5000,  0.5000, -0.5000, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			 0.5000, -0.5000,  0.5000, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
			 0.5000, -0.5000,  0.5000, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
			 0.5000,  0.5000, -0.5000, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			 0.5000,  0.5000,  0.5000, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,

			 // Left				   			   
			-0.5000, -0.5000, -0.5000, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
			-0.5000, -0.5000,  0.5000, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			-0.5000,  0.5000, -0.5000, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
			-0.5000,  0.5000, -0.5000, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
			-0.5000, -0.5000,  0.5000, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			-0.5000,  0.5000,  0.5000, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f,

			// Bottom
			-0.5000, -0.5000, -0.5000, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f,
			 0.5000, -0.5000, -0.5000, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f,
			-0.5000, -0.5000,  0.5000, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f,
			-0.5000, -0.5000,  0.5000, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f,
			 0.5000, -0.5000, -0.5000, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f,
			 0.5000, -0.5000,  0.5000, 0.0f, -1.0f, 0.0f, 1.0f, 1.0f,

			 // Top
			-0.5000,  0.5000, -0.5000, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
			-0.5000,  0.5000,  0.5000, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
			 0.5000,  0.5000, -0.5000, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
			 0.5000,  0.5000, -0.5000, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
			-0.5000,  0.5000,  0.5000, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
			 0.5000,  0.5000,  0.5000, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
		};

		m_Shader = std::make_shared<BEngine::Shader>("Assets/shader.glsl");

		m_ScreenShader = std::make_shared<BEngine::Shader>("Assets/screenshader.glsl");

		m_Obj = std::make_shared<BEngine::VertexData>(std::vector<BEngine::VertexDataElement>{ {GL_FLOAT, 3}, { GL_FLOAT, 3 }, { GL_FLOAT, 2 }}, vertices, indices);
		
		m_Camera = std::make_shared<BEngine::PerspectiveCamera>(70, 16.0f / 9.0f, 0.01f, 1000.0f);
		m_Camera->SetPosition({ 0.0f, 0.0f, 2.0f });
		m_CameraController = std::make_shared<BEngine::CameraController>(m_Camera, 0.25f, 1, 2);

		m_Texture1 = std::make_shared<BEngine::Texture2D>("Assets/testtex1.png");
		m_Texture2 = std::make_shared<BEngine::Texture2D>("Assets/testtex2.png");
		m_Texture3 = std::make_shared<BEngine::Texture2D>("Assets/testtex3.png");
		m_Texture4 = std::make_shared<BEngine::Texture2D>("Assets/testtex4.png");

		m_ScreenQuad = std::make_shared<BEngine::VertexData>(
			std::vector<BEngine::VertexDataElement>{ {GL_FLOAT, 3}, { GL_FLOAT, 2 }},
			std::vector<float>{
			-1, -1, 0, 0, 0,
				1, -1, 0, 1, 0,
				1, 1, 0, 1, 1,
				-1, 1, 0, 0, 1},
			std::vector<uint32_t>{0, 1, 2, 2, 3, 0});

		BEngine::FrameBufferProperties props = { 1280, 720 };
		m_FrameBuffer = std::make_shared<BEngine::FrameBuffer>(props);

		BEngine::RenderCommands::Init();
	}

	virtual void OnUpdate() override
	{
		m_FrameBuffer->Bind();

		m_CameraController->Update();

		BEngine::Renderer::BeginFrame(m_CameraController->GetCamera());
		BEngine::RenderCommands::ClearColor({ 0.04f, 0.06f, 0.05f });
		BEngine::RenderCommands::Clear();

		m_Texture1->Bind(0);
		m_Texture2->Bind(1);
		m_Texture3->Bind(2);
		m_Texture4->Bind(3);

		if (BEngine::Input::IsKeyPressed(KEY_1))
		{
			m_Shader->UploadUniformTextureSlot("uTexture", 0);
		}
		if (BEngine::Input::IsKeyPressed(KEY_2))
		{
			m_Shader->UploadUniformTextureSlot("uTexture", 1);
		}
		if (BEngine::Input::IsKeyPressed(KEY_3))
		{
			m_Shader->UploadUniformTextureSlot("uTexture", 2);
		}
		if (BEngine::Input::IsKeyPressed(KEY_4))
		{
			m_Shader->UploadUniformTextureSlot("uTexture", 3);
		}

		BEngine::Renderer::Draw(m_Obj, m_Shader);
		
		m_FrameBuffer->UnBind();
		BEngine::RenderCommands::Clear();

		m_FrameBuffer->BindColorAttachment();

		BEngine::Renderer::Draw(m_ScreenQuad, m_ScreenShader);
	}

	BEngine::RefPtr<BEngine::PerspectiveCamera> m_Camera;
	BEngine::RefPtr<BEngine::Shader> m_Shader, m_ScreenShader;
	BEngine::RefPtr<BEngine::VertexData> m_Obj;
	BEngine::RefPtr<BEngine::VertexData> m_ScreenQuad;
	BEngine::RefPtr<BEngine::CameraController> m_CameraController;
	BEngine::RefPtr<BEngine::Texture2D> m_Texture1, m_Texture2, m_Texture3, m_Texture4;
	BEngine::RefPtr<BEngine::FrameBuffer> m_FrameBuffer;
};



BEngine::Application* CreateApplication()
{
	return new TestApp;
}