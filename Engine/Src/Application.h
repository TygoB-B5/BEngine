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

	private:
		void Init();
	};
}