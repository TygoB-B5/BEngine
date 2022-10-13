#pragma once
#include "bepch.h"

#include "Core.h"
#include "Log.h"
#include "Window.h"
#include "Input.h"

namespace BEngine
{
	class Application
	{
	public:
		Application(const std::string& appName); 

		void Run();

		virtual void OnUpdate() = 0;

		const RefPtr<Window>& GetWindow() const { return m_Window; }

	private:
		void Init();

	private:
		RefPtr<Window> m_Window;
		std::string m_AppName;
	};
}