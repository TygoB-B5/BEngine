#pragma once
#include "Core.h"

namespace BEngine
{
	class Application
	{
	public:
		Application(); 
		~Application();

		void Run();

		virtual void OnTick() = 0;

	private:
		void Init();

	private:
		bool m_IsRunning;
	};
}