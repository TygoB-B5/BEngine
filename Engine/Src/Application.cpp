#include "Application.h"
#include "bepch.h"

namespace BEngine
{
	Application::Application()
	{
		std::cout << "Construct";
	}

	Application::~Application()
	{
		std::cout << "Destruct";
	}

	void Application::Run()
	{
		std::cout << "Running";
	}

	void Application::Init()
	{

	}
}