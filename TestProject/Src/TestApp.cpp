#include <BEngine.h>

class TestApp : public BEngine::Application
{
public:

	TestApp()
		: BEngine::Application("TestApp")
	{
		GetWindow()->SetVsync(true);

		m_Shader = std::make_shared<BEngine::Shader>("Assets/shader.glsl");

		std::vector<float> vertices = {
			-0.5f, -0.5f, 0.0f, 1, 1, -1,
			0.5f, -0.5f, 0.0f,  1, -1, 1,
			0.5f,  0.5f, 0.0f,  -1, -1, 1,
			-0.5f,  0.5f, 0.0f,  1, -1 , -1,
		};

		std::vector<uint32_t> indices = {
			0, 1, 2, 2, 3, 0
		};


		m_VertLayout = std::make_shared<BEngine::VertexArray>();
		m_VertBuffer = std::make_shared<BEngine::VertexBuffer>();
		m_IndexBuffer = std::make_shared<BEngine::IndexBuffer>();

		m_VertLayout->Bind();

		m_VertBuffer->SetData(vertices);
		m_IndexBuffer->SetData(indices);

		m_VertLayout->SetLayout({
			{ GL_FLOAT, 3},
			{ GL_FLOAT, 3 }
			});

		m_VertBuffer->UnBind();
		m_VertLayout->UnBind();
		m_IndexBuffer->UnBind();
	}

	virtual void OnUpdate() override
	{
		glClearColor(0.05f, 0.06f, 0.05f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		m_Shader->Bind();
		m_Shader->UploadUniformFloat("_FunnyFloat", sin(BEngine::Time::GetElapsedTime() * 10));
		m_VertLayout->Bind();

		glDrawElements(GL_TRIANGLES, m_IndexBuffer->GetElementCount(), GL_UNSIGNED_INT, 0);
	}

	BEngine::RefPtr<BEngine::Shader> m_Shader;
	BEngine::RefPtr<BEngine::VertexArray> m_VertLayout;

	BEngine::RefPtr<BEngine::VertexBuffer> m_VertBuffer;
	BEngine::RefPtr<BEngine::IndexBuffer> m_IndexBuffer;
};

BEngine::Application* CreateApplication()
{
	return new TestApp;
}