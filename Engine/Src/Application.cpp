#include "Application.h"
#include "bepch.h"

namespace BEngine
{
	Application::Application()
		: m_IsRunning(true)
	{
		Init();	
	}

	void Application::Run()
	{
		while (m_IsRunning)
		{
			OnUpdate();
		}
	}

	void Application::Init()
	{
		BEngine::Log::Init();

		m_Window = std::make_shared<Window>("MyWindow", 1280, 720);
	}
}