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


		// Define three vertices with 3D positions
		float vertices[] = {
			-0.5f, -0.5f, 0.0f, 0.25f, 0.5f, 0.25f,
			0.5f, -0.5f, 0.0f,  0.5f, 0.25f, 1,
			0.0f,  0.5f, 0.0f,  1, 0.5f, 0.25f,
		};

		// Generate vertex buffer object (VBO) and vertex array object (VAO)
		unsigned int VBO, VAO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);

		// Bind VAO, then bind VBO
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		// Copy the vertex data into the buffer's memory
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		// Unbind so other calls won't modify VBO and VAO
		m_VertLayout->Bind();
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);


		this->VAO = VAO;
	}

	virtual void OnUpdate() override
	{
		glClearColor(0.05f, 0.06f, 0.05f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		m_Shader->Bind();

		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}

	BEngine::RefPtr<BEngine::Shader> m_Shader;
	BEngine::RefPtr<BEngine::VertexLayout> m_VertLayout;
	int VAO;
};

BEngine::Application* CreateApplication()
{
	return new TestApp;
}