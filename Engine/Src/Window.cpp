#include "Window.h"
#include "Core.h"

namespace BEngine
{
	Window::Window(const std::string& name, uint32_t width, uint32_t height, bool isVsync)
		: m_Width(width), m_Height(height), m_Name(name), m_Vsync(isVsync), m_ShouldClose(false)
	{
		m_Window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);

		BE_ASSERT(m_Window, "Window was not Initialized.")

		// Initialize GLFW.
		if (!glfwInit())
		{
			BE_ASSERT(false, "Unable to Initialize GLFW.")
		}

		// Make this window the current context.
		glfwMakeContextCurrent(m_Window);

		// Turn vsync on or off.
		glfwSwapInterval(isVsync ? 1 : 0);

		// Show the window.
		glfwShowWindow(m_Window);
	}

	void Window::Update()
	{
		// Poll input events.
		glfwPollEvents();

		// Set shouldClose variable when the user closes the window.
		m_ShouldClose = glfwWindowShouldClose(m_Window);
	}
}