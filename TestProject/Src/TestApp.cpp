#include <BEngine.h>

class TestApp : public BEngine::Application
{
public:

	TestApp()
		: BEngine::Application("TestApp")
	{
		GetWindow()->SetVsync(true);

		m_Shader = std::make_shared<BEngine::Shader>("Assets/shader.glsl");

		m_VertLayout = std::make_shared<BEngine::VertexLayout>(
			BEngine::VertexLayout(
				{
					{ GL_FLOAT, 3},
					{ GL_FLOAT, 3}
				}));

		float vertices[] = {
			-0.5f, -0.5f, 0.0f, 0.25f, 0.5f, 0.25f,
			0.5f, -0.5f, 0.0f,  0.5f, 0.25f, 1,
			0.5f,  0.5f, 0.0f,  1, 0.5f, 0.25f,
			-0.5f,  0.5f, 0.0f,  1, 0.5f, 0.25f,
		};

		uint32_t indices[] = {
			0, 1, 2, 2, 3, 0
		};

		unsigned int VBO, VAO, IBO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &IBO);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		m_VertLayout->Bind();

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		this->VAO = VAO;
		this->IBO = IBO;
	}

	virtual void OnUpdate() override
	{
		glClearColor(0.05f, 0.06f, 0.05f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		m_Shader->Bind();
		m_Shader->UploadUniformFloat("_FunnyFloat", sin(BEngine::Time::GetElapsedTime() * 10));
		glBindVertexArray(VAO);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

	BEngine::RefPtr<BEngine::Shader> m_Shader;
	BEngine::RefPtr<BEngine::VertexLayout> m_VertLayout;
	int VAO, IBO;
};

BEngine::Application* CreateApplication()
{
	return new TestApp;
}