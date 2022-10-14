#include "Window.h"

namespace BEngine
{
	Window::Window(const std::string& name, uint32_t width, uint32_t height, bool isVsync)
		: m_Width(width), m_Height(height), m_Name(name), m_Vsync(isVsync), m_ShouldClose(false)
	{

		// Initialize GLFW.
		if (!glfwInit())
		{
			BE_ASSERT(false, "Unable to Initialize GLFW.")
			glfwTerminate();
		}

		// Create glfw winow.
		m_Window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);

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

		// Turn vsync on or off.
		glfwSwapInterval(isVsync ? 1 : 0);

		// Log OpenGl specs.
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

		// Set shouldClose variable when the user closes the window.
		m_ShouldClose = glfwWindowShouldClose(m_Window);


	}

	void Window::SetVsync(bool enabled)
	{
		m_Vsync = enabled;

		// Turn vsync on or off.
		glfwSwapInterval(m_Vsync ? 1 : 0);
	}
}