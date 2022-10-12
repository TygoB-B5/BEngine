#include "Application.h"
#include "bepch.h"

namespace BEngine
{
	Application::Application()
		: m_IsRunning(true)
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (m_IsRunning)
		{
			OnTick();
		}
	}

	void Application::Init()
	{

	}
}