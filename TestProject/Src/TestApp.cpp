#include <BEngine.h>
#include "glm/glm.hpp"

class TestApp : public BEngine::Application
{
public:

	TestApp()
	{

	}

	virtual void OnUpdate() override
	{
		BE_WARN(std::to_string(BEngine::Input::GetMousePosition().x));

		if (BEngine::Input::IsMouseButtonReleased(0))
			BE_TRACE("hi3");
	}
};

BEngine::Application* CreateApplication()
{
	return new TestApp;
}