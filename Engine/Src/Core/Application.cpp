#include "Application.h"
#include "Time.h"

#include "Renderer/Shader.h"

namespace BEngine
{
	Application* Application::s_Instance = nullptr;

	Window::WindowProperties Application::SetupWindowProperties()
	{
		BE_WARN("Creating window with default properties")

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
		// Assign singleton variable.
		s_Instance = this;

		// Create window instance.
		m_Window = std::make_shared<Window>(s_Instance->SetupWindowProperties());

		Input::Init();
	}
}