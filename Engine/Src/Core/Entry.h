#include "Core.h"
#include "Application.h"

extern BEngine::Application* CreateApplication();

int main()
{
	SHOW_CONSOLE()

	// Create new instance of application
	BEngine::Application* app = CreateApplication();

	// Initialize application.
	app->Init();

	// Run application.
	app->Run();

	// If application stopped delete its memory.
	delete app;
}