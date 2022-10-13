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
		Application(); 

		void Run();

		virtual void OnUpdate() = 0;

	private:
		void Init();

	private:
		RefPtr<Window> m_Window;
	};
}