#include <BEngine.h>

class TestApp : public BEngine::Application
{
public:

	TestApp()
		: BEngine::Application("TestApp")
	{
		GetWindow()->SetVsync(true);

		BEngine::Shader shader("Assets/shader.glsl");
		m_Shader = shader;

		// Define three vertices with 3D positions
		float vertices[] = {
			-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			0.0f,  0.5f, 0.0f
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

		// Set attributes that describe how OpenGL should interpret the vertex data
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);


		// Unbind so other calls won't modify VBO and VAO
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);


		this->VAO = VAO;
	}

	virtual void OnUpdate() override
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		m_Shader.Bind();

		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}

	BEngine::Shader m_Shader;
	int VAO;
};

BEngine::Application* CreateApplication()
{
	return new TestApp;
}