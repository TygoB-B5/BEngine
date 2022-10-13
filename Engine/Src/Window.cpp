#include "Window.h"
#include "Core.h"

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

		// Set up glfw error callback with lambda.
		glfwSetErrorCallback([](int error, const char* msg) {
			BE_ASSERT(false, "[" + std::to_string(error) + "] " + msg)
			});

		// Set window to current context.
		glfwMakeContextCurrent(m_Window);

		// Turn vsync on or off.
		glfwSwapInterval(isVsync ? 1 : 0);
	}

	void Window::Update()
	{
		// Poll input events.
		glfwPollEvents();

		// Swap buffers.
		glfwSwapBuffers(m_Window);

		// Set shouldClose variable when the user closes the window.
		m_ShouldClose = glfwWindowShouldClose(m_Window);
	}
}