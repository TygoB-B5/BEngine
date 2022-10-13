#include "Application.h"
#include "Time.h"

namespace BEngine
{
	Application::Application(const std::string& appName)
		: m_AppName(appName)
	{
		Init();	
	}

	void Application::Run()
	{

		// Main application loop.
		while (!m_Window->IsClosed())
		{
			Input::Flush();
			Time::Tick();
			m_Window->Update();
			OnUpdate();
		}
	}

	void Application::Init()
	{
		Log::Init();

		// Create window.
		m_Window = std::make_shared<Window>(m_AppName, 1280, 720, false);

		Input::Init(m_Window->GetNativeWindow());
	}
}