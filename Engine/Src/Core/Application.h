#pragma once
#include "bepch.h"

#include "Core.h"
#include "Utils/Log.h"
#include "Window.h"
#include "Input.h"

namespace BEngine
{
	class Application
	{
	public:
		Application(const std::string& appName); 

		void Run();

		const RefPtr<Window>& GetWindow() const { return m_Window; }

	public:
		virtual void OnInit() = 0;
		virtual void OnUpdate() = 0;

	private:
		void Init();

	private:
		RefPtr<Window> m_Window;
		std::string m_AppName;
	};
}