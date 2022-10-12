#include "Core.h"
#include "Application.h"

extern BEngine::Application*  CreateApplication();

int main()
{
	// Create new instance of application
	BEngine::Application* app = CreateApplication();

	// Run application.
	app->Run();

	// If application stopped delete its memory.
	delete app;
}