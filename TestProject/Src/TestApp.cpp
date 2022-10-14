#include <BEngine.h>

class TestApp : public BEngine::Application
{
public:

	TestApp()
		: BEngine::Application("TestApp")
	{
		GetWindow()->SetVsync(true);

		// Variables for checking compilation/linking correctness
		int success;
		char infoLog[512];

		// Basic vertex shader in GLSL (OpenGL Shading Language)
		const char* vertexShaderSource =
			"#version 330 core\n"
			"layout (location = 0) in vec3 aPos;\n"
			"uniform float lol;\n"
			"void main() {\n"
			"	gl_Position = vec4(aPos.x + sin(lol), aPos.y + cos(lol), aPos.z, 1.0);\n"
			"}\0";

		// Basic fragment shader
		const char* fragmentShaderSource =
			"#version 330 core\n"
			"out vec4 FragColor;\n"
			"void main() {\n"
			"	FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
			"}\0";

		// Create a vertex shader object
		unsigned int vertexShader;
		vertexShader = glCreateShader(GL_VERTEX_SHADER);

		// Attach the shader source code to the shader object
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);

		// Compile the vertex shader dynamically 
		glCompileShader(vertexShader);

		// Check if compilation was successful
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n";
			std::cout << infoLog << std::endl;
		}

		// Create a fragment shader object
		unsigned int fragmentShader;
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		// Attach the shader source code to the shader object
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);

		// Compile the fragment shader dynamically
		glCompileShader(fragmentShader);
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n";
			std::cout << infoLog << std::endl;
		}


		// 2. Link shaders

		// Create a shader program
		unsigned int shaderProgram;
		shaderProgram = glCreateProgram();

		// Attach the compiled shaders to the shader program
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glLinkProgram(shaderProgram);

		// Check if linking was successful
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
			std::cout << "ERROR::PROGRAM::LINKING_FAILED\n";
			std::cout << infoLog << std::endl;
		}

		// Delete shader objects if we no longer need them anymore
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);


		// 3. Set up vertex data and configure vertex attributes

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
		this->shaderProgram = shaderProgram;




	}

	virtual void OnUpdate() override
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		GLuint id = glGetUniformLocation(shaderProgram, "lol");
		glUniform1f(id, BEngine::Time::GetElapsedTime());
	}

	int shaderProgram;
	int VAO;
};

BEngine::Application* CreateApplication()
{
	return new TestApp;
}