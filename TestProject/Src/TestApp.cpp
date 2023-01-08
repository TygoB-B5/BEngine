#include <Bonfire.h>
#include "glm/glm.hpp"
#include "glad/glad.h"

class TestApp : public Bonfire::Application
{
public:
	virtual Bonfire::Window::WindowProperties SetupWindowProperties() override
	{
		return { "MyTestApp", 1280, 720, true };
	}

	virtual void OnInit() override
	{
		std::vector<GLuint> cubeIndices{
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

		std::vector<float> cubeVertices{
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

		std::vector<GLuint> floorIndices
		{
			0, 2, 1, 0, 3, 2
		};

		std::vector<float> floorVertices
		{
			25,  -0.5, 25, 0, 1, 0, 1, 1,
			-25, -0.5, 25, 0, 1, 0, 0, 1,
			-25, -0.5, -25, 0, 1, 0, 0, 0,
			25,  -0.5, -25,  0, 1, 0, 1, 0,
		};

		m_CubeShader = std::make_shared<Bonfire::Shader>("Assets/shader.glsl");
		m_ShadowShader = std::make_shared<Bonfire::Shader>("Assets/shadowshader.glsl");
		m_ScreenShader = std::make_shared<Bonfire::Shader>("Assets/screenshader.glsl");

		m_Cube = std::make_shared<Bonfire::VertexData>(std::vector<Bonfire::VertexDataElement>{ {GL_FLOAT, 3}, { GL_FLOAT, 3 }, { GL_FLOAT, 2 }}, cubeVertices, cubeIndices);
		
		m_Floor = std::make_shared<Bonfire::VertexData>(std::vector<Bonfire::VertexDataElement>{ {GL_FLOAT, 3}, { GL_FLOAT, 3 }, { GL_FLOAT, 2 }}, floorVertices, floorIndices);

		m_Camera = std::make_shared<Bonfire::PerspectiveCamera>(70, 16.0f / 9.0f, 0.01f, 1000.0f);
		m_Camera->SetPosition({ 0.0f, 0.0f, 2.0f });
		m_CameraController = std::make_shared<Bonfire::CameraController>(m_Camera, 0.25f, 3, 7);

		m_Texture1 = std::make_shared<Bonfire::Texture2D>("Assets/testtex1.png");
		m_Texture2 = std::make_shared<Bonfire::Texture2D>("Assets/testtex2.png");
		m_Texture3 = std::make_shared<Bonfire::Texture2D>("Assets/testtex3.png");
		m_Texture4 = std::make_shared<Bonfire::Texture2D>("Assets/testtex4.jpg");

		m_ScreenQuad = std::make_shared<Bonfire::VertexData>(
			std::vector<Bonfire::VertexDataElement>{ {GL_FLOAT, 3}, { GL_FLOAT, 2 }},
			std::vector<float>{
			-1, -1, 0, 0, 0,
				1, -1, 0, 1, 0,
				1, 1, 0, 1, 1,
				-1, 1, 0, 0, 1},
			std::vector<uint32_t>{0, 1, 2, 2, 3, 0});


		Bonfire::FrameBufferProperties props = { 1280, 720 };
		m_FrameBuffer = std::make_shared<Bonfire::FrameBuffer>(props);

		Bonfire::FrameBufferProperties shadowProps = { 4048, 4048 };
		m_ShadowBuffer = std::make_shared<Bonfire::FrameBuffer>(shadowProps);

		m_LightPos = { -7.0f, 4.0f, -4.0f };

		Bonfire::RenderCommands::Init();
	}

	virtual void OnUpdate() override
	{
		m_ShadowBuffer->Bind();
		glViewport(0, 0, 4048, 4048);
		glCullFace(GL_FRONT);

		m_CameraController->Update();


		float near_plane = 1, far_plane = 15;
		m_LightProjection = glm::ortho(-10.f, 10.f, -10.f, 10.f, near_plane, far_plane);
		m_LightView = glm::lookAt(m_LightPos, glm::vec3(0.0f), glm::vec3(0.0, 1.0, 0.0));
		m_LightViewProjection = m_LightProjection * m_LightView;

		Bonfire::Renderer::BeginFrame(m_CameraController->GetCamera());
		Bonfire::RenderCommands::ClearColor({ 0.04f, 0.06f, 0.05f });
		Bonfire::RenderCommands::Clear();

		m_ShadowShader->Bind();
		m_ShadowShader->UploadUniformMat4("uLightViewProjectionMatrix", m_LightViewProjection);
		m_ShadowShader->UploadUniformMat4("uModelMatrix", glm::mat4(1.0f));

		Bonfire::Renderer::Draw(m_Floor, m_ShadowShader);
		m_CubePosition.x = sin(Bonfire::Time::GetElapsedTime());
		m_CubePosition.z = cos(Bonfire::Time::GetElapsedTime());
		m_ShadowShader->UploadUniformMat4("uModelMatrix", glm::translate(glm::mat4(1.0f), glm::vec3(m_CubePosition.x, m_CubePosition.y, m_CubePosition.z)));
		Bonfire::Renderer::Draw(m_Cube, m_ShadowShader);

		m_ShadowBuffer->UnBind();
		glViewport(0, 0, 1280, 720);
		glCullFace(GL_BACK);

		m_FrameBuffer->Bind();
		Bonfire::RenderCommands::Clear();
		
		m_Texture1->Bind(0);
		m_Texture2->Bind(1);
		m_Texture3->Bind(2);
		m_Texture4->Bind(3);

		if (Bonfire::Input::IsKeyPressed(KEY_1))
		{
			m_CubeShader->UploadUniformTextureSlot("uTexture", 0);
		}
		if (Bonfire::Input::IsKeyPressed(KEY_2))
		{
			m_CubeShader->UploadUniformTextureSlot("uTexture", 1);
		}
		if (Bonfire::Input::IsKeyPressed(KEY_3))
		{
			m_CubeShader->UploadUniformTextureSlot("uTexture", 2);
		}
		if (Bonfire::Input::IsKeyPressed(KEY_4))
		{
			m_CubeShader->UploadUniformTextureSlot("uTexture", 3);
		}

		m_ShadowBuffer->BindDepthAttachment(4);

		m_CubeShader->Bind();
		m_CubeShader->UploadUniformVec3("uCameraPosition", m_CameraController->GetCamera()->GetPosition());
		m_CubeShader->UploadUniformVec3("uLightPosition", m_LightPos);
		m_CubeShader->UploadUniformMat4("uLightViewProjectionMatrix", m_LightViewProjection);
		m_CubeShader->UploadUniformTextureSlot("uShadowMap", 4);

		m_CubeShader->UploadUniformMat4("uModelMatrix", glm::mat4(1.0f));

		Bonfire::Renderer::Draw(m_Floor, m_CubeShader);

		m_CubeShader->UploadUniformMat4("uModelMatrix", glm::translate(glm::mat4(1.0f), glm::vec3(m_CubePosition.x, m_CubePosition.y, m_CubePosition.z)));
		
		Bonfire::Renderer::Draw(m_Cube, m_CubeShader);
		
		m_FrameBuffer->UnBind();

		Bonfire::RenderCommands::Clear();

		m_FrameBuffer->BindColorAttachment(0);

		Bonfire::Renderer::Draw(m_ScreenQuad, m_ScreenShader);
		
	}
	glm::vec3 m_CubePosition = { 0,0,0 };
	glm::vec3 m_LightPos;
	Bonfire::RefPtr<Bonfire::PerspectiveCamera> m_Camera;
	Bonfire::RefPtr<Bonfire::Shader> m_CubeShader, m_ScreenShader, m_ShadowShader;
	Bonfire::RefPtr<Bonfire::VertexData> m_Cube, m_Floor;
	Bonfire::RefPtr<Bonfire::VertexData> m_ScreenQuad;
	Bonfire::RefPtr<Bonfire::CameraController> m_CameraController;
	Bonfire::RefPtr<Bonfire::Texture2D> m_Texture1, m_Texture2, m_Texture3, m_Texture4;
	Bonfire::RefPtr<Bonfire::FrameBuffer> m_FrameBuffer, m_ShadowBuffer;

	glm::mat4 m_LightProjection;
	glm::mat4 m_LightView;
	glm::mat4 m_LightViewProjection;
};



Bonfire::Application* CreateApplication()
{
	return new TestApp;
}