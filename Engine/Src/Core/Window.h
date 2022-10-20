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
		Window(const std::string& name, uint32_t width, uint32_t height, bool isVsync = true);

		// Swap screen buffers and poll events.
		void Update();

		// Return if the window should be closed.
		inline bool IsClosed() const { return m_ShouldClose; }

		// Enable or disable vertical sync.
		void SetVsync(bool enabled);

		GLFWwindow* GetNativeWindow() const { return m_Window; }

	private:
		GLFWwindow* m_Window;
		std::string m_Name;
		uint32_t m_Width, m_Height;
		bool m_Vsync;
		bool m_ShouldClose;
	};
}