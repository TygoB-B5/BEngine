#include <BEngine.h>
#include "glm/glm.hpp"

class TestApp : public BEngine::Application
{
public:

	TestApp()
		: BEngine::Application("TestApp")
	{
		GetWindow()->SetVsync(true);
		std::vector<float> vertices = {
					-0.5f, -0.5f, 1,
					 0.5f, -0.5f, 1,	
					 0.5f,  0.5f, 1,	
					-0.5f,  0.5f, 1,
		};

		std::vector<float> vertices2 = {
			-0.5f - 0.25f, -0.5f - 0.25f, 1,
			 0.5f - 0.25f, -0.5f - 0.25f, 1,
			 0.5f - 0.25f,  0.5f - 0.25f, 1,
			-0.5f - 0.25f,  0.5f - 0.25f, 1,
		};

		std::vector<uint32_t> indices = {
			2, 1, 0, 0, 3, 2
		};

		m_Shader = std::make_shared<BEngine::Shader>("Assets/shader.glsl");

		m_Obj = std::make_shared<BEngine::RenderData>(std::vector<BEngine::VertexDataElement>{ {GL_FLOAT, 3}}, vertices, indices);
		m_Obj2 = std::make_shared<BEngine::RenderData>(std::vector<BEngine::VertexDataElement>{ {GL_FLOAT, 3}}, vertices2, indices);


		BEngine::RenderCommands::Init();
	}

	virtual void OnUpdate() override
	{
		BEngine::RenderCommands::ClearColor({ 0.05f, 0.06f, 0.05f });
		BEngine::RenderCommands::Clear();

		m_Shader->Bind();
		m_Shader->UploadUnitformMat4("uViewProjection", glm::mat4(BEngine::Time::GetElapsedTime() * 5));
		BEngine::Renderer::Draw(m_Obj);
		m_Shader->UploadUnitformMat4("uViewProjection", glm::mat4(BEngine::Time::GetElapsedTime()));
		BEngine::Renderer::Draw(m_Obj2);
	}

	BEngine::RefPtr<BEngine::Shader> m_Shader;

	BEngine::RefPtr<BEngine::RenderData> m_Obj, m_Obj2;
};



BEngine::Application* CreateApplication()
{
	return new TestApp;
}