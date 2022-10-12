#include "Application.h"


void main()
{
	// Create new instance of application
	auto app = new BEngine::Application;

	// Run application.
	app->Run();

	// If application stopped delete its memory.
	delete app;
}