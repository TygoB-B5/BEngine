#include "Window.h"

namespace BEngine
{
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

		// Set up glfw error callback with lambda.
		glfwSetErrorCallback([](int error, const char* msg) {
			BE_ASSERT(false, "[" + std::to_string(error) + "] " + msg)
			});

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