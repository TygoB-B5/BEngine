#include "Application.h"
#include "bepch.h"

namespace BEngine
{
	Application::Application()
	{
		Init();	
	}

	void Application::Run()
	{
		while (!m_Window->IsClosed())
		{
			// Update window.
			m_Window->Update();

			// App update.
			OnUpdate();
		}
	}

	void Application::Init()
	{
		BEngine::Log::Init();

		// Initialize window.
		m_Window = std::make_shared<Window>("MyWindow", 1280, 720, false);
	}
}