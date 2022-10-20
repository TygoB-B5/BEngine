#pragma once
#include "bepch.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Core.h"


namespace BEngine
{
	class Window
	{
	public:
		struct WindowProperties
		{
			WindowProperties(std::string name = "Application", uint32_t width = 1280, uint32_t height = 720, bool vsync = true)
				: Name(name), Width(width), Height(height), Vsync(vsync)
			{}

			std::string Name;
			uint32_t Width;
			uint32_t Height;
			bool Vsync;
		};

	public:
		Window(const WindowProperties& properties);

		// Swap screen buffers and poll events.
		void Update();

		// Returns true if the window should be closed.
		inline bool IsClosed() const { return m_ShouldClose; }

		// Returns the native GLFWindow* of this application.
		GLFWwindow* GetNativeWindow() const { return m_Window; }

	private:
		GLFWwindow* m_Window;
		bool m_ShouldClose;
		WindowProperties m_WindowProperties;
	};
}