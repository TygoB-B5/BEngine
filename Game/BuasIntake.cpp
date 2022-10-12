// BuasIntake.cpp : Defines the entry point for the application.
//

#include "BuasIntake.h"

using namespace std;

int main()
{
	glr::window window(1280, 720, "MyWindow", true);
	glr::renderer::rendererSettings settings;

	glr::renderer renderer(window, settings);

	while (!renderer.getWindow().shouldClose())
	{
		renderer.update();
	}
	return 0;
}
