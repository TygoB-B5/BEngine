#pragma once
#include "GLFW/glfw3.h"
#include "bepch.h"

namespace BEngine
{
	class Window
	{
	public:
		Window(const std::string& name, uint32_t width, uint32_t height, bool isVsync = true);

		void Update();
		inline bool IsClosed() const { return m_ShouldClose; }

	private:
		GLFWwindow* m_Window;
		std::string m_Name;
		uint32_t m_Width, m_Height;
		bool m_Vsync;
		bool m_ShouldClose;
	};
}