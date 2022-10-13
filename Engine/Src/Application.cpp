#include "Application.h"

namespace BEngine
{
	Application::Application()
	{
		Init();	
	}

	void Application::Run()
	{

		// Main application loop.
		while (!m_Window->IsClosed())
		{
			Input::Flush();
			m_Window->Update();
			OnUpdate();
		}
	}

	void Application::Init()
	{

		// Initialize window.
		m_Window = std::make_shared<Window>("MyWindow", 1280, 720, false);

		// Initialize other components.
		Log::Init();
		Input::Init(m_Window->GetNativeWindow());
	}
}