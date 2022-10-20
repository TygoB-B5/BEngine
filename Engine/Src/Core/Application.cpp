#include "Application.h"
#include "Time.h"

#include "Renderer/Shader.h"

namespace BEngine
{
	Window::WindowProperties Application::SetupWindowProperties()
	{
		BE_WARN("Creating window with default properties")
		BE_WARN("Override \"Window::WindowProperties Application::SetupWindowProperties()\" to set custom properties");

		return Window::WindowProperties();
	}

	void Application::Run()
	{
		// Initializes application that uses BEngine.
		OnInit();

		// Main application loop.
		while (!m_Window->IsClosed())
		{
			Input::Flush();
			Time::Tick();
			m_Window->Update();

			// Updates application that uses BEngine.
			OnUpdate();
		}
	}

	void Application::Init()
	{
		// Create window with properties defined in virtual SetupWindowProperties method.
		m_Window = std::make_shared<Window>(SetupWindowProperties());

		// Initialize input class.
		Input::Init(m_Window->GetNativeWindow());
	}
}