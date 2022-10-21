#include "Window.h"

namespace BEngine
{
	void GLAPIENTRY
		MessageCallback(GLenum source,
			GLenum type,
			GLuint id,
			GLenum severity,
			GLsizei length,
			const GLchar* message,
			const void* userParam)
	{
		std::string msg = std::to_string(type) + " " + std::to_string(severity) + " " + std::string(message, length);

		switch (severity)
		{
			case 0: BE_WARN(msg) return;
			case 1: BE_WARN(msg) return;
			case 2: BE_WARN(msg) return;
			case 3: BE_WARN(msg) return;
		}
	}

	Window::Window(const WindowProperties& properties)
		:  m_ShouldClose(false)
	{
		// Initialize GLFW.
		if (!glfwInit())
		{
			BE_ASSERT(false, "Unable to Initialize GLFW.")
			glfwTerminate();
		}

		// Create glfw window.
		m_Window = glfwCreateWindow(properties.Width, properties.Height, properties.Name.c_str(), NULL, NULL);

		BE_ASSERT(m_Window, "Window was not Initialized.")

		// Set window to current context.
		glfwMakeContextCurrent(m_Window);

		// Initialize GLAD.
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			BE_ASSERT(false, "Unable to Initialize GLAD")
		}


#ifndef BE_DISTRIBUTE

		// Set up glfw error callback with lambda.
		glfwSetErrorCallback([](int error, const char* msg) {
			BE_ASSERT(false, "[" + std::to_string(error) + "] " + msg)
			});

		// Set up opengl error callback with lambda
		glEnable(GL_DEBUG_OUTPUT);
		glDebugMessageCallback(MessageCallback, 0);

#endif

		// Turn vsync on or off based on properties.
		glfwSwapInterval(properties.Vsync ? 1 : 0);

		// Log OpenGl info.
		BE_INFO("BEngine")
			BE_INFO(std::string(" ") + (const char*)glGetString(GL_RENDERER))
			BE_INFO(std::string(" ") + (const char*)glGetString(GL_VERSION))
			BE_INFO(std::string(" ") + (const char*)glGetString(GL_VENDOR))
			BE_INFO(std::string(" ") + (const char*)glGetString(GL_SHADING_LANGUAGE_VERSION))
	}

	void Window::Update()
	{
		// Poll input events.
		glfwPollEvents();

		// Swap screen buffers.
		glfwSwapBuffers(m_Window);

		// Set ShouldClose variable true if the user closes the window.
		m_ShouldClose = glfwWindowShouldClose(m_Window);
	}
}