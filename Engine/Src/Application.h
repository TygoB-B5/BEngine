#pragma once
#include "Core.h"
#include "Log.h"
#include "Window.h"

namespace BEngine
{
	class Application
	{
	public:
		Application(); 

		void Run();

		virtual void OnUpdate() = 0;

	private:
		void Init();

	private:
		RefPtr<Window> m_Window;
		bool m_IsRunning;
	};
}