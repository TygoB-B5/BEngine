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
		void Init();
		void Run();

		const RefPtr<Window>& GetWindow() const { return m_Window; }

	public:
		virtual Window::WindowProperties SetupWindowProperties();

	public:
		virtual void OnInit() = 0;
		virtual void OnUpdate() = 0;

	private:
		RefPtr<Window> m_Window;
	};
}